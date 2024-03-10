static const char PROGMEM INDEX_HTML_Property[] = R"rawliteral(
var Savefordelect = Array(30).fill("");   
var Mqttsetup = Array.from(Array(4), () => new Array(6).fill("")); 
//Convert serialcelldata to svgtext//
function addtext() 
{gettimeclock();
var cellw=160; //block witdth
var cellh=80;  //block height  
//Mqttsetup=JSON.parse(localStorage.getItem('systcell')); 
if(mqupdate===1)
  {mqupdate=0;
  downloadsetup('MQSD',Mqttsetup);
  }
svgtext=""; 
 //console.log('4=',serialcelldata);
  //serialcelldata[0]=47;     //add handle color//
  {let tcolor="' fill='rgb(255,255,255)'>";
  for(let yb=0;yb<ycount;yb++)   //order
    {for(let xa=0;xa<xcount;xa++) 
      {//if(xa===6)  continue;
      let type=serialcelldata[yb*48+xa*8];  
      let pin=serialcelldata[yb*48+xa*8+1]>>8;  
      for(let zc=0;zc<=zcount;zc++)   
        {let x=serialcelldata[zc+xa*8+yb*48]>>8;
        let y=serialcelldata[zc+xa*8+yb*48]&255; //lower 8 bit       //1  
        if(serialcelldata[zc+xa*8+yb*48]!="")
          {let yp=[0,12,30,40,48,75,60,48];
          let xp1=[0,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,19,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,20,18,18,18,18,35,18,18,18,18,35,35,18,18,18,18,20,38,30,18,18,18,18,18,18,18,18];   
          let xp2=[0,20,20,20,20,20,20,20,20,20,10,20,20,20,20,20,20,20,20,19,20,20,20,35,40,40,35,40,40,40,40,20,20,40,40,40,40,35,35,35,43,33,33,40,20,35,35,35,33,20,35,20,20,20,20,35,35,20,20,20,35,40,20,20,20,20,20,20,20,20,20,10];  
          //t xp2=[0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10, 1, 2, 3, 4, 5, 6, 7, 8, 9,20, 1, 2, 3, 4, 5, 6, 7, 8, 9,30, 1, 2, 3, 4, 5, 6, 7, 8, 9,40, 1, 2, 3, 4, 5, 6, 7, 8, 9,50, 1, 2, 3, 4, 5, 6, 7, 8, 9,60, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
          let xp4=[0,20,20,20,20,20,20,20,20,20,10,20,20,20,20,20,20,20,20,19,20,20,20, 5,20,20,20,20,20,20,30,30,30,30,30,20,35,35,35,25,20,33,33,20,38,20,35,35,20,20,40,50,20,20,20,20,20,20,20,20, 5,40,20,20,20,20,20,20,20,20,30,10];  
          let xp5=[0,20,20,20,20,20,20,20,20,20,10,20,20,20,20,20,20,20,20,19,20,20,20,35,20,20,20,20,20,20,30,20,20,20,20,20,20,20,20,20,40,20,20,20,20,20,20,20,20,20,50,20,20,20,20,20,20,20,20,20, 5,61,20,20,20,20,20,20,20,20,20,10];       
          if(zc===1 || zc===2)  //text 1 2 required code convert ???
            {if(zc==1)
              {let itext="<text x='"+(xa*cellw+xp1[type])+"' y='";
              if(type===62)
                {svgtext=svgtext+itext+(yb*cellh+yp[zc])+tcolor+lookup1table[y]+x+"</text>"   
                for(let t=0;t<16;t++)
                  {if(pin===parseInt(clkid[t]))
                    {svgtext=svgtext+itext+(yb*cellh+25)+tcolor+setbt[pin-1]+"</text>"
                    svgtext=svgtext+itext+(yb*cellh+38)+tcolor+setbd[pin-1]+"</text>"
                    svgtext=svgtext+itext+(yb*cellh+51)+tcolor+setet[pin-1]+"</text>"
                    svgtext=svgtext+itext+(yb*cellh+64)+tcolor+seted[pin-1]+"</text>"
                    }
                  }
                } 
              else
                {//if(type===45)
                //  {svgtext=svgtext+"<text x='"+(xa*cellw+xp2[type])+"' y='"+(yb*cellh+yp[2])+tcolor+Mqttsetup[0][1]+"</text>"  
                //  svgtext=svgtext+itext+(yb*cellh+yp[zc])+tcolor+lookup1table[y]+x+"</text>" 
                //  }
                //else ????
                if(type===50 || type===55)
                  svgtext=svgtext+itext+(yb*cellh+yp[zc])+tcolor+phonecol[x]+"</text>"; 
                else
                  svgtext=svgtext+itext+(yb*cellh+yp[zc])+tcolor+lookup1table[y]+x+"</text>"    
                }
              }                                       
            if(zc===2)
                {let svgt=svgtext+"<text x='"+(xa*cellw+xp2[type])+"' y='"+(yb*cellh+yp[zc])+tcolor;
                  switch(type) //if(type===48)
                  {case 26:                              
                    svgtext=svgt+svgtext+serialcelldata[zc+xa*8+yb*48]+"</text>"; 
                    break;    
                  case 40:   
                  case 41:
                  case 42:                                          
                    svgtext=svgt+svgtext+y+"</text>"; 
                    break;
                  //case 43:                                          
                    //svgtext=svgt+x+"</text>";   
                    //break;                         
                  case 44:  
                  case 45:                              
                    svgtext=svgt+Mqttsetup[0][x+1]+"</text>"; 
                    break;                    
                  case 46:
                    svgtext=svgt+UserDefIn[x]+"</text>"
                    break;
                  case 47:
                    svgtext=svgt+UserDefIn[x]+"</text>"
                    break;                  
                  case 51:
                  case 52:
                  case 53:
                  case 54:
                    svgtext=svgt+phonecol[x]+"</text>";                          
                    break;
                  case 50:
                  case 55:
                    svgtext=svgt+phonerow[x]+"</text>"
                    break;  
                  case 37:
                    svgtext=svgt+timerdelaytype[x]+"</text>"
                    break;
                  case 48:
                    svgtext=svgt+AMathlookup[x]+"</text>"
                    break;  
                  case 38:                    
                    svgtext=svgt+Countlookup[x]+"</text>"
                    break;                                                                                                                      
                  case 60:
                    svgtext=svgt+RTimerlookup[x]+"</text>" //repeat timer
                    break;
                  default:         
                    svgtext=svgt+lookup2table[type]+x+"</text>"; 
                    break;     
                  }
                }
              }              
          if(zc===4 || zc===5 || zc===6 || zc===7)   
            {let y16=serialcelldata[zc+xa*8+yb*48];
            if(type===50)  
              {if(zc===6)
                svgtext=svgtext+"<text x='"+(xa*cellw+xp2[2])+"' y='"+(yb*cellh+yp[2])+tcolor+x+"</text>";   
              if(zc===4)
                svgtext=svgtext+"<text x='"+(xa*cellw+xp4[type])+"' y='"+(yb*cellh+yp[zc])+tcolor+phoneworkmode[x]+"</text>";   
              }          
            else
              {if(type===23) 
                svgtext=svgtext+"<text x='"+(xa*cellw+xp4[type])+"' y='"+(yb*cellh+yp[6])+tcolor+outtype[x]+"</text>"; 
              else if(type===46 || type===47 || type===61)
                svgtext=svgtext+"<text x='"+(xa*cellw+xp4[type])+"' y='"+(yb*cellh+yp[4])+tcolor+y16+"</text>";    //MODtype[x]+"</text>";      
              else if(type===60)
                svgtext=svgtext+"<text x='"+(xa*cellw+xp4[type])+"' y='"+(yb*cellh+yp[6])+tcolor+y16+"</text>";            
              else if(type===38 || type===41 || type===42)
                svgtext=svgtext+"<text x='"+(xa*cellw+xp4[type])+"' y='"+(yb*cellh+yp[4])+tcolor+y16+"</text>";    
              else  
              {if(zc===4) 
                svgtext=svgtext+"<text x='"+(xa*cellw+xp4[type])+"' y='"+(yb*cellh+yp[zc])+tcolor+x+"</text>";               
              else
                svgtext=svgtext+"<text x='"+(xa*cellw+xp5[type])+"' y='"+(yb*cellh+yp[zc])+tcolor+x+"</text>";    
              }
              }  
            }
          }
        }  
      }
    }
  } 
}

var clkid=Array(17).fill("");
var setbt=Array(17).fill("");
var setet=Array(17).fill("");
var setbd=Array(17).fill("");
var seted=Array(17).fill("");
var cycle=Array(17).fill("");

function gettimeclock()
{let tc=0;
let td=0;  
const Today = new Date();
const dd = String(Today.getDate()).padStart(2, '0');
const mm = String(Today.getMonth() + 1).padStart(2, '0'); //January is 0 so we need to add 1
const yyyy = Today.getFullYear();
//const utcHour = Today.getUTCHours();
//const localHour = Today.getHours();  
const formattedDate = yyyy+'-'+mm+'-'+dd;
const formattedTime = Today.toLocaleTimeString('en-US', { hour12: false });
//var D1=  new Date();
//var D2=  new Date();  
//const currentDate = new Date();
//const currentTime = new Date();  
//const formattedDate = currentDate.toISOString().split('T')[0];
//const formattedTime = currentTime.toLocaleTimeString('en-US',{ hour12: false });  
for(y=4;y<timedata.length;y++)
  {if(timedata[y]=='*')
    {clkid[tc]=timedata[y+1];   
    setbt[tc]=timedata[y+2]+timedata[y+3]+':'+timedata[y+4]+timedata[y+5]+':'+timedata[y+6]+timedata[y+7];      
    setet[tc]=timedata[y+8]+timedata[y+9]+':'+timedata[y+10]+timedata[y+11]+':'+timedata[y+12]+timedata[y+13];       
    setbd[tc]=20+timedata[y+14]+timedata[y+15]+'-'+timedata[y+16]+timedata[y+17]+'-'+timedata[y+18]+timedata[y+19];
    seted[tc]=20+timedata[y+20]+timedata[y+21]+'-'+timedata[y+22]+timedata[y+23]+'-'+timedata[y+24]+timedata[y+25];    
    cycle[tc]=timedata[y+26];        
    if(formattedDate>seted[tc])  //take out pass date
        clkid[tc]='0';
    else  
        {if(formattedTime>setet[tc])
          clkid[tc]='0';    
        }  
    if(tc++>=16)       break;
    }
  }  
  //ordering
  for(tc=0;tc<16;tc++)
    {for(td=tc+1;td<16;td++)
      {if(clkid[tc]!=0 && clkid[td]!=0 && setbd[tc]>=setbd[td] && setbt[tc]>setbt[td])
        {clkid[16]=clkid[tc]; setbt[16]=setbt[tc]; setet[16]=setet[tc]; setbd[16]=setbd[tc]; seted[16]=seted[tc]; cycle[16]=cycle[tc]; 
        clkid[tc]=clkid[td]; setbt[tc]=setbt[td]; setet[tc]=setet[td]; setbd[tc]=setbd[td]; seted[tc]=seted[td]; cycle[tc]=cycle[td];
        clkid[td]=clkid[16]; setbt[td]=setbt[16]; setet[td]=setet[16]; setbd[td]=setbd[16]; seted[td]=seted[16]; cycle[td]=cycle[16];
        }
      }  
    } 
}


function clearfile()
{
  Acstatus="";  
  statbuf=""; 
  svgtext=""; 
  svgdata0="";
  svgdata3="";
  svgSimSign="";
  serialcelldata = Array(1920).fill("");    //480  fine end point
  DeviceState = Array(240).fill("");         //60     
  updatetable(FILLALL);
}
  var selectend="</select><br>";   
  var RTimerlookup=['ks','ks','sec','ms'];
  var outtype=['Non invert','Non invert','Invert','Active ON-Front','Active ON Rear','Active OFF-Front','Active OFF-Rear'];
  var MODtype=['MOD1','MOD2','MOD3','MOD4','MOD5','MOD6','MOD7','MOD8'];  
  var Countlookup=['Active ON slow','Active ON slow','Active ON fast','Active OFF slow','Active OFF fast','rise pulse slow','rise pulse fast'];
  var timerdelaytype=['Active OFF sec','Active OFF sec','Active OFF ms','Active ON sec','Active ON ms','Delay Active OFF sec','Delay Active OFF ms','Delay Active ON sec','Delay Active ON ms','Delay Pulse sec','Delay Pulse ms']; 
  var UserDefIn=['Digital','Analog','Mem16','Mem32','Mem64'];
  var AMathlookup=['ASW-N','ASW-N','ASW-R','A+B','A-B','B-A','AxB','A/B','B/A'];
  var phonecol=['A','A','B','C','D','E'];
  var phonerow=['1','1','2','3','4','5','6','7','8'];
  var phoneworkmode=['ON/OFF','ON/OFF','PULSE','VALUE'];
  var lookup1table=['0','1','2','3','4','5','6','7','8','9','10','1','2','3','4','5','6','7','8','9','20',
    '1','2',"Link ","Aout","Ain","CON","Din","Din","Din","Din","Din","Din","Din","Din","Din","Din","Timer",
    "Counter","RSFF ","DAC","ADC","CMP","Pin","MqttTx","MqttRx","UserTx","UserRx","Math","","COL","51","52","53","54","COL","","57","58","59","RTimer ","","Clock "];
  var lookup2table=['0','1','2','3','4','5','6','7','8','9','10','1','2','3','4','5','6','7','8','9','20',
    '1','','RLY','','','val','Return','','','','','','','','','','Mode/Unit','Mode','0=Forever(sec)',
    'Step','Ref','L-H:','','To-Topic','RxTopic','TYPE','TYPE','Mode','Mode','ROW','Row','52','53','54','ROW','Mode','57','58','59','Unit','','activated'];
  var lookup4table=['0','1','2','3','4','5','6','7','8','9','10','1','2','3','4','5','6','7','8','9','20',
    '1','2','Link Type','4','5','6','7','8','9','30','1','2','3','4','5','6','Time Set','Clock set','0=Forever(sec)',
    'Offset','H-L','H-L','43','MqttRx','RxType','Modbus Address','Modbus Address','value','if<','TYPE','','','','','55','','','','59','Time Set','Call'];
  var lookup6table=['0','1','2','3','4','5','6','7','8','9','10','1','2','3','4','5','6','7','8','9','20',
    '1','2','ModeB','4','5','6','7','8','9','30','1','2','3','4','5','6','Time Set(Sec)','Clock set','0=Forever(sec)','40','LOW','LOW','3','Topic','Topic','6','7','Value','Echo','10']; 
  var sdata="";  

  function openPopup(Type,xx,yy) {         
    mouseleftallow=0;
    var type=Type;    
    if(type!="")    
    {var iddlookup=[0,256,512,768,1024,1280,1536,1792,2048];    
    var id1type=0;
    if(serialcelldata[yy*48+xx*8+1]>>8===0)
      id1type=(lookup1table[type]+1).toString(); //load previous data 
    else
      id1type=lookup1table[type]+(serialcelldata[yy*48+xx*8+1]>>8).toString(); //load previous data 
    var id2type=lookup2table[type]+(serialcelldata[yy*48+xx*8+2]>>8).toString();
      if((serialcelldata[yy*48+xx*8+2]>>8)===0)
    id2type=(lookup2table[type]+1).toString();      
    var id1num=iddlookup[serialcelldata[yy*48+xx*8+1]>>8]+type;//this is string add
    var id2num=iddlookup[serialcelldata[yy*48+xx*8+2]>>8]+type;//see iddlookup
    var id4num=iddlookup[serialcelldata[yy*48+xx*8+4]>>8]+type;//see iddlookup
    var id4type=outtype[serialcelldata[yy*48+xx*8+4]>>8]; 
    var id4MOD=MODtype[serialcelldata[yy*48+xx*8+4]>>8]; 
    //if(type===45 && id2num<256) id2num=256+type; ????
    var id1numnotype=serialcelldata[yy*48+xx*8+1]>>8;
    var id2numnotype=serialcelldata[yy*48+xx*8+2]>>8;
    var id4numnotype=serialcelldata[yy*48+xx*8+4]>>8;
    var id2fig=(serialcelldata[yy*48+xx*8+2]>>8)+1;
    //id2fig=id2fig;
    if(id2fig>5 || id2fig<2)  id2fig=2;
    //console.log('id2figA',id2fig);
    var valset2=serialcelldata[yy*48+xx*8+2];
    var valset4=serialcelldata[yy*48+xx*8+4];
    var valset5=serialcelldata[yy*48+xx*8+5];   //comment
    var valset6=serialcelldata[yy*48+xx*8+6];   //payload
    var valset7=serialcelldata[yy*48+xx*8+7];   //topic
    //var popup = document.getElementById('popup-overlay');         
    //******************************************************/    
    var digitalinputpin=8;        //input output use this veriable ana analog
    var analoginputpin=4;        //input output use this veriable ana analog
    //******************************************************/ 
    var selecttable2_14=  
      "<label>Id:</label>\
      <option value='"+(256+type)+"'>"+lookup2table[type]+"1</option>\
      <option value='"+(512+type)+"'>"+lookup2table[type]+"2</option>\
      <option value='"+(768+type)+"'>"+lookup2table[type]+"3</option>\
      <option value='"+(1024+type)+"'>"+lookup2table[type]+"4</option>"
    var selecttable2_58=            
      "<option value='"+(1280+type)+"'>"+lookup2table[type]+"5</option>\
      <option value='"+(1536+type)+"'>"+lookup2table[type]+"6</option>\
      <option value='"+(1792+type)+"'>"+lookup2table[type]+"7</option>\
      <option value='"+(2048+type)+"'>"+lookup2table[type]+"8</option>"                 
    
    var selecttable1_14=  
      "<label>Id:</label>\
      <option value='"+(256+type)+"'>"+lookup1table[type]+"1</option>\
      <option value='"+(512+type)+"'>"+lookup1table[type]+"2</option>\
      <option value='"+(768+type)+"'>"+lookup1table[type]+"3</option>\
      <option value='"+(1024+type)+"'>"+lookup1table[type]+"4</option>"
    var selecttable1_58=            
      "<option value='"+(1280+type)+"'>"+lookup1table[type]+"5</option>\
      <option value='"+(1536+type)+"'>"+lookup1table[type]+"6</option>\
      <option value='"+(1792+type)+"'>"+lookup1table[type]+"7</option>\
      <option value='"+(2048+type)+"'>"+lookup1table[type]+"8</option>"               
    
    var selecttable1="";
    if(digitalinputpin===4)
      selecttable1=selecttable1_14;
    if(digitalinputpin===8)
      selecttable1=selecttable1_14+selecttable1_58;          
      
    var selecttable2="";
    if(analoginputpin===4)
      selecttable2=selecttable2_14;
    if(analoginputpin===8)
      selecttable2=selecttable2_14+selecttable2_58;                
    //******************************************************/ 
    var linkoutputtype=
      "<label>Id:</label>\
        <option value='"+(256+type)+"'>"+outtype[1]+"</option>\
        <option value='"+(512+type)+"'>"+outtype[2]+"</option>\
        <option value='"+(768+type)+"'>"+outtype[3]+"</option>\
        <option value='"+(1024+type)+"'>"+outtype[4]+"</option>"      
    
    var linkMODtype=
        "<label>Id:</label>\
          <option value='"+(256+type)+"'>"+MODtype[1]+"</option>\
          <option value='"+(512+type)+"'>"+MODtype[2]+"</option>\
          <option value='"+(768+type)+"'>"+MODtype[3]+"</option>\
          <option value='"+(1024+type)+"'>"+MODtype[4]+"</option>"        
        

    var Unit=
    "<label>"+lookup2table[type]+":</label>\
    <select id='unit' value="+id2numnotype+">\
    <option value='"+id2num+"'>"+timerdelaytype[id2numnotype]+"</option>\
    <option value='"+(256+type)+"'>"+timerdelaytype[1]+"</option>\
    <option value='"+(512+type)+"'>"+timerdelaytype[2]+"</option>\
    <option value='"+(768+type)+"'>"+timerdelaytype[3]+"</option>\
    <option value='"+(1024+type)+"'>"+timerdelaytype[4]+"</option>\
    <option value='"+(1280+type)+"'>"+timerdelaytype[5]+"</option>\
    <option value='"+(1536+type)+"'>"+timerdelaytype[6]+"</option>\
    <option value='"+(1792+type)+"'>"+timerdelaytype[7]+"</option>\
    <option value='"+(2048+type)+"'>"+timerdelaytype[8]+"</option>\
    <option value='"+(2304+type)+"'>"+timerdelaytype[9]+"</option>\
    <option value='"+(2560+type)+"'>"+timerdelaytype[10]+"</option>\
    </select><br>"    
    
    var UserDefineOut=
    "<label>"+lookup2table[type]+":</label>\
    <select id='userdefine' value="+id2numnotype+">\
    <option value='"+id2num+"'>"+UserDefIn[id2numnotype]+"</option>\
    <option value='"+(256+type)+"'>"+UserDefIn[1]+"</option>\
    <option value='"+(512+type)+"'>"+UserDefIn[2]+"</option>\
    <option value='"+(768+type)+"'>"+UserDefIn[3]+"</option>\
    <option value='"+(1024+type)+"'>"+UserDefIn[4]+"</option>\
    </select><br>"    

    var UserDefineIn=UserDefineOut;
    
    var RTimer=
    "<label>"+lookup2table[type]+":</label>\
    <select id='rtimer' value="+id2numnotype+">\
    <option value='"+id2num+"'>"+RTimerlookup[id2numnotype]+"</option>\
    <option value='"+(256+type)+"'>"+RTimerlookup[1]+"</option>\
    <option value='"+(512+type)+"'>"+RTimerlookup[2]+"</option>\
    <option value='"+(768+type)+"'>"+RTimerlookup[3]+"</option>\
    </select><br>" 

    var AMath=
    "<select id='aMath' value="+id2numnotype+">\
    <option value='"+id2num+"'>"+AMathlookup[id2numnotype]+"</option>\
    <option value='"+(256+type)+"'>"+AMathlookup[1]+"</option>\
    <option value='"+(512+type)+"'>"+AMathlookup[2]+"</option>\
    <option value='"+(768+type)+"'>"+AMathlookup[3]+"</option>\
    <option value='"+(1024+type)+"'>"+AMathlookup[4]+"</option>\
    <option value='"+(1280+type)+"'>"+AMathlookup[5]+"</option>\
    <option value='"+(1536+type)+"'>"+AMathlookup[6]+"</option>\
    <option value='"+(1792+type)+"'>"+AMathlookup[7]+"</option>\
    <option value='"+(2048+type)+"'>"+AMathlookup[8]+"</option>\
    </select><br>" 

    var Count=
    "<label>"+lookup2table[type]+":</label>\
    <select id='count' value="+id2numnotype+">\
    <option value='"+id2num+"'>"+Countlookup[id2numnotype]+"</option>\
    <option value='"+(256+type)+"'>"+Countlookup[1]+"</option>\
    <option value='"+(512+type)+"'>"+Countlookup[2]+"</option>\
    <option value='"+(768+type)+"'>"+Countlookup[3]+"</option>\
    <option value='"+(1024+type)+"'>"+Countlookup[4]+"</option>\
    <option value='"+(1280+type)+"'>"+Countlookup[5]+"</option>\
    <option value='"+(1536+type)+"'>"+Countlookup[6]+"</option>\
    </select><br>" 
    
    var group=
    "<label>Group:</label>\
    <select id='group' value="+id2numnotype+">\
    <option value='"+id1num+"'>"+id2numnotype+"</option>\
    <option value='"+(256+type)+"'>1</option>\
    <option value='"+(512+type)+"'>2</option>\
    <option value='"+(768+type)+"'>3</option>\
    <option value='"+(1024+type)+"'>4</option>\
    <option value='"+(1280+type)+"'>5</option>\
    <option value='"+(1536+type)+"'>6</option>\
    <option value='"+(1792+type)+"'>7</option>\
    <option value='"+(2048+type)+"'>8</option>\
    </select><br>"  

    var phin=
    "<label>"+lookup4table[type]+":</label>\
    <select id='phin' value="+id4numnotype+">\
    <option value='"+id4num+"'>"+phoneworkmode[id4numnotype]+"</option>\
    <option value='"+(256+type)+"'>"+phoneworkmode[1]+"</option>\
    <option value='"+(512+type)+"'>"+phoneworkmode[2]+"</option>\
    <option value='"+(768+type)+"'>"+phoneworkmode[3]+"</option>\
    </select><br>"    
    
    var KeySel=
    "<label>"+lookup1table[type]+":</label>\
    <select id='KeySel' value="+id1numnotype+">\
    <option value='"+id1num+"'>"+phonecol[id1numnotype]+"</option>\
    <option value='"+(256+type)+"'>"+phonecol[1]+"</option>\
    <option value='"+(512+type)+"'>"+phonecol[2]+"</option>\
    <option value='"+(768+type)+"'>"+phonecol[3]+"</option>\
    <option value='"+(1024+type)+"'>"+phonecol[4]+"</option>\
    <option value='"+(1280+type)+"'>"+phonecol[5]+"</option>\
    </select><br>"  
              
    var Select4=
    "<label>"+lookup4table[type]+":</label>\
    <select id='outmode' value="+id4type+">\
    <option value='"+id4num+"'>"+id4type+"</option>"+linkoutputtype+selectend;   
    var Select2=
      "<label>"+lookup2table[type]+":</label>\
      <select id='linkst' value="+id2type+">\
      <option value='"+id2num+"'>"+id2type+"</option>"+selecttable2+selectend;   
    
    var SelectTopic=  //if id2fig=null setup required
      "<label>"+lookup2table[type]+":</label>\
      <select id='topicst' value="+Mqttsetup[0][id2fig]+">\
      <option value='"+id2num+"'>"+Mqttsetup[0][id2fig]+"</option>\
      <option value='"+(256+type)+"'>"+Mqttsetup[0][2]+"</option>\
      <option value='"+(512+type)+"'>"+Mqttsetup[0][3]+"</option>\
      <option value='"+(768+type)+"'>"+Mqttsetup[0][4]+"</option>\
      <option value='"+(1024+type)+"'>"+Mqttsetup[0][5]+"</option>\
      </select><br>"
    var OutputMode=  //if id2fig=null setup required
      "<label>"+lookup2table[type]+":</label>\
      <select id='OutMode' value="+id2fig+">\
      <option value='"+id2num+"'>"+(id2fig-1)+"</option>\
      <option value='"+(256+type)+"'>1</option>\
      <option value='"+(512+type)+"'>2</option>\
      <option value='"+(768+type)+"'>3</option>\
      <option value='"+(1024+type)+"'>4</option>\
      </select><br>"
    var commnest=  
      "<label>Comment:</label><br><input class='comst' type='text' maxlength='30' id='comst' style='width:140px' value="+valset5+"><br>"
    var phoneRowIn=  
      "<label>"+lookup2table[type]+"</label>\
      <select id='phoneRowIn' value="+id2numnotype+">\
      <option value='"+id2num+"'>"+phonerow[id2numnotype]+"</option>\
      <option value='"+(256+type)+"'>"+phonerow[1]+"</option>\
      <option value='"+(512+type)+"'>"+phonerow[2]+"</option>\
      <option value='"+(768+type)+"'>"+phonerow[3]+"</option>\
      <option value='"+(1024+type)+"'>"+phonerow[4]+"</option>\
      <option value='"+(1280+type)+"'>"+phonerow[5]+"</option>\
      <option value='"+(1536+type)+"'>"+phonerow[6]+"</option>\
      <option value='"+(1792+type)+"'>"+phonerow[7]+"</option>\
      <option value='"+(2048+type)+"'>"+phonerow[8]+"</option>\
      </select><br>"
    //var autoidstdigital="<select id='autoidstdigital' value='Auto'> 
    /////////////////////////////////  
    var autoidstdigital="<label>ID:</label><select id='autoidstdigital' value="+id1type+">\
    <option value='"+id1num+"'>Auto</option>selecttable1+selectend;"+selecttable1+selectend; 
    //change to selecttable1 from selecttable2
    var autoidstanalog="<label>ID:</label><select id='autoidstdigital' value="+id1type+">\
    <option value='"+id1num+"'>Auto</option>selecttable1+selectend;"+selecttable1+selectend; 
    
    var menuidst="<label>ID:</label><select id='menuidst' value="+id1type+">\
    <option value='"+id1num+"'>"+id1type+"</option>selecttable1+selectend;"+selecttable1+selectend;    
    var hlst2=   
    "<label>"+lookup2table[type]+":</label><input type='text' maxlength='5' id='thst2' value="+valset2+" ><br>"
    var hlst4=
    //"<label>"+lookup4table[type]+":</label><input type='number' pattern='[0]' maxlength='5' id='thst4' value="+valset4+"><br>"   
    "<label>"+lookup4table[type]+":</label><input type='text' maxlength='5' oninput='this.value=(parseInt(this.value)||0)' placeholder='0' autofocus=''\
    id='thst4' value="+valset4+"><br>"       
    var endst="<button class='sbut' onclick='closePopup("+type+","+xx+","+yy+")'>Submit</button>"           
    ////////////////////////////////////
    if(type===23)   sdata=autoidstdigital+Select2+Select4+commnest+endst;             //Link
    if(type===24)   sdata=autoidstanalog+"<h7>Unique ID required</h7><br>"+group+commnest+"<br>"+endst;                //AOUT
    if(type===25)   sdata=autoidstanalog+"<h7>Unique ID required</h7><br>"+group+commnest+"<br>"+endst;                //Ain
    if(type===26)   sdata=autoidstdigital+hlst2+commnest+endst;                       //AIN CONSTANT
    if(type>26 && type<=36)   sdata=menuidst+"<h7>Input can multi assign</h7><br>"+group+commnest+"<br>"+endst;            //Normal OPEN--CONSTANTswitches
    if(type===37)   sdata=autoidstdigital+Unit+hlst4+commnest+endst;                  //timer   
    if(type===38)   sdata=autoidstdigital+Count+hlst4+commnest+endst;                 //counter
    if(type===39)   sdata=autoidstdigital+"<br>"+commnest+"<br>"+endst;               //FF
    if(type===40)   sdata=autoidstdigital+hlst2+commnest+endst;                       //DAC
    if(type===41)   sdata=autoidstdigital+hlst2+hlst4+commnest+endst;                 //ADC up down
    if(type===42)   sdata=autoidstdigital+hlst2+hlst4+commnest+endst;                 //COMPARATOR
    //if(type===43)   sdata=menuidst+OutputMode+"<h7>Output can multi assign</h7><br>"+commnest+"<br>"+endst;                      //relay
    if(type===43)   sdata=menuidst+"<h7>Output can multi assign</h7><br>"+group+commnest+"<br>"+endst;  
    if(type===44)   sdata=autoidstdigital+SelectTopic+"<h7>TX topic equal to RX topic</h7><br>"+commnest+endst;                 //MQTT in
    if(type===45)   sdata=autoidstdigital+SelectTopic+"<h7>RX topic equal to TX topic</h7><br>"+commnest+"<br>"+endst;               //MQTT out    
    if(type===46)   sdata=autoidstdigital+UserDefineOut+hlst4+commnest+endst;            //USER in
    if(type===47)   sdata=autoidstdigital+UserDefineIn+hlst4+commnest+endst;                  //USER out
    if(type===48)   sdata=autoidstdigital+AMath+"<br>"+commnest+endst;                //math out
    if(type===49)   sdata=autoidstdigital+"<h7>Output can multi assign</h7><br>"+commnest+"<br>"+endst;                      //relay
    if(type===50)   sdata=KeySel+phoneRowIn+phin+commnest+"<br>"+endst;               //phone in 
    if(type===51)   sdata=KeySel+"<br>"+commnest+"<br>"+endst;                        //API phone in  
    if(type===55)   sdata=KeySel+phoneRowIn+commnest+endst;                           //phone out
    if(type===56)   sdata=KeySel+"<br>"+commnest+"<br>"+endst;                        //API phone out  
    if(type===60)   sdata=autoidstdigital+RTimer+hlst4+commnest+endst;                //repeat timer
    if(type===61)   sdata=autoidstdigital+group+hlst4+commnest+endst; 
    if(type===62)   sdata=autoidstdigital+commnest+endst;                             //repeat timer
    }
  }
 
var checkoveronce = Array.from(Array(70), () => new Array(9).fill(0)); 
//for auto ID
function cannotmorethanonce(type,deviceID,xx,yy) {
if(type===23 || type===24 || (type>=37 && type<=42) || type>=44 || type>=50 || type>=55)  //assign once control
  {//get assign status
  for(let t=1;t<9;t++)  
    checkoveronce[type][t]=0;
  for(let gx=0;gx<xcount;gx++)
    for(let gy=0;gy<ycount;gy++)
    {scantype=serialcelldata[gy*48+gx*8];  
    if(scantype==type && serialcelldata[gy*48+gx*8+1]>0)    //type equal 
      {checkoveronce[type][serialcelldata[gy*48+gx*8+1]>>8]=1;        //set as 1
      if(gx===xx && gy===yy)
        return 0;     //already in use with same location
      }  
    }  
  if(checkoveronce[type][deviceID]===0)  
    {checkoveronce[type][deviceID]=1;  
    return 0;
    }
  else  //id already used
    return 1;
  }
}  
    

function closePopup(type,xx,yy) {           
    //var popup = document.getElementById('popup-overlay');
    //deletetable(); 
    var val1;
    var val2=""; 
    var val4; 
    var val5; 
    var assignok=0;  
    let shift8val1;   
    document.getElementById('botul').style.backgroundColor="#f0f0f0"; 
    
    if(type>=50 && type<61)
      {if(type===50 || type===55 || type===51 || type===56)  
        val1 = document.getElementById('KeySel').value;           
      }
    else if((type>26 && type<=36) || type==43)
      {val1 = document.getElementById('menuidst').value;   //store value         
      //if(val1<255)  val1=256+type;  //force to 1        
      }
    else
      {val1 = document.getElementById('autoidstdigital').value;   //store value         
      //if(val1<255)  val1=256+type;  //force to 1        
      }  
    shift8val1=val1>>8;   //for auto ID  
    if(shift8val1===0) 
      {shift8val1=1;  
      if(cannotmorethanonce(type,shift8val1,xx,yy)==1)
        {for(shift8val1=1;shift8val1<=9;shift8val1++)
        if(shift8val1<=9 && checkoveronce[type][shift8val1]==0) 
          {if(shift8val1===9)
            {window.alert("All available devices fully assigned");        
            assignok=1;          
            }
          if(cannotmorethanonce(type,shift8val1,xx,yy)==1)  //second time                                         
            {window.alert("This device ID cannot not auto assign\n Please assign manually");        
            assignok=1;
            break;
            }
          else
            {assignok=0;             
            break;
            }
          }  
        }  
      else
          {//window.alert("This device ID cannot not assign more than once \n auto assign to next available"); 
          assignok=0;
          }      
      val1=(shift8val1<<8)+type;      
      }    
    else
      {if(cannotmorethanonce(type,shift8val1,xx,yy)==1)
        {window.alert("Cannot assign more than once");    
        assignok=1;
        }
      else
        {val1=(shift8val1<<8)+type;   
        assignok=0;
        }
      }    
    val2=0;  
    if(assignok===0)      
    {updataonecell(1,xx,yy,val1);  //show ID text         
    switch(type)
    {case 23:     //link
          val2 = document.getElementById('linkst').value;   
          if(val2<200)  val2="256";
          break;
    case  26:
          val2 = document.getElementById('thst2').value;
          //if(val2==="")  val2="127";  //default   
          break; 
    case  37:
          val2 = document.getElementById('unit').value;   
          if(val2<200)  val2="256";
          break;       
    case  40:
          val2 = document.getElementById('thst2').value;   
          if(val2==="")  val2="32";
          break;          
    case  41:
    case  42:            
          val2 = document.getElementById('thst2').value;   
          break; 
    case  24:
    case  25:
    case  27:
    case  28:
    case  29:
    case  30: 
    case  33:
    case  34:
    case  35:
    case  36:  
    case  43:    
    case  61:        
          val2 = document.getElementById('group').value;   
          break;                 
    case  46:
    case  47: 
          val2 = document.getElementById('userdefine').value;   
          break;           
    case  60:
          val2 = document.getElementById('rtimer').value;   
          break    
    case  48:
          val2 = document.getElementById('aMath').value;   
          break;           
    case  38:
          val2 = document.getElementById('count').value;   
          break;   
    case  44:
    case  45:
          val2 = document.getElementById('topicst').value;   
          break;             
    }
    if(val2>0)
      updataonecell(2,xx,yy,val2);    
    if(type===23)  //select item
      {val4 = document.getElementById('outmode').value;            
      if(val4<200) val4="256";
      updataonecell(4,xx,yy,val4);  //show text     
      }
    if(type===37|| type===60 || type===61 || type===38 || type===41 || type===42 || type===46 || type===47)  //A/D convert
    {val4 = document.getElementById('thst4').value;           
    if(val4===null) val4=1;
    updataonecell(4,xx,yy,val4);  //show text   
    }    
    if(type===50 || type===55)  
    {val2 = document.getElementById('phoneRowIn').value;   
    if(val2<256)  val2=256;
    updataonecell(2,xx,yy,val2);  //show text  
    }   
    if(type===50) //select item
    {val4 = document.getElementById('phin').value;            
    if(val4<200) val4="256";
    updataonecell(4,xx,yy,val4);  //show text     
    }
    val5 = document.getElementById('comst').value;   
    if(type===41 && val4>val2) 
      window.alert("HIGH VALUE must GREAT than LOW value")                       
    updataonecell(5,xx,yy,val5);  //comment       
    }
  addtext(); 
  mouseleftallow=1;    
  localStorage.setItem('plcdata',JSON.stringify(serialcelldata)); 
  document.getElementById('popup').style.display='none';
  updatetable(TEXT); 
  }

function updataonecell(z,x,y,texthere)  
{
if(texthere===Delete) //clear      
{//if((serialcelldata[x*8+y*48+3]&2)===2)
serialcelldata[x*8+(y+1)*48+3]=serialcelldata[x*8+(y+1)*48+3]&0xf6;
//if((serialcelldata[x*8+y*48+3]&1)===1)
serialcelldata[x*8+(y-1)*48+3]=serialcelldata[x*8+(y-1)*48+3]&0xfd;
  for(let zz=0;zz<8;zz++)   
  serialcelldata[y*48+x*8+zz]="";        
  //serialcelldata[x*8+(y+1)*48+3]=serialcelldata[x*8+(y+1)*48+3]&0xf7;
  Acstatus="";  
  statbuf=""; //device on off status
  cursign=""; //clear cursor
  //addtext();    //for delete text
}    
else
{if(texthere<=Delete)
  {
    if(z===3)
      {if(texthere===4 || texthere===8)
        {serialcelldata[y*48+x*8]="";   
        serialcelldata[y*48+x*8+1]="";    
        serialcelldata[y*48+x*8+2]="";                      
        serialcelldata[y*48+x*8+4]="";    
        serialcelldata[y*48+x*8+5]="";     
        serialcelldata[y*48+x*8+6]="";   
        serialcelldata[y*48+x*8+7]="";                              
        }
      if(texthere===2)// || texthere===1)    
          {serialcelldata[(y+1)*48+x*8+z]=serialcelldata[(y+1)*48+x*8+z]|1;  
          serialcelldata[(y)*48+x*8+z]=serialcelldata[(y)*48+x*8+z]|2;  
          }
      if(texthere===1)    
          {serialcelldata[(y-1)*48+x*8+z]=serialcelldata[(y-1)*48+x*8+z]|2;
          serialcelldata[(y)*48+x*8+z]=serialcelldata[(y)*48+x*8+z]|1;   
          }
      if(texthere===8)                               
        serialcelldata[y*48+x*8+z]=serialcelldata[y*48+x*8+z]|0x08;        
      if(texthere===4)            
        serialcelldata[y*48+x*8+z]=serialcelldata[y*48+x*8+z]|0x04;                         
      }
    if(z===0)                 
        {
          {serialcelldata[y*48+x*8+1]="";    
          serialcelldata[y*48+x*8+2]="";    
          serialcelldata[y*48+x*8+4]="";    
          serialcelldata[y*48+x*8+5]=""; 
          serialcelldata[y*48+x*8+6]="";  
          serialcelldata[y*48+x*8+7]="";                      
          }                  
        serialcelldata[y*48+x*8+3]=serialcelldata[y*48+x*8+3] & 0x03;  //            
        serialcelldata[y*48+x*8]=texthere;                    
        }                 
    }   
  }  
  //5 for comment 6 topic 7 payload
  if(serialcelldata[y*48+x*8]>0)  
  {if(z===1 || z===2 || z===4 || z===5 || z===6 || z===7) 
   {serialcelldata[y*48+x*8+z]=texthere;   
   }
  }   
}
)rawliteral";