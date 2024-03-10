static const char PROGMEM INDEX_HTML_helppopup[] = R"rawliteral(
svghints[0]="<h4>Click the icon with the left mouse button to open the corresponding help manual</h4>\
<h4>Use the [STATUS] key to detect the MQTT connection status</h4>\
<h4>Use the [Edit page] key to return to the Edit page editing screen</h4>\
<h4>Use the [Probe] key to test the electrostatic status of the Edit page</h4>\
<h4>Use the [Download] key to load the current ladder diagram program in the Edit page into the PC editing screen.</h4>\
<h4>Use the [Upload] key to send the ladder program from the editing screen to the Edit page</h4>\
<h4>Red line is High voltage</h4>\
<h4>Green Line is low voltage</h4>\
<h4>Yellow Line is open circuit</h4>\
<h4>Short input pin to circuit ground for input activated/h4>\
<h4>Open input pin for deactivated/h4>"
svghints[2]="<h4>Link wire connect bwteen devices</h4><h4>Green for low voltage in simulation</h4><h4>Orange for analog signal go through in imulation</h4>"; 
svghints[4]="<h4>Example of pick up claw</h4><h4>Green for low voltage in simulation</h4><h4>Orange for analog signal go through in imulation</h4>";  
svghints[8]="<h4>Link wire connect bwteen devices</h4><h4>Green for low voltage in simulation</h4><h4>Orange for analog signal go through in imulation</h4>";  
svghints[23]="<h4>Link (4 operation mode)</h4>\
<h4>NONINV the link will follow a relay output</h4>\
<h4>INV the link will follow a relay output with invert condition</h4>\
<h4>AONF output pulse follow the relay ON edge</h4>\
<h4>AONB output pulse follow the relay OFF edge</h4>\
<h4>AONF AONB output pulse for trigger device such as FlipFlop</h4>"
svghints[24]="<h4>Analog output<h4><h4>Range form 0-255<h4>"; 
svghints[25]="<h4>Analog input</h4><h4>ID can re-assign</h4>";
svghints[26]="<h4>Analog input with fixed value</h4><h4>ID can re-assign</h4>"; 
//Normal open
svghints[28]="<h4>Normal open Riseing edge trigger</h4>"; 
svghints[30]="<h4>Normal open digital input</h4><h4>Multiple input pins can be assigned</h4><h4>Green line is low voltage when Probe</h4>"; 
svghints[36]="<h4>Normal close digital input</h4><h4>Multiple input pins can be assigned</h4><h4>Green line is low voltage when Probe</h4>"; 
svghints[37]=
"<h4>Timer (10 operation mode)</h4>\
<h4>Active ON (sec) Normal OFF (Reset to early OFF) Reset pin is option</h4>\
<h4>Active ON (ms ) Normal OFF (Reset to early OFF) Reset pin is option</h4>\
<h4>*Active OFF (sec) Normal ON (Reset to early ON) Reset pin is option</h4>\
<h4>*Active OFF (ms ) Normal ON (Reset to early ON) Reset pin is option</h4>\
<h4>Delay Acitve OFF (sec) Reset pin require to return ON</h4>\
<h4>Delay Acitve OFF (ms) Reset pin require to return ON</h4>\
<h4>*Delay Acitve ON (sec) Reset pin require to return OFF</h4>\
<h4>*Delay Acitve ON (ms) Reset pin require to return OFF</h4>\
<h4>Delay pulse (ms ) pulse out when time's up (Reset not require)</h4>\
<h4>Delay pulse (sec) pulse out when time's up (Reset not require)</h4>\
<h4>*'On' will take effect after the first trigger</h4>";
svghints[38]=
"<h4>Counter (6 operation mode)</h4>\
<h4>Normal OFF Active ON with Debounce delay</h4>\
<h4>Normal OFF Active ON without Debounce delay</h4>\
<h4>Normal ON Active OFF with Debounce delay</h4>\
<h4>Normal ON Active OFF without Debounce delay</h4>\
<h4>Active pulse with Debounce delay</h4>\
<h4>Active pulse without Debounce delay</h4>"
svghints[39]="<h4>RS Flip Flop</h4><h4>Set input & reset input</h4>"; 
svghints[40]="<h4>Digital to Analog</h4><h4>Two digital inputs for up and down, with specify inverval step</h4>"; 
svghints[41]="<h4>Analog to digital</h4>"; 
svghints[42]="<h4>Analog comparator</h4><h4>input range 0-255</h4><h4>Hysteresis control to avoid fluctuate output</h4>"; 
svghints[43]="<h4>Relay output</h4><h4>support multiple assign</h4>"; 
//svghints[44]="<h4>Mqtt Tx</h4><h4>right click to get single board test sample</h4>"; 
//svghints[45]="<h4>Mqtt Rx</h4>"; 

svghints[44]="<h4>Call from Arduino</h4>"; 
svghints[45]="<h4>Call from Arduino</h4><h4>This Version not support MQTT</h4>";
svghints[46]="<h4>This Version not support MQTT</h4>"; 
svghints[47]="<h4>Interrupt Arduino routine</h4><h4>This Version not support MQTT</h4>"; 
//svghints[46]="<h4>User in:</h4><h4>Uart TX with information below:</h4><h4>ID number, Job Number & Argument</h4>"; 
//svghints[47]="<h4>User out:</h4><h4>Uart RX return information below:</h4><h4>Corresponding ID number, Job Number & Job-result</h4>";  
svghints[48]="<h4>Analog Math (8 operation mode)</h4>\
<h4>ASW-N Analog switch, when enable, output=input</h4>\
<h4>ASW-R Analog switch, when enable, output=255-input</h4>\
<h4>Outtput=0 if not enable</h4>\
<h4>Math function result of two inputs, include + - X /</h4>"
svghints[50]="<h4>Phone in</h4><h4>Mqtt or Xhttp</h4><h4>Xhttp only support local network</h4><h4>e.g. 192.168.x.xx:8088</h4><h4>Mqtt support WWW</h4>"; 
svghints[55]="<h4>Phone out</h4><h4>Mqtt or Xhttp</h4><h4>Xhttp only support local network</h4><h4>e.g. 192.168.x.xx:8088</h4><h4>Mqtt support WWW</h4>"; 
svghints[60]="<h4>Repeat timer</h4><h4>generate continue pulse the Specify time interval</h4><h4>\
Signal generator</h4><h4>Time set:</h4><h4>Tap input for PAUSE is optional</h4>\
<h4>Time set:</h4><h4>kilo second, second and millisecond</h4>";
svghints[80]="<h4>Select PLC item to erase</h4>";

var isconnected=0x55aa;

function helpopenModal()
{
switch(comv_icon)
    {case    2:     
        openModal('<b>Vertical line</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/pneumaticControl.png" alt='+reqweb+'>'+text2+st2+Thened); 
        break;
    case    4:
        openModal('<b>Example of vacuum claw pickup</b>\
        <img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/clawpickup.png" alt='+reqweb+'>'+' >\
        <img class="helpimage" src="https://ipcworld.w3spaces.com/SVGPLC/images/pickplace.jpg" alt='+reqweb+'>'+' >\
        '+text4+st4+Thened); 
        break;
    case    8:
        openModal('<b>Temperture Control fan</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/TempertureControlFan.png" alt='+reqweb+'>'+text8+st8+Thened);  
        break;    
    case   23:
        openModal('<b>Link to relay output</b>'+htext23+'<img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/link23.png" alt='+reqweb+'>'+text23+st23+Thened);  
        break;    
    case   24:
        openModal('<b>Analog output</b>'+htext23+'<img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/Math48.png" alt='+reqweb+'>'+text25+st48A+Thened);        
        break;
    case   25:
        openModal('<b>Analog input</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/PLC25-26.png" alt='+reqweb+'>'+text25+st25+Thened);  
        break;   
    case   26:        
        openModal('<b>Constant input</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/TempControl26.png" alt='+reqweb+'>'+text26+st26+Thened);  
        break;
    case   28:       //normal open up arrow 
        openModal('<b>Normal open rising pulse</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/platformAdjust.png" alt='+reqweb+'>'+text28+st28+Thened);  
        break;  
    case   29:        
        openModal('<b>Normal open falling pulse</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/platformControlfallong29.png" alt='+reqweb+'>'+text28+st29+Thened);  
        break;           
    case   30:
        openModal('<b>Timer output pulse</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/TimerPulse.png" alt='+reqweb+'>'+text30+CopyTest+st30+Thened);             
        break;                        
    case   36:
        openModal('<b>Timer 4 operation modes</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/TimerA36.png" alt='+reqweb+'>'+text36+st36A+Thened);  
        break;
    case   37:
        openModal('<b>Timer 4 operation modes</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/Timer4mode.png" alt='+reqweb+'>'+text37+
        '<img class="helpimageM" src="https://ipcworld.w3spaces.com/SVGPLC/images/TimerWaveform.png">'+st37+Thened);          
        break;    
    case   38:
        openModal('<b>FligFlog</b><img class="helpimageM" src="https://ipcworld.w3spaces.com/SVGPLC/images/counter38.png" alt='+reqweb+'>'+text38+st38+Thened+
        '<b>Press Platform up/down control example</b><img class="helpimageM" src="https://ipcworld.w3spaces.com/SVGPLC/images/PressPlatformControl.png" alt='+reqweb+'>'+text38+st38A+Thened);   
        break;     
    case   39:        
        openModal('<b>FligFlog</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/FlipFlop39.png" alt='+reqweb+'>'+text39+st39+Thened);   
        break;     
    case   40:
        openModal('<b>Digital to analog</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/DtoA40.png" alt='+reqweb+'>'+text40+st40+Thened);  
        break; 
    case   41:
        openModal('<b>Analog to digital</b>'+htext41+'<img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/ADconvert41.png" alt='+reqweb+'>'+text40+st41+Thened);  
        break;    
    case   42:
        openModal('<b>Analog comparator</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/CMP42.png" alt='+reqweb+'>'+text42+st42+Thened);  
        break;     
    case   43:
        openModal('<b>Relay</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/RelayFlipFlop.png" alt='+reqweb+'>'+text43+st43+Thened);   
        break;    
    case   44:
        openModal('<b>Mqtt input</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/mqtt44.png" alt='+reqweb+'>'+text44+st44+Thened);
        break;            
    case   45:
        openModal('<b>Mqtt Rx</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/Mqtt45.png" alt='+reqweb+'>'+text44+st45+Thened);              
        break;    
    case   46:
        openModal('<b>User define device input</b>'+htext39+'<img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/userinput47.png" alt='+reqweb+'>'+text46+st47+Thened);   
        break;     
    case   47:
        openModal('<b>User define device output</b>'+htext39+'<img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/userinput47.png" alt='+reqweb+'>'+text47+st47+Thened);  
        break;     
    case   48:
        openModal('<b>FligFlog</b>'+htext39+'<img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/math48.png" alt='+reqweb+'>'+text39+st48+Thened);   
        break; 
    case   50:
        //openModal('<b>FligFlog</b>'+htext39+'<img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/MqttPhone4450.png" alt='+reqweb+'>'+text39+st50+Thened);   
        openModal('<b>FligFlog</b>'+htext39+'<img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/Phone50.png" alt='+reqweb+'>'+text39+st50+Thened);          
        break;  
    case   55:
        openModal('<b>FligFlog</b>'+htext39+'<img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/phoneout55.png" alt='+reqweb+'>'+text39+st55+Thened);   
        break;           
    case   60:
        openModal('<b>Repeat timer</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/RepeatTimer.png" alt='+reqweb+'>'+text80+st60+Thened);  
        break;   
    case   61:      //servo
        openModal('<b>Repeat timer</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/RepeatTimer.png" alt='+reqweb+'>'+text80+st60+Thened);  
        break;   
    case   62:      //servo
        openModal('<b>Repeat timer</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/RepeatTimer.png" alt='+reqweb+'>'+text80+st60+Thened);  
        break;                   
    case   80:
        openModal('<b>Delete device</b><img class="helpimageS" src="https://ipcworld.w3spaces.com/SVGPLC/images/analogcontrolLED.png" alt='+reqweb+'>'+text80+st80+Thened);  
        break;
    case   99:
        openModal(Login);  
        break;             
    case   100:
        openModal(About);      
        break;                                             
    }
}    
var reqweb = "________________Image_require_web_support"


var Login=
'<br><h5>Please Login password</h5><br>\
<br><h5>8 characters</h5><br>\
<input  type="text" id="disp" onclick="inputclick()" class="disp" minlength="4" maxlength="14" size="14"\
style="margin-left:100px;width:250px;height:25px;font-size:20px"></input>\
<br><button class="button but9" id="rmt96" onclick="checkpassword();"\
style="margin-left:150px;width:150px;height:25px;font-size:20px;color:#d5d5d5;background-color:#353535;">Update pw</button>\
</td></tr>'


function inputclick()
{document.getElementById("disp").value="";
}

function checkpassword()
{let disptext1;
let disptext=document.getElementById("disp").value;
if(disptext.length===8)
    {localStorage.setItem("editpageSecret",'*'+disptext);
    document.getElementById("disp").value="Refresh page to start";
    disptext1=localStorage.getItem("editpageSecret");
    console.log("disptext=",disptext1);
    }
else
    disptext=document.getElementById("disp").value="8 characters require";    
if(disptext.length===8)
    {disptext=localStorage.getItem("editpageSecret")
    if(disptext===null)
        {document.getElementById("disp").value="Please input password";
        //document.getElementById("disp").value="";
        console.log("disptext=",disptext);
        }
    }
}


//{if(CheckHWStatus("MCC"+disptext)\
//{disptext=document.getElementById("disp").value;\
//}</script>'

var About=
'<br><h5>Firmware Version: 2.24</h5><br>\
<h5>Features:</h5>\
<h5>(1) Graphic user interface, support by browser</h5>\
<h5>(2) Can link up to 4 PLC with Build-in Mqtt borker/h5>\
<h5>(3) Support analog input out/h5>\
<h5>(4) Build=in http server, Can work without internet</h5>\
<h5>(5) Low power consumption, just use 5V usb power adaptor</h5>\
<h5>(6) Build-in UART hub, support 8 User program functions</h5>\
<h5>(7) Remote program update</h5>\
<h5>(8) Built-in data acquisition function</h5>\
<h5>(9) Built-in help manuals</h5>\
<h5>(10) Built-in simulation</h5>\
<h5>(11) Watch dog monitor</h5>\
<h5>(12) 240 program steps</h5>\
<h5>(13) User define interface</h5>\
<h5>Item 2,8 11 and 12 not for text version/h5>'
//https://howtojs.io/alternative-to-document-execcommand-to-copy-to-clipboard-in-the-browsers-using-javascript/


function copytestarea() {
    var copyText = document.getElementById("values");   
    copyText.select();
    try {
      document.execCommand("copy");
      } catch (err) {
      window.alert("Unable to copy to clipboard, please copy manually",err);
      }
    }

function savetoedit(){
    var rplcdata=document.getElementById("values");     
    document.getElementById("popupbut").innerText="Press Close";   
    document.getElementById("popupbut").style.backgroundColor="green";   
    rplcdata=rplcdata.value;       
    var test = Array(1920).fill("");  
      var arraylength=0;
      var result="";
      for(var t=0;t<5770;t++)  
        {if(rplcdata[t]===',')
          {if(result!="" && result[0]>='0'&& result[0]<='9')
            test[arraylength]=parseInt(result);
          else
            test[arraylength]=result;  
          result="";
          if(arraylength++>1920)
            break;
          }
        else
          {if(rplcdata[t]==='_') 
            result=result+' ';
          else if(rplcdata[t]>='0' && rplcdata[t]<='~' && rplcdata[t]!=']' && rplcdata[t]!='[')
            {result=result+rplcdata[t];
            //console.log('result=',result);
            }
          }
        }    
      console.log('upptest=',test);
      console.log('uppLength=',test.length);
      //localStorage.setItem('plcdata',rplcdata);
      localStorage.setItem('plcdata',JSON.stringify(test));
      localStorage.setItem('refreshpage',"required");
}

var htext23=
'<h5>Noninv Moninvert ON link to relay OFF / ON</h5>\
<h5>inv Invert link to relay ON / OFF </h5>\
<h5>AON-F Activate ON (pulse) link to relay OFF to ON transit</h5>\
<h5>AON-B Activate ON (pulse) link to relay ON to OFF transit</h5>\
<h5>AON-F Activate OFF link to relay OFF to ON transit</h5>\
<h5>AON-B Activate OFF link to relay ON to OFF transit</h5>\
'

var htext37=
'<h5>AON sec- Immediate ON, OFF when timeouts, reset (obtional)</h5>\
<h5>AOFF sec- Immediate OFF, ON when timeouts,  reset (obtional)</h5>\
<h5>DAON sec- Normal off, Output ON when timeout</h5>\
<h5>DAOFF sec- Normal On, Output OFF when timeout</h5>\
'
var htext38=
'<h5>DTP Delay pulse timer output a pulse signal to trigger the flip flop in the specify time delay</h5>\
<h5>The flip flop can direct control by input pins</h5>\
'
var htext39=
'<h5>AL slow Normal ON, OFF when count reached, reset required, slow debounce </h5>\
<h5>AH slow Normal OFF, ON when count reached, reset required, slow debounce </h5>\
<h5>AL fast Normal ON, OFF when count reached, reset required, fast debounce </h5>\
<h5>AH fast Normal OFF, ON when count reached, reset required, fast debounce </h5>\
<h5>Pulse fast Normal OFF, Pulse when count reached, reset(obtional), fast debounce </h5>\
'
var htext44=
'<h5>Default is Normal low, High when set High or pulse, reset is required </h5>\
<h5>Use link can get invert output</h5>\
</textarea>'

var htext40=
'<h5>Up or Down, in a specified step, the defualt step is 32</h5>\
<h5>Analog output, digital pulse control</h5>\
</textarea>'

var htext41=
'<h4From Low to High, or From High to Low, must over the preset valuses</h5>\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,25,281,,0,,,,,42,298,10,0,10,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,,,,25,537,,0,,,,,,,,8,\
</textarea>'

var htext42=
'<h4From Low to High, or From High to Low, must over the preset valuses</h5>\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,25,281,,0,,,,,42,298,10,0,10,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,,,,25,537,,0,,,,,,,,8,\
</textarea>'

var htext43=
'<h5>Up or Down, in a specified step, the defualt step is 32</h5>\
<h5>Analog output, digital pulse control</h5>\
</textarea>'

var st2=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,30,286,,0,,Start_switch,,,38,294,294,0,5,count_for_start_buffer,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,buffer_on,,,30,798,,0,\
,up_switch,,,,,,12,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,811,,0,,up_relay,,,30,286,,0,,Start_switch,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,555,,0,,cyclinder_on,\
</textarea>'

var st4=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
28,284,,0,,start_pick,,,,,,4,,,,,39,295,,0,,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,move_to_pick_area,,,,,,,,,,,,,,,,,,,,,,10,,,,,,,,,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,37,293,2341,2,2,return,\
,,23,535,256,1,791,,,,37,805,2341,0,1,,,,39,551,,0,,,,,43,555,,0,,down_claw,,,28,540,,0,,toucn_sensor,,,37,549,2341,3,1,,,,,,,4,,,,,,,,4,,,,,,,,8,,,,,,,,0,,,,,,,,0,,,,,37,1061,\
2341,1,3,,,,,,,2,,,,,23,279,535,0,791,,,,39,807,,0,,,,,43,1067,,0,,close_vaccum,,,,,,,,,,,,,,,,,,,,,,5,,,,,,,,4,,,,,,,,8,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\
,,,,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,\
</textarea>'

var st8=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,25,281,,0,,,,,,,,6,,,,,42,298,2,0,2,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,,,,,,,,,,,,26,282,100,3,,,,,,,,8,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\
,,,,,,,,,,7,,,,,42,554,2,0,2,,,,,,,4,,,,,,,,4,,,,,43,555,,0,,,,,,,,,,,,,26,282,110,3,,,,,,,,8,,,,,,,,,,,,,,,,,,,,,,,,0,,,,,,,,,,,,,,,,7,,,,,42,810,2,0,2,,,,,,,4,,,,,,,,4,,,,,43,811,\
,0,,,,,,,,,,,,,26,282,120,3,,,,,,,,8,,,,,,,,,,,,,,,,0,,,,,,,,0,,,,,,,,,,,,,,,,5,,,,,42,1066,2,0,2,,,,,,,4,,,,,,,,4,,,,,43,1067,,0,,,,,,,,,,,,,26,282,130,0,,,,,,,,8,\
</textarea>'

var st4A=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,28,284,,0,,Start_up_signal,,,,,,4,,,,,39,295,,0,,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,Move_to_pick_location,,,23,535,791,0,256,\
Return_to_place_location,,,,,,4,,,,,,,,8,,,,,,,,,,,,,,,,,,,,,,,,,,,,,23,279,279,0,279,Down_claw,,,,,,4,,,,,39,551,,0,,,,,,,,4,,,,,,,,4,,,,,43,555,,0,,down_claw,,,23,791,279,\
0,279,Up,,,,,,4,,,,,,,,8,,,,,,,,,,,,,,,,,,,,,,,,,,,,,30,286,,0,,Pick_sensor_got_object,,,,,,4,,,,,39,807,,0,,,,,,,,4,,,,,,,,4,,,,,43,811,,0,,Open_vaccum,,,23,1047,256,0,1047,\
place_item,,,,,,4,,,,,,,,8,\
</textarea>'

var st23=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
60,316,572,0,6,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,,,,23,279,279,0,1047,,,,,,,4,,,,,37,293,805,0,1,,,,,,,4,,,,,,,,4,,,,,43,811,,0,,,,,23,535,791,0,1047,,,,,,,4,,,,,37,549,805,0,1,,,,,,,4,,,,,,,,4,,,,,43,1067,,0,,,,,23,791,1047,0,1047,,,,,,,4,,,,,37,805,805,0,1,,,,,,,4,,,,,,,,4,,,,,43,1323,,0,,,,,23,1047,1303,0,1047,,,,,,,4,,,,,37,1061,805,0,1,,,,,,,4,,,,,,,,4,,,,,43,1579,,0,,,,,23,1303,1559,0,1047,,,,,,,4,,,,,37,1317,805,0,1,,,,,,,4,,,,,,,,4,,,,,43,1835,\
</textarea>'

var st25=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,26,282,111,,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,24,280,,,,,,,25,281,,0,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,24,536,\
</textarea>'

var st26=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,0,,,,,25,281,,0,,Temp_sensor,,,,,,4,,,,,42,298,10,0,10,Temperture_conpare,,,,,,4,,,,,,,,4,,,,,43,299,,0,,Air_conditioner_control,,,26,282,100,0,,compare_value,,,,,,4,,,,,,,,8,\
</textarea>'

var st28=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,28,284,,,,Below_level,,,36,548,,,,Reach_Max,,,37,293,805,,3,Start,,,,,,4,,,,,,,,4,,,,,43,299,,,,Up_motor,,,30,542,,0,,down_plat,,,36,292,,,,limit_sw,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,811,,,,Down_motor,\
</textarea>'

var st29=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,29,285,,0,,Follow_edge_trigger,,,36,548,,,,Reach_Max,,,37,293,805,,3,Start,,,,,,4,,,,,,,,4,,,,,43,299,,,,Up_motor,,,30,542,,0,,down_plat,,,36,292,,,,limit_sw,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,811,,,,Down_motor,\
</textarea>'

var st36A=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
30,286,,,,,,,37,293,293,0,3,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,299,,,,,,,30,542,,0,,,,,,,,8,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,30,286,,0,,,,,37,549,805,0,3,,,,,,,4,,,,,,,,4\
,,,,,,,,4,,,,,43,555,,0,,,,,30,542,,0,,,,,,,,8,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,30,286,,0,,,,,37,805,1317,0,3,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,811,,0,,,,,30,542,,0,,,,,,,,8\
,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,30,286,,0,,,,,37,1061,1829,0,5,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,1067,,0,,,,,30,542,,0,,,,,,,,8,\
</textarea>'

var st30=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,30,1310,,0,0,,,,0,,,4,,,,,37,293,2341,0,1,,,,39,295,,0,0,,,,0,,,4,,,,,43,811,,0,0,,,,30,1566,,0,0,,,,0,,,4,,,,,0,,,4,,,,,0,,,8,\
</textarea>'

var st37=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
0,,,0,,,,,0,,,0,,,,,0,,,0,,,,,0,,,0,,,,,0,,,0,,,,,0,,,0,,,,,28,284,,0,,,,,,,,4,,,,,37,293,293,0,1,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,,,,28,540,,0,0,,,,0,,,4,,,,,37,549,805,0,1,,,,0,,,4,,,,,0\
,,,4,,,,,43,555,,0,0,,,,28,796,,0,,,,,,,,4,,,,,37,805,1317,0,1,,,,,,,4,,,,,,,,4,,,,,43,811,,0,,,,,28,1052,,0,,,,,,,,4,,,,,,,,8,,,,,0,,,0,,,,,0,,,0,,,,,0,,,0,,,,,28,1308,,0,,,,,,,,4,,,,,37,\
1061,1829,0,1,,,,,,,4,,,,,,,,4,,,,,43,1067,,0,,,,,28,1564,,0,,,,,,,,4,,,,,,,,8,\
</textarea>'

var st38=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
30,286,,0,,,,,,,,4,,,,,38,294,294,0,5,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,,,,30,542,,0,,,,,,,,4,,,,,,,,8,\
</textarea>'

var st38A=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
30,286,,0,,,,,30,542,,0,,,,,39,295,,0,,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,Start_cylinder_down,,,23,791,1047,0,791,,,,,,,4,,,,,,,,8,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\
30,798,,0,,zber,,,38,294,550,0,10,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,555,,0,,sylinder_buffer_stop_,,,23,535,1047,0,791,,,,,,,8,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\
,,,,,23,279,535,0,791,,,,37,293,805,0,1,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,811,,0,,start,,,30,1054,,0,,finish_done,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,1067,\
,0,,up_sylinder,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0\
,,,,,,,,0,\
</textarea>'

var st39=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
30,286,,0,,,,,,,,4,,,,,39,295,,0,,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,,,,30,542,,0,,,,,,,,4,,,,,,,,8,,,,,,,,,,,,,,,,,,,,,,,,,,,,,23,279,279,0,535,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,555,\
</textarea>'

var st138=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
60,316,572,0,2,,,,0,,,6,,,,,0,,,4,,,,,37,293,549,0,1,,,,0,,,4,,,,,43,299,,0,0,,,,30,286,,0,0,,,,0,,,1,,,,,0,,,0,,,,,0,,,0,,,,,0,,,0,,,,,0,,,0,,,,,23,279,279,0,279,,,,0,,,4,,,,,0,,,4,,,,,38,550,294,0,\
5,,,,0,,,4,,,,,43,555,,0,0,,,,23,535,535,0,1559,,,,0,,,4,,,,,0,,,4,,,,,0,,,12,,,,,37,549,549,0,1,,,,43,811,,0,0,,,,23,791,791,0,279,,,,0,,,4,,,,,0,,,4,,,,,38,294,294,0,5,,,,0,,,4,,,,,43,1067,,0,0,,,,\
23,1047,1047,0,1559,,,,0,,,4,,,,,0,,,4,,,,,0,,,12,,,,,37,805,549,0,1,,,,43,1323,\
</textarea>'

var st40=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
30,286,,0,,,,,40,552,32,0,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,24,1048,,0,,,,,30,542,,0,,,,,,,,8,,,,,,,,,,,,,,,,0,,,,,,,,,,,,,,,,0,,,,,50,306,,0,,,null,,40,296,32,0,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,24,280,,0,,,,,\
50,562,,0,,,null,,,,,8,\
</textarea>'

var st41=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
25,281,,0,,,,,,,,4,,,,,41,297,138,0,128,,,,,,,4,,,,,,,,4,,,,,43,299,\
</textarea>'

var st42=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
25,281,,0,,,,,,,,4,,,,,41,297,138,0,128,,,,,,,4,,,,,,,,4,,,,,43,299,\
</textarea>'

var st39=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
23,1303,1303,0,1303,,,,30,286,0,0,0,,,,39,295,0,0,0,,,,0,0,0,4,0,,,,0,0,0,4,0,,,,43,299,0,0,0,,,,23,279,1303,0,1559,,,,0,0,0,4,0,,,,0,0,0,8,0,,,,0,0,0,0,0,,,,0,0,0,0,0,,,,0,0,0,0,0,,,,23,1559,1303,0,1303,,,,\
30,542,0,0,0,,,,39,551,0,0,0,,,,0,0,0,4,0,,,,0,0,0,4,0,,,,43,555,0,0,0,,,,23,535,1303,0,1559,,,,0,0,0,4,0,,,,0,0,0,8,0,,,,0,0,0,0,0,,,,0,0,0,0,0,,,,0,0,0,0,0,,,,23,1815,1303,0,1303,,,,30,798,0,0,0,,,,39,807,\
0,0,0,,,,0,0,0,4,0,,,,0,0,0,4,0,,,,43,811,0,0,0,,,,23,791,1303,0,1559,,,,0,0,0,4,0,,,,0,0,0,8,0,,,,0,0,0,0,0,,,,0,0,0,0,0,,,,0,0,0,0,0,,,,23,2071,1303,0,1303,,,,30,1054,0,0,0,,,,39,1063,0,0,0,,,,0,0,0,4,0,,,,\
0,0,0,4,0,,,,43,1067,0,0,0,,,,23,1047,1303,0,1559,,,,0,0,0,4,0,,,,0,0,0,8,0,\
</textarea>'

var st43=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,30,286,,0,,,,,,,,4,,,,,39,295,,0,,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,down,,,23,279,791,0,791,,,,37\
,293,2341,0,,,,,,,,10,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,0,,,,,,,,5,,,,,,,,4,,,,,,,,4,,,,,43,555,,0,,upcydiner,,,30,542,,0,,Sensor,,,,,,4\
,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,811,,0,,moveR,\
</textarea>'

var st44=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
25,281,,0,0,,,,44,300,1068,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,301,,0,0,,,,24,280,,0,0,,,,25,537,,0,0,,,,44,556,1068,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,557,,0,0\
,,,,24,792,,0,0,,,,30,286,,0,0,,,,44,812,1068,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,813,,0,0,,,,43,1323,,0,0,,,,36,548,,0,0,,,,44,1068,1068,0,0,,,,0,,,0,,,,,0\
,,,0,,,,,45,1069,,0,0,,,,43,1835,\
</textarea>'

var st45=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
25,281,,0,0,,,,44,1836,556,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,1837,,0,0,,,,24,1560,,0,0,,,,50,2098,,0,0,,null,,44,2092,556,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,2093,,0,0,,,,43,555,,0,0,,,,50,1330,,0,0,,null,\
,44,1324,556,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,1325,,0,0,,,,43,1323,,0,0,,,,25,537,,0,0,,,,44,1580,556,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,1581,,0,0,,,,24,1816,,0,0,,,,30,542,,0,0,,,,44,812,556,0,0,,,,0,,,\
0,,,,,0,,,0,,,,,45,813,,0,0,,,,43,811,,0,0,,,,36,292,,0,0,,,,44,300,556,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,301,,0,0,,,,43,1067,,0,0,,,,50,562,,0,0,,null,,44,556,556,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,557,,\
0,0,,,,24,2072,,0,0,,,,50,1074,,0,0,,null,,44,1068,556,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,1069,,0,0,,,,24,280,,0,0,\
</textarea>'

var st47=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,25,281,,0,,,,,46,302,46,0,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,60,316,60,0,,,,,,,,8,\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,47,303,47,0,,,,,44,300,44,0,\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,60,572,60,0,,,,,,,,8,\
</textarea>'

var st48=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,25,281,,0,,,,,48,304,304,0,,,,,,,,4,,,,,,,,4,,,,,24,280,,0,,,,,,,,,,,,,30,286,,0,,,,,,,,8,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,25,537,\
,0,,,,,48,560,816,0,,,,,,,,4,,,,,,,,4,,,,,24,536,,0,,,,,,,,,,,,,25,793,,0,,,,,,,,8,\
</textarea>'

var st48A=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,26,282,111,0,,,,,48,304,560,0,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,24,280,,0,,,,,36,292,,0,,,,,,,,8,\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,25,281,,0,,,,,48,560,816,0,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,24,536,,0,,,,,25,537,,0,,,,,,,,8,\
</textarea>'

var st50=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
50,306,,0,,,OK,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,,,,50,562,,0,,,OK,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,555,,0,,,,,50,818,,0,,,OK,,,,,4,\
,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,811,,0,,,,,50,1074,,0,,,OK,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,1067,,0,,,,,50,1330,,0,,,OK,,,,,4,,,,,,,,4,,,,,,,,4,,,\
,,,,,4,,,,,43,1323,,0,,,,,50,1586,,0,,,OK,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,1579,,0,,,,,50,1842,,0,,,OK,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,1835,,0,,\
,,,50,2098,,0,,,OK,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,2091,,0,,,,,,,,0,\
</textarea>'

var st50A=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
50,306,,0,,,OK,,44,300,1068,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,301,,0,0,,,,24,280,,0,0,,,,50,562,,0,,,OK,,44,556,1068,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,557,,0,0,,,,24,792,,0,0,,,,50,818,,0,,,OK,\
,44,812,1068,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,813,,0,0,,,,43,1323,,0,0,,,,50,1074,,0,,,OK,,44,1068,1068,0,0,,,,0,,,0,,,,,0,,,0,,,,,45,1069,,0,0,,,,43,1835,\
</textarea>'

var st55=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
25,281,,0,,test_analog_value,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,55,311,567,0,,test_value,OK,,30,286,,0,,test_digital_HL,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,55,567,55,0,,Test_logic_HL,OK,\
</textarea>'

var st61=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,60,316,572,0,2,,,,37,293,293,2,1,,,,,,,4,,,,,,,,4,,,,,43,299,,\
0,,,,,,,,,,,,,,,,136,,,,,37,293,805,1,1,,,,,,,4,,,,,,,,4,,,,,43,555,</textarea>'

var st60=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,0,,,,,,,,0,,,,,,,,,,,,,,,,0,,,,,,,,,,,,,,,,,,,,,,,,0,,,,,60,316,572,0,1,,,,38,294,294,0,5,,,,,,,4,,,,,,,,4,,,,,43,299,,0\
,,,,,,,,,,,,,,,,136,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,,,,0,,,,,23,535,279,0,791,,,,,,,4,,,,,39,295,,0,,,,,,,,4,,,,,,,,4,,,,,43,\
811,,0,,,,,23,279,279,0,791,,,,,,,4,,,,,37,293,549,0,5,,,,,,,4,,,,,,,,4,,,,,43,555,,0,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\
,,,,,,,,,,,,,,30,542,,0,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,1067,,0,,,,,23,791,1047,0,791,,,,,,,4,,,,,37,293,549,0,1,,\
,,,,,4,,,,,,,,4,,,,,43,1323,\
</textarea>'

var st80=
'<textarea class="helpcode" style="width:400px;height: 120px;padding:30px;margin-left:30px; font-size:10pt" id="values">\
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,25,281,,0,,,,,,,,6,,,,,42,298,2,0,2,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,,,,,,,,,,,,26,282,100,3,,,,,,,,8,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\
,,,,,,,,,7,,,,,42,554,2,0,2,,,,,,,4,,,,,,,,4,,,,,43,555,,0,,,,,,,,,,,,,26,282,110,3,,,,,,,,8,,,,,,,,,,,,,,,,,,,,,,,,0,,,,,,,,,,,,,,,,7,,,,,42,810,2,0,2,,,,,,,4,,,,,,,,4,,,,,43,811,\
,0,,,,,,,,,,,,,26,282,120,3,,,,,,,,8,,,,,,,,,,,,,,,,0,,,,,,,,0,,,,,,,,,,,,,,,,7,,,,,42,1066,2,0,2,,,,,,,4,,,,,,,,4,,,,,43,1067,,0,,,,,,,,,,,,,26,282,130,3,,,,,,,,8,,,,,,,,,,,,,,,,\
,,,,,,,,,,,,,,,,,,,,,,,,7,,,,,42,1322,2,0,2,,,,,,,4,,,,,,,,4,,,,,43,1323,,0,,,,,,,,,,,,,26,282,140,3,,,,,,,,8,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,7,,,,,42,1578,2,0,2,,,,,,,4,,,\
,,,,,4,,,,,43,1579,,0,,,,,,,,,,,,,26,282,150,3,,,,,,,,8,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,7,,,,,42,1834,2,0,2,,,,,,,4,,,,,,,\
,4,,,,,43,1835,,0,,,,,,,,,,,,,26,282,160,3,,,,,,,,8,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,5,,,,,42,2090,2,0,2,,,,,,,4,,,,,,,,4,,,,,43,2091,,0,,,,,,,,,,,,,26,282,170,0,,,,,,,,8,\
</textarea>'

var phonecontrol=
'50,306,,0,,,OK,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,299,,0,,,,,50,562,,0,,,OK,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,555,,0,,,,,50,818,,0,,,OK,,,,,4,,,,,,,,4\
,,,,,,,,4,,,,,,,,4,,,,,43,811,,0,,,,,50,1074,,0,,,OK,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,1067,,0,,,,,50,1330,,0,,,OK,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,\
1323,,0,,,,,50,1586,,0,,,OK,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,1579,,0,,,,,50,1842,,0,,,OK,,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,1835,,0,,,,,50,2098,,0,,,OK,\
,,,,4,,,,,,,,4,,,,,,,,4,,,,,,,,4,,,,,43,2091,,0,\
</textarea>'

var text2=
'<h6>Pneumatic cylinder control example</h6>'

var text4=
'<h6>Vaccum claw pick up example</h6>'

var text8=
'<h6>For device enable, reset, second input etc.</h6>'

var text23=
'<h5>Set a fixed constant value</h5>\
<h5>Range from 0 to 255</h5>\
<h5>corresponding range 0 to 3.3V</h5>\
<h5>Another is variable value input and output to analog pin/h5>\
'
var text25=
'<h5>Set a fixed constant value</h5>\
<h5>Range from 0 to 255</h5>\
<h5>corresponding range 0 to 3.3V</h5>\
<h5>Another is variable value input and output to analog pin/h5>\
'
var text26=
'<h5>Set a fixed constant value</h5>\
<h5>Range from 0 to 255</h5>\
<h5>corresponding range 0 to 3.3V</h5>\
'
var text28=
'<h6>Example of a auto adjust level platform</h6>\
<h6>When a Din touched, the platform up motor will on for 3 second</h6>'

var text30=
'<h5>Press Din5, timer output a pulse after 1 second, it will trigger flipflop on</h5>\
<h5>Press Din6 to reset the flipflop</h5>'

var text36=
'<h5>(1) Active off timer, press Din 1, relay will off for 3 seconds,</h5>\
<h5>It can early resume normal when press Din2.</h5>\
<h5>(2) Active on timer, press Din 1, relay will on for 3 seconds,</h5>\
<h5>It can early resume normal when press Din2.</h5>\
<h5>(3) Active on timer, press Din 1, relay will on after 3 seconds,</h5>\
<h5>It will continue on until press Din2.</h5>\
<h5>(4) Active off timer, press Din 1, relay will off for 5 seconds,</h5>\
<h5>It will continue off until press Din2.</h5>'

var text37=
'<h5>Timer (10 operation mode)</h4>\
<h5>Active ON (sec) Normal OFF (Reset to early OFF) Reset pin is option</h5>\
<h5>Active ON (ms ) Normal OFF (Reset to early OFF) Reset pin is option</h5>\
<h5>Active OFF (sec) Normal ON (Reset to early ON) Reset pin is option</h5>\
<h5>Active OFF (ms ) Normal ON (Reset to early ON) Reset pin is option</h5>\
<h5>Delay Acitve OFF (sec) Reset pin require to return ON</h5>\
<h5>Delay Acitve OFF (ms) Reset pin require to return ON</h5>\
<h5>Delay Acitve ON (sec) Reset pin require to return OFF</h5>\
<h5>Delay Acitve ON (ms) Reset pin require to return OFF</h5>\
<h5>Delay pulse (ms ) pulse out when times up (Reset not require)</h5>\
<h5>Delay pulse (sec) pulse out when times up (Reset not require)</h5>';

var text38=
'<h5Default is Normal low, High when set High or pulse, reset to normal</h5>'

var text39=
'<h5Default is Normal low, High when set High or pulse, reset to normal</h5>'

var text40=
'<h5>Up or Down, in a specified step interval, the defualt step interval is 32</h5>\
<h5>Analog output, digital pulse control</h5>\
</textarea>'

var text42=
'<h5>Compare two analog levels</h5>\
<h5>A hysteresis to avoid bouncing or unstable</h5>'

var text43=
'<h5>Relay output example</h5>\
'
var text44=
'<h4>Mqtt input example</h4>'

var text46=
'<h4>Mqtt input example</h4>'

var text47=
'<h4>Mqtt input example</h4>'

var text80=
'<h4>Example analog control LED</h4>'

var Thened=
'<br><br><button onclick="savetoedit()" id="popupbut" class="popupbut">Copy to Edit page</button><br><br>\
<h5>close window, and than,</h5><h5> press Edit page button to upload this program into Edit page</h5><br><br><br>'

var CopyTest=
'<button class="ctt" onclick="copytestarea()">Copy text</button>'
)rawliteral";

