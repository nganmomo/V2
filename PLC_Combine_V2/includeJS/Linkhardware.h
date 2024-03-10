static const char PROGMEM INDEX_HTML_Linkhardware[] = R"rawliteral(
//var URL="192.168.1.95:8088";
var  URL=window.location.host;
var xhttp = new XMLHttpRequest();
var rxcode="";
var bufferz0 = Array(245).fill(0);   //242
var bufferz1 = Array(245).fill(0);   //242
var bufferz2 = Array(245).fill(0);   //242
var bufferz3 = Array(245).fill(0);   //242
var bufferz4 = Array(245).fill(0);   //242 

var bufferzL0 = Array(127).fill(0);   //242
var bufferzU0 = Array(127).fill(0);   //242
var bufferzL1 = Array(127).fill(0);   //242
var bufferzU1 = Array(127).fill(0);   //242
var bufferzL2 = Array(127).fill(0);   //242 
var bufferzU2 = Array(127).fill(0);   //242
var bufferzL3 = Array(127).fill(0);   //242
var bufferzU3 = Array(127).fill(0);   //242
var bufferzL4 = Array(127).fill(0);   //242
var bufferzU4 = Array(127).fill(0);   //242 
var bufferzL5 = Array(127).fill("");  //for comment -1000
var bufferzU5 = Array(127).fill("");  //for comment -1000
var bufferzL6 = Array(127).fill("");  //extra       -100 
var bufferzU6 = Array(127).fill("");  //extra       -100 
var bufferzL7 = Array(127).fill("");  //extra       -100 
var bufferzU7 = Array(127).fill("");  //extra       -100 
var bufferTxbut = Array(300).fill("");  //extra       -100 
var loopcontrol;

//const mySuccessful = setTimeout(upsuccessful,100000); 
var timeoutmessage="";

//transmit table
function uploadespStart()
{//console.log(uploadespStart)
var  type;
var xa;
var yb;
loopcontrol=0;
  bufferzL0[0]="txA";        //tx0     int_16t SIGNCODE   
  bufferzU0[0]="txB";        //tx1     text4 ID
  bufferzL1[0]="txC";        //tx2     text4 LINK
  bufferzU1[0]="txD";        //tx3     LINECODE
  bufferzL2[0]="txE";        //tx4     PARA
  bufferzU2[0]="txF";        //tx0     int_16t SIGNCODE   
  bufferzL3[0]="txG";        //tx1     text4 ID
  bufferzU3[0]="txH";        //tx2     text4 LINK
  bufferzL4[0]="txJ";        //tx3     LINECODE
  bufferzU4[0]="txK";        //tx4     PARA
  //bufferz5[0]="txF"; bufferz5[61]=0;        //tx5     COMMENT
for(yb=0;yb<(ycount>>1);yb++)        
  {for(xa=0;xa<xcount;xa++)     
    {type=serialcelldata[yb*48+xa*8];
    bufferzL0[yb*6+xa+1]=type;        //move data to buffer for upload
    bufferzL1[yb*6+xa+1]=serialcelldata[yb*48+xa*8+1]>>8;
    if((type>=40 && type<=43) || type==26)
      bufferzL2[yb*6+xa+1]=serialcelldata[yb*48+xa*8+2];
    else
      bufferzL2[yb*6+xa+1]=serialcelldata[yb*48+xa*8+2]>>8;    
    bufferzL3[yb*6+xa+1]=serialcelldata[yb*48+xa*8+3];         
    bufferzL4[yb*6+xa+1]=serialcelldata[yb*48+xa*8+4];    
    bufferzL5[yb*6+xa+1]=serialcelldata[yb*48+xa*8+5]; 
    bufferzL6[yb*6+xa+1]=serialcelldata[yb*48+xa*8+6];   
    bufferzL7[yb*6+xa+1]=serialcelldata[yb*48+xa*8+7];   
    }                  
  } 
for(yb=0;yb<(ycount>>1);yb++)         
  {for(xa=0;xa<xcount;xa++)     
    {type=serialcelldata[(yb+20)*48+xa*8];
    bufferzU0[yb*6+xa+1]=type;        //move data to buffer for upload
    bufferzU1[yb*6+xa+1]=serialcelldata[(yb+20)*48+xa*8+1]>>8;
    if((type>=40 && type<=43) || type==26)
      bufferzU2[yb*6+xa+1]=serialcelldata[(yb+20)*48+xa*8+2];
    else
      bufferzU2[yb*6+xa+1]=serialcelldata[(yb+20)*48+xa*8+2]>>8;    
    bufferzU3[yb*6+xa+1]=serialcelldata[(yb+20)*48+xa*8+3];      
    bufferzU4[yb*6+xa+1]=serialcelldata[(yb+20)*48+xa*8+4];       
    bufferzU5[yb*6+xa+1]=serialcelldata[(yb+20)*48+xa*8+5]; 
    bufferzU6[yb*6+xa+1]=serialcelldata[(yb+20)*48+xa*8+6]; 
    bufferzU7[yb*6+xa+1]=serialcelldata[(yb+20)*48+xa*8+7];   
    }                  
  }   
var length=findlength(bufferzL0);
uploadesp(bufferzL0,length);    
}

function findlength(buffer)
{let rc=0;
for(var t=0;t<244;t++)
  {if(buffer[t]>0)
    rc=t;    
  }
buffer[rc+1]='*';  
return rc+2;
}

function findlength1000(buffer)
{let rc=0;
for(var t=0;t<125;t++)
  {if(buffer[t]!="")
    rc=t;    
  }
//buffer[rc+1]='*';   
return rc+1;
}

//////////////////Upload//begin////////////////////////
function  uploadnextturn(txre)
{console.log('uploadnextturn',txre)
//document.getElementById('botul').style.backgroundColor="#848686";
timeoutmessage="Upload overtime, please wait or try again";
var length=0;
document.getElementById('labelul').style.backgroundColor="aliceblue";  
document.getElementById('labelul').style.width="30px";
if(txre==="txa" && loopcontrol===0)  //B
  {const myTimeout = setTimeout(TimeoutMessage,3000);
  document.getElementById('labelul').style.width="40px";
  length=findlength(bufferzU0) //add '*' at end
  if(length>2)  
    uploadesp(bufferzU0,length);  
  else  
    txre="txb";      
  loopcontrol++;       
  }           
if(txre==="txb" && loopcontrol===1)  //C
  {document.getElementById('labelul').style.width="40px";
  length=findlength(bufferzL1);
    uploadesp(bufferzL1,length);  
  loopcontrol++;       
  }           
if(txre==="txc"  && loopcontrol===2)  //D
  {document.getElementById('labelul').style.width="50px";
  length=findlength(bufferzU1);
  if(length>2)    
    uploadesp(bufferzU1,length); 
  else  
    txre="txd";    
  loopcontrol++;
  }  
if(txre==="txd"  && loopcontrol===3)  //E
  {document.getElementById('labelul').style.width="60px";
  length=findlength(bufferzL2);
    uploadesp(bufferzL2,length);   
  loopcontrol++;   
  }
if(txre==="txe"  && loopcontrol===4)  //F
  {document.getElementById('labelul').style.width="70px";
  length=findlength(bufferzU2);
  if(length>2)    
    uploadesp(bufferzU2,length);  
  else  
    txre="txf";    
  loopcontrol++; 
  }
if(txre==="txf" && loopcontrol===5)  //G
  {document.getElementById('labelul').style.width="80px";
  length=findlength(bufferzL3);
  //if(length>2)   
    uploadesp(bufferzL3,length);  
  //else
  //  txre="txg"; 
  loopcontrol++;       
  }           
if(txre==="txg" && loopcontrol===6)  //H
  {document.getElementById('labelul').style.width="90px";
  length=findlength(bufferzU3);
  if(length>2)    
    uploadesp(bufferzU3,length);  
  else  
    txre="txh";    
  loopcontrol++;       
  }           
if(txre==="txh"  && loopcontrol===7)  //J
  {document.getElementById('labelul').style.width="100px";
  length=findlength(bufferzL4);
    uploadesp(bufferzL4,length); 
  loopcontrol++;
  }  
if(txre==="txj"  && loopcontrol===8)  //cannot bypass K Save EEPROM
  {document.getElementById('labelul').style.width="110px";
  length=findlength(bufferzU4);    
  uploadesp(bufferzU4,length);    
  loopcontrol++;   
  }

if((txre==="txk" || txre==="tym") && loopcontrol===9)   
  {document.getElementById('labelul').style.width="140px";   
  //clearTimeout(my_Timeout);  
  if( txre==="tym")
    timeoutmessage="MQTT not connected,\n Check SW or MQTT setup";  
  else  
    timeoutmessage="Hareware will not keep comment, Please use file to keep comment\n\n upload successful";           
  document.getElementById('labelul').style.backgroundColor="#333333";    
  document.getElementById('botul').style.backgroundColor="#848686"; 
  }    
}  
var timedata="";
//////////////////download//////////////////////////
function DownloadFromHW(txre) { 
if(tryonline===1)
  window.alert("This function required hardware");
else if(Sceret===0)
  window.alert("Please login before download\n, refresh to login page");
else  
  {timeoutmessage="Download overtime, please wait";
  //myTimeout=setTimeout(TimeoutMessage,3000);    
  if(txre==="start")
    {const myTimeout = setTimeout(TimeoutMessage,3000);
    document.getElementById('labelul').style.backgroundColor="aliceblue";  
    document.getElementById('labelul').style.width="30px";
    retrieve("RET0",bufferz0);  //A  type 
    loopcontrol=1;      
    }
  if(txre==="REt0"  && loopcontrol===1) //icon type
    {retrieve("RET1",bufferz1); 
    loopcontrol++;
    document.getElementById('labelul').style.width="50px";
    }  
  if(txre==="REt1"  && loopcontrol===2)  //C input 2
    {retrieve("RET2",bufferz2);  //+type
      loopcontrol++;
    }
  if(txre==="REt2"  && loopcontrol===3)   //D line
    {retrieve("RET3",bufferz3);    //+type       
    loopcontrol++;  
    document.getElementById('labelul').style.width="70px";
    }    
  if(txre==="REt3"  && loopcontrol===4)   //
    {retrieve("RET4",bufferz4);           
    loopcontrol++;
    document.getElementById('labelul').style.width="90px";
    }  
  if(txre==="REt4"  && loopcontrol===5)
    {retrieve("MQSd",timedata);   
    loopcontrol++;
    document.getElementById('labelul').style.width="100px";  
    }
  if(txre==="mQsD"  && loopcontrol===6)
    {scd_bufferz();
    //clearTimeout(myTimeout);
    localStorage.setItem('plcdata',JSON.stringify(serialcelldata));  
    lookup=cursor;   
    document.getElementById('labelul').style.width="130px";
      //inputresponse(serialcelldata[0]); //init all drop down menu//  
    updatetable(FILLALL);       
    timeoutmessage="Hareware will not keep comment, Please use file to keep comment\n download successful";           
    document.getElementById('labelul').style.backgroundColor="#333333";
    }
  //else
  //  {
  //  window.alert("Please set time clock and try again"); 
  //  }            
  }  
} 


function TimeoutMessage(){               
  window.alert(timeoutmessage);
} 


//received table
function retrieve(datatosend,buffer) {   
  //console.log('retrieve');    
  let rxreall="";   
  let rxdata="";
  xhttp.onreadystatechange = function() {
  let txre="";   
  let tcount=1;
  let rxbuf="";
  if (this.readyState == 4 && this.status == 200) {      
      txre=this.responseText[0]+this.responseText[1]+this.responseText[2];           
      //rxreall=this.responseText;
      rxreall=this.responseText.replace("%20", " ");
      if(txre==="REt")  ////MQST MQSD Advance Setup 
        {txre=txre+this.responseText[3];
        for(var i=5;i<1686;i++)    //426
          {if(rxreall[i]==='*')
            break; 
          if(rxreall[i]==='%')    
            {//i++;                                                    
            buffer[tcount++]=parseInt(rxbuf);
            rxbuf="";     
            }
          else         
             rxbuf=rxbuf+rxreall[i];                      
          }        
        DownloadFromHW(txre); //get again 
        //console.log(txre,'=',rxreall);   //buffer //rxreall
        //console.log(txre,'=',buffer);   //buffer //rxreall
        }      
      if(this.responseText[3]==='D')  
        {if(txre==="tyf" || txre==="tyg" || txre==="tym")  //input 5  for commnet
          {let x=1;
          let onceonly=0;  
          for(var t=5;t<600;t++)
            {if(rxreall[t]==='*')
              break;             
            if((rxreall[t]==='!' || rxreall[t]==='^' || rxreall[t]==='*' ) && rxreall[t+1]===',')
              {if(txre==="tyf")                
                {if(rxreall[t]==='!' && rxreall[t+1]===',')
                  bufferzL5[x]=rxdata;//for comment
                if(rxreall[t]==='^' && rxreall[t+1]===',')
                  bufferzL6[x]=rxdata;//for comment    
                if(rxreall[t]==='*' && rxreall[t+1]===',') 
                  bufferzL7[x]=rxdata; //for extra                              
                }
              if(txre==="tyg")                
                {if(rxreall[t]==='!' && rxreall[t+1]===',')
                  bufferzU5[x]=rxdata;//for comment
                if(rxreall[t]==='^' && rxreall[t+1]===',')
                  bufferzU6[x]=rxdata;//for comment    
                if(rxreall[t]==='*' && rxreall[t+1]===',') 
                  bufferzU7[x]=rxdata; //for extra                           
                }                
              rxdata="";                           
              if(onceonly===0)
                {t++;
                x++;  
                onceonly=1;            
                }
              }    
            else                
              {if(rxreall[t]==',') 
                {bufferzL5[x]="";
                bufferzL6[x]="";    
                bufferzL7[x]="";    
                onceonly=0;
                x++;
                }
              else
                rxdata=rxdata+rxreall[t]; 
              }  
            }       
          txre=txre+this.responseText[3];         
          DownloadFromHW(txre);         
          }  
        if(txre==="mQs")  //timeclock date
          {timedata=this.responseText;
          txre=txre+this.responseText[3];         
          DownloadFromHW(txre);         
          }
        }    
      }   
    }         
  xhttp.open("GET","http://"+URL+"/action?go=" + datatosend, true);   
  xhttp.send();        
}  
  
//sub program for table TX RX and Run 
function uploadesp(datatosend,Length) { 
  if(tryonline===1)
    window.alert("This function required hardware");
  {if(Sceret===0)
      window.alert("Please login before upload\n, refresh to login page");
    else
    {if(datatosend==='swur')
         {document.getElementById('labelul').style.backgroundColor="aliceblue";  
         document.getElementById('labelul').style.width="130px";
         }        
    xhttp.onreadystatechange = function() {
    txre="";  
    if (this.readyState == 4 && this.status == 200) {  
        for(let t=0;t<6;t++)           
        txre=this.responseText[0]+this.responseText[1]+this.responseText[2];                                              
        if(txre==="Run")
        document.getElementById("runkey").style.backgroundColor = "red";
        else
        {if(txre==="SyS")  //for bing test
          {console.log('t34',txre);   
          }
        else
          {if(txre==="SWU")      //switch simulate return   
            {document.getElementById('labelul').style.backgroundColor="#333333";             
            rxcode=this.responseText;          
            for (let i=0;i<240;i++)          
              {instate[i]=parseInt(rxcode[i+10]);      //offset adjust         
              if(rxcode[i+250]==='0')  DeviceState[i]="OFF";
              else   DeviceState[i]="ON";
                {fbstatus1[i]=rxcode[i+490];     
                fbstatus2[i]=rxcode[i+730];     
                fbstatus3[i]=rxcode[i+970];     
                fbstatus4[i]=rxcode[i+1210];                      
                }
              }        
            showtable(txre);  
            //console.log('fbstatus1',rxcode);     
            }         
          else
            uploadnextturn(txre);       //for next turn     
          }  
        }
      }                  
    }   
    //console.log('txre',txre);
    if(Length>0)
      datatosend.length=Length;  
    xhttp.open("GET","http://"+URL+"/action?go=" + datatosend, true);   
    xhttp.send();  
    }    
  }  
}  

function showtable(txre)
{//console.log('showtable'); 
//console.log('txre1',txre); 
if(txre==="SWU")      
  {  
  updatestatus();
  updatecolor();
  updatetable(SIM);//gentable();
  }  
}  

function downloadsetup(txdata,systcell)  //txdata= "MQSD"
{//MQSU MQSD     
var xhtp = new XMLHttpRequest(); 
  xhtp.onreadystatechange = function() {
  txre="";  
  tyre="";
  xsetdev=4;
  ysetdev=7;
  tt=0;
  if(this.readyState == 4 && this.status == 200) {      
      txre=this.responseText[0]+this.responseText[1]+this.responseText[2]+this.responseText[3];                                       
      tyre=this.responseText;
      if(txre==="mQsD")   //mQsU is Download     
        {console.log('mqs upload ok',this.responseText);
        let x=0;let y=0;let z=0;
        for(tt=4;tt<500;tt++)
          {if(tyre[tt]=='%')
            {if(x++>=(xsetdev-1))
              {x=0;y++;
              if(y>=ysetdev)  
                break; //y=0;   
              }                                 
            systcell[x][y]="";              
            }  
          else                       
            systcell[x][y]=systcell[x][y]+tyre[tt];                                                            
          }                 
        }
      }
    }        
  console.log("txdata=",txdata);      
  xhtp.open("GET","http://"+URL+"/action?go="+txdata, true);     
  xhtp.send();  
}


////////////////////run and update//////////////////////
function CheckHWStatus(x) { 
  if(tryonline===1)
    window.alert("This function required hardware");
  else
  {let vdata;   
  if(x===0)
    vdata="MCK"; 
  else
    vdata="MCC"+localStorage.getItem("editpageSecret"); 
  xhttp.onreadystatechange = function() {
  //Sceret=0;
  if (this.readyState == 4 && this.status == 200) {      
    if(this.responseText[0]==='M' && this.responseText[1]==='C' && this.responseText[2]==='c')
      {if(this.responseText[4]==='Y')
        Sceret=1;  
      else
        PleaseLogin();  
      }
    else if(this.responseText[0]==='M' && this.responseText[1]==='C' && this.responseText[2]==='k')  
      {if(this.responseText[3]==='Q' && this.responseText[4]==='S')
        {document.getElementById("botstatus").innerText="MQTTOK";
        //document.getElementById("botstatus").style.color ="yellow";
        }
      else
        {document.getElementById("botstatus").innerText ="NORMAL";                        
        //document.getElementById("botstatus").style.color ="yellow";      
        window.alert("Check mqtt switch and wifi");
        }
      }        
    } 
  }  
  xhttp.open('GET','http://'+URL+'/action?go='+vdata, true);
  xhttp.send();
  }
}

function scd_bufferz()
{let type=0;
//Acstatus="";  

//statbuf=""; 
//svgtext="";    
let yb=0;
let xa=0;
for(yb=0;yb<ycount;yb++)        
  {for(xa=0;xa<xcount;xa++)     
    {type=bufferz0[yb*6+xa+1];
    serialcelldata[yb*48+xa*8]=type; //0
    if(type!="")
      {//serialcelldata[yb*48+xa*8+1]=bufferz1[yb*6+xa+1];//not enougth for 2048 decode before sending     
      serialcelldata[yb*48+xa*8+1]=(bufferz1[yb*6+xa+1]<<8)+type;  
      if(bufferz2[yb*6+xa+1]!="")
      {if((type>=40 && type<=43) || type==26)
        serialcelldata[yb*48+xa*8+2]=bufferz2[yb*6+xa+1];
      else
        serialcelldata[yb*48+xa*8+2]=(bufferz2[yb*6+xa+1]<<8)+type; //add type   2              
      }
      serialcelldata[yb*48+xa*8+4]=bufferz4[yb*6+xa+1]; 
      serialcelldata[yb*48+xa*8+5]=bufferzL5[yb*6+xa+1];    
      serialcelldata[yb*48+xa*8+6]=bufferzL6[yb*6+xa+1];    
      serialcelldata[yb*48+xa*8+7]=bufferzL7[yb*6+xa+1];        
      if(yb>=20)  
        {serialcelldata[yb*48+xa*8+5]=bufferzU5[(yb-20)*6+xa+1];         
        serialcelldata[yb*48+xa*8+6]=bufferzU6[(yb-20)*6+xa+1];  
        serialcelldata[yb*48+xa*8+7]=bufferzU7[(yb-20)*6+xa+1]; 
        }
      } 
    serialcelldata[yb*48+xa*8+3]=bufferz3[yb*6+xa+1];  
    }                  
  } 
}
)rawliteral";
