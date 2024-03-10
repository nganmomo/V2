static const char PROGMEM INDEX_HTML_setupclock[] = R"rawliteral(
<html>
<body>
<br><label for='Current time' style='margin-left:10px'>Current time </label><input type='time' id='ctime' step='3600'>
<label for='Startday'>Current date </label><input type='date' id='cdate'>
<label for='UTC' style='margin-left:50px'>UTC </label><input type='number' id='utc' style='width:40px'>
<button type='button' onclick='getdaydatetime(0)' style='margin-left:60px' >Current date/time</button>
<br><br>
<div id=ssetup></div>
</body>
</html>  
<script>
// For mqtt
let xsetdev=6;
let ysetdev=16;
var timedata="";
//for htmltestpage.html
var rowtext = Array.from(Array(xsetdev), () => new Array(ysetdev)); 
var systcell = Array.from(Array(xsetdev), () => new Array(ysetdev).fill("")); 

function getdaydatetime(Getdefault)
{
const Today = new Date();
const dd = String(Today.getDate()).padStart(2, '0');
const mm = String(Today.getMonth() + 1).padStart(2, '0'); //January is 0 so we need to add 1
const yyyy = Today.getFullYear();
const utcHour = Today.getUTCHours();
const localHour = Today.getHours();  
UTC=-(utcHour-localHour);
  if(UTC>12)  UTC=UTC-24;  
//console.log("Current date:", Today);
const formattedDate = yyyy+'-'+mm+'-'+dd;
const formattedTime = Today.toLocaleTimeString('en-US', { hour12: false });
document.getElementById('utc').value=UTC; 
document.getElementById('ctime').value=formattedTime;
document.getElementById('cdate').value=formattedDate;
if(Getdefault===1)
  {for(let j=0;j<ysetdev;j++)    
    {document.getElementById('clkid'+j).value=0;
    document.getElementById('setbt'+j).value=formattedTime;
    document.getElementById('setet'+j).value=formattedTime;
    document.getElementById('setbd'+j).value=formattedDate;
    document.getElementById('seted'+j).value=formattedDate;
    //document.getElementById('cycle'+j).value=0;
    }
  }  
}

function sysloadinitdata(){      
console.log('cd0',systcell);   
 
  for(let t=0;t<ysetdev;t++)                                            
      {rowtext[0][t]= "<td><label>Clock ID:</label>\
      <select id='clkid"+t+"'>\
      <option value=0>OFF</option>\
      <option value=1>1</option>\
      <option value=2>2</option>\
      <option value=3>3</option>\
      <option value=4>4</option>\
      <option value=5>5</option>\
      <option value=6>6</option>\
      <option value=7>7</option>\
      <option value=8>8</option>\
      </select><style='width:60px'></td>"                        
      rowtext[1][t] = "<td><label for='time-input'>On </label><input type='time' id='setbt"+t+"' step='3600' onclick='tcopyto("+t+",0)' onchange='tcopytonext("+t+",1)'></td>"                        
      rowtext[2][t] = "<td><label for='time-input'>Off </label><input type='time' id='setet"+t+"' step='3600' onchange='tcopytonext("+t+")'></td>"                        
      rowtext[3][t] = "<td><label for='Startday'>Begin </label><input type='date' id='setbd"+t+"' onchange='dcopytonext("+t+")'></td>"    
      rowtext[4][t] = "<td><label for='Endday'>End </label><input type='date' id='seted"+t+"' onchange='dcopytonext("+t+")'></td>"                        
      //rowtext[5][t] = "<td>Cycle \
      //<select id='cycle"+t+"'>\
      //<option value=0>Once</option>\
      //<option value=1>Daily</option>\
      //<option value=2>weekly</option></td>\
      //<option value=3>forever</option></td>"
      }              


  for(let j=0;j<ysetdev;j++)  
      {row = document.getElementById('myDRow'+j.toString());         
      x0 = row.insertCell(0);  //insert
      x1 = row.insertCell(1);      
      x2 = row.insertCell(2); 
      x3 = row.insertCell(3); 
      x4 = row.insertCell(4);     
      //x5 = row.insertCell(5);                         
      x0.innerHTML = rowtext[0][j];  //
      x1.innerHTML = rowtext[1][j];  //   
      x2.innerHTML = rowtext[2][j];  //
      x3.innerHTML = rowtext[3][j];  //  
      x4.innerHTML = rowtext[4][j];  //   
      //x5.innerHTML = rowtext[5][j];  //            
      }                
   }     

function  tcopyto(t,step)
{if((document.getElementById('clkid'+t).value)==='0')
  window.alert("Enter Clock ID before time/date");      
if(step===0)
  {getdaydatetime(0);
  document.getElementById('setbt'+t).value=formattedTime;
  document.getElementById('setbd'+t).value=formattedDate; 
  }
if(step===1)
  {document.getElementById('setet'+t).value=document.getElementById('setbt'+t).value;
  document.getElementById('seted'+t).value=document.getElementById('setbd'+t).value; 
  }    
}

function  tcopytonext(t)
{if((document.getElementById('clkid'+t).value)==='0')
  window.alert("Enter Clock ID before time/date");     
if(document.getElementById('setet'+t).value<document.getElementById('setbt'+t).value)   
  {document.getElementById('setet'+t).value=document.getElementById('setbt'+t).value
  //window.alert("End time must greater than begin time");
  }  
}

function  dcopytonext(t)
{if((document.getElementById('clkid'+t).value)==='0')
  window.alert("Enter Clock ID before time/date");     
getdaydatetime(0);
if(document.getElementById('setbd'+t).value<formattedDate)
  document.getElementById('setbd'+t).value=formattedDate;   
if(document.getElementById('seted'+t).value<document.getElementById('setbd'+t).value)
  {document.getElementById('seted'+t).value=document.getElementById('setbd'+t).value;
  window.alert("End day must greater than begin day");
  }  
}

function Uploadclock()
{//MQSd
timedata="";  
for(let j=0;j<ysetdev;j++)    
    {timedata=timedata+'*'+document.getElementById('clkid'+j).value;
    timedata=timedata+document.getElementById('setbt'+j).value;
    timedata=timedata+document.getElementById('setet'+j).value+'$';
    timedata=timedata+document.getElementById('setbd'+j).value+'$';
    timedata=timedata+document.getElementById('seted'+j).value;
    //timedata=timedata+document.getElementById('cycle'+j).value;
    }  
timedata=timedata.replaceAll(':','');
timedata=timedata.replaceAll('$20','');
timedata=timedata.replaceAll('-','');
let le=timedata.length;
let UTC=document.getElementById('utc').value;
//localStorage.setItem('Timedata',timedata); 
Uploadsetup("MQSu"+UTC+timedata);  
}

const currentDate = new Date();
const currentTime = new Date();
const formattedDate = currentDate.toISOString().split('T')[0];
const formattedTime = currentTime.toLocaleTimeString('en-US', { hour12: false });  

syssetup=
"<table class='devtable'>\
<tbody>\
<tr id='myDRow0'></tr><tr id='myDRow1'></tr><tr id='myDRow2'></tr><tr id='myDRow3'></tr><tr id='myDRow4'>\
</tr><tr id='myDRow5'></tr><tr id='myDRow6'></tr><tr id='myDRow7'></tr><tr id='myDRow8'></tr>\
<tr id='myDRow9'></tr><tr id='myDRow10'></tr><tr id='myDRow11'></tr><tr id='myDRow12'></tr><tr id='myDRow13'>\
</tr><tr id='myDRow14'></tr><tr id='myDRow15'>\
</tbody>\
</table>\
<br>\
<button type='button' onclick='getdaydatetime(1)' style='margin-left:350px' >Reset</button>\
<button type='button' id='upl' onclick='Uploadclock()' style='margin-left:200px'>Upload setup</button><br>\
<h3 id='testNet' style='display:inline;margin-left:100px'></h3>\
<h3>Time signal is received from WiFi please keep Wi-Fi on</h3>\
<h3>To avoid set time overlap, it may cause unespect result</h3>\
<style>input{\
  background: rgb(161, 154, 154);\
  text-align: center;}\
</style>"

var UTC="";

window.onload = async function(){
  document.getElementById('ssetup').innerHTML=syssetup;  
  getdaydatetime(0);  
  ///////////////////calculate day of year
  //const date = new Date(2023, 11, 12); // Months are 0-indexed  month must minus 1
  //const startOfYear = new Date(2023, 0, 1); // January 1st
  //const dayOfYear = Math.ceil((date - startOfYear) / (24 * 60 * 60 * 1000));
  //const month = (date.getMonth() + 1).toString().padStart(2, '0');
  //const day = date.getDate().toString().padStart(2, '0');
  //const year = date.getFullYear().toString().slice(-2);
  ///////////////////
  sysloadinitdata();
  //timedata=localStorage.getItem('Timedata'); 
  Uploadsetup("MQSd");     
}

function Uploadsetup(Txdata)  //txdata= "MQSD"
{//MQSU MQSD   
URL=window.location.host; 
//URL="192.168.1.84:8088"  
var xhtp = new XMLHttpRequest(); 
  xhtp.onreadystatechange = function() { 
  let tc=0;
  if(this.readyState == 4 && this.status == 200) {      
    let txre=this.responseText[0]+this.responseText[1]+this.responseText[2]+this.responseText[3];                                       
    timedata=this.responseText;
      if(txre==="mQsD")   //mQsU is Download     
        {if(timedata[5]==='*')
          document.getElementById('utc').value=timedata[4]; 
        else
          document.getElementById('utc').value=-timedata[5];   
        for(let y=4;y<timedata.length;y++)
          {if(timedata[y]==='*')
            {document.getElementById('clkid'+tc).value=timedata[y+1];
            document.getElementById('setbt'+tc).value=timedata[y+2]+timedata[y+3]+':'+timedata[y+4]+timedata[y+5]+':'+timedata[y+6]+timedata[y+7];
            document.getElementById('setet'+tc).value=timedata[y+8]+timedata[y+9]+':'+timedata[y+10]+timedata[y+11]+':'+timedata[y+12]+timedata[y+13];       
            document.getElementById('setbd'+tc).value='20'+timedata[y+14]+timedata[y+15]+'-'+timedata[y+16]+timedata[y+17]+'-'+timedata[y+18]+timedata[y+19];
            document.getElementById('seted'+tc).value='20'+timedata[y+20]+timedata[y+21]+'-'+timedata[y+22]+timedata[y+23]+'-'+timedata[y+24]+timedata[y+25];
            //document.getElementById('cycle'+tc).value=timedata[y+26];      
            tc++;       
            }
          }  
        }
      if(txre==="mQsU")   //mQsU is Download       
        window.alert("Upload successful");
      }                           
    }     
  xhtp.open("GET","http://"+URL+"/action?go=" + Txdata, true);     
  xhtp.send();  
}
</script>
)rawliteral";