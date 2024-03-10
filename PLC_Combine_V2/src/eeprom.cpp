#include "../include/plcsvg.h"



void eepromread(int offset,uint16_t (*dataz)[40],byte type)
{//most=1 //less=0 //full =2
EEPROM.begin(EEPROM_SIZE);    
int16_t tdata;
for(int y=0;y<ycount;y++)  
    {for(int x=0;x<xcount;x++) 
      {if(type==2)
        {tdata=EEPROM.read(offset++); //higher byte
        tdata=tdata<<8;
        tdata=tdata | EEPROM.read(offset++);
        dataz[x][y]=tdata;    
        }      
      if(type==1 || type==0)          
         dataz[x][y]=EEPROM.read(offset++); //higher byte                        
      }
    }
EEPROM.end();      
}

void eepromwrite(int offset,uint16_t (*dataz)[40],byte type)
{//most=1 //less=0 //full =2
EEPROM.begin(EEPROM_SIZE);
for(int y=0;y<ycount;y++)  
    {for(int x=0;x<xcount;x++) 
      {if(type==2)
        {EEPROM.write(offset++,dataz[x][y]>>8); //higher byte
        EEPROM.write(offset++,dataz[x][y]); //lower byte         
        }
      if(type==1 || type==0)  
        EEPROM.write(offset++,dataz[x][y]); //lower byte        
      }
    }        
EEPROM.commit();     
EEPROM.end();   
}
//will combin later
void eewint16(int offset,int16_t data)
{int t;
EEPROM.begin(EEPROM_SIZE);    
EEPROM.write(offset,data>>8); //higher byte
EEPROM.write(offset+1,data); //lower byte        
EEPROM.commit();     
EEPROM.end();   
}

int16_t eerint16(int offset)
{int16_t data;
EEPROM.begin(EEPROM_SIZE);
data=EEPROM.read(offset); 
data=data<<8;
data=data | EEPROM.read(offset+1);   
EEPROM.commit();     
EEPROM.end();   
return data;
}

void eewClear(int offset,char keyc,int length)
{int t;
EEPROM.begin(EEPROM_SIZE);
for(t=0;t<length;t++)     
    EEPROM.write(offset+t,keyc); //lower byte         
EEPROM.commit();     
EEPROM.end();   
}


void eewbyte(int offset,char* keyc,int length)
{int t;
EEPROM.begin(EEPROM_SIZE);
for(t=0;t<length;t++)     
    EEPROM.write(offset+t,keyc[t]); //lower byte         
EEPROM.commit();     
EEPROM.end();   
}

void eerbyte(int offset,char* keyc,int length)
{int t;
EEPROM.begin(EEPROM_SIZE);
for(t=0;t<length;t++)     
    keyc[t]=EEPROM.read(offset+t); //lower byte         
EEPROM.commit();     
EEPROM.end();   
}

void eewpassid(int offset,char* iddata,char* pwdata)
{int t;
EEPROM.begin(EEPROM_SIZE);
for(t=0;t<20;t++)     
    EEPROM.write(offset+t,iddata[t]); //lower byte         
offset=offset+20;
for(t=0;t<20;t++)   
    EEPROM.write(offset+t,pwdata[t]); //lower byte        
EEPROM.commit();     
EEPROM.end();   
}

void eerpassid(int offset,char* iddata,char* pwdata)
{int t;
    EEPROM.begin(EEPROM_SIZE);
for(t=0;t<20;t++)     
    iddata[t]=EEPROM.read(offset+t); //lower byte         
offset=offset+20;
for(t=0;t<20;t++)   
    pwdata[t]=EEPROM.read(offset+t); //lower byte          
EEPROM.commit();     
EEPROM.end();   
}
