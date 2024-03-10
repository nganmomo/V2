#pragma once
#include <Arduino.h>
#include <EEPROM.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <time.h>
//#define DEBUG
#define ipcworld
#define MQTTACTIVE
//#define SWITCHTOBROKER
//*******************************//
#define BYPASSSETUP
//#define CreateUnicode
#define CheckUnicode    //software lock security
//*******************************//
#define ver2    

//#define chphpw      //bypass check phone password
//#define uart1       //software uart   

#define inputoff    1
#define analogoff   8
#define outputoff   33

#define writeonly   0
#define readwrite   1

#define DPLAY       1
#define VERIFY      2
#define DWORK       3
#define AWORK       4
#define KEYINIT     5
#define JDONE       6

#define ON          1
#define OFF         0
#define CLOSE       3 //not for switches
#define OPEN        2
#define xcount      6
#define ycount      40

#define eessid      0           //50
#define adddataz0   50          //240       8 bit            
#define adddataz1   290         //240       8 bit shif 8
#define adddataz2   530         //240       8 bit shit 8
#define adddataz3   770         //240       8 bit 
#define adddataz4   1010        //480       16 bit
#define MQSTdata    1490        //500
#define phpw        2000        //20
#define editpw      2020        //20    
#define MQtopic     2040        //40  
#define phonesize   2080        //4 
#define keychar     2084        //400
#define unicode     2484        //16
#define timeclock   2450        //500
#define mqttpass    2950        //
#define EEPROM_SIZE 3072        //

//https://www.espressif.com/sites/default/files/documentation/esp32-s3_hardware_design_guidelines_en.pdf
//GPIO 26-32 SPI flash
//PSRAM 33-37
//ESP32-S3R8 ESP32-S3R8V GPIO 33-37
//Should not use 0 3 45 46
//38 led rgb
#ifdef ver1     //T board
#define SERIAL1_TX_PIN 47 
#define SERIAL1_RX_PIN 45 

#define Pin1 47
#define Pin2 48
#define Pin3 45
#define Pin4 35
#define Pin5 35
#define Pin6 36
#define Pin7 37   
#define Pin8 38

#define Pout1 8
#define Pout2 18
#define Pout3 17
#define Pout4 16
#define Pout5 15
#define Pout6 7
#define Pout7 6   
#define Pout8 5
#define Ain0 0
#define Ain1 9
#define Ain2 10
#define Ain3 11
#define Ain4 12

#define SETUPSTATE  1                //17
#define Enmqttclient  16           //RUN OR SIM BUTTON    
#define mqttbrokenpin  15
#define setuppin  13
#endif
#ifdef ver2     //squre board

#define SERIAL1_TX_PIN 47 
#define SERIAL1_RX_PIN 45 

#define MaxIn  8
#define Pin1 7
#define Pin2 15    //DEBUG PIN  
#define Pin3 16
#define Pin4 17
#define Pin5 18
#define Pin6 8
#define Pin7 46   
#define Pin8 13     

#define MaxOut  8
#define Pout1 42
#define Pout2 41
#define Pout3 40
#define Pout4 39
#define Pout5 37
#define Pout6 36
#define Pout7 35   
#define Pout8 45

#define Ain1 4
#define Ain2 5
#define Ain3 3
#define Ain4 6

#define Aout1 9
#define Aout2 10
#define Aout3 11
#define Aout4 12   

#define setuppin    1         //SETUP BUTTON
#define pw_enable_sw   2 
#define Enmqttclient  16   
#define mqttbrokenpin  15 

//#define mqttbrokenpin  37
//#define mqttclientpin  38
#endif

#ifdef ver3             //with circle watch inside//
#define SERIAL1_TX_PIN 47 
#define SERIAL1_RX_PIN 45 

#define Pin1 37
#define Pin2 38
#define Pin3 39
#define Pin4 40
#define Pin5 41
#define Pin6 42
#define Pin7 2   
#define Pin8 1

#define Pout1 8
#define Pout2 18
#define Pout3 17
#define Pout4 16
#define Pout5 15
#define Pout6 7
#define Pout7 6
#define Pout8 5   

#define Ain1 14
#define Ain2 13
#define Ain3 12
#define Ain4 11

#define Aout1 9
#define Aout2 10
#define Aout3 35
#define Aout4 36

#define setuppin        15  //work with SETUPSTATE
#define setuppassword   7  //work with SETUPSTATE

#endif
#ifdef ver4             //4 input/output small PLC
#define SERIAL1_TX_PIN 47 
#define SERIAL1_RX_PIN 45 

#define Pin1 35
#define Pin2 36
#define Pin3 37
#define Pin4 38
#define Pin5 0
#define Pin6 0
#define Pin7 0
#define Pin8 0

#define Pout1 21        //4066 convert voltage to 3.3V
#define Pout2 14
#define Pout3 13
#define Pout4 12
#define Pout5 0        //4066 convert voltage to 3.3V
#define Pout6 0
#define Pout7 0
#define Pout8 0

#define Aout0 0
#define Aout1 0
#define Aout2 0
#define Aout3 0
#define Aout4 0

#define Ain0 0
#define Ain1 0
#define Ain2 0
#define Ain3 0
#define Ain4 0

#define setuppin  4         //SETUP BUTTON
#define pw_enable_sw  7 
//#define mqttbrokenpin  37
//#define mqttclientpin  38
#endif
#ifdef ver5             //5 Liligo 4 relay
#define invout
//#define invin
#define Pin1 0
#define Pin2 0
#define Pin3 0
#define Pin4 0
#define Pin5 0
#define Pin6 0
#define Pin7 0
#define Pin8 0

#define Pout1 21        
#define Pout2 19
#define Pout3 18
#define Pout4 5
#define Pout5 0        //4066 convert voltage to 3.3V
#define Pout6 0
#define Pout7 0
#define Pout8 0

#define Aout0 0
#define Aout1 0
#define Aout2 0
#define Aout3 0
#define Aout4 0

#define Ain0 0
#define Ain1 0
#define Ain2 0
#define Ain3 0
#define Ain4 0

#define setuppin  13         //SETUP BUTTON
#define pw_enable_sw 27 
//#define mqttclientpin  36
#endif
#ifdef  ver6    //KC868
#define SERIAL1_TX_PIN 17 
#define SERIAL1_RX_PIN 16 

#define MaxOut  4
#define MaxIn   4
#define UartTx  17
#define UartRx  16

#define Pin1 36
#define Pin2 39
#define Pin3 27
#define Pin4 14

#define Pout1 2        
#define Pout2 15
#define Pout3 29
#define Pout4 26

#define Ain0 32
#define Ain1 33
#define Ain2 34
#define Ain3 35

#define Aout 27
#define Aout 14

#define Timp2 12
#define Timp1 16

#define Beep  18

#define IRD   23
#define IRS   22  

#define setuppin  19         //SETUP BUTTON
#define pw_enable_sw 21 
#endif
#define SETUPSTATE 0
extern char mssid[20];
extern char mpass[20];
extern char MQTINTERVAL[5][4];  
extern byte SerialMode;

extern void    rwswiches(int wonly);
extern void    runplc(uint32_t realtimeloop);
extern void    initplc();
extern byte    OnOffdevice[63];         //check table
extern byte    Deviceinit;
struct boxstate
{
byte DeviceState;
byte Linknum;
};
extern boxstate BoxState[6][40];
//timeclock//
extern byte clkid[17];
extern int32_t setbt[17];
extern int32_t setet[17];
extern int32_t setbd[17];
extern int32_t setem[17];
extern int32_t setbm[17];
extern int32_t seted[17];
extern int32_t setby[17];
extern int32_t setey[17];
extern int32_t setbdoy[17];
extern int32_t setedoy[17];
extern byte cycle[17];
extern int UTC;
extern int32_t currenttime;
extern int32_t currentdateofyear;
//netanalysis
extern byte netnum[6][40];
extern void updatestate();
extern void netanalysis();
extern byte GetlastScan();
extern byte digstate[244];
extern byte anastate[244];
//plc submain//
extern byte asxii2int(char *payload,byte offset); 
extern int numchartowrite;
extern char keyvalue[20];
extern char variable[1600];
extern byte Rtimersetflag[9];
extern size_t   buf_len;  
extern int8_t   mqttrun;
extern void receivedplcdata();    
extern void receivedplc(int eedata,int maxlen,char rw,int offset);     
extern byte cellkeyboard(byte work);   
extern void switchsimulate(byte stateonly);    
extern void systemsetup(); 
extern void receivedplcTable();    
extern byte getdata100(int gx,int gy,char* rebuf,int length,char *pt,char endsign=0);

extern void saveint16(char *variable,uint16_t (*dataz)[40],byte start,byte end);
extern void readinput(uint32_t realtimeloop,byte Lasty);
extern void updateinstate(uint32_t realtimeloop,byte lasty);
extern void ioinit();
///////MQTT//////////
extern void connectToMqtt();
extern void clientsetup(byte mqtt);
extern char MYTOPIC[5][64];  // = "mytopic2";
extern void disconnectmqtt();
extern  const char* ssid;
extern  const char* password;
//EEPROM
extern void eepromread(int offset,uint16_t (*dataz)[40],byte type);
extern void eepromwrite(int offset,uint16_t (*dataz)[40],byte type);
extern void eewClear(int offset,char keyc,int length);
extern void eewbyte(int offset,char* keyc,int length);
extern void eerbyte(int offset,char* keyc,int length); //add end sign later
extern void eewpassid(int offset,char* iddata,char* pwdata);
extern void eerpassid(int offset,char* iddata,char* pwdata);
extern void eewint16(int offset,int16_t data);
extern int16_t eerint16(int offset);
///////////////////
//for phone
extern String displaymess;
//for hardware//
extern char phonebuf[16];
extern byte Pinout[9];
extern byte Pinin[9];
extern byte analogpin[5];
extern byte analogpout[5];
extern byte inreadstate[9];
extern byte outstatus[9];
extern byte SerachFlag;
extern byte buttonnum;          //xhttp control button
extern byte buttonmode;
extern byte Rbuttonnum;          //xhttp control button
extern byte Rbuttonmode;
//MQTT
extern char EPHMQTT[2];
extern char EPLCMQTT[2];
extern byte getdata(byte gx,byte gy,char* rebuf);
extern void clientTX(byte topic);
extern byte clientTXStatus[4];
extern void initmattdate();

extern char RxAnaValue[4][9][4];   
extern byte RxIOpinit[4][9]; 
extern char TxAnaValue[4][8][4];   
extern byte TxIOpinit[4][8];

extern byte RelayOnOffstate[16];
extern int  rxpin;
extern byte MqttDisplay[16];
extern byte INKeyreached;
extern byte PhoneKeyIn;
extern byte mqttcellinstate;
extern byte mqttconnected;
extern byte wificonnected;
extern byte mqtten;
extern byte checkmqtt();
////////////////////
extern uint16_t dataz0[6][40];//0  sign 16
extern uint16_t dataz1[6][40];//1  id    32
extern uint16_t dataz2[6][40];//2  link  32
extern uint16_t dataz3[6][40];//3  line  16
extern uint16_t dataz4[6][40];//4  set   32
extern char   dataz100g7[100];//4  set   32
extern uint32_t timer[2][8];
extern byte beforestate[16];  //link cycle for 16 link 
extern unsigned long counter[16];
extern int16_t d2abuf[9];
extern byte    d2aupedge[9];
extern byte    d2adownedge[9];
extern byte    deboun44[9];
///run mode/////////////
extern int8_t  Runmode;
//for phone timeout
extern char phonepw[16];
extern char Storephonepw[16];
extern char Storeeditpw[16];
extern byte ctlpermit;
extern byte adminpermit;
//for phone timer
extern unsigned long phonestartTime;
extern unsigned long phoneelapsedTime;
extern unsigned long phonetimeset;
//clocktimer
void setuptimeclock(byte load);
//void inserttimeclock();

extern void anykey(byte a);
extern char encrytext[12];
extern char comparetext[12];
extern uint64_t chipId;
extern void encrypt(char* encrytext,uint64_t chipId);
extern void brokersetup(int port);
extern void brokerloop();
/*
void anykey(int test,int point1,int point2);
Serial.println("anykey");  
while (!Serial.available());
Serial.read();
*/
//void brokersetup(int port);
//void brokerloop();