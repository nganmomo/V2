static const char PROGMEM INDEX_HTML_mqsetup[] = R"rawliteral(
<html>
<script src='https://cdnjs.cloudflare.com/ajax/libs/qrcodejs/1.0.0/qrcode.min.js'></script>  
<body><div id=ssetup></div>
<h2 id='UTLI1'></h2>
<div class='qr' id='qrcode1' style='margin-left:200px;'></div><br><br>
<br><button type='button' onclick='PhoneLogicCode()' style='margin-left:50px' >Gen Phone Login code</button><br>
<h2 id='UTLI2'></h2>
<div class='qr' id='qrcode2' style='margin-left:200px;margin-bottom:400px;'></div><br><br>
</body>
</html>  
<script>
// For mqtt
var xsetdev=4;
var ysetdev=7;
var txdata;
//for htmltestpage.html
var rowtext = Array.from(Array(xsetdev), () => new Array(ysetdev)); 
var systcell = Array.from(Array(xsetdev), () => new Array(ysetdev).fill("")); 

function sysloadinitdata(){      
console.log('cd0',systcell);   
  //localStorage.clear(); //all items
  //localStorage.removeItem('systcell');
  var np = ['SERVER','LocalTopic','MASTER TOPIC','SLAVE TOPIC A','SLAVE TOPIC C','SLAVE TOPIC B','SLAVE TOPIC C'];
  var pp = ['PORT','ECODE','* Subscribe Master','*Subscribe Slave A','*Subscribe Slave B','*Subscribe Slave C'];
  var dp1 = ['User ID','Qos','Refresh','Refresh','Refresh','Refresh'];
  var dp2 = ['PW','Refresh period','Refresh period','Refresh period','Refresh period','Refresh period'];  
  for(let t=0;t<ysetdev;t++)                                       
      {if(t===0)  
        {rowtext[0][t] = "<td>"+np[t]+":<input type='text' maxlength='120' value='"+systcell[0][t]+"'onchange=updatetcell(0,"+t+",value) style='width:180px'></td>"                        
        rowtext[1][t] = "<td>"+pp[t]+":<input type='number' step='any' maxlength='4' value='"+systcell[1][t]+"'onchange=updatetcell(1,"+t+",value) style='width:100px;margin-right:50px'></td>"   
        rowtext[2][t] = "<td>"+dp1[t]+":<input type='text' maxlength='20' value='"+systcell[2][t]+"'onchange=updatetcell(2,"+t+",value) style='width:100px'></select></td>"             
        rowtext[3][t] = "<td>"+dp2[t]+"<input type='text' maxlength='20' value='"+systcell[3][t]+"'onchange=updatetcell(3,"+t+",value) style='width:100px'></select></td>"    
        }                                  
      if(t===1)
        {//rowtext[0][t] = "<td>*Local MQTT server encrypt<input type='checkbox' id='mybox' onclick='updatecolor()'></td>"
        rowtext[0][t] = "<td>"+pp[t]+":<input id='addcode' type='text' maxlength='32' value='"+systcell[1][t]+"'onchange=updatetcell(1,"+t+",value) style='width:220px'></select></td>"   
        rowtext[1][t] = "<td>Ph:<input id='addcode' type='text' maxlength='32' value='"+systcell[2][t]+"'onchange=updatetcell(1,"+t+",value) style='width:162px'></select></td>"
        rowtext[2][t]=  "<td><button onclick='copyToClipboard()' style='margin-left:15px'>Copy ECODE to Clipboard</button></td>"
        rowtext[3][t] = "<td><button type='button' id='grc' onclick='GererateRC()' style='margin-left:10px'>***Gererate random code</button></td>"               
        }           
      if(t>1 && t<6) 
        {rowtext[0][t] = "<td>"+np[t]+":<input type='text' maxlength='20' value='"+systcell[0][t]+"'onchange=updatetcell(0,"+t+",value) style='width:160px'></td>"
        rowtext[1][t] = "<td>"+pp[t]+":<input type='radio' id='radio"+t+"' name='group1' value='' onclick='updatecolor()'><br>"
        rowtext[2][t] = "<td>"+dp2[t]+":<input type='number' step='any' maxlength='4' value='"+systcell[2][t]+"'onchange=updatetcell(2,"+t+",value) style='width:80px'></select></td>"             
        rowtext[3][t] = "<td></td>"             
        }  
      if(t>=6)
        {rowtext[0][t] = "<td>##WSS encrypt(Phone only)<input type='checkbox' id='enwss' onclick='updatecolor()'></td>"              
        rowtext[1][t] = "<td>Enable PLC Mqtt<input type='checkbox' id='enplc' onclick='updatecolor()'></td>"
        rowtext[2][t] = "<td>Enable phone Mqtt<input type='checkbox' id='enphone' onclick='updatecolor()'></td>"             
        rowtext[3][t] = ""   
        }  
      } 
       
  for(let j=0;j<ysetdev;j++)  
      {row = document.getElementById('myDRow'+j.toString());         
      x0 = row.insertCell(0);  //insert
      //if(j<6)
        {x1 = row.insertCell(1); 
        x2 = row.insertCell(2); 
        x3 = row.insertCell(3);        
        }
      x0.innerHTML = rowtext[0][j];  //
      //if(j<6)
        {x1.innerHTML = rowtext[1][j];  //   
        x2.innerHTML = rowtext[2][j];  //
        x3.innerHTML = rowtext[3][j];  //      
        }
      }                
   }     


  function copyToClipboard() {
    // Get the textarea element
    var textarea = document.getElementById("addcode");    
    textarea.select();
    textarea.setSelectionRange(0, 99); // For mobile devices
    document.execCommand("copy");    
    textarea.setSelectionRange(0, 0);
}

function updatetcell(x,y,value)
{systcell[x][y]=value;
localStorage.setItem('systcell',JSON.stringify(systcell));
document.getElementById('upl').style.backgroundColor='yellow';
}

function updatecolor()
{
document.getElementById('upl').style.backgroundColor='yellow';
}



function UploadsetupMqsu()
{ 
  Uploadsetup('MQSU');
  document.getElementById('uph').style.backgroundColor='yellow'; 
}


function Uploadsetup(txdata)  //txdata= "MQSD"
{//MQSU MQSD   
var xhtp = new XMLHttpRequest(); 
  xhtp.onreadystatechange = function() {
  txre="";  
  tyre="";
  if(this.readyState == 4 && this.status == 200) {      
      txre=this.responseText[0]+this.responseText[1]+this.responseText[2]+this.responseText[3];                                       
      tyre=this.responseText;
      if(txre==="mQsD")   //mQsU is Download     
        {console.log('mqs upload ok',this.responseText);
        let x=0;let y=0;let z=0;
        for(var t=4;t<500;t++)
          {if(tyre[t]=='%')
            {if(x++>=(xsetdev-1))
              {x=0;y++;
              if(y>=ysetdev)  
                break; //y=0;   
              }                                 
            }  
          else                       
            systcell[x][y]=systcell[x][y]+tyre[t];                                                            
          }   
        Loaddetable();          
        }
    }    
    t=systcell[3][1]-0x30;
    if(!(t>=2 && t<=5)) t=2;
      document.getElementById('radio'+t).checked='checked';               
  }  
  if(txdata==="MQSU")
  {
  systcell[0][6]='0';
  if(document.getElementById('enwss').checked===true)
    systcell[0][6]='1';
  
  systcell[1][6]='0';
  if(document.getElementById('enplc').checked===true)
    systcell[1][6]='1';       

  systcell[2][6]='0';
  if(document.getElementById('enphone').checked===true)
    systcell[2][6]='1';   

  //systcell[3][6]='0';
  //if(document.getElementById('mybox').checked===true)
  //  systcell[3][6]='1'; 

  for(let t=2;t<=5;t++)
  {if(document.getElementById('radio'+t).checked)
    { systcell[0][1]=systcell[0][t]; //main topic move to location
      systcell[3][1]=t+0x30;  
      break;
    }
  }    
  for(var y=0;y<ysetdev;y++)
    {for(var x=0;x<xsetdev;x++)
      txdata=txdata+systcell[x][y]+'%';   //^%";    
    }   
  }  
  console.log("txdata=",txdata);     
  //URL="192.168.1.108:8088";
  var URL=window.location.host; 
  let t=0;
  let Txdata="";
  let L=txdata.length;
  for(t=0;t<L;t++)
    {if(txdata[t]===" ")
      Txdata=Txdata+"_";
    else
      Txdata=Txdata+txdata[t];
    }
  xhtp.open("GET","http://"+URL+"/action?go=" + Txdata, true);     
  xhtp.send();  
}

function makeid(length) {
    let result = '';
    const characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
    const charactersLength = characters.length;
    let counter = 0;
    while (counter < length) {
      result += characters.charAt(Math.floor(Math.random() * charactersLength));
      counter += 1;
    }
    return result;
}

function GererateRC()
{
  systcell[1][1]=makeid(32);  
  systcell[2][1]=makeid(32);  
  Loaddetable(); 
}

function Loaddefault(type)      
{if(type===1)
  {systcell[0][0]='broker.hivemq.com';                       //ste=localStorage.getItem('myurl'); 
  systcell[1][0]='1883'
  systcell[2][0]=''; 
  systcell[3][0]=''; 
  systcell[0][6]='0'; 
  systcell[1][6]='1'; //Enable PLC Mqtt
  systcell[2][6]='0'; //Enable phone Mqtt     
  }  
else if(type===3)
  {systcell[0][0]='XXX eu.hivemq.cloud';                       //ste=localStorage.getItem('myurl'); 
  systcell[1][0]='8883'
  systcell[2][0]='input_id'; 
  systcell[3][0]='input_pw';  
  systcell[0][6]='1';   
  systcell[1][6]='1'; //Enable PLC Mqtt
  systcell[2][6]='1'; 
  }
else
  {systcell[0][0]='192.168.1.186';                       //ste=localStorage.getItem('myurl'); 
  systcell[1][0]='1883';  
  systcell[2][0]='input_id'; 
  systcell[3][0]='input_pw';   
  systcell[0][6]='0';
  systcell[1][6]='1'; //Enable PLC Mqtt
  systcell[2][6]='0'; //Enable phone Mqtt
  }
//systcell[0][1]="myTopic1";
//systcell[1][1]='Z7?P[{|L';  
systcell[1][1]=makeid(32);
systcell[2][1]=makeid(32); 
systcell[3][1]='1';  //Subscribe master

for(var t=2;t<ysetdev-1;t++)  
  {
  systcell[0][t]="myTopic"+(t-1);     
  systcell[1][t]='1'; 
  systcell[2][t]='1'; 
  systcell[3][t]='1';    
  }     
//systcell[3][6]='2'; //Subscribe master
//for select subscript   
t=2;
systcell[0][1]=systcell[0][t];  //select typic follow Subscribe
systcell[3][1]=t+0x30;  //Subscribe master
document.getElementById('radio'+t).checked='checked';  
document.getElementById('efftopic').innerText=effectivetopic;
}

//Z7?P  
function Localdefault(type)
{Loaddefault(type);
Loaddetable()
document.getElementById('upl').style.backgroundColor='yellow';
}

function Loaddetable(){
localStorage.setItem('systcell',JSON.stringify(systcell));
for(let y=0;y<ysetdev;y++)  
  {var row = document.getElementById('myDRow'+y.toString());      
    {for(let j=0;j<xsetdev;j++)          
      row.deleteCell(0);         
    }   
  }    
sysloadinitdata();
if(systcell[0][6]==='0')  
  document.getElementById('enwss').checked=false;
else  
  document.getElementById('enwss').checked=true;
//if(systcell[2][1]==='0')  
//  document.getElementById('mybox').checked=false;
//else  
//  document.getElementById('mybox').checked=true;
///////////////////////
if(systcell[1][6]==='0') 
  document.getElementById('enplc').checked=false;
else
  document.getElementById('enplc').checked=true; 
///////////////////////
if(systcell[2][6]==='0') 
  document.getElementById('enphone').checked=false;
else
  document.getElementById('enphone').checked=true;     
///////////////////////
  t=systcell[3][1]-0x30;  //subscript master
if(!(t>=2 && t<=5)) t=2;
  document.getElementById('radio'+t).checked='checked';    
}

//let t=systcell[3][1];
// Get the radio input element by its id
//var radioInput = document.getElementById("radio2");
// Set the checked property to true
//radioInput.checked = true;
syssetup=
"<h3>To unlock this setting, the 'PWSET' switch must be in the set position and locked again to take effect.</h3>\
<table class='devtable'>\
<tbody>\
<tr id='myDRow0'></tr><tr id='myDRow1'></tr><tr id='myDRow2'>\
</tr><tr id='myDRow3'></tr><tr id='myDRow4'></tr><tr id='myDRow5'></tr><tr id='myDRow6'></tr>\
</tbody>\
</table>\
<h3 style='display:inline'> If set slave, copy master ECODE to slave to make both equal</h3><br>\
<br>\
<button type='button' onclick='Localdefault(3)' style='margin-left:50px' >HIVEMQ WSS(Phone)</button>\
<h3 style='display:inline'> Use for WSS mqtt (SERVER UPDATE REQUIRE)</h3><br>\
<button type='button' onclick='Localdefault(1)' style='margin-left:50px' >#Simple HIVEMQ</button>\
<h3 style='display:inline'> Use for Simple mqtt without password and use ID</h3><br>\
<button type='button' onclick='Localdefault(2)' style='margin-left:50px' >#Local Broker</button>\
<h3 style='display:inline'> Use for Simple local mqtt broker without password and use ID</h3><br><br>\
<button type='button' id='upl' onclick='UploadsetupMqsu()' style='margin-left:700px'>Upload setup</button><br>\
<br><button type='button' onclick='EffectTopic()' style='margin-left:100px' >Effective Topic</button>\
<h3 id='testNet' style='display:inline;margin-left:100px'></h3>\
<h3 id='uph'>If any data is changed, the HARDWARE RESET key must be pressed to take effect.</h3>\
<style>input{\
  background: rgb(161, 154, 154);\
  text-align: center;}\
</style>\
<h3 style='display:inline'><label type='text' id='efftopic'></label></h3>\
<h3>##If use MQTT broker encrypt, password and user ID must set, select HIVEMQ to get default setting</h3>\
<h3>#If MQTT broker does not support password and ID settings, a 32 characters code will be added to the topic as the encryption code. e.g. TOPIC = ECODE+TOPIC</h3>\
<h3>*Select one of the four as the subscription topic to receive Mqtt signals, other three are for transmission.</h3>\
<h3>** All PLC card mush use same ECODE.</h3>\
<h3>Mqtt control is based on static control and the response time is about 1 second. For communication between PLC boards, refresh interval can adjust from 1 second to 10 second</h3>\
<h3>For ESP32 broker encryted all PLC modules, include borker, must use same 'ECODE' code.</h3>"

    


var MQqrcode1 = new QRCode('qrcode1','https://ipcworld.w3spaces.com/SVGPLC/PLC/pwaphwss.html');
document.getElementById('UTLI1').innerText='https://ipcworld.w3spaces.com/SVGPLC/PLC/pwaphwss.html';

var loginincode;




var effectivetopic="";

function PhoneLogicCode()
{
loginincode='***'+systcell[0][0]+'***'+systcell[1][0]+'***'+systcell[2][0]+'***'+systcell[3][0]+'***'+systcell[2][1]; 
document.getElementById('qrcode2').innerText='';
var MQqrcode2 = new QRCode('qrcode2',loginincode);
document.getElementById('UTLI2').innerText='Phone login code';
}

function EffectTopic()
{
for(let t=2;t<ysetdev-1;t++)  
  {if(document.getElementById('radio'+t).checked===true)
    effectivetopic='P'+systcell[1][1]+systcell[0][t];
  }
//effectivetopic='P'+systcell[1][1]+systcell[0][1];
document.getElementById('efftopic').innerText="Effective topic ="+effectivetopic;
}



window.onload = async function(){
  document.getElementById('ssetup').innerHTML=syssetup; 
  loginincode='***'+systcell[0][0]+'***'+systcell[1][0]+'***'+systcell[2][0]+'***'+systcell[3][0]+'***'+systcell[2][1];
  sysloadinitdata();
  Uploadsetup("MQSD");  
}
</script>
)rawliteral";