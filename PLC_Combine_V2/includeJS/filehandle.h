static const char PROGMEM INDEX_HTML_filehandle[] = R"rawliteral(
<html>
<input type="file" id="myFile">
<hr>
<h3 class="col-lg-9">Load file in edit page, refresh require after loading</h3>    
<textarea style="width:500px;height: 200px" id="output"></textarea>
<button onclick="savetoedit() "class="btn btn-default">Replace the edit page file</button>
<meta charset="UTF-8"/>
<title>JavaScript: Save contents of text box to local file</title>
<link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css" rel="stylesheet" />
<!--link href="css/custom.css" rel="stylesheet" /-->
<style type="text/css">
body {
  background-color:rgb(128, 134, 128);
}
</style>
</head>
<body>
<div class="wrapper">
  <header>    
    <h3 class="col-lg-9">Save ladder code in edit page 1:</h3>        
    </div>
  </header>  
<textarea style="width:500px;height: 200px" id="values"></textarea>
  <a id="saveToFile" class="btn btn-default">Save to file</a>
  <button onclick="copytestarea()">Copy text</button>
  <h3 class="col-lg-9">Save ladder code in edit page:</h3>
</div>
</div>

<script src="http://code.jquery.com/jquery.js"></script>
<script>
function copytestarea() {
  var copyText = document.getElementById("values");
  copyText.select();
  try {
    document.execCommand('copy');
    } catch (err) {
    window.alert('Unable to copy to clipboard, please copy manually',err);
    }
  }

function savetoedit()
{var rplcdata=document.getElementById("output").value;
  console.log('upplcdata=',rplcdata);  
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
  //console.log('upptest=',test);
  //console.log('uppLength=',test.length);
  localStorage.setItem('plcdata',JSON.stringify(test));
  localStorage.setItem('refreshpage',"required");
}

window.onload = async function(){ 
  var test="";  
  var Length=0; 
  var  rplcdata=localStorage.getItem('plcdata');     
  console.log('rplcdata=',rplcdata);
  for(var t=0;t<rplcdata.length;t++)  //calculate length;
    {if((rplcdata[t]>='/' && rplcdata[t]<='~' && rplcdata[t]!=']' && rplcdata[t]!='[')|| rplcdata[t]===' ')
      {//console.log('print=',rplcdata[t]);                  
      Length=t;      
      if(rplcdata[t]==='n')   //if = null reduce length
        {if(rplcdata[t+1]==='u' && rplcdata[t+2]==='l' && rplcdata[t+3]==='l')      
          {for(let J=t;J>0;J--)
              {if(rplcdata[J]>'0' && rplcdata[J]<='~')
                {Length=J;
                break;               
                }
              }
          break;
          }
        }
      }           
    } 
  //console.log("Length=",Length);   
  //console.log("rplcdata=",rplcdata);   
  for(var t=0;t<Length+3;t++)
    {if(rplcdata[t]===' ') 
      test=test+'_';
    else if(rplcdata[t]>='0' && rplcdata[t]<='~' && rplcdata[t]!=']' && rplcdata[t]!='[')
      {//console.log('print=',rplcdata[t]);
      test=test+rplcdata[t]; 
      }      
    else if(rplcdata[t]===',')
      test=test+',';  
    }    
  if(rplcdata!=null)
    {//document.getElementById("values").innerText=rplcdata;
    document.getElementById("values").innerText=test;
    console.log('doplcdata=',test);
    }
  //else
  //  document.getElementById("dtarea").innerText="No data";  
}
var input = document.getElementById("myFile");
var output = document.getElementById("output");

input.addEventListener("change", function () {
  if (this.files && this.files[0]) {
    var myFile = this.files[0];
    var reader = new FileReader();
    reader.addEventListener('load', function (e) {
      output.textContent = e.target.result;
    });
    reader.readAsBinaryString(myFile);
  }
});
$(function() {
  $('#saveToFile').click(function(e) {        
    var data = document.getElementById('values').value;   
    console.log('txdata=',data);
    var data = 'data:application/txt;charset=utf-8,' + encodeURIComponent(data);
    var el = e.currentTarget;
    el.href = data;
    el.target = '_blank';
    el.download = 'plcdata.txt';
  });
});
///////////////////////////////////////////////////////////////////////
</script>
</body>
</html>
)rawliteral";