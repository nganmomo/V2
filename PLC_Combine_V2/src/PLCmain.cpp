#include "../include/plcsvg.h"
#include "icontext.h"
#include "homehw.h"
#include "filehandle.h"
#include "helppopup.h"
#include "homeweb.h"
#include "mobile.h"
#include "mqsetup.h"
#include "phone.h"
#include "setupclock.h"

//#include "svgpick.h"
#include "svgplccell.h"
#include "Property.h"
//#include "plcsvgut.h"
#include "Linkhardware.h"
//#include "hwsim.h"
//#include "helppopup.h"
//#include "mqsetup.h"
#include "plcsvgcss.h"
//#include "qrcode.h"
//#include "esp_timer.h"
//#include "img_converters.h" 
//#include "fb_gfx.h"
#include <esp_task_wdt.h>
#include "soc/soc.h"             // disable brownout problems
#include "soc/rtc_cntl_reg.h"    // disable brownout problems
#include "esp_http_server.h"
const int timeZone = -6;         // Your time zone in hours (UTC)
WiFiUDP ntpUDP;
//NTPClient timeClient(ntpUDP, "pool.ntp.org");
NTPClient timeClient(ntpUDP, "pool.ntp.org", timeZone * 3600, 60000);
//////////HW COUNTER///////
//const int counterPin = 7;  // Replace with the GPIO pin you want to use as the counter input
//volatile int counterValue = 0;
//////////HW COUNTER///////
//MqttBroker
//char mqtpass[10];
//MqttBroker
#ifdef  uart1
uint16_t uartmaster(int length); 
void SerialRTXLoop(char* buffer,byte length);
#endif
void coolboot();
void ioinit();
void downloadinit();
// Replace with your network credentials
const char* ssid =""; //"ATT3jl8Tns";
const char* password ="";//"6mrk8iyf26vn";
char mssid[20];
char mpass[20];
byte setupmode=0;
//Serialloop
byte Serialmode;
byte Srxcount;
char SRXbuffer[255];
char STXbuffer[255];
////////////////
uint16_t connectcount=0;
byte Deviceinit=0;
byte buttonnum=0;
byte buttonmode;
byte Rbuttonnum=0;
byte Rbuttonmode;
byte Pinout[9]={0,Pout1,Pout2,Pout3,Pout4,Pout5,Pout6,Pout7,Pout8};
byte Pinin[9]={0,Pin1,Pin2,Pin3,Pin4,Pin5,Pin6,Pin7,Pin8};
byte analogpin[5]={0,Ain1,Ain2,Ain3,Ain4};
//byte analogpout[5]={Aout0,Aout1,Aout2,Aout3,Aout4};

String MYSSID = "";
String MYPASSWORD = "";

#define PART_BOUNDARY "123456789000000000000987654321"
int32_t currenttime;
int32_t currentdateofyear;
int8_t  Runmode = 1;
int8_t  mqttrun = 1;
byte    mqtten=0;
uint16_t dataz0[6][40];//0  sign 16
uint16_t dataz1[6][40];//1  id    32
uint16_t dataz2[6][40];//2  link  32
uint16_t dataz3[6][40];//3  line  16
uint16_t dataz4[6][40];//4  set   32
char     dataz100g7[100];//4  set   32
boxstate BoxState[6][40];
int64_t keypassword=0;
int64_t timeloop=10000000;//10000000
static const char* _STREAM_CONTENT_TYPE = "multipart/x-mixed-replace;boundary=" PART_BOUNDARY;
static const char* _STREAM_BOUNDARY = "\r\n--" PART_BOUNDARY "\r\n";
static const char* _STREAM_PART = "Content-Type: image/jpeg\r\nContent-Length: %u\r\n\r\n";

//////////HW COUNTER///////
//void IRAM_ATTR counterInterruptHandler() { 
//counterValue++;  // Increment the counter value on each interrupt  
//if(counterValue>10) digitalWrite(42,ON);
//if(counterValue>20) {digitalWrite(42,OFF);
//counterValue=0;}
//}
//////////HW COUNTER///////

httpd_handle_t controller_httpd = NULL;
httpd_handle_t stream_httpd = NULL;
void saveint16(char *variable,uint16_t (*dataz)[40],byte start,byte end);
//step2
static esp_err_t index_handler_phone(httpd_req_t *req){
  httpd_resp_set_type(req, "text/html");  
  return httpd_resp_send(req, (const char *)INDEX_HTML_phone, strlen(INDEX_HTML_phone));//8088 mobile phone/
}

static esp_err_t index_handler_homehw(httpd_req_t *req){
  httpd_resp_set_type(req, "text/html");
  return httpd_resp_send(req,(const char *)INDEX_HTML_homehw, strlen(INDEX_HTML_homehw));//8088/PLC main enter 
}

static esp_err_t index_handler_filehandle(httpd_req_t *req){
  httpd_resp_set_type(req, "text/html");
  return httpd_resp_send(req,(const char *)INDEX_HTML_filehandle, strlen(INDEX_HTML_filehandle));//8088/PLC main enter 
}

static esp_err_t index_handler_mqsetup(httpd_req_t *req){
  httpd_resp_set_type(req, "text/html");    
  return httpd_resp_send(req, (const char *)INDEX_HTML_mqsetup, strlen(INDEX_HTML_mqsetup));//8088/KEYS keyboard /
}

static esp_err_t index_handler_helppopup(httpd_req_t *req){
  httpd_resp_set_type(req, "text/html");    
  return httpd_resp_send(req, (const char *)INDEX_HTML_helppopup, strlen(INDEX_HTML_helppopup));//8088/KEYS keyboard /
}

static esp_err_t index_handler_mobile(httpd_req_t *req){
  httpd_resp_set_type(req, "text/html");    
  return httpd_resp_send(req, (const char *)INDEX_HTML_mobile, strlen(INDEX_HTML_mobile));//8088/KEYS keyboard /
}
/*
static esp_err_t index_handler_svgPick(httpd_req_t *req){
  httpd_resp_set_type(req, "text/js");
  return httpd_resp_send(req, (const char *)INDEX_HTML_svgPick, strlen(INDEX_HTML_svgPick));//
}
*/
static esp_err_t index_handler_svgplccell(httpd_req_t *req){
  httpd_resp_set_type(req, "text/js");
  return httpd_resp_send(req, (const char *)INDEX_HTML_svgplccell, strlen(INDEX_HTML_svgplccell));//
}

static esp_err_t index_handler_icontext(httpd_req_t *req){
  httpd_resp_set_type(req, "text/js");
  return httpd_resp_send(req, (const char *)INDEX_HTML_icontext, strlen(INDEX_HTML_icontext));//
}

static esp_err_t index_handler_Property(httpd_req_t *req){
  httpd_resp_set_type(req, "text/js");
  return httpd_resp_send(req, (const char *)INDEX_HTML_Property, strlen(INDEX_HTML_Property));//not used 
}

static esp_err_t index_handler_Linkhardware(httpd_req_t *req){
  httpd_resp_set_type(req, "text/js");
  return httpd_resp_send(req, (const char *)INDEX_HTML_Linkhardware, strlen(INDEX_HTML_Linkhardware));//
}

static esp_err_t index_handler_setupclock(httpd_req_t *req){
  httpd_resp_set_type(req, "text/html");
  return httpd_resp_send(req, (const char *)INDEX_HTML_setupclock, strlen(INDEX_HTML_setupclock));//
}

static esp_err_t index_handler_plcsvgcss(httpd_req_t *req){
  httpd_resp_set_type(req, "text/css");    
  return httpd_resp_send(req, (const char *)INDEX_HTML_plcsvgcss, strlen(INDEX_HTML_plcsvgcss));//8088/KEYS keyboard /
}

static esp_err_t index_handler_homeweb(httpd_req_t *req){
  httpd_resp_set_type(req, "text/html");    
  return httpd_resp_send(req, (const char *)INDEX_HTML_homeweb, strlen(INDEX_HTML_homeweb));//8088/KEYS keyboard /
}

//INDEX_HTML3 for cell phone api

int numchartowrite;
char variable[1600] = {0,};  //600
char ReturnSign;
size_t buf_len;  


static esp_err_t cmd_handler(httpd_req_t *req){  
  char*  buf;
  numchartowrite=4;
  buf_len = httpd_req_get_url_query_len(req) + 1;
  if (buf_len > 1) {
    buf = (char*)malloc(buf_len);
    if(!buf){
      httpd_resp_send_500(req);
      return ESP_FAIL;
    }
    if (httpd_req_get_url_query_str(req, buf, buf_len) == ESP_OK) {
      if (httpd_query_key_value(buf, "go", variable, sizeof(variable)) == ESP_OK) {
      } else {
        free(buf);
        httpd_resp_send_404(req);
        return ESP_FAIL;
      }
    } else {
      free(buf);
      httpd_resp_send_404(req);
      return ESP_FAIL;
    }
    free(buf);
  } else {
    httpd_resp_send_404(req);
    return ESP_FAIL;
  }
  int res = 0;
  //////////////////////////////////   
  if(res){
    return httpd_resp_send_500(req);
  }   
  Runmode=0;    //STOP RUN PLC      
  //Serial.print("variable1=");
  //Serial.println(variable);
  ReturnSign=variable[2];
  if(variable[2]<0x60)
    ReturnSign=variable[2]+0x20;     //to lower case
  if(variable[0]=='k' && variable[1]=='e' && variable[2]=='y') //update cell key char
    {//Serial.println("key");
    int t;
    if(variable[3]=='s')
      {//mobile.js   http://192.168.1.84:8088/KEYS                      
      eewbyte(keychar,&variable[4],350);       
      for(t=60;t<350;t++)      
        {if(variable[t]=='*' && variable[t+1]=='^' && variable[t+2]=='^')
          {eewbyte(MQtopic,&variable[t+3],33);           
          break;
          }
        }      
      for(t=t;t<350;t++)      
        {if(variable[t]=='*' && variable[t+1]=='$' && variable[t+2]=='^')
          {eewbyte(phonesize,&variable[t+3],2);           
          break;
          }
        }             
      for(t=t;t<350;t++)      
        {if(variable[t]=='*' && variable[t+1]=='^' && variable[t+2]=='*')
          {eewbyte(phpw,&variable[t+3],9);           
          break;
          }
        }
      for(t=t;t<350;t++)      
        {if(variable[t]=='*' && variable[t+1]=='$' && variable[t+2]=='*')
          {eewbyte(editpw,&variable[t+3],9);           
          break;
          }
        }         
      }
    if(variable[3]=='r' || variable[3]=='w') //read and read with password (must with switch)
      {eerbyte(keychar,&variable[4],350);     
      for(t=60;t<350;t++)     //keyboard initial
        {if(variable[t]=='*' && variable[t+1]=='$' && variable[t+2]=='^')                         
          break;
        }                     
      if(variable[3]=='w')  //with xy+password
        numchartowrite=t+5+25;
      else  
        numchartowrite=t+5;   //with xy no password
      variable[3]='R'; 
      }    
    ReturnSign='y';   //numchartowrite default 6   
    }      
  if(variable[0]=='m' && variable[1]=='o' && variable[2]=='b') //mobile   mobo96 verify password
    {if(variable[3]=='o')
      numchartowrite=cellkeyboard(VERIFY);  //staticpromipcw.h local remote.js    
    if(variable[3]=='k')
      numchartowrite=cellkeyboard(DWORK); 
    if(variable[3]=='t')
      numchartowrite=cellkeyboard(DPLAY);      
    displaymess.toCharArray(&variable[4],displaymess.length()+1);  
    numchartowrite=displaymess.length()+4;   //http://192.168.1.84:8088/MOB   feedback unchange   
    Runmode=1;   
    }
  if(variable[0]=='s' && variable[1]=='w' && variable[2]=='u') //switch simulation Tested
    {Runmode=10; 
    for(int t=0;t<10000;t++) //wait for limited time
       {delay(1);
       if(Runmode==1) //break when complete a cycle
          {//Serial.println("Runmode=10"); 
          break;
          }
       }    
    //switchsimulate(1);  
    ReturnSign='U';   
    }
  if(variable[0]=='M' && variable[1]=='Q' && variable[2]=='S') //MQTT Uploadsetup MQST Tested
    {systemsetup();               
    //Serial.print("variable=");
    //Serial.println(variable);
    Runmode=1;    //RUN PLC    
    }  
  if(variable[0]=='M' && variable[1]=='C' && variable[2]=='K') //MQTT Uploadsetup MQST Tested
    {  
    if(mqttconnected==1) variable[3]='Q';
    else  variable[3]='N';
     if(Runmode) variable[4]='S';
    else  variable[4]='S';
    numchartowrite=5;
    Runmode=1;    //RUN PLC    
    }    
  if(variable[0]=='M' && variable[1]=='C' && variable[2]=='C') //Check password
    {if(digitalRead(pw_enable_sw)==1)      //if pw_enable_sw==1 bypass check password
      {variable[4]='Y';adminpermit=0;}  //admin condition
    else
      {byte t;      
      eerbyte(editpw,Storeeditpw,9);
      for(t=0;t<14;t++)
        {if(variable[t+4]!=Storeeditpw[t])
          break;
        }            
      if(t<8) {variable[4]='N';adminpermit=1;}  //fail 
      else  {variable[4]='Y';adminpermit=0;}    //pass
      }
    Runmode=1;    //RUN PLC    
    }      
  /////////////////////////////////////////////////////////////////////////////////////    
  if(variable[0]=='t' && variable[1]=='x')  //uploadespStart
    {receivedplcdata();  
    if(variable[2]=='K')        
       Runmode=2;  
    }   
  if(variable[0]=='R' && variable[1]=='E' && variable[2]=='T') //PLC table sent back
    {receivedplcTable(); //download from PLC    
    } 
  if(variable[0]=='t' && variable[1]=='y' && variable[2]=='G' && variable[3]=='D')  //after download
      {Serial.println("txGD");    
        Runmode=1;  
      }
  //for test below    
  //for(int t=0;t<10;t++)
  //variable[t]=t+0x30;
  //numchartowrite=12;
  //Serial.print("Send=");
  //Serial.println(variable);
  //for test above   
  //bypass download or comment upload//     
  variable[2]=ReturnSign;    
  httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");   
  return httpd_resp_send(req,variable,numchartowrite);   
  }

void starthttpServer(){
  httpd_config_t config = HTTPD_DEFAULT_CONFIG();
  config.max_open_sockets = 10;
  config.max_uri_handlers = 14;
  config.server_port = 8088;
  httpd_uri_t index_uri = {
    .uri       = "/",
    .method    = HTTP_GET,
    .handler   = index_handler_phone,
    .user_ctx  = NULL
  };
//load mainpage //step3
  httpd_uri_t index_uri1 = {
      .uri       = "/lan",
      .method    = HTTP_GET,
      .handler   = index_handler_homehw,
      .user_ctx  = NULL
    };
//setup cellphone key    
  httpd_uri_t index_uri2 = {
      .uri       = "/filehandle",
      .method    = HTTP_GET,
      .handler   = index_handler_filehandle,
      .user_ctx  = NULL
    };  
  
  httpd_uri_t index_uri3 = {
      .uri       = "/mqsetup",
      .method    = HTTP_GET,
      .handler   = index_handler_mqsetup,
      .user_ctx  = NULL
    };
  
  httpd_uri_t index_uri4 = {
      .uri       = "/mobile",
      .method    = HTTP_GET,
      .handler   = index_handler_mobile,
      .user_ctx  = NULL
    };
 
  httpd_uri_t index_uri5 = {
      .uri       = "/helppopup",
      .method    = HTTP_GET,
      .handler   = index_handler_helppopup,
      .user_ctx  = NULL
    };
  httpd_uri_t index_uri6 = {
      .uri       = "/web",
      .method    = HTTP_GET,
      .handler   = index_handler_homeweb,
      .user_ctx  = NULL
    };
///////////////////////////////////////        
  httpd_uri_t index_uri7 = {
    .uri       = "/svgplccell",
    .method    = HTTP_GET,
    .handler   = index_handler_svgplccell,
    .user_ctx  = NULL
    };        
  httpd_uri_t index_uri8 = {
    .uri       = "/icontext",
    .method    = HTTP_GET,
    .handler   = index_handler_icontext,
    .user_ctx  = NULL
    };            
    httpd_uri_t index_uri9 = {
    .uri       = "/Property",
    .method    = HTTP_GET,
    .handler   = index_handler_Property,
    .user_ctx  = NULL
    };        
  httpd_uri_t index_uri10 = {
    .uri       = "/Linkhardware",
    .method    = HTTP_GET,
    .handler   = index_handler_Linkhardware,
    .user_ctx  = NULL
    };   
  httpd_uri_t index_uri11 = {
    .uri       = "/setupclock",
    .method    = HTTP_GET,
    .handler   = index_handler_setupclock,
    .user_ctx  = NULL
    };      
  httpd_uri_t index_uri12 = {
      .uri       = "/plcsvgcss",
      .method    = HTTP_GET,
      .handler   = index_handler_plcsvgcss,
      .user_ctx  = NULL
    };     
  httpd_uri_t cmd_uri = {
    .uri       = "/action",
    .method    = HTTP_GET,
    .handler   = cmd_handler,
    .user_ctx  = NULL
  };  


  if (httpd_start(&controller_httpd, &config) == ESP_OK) {   
    httpd_register_uri_handler(controller_httpd, &index_uri12);  //step4
    httpd_register_uri_handler(controller_httpd, &index_uri11);  
    httpd_register_uri_handler(controller_httpd, &index_uri10);   
    httpd_register_uri_handler(controller_httpd, &index_uri9);
    httpd_register_uri_handler(controller_httpd, &index_uri8);
    httpd_register_uri_handler(controller_httpd, &index_uri7);
    httpd_register_uri_handler(controller_httpd, &index_uri6);
    httpd_register_uri_handler(controller_httpd, &index_uri5); 
    httpd_register_uri_handler(controller_httpd, &index_uri4);
    httpd_register_uri_handler(controller_httpd, &index_uri3);
    httpd_register_uri_handler(controller_httpd, &index_uri2);
    httpd_register_uri_handler(controller_httpd, &index_uri1);
    httpd_register_uri_handler(controller_httpd, &index_uri);
    httpd_register_uri_handler(controller_httpd, &cmd_uri);
  }  
}
//********************************************************//
void downloadinit()
{initplc();         
  {netanalysis();       
    /*
    {byte x,y;
    for(y=0;y<ycount;y++) 
      {
      for(x=0;x<xcount;x++) 
        {Serial.print('/');
        Serial.print(netnum[x][y]);                  
        }
      Serial.println('=');   
      for(x=0;x<xcount;x++) 
        {Serial.print('-');
        Serial.print(BoxState[x][y].Linknum);                  
        }
      Serial.println('=');     
      }
    }       
    */
    //genlinktable();              
    ioinit();        //0 if not coolboot from 0 
    esp_task_wdt_init(1,true);   
    esp_task_wdt_add(NULL);  //gen reset signal
    delay(1500);    //create timeout reset
    //coolboot();
    Serial.println("Cool boot");   
    Runmode=1;   
    esp_task_wdt_init(20,true);   
    esp_task_wdt_add(NULL);            
  }
}                    
#ifdef ver3
void coolboot()
{pinMode(COOLBOOT,OUTPUT);
digitalWrite(COOLBOOT,LOW);
}
#endif
void setup(){   
  // Initialize the watchdog timer with a timeout of 10 seconds  
  esp_task_wdt_init(20, false);   //false to stop watch dog timer -> turn on is true
  esp_task_wdt_add(NULL);         //reset when 20 second over
  pinMode(setuppin,INPUT_PULLUP); 
  
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector 
  Serial.begin(115200);
  Serial.setDebugOutput(false); 
  #ifdef  uart1
  Serial1.begin(115200, SERIAL_8N1, SERIAL1_TX_PIN, SERIAL1_RX_PIN);     
  #endif
  Serial.println("///////////////Donkey PLC setup information///////////////");  
  //MqttBroker
  if(pw_enable_sw!=0)  //On or OFf passward check//
    {pinMode(pw_enable_sw,INPUT_PULLUP);
    if(digitalRead(pw_enable_sw)==1)  
      Serial.println("Password Setup switch is in UNLOCK position");  
    else
      Serial.println("Password Setup switch is in LOCK position");    
    }  
  //modify in sMQTTBroker.cpp 
  ///////////////////////////////  
  Serial.println("Designed by DonKey Lab.");  
  eerpassid(eessid,mssid,mpass);
  if(mssid[0]>=0x30 && mssid[0]<0x7e)
  {Serial.println(mssid);
  Serial.println(mpass); 
  }   

  if(digitalRead(setuppin)==SETUPSTATE)  //setup mode
    {byte key; 
    setupmode=1;   
    eerbyte(0,&STXbuffer[1],50);
    #ifdef  uart1
    SerialRTXLoop(STXbuffer,50);    
    if(uartmaster(50)>40000)
      key=0;  
    #endif  
      Serial.print("Input ssid=");  
      do{if (Serial.available() > 0) {
        key = Serial.read();
        MYSSID=MYSSID+static_cast<char>(key);
        }
        }while(key!=0xd && key!=0xa);
      Serial.println(MYSSID);  
      key=0;
      Serial.print("Input password=");
      do{if (Serial.available() > 0) {
        key = Serial.read();
        MYPASSWORD=MYPASSWORD+static_cast<char>(key);
        }
        }while(key!=0xd && key!=0xa);           
    eerbyte(eessid,&STXbuffer[1],50);  //data to link Broker board 
    #ifdef  uart1
    SerialRTXLoop(STXbuffer,50);
    if(uartmaster(50)>40000)
      Serial.println("Uart connect failure");
    #endif     
    Serial.println(MYPASSWORD);  
    Serial.println("To run program set switch to run position and press reset to start program");
    Serial.println("To change SSID or password set switch setup position and press reset");
    MYSSID.toCharArray(mssid,MYSSID.length());
    MYPASSWORD.toCharArray(mpass,MYPASSWORD.length()); 
    eewpassid(eessid,mssid,mpass);
    //while (!Serial.available());
    while (digitalRead(setuppin)==SETUPSTATE);      //wait for key release
    }
  else    //below no setup require
    eerpassid(eessid,mssid,mpass);                    
  //#ifdef    MQTTACTIVE       
    getdata(1,6,EPLCMQTT);
    getdata(2,6,EPHMQTT);     
    if(EPHMQTT[0]=='1'|| EPLCMQTT[0]=='1')
      clientsetup(1);     //connect to wifi and Mqtt
    else                
      clientsetup(0);     //connect to wifi only  
  while(wificonnected==0) 
  {Serial.print('.');
  if(connectcount++>512)
      {Serial.println("Connect error");
      Serial.println("Unable to connect network, reenter check password and id"); //add check mqtt and bypass if necessory    
      }
  delay(20);
  } 
  if(mqttconnected)
    Serial.println("Mqtt connected");         
  else
    Serial.println("Waiting for Mqtt connect");      
  //////////
    #ifdef CreateUnicode
    uint64_t chipId = ESP.getEfuseMac();
    encrypt(encrytext,chipId);    
    eewbyte(unicode,encrytext,12);      
    #endif
  //////////  
    #ifdef  CheckUnicode
    uint64_t chipId = ESP.getEfuseMac();    
    byte tc;
    eerbyte(unicode,comparetext,12);
    encrypt(encrytext,chipId);        
    for(tc=0;tc<12;tc++)
      {if(encrytext[tc]!=comparetext[tc])
        break;
      }    
    if(tc<12)
       Serial.println("MCU Unicode not match");
    else
       Serial.println("MCU Unicode match");    
    #endif
  /////////  
  timeClient.begin(); 
  Serial.println("WiFi connected");
  Serial.print("Donkey Lab PLC Ready! Go to: http://");  
  Serial.println(WiFi.localIP());    
  // Start streaming web server
  starthttpServer();            
  eepromread(adddataz0,dataz0,0);     
  eepromread(adddataz1,dataz1,0);    
  eepromread(adddataz2,dataz2,0);    
  eepromread(adddataz3,dataz3,0);    
  eepromread(adddataz4,dataz4,2);  
  initplc();  
  netanalysis();   
  //phone password
  eerbyte(phpw,Storephonepw,8); 
  Serial.print("phonepw = ");
  Serial.println(Storephonepw);
  eerbyte(editpw,Storeeditpw,8); 
  Serial.print("PLC PW  = ");
  Serial.println(Storeeditpw);
  /*
  {byte x,y;
    for(y=0;y<ycount;y++) 
    {
    for(x=0;x<xcount;x++) 
      {Serial.print('/');
      Serial.print(netnum[x][y]);                  
      }
    Serial.println('=');   
    for(x=0;x<xcount;x++) 
      {Serial.print('-');
      Serial.print(BoxState[x][y].Linknum);                  
      }
    Serial.println('=');     
    }
  } 
  */         
  ioinit();  
  timeClient.update();  
  currenttime=(timeClient.getHours()*3600)+(timeClient.getMinutes()*60)+timeClient.getSeconds();
  currentdateofyear=timeClient.getEpochTime()/86400-19722;
  setuptimeclock(1);    
  //////////HW COUNTER///////
  //Runmode=0;  //stop run PLC
  //attachInterrupt(digitalPinToInterrupt(counterPin), counterInterruptHandler, RISING);
  //////////HW COUNTER///////
  Runmode=1;  //after setup 
}

void ioinit()
{Serial.println("ioinit");
byte h;
for(h=1;h<=MaxOut;h++)        
  {pinMode(Pinout[h],OUTPUT);                     
  digitalWrite(Pinout[h],HIGH);
  }
for(h=1;h<=MaxIn;h++)   
  pinMode(Pinin[h],INPUT_PULLUP);             
}


//byte test=0;
//unsigned long timeinsecond;
//unsigned long timeDayofYear;
extern struct tm timeinfo;
void loop() {   
  //if(ctlpermit==1)      
  //  {phoneelapsedTime=millis()-phonestartTime;  
  //  if(phoneelapsedTime>60000)
  //    ctlpermit=0;
  //  } 
  if(Runmode==2)
    {Serial.println("IO init 2");  
      downloadinit(); 
    //coolboot();
    Runmode=1;
    }       
  if(Runmode==1)
  {for(uint32_t realtimeloop=0;realtimeloop<0x100000;realtimeloop++)      
    {runplc(realtimeloop);           
    if(Runmode==0)             
      {Serial.println("IO init 3"); 
      break;            
      }
    if(Runmode==10 && (realtimeloop&0x1ff)==0x1ff)  
      {switchsimulate(1);
      Runmode=1;
      }
    if((realtimeloop&0x1fff)==0x1fff)  
      {           
      connectToMqtt();                  
      }  
    if((realtimeloop&0xffff)==0xffff)  //0xffff
      {esp_task_wdt_reset();     //rest wdt                    
      if(wificonnected)// && (test<5 || test>10))
        {timeClient.update();                        
        //get time details
        currenttime=(timeClient.getHours()*3600)+(timeClient.getMinutes()*60)+timeClient.getSeconds();
        currentdateofyear=timeClient.getEpochTime()/86400-19722;
        //Serial.printf("timeDayofYear=%D currenttime%d\n",currentdateofyear,currenttime);             
        }
      else
        {unsigned long startTime=millis();          
        //Serial.print("MCU Time=");               
        currenttime=currenttime+((startTime-currenttime)/1000)%4;               
        }             
      }        
    }
  }
}       
/*
  int	tm_sec;
  int	tm_min;
  int	tm_hour;
  int	tm_mday;
  int	tm_mon;
  int	tm_year;
  int	tm_wday;
  int	tm_yday;
  int	tm_isdst;
*/

