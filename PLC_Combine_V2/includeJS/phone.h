static const char PROGMEM INDEX_HTML_phone[] = R"rawliteral(
<html>
<head><link href='http://ipcworld.online/SVGPLC/images/favicon.ico' type='image/x-icon' rel='shortcut icon'/>
<!--
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>MQTT Publisher</title>
<script src="https://cdnjs.cloudflare.com/ajax/libs/paho-mqtt/1.0.1/mqttws31.min.js" type="text/javascript"></script>
-->
</head>
<title>ESP32-CAM Xhttp phone</title>
<meta name='viewport' content='width=device-width, initial-scale=1'>
<body>
<a href="http://ipcworld.online/pwa/pwaph.html" style=color:burlywood><h2>Donkey LAN</h2></a> 
<label id="init">Input put password</label>
<br>
<tr>
<input  type='text' id='disp' onclick='inputclick()' class='disp' minlength='4' maxlength='16' size='14'></input>
<table class='devtable'><tbody>
<tr id='myDRow0'></tr><tr id='myDRow1'></tr><tr id='myDRow2'></tr><tr id='myDRow3'></tr>
<tr id='myDRow4'></tr><tr id='myDRow5'></tr><tr id='myDRow6'></tr><tr id='myDRow7'></tr>
</tbody>
</table>
<br>
<button class='button but9' id='rmt96' onclick='updatepassword();'>Verify ID</button>
<!--button class='button but9' id='rmt96' onclick='location.reload();'>Refresh</button-->
</body>
<script>
let protocal=0;     //0 for xhttp  1 for mqtt
let mxsetdev=5;
let mysetdev=6;  
var rowtext = Array.from(Array(6), () => new Array(8)); 

var butcolor = ["#101010","#2f4468","#0c570c","808480","#576935"];
var ratio=Array(8).fill("0"); 
var kvalue=Array(24).fill(" "); 
var keyv="";
var keyvout="";
var PreviousKey=0;

function loadkeytable2(){    
  for(let t=0;t<mysetdev;t++)   
    {   let v=t+1;
        rowtext[0][t] = "<td><button class='button but1' id='rmt"+v+"1' onclick='toggleCheckbox("+v+"1);'>"+v+"</button></td>"
        rowtext[1][t] = "<td><button class='button but2' id='rmt"+v+"2' onclick='toggleCheckbox("+v+"2);'>"+v+"</button></td>"
        rowtext[2][t] = "<td><button class='button but3' id='rmt"+v+"3' onclick='toggleCheckbox("+v+"3);'>"+v+"</button></td>"
        rowtext[3][t] = "<td><button class='button but4' id='rmt"+v+"4' onclick='toggleCheckbox("+v+"4);'>"+v+"</button></td>"
        rowtext[4][t] = "<td><button class='button but5' id='rmt"+v+"5' onclick='toggleCheckbox("+v+"5);'>"+v+"</button></td>"
        rowtext[5][t] = "<td><button class='button but6' id='rmt"+v+"6' onclick='toggleCheckbox("+v+"6);'>"+v+"</button></td>"
    }     
  for(let j=0;j<mysetdev;j++)  
      {row = document.getElementById('myDRow'+j.toString());         
      for(let k=0;k<mxsetdev;k++)
        {x0 = row.insertCell(k);        
        x0.innerHTML = rowtext[k][j];  //        
        }      
      }          
      //toggleCheckbox(999);    //request load key character  
}


function inputclick()           //display click
{if(butcolor[keytype]!=null && PreviousKey>0)
    document.getElementById('rmt'+PreviousKey).style.backgroundColor=butcolor[keytype];//"#2f4468"; 
  document.getElementById('disp').value=""; 
}

var  txed="";
var  norepeat=0;
var  keyno=0;
var  keytype=0;
var  disptext;
var  islock;
function updatepassword()
{
//txmessage='INITK'; // phone initial
//publishMessage();
RXstatus=0;
let k=0;
disptext=document.getElementById("disp").value;  
  if(disptext.length==8)  
    localStorage.setItem('phoneSecret',disptext);     
  else if(disptext=document.getElementById("disp").value==="Pls Verify ID")
    disptext=localStorage.getItem('phoneSecret'); 
  else if(disptext.length!=8)// && disptext[0]=='*')
    document.getElementById("disp").value="Must 8 character";   
  toggleCheckbox(96); //update password
  document.getElementById('rmt96').style.backgroundColor="#3A3736";//dark butcolor[keyno];  
    //if(PreviousKey!=0)
    //  document.getElementById('rmt'+PreviousKey).style.backgroundColor=butcolor[keytype];//"#2f4468";   
    //  document.getElementById('init').innerText="";    
}
/*
function updatepassword()
{
disptext=document.getElementById("disp").value;  
if(disptext.length!=8)  // && disptext[0]=='*')
  document.getElementById("disp").value="Must 8 character"; 
else
  {localStorage.setItem('phoneSecret',disptext);   
  disptext=localStorage.getItem('phoneSecret');  
  if(disptext===null)
    document.getElementById("disp").value="Pls update pw"; 
  else
    {toggleCheckbox(96); //update password
    document.getElementById('rmt96').style.backgroundColor="#3A3736";//butcolor[keyno];  
    if(PreviousKey!=0)
      document.getElementById('rmt'+PreviousKey).style.backgroundColor=butcolor[keytype];//"#2f4468";   
      document.getElementById('init').innerText="";
    }
  }
}
*/
/////////////////////////////////
function toggleCheckbox(x)
{if(x<98)
  {//if(PreviousKey!=0)
  //  document.getElementById('rmt'+PreviousKey).style.backgroundColor=butcolor[keytype];//"#2f4468"; 
  keyno=parseInt(x/10)-1;
  if(x==96)   //update password
  document.getElementById('rmt'+x).style.backgroundColor="#3A3736";//butcolor[keyno];
  else
  {document.getElementById('rmt'+x).style.backgroundColor="yellow";//butcolor[keyno];
  PreviousKey=x;  
  keytype=x%10;  
  }
  toggleCheck(x); //tx key to PLC
  norepeat=1;     //get display once 
  }
else
  {const myTimeout = setTimeout(getdispay,500);      
  }
}

function getdispay()
{if(norepeat===1)
  {toggleCheck('T'); //show display
    norepeat=0;
  if(PreviousKey!=0)
    document.getElementById('rmt'+PreviousKey).style.backgroundColor=butcolor[keytype];//"#2f4468";   
  }  
}

function FBhandledisplay(responseText,x)
{var j;
var t=0;
let hx=x/10;
let lx=x%10;  
var avalue=0;
keyvout=keyv;
keyv="";     //response to display o 4-18 position
let disptext="";
if(responseText[3]==='d' || responseText[3]==='k' || responseText[3]==='t')  
  {for(let t=4;t<21;t++)
    {if(responseText[t]===undefined)
      break;
    if(responseText[t]==="u0000")
      continue;   
    disptext=disptext+responseText[t];
    if(disptext==="READY")
      islock=0;  
    }            
  if(responseText[4]==='A' && responseText[5]===':' && responseText[6]==='=') 
    {avalue=responseText[7]+responseText[8]+responseText[9];
    document.getElementById('disp').value='A:='+(avalue*ratio[keyno]/255).toFixed(2)+'/D:='+responseText[14]+
    '('+responseText[16]+'/'+responseText[18]+')';
    }
  else
    {if(islock===1)
      document.getElementById('disp').value="PLS Verify ID";  //add to PWA
    else  
      {document.getElementById('disp').value=disptext;
      if(disptext==='ID not match')
        document.getElementById('rmt96').style.backgroundColor="#111111";//2f4468";//butcolor[keyno];
      else
        {if(disptext[0]==='O' && disptext[1]==='N')
          document.getElementById('rmt'+PreviousKey).style='border:1px solid #c51919;width:'+WW+'px;height:'+HH+'px';  
        else
          document.getElementById('rmt'+PreviousKey).style='border:0px solid #c51919;width:'+WW+'px;height:'+HH+'px';
        }
      }
    }          
  }  
else
  document.getElementById('disp').value="";  
if(responseText[3]==='k') 
  toggleCheckbox(100);  //request display
if(responseText[4]==='P' && responseText[5]==="L" && responseText[6]==="S")  //require update password
  document.getElementById('rmt96').style.backgroundColor="#2f4468";//butcolor[keyno];       
//////////////Request display continue/////////// 
}

var WW;
var HH;

function handleInitKey(responseText){
  var keyv="";
  var k=1;
  var t=10;
  let tmpic="";
  const  tx=['140','140','100','80','60','50','53'];
  const  ty=['130','130','120','70','45','45','45','40'];
  if(responseText[3]=='R')
  {for(j=60;j<350;j++)
    {if(responseText[j]==='*' && responseText[j+1]==='^' && responseText[j+2]==='^')  
      {for(let t=3;t<35;t++)
        tmpic=tmpic+responseText[j+t];       
      localStorage.setItem('phoneMqttSecret',tmpic);   
      j=j+35;                     
      }
    if(responseText[j]==='*' && responseText[j+1]==='$' && responseText[j+2]==='^')  
      {
        mxsetdev=responseText[j+3];
        mysetdev=responseText[j+4];
        WW=tx[mxsetdev];
        HH=ty[mysetdev];
        keyv="";
        loadkeytable2();
        for(let y=1;y<=mysetdev;y++)
          {for(let x=1;x<=mxsetdev;x++) 
            {t=y*10+x;
            document.getElementById('rmt'+t).style.width=tx[mxsetdev]+'px';     
            document.getElementById('rmt'+t).style.height=ty[mysetdev]+'px';                       
            if(mysetdev<4 || mysetdev<4)  
              document.getElementById('rmt'+t).style.margin="13px 13px"; 
            }
          }   
        document.getElementById('rmt96').style.backgroundColor="#111111";                      
        break;              
      }
    else    
      keyv=keyv+responseText[j];      
    }  
  for(j=4;j<350;j++)   
    {if(responseText[j]==='@') // && responseText[j+2]=='%')             
      {if(k<=mxsetdev && t<=(mysetdev*10))                                 
        document.getElementById('rmt'+(k+t)).innerText=keyv;            //yx                              
      if(k===6)                        
        ratio[(t/10)-1]=keyv;                    //store a value 
      ////////////
      keyv=""; 
      if(k++>=6)
        {k=1;
        t=t+10;
        }
      if(t>80)                       
        break;                      
      }
    else
      keyv=keyv+responseText[j];                                                                                                                                                                                                
    }
  }
if(responseText[3]=='o')
  {
  document.getElementById('disp').value=responseText[4]+responseText[5]; 
  }  
}
///////////////////FOR XHTTP COMMUNICATION////////////////
function toggleCheck(x) {
//if(keyv.length>20)
//keyv="";
//kvalue[x]; 
var xhr = new XMLHttpRequest();
xhr.onreadystatechange = function() {
  if (this.readyState == 4 && this.status == 200)           
    FBhandledisplay(this.responseText,x);     
  }
  ///////////////////////
  if(x!='T')
  {if(x!=96) //show value except verify password
    {disptext=document.getElementById('disp').value;
    if(disptext!="0")//disptext[0]!='*')  //convert accordingly
      {if(parseInt(disptext)>parseInt(ratio[~~(x/10)]))
        {document.getElementById('disp').value="over maximum";          
        disptext="255";
        }
      else
        disptext=~~(parseInt(disptext)*255/parseInt(ratio[~~(x/10)]));             
      }  
    }  
    if(x===96)// && disptext.length!=8)  
      {disptext=localStorage.getItem('phoneSecret');   
      x="/action?go=mobo" + x + disptext;
      }
    else
      x="/action?go=mobk" + x;  
  }
  else
      x="/action?go=mobt"; 
  xhr.open("GET","http://"+URL+x, true);            
  xhr.send();                     
}
var pw=0;
//////////////////////////////////////////
window.onload = async function(){ 
  URL=window.location.host;
  //URL="192.168.1.84:8088";
  updatekeytext();  
  document.getElementById("disp").value="Pls Verify ID";    
  islock=1;
  }
//////////////////////////////////////////
function updatekeytext() {
var xhr = new XMLHttpRequest();  
xhr.onreadystatechange = function() {
  if(this.readyState == 4 && this.status == 200) {    
    handleInitKey(this.responseText);
    } 
  }  
//xhr.open("GET",URL+"action?go=keyr", true);
xhr.open("GET","http://"+URL+"/action?go=keyr", true);
xhr.send();  
}
</script>
<style> 
  body { font-family: Arial; text-align: center; margin:0px auto; padding-top: 30px; background-color: rgb(58, 56, 55);}
  table { margin-left: auto; margin-right: auto; }
  td { padding: 8 px; }
  .button {    
    border: none;
    color:  rgb(214, 207, 202);
    padding: 5px 5px;
    text-align: justfy;
    text-decoration: none;
    display: inline-block;
    font-size: 14px;
    margin: 3px 3px;
    width:53px;
    height:30px;
    cursor: pointer;   
    border-radius: 12%;
    -webkit-tap-highlight-color: rgba(0,0,0,0);
  }
  .but {
    background-color: rgb(196, 189, 184);
    color:rgba(7, 7, 6, 0.788);
  }
  .but1 {
    background-color: #2f4468;    
  }
  .but2 {
    background-color: rgb(12, 87, 12);   
  }
  .but3 {
    background-color: rgb(128,134,128);  
  }
  .but4 {
    background-color: rgb(87,105,53);   
  }
  .but5 {
    background-color: rgb(121,37,37);  
  } 
  .but6 {
    background-color: rgb(138, 190, 41);   
  }
  .but7 {
    background-color: rgb(87, 59, 212);  
  } 
  .but8 {
    background-color: rgb(206, 111, 111);  
  } 
  .but9 {
    background-color: rgb(17, 17, 17); 
    color:rgb(58, 56, 55);
    width:100px; 
  }    
  .disp{text-align: center;
    font-size: 25px;
    background-color: chocolate;
    border-color:black;
    border-width: 2px;
    margin-bottom: 15px;
    border-radius: 10%;
    }
</style>
</html>
)rawliteral";