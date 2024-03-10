#include "../include/plcsvg.h"
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
char mqtt_port_char[6];
char ISMASTER[5]; 
char MYTOPIC[5][64];  // = "mytopic2";
char ECODE[40];  
char PCODE[40];  
char EWSS[2];   
char MQTT_BROKER[64];  
char MPASSWORD[32];  
char MUSERID[32]; 
char MQTINTERVAL[5][4];  
char EPHMQTT[2];
char EPLCMQTT[2];
byte RelayOnOffstate[16];
int  rxpin;
byte MqttDisplay[16];
char lastTxAnaValue[4][8][4];  
byte lastTxIOpinit[4][8];
byte mqttconnected=0;
byte wificonnected=0;
byte wssenable=0;

static const char *root_ca PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIFazCCA1OgAwIBAgIRAIIQz7DSQONZRGPgu2OCiwAwDQYJKoZIhvcNAQELBQAw
TzELMAkGA1UEBhMCVVMxKTAnBgNVBAoTIEludGVybmV0IFNlY3VyaXR5IFJlc2Vh
cmNoIEdyb3VwMRUwEwYDVQQDEwxJU1JHIFJvb3QgWDEwHhcNMTUwNjA0MTEwNDM4
WhcNMzUwNjA0MTEwNDM4WjBPMQswCQYDVQQGEwJVUzEpMCcGA1UEChMgSW50ZXJu
ZXQgU2VjdXJpdHkgUmVzZWFyY2ggR3JvdXAxFTATBgNVBAMTDElTUkcgUm9vdCBY
MTCCAiIwDQYJKoZIhvcNAQEBBQADggIPADCCAgoCggIBAK3oJHP0FDfzm54rVygc
h77ct984kIxuPOZXoHj3dcKi/vVqbvYATyjb3miGbESTtrFj/RQSa78f0uoxmyF+
0TM8ukj13Xnfs7j/EvEhmkvBioZxaUpmZmyPfjxwv60pIgbz5MDmgK7iS4+3mX6U
A5/TR5d8mUgjU+g4rk8Kb4Mu0UlXjIB0ttov0DiNewNwIRt18jA8+o+u3dpjq+sW
T8KOEUt+zwvo/7V3LvSye0rgTBIlDHCNAymg4VMk7BPZ7hm/ELNKjD+Jo2FR3qyH
B5T0Y3HsLuJvW5iB4YlcNHlsdu87kGJ55tukmi8mxdAQ4Q7e2RCOFvu396j3x+UC
B5iPNgiV5+I3lg02dZ77DnKxHZu8A/lJBdiB3QW0KtZB6awBdpUKD9jf1b0SHzUv
KBds0pjBqAlkd25HN7rOrFleaJ1/ctaJxQZBKT5ZPt0m9STJEadao0xAH0ahmbWn
OlFuhjuefXKnEgV4We0+UXgVCwOPjdAvBbI+e0ocS3MFEvzG6uBQE3xDk3SzynTn
jh8BCNAw1FtxNrQHusEwMFxIt4I7mKZ9YIqioymCzLq9gwQbooMDQaHWBfEbwrbw
qHyGO0aoSCqI3Haadr8faqU9GY/rOPNk3sgrDQoo//fb4hVC1CLQJ13hef4Y53CI
rU7m2Ys6xt0nUW7/vGT1M0NPAgMBAAGjQjBAMA4GA1UdDwEB/wQEAwIBBjAPBgNV
HRMBAf8EBTADAQH/MB0GA1UdDgQWBBR5tFnme7bl5AFzgAiIyBpY9umbbjANBgkq
hkiG9w0BAQsFAAOCAgEAVR9YqbyyqFDQDLHYGmkgJykIrGF1XIpu+ILlaS/V9lZL
ubhzEFnTIZd+50xx+7LSYK05qAvqFyFWhfFQDlnrzuBZ6brJFe+GnY+EgPbk6ZGQ
3BebYhtF8GaV0nxvwuo77x/Py9auJ/GpsMiu/X1+mvoiBOv/2X/qkSsisRcOj/KK
NFtY2PwByVS5uCbMiogziUwthDyC3+6WVwW6LLv3xLfHTjuCvjHIInNzktHCgKQ5
ORAzI4JMPJ+GslWYHb4phowim57iaztXOoJwTdwJx4nLCgdNbOhdjsnvzqvHu7Ur
TkXWStAmzOVyyghqpZXjFaH3pO3JLF+l+/+sKAIuvtd7u+Nxe5AW0wdeRlN8NwdC
jNPElpzVmbUq4JUagEiuTDkHzsxHpFKVK7q4+63SM1N95R1NbdWhscdCb+ZAJzVc
oyi3B43njTOQ5yOf+1CceWxG1bQVs5ZufpsMljq4Ui0/1lvh+wjChP4kqKOJ2qxq
4RgqsahDYVvTH9w7jXbyLeiNdd8XM2w9U/t7y0Ff/9yi0GE44Za4rF2LN9d11TPA
mRGunUHBcnWEvgJBQl9nJEiU0Zsnvgc/ubhPgXRR4Xq37Z0j4r7g1SgEEzwxA57d
emyPxgcYxn/eR44/KJ4EBs+lVDR3veyJm+kXQ99b21/+jh5Xos1AnX5iItreGCc=
-----END CERTIFICATE-----
)EOF";

//---- WiFi settings
//const char* ssid = "ATT3jl8Tns";
//const char* password ="6mrk8iyf26vn";
//---- MQTT Broker settings
char* mqtt_server;// = "f27d2ae246004779b11b64b42778b4a1.s2.eu.hivemq.cloud";
char* mqtt_username;// = "nganmomo";
char* mqtt_password;// = "5585Ngan";
//const int mqtt_port;// =8883;
int mqtt_port;
void callback(char* topic, byte* payload, unsigned int length);
void reconnect();
void publishMessage(const char* topic, String payload , boolean retained);
void TxToPhone(byte isinit,int length);
void onMqttConnect();
void connectToWifi();
void WiFiEvent(WiFiEvent_t event);
WiFiClient espClient;
WiFiClientSecure espClient_s;
PubSubClient client(espClient);
PubSubClient client_s(espClient_s);

TimerHandle_t mqttReconnectTimer;
TimerHandle_t wifiReconnectTimer; 

void clientsetup(byte mqtt) {  
  //eerbyte(MQtopic,PCODE,32);        
  getdata(0,0,MQTT_BROKER);  
  getdata(1,0,mqtt_port_char);
  getdata(2,0,MUSERID);
  getdata(3,0,MPASSWORD);        
  getdata(1,1,ECODE); //1,1      
  getdata(2,1,PCODE);
  getdata(0,6,EWSS); 
  getdata(1,6,EPLCMQTT);
  getdata(2,6,EPHMQTT);       
  Serial.print("MQTT_BROKER :"); 
  Serial.println(MQTT_BROKER);   
  Serial.print("mqtt_port_char :"); 
  Serial.println(mqtt_port_char); 
  Serial.print("ECODE :");  
  Serial.println(ECODE);    
  Serial.print("PCODE :");  
  Serial.println(PCODE);    
  Serial.print("MQTT USER ID :");  
  Serial.println(MUSERID);   
  Serial.print("MQTT PASSWORD :");
  Serial.println(MPASSWORD);
  Serial.print("MQTT USE WSS=");  
  Serial.println(EWSS[0]);  
  Serial.print("PLC MQTT ENABLE=");  
  Serial.println(EPLCMQTT);     
  Serial.print("PHONE MQTT ENABLE=");  
  Serial.println(EPHMQTT);     
if(mqtt)
{if(EWSS[0]=='1')
  wssenable=1;
else
  wssenable=0;  
mqtt_server=MQTT_BROKER;
mqtt_username=MUSERID;
mqtt_password=MPASSWORD; 
mqtt_port=(mqtt_port_char[0]-0x30)*1000+(mqtt_port_char[1]-0x30) //??
    *100+(mqtt_port_char[2]-0x30)*10+(mqtt_port_char[3]-0x30);  
Serial.print("This PLC assigned as= ");  
getdata(3,1,ISMASTER);     
if(ISMASTER[1]=='0')  
  Serial.println("MASTER"); 
if(ISMASTER[1]=='1')  
  Serial.println("SLAVE A");   
if(ISMASTER[1]=='2')  
  Serial.println("SLAVE B");   
if(ISMASTER[1]=='3')  
  Serial.println("SLAVE C");      
  for(int t=1;t<6;t++)       
    {if(t==5) 
      {Serial.print("This Phone assigned=");  //no topic for phone
      Serial.println(PCODE);  
      }
    else
      {getdata(0,t+1,&MYTOPIC[t][0]);    
      Serial.println(&MYTOPIC[t][0]);         
      }   
    }             
  randomSeed(micros());
  while (!Serial) delay(1);
  if(wssenable)
    {espClient_s.setCACert(root_ca);
    client_s.setServer(mqtt_server, mqtt_port);
    Serial.println("Set callback"); 
    client_s.setCallback(callback);
    }
  else  
    {
    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(callback);
    }
  }
else
  {
  Serial.println("Mqtt setup require, Please click [Enable PLC Mqtt]");   
  }  
//mqttReconnectTimer = xTimerCreate("mqttTimer", pdMS_TO_TICKS(2000), pdFALSE, (void*)0, reinterpret_cast<TimerCallbackFunction_t>(connectToMqtt));  
wifiReconnectTimer = xTimerCreate("wifiTimer", pdMS_TO_TICKS(2000), pdFALSE, (void*)0, reinterpret_cast<TimerCallbackFunction_t>(connectToWifi));
WiFi.onEvent(WiFiEvent);
connectToWifi();
}

void connectToWifi()
{
if((WiFi.status() != WL_CONNECTED))
  {Serial.println("Connect to Mqtt with encrypt"); 
  WiFi.mode(WIFI_STA);
//#ifdef  BYPASSSETUP 
//  WiFi.begin("ATT3jl8Tns","6mrk8iyf26vn");
//#else
  WiFi.begin(&mssid[0],&mpass[0]);
//#endif 
  }
}


void connectToMqtt() {
  if(EPHMQTT[0]=='1'|| EPLCMQTT[0]=='1')
  {if(wssenable)
    {if (!client_s.connected()) reconnect();
        client_s.loop();
    }
  else
    {if (!client.connected()) reconnect();
        client.loop();
    }
  }
}

void WiFiEvent(WiFiEvent_t event) {   
    Serial.printf("[WiFi-event] event: %d\n", event);
    switch(event) {
    case SYSTEM_EVENT_STA_GOT_IP:
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
        if(EPHMQTT[0]=='1'|| EPLCMQTT[0]=='1')
          {connectToMqtt();
          mqtten=1;
          }
        wificonnected=1;
        break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
        Serial.println("WiFi lost connection");
        //xTimerStop(mqttReconnectTimer, 0); // ensure we don't reconnect to MQTT while reconnecting to Wi-Fi
        xTimerStart(wifiReconnectTimer, 0);
        break;
    }    
}

//=======================================================================Function=================================================================================
void reconnect() {
//while (!client.connected()) {
if(wssenable)
  {if(!client_s.connected()) {
    //Serial.print("Attempting MQTT connection…");
    String clientId = "ESP832Client-"; // Create a random client ID
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client_s.connect(clientId.c_str(), mqtt_username, mqtt_password)) {
        //Serial.println("Mqtt Encrypt connected");     
        onMqttConnect();      
        }      
      }
  }
else
 {if(!client.connected()) {
    //Serial.print("Attempting MQTT connection…");
    String clientId = "ESP832Client-"; // Create a random client ID
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str(), mqtt_username, mqtt_password)) {
        //Serial.println("Mqtt Simple connected");     
        onMqttConnect();      
        }      
      }
  }
}

//======================================= publising as string
void publishMessage(const char* topic, String payload , boolean retained){
if(wssenable)
  {if (client_s.publish(topic, payload.c_str(), true))
  Serial.println("Message publised ["+String(topic)+"]: "+payload);
  }
else
  {if (client.publish(topic, payload.c_str(), true))
  Serial.println("Message publised ["+String(topic)+"]: "+payload);
  }  
}
//phone on Mqtt:--
//(1) On message or callback
//(2) Send data to cellkeyboard
//(3) the buttonmod and buttonnum detect runplc loop, when data ready,Mqtt get it by request display. 
void callback(char* topic, byte* payload, unsigned int len) {
char chars[200];
byte rxtopic;
for(unsigned int i = 0; i < len; i++)
  chars[i] = (char)payload[i];
//Serial.print("callback=");
//Serial.println(chars);   
//Serial.print("topic=");
//Serial.println(topic);     
if(topic[0]=='M'|| topic[0]=='A'|| topic[0]=='B'|| topic[0]=='C')   //PLC
  {if(topic[0]=='M') rxtopic=0;if(topic[0]=='A') rxtopic=1;if(topic[0]=='B') rxtopic=2;if(topic[0]=='C') rxtopic=3;  
  byte t,j;
  byte y=0;  
  //pass mqtt status to plcinit.cpp case 45//  
  for(t=1;t<=8;t++)    //2D array to 1D array
    {for(j=0;j<4;j++)
      RxAnaValue[rxtopic][t][j]=payload[y++]-0x30;                               
    }    
  for(t=1;t<=8;t++)    
    RxIOpinit[rxtopic][t]=payload[y++]-0x30; //and change to ascii  
  }
  //pass mqtt status to plcinit.cpp case 45//
if(topic[0]=='T')   //for Mqtt phone
  {byte type;
  if(payload[0]=='D' && payload[1]=='I' && payload[2]=='S'&& payload[3]=='P'&& payload[4]=='L')  
    { variable[4]='t';    //request display
      cellkeyboard(DPLAY);    //*step1*//         
      TxToPhone(DPLAY,0); 
      payload[0]=='/'; //avoid repeat  
    }             
  else if(payload[0]=='I' && payload[1]=='N' && payload[2]=='I'&& payload[3]=='T'&& payload[4]=='K')
      {variable[4]=payload[5];variable[5]=payload[6];variable[6]=payload[7];variable[7]=payload[8];
      TxToPhone(KEYINIT,0);      //requess initial keyboard
      }
  else if(payload[0]=='K' && payload[1]=='E' && payload[2]=='Y'&& payload[3]=='I'&& payload[4]=='N')       
    {if(len>100) len=100;      //handle incomming request
      for(int t=0;t<(len-5);t++)
        {variable[t+4]=payload[t+5];
        }        
      //Serial.print("variable12=");
      //Serial.println(variable);
      if(variable[4]=='9')    //*request verify*//
        {cellkeyboard(VERIFY);    //*step1*//   
        TxToPhone(DPLAY,0);
        }
      else
        {cellkeyboard(DWORK);    //*step1*//       
        TxToPhone(JDONE,0);      
        }
    }                   
  }  
}

void onMqttConnect() { 
  mqttconnected=1;
  Serial.println("Connected to MQTT.");
  char lookup[5]={'T','M','A','B','C'};
  char str[100];
  char pstr[100];
  char tstr[100];    
  strcat(str, ECODE);
  //strcat(str, &MYTOPIC[0][0]); //add broker                      
  if(ISMASTER[1]=='0')
    {Serial.println("PLC Master subscribe list:");
      for(int t=1;t<=4;t++)
      {strcpy(pstr,"");      
      pstr[0]=lookup[t];
      pstr[1]='\0';      
      strcat(pstr,ECODE);    
      strcat(pstr,&MYTOPIC[t][0]);                       
      if(wssenable)
        client_s.subscribe(pstr);
      else
        client.subscribe(pstr);    
      Serial.println(pstr);
      strcpy(pstr,"");    
      }
    }
  else
    {Serial.println("PLC Slave subscribe:");
      strcpy(pstr,"");
    strcat(pstr,str);
    pstr[0]=lookup[ISMASTER[1]-0x30+1];
    pstr[1]='\0';
    strcat(pstr,ECODE);    
    strcat(pstr,&MYTOPIC[ISMASTER[1]-0x30+1][0]);
    client.subscribe(pstr);     
    Serial.println(pstr);
    }  
  if(EPHMQTT[0]=='1')
  {int ttc;  
  for(ttc=0;ttc<32;ttc++)  
    {if(PCODE[ttc]>'z')
        break;                   
    }
  if(ttc>30)  
    {tstr[0]=lookup[0];//telephone
    tstr[1]='\0';    
    strcat(tstr,PCODE);
    Serial.println("Phone subscribe:");
    Serial.println(tstr); 
    if(wssenable)
      client_s.subscribe(tstr);   
    else
      client.subscribe(tstr); 
    Serial.println(pstr);      
    }
  else
    Serial.println("Phone setup require");   
  }
} 

//For telephone
void TxToPhone(byte isinit,int length) {
char str[100];
str[0]='R'; //response sign
str[1]='\0';
strcat(str,PCODE);
//Serial.print("str1=");
//Serial.println(str);
if(isinit==DPLAY)   //Display
  {variable[0]='d';variable[1]='i';variable[2]='s';variable[3]='d';        
  byte Len=displaymess.length();
  displaymess.toCharArray(&variable[4],Len+1); 
  }
if(isinit==JDONE)   //handle keyin   
  {variable[0]='j';variable[1]='o';variable[2]='b';variable[3]='d';}        
if(isinit==KEYINIT)   //keyboard setup 
  {eerbyte(keychar,&variable[8],350);          
  variable[0]='i';variable[1]='n';variable[2]='i';variable[3]='R';   
  }   
//Serial.print("str=");
//Serial.println(str);   
//Serial.print("publishlast=");
//Serial.println(variable);
if(wssenable)  
  client_s.publish(str,variable,true);  
else
  {//Serial.println("not wss");   
  client.publish(str,variable,true);  
  }
}

//For PLC
void clientTX(byte topic) {
byte t,j;
byte y=0;
byte txrequired=0;  //if no change bypass tx;
//Serial.print("MYTOPIC=");  
//Serial.println(&MYTOPIC[topic+1][0]);  
char pay_load[41];
if(EPLCMQTT[0]=='1')
  {for(t=0;t<8;t++)    //2D array to 1D array
    {for(j=0;j<4;j++)
      {pay_load[y++]=TxAnaValue[topic][t][j];         
      if(TxAnaValue[topic][t][j]!=lastTxAnaValue[topic][t][j])
        {txrequired=1;
        lastTxAnaValue[topic][t][j]=TxAnaValue[topic][t][j];    
        }
      }
    }  
    for(t=0;t<8;t++)    
    {pay_load[y++]=TxIOpinit[topic][t]; //and cnange to ascii
    if(TxIOpinit[topic][t]!=lastTxIOpinit[topic][t])
      {txrequired=1;
      lastTxIOpinit[topic][t]=TxIOpinit[topic][t];
      }
    }
    if(txrequired==1)      
    { char str[100];
      char lookup[5]={'T','M','A','B','C'};
      str[0]=lookup[topic+1];
      str[1]='\0';
      for(t=0;t<40;t++)    
      pay_load[t]=pay_load[t]+0x30;
      pay_load[40]='\0';          
      strcat(str, ECODE);               
      strcat(str, &MYTOPIC[topic+1][0]);
      Serial.print("str=");
      Serial.println(str);   
      if(wssenable)    
        client_s.publish(str,pay_load,true);                            
      else
        client.publish(str,pay_load,true);   
    } 
  } 
}