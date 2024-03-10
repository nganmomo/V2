static const char PROGMEM INDEX_HTML_mobile[] = R"rawliteral(  
<!DOCTYPE html>
<body>
<div id=mobilekey></div>
</body>
<script>
let mxsetdev=6;
let mysetdev=8;

//var rowtext = Array.from(Array(mxsetdev), () => new Array(mysetdev)); 
var rowtext = Array.from(Array(6), () => new Array(8)); 
var mcell = new Array(48);
 
function Uploadremotekey()
{var txdata="keys";
var xhtp = new XMLHttpRequest(); 
xhtp.onreadystatechange = function() {
  if (this.readyState == 4 && this.status == 200) {                                    
      if(this.responseText==="keys")        
        window.alert("Upload successful");
      }         
  }  
for(var t=7;t<55;t++)
  {var ktext;
  ktext=document.getElementById('rmtt'+t).value;  
  txdata=txdata+ktext+"@";
  }
let txdata1="*^^"+document.getElementById('mqtopic').value+'@';
let txdata2="*$^"+mxsetdev+mysetdev+'@';    
let txdata3="*^*"+document.getElementById('phpw').value+'@';  
//let txdata4="*$*"+document.getElementById('editpw').value+'@';  
txdata=txdata+txdata1+txdata2+txdata3;//+txdata4;
length= txdata.length; 
if(length<350)
  {xhtp.open("GET","http://"+URL+"/action?go=" + txdata, true);   
  xhtp.send();  
  } 
}


function copyToClipboard() {
    // Get the textarea element
    var textarea = document.getElementById("mqtopic");

    // Select the text in the textarea
    textarea.select();
    textarea.setSelectionRange(0, 99999); // For mobile devices

    // Copy the selected text to the clipboard
    document.execCommand("copy");

    // Deselect the text
    textarea.setSelectionRange(0, 0);
}
//////////////////////////////////////////
function toggleCheckbox() {
  var xhr = new XMLHttpRequest();
  var keyv=""; 
  var k=7;
xhr.onreadystatechange = function() {
  if (this.readyState == 4 && this.status == 200) {     
    if(this.responseText[3]=='R')
      {let j=0;
      for(j=4;j<this.responseText.length;j++)
        {if(this.responseText[j]=='@' && k<55)// && this.responseText[j+2]=='%')
          {document.getElementById('rmtt'+k).value=keyv;               
          k++;
          keyv="";                 
          }   
        else    
          keyv=keyv+this.responseText[j];        
        //password                           
        if(this.responseText[j]==='*' && this.responseText[j+1]==='^' && this.responseText[j+2]==='^')  
          {let phpval="";
          for(let t=3;t<35;t++)
              {phpval=phpval+this.responseText[j+t];
              if(this.responseText[j+t]==='@')
                break;
              }
          document.getElementById('mqtopic').value=phpval;  
          localStorage.setItem('stmqtopic',phpval);                       
          }       
        if(this.responseText[j]==='*' && this.responseText[j+1]==='$' && this.responseText[j+2]==='^')  
          {mxsetdev=this.responseText[j+3];
          mysetdev=this.responseText[j+4];                    
          updaterowscols(1);              
          }         
        if(this.responseText[j]==='*' && this.responseText[j+1]==='^' && this.responseText[j+2]==='*')  
          {let phpval="";
          for(let t=3;t<11;t++)
              {phpval=phpval+this.responseText[j+t];
              if(this.responseText[j+t]==='@')
                break;
              }
          document.getElementById('phpw').value=phpval;   
          localStorage.setItem('stmpwapw',phpval);           
          }
        if(this.responseText[j]==='*' && this.responseText[j+1]==='$' && this.responseText[j+2]==='*')  
          {let phpval="";
          for(let t=3;t<11;t++)
              {phpval=phpval+this.responseText[j+t];
              if(this.responseText[j+t]==='@')
                break;
              }
          //document.getElementById('editpw').value=phpval;                        
          break;
          }                           
        }   
      }
    if(this.responseText[3]=='o')
      {
      document.getElementById('disp').value=this.responseText[4]+this.responseText[5]; 
      }  
    } 
  }  
xhr.open("GET","http://"+URL+"/action?go=keyw", true); //
xhr.send();
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

function GererateRC(type)
{if(type===1)
document.getElementById('phpw').value=makeid(8);
//if(type===2)
//document.getElementById('editpw').value=makeid(8);
if(type===3)
document.getElementById('mqtopic').value=makeid(32);
}


///////////////////////////////////////////////////////
function loaddefaultA()
{//loadkeytable2();
for(var t=1;t<=8;t++)
  {for(var j=1;j<=6;j++)
    {if(j<6)
        document.getElementById('rmtt'+(j+t*6)).value=t;   
      else  
        document.getElementById('rmtt'+(j+t*6)).value=100;              
    }
  } 
document.getElementById('phpw').value="1a2b3c4d"; 
//document.getElementById('editpw').value="a1b2c3d4"; 
document.getElementById('mqtopic').value="O0hVYjnHmd6yOLJQWrSrykhAY3CzpE33";                       
}

function loaddefaultB()
{//loadkeytable2();
for(var t=1;t<=8;t++)
  {for(var j=1;j<=6;j++)
    {
      if(j<6)
        document.getElementById('rmtt'+(j+t*6)).value=(t)*10000;   
      else  
        document.getElementById('rmtt'+(j+t*6)).value=100;   
    }
  }  
document.getElementById('phpw').value="30f5C7zR"; 
//document.getElementById('editpw').value="6FfeAq4a"; 
document.getElementById('mqtopic').value="nOFbQgD9gNQ5KkCbp8sewbZzVbuD8oWq";          
}


function loadkeytable1(){             
  for(let y=0;y<mysetdev;y++)  
    {var row = document.getElementById('myDRow'+y.toString());   
    for(var t=0;t<mxsetdev;t++)
      row.deleteCell(0);      
    }  
  loadkeytable();  
  }  

function loadkeytable(){ 
  loadkeytable2();  
  //toggleCheckbox(999);      
}

function updaterowscols(set)
{
  for(let y=1;y<=8;y++)
    {for(let x=1;x<=6;x++)
      {let L=x+(y*6);
      document.getElementById('rmtt'+L).style.backgroundColor="#eAe7e6";
      }
    }
  if(set===1)
  {document.getElementById('rows').value=mysetdev;
  document.getElementById('cols').value=mxsetdev;
  }
  else
  {mysetdev=document.getElementById('rows').value;
  mxsetdev=document.getElementById('cols').value;
  }
  for(let y=1;y<=mysetdev;y++)
    {for(let x=1;x<=mxsetdev;x++)
      {let L=x+(y*6);
      document.getElementById('rmtt'+L).style.backgroundColor="#979797";
      }
    }
}



function loadkeytable2(){    
  for(let k=0;k<mysetdev;k++)   
    {   t=k+1;
        rowtext[0][k] = "<td><label>A"+t+"</label><input class='rmtt' id='rmtt"+(1+t*mxsetdev)+"' maxlength='5' type='text' value='"+mcell[1+t*mxsetdev]+"' style='width:50px;height:22px;'></td>"
        rowtext[1][k] = "<td><label>B"+t+"</label><input class='rmtt' id='rmtt"+(2+t*mxsetdev)+"' maxlength='5' type='text' value='"+mcell[2+t*mxsetdev]+"' style='width:50px'height:25px;'></td>"  
        rowtext[2][k] = "<td><label>C"+t+"</label><input class='rmtt' id='rmtt"+(3+t*mxsetdev)+"' maxlength='5' type='text' value='"+mcell[3+t*mxsetdev]+"' style='width:50px'height:25px;'></td>"             
        rowtext[3][k] = "<td><label>D"+t+"</label><input class='rmtt' id='rmtt"+(4+t*mxsetdev)+"' maxlength='5' type='text' value='"+mcell[4+t*mxsetdev]+"' style='width:50px;height:22px;'></td>"
        rowtext[4][k] = "<td><label>E"+t+"</label><input class='rmtt' id='rmtt"+(5+t*mxsetdev)+"' maxlength='5' type='text' value='"+mcell[5+t*mxsetdev]+"' style='width:50px'height:25px;'></td>"         
        rowtext[5][k] = "<td><label>F"+t+"</label><input class='rmtt' id='rmtt"+(6+t*mxsetdev)+"' maxlength='5' type='text' value='"+mcell[6+t*mxsetdev]+"' style='width:50px'height:25px;'></td>"   
    }     
  for(let j=0;j<mysetdev;j++)  
      {row = document.getElementById('myDRow'+j.toString());         
      for(let k=0;k<mxsetdev;k++)
        {x0 = row.insertCell(k);        
        x0.innerHTML = rowtext[k][j];  //        
        }
      /*
      x0 = row.insertCell(0);  
      x1 = row.insertCell(1); 
      x2 = row.insertCell(2);   
      x3 = row.insertCell(3);  
      x4 = row.insertCell(4);   
      x5 = row.insertCell(5);   
      x0.innerHTML = rowtext[0][j];  //
      x1.innerHTML = rowtext[1][j];  //   
      x2.innerHTML = rowtext[2][j];  //    
      x3.innerHTML = rowtext[3][j];  //
      x4.innerHTML = rowtext[4][j];  //     
      x5.innerHTML = rowtext[5][j];  //     
      */
      }          
      toggleCheckbox(999);      
}


var mobilekey=
"<h3>Step 1:Set lock switch in unlock position</h3>\
<h3>Step 2 : Input keypad character, row and column number</h3>\
<h3>and than edit the necessory value, press upload when done</h3>\
<table class='devtable'><tbody>\
<tr id='myDRow0'></tr><tr id='myDRow1'></tr><tr id='myDRow2'></tr><tr id='myDRow3'>\
</tr><tr id='myDRow4'></tr><tr id='myDRow5'></tr><tr id='myDRow6'></tr><tr id='myDRow7'></tr>\
</tbody></table><br>\
<label for='rows' >Select the number of rows:</label>\
  <select id='rows' name='cols' onchange='updaterowscols(0)'>\
    <option value='1'>1</option>\
    <option value='2'>2</option>\
    <option value='3'>3</option>\
    <option value='4'>4</option>\
    <option value='5'>5</option>\
    <option value='6'>6</option>\
    <option value='7'>7</option>\
    <option value='8' selected>8</option>\
  </select>\
  <label for='cols' style='margin-left:100px'>Select the number of columns:</label>\
  <select id='cols' name='cols' onchange='updaterowscols(0)'>\
    <option value='1'>1</option>\
    <option value='2'>2</option>\
    <option value='3'>3</option>\
    <option value='4'>4</option>\
    <option value='5'selected>5</option>\
  </select><br><br>\
<button type='button' class='mkey' onclick='loadkeytable1()' style='margin-left:50px'>Refresh or cancel input</button>\
<button type='button' class='mkey' onclick='loaddefaultA()' style='margin-left:50px'>Load default A</button>\
<button type='button' class='mkey' onclick='loaddefaultB()' style='margin-left:50px'>Load default B</button>\
<h4>Setup password for phone control, any 8 character</h4>\
<input class='rmtt' id='phpw' maxlength='8' type='text' value='1A3B5C7D' style='width:150px;height:22px;margin-left:120px'></td>\
<button type='button' id='grc' onclick='GererateRC(1)' style='margin-left:10px'>***Gererate random code</button>\
<button type='button' id='grc' onclick='GererateRC(2)' style='margin-left:10px'>***Gererate random code</button>\
<h4>Setup random topic for mqtt, any 32 character</h4><button onclick='copyToClipboard()' style='margin-left:150px'>Copy to Clipboard</button><br><br>\
<input class='rmtt' id='mqtopic' maxlength='32' type='text' value='1A3B5C7D' style='width:250px;height:22px;margin-left:20px'></td>\
<button type='button' id='grc' onclick='GererateRC(3)' style='margin-left:10px'>***Gererate random code</button>\
<button type='button' class='mkey' onclick='Uploadremotekey()' style='margin-left:50px'>Upload setup</button><br>\
<h3>Step 3: Assign the function of each key in the EDITPAGE</h3>\
<h3>Step 4: Use he link below, Scan the QR code below, create a PWA app in phone.</h3>"

window.onload = async function(){         
  //URL="192.168.1.95:8088";
  URL=window.location.host;  
  console.log(URL);
  console.log('11ter',mcell);  
  document.getElementById('mobilekey').innerHTML=mobilekey;     
  loadkeytable(); 
}
</script>
<style>
body
{
margin-left: 50px;
}  
.rmtt
{height: 25px;
background-color: beige;
text-align: center;
}
.qr
{
  margin-left: 100px;
}
</style>
</html>  
)rawliteral";
