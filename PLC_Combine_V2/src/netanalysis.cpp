#include "../include/plcsvg.h"
//#define byte unsigned char
byte netnum[6][40];
//byte analogval[6][10];
byte digstate[244];
byte anastate[244];
//byte col3out[6][10];
byte x,y,t;
byte netcount=1;

void updatealltobigger(byte vala,byte valb)
{
byte xx,yy;
if(vala!=0 && valb!=0)
  {for(yy=0;yy<ycount;yy++) 
    {for(xx=0;xx<xcount;xx++) //xx=1  
      {if(netnum[xx][yy]==vala)
        netnum[xx][yy]=valb;      
      }
    }
  }
}
void netanalysis()
{byte col3out;
byte xx,yy; 
byte outsearch=0;
Deviceinit=1;
netcount=0;
for(t=0;t<240;t++)  //t=1
  digstate[t]=0;    //off state
//for(t=1;t<2;t++)
  {for(y=0;y<ycount;y++) 
    for(x=0;x<xcount;x++) //x=1
    {netnum[x][y]=0;  
    digstate[netnum[x][y]]=0;    
    BoxState[x][y].Linknum=0;      
    }
  for(y=0;y<ycount;y++) 
    {for(x=0;x<(xcount);x++)   //x=1
      {col3out=dataz3[x][y];
      if((col3out&4)==4 && x<(xcount-1))  //horizontal line
        {if(netnum[x][y]==0 && netnum[x+1][y]==0)  
          {netcount++;
          netnum[x][y]=netcount;  
          netnum[x+1][y]=netcount;             
          }                
        else   
          {if(netnum[x+1][y]==0)
              netnum[x+1][y]=netnum[x][y];
          else if(netnum[x][y]==0)
              netnum[x][y]=netnum[x+1][y];                            
          else if(netnum[x][y]!=netnum[x+1][y])
              updatealltobigger(netnum[x][y],netnum[x+1][y]);         
          }                                                                                 
        }

      if((col3out&2)==2 && y<9)  //vertical down line
        {if(netnum[x][y]==0 && netnum[x][y+1]==0)  
          {netcount++;
          netnum[x][y]=netcount;  
          netnum[x][y+1]=netcount;                      
          }
        else 
          {if(netnum[x][y+1]==0)
              netnum[x][y+1]=netnum[x][y];
          else if(netnum[x][y]==0)
              netnum[x][y]=netnum[x][y+1];                                       
          if(netnum[x][y]!=netnum[x][y+1])   
              updatealltobigger(netnum[x][y],netnum[x][y+1]);      
          }                                                                           
        }        
      if((col3out&1)==1 && y>1)  //vertical up line
        {if(netnum[x][y]==0 && netnum[x][y-1]==0)  
          {netcount++;
          netnum[x][y]=netcount;  
          netnum[x][y-1]=netcount;                      
          }
        else 
          {if(netnum[x][y-1]==0)
              netnum[x][y-1]=netnum[x][y];
          else if(netnum[x][y]==0)
              netnum[x][y]=netnum[x][y-1];
          if(netnum[x][y]!=netnum[x][y-1])   
              updatealltobigger(netnum[x][y],netnum[x][y-1]);                                   
          }                                                                                    
        }                             
      }   
    }
  }     

for(y=0;y<ycount;y++) 
  {for(x=0;x<(xcount-1);x++)   //nothing in front, generate new netcount
    {if((dataz3[x][y]&4)!=4 && dataz3[x+1][y]==0)
      {netcount++;
      netnum[x+1][y]=netcount; 
      if(netnum[x][y]==0)
        {netcount++;
        netnum[x][y]=netcount;
        }
      }            
    }
  }    

for(y=0;y<ycount;y++) //for link
  {for(x=0;x<xcount;x++)   
    {outsearch=0;
    if(dataz0[x][y]==23)
      {//Serial.print("Linknum 23 found");
      for(yy=0;yy<ycount;yy++) //for link
        {for(xx=0;xx<xcount;xx++)   
          {//type = link;  link id = Relay ID [xx][yy]>>8; Link ID =dataz2[x][y]
          if(dataz0[xx][yy]==43 && (dataz1[xx][yy])==(dataz2[x][y])) //relay id and link match
            {BoxState[x][y].Linknum=netnum[xx][yy];  //use link ID as Linknum;   old=netnum[xx][yy];                       
            BoxState[xx][yy].Linknum=netnum[xx][yy];
            //Serial.print("Linknum=");
            //Serial.println(BoxState[x][y].Linknum);
            outsearch=1; //serach next 23            
            break;
            }
          }
        if(outsearch==1)
        break;  
        }     
      }      
    }  
  }  
}       



// 1 input device, 2 input switch, 4  analog    
//byte eONDevice[63]={0,1,2,3,4,5,6,7,8,9,1,*,2,3,4,5,6,7,8,9,2,*,2,3,4,5,6,7,8,9,3,*,2,3,4,5,6,7,8,9,04,*,2,3,4,5,6,7,8,9,5,*,2,3,4,5,6,7,8,9,6,1,2};
byte OnOffdevice[63]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,4,0,2,2,2,2,2,2,2,2,2,2,1,1,1,12,9,1,0,1,5,0,5,0,0,5,5,0,0,0,0,0,0,0,1,1,1,1};

byte  GetlastScan()//update instate
{byte lasty;       
for(y=0;y<ycount;y++) 
  {for(x=0;x<xcount;x++)     
    {if(dataz0[x][y]>0 || dataz3[x][y]>0)
      lasty=y;                          
    }
  }   
return lasty+1;
}


void  updatestate()//update instate
{byte type;
for(y=0;y<ycount;y++)  //for input
  {for(x=0;x<xcount;x++)
    {digstate[netnum[x][y]]=OFF; //OFF ALL NET BETFOR OF
    //BoxState[x][y].DeviceState=OFF;
    }
  }  
//Serial.printf("type=: %d DS=: %d\n",dataz0[0][0],BoxState[0][0].DeviceState);
for(x=0;x<xcount;x++)     
  {for(y=0;y<ycount;y++)  //for input
    {type=dataz0[x][y];                                        
    if(x==0 && (dataz3[x][y]&4)==4)
      {digstate[netnum[x+1][y]]=ON;      
      }
    else
      {if(type>0 && x<5)
        {if(BoxState[x][y].DeviceState==CLOSE)    //switch  2
          {if((OnOffdevice[type]&2)==2 && (digstate[netnum[x][y]]==ON || x==0))          //switches                    
            {digstate[netnum[x+1][y]]=ON;                    
            }
          }      
        if(BoxState[x][y].DeviceState==ON)  
          {if((OnOffdevice[type]&1)==1)              //self enable 1            
            digstate[netnum[x+1][y]]=ON;                                                                
          }                            
        }      
      }
    }
  }
}  