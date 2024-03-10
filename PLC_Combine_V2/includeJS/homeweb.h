static const char PROGMEM INDEX_HTML_homeweb[] = R"rawliteral(
<!DOCTYPE html>
<head>
<title>Network Programmable Logic control</title>
</head>

<!--Begin of selection -->

<link rel="icon" type="image/x-icon" href="https://ipcworld.w3spaces.com/SVGPLC/images/favicon.ico">
<script src="https://ipcworld.w3spaces.com/SVGPLC/icontext.js"></script>  
<script src="https://ipcworld.w3spaces.com/SVGPLC/svgplccell.js"></script>    
<script src="https://ipcworld.w3spaces.com/SVGPLC/Property.js"></script> 
<script src="https://ipcworld.w3spaces.com/SVGPLC/Linkhardware.js"></script>
<script src="https://ipcworld.w3spaces.com/SVGPLC/helppopup.js"></script> 
<link rel="stylesheet" href="https://ipcworld.w3spaces.com/SVGPLC/css/plcsvg.css">

<!--
<link href='http://ipcworld.online/favicon.ico' type='image/x-icon' rel='shortcut icon'/>
<script src="icontext.js"></script> 
<script src="svgplccell.js"></script>     
<script src="Property.js"></script>    
<script src="Linkhardware.js"></script>   
<script src="helppopup.js"></script>      
<link rel="stylesheet" href="css/plcsvg.css">  
-->
<!--End of selection -->
<script>
//var tryonline=1;      //Require hardware
var tryonline=0;    //Not require hardware
</script>

<meta name="viewport" content="width=device-width, initial-scale=1">
<body>

<div class="navbar"> 
    <button style="margin-left:25px" onclick="history.back()">homehw</button>
    <button type="button" class="botstatus" id="botstatus" onclick="CheckHWStatus(0)" >STATUS</button>   
    <button type="button" class="plcedit" id="plcedit" onclick="showedit(1)" >Edit page</button>   
    <button type="button" class="botcl" onclick="clearfile()" >clear</button>    
    <button type="button" class="botsim" onclick="uploadesp('swur',0)" >Probe</button> 
    <button type="button" class="botdl" onclick="DownloadFromHW('start')" >download</button>
    <button type="button" class="botul" id="botul";  onclick="UploadToHW()" >upload</button>      
    <button type="button" class="closeul" id="closeul";  onclick="showedit(2)" >CLOSE</button>  
    <button type="button" class="labelul"  id="labelul"></button>      
    <button type="button" class="about" onclick="Aboutpopup()" id="about">About</button>   
</div>

<div class="sidebar">
    <div class="scaled-content">
      <div class="textw" id="textw"></div>
      <div class="container" id="piccont">
      <div id="SHOWSVG"></div>
      </div>      
      <div class="container" id="hintscont">
      <div id="HINTS"></div>               
      </div>   
    </div>    
</div>

<!-- Page Content -->
<div class="content">                                     
  <div class="container" id="tablecont">              
  <div id="plcsvgmain"></div> 
  </div><!--end of tablecont-->         
  <div id="popup-overlay" class="overlay"></div>
  <div class="popup" id="popup"></div>                  
</div><!--end of content-->        
<!-- Bottom Bar -->
<div class="bottombar">   
    <button type="button" class="clock" onclick="changeframe(0)">Clock</button>
    <!--button type="button" class="bqrcode" onclick="changeframe(1)">QRcode</button-->    
    <button type="button" class="botmqtt" onclick="changeframe(2)">Mqtt</button>
    <button type="button" class="botphone" onclick="changeframe(3)">Phone</button>
    <button type="button" class="botfile" onclick="changeframe(4)">File</button>    
    <button type="button" class="EDIT" id="EDIT";  onclick="showedit(0)" >EDIT</button>  
</div>
<dialog id="dialog">     
</body>
</html>


<script>
//var tryonline=0;
var systemtype=1;
//var URL="192.168.1.84:8088";
var URL=window.location.host; 
var Showtable = "";
var divc1 = document.getElementById('piccont'); 
var divc2 = document.getElementById('tablecont'); 
divc1.addEventListener('contextmenu', (e) => {e.preventDefault()});   
divc2.addEventListener("contextmenu", (e) => {e.preventDefault()});   
window.onload = async function(){         
  CheckHWStatus('MCC');
  Sceret=1;  //bypass login
  ////////////////
  updatacell();  
  try
    {serialcelldata=JSON.parse(localStorage.getItem('plcdata')); 
    }
  catch
    {serialcelldata = Array(1920).fill("");  
    }  
  if (localStorage.getItem('plcdata')=== null)  
    serialcelldata = Array(1920).fill("");      
  updatetable(FILLALL);  
  //var w = window.innerWidth;
  var h = window.innerHeight;
  document.getElementById('SHOWSVG').innerHTML=svgdata;
  document.getElementById('HINTS').innerHTML=svghints[0];
  document.getElementById('hintscont').style.height=h-520+'px'; 
  //CheckHWStatus();
  document.getElementById('textw').innerHTML="Pick one to place";
  showedit(1); //close edit bar
}  

var dailog=document.getElementById("dialog"); 
function openModal(htmltext) { 
    document.getElementById("dialog").innerHTML="<br><button onclick='closeModal()' class='bothelp'>Close</button><br><br>"+htmltext; 
    dailog.showModal();
} 

function closeModal() { 
    dailog.close(); 
}    

function showedit(x)
{if(x===1 || x===2)
  {if(x===2)
    document.getElementById('closeul').style.visibility='hidden'
    //updatacell();  
  if (localStorage.getItem('plcdata') != null)
    {serialcelldata=JSON.parse(localStorage.getItem('plcdata')); 
    //addtext();
    }
  else  
    serialcelldata = Array(1920).fill("");    
  if(localStorage.getItem('refreshpage') === "required")
    {localStorage.setItem('refreshpage',"notneed");
    UploadToHW();
    }
  }
  if(svgwidth===1030 || x===1)
    {svgwidth=962;
    document.getElementById('tablecont').style.width=974+'px';       
    }
  else
    {svgwidth=1030;
    document.getElementById('tablecont').style.width=1042+'px';   
    }
updatetable(FILLALL);  
}
</script>
)rawliteral";