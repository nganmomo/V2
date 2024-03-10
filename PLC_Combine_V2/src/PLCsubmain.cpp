#include "../include/plcsvg.h"
//for timer for phone password timeout
char phonepw[16];
char Storephonepw[16];
char Storeeditpw[16];
byte ctlpermit=1;//dont check pw
byte adminpermit=0;
unsigned long phonestartTime;
unsigned long phoneelapsedTime;
unsigned long phonetimeset;
String displaymess;
char encrytext[12];
char comparetext[12];
uint64_t chipId;
void setuptimeclock(byte load);

void saveint16Clear(uint16_t (*dataz)[40]);
char keyvalue[20];
  void receivedplcdata()
  {numchartowrite=6; 
  if(variable[0]=='t' && variable[1]=='x')  
    {if(variable[2]=='A')               //is sign
        {saveint16(variable,dataz0,0,20);  
        saveint16Clear(dataz0);      
        }        
    if(variable[2]=='B')                //is id
        {saveint16(variable,dataz0,20,40);                                  
        }
    if(variable[2]=='C')                //is link  
        {saveint16(variable,dataz1,0,20);    
        saveint16Clear(dataz1);          
        }
    if(variable[2]=='D')                //is link
        {saveint16(variable,dataz1,20,40);           
        }
    if(variable[2]=='E')                //is set
        {saveint16(variable,dataz2,0,20);              
        saveint16Clear(dataz2); 
        }                      
    if(variable[2]=='F')               //is sign
        {saveint16(variable,dataz2,20,40);       
        }        
    if(variable[2]=='G')                //is id
        {saveint16(variable,dataz3,0,20);          
        saveint16Clear(dataz3); 
        }
    if(variable[2]=='H')                //is link  
        {saveint16(variable,dataz3,20,40);              
        }
    if(variable[2]=='J')                //is link
        {saveint16(variable,dataz4,0,20);                
        //k uncondition//
        }
    if(variable[2]=='K')                //is set
        {saveint16(variable,dataz4,20,40);                                       
        eepromwrite(adddataz0,dataz0,0);
        eepromwrite(adddataz1,dataz1,0);
        eepromwrite(adddataz2,dataz2,0);
        eepromwrite(adddataz3,dataz3,0);
        eepromwrite(adddataz4,dataz4,2);                       
        }            
    }          
  }     
     
void receivedplc(int eedata,int maxlen,char rw,int offset)     
{     //just store for comment topic payload   
  eedata=eedata+offset;           
  if(rw=='U')
    {numchartowrite=6;     
    eewbyte(eedata,&variable[5],maxlen);       
    }   
  if(rw=='D')           
    {numchartowrite=maxlen+6;
    eerbyte(eedata,&variable[5],maxlen);
    variable[3]='D';   
    }            
}                

char  knum;
char  kmode;
char  kmodeC;
byte cellkeyboard(byte work)    //kin or display       
{//update keypad character if key number =99 //mobile control mobo mobi    
byte y; 
byte Len=0;     //process request  
byte ret=0;
if(work==VERIFY)
{
#ifdef  chphpw
  {//Serial.print("variable[6]=");
  //Serial.println(&variable[6]);
  //Serial.print("Storephonepw=");
  //Serial.println(Storephonepw);  
  for(y=0;y<10;y++)
    {if(variable[y+6]!=Storephonepw[y])
      break;
    }
  if(y>7)  
    {//phonestartTime=millis();  
    ctlpermit=1;
    displaymess="READY";   
    }  
  else
    {ctlpermit=0;  
    displaymess="ID not match";    
    }
  }           
#else
  {ctlpermit=1;
  displaymess="READY";     
  }
#endif 
variable[3]='d';    //display required   
}
if(work==DWORK)
  {buttonnum=variable[4]-0x30; //0-8 Y
  buttonmode=variable[5]-0x30; //0-5 X     
  Rbuttonnum=variable[4]-0x30; //0-8 Y
  Rbuttonmode=variable[5]-0x30; //0-5 X   
  knum=variable[4];
  kmode=variable[5];        
  kmodeC=kmode+0x10;    
  /*
  Serial.print("kmodeC="); 
  Serial.println(kmodeC);
  Serial.print("ROW="); 
  Serial.println(buttonnum);  
  Serial.print("COL=");
  Serial.println(buttonmode);      
  */
  displaymess="";    
  }    
if(work==DPLAY)          
  {if(ctlpermit==1)
    {if(displaymess.length()<3)    
      {displaymess="Not assign(";                                    
      buttonmode=0;
      }
    displaymess=displaymess+kmodeC+'/'+knum+')';  
    }
  else
    displaymess="Verify ID";  //when using 2nd pw                               
  }         
return 0;
}   
/////////////////  
  
/*/  
  else  
    {//Serial.print("phonebuf2=");
    //Serial.println(phonebuf);
    //Serial.print("buttonnum=");
    //Serial.println(buttonnum);
    for(byte v=0;v<buttonnum;v++) //for analog
      variable[4+v]=phonebuf[v];
    Len=Len+buttonnum;
    Serial.print("variable12=");
    Serial.println(variable);
    }      
  } 
displaymess.toCharArray(&variable[4],Len+1);  
for(y=0;y<100;y++)    
  {if(variable[y]==0)
    {
    break;
    }
  }
Serial.print("variable3=");
Serial.println(variable);    
if(y<5)  y=5;
return y;  //step3// return to Mqtt publish//
}
*/

      
void switchsimulate(byte stateonly)   //switch simulation 
{//switch update       
  int x,y,z,t;
  byte lasty;
  byte realtimeloop;  
  if(stateonly==0)    
    {if(variable[3]=='i')
      {x=variable[4]-0x30; //x
      x=variable[4]-0x30; //x
      y=variable[5]-0x30; //Y               
      z=variable[6]-0x30; //on or off
      t=variable[7]-0x30; //edge or static       
      BoxState[x][y].DeviceState=z; //on off control      
      for(int j=0;j<2;j++)  //do 3 times
      lasty=GetlastScan();
      updateinstate(0,lasty);   //execute simulate once          
      if(t==1) //edge or static
        {BoxState[x][y].DeviceState=0; 
        updateinstate(0,lasty);     //execute simulate once               
        }            
        rwswiches(writeonly);  
      }
    }    
for(y=0;y<ycount;y++)  //30 convert digital to ascii by add 0x30
  {byte type,pin;
  for(x=0;x<xcount;x++)    //240      
    {if(anastate[netnum[x][y]]>0)      //if > 0 means analog
        variable[y*6+x+10]='2';        //net color orange 
    else
        variable[y*6+x+10]=digstate[netnum[x][y]]+0x30;   //net type color 10 is offset   
    variable[y*6+x+250]=BoxState[x][y].DeviceState+0x30;   //device state   70  
    pin=dataz1[x][y];      
    if(type=dataz0[x][y]==40)
      {   //show D?A output
      variable[y*6+x+490]=(d2abuf[pin]/100)+0x30;//BoxState[x][y].status1+0x30;      //not use 13
      variable[y*6+x+730]=(d2abuf[pin]/10)%10+0x30;//BoxState[x][y].status2+0x30;    //not use 19
      variable[y*6+x+970]=(d2abuf[pin]%10)+0x30;//BoxState[x][y].status3+0x30;       //not use 25
      variable[y*6+x+1210]='A';//BoxState[x][y].status4+0x30;      //not use          31
      }    
    if(type=dataz0[x][y]==38)
      {   //show count
      variable[y*6+x+490]=(counter[pin]/100)+0x30;//BoxState[x][y].status1+0x30;      //not use
      variable[y*6+x+730]=(counter[pin]/10)%10+0x30;//BoxState[x][y].status2+0x30;    //not use
      variable[y*6+x+970]=(counter[pin]%10)+0x30;//BoxState[x][y].status3+0x30;       //not use
      variable[y*6+x+1210]='A';//BoxState[x][y].status4+0x30;      //not use          
      }
    else  //show analog value
      {variable[y*6+x+490]=(anastate[netnum[x][y]]/100)+0x30;//BoxState[x][y].status1+0x30;      //not use
      variable[y*6+x+730]=(anastate[netnum[x][y]]/10)%10+0x30;//BoxState[x][y].status2+0x30;     //not use
      variable[y*6+x+970]=(anastate[netnum[x][y]]%10)+0x30;//BoxState[x][y].status3+0x30;        //not use
      variable[y*6+x+1210]='A';//BoxState[x][y].status4+0x30;      //not use          
      }
    }       
  }     
variable[0]='S';variable[1]='W';variable[2]='U';  //switch update
numchartowrite=1211;       
}   

void systemsetup()
{int Length;           
  mqttrun=0; 
  //for mqtt setup
  if(variable[3]=='U')
    {//numchartowrite=4;    
    eewbyte(MQSTdata,variable,500);   
    variable[3]='U';        
    }
  if(variable[3]=='D')  
    {numchartowrite=500;
    eerbyte(MQSTdata,variable,500);
    variable[3]='D';
    }   
  //for time clock
  if(variable[3]=='u')
    {//numchartowrite=4;    
    eewbyte(timeclock,variable,500);   
    variable[3]='U';   
    setuptimeclock(0);      
    }
  if(variable[3]=='d')  
    {numchartowrite=500;
    eerbyte(timeclock,variable,500);
    variable[3]='D';
    }           
variable[0]='m'; 
variable[1]='Q'; 
variable[2]='s'; 
mqttrun=1;      
}    

byte clkid[17];
int32_t setbt[17];
int32_t setet[17];
int32_t setbd[17];
int32_t setem[17];
int32_t setbm[17];
int32_t seted[17];
int32_t setby[17];
int32_t setey[17];
int32_t setbdoy[17];
int32_t setedoy[17];
byte cycle[17];
int UTC;

struct tm timeinfo;

void setuptimeclock(byte load)
{if(load)
    eerbyte(timeclock,variable,500);  
byte tc=0;
int y;
for(y=4;y<500;y++)
  {if(variable[y]>=0x30)
      variable[y]=variable[y]-0x30;  
  }
if(variable[5]=='*')  
  UTC=variable[4];
else
  UTC=-variable[5];  
//Serial.print("UTC="); 
//Serial.println(UTC);  
for(y=4;y<500;y++)
  {if(variable[y]=='*')
    {clkid[tc]=variable[y+1];   
    setbt[tc]=variable[y+2]*36000+variable[y+3]*3600+variable[y+4]*600+variable[y+5]*60+variable[y+6]*10+variable[y+7];
    setet[tc]=variable[y+8]*36000+variable[y+9]*3600+variable[y+10]*600+variable[y+11]*60+variable[y+12]*10+variable[y+13];       
    setby[tc]=variable[y+14]*10+variable[y+15];
    setbm[tc]=variable[y+16]*10+variable[y+17];
    setbd[tc]=variable[y+18]*10+variable[y+19];    
    setey[tc]=variable[y+20]*10+variable[y+21];
    setem[tc]=variable[y+22]*10+variable[y+23];        
    seted[tc]=variable[y+24]*10+variable[y+25];        
    cycle[tc]=variable[y+26];        
    timeinfo.tm_year = setby[tc]+100;  // Years since 1900
    timeinfo.tm_mon = setbm[tc] - 1;    // Months from 0 to 11
    timeinfo.tm_mday = setbd[tc];    
    mktime(&timeinfo);
    setbdoy[tc] = timeinfo.tm_yday + 1;  // tm_yday is 0-index    
    //Serial.printf("Day of the year1: %d\n", setbdoy[tc]);                    
    
    timeinfo.tm_year = setey[tc] + 100;  // Years since 1900
    timeinfo.tm_mon = setem[tc] - 1;    // Months from 0 to 11
    timeinfo.tm_mday = seted[tc];    
    mktime(&timeinfo);
    setedoy[tc] = timeinfo.tm_yday + 1;  // tm_yday is 0-index   
    //Serial.printf("Day of the year2: %d\n", setedoy[tc]);
    if(tc++>=16)       break;
    }
  }  
//inserttimeclock();  
}

/*
void inserttimeclock()
{byte tc,td;
//timeClient.update(); 
//currentdateofyear=timeClient.getEpochTime()/86400-19722;
  {for(tc=0;tc<16;tc++)                
    {for(td=0;td<16;td++)             
      {if(clkid[tc]!=0 && (setedoy[tc]==currentdateofyear && setet[tc]>currenttime || setedoy[tc]>currentdateofyear))
        {clkid[tc]=0;        
        Serial.printf("ed= %d ct= %d dy= %d \n", setedoy[tc],currentdateofyear,setet[tc]);
        }   
      else if(clkid[tc]!=0 && setedoy[tc]>=setbdoy[td] && setbt[tc]>setbt[td])
        {setedoy[16]=setbdoy[tc]; setedoy[16]=setbdoy[tc]; clkid[16]=clkid[tc]; setbt[16]=setbt[tc]; setet[16]=setet[tc]; setbd[16]=setbd[tc]; seted[16]=seted[tc]; setbd[16]=setbm[tc]; seted[16]=setem[tc]; setby[16]=setby[tc]; setey[16]=setey[tc]; cycle[16]=cycle[tc];
        setedoy[tc]=setbdoy[td]; setedoy[tc]=setbdoy[td]; clkid[tc]=clkid[td]; setbt[tc]=setbt[td]; setet[tc]=setet[td]; setbd[tc]=setbd[td]; seted[tc]=seted[td]; setbd[tc]=setbm[td]; seted[tc]=setem[td]; setby[tc]=setby[td]; setey[tc]=setey[td]; cycle[tc]=cycle[td];
        setedoy[td]=setbdoy[16]; setedoy[td]=setbdoy[16]; clkid[td]=clkid[16]; setbt[td]=setbt[16]; setet[td]=setet[16]; setbd[td]=setbd[16]; seted[td]=seted[16]; setbd[td]=setbm[16]; seted[td]=setem[16]; setby[td]=setby[16]; setey[td]=setey[16]; cycle[td]=cycle[16];
        }         
      }            
    }
  }
} 
*/
void receivedplcTable() //RET
  {uint16_t tdata,t=4;
  char idx=variable[3]-0x30;
  byte y,x;
  for(y=0;y<ycount;y++)
    {for(x=0;x<xcount;x++)    
        {if(idx==0)     tdata=dataz0[x][y];
        else if(idx==1)  tdata=dataz1[x][y];
        else if(idx==2)  tdata=dataz2[x][y];
        else if(idx==3)  tdata=dataz3[x][y];
        else if(idx==4)  tdata=dataz4[x][y];                
        variable[t++]='%';                       
        if(tdata>10000) variable[t++]=(tdata/10000)+0x30;  
        if(tdata>1000) variable[t++]=(tdata/1000)%10+0x30;                 
        if(tdata>100) variable[t++]=(tdata/100)%10+0x30;  
        if(tdata>10) variable[t++]=(tdata/10)%10+0x30;  
        variable[t++]=tdata%10+0x30;                 
        }
    }
  variable[t++]='%'; 
  variable[t++]='*';      
  numchartowrite=t;        
  }    

void saveint16Clear(uint16_t (*dataz)[40])
  {
  for(int t=20;t<ycount;t++) //fill the rest
    {for(int s=0;s<xcount;s++)
      dataz[s][t]=0;
    }
  }


void saveint16(char *variable,uint16_t (*dataz)[40],byte start,byte end)
  {int16_t gt[4];
  byte k=0;
  byte i,t;
  byte first=1;
  byte x=0;  
  byte y=start;
  if(start==0)
    {for(t=start;t<ycount;t++) //fill the rest
      {for(int s=0;s<xcount;s++)
        dataz[s][t]=0;
      }
    }  
    for(i=0;i<1200;i++)
    {if(variable[i]=='*')
        break;
    if(variable[i]==',') 
        {if(first==1)
          {first=0;  continue;}
        if(k==4)
          dataz[x][y]=gt[0]*1000+gt[1]*100+gt[2]*10+gt[3];           
        if(k==3)
          dataz[x][y]=gt[0]*100+gt[1]*10+gt[2];
        if(k==2)
          dataz[x][y]=gt[0]*10+gt[1];  
        if(k==1)  
          dataz[x][y]=gt[0];
        if(k==0)  
          dataz[x][y]=0;
        k=0;                 
        x++;        
        if(x>=xcount) {y++; x=0;}
        if(y>=end) y=start; 
        }
    else          
        {if(variable[i]>0x39 || variable[i]<0x30)      continue;      //non figure continue 
          gt[k++]=variable[i]-0x30;
        }
    }      
  //for(t=start;t<end;t++)
  //  {for(int s=0;s<xcount;s++)
  //    {Serial.print(dataz[s][t],DEC);   
  //    Serial.print("<");    
  //    }
  //  }        
  }

//byte leng length of string sat number or char for ||mqtt only||
byte getdata(byte gx,byte gy,char* rebuf)
{char tyre[500];
eerbyte(MQSTdata,tyre,500);
//Serial.print("tyre");
//Serial.println(tyre);
int sat=0;
int t,x=0,y=0;  
for(int t=4;t<500;t++)
  {if(tyre[t]=='%') //&& tyre[t+1]=='%')
    {if(x++>=3)         //x 5   the table has 3 col
      {x=0;y++;
      if(y>=7) 
        {y=0;    //y     the table has 24 row  
        break;
        }
      }       
    }
  else
    {if(gx==x && gy==y)                
      {rebuf[sat++]=tyre[t];         
      if(rebuf[sat]=='%')    
        {rebuf[sat]=0;
        Serial.print("rebuf=");
        Serial.println(rebuf);
        break;                                  
        }
      }
    }  
  }  
return sat;
}

byte checkmqtt()
{byte x,y;
byte mqttexist=0;
for(x=0;x<xcount;x++)
  for(y=0;y<ycount;y++)
    {if(dataz0[x][y]==44 || dataz0[x][y]==45)
      {mqttexist=1;
        break;
      }
    }
if(mqttexist==1 && (mqtten==0 || mqttconnected==0)) 
  return 1; //fault return
else
  return 0;  
} 


void encrypt(char* text,uint64_t chipId)
{byte lookup[32]={'1','f','Z','O','Y','g','2','n','m','h','3','I','x','L','l','6','e','9','5','4','J','c','M','0','b','d','8','7','k','a','O','p'};
byte shiftup[32]={5,1,2,3,6,7,8,0,9,5,4,1,2,3,8,7,6,0,9,4,5,1,2,7,6,1,8,0,9,4};
uint64_t X=((chipId*773/612)*293);
for(byte i=0;i<12;i++)
  { 
  text[i]=X & 0x1f; 
  X=X>>2;
  text[i]=lookup[text[i]];
  } 
}

#ifdef  uart1
void SerialRTXLoop(char* buffer,byte length)
{length=length+1;
STXbuffer[0]=0x5a;
Srxcount=0;
Serial1.write(STXbuffer,length);
}


uint16_t uartmaster(int length)     //master
{byte rxd;
length=length+1;
int y;
for(y=0;y<50000;y++)  
  {if (Serial1.available() && Srxcount<=length) {   
      rxd=Serial1.read();
      if(Srxcount==0 && rxd==0x5a) Srxcount=0;
      SRXbuffer[Srxcount] = rxd;         
      Serial.print(SRXbuffer[Srxcount],DEC);
      Srxcount++;       
      if(Srxcount>=length)          
      break;
      }  
  }  
  return y;  
}
#endif