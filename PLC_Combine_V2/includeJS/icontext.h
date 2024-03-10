static const char PROGMEM INDEX_HTML_icontext[] = R"rawliteral(
///////////////////hwsim.js+svgpick.js+icontext//////////
//var systemtype=1;
  var tryonline=0;  //try on line

  var Sceret=0;
  var comv_icon=0;
  var txcount=14;
  var tycount=80;
  var ycount=40; 
  var xcount=6;
  var zcount=7;  //must over range
  
  //SHOW PLC EDIT
  var FILLALL=10;
  var TEXT=11;
  var CURSOR=12;
  var SIM=18;
  var CLEAR=16;
  var LOGIN=99;
  var ABOUT=100;
  
  var serialcelldata = Array(1920).fill(""); 
  var cursor=81;
  var Delete=80;
  var svgdata0="";
  var svgdata3="";
  var svgdata="";
  var svgtext="";
  var svgedit="";
  var svgSimSign="";
  var svghints = Array(85).fill(""); 
  var showstatus=0;
  var svgwidth=1030;
  //sim
  var statbuf=""; 
  var Acstatus="";
    
/////////ComVariable//////////
var instate = Array(240).fill(0);  
var DeviceState= Array(240).fill("off");    
var DeviceStatus= Array(240).fill(0);     
var cellw=160;
var cellh=80;  
var fx=0;   //for ff
var fy=0;   //for ff
var tx=0;   //for timer
var ty=0;   //for timer
var cx=0;
var cy=0;
var countup=0;

var  fbstatus1=Array(60).fill('0'); 
var  fbstatus2=Array(60).fill('0'); 
var  fbstatus3=Array(60).fill('0'); 
var  fbstatus4=Array(60).fill('0'); 

var URL ="192.168.1.95:8088";
//var URL=window.location.host; 

function updatestatus() //e.g. ON OFF *important*
{//console.log('updatestatus');
statbuf=""; //device on off status
Acstatus="";  
for(var yb=0;yb<ycount;yb++)
for(var xa=0;xa<xcount;xa++)
  {var type=serialcelldata[xa*8+yb*48];    
  if(type>0)
    {//statbuf=statbuf+"<text x='"+(xa*cellw+90)+"' y='"+(yb*cellh+68)+"' fill='yellow'>STAT:</text>";
    let statb="<text x='"+(xa*cellw+90)+"' y='"+(yb*cellh+68)+"' fill='rgb(255,255,255)'>STAT: ";  
    if((type===24 || type==55 || type==38)|| (type==44 && instate[yb*6+xa]===2))//analog take the after postion INPUT
      {statbuf=statbuf+statb+(fbstatus1[yb*6+xa]+fbstatus2[yb*6+xa]+fbstatus3[yb*6+xa])+"</text>";  
      }    
    if(type===25 || type===40 || type==48 ||(type==45 && instate[yb*6+xa+1]===2)) //analog take the after postion OUTPUT
      {statbuf=statbuf+statb+(fbstatus1[yb*6+xa+1]+fbstatus2[yb*6+xa+1]+fbstatus3[yb*6+xa+1])+"</text>";  
      }      
    if((type>=28 && type<=36)||(type==45 && instate[yb*6+xa+1]<2)) //lower case for switches
      {if(DeviceState[yb*6+xa]==='ON')  DeviceState[yb*6+xa]='on';
      if(DeviceState[yb*6+xa]==='OFF')  DeviceState[yb*6+xa]='off';   
      statbuf=statbuf+statb+DeviceState[yb*6+xa]+"</text>"; 
      }
    if(type==44 && instate[yb*6+(xa-1)]<2 && instate[yb*6+xa]!=2)
      {if(DeviceState[yb*6+(xa-1)]==='on')  DeviceState[yb*6+xa]='on';
      if(DeviceState[yb*6+(xa-1)]==='off')  DeviceState[yb*6+xa]='off';   
      statbuf=statbuf+statb+DeviceState[yb*6+xa]+"</text>"; 
      }  
    if(DeviceState[yb*6+xa]!=""&& (type===43 || type===39))//FOR PIN ONLY FF RLY
      statbuf=statbuf+statb+DeviceState[yb*6+xa]+"</text>"; 
    if(DeviceState[yb*6+xa]!="" && (type===38 || type===37))//For Timer and counter
      Acstatus=Acstatus+statb+DeviceStatus[yb*6+xa]+"</text>";      
    }
  }   
}

function updatecolor() {
  var type;  
  var ctltext="";
  svgSimSign="";
  for(xa=0;xa<xcount;xa++)   //display color and sign
    {for(yb=0;yb<ycount;yb++)                
      {type=serialcelldata[xa*8+yb*48];     //device in out color
      //if(instate[yb*6+xa]>=2) incolor='orange';
      if(instate[yb*6+xa]===1 || xa===0) incolor='green'; //left side
      else if(instate[yb*6+xa]===2) incolor='orange';
      else if(instate[yb*6+xa]===0) incolor='yellow';    
      
      //if(instate[yb*6+xa+1]>=2) outcolor='orange';
      if(instate[yb*6+xa+1]===1) outcolor='green';
      else if(instate[yb*6+xa+1]===2) outcolor='orange';
      else if(instate[yb*6+xa+1]===0) outcolor='yellow';   
      
      if(xa===5)  outcolor='red';                        //right sight                  
      svgSimSign=svgSimSign+filldata(serialcelldata[xa*8+yb*48],xa,yb,incolor,outcolor);   
      
      var uppersign=serialcelldata[xa*8+(yb-1)*48];   //handle lower center tap
      if((serialcelldata[xa*8+yb*48+3]&8)===8 && (uppersign===40||uppersign===44||uppersign===46||uppersign===60))           
        {if(uppersign===40)  ctltext='DOWN';
        if(uppersign===44)  ctltext='SEND';
        if(uppersign===46)  ctltext='TRIGGER';
        if(uppersign===60)  ctltext='PAUSE';        
        svgSimSign=svgSimSign+filldata(serialcelldata[xa*8+yb*48+3],xa,yb,'yellow','yellow',ctltext);//
        }
      if((serialcelldata[xa*8+yb*48+3]&8)>0 && (serialcelldata[xa*8+(yb-1)*48]===42 || serialcelldata[xa*8+(yb-1)*48]===48)) //handle comparator low line color
        {console.log('color changed',serialcelldata[xa*8+yb*48+3]&7|0x10);
        svgSimSign=svgSimSign+filldata(serialcelldata[xa*8+yb*48+3]&7|0x10,xa,yb,incolor,outcolor,ctltext);
        } 
      else  
        svgSimSign=svgSimSign+filldata(serialcelldata[xa*8+yb*48+3],xa,yb,incolor,outcolor,ctltext); //fill line color
      //Device state follow the instate     
      if(type===43)
        {if(instate[yb*6+xa]>0)
          DeviceState[yb*6+xa]="ON";
        else
          DeviceState[yb*6+xa]="OFF";  
        }  
      }    
    } 
  }
//////////end of hwsim.js//////////////////////  
//////////start of icontext.js////////////////// 
function filldata(type,x,y,inputcolor='yellow',outputcolor='yellow',ctltext='RET')
{     var uppersign=serialcelldata[x*8+(y-1)*48];       
      if(uppersign===40)  ctltext='DOWN';
      if(uppersign===44)  ctltext='SEND';
      if(uppersign===46)  ctltext='TRIGGER';
      if(uppersign===60)  ctltext='PAUSE';
      if(uppersign===61)  ctltext='';       
      var cellw=160;
      var cellh=80;
      var soffset=0; //0 or 80
      var incolor=inputcolor;
      var outcolor=outputcolor;
      var tricolor='blue';
      var endcell=160;
      var retval="";      
      var rectangle="<rect  x='"+(x*cellw+90)+"' y='"+(y*cellh+15)+"' width='50' height='40' style='fill:rgb(70, 70, 70);stroke:yellow;stroke-width:2'/>";      
      var rectangleline="<polygon points='"+(x*cellw+90)+","+(y*cellh+15)+" "+(x*cellw+140)+","+(y*cellh+15)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+90)+","+(y*cellh+55)+" "+(x*cellw+140)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+90)+","+(y*cellh+15)+" "+(x*cellw+90)+","+(y*cellh+20)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+90)+","+(y*cellh+35)+" "+(x*cellw+90)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+140)+","+(y*cellh+15)+" "+(x*cellw+140)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>"

      var parallelogram="<polygon points='"+(x*cellw+90)+","+(y*cellh+15)+" "+(x*cellw+80)+","+(y*cellh+55)+" "+(x*cellw+135)+"\
      "+(y*cellh+55)+" "+(x*cellw+145)+","+(y*cellh+15)+"'style='fill:rgb(70, 70, 70);stroke:yellow;stroke-width:2'/>"
      
      var arrowup="<polygon points='"+(x*cellw+110)+","+(y*cellh+15)+" "+(x*cellw+115)+","+(y*cellh+25)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+110)+","+(y*cellh+15)+" "+(x*cellw+105)+","+(y*cellh+25)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+110)+","+(y*cellh+15)+" "+(x*cellw+110)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>"

      var arrowdown="<polygon points='"+(x*cellw+110)+","+(y*cellh+55)+" "+(x*cellw+115)+","+(y*cellh+45)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+110)+","+(y*cellh+55)+" "+(x*cellw+105)+","+(y*cellh+45)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+110)+","+(y*cellh+15)+" "+(x*cellw+110)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>"

      var normalopen="<polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+100)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
      <polygon points='"+(x*cellw+100)+","+(y*cellh+15)+" "+(x*cellw+100)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+120)+","+(y*cellh+15)+" "+(x*cellw+120)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+121)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>"
  
      var normalclose="<polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+100)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
      <polygon points='"+(x*cellw+100)+","+(y*cellh+15)+" "+(x*cellw+100)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+120)+","+(y*cellh+15)+" "+(x*cellw+120)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+121)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>\
      <polygon points='"+(x*cellw+120)+","+(y*cellh+15)+" "+(x*cellw+100)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>"
     
      var rectangleinout="<polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+88)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
      <polygon points='"+(x*cellw+142)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>"

      var rightarrow= "<polygon points='"+(x*cellw+90)+","+(y*cellh+15)+" "+(x*cellw+90)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+90)+","+(y*cellh+15)+" "+(x*cellw+130)+","+(y*cellh+15)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+90)+","+(y*cellh+55)+" "+(x*cellw+130)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+145)+","+(y*cellh+35)+" "+(x*cellw+130)+","+(y*cellh+15)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+145)+","+(y*cellh+35)+" "+(x*cellw+130)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>"

      var leftarrow=
      "<polygon points='"+(x*cellw+140)+","+(y*cellh+15)+" "+(x*cellw+140)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+100)+","+(y*cellh+15)+" "+(x*cellw+140)+","+(y*cellh+15)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+100)+","+(y*cellh+55)+" "+(x*cellw+140)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+80)+","+(y*cellh+35)+" "+(x*cellw+100)+","+(y*cellh+15)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+80)+","+(y*cellh+35)+" "+(x*cellw+100)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>"
      
      var phonein= "<polygon points='"+(x*cellw+100)+","+(y*cellh+15)+" "+(x*cellw+100)+","+(y*cellh+50)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+125)+","+(y*cellh+15)+" "+(x*cellw+125)+","+(y*cellh+50)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+100)+","+(y*cellh+50)+" "+(x*cellw+125)+","+(y*cellh+50)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+100)+","+(y*cellh+15)+" "+(x*cellw+125)+","+(y*cellh+15)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+125)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>"

      var phoneout="<polygon points='"+(x*cellw+100)+","+(y*cellh+15)+" "+(x*cellw+100)+","+(y*cellh+50)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+125)+","+(y*cellh+15)+" "+(x*cellw+125)+","+(y*cellh+50)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+100)+","+(y*cellh+50)+" "+(x*cellw+125)+","+(y*cellh+50)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+100)+","+(y*cellh+15)+" "+(x*cellw+125)+","+(y*cellh+15)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw)+","+(y*cellh+35)+" "+(x*cellw+100)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>"

      var HORIZONTAL="<polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>"
      var rightangleup=
      "<polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+115)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
      <polygon points='"+(x*cellw+115)+","+(y*cellh)+" "+(x*cellw+115)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
      <polygon points='"+(x*cellw+115)+","+((y-1)*cellh+57)+" "+(x*cellw+115)+","+((y-1)*cellh+cellh)+"'style='stroke:"+incolor+";stroke-width:2;'/>"
      //<text font-size=11 x='"+(x*cellw+110)+"' y='"+((y-1)*cellh+50)+"' fill='yellow'>"+ctltext+"</text>"         
      //2
      var vhalflower="<polygon points='"+(x*cellw+soffset+2)+","+(y*cellh+35)+" "+(x*cellw+soffset+2)+","+(y*cellh+cellh)+"'style='stroke:"+incolor+";stroke-width:2;'/>"        
      var vhalfupper="<polygon points='"+(x*cellw+soffset+2)+","+(y*cellh)+" "+(x*cellw+soffset+2)+","+(y*cellh+36)+"'style='stroke:"+incolor+";stroke-width:2;'/>"
      var remote="<text font-size=11 x='"+(x*cellw+88)+"' y='"+(y*cellh+65)+"' fill='yellow'>Remote</text>"
      var shortRightup= "<polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+75)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
      <polygon points='"+(x*cellw+75)+","+(y*cellh)+" "+(x*cellw+75)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
      <polygon points='"+(x*cellw+75)+","+((y-1)*cellh+45)+" "+(x*cellw+75)+","+((y-1)*cellh+80)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
      <polygon points='"+(x*cellw+75)+","+((y-1)*cellh+45)+" "+(x*cellw+90)+","+((y-1)*cellh+45)+"'style='stroke:"+incolor+";stroke-width:2;'/>"
     
      var compare="<polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+88)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
      <polygon points='"+(x*cellw+90)+","+(y*cellh+15)+" "+(x*cellw+145)+","+(y*cellh+35)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+90)+","+(y*cellh+55)+" "+(x*cellw+145)+","+(y*cellh+35)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+90)+","+(y*cellh+15)+" "+(x*cellw+90)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
      <polygon points='"+(x*cellw+145)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>"

      var GROUP="<text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>Group:</text>";
      
      switch(type)                      
        {case 1:     //VERTICAL HALF UPPER
          retval=vhalfupper; 
          break;        
        case  2:     //VERTICAL HALF LOWER
          retval=vhalflower;
          break;  
        case  3:     //VERTICAL HALF LOWER
          retval=vhalfupper+vhalflower;        
          break;           
        case  4:     //HORIZONTAL  
          retval=HORIZONTAL;
          break; 
        case  5:     //VERTICAL HALF UPPER
          retval=HORIZONTAL+vhalfupper;        
          break;        
        case  6:     //VERTICAL HALF LOWER
          retval=HORIZONTAL+vhalflower;           
          break; 
        case  7:     //VERTICAL HALF LOWER
          retval=HORIZONTAL+vhalflower+vhalfupper;    
          break; 
        case 8:     //right angle up
          retval=rightangleup+"<text font-size=11 x='"+(x*cellw+105)+"' y='"+((y-1)*cellh+50)+"' fill='yellow'>"+ctltext+"</text>";
          break;         
        case 10:     //right angle up+2
          retval=rightangleup+vhalflower+"<text font-size=11 x='"+(x*cellw+105)+"' y='"+((y-1)*cellh+50)+"' fill='yellow'>"+ctltext+"</text>";
          break; 
        case 12:     //4 add 8
          retval=HORIZONTAL+rightangleup+"<text font-size=11 x='"+(x*cellw+105)+"' y='"+((y-1)*cellh+50)+"' fill='yellow'>"+ctltext+"</text>";
          break;   
        case 14:     //4 add 8
          retval=HORIZONTAL+rightangleup+vhalflower+"<text font-size=11 x='"+(x*cellw+105)+"' y='"+((y-1)*cellh+50)+"' fill='yellow'>"+ctltext+"</text>";
          break;     
        case 16:     //short right angle up //analog compare
          retval=shortRightup;
          break;
        case 18:     //right angle up+2
          retval=shortRightup+vhalflower;          
          break;          
        case 20:     //right angle up+2 0x10111
          retval=shortRightup+HORIZONTAL;             
          break; 
        case 22:     //right angle up+2 0x10111
          retval=shortRightup+HORIZONTAL+vhalflower;             
          break;            
        case  23:     //LINK
          retval=rightarrow+
          "<polygon points='"+(x*cellw+142)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>Link:</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+48)+"' fill='yellow'>Mode:</text>\
          <text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+40)+"' fill='yellow'>LINK</text>"
          break;                 
        case  24:     //ADC
          retval=leftarrow+
          "<polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+80)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
          <polygon points='"+(x*cellw+140)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+92)+"' y='"+(y*cellh+40)+"' fill='yellow'>AOUT</text>"+GROUP;
          break;                                               
        case  25:     //AIN
          retval=rightarrow+
          "<polygon points='"+(x*cellw+142)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+40)+"' fill='yellow'>AIN</text>"+GROUP;
          break;   
        case  26:     //AIN CONSTANT
          retval=rightarrow+
          "<polygon points='"+(x*cellw+142)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>Value:</text>\
          <text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+12)+"' fill='yellow'>CONSTANT</text>\
          <text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+40)+"' fill='yellow'>AIN</text>"
          break;            
        case  27:   //normal open remote 
          retval=normalopen+arrowup+remote+GROUP;
          break;  
        case  28:   //normal open rising 
          retval=normalopen+arrowup+GROUP;
          break;
        case  29:   //normal open falling  
          retval=normalopen+arrowdown+GROUP;
          break; 
        case  30:   //NORMAL open
          retval=normalopen+GROUP;    
          break;
        case  33:    //normal CLOSE rising         
          retval=normalclose+arrowup+remote+GROUP;
          break;  
        case  34:    //normal CLOSE rising         
          retval=normalclose+arrowup+GROUP;
          break;
        case  35:   //normal CLOSE falling  
          retval=normalclose+arrowdown+GROUP;
          break;    
        case  36:   //normal close
          retval=normalclose+arrowdown+GROUP;
         break;  
        case  37:     //TIMER            
          retval=rectangleline+rectangleinout+"<text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+40)+"' fill='yellow'>Timer</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>Mod:</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+48)+"' fill='yellow'>Time:</text>"         
          break;                                
        case  38:     //COUNTER
          //retval=rectangle+rectangleinout+"<text font-size=11 x='"+(x*cellw+100)+"' y='"+(y*cellh+40)+"' fill='yellow'>C</text>\
          retval=rectangleline+rectangleinout+"<text font-size=11 x='"+(x*cellw+93)+"' y='"+(y*cellh+40)+"' fill='yellow'>Counter</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>Mode:</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+48)+"' fill='yellow'>Count:</text>"          
          break;                   
        case  39:     //FLIP FLOP
          retval=rectangle+rectangleinout+"<text font-size=11 x='"+(x*cellw+98)+"' y='"+(y*cellh+38)+"' fill='yellow'>SRFF</text>"
          break;         
        case  40:     //DAC
          retval= rightarrow+     
          "<polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+88)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
          <polygon points='"+(x*cellw+146)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>Step:</text>\
          <text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+40)+"' fill='yellow'>UP</text>\
          <text font-size=11 x='"+(x*cellw+105)+"' y='"+(y*cellh+30)+"' fill='yellow'>D/A</text>"
          break;    
        case  41:     //ADC up down
          retval= leftarrow+
          "<polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+80)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
          <polygon points='"+(x*cellw+142)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>REF:</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+48)+"' fill='yellow'>H--L:</text>\
          <text font-size=11 x='"+(x*cellw+92)+"' y='"+(y*cellh+40)+"' fill='yellow'>A/D</text>"
          break;                            
        case  42:     //COMPARATOR
          retval=  compare+
          "<text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>L->H:</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+48)+"' fill='yellow'>H->L:</text>\
          <text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+12)+"' fill='yellow'>Hysteresis</text>\
          <text font-size=11 x='"+(x*cellw+92)+"' y='"+(y*cellh+40)+"' fill='yellow'>CMP</text>"
          break;
        case  43:    //RELAY    
          retval= "<polygon points='"+(x*cellw+90)+","+(y*cellh+35)+" "+(x*cellw+100)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
          <polygon points='"+(x*cellw+90)+","+(y*cellh+35)+" "+(x*cellw+100)+","+(y*cellh+15)+"'style='stroke:yellow;stroke-width:2;'/>\
          <polygon points='"+(x*cellw+135)+","+(y*cellh+15)+" "+(x*cellw+145)+","+(y*cellh+35)+"'style='stroke:yellow;stroke-width:2;'/>\
          <polygon points='"+(x*cellw+135)+","+(y*cellh+55)+" "+(x*cellw+145)+","+(y*cellh+35)+"'style='stroke:yellow;stroke-width:2;'/>\
          <polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+88)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
          <polygon points='"+(x*cellw+145)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+105)+"' y='"+(y*cellh+40)+"' fill='yellow'>OUT</text>"+GROUP;
          break;  
        case  44:     //MQTT IN
          retval=rectangle+"<polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+88)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+98)+"' y='"+(y*cellh+30)+"' fill='yellow'>MQTT</text>\
          <text font-size=11 x='"+(x*cellw+98)+"' y='"+(y*cellh+48)+"' fill='yellow'>TX</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>To:</text>"
          break;
        case  45:     //MQTT OUT 
          retval=rectangle+"<polygon points='"+(x*cellw+142)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+30)+"' fill='yellow'>MQTT</text>\
          <text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+48)+"' fill='yellow'>RX</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>From:</text>"
          break;                      
        case  46:     //MODBUS IN
          retval=parallelogram+
          "<polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+85)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+48)+"' fill='yellow'>ADD:</text>\
          <text font-size=11 x='"+(x*cellw+92)+"' y='"+(y*cellh+34)+"' fill='yellow'>TO</text>\
          <text font-size=11 x='"+(x*cellw+86)+"' y='"+(y*cellh+48)+"' fill='yellow'>MODBUS</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>Type:</text>" 
          break; 
        case  47:     //MODBUS out        
          retval=parallelogram+
          "<polygon points='"+(x*cellw+140)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+48)+"' fill='yellow'>ADD:</text>\
          <text font-size=11 x='"+(x*cellw+92)+"' y='"+(y*cellh+34)+"' fill='yellow'>FROM</text>\
          <text font-size=11 x='"+(x*cellw+86)+"' y='"+(y*cellh+48)+"' fill='yellow'>MODBUS</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>Type:</text>"
          break; 
        case  48:     //math out        
        retval=  compare+
          "<text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>Math:</text>\
          <text font-size=11 x='"+(x*cellw+78)+"' y='"+(y*cellh+30)+"' fill='yellow'>A</text>\
          <text font-size=11 x='"+(x*cellw+78)+"' y='"+(y*cellh+56)+"' fill='yellow'>B</text>\
          <text font-size=11 x='"+(x*cellw+90)+"' y='"+(y*cellh+73)+"' fill='yellow'>Analog Math</text>\
          <text font-size=11 x='"+(x*cellw+92)+"' y='"+(y*cellh+40)+"' fill='yellow'>Math</text>"
          break;
        case  49:     //MQTT OUT
          retval="<polygon points='"+(x*cellw+90)+","+(y*cellh+15)+" "+(x*cellw+90)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
          <polygon points='"+(x*cellw+140)+","+(y*cellh+15)+" "+(x*cellw+140)+","+(y*cellh+55)+"'style='stroke:yellow;stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+30)+"' fill='yellow'>GROUP</text>\
          <text font-size=11 x='"+(x*cellw+105)+"' y='"+(y*cellh+45)+"' fill='yellow'>CTL</text>\
          <text font-size=11 x='"+(x*cellw+105)+"' y='"+(y*cellh+60)+"' fill='yellow'>I/O</text>\
          <polygon points='"+(x*cellw+140)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>\
          <polygon points='"+(x*cellw)+","+(y*cellh+35)+" "+(x*cellw+90)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>"  
          break;                     
        case  50:    //PHONE IN
          retval=phonein+                    
          "<text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+48)+"' fill='yellow'>TYPE:</text>\
          <text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+73)+"' fill='yellow'>PHONE IN:</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>ROW:</text>"
          break;  
        case  51:    //API PHONE IN
          retval=phonein+                   
          "<text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+48)+"' fill='yellow'>Code:</text>\
          <text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+73)+"' fill='yellow'>API PH IN</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>Row:</text>"         
          break;          
        case  55:    //PHONE OUT
          retval=phoneout+                   
          //"<text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+48)+"' fill='yellow'>TYPE:</text>\
          "<text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+73)+"' fill='yellow'>PHONE OUT</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>ROW:</text>"
          break;  
        case  56:    //API PHONE OUT
          retval=phoneout+                  
          "<text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+48)+"' fill='yellow'>Code:</text>\
          <text font-size=11 x='"+(x*cellw+95)+"' y='"+(y*cellh+73)+"' fill='yellow'>API PH OUT</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>Mode:</text>"
          break;    
        case  60:    //Repeat Time  
          retval=rectangle+"<polygon points='"+(x*cellw+142)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+outcolor+";stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+100)+"' y='"+(y*cellh+40)+"' fill='yellow'>RT</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>Unit:</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+48)+"' fill='yellow'>Repeat Time:</text>"          
          break;       
        case  61:    //Time tank  
        retval=parallelogram+
          "<polygon points='"+(x*cellw+soffset)+","+(y*cellh+35)+" "+(x*cellw+85)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
          <polygon points='"+(x*cellw+140)+","+(y*cellh+35)+" "+(x*cellw+endcell)+","+(y*cellh+35)+"'style='stroke:"+incolor+";stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+48)+"' fill='yellow'>CALL:</text>\
          <text font-size=11 x='"+(x*cellw+92)+"' y='"+(y*cellh+34)+"' fill='yellow'>USER</text>\
          <text font-size=11 x='"+(x*cellw+86)+"' y='"+(y*cellh+48)+"' fill='yellow'>DEFINE</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+30)+"' fill='yellow'>Group:</text>"       
          break;
        case  62:    //Servo  
          retval="<circle  cx='"+(x*cellw+120)+"' cy='"+(y*cellh+35)+"' r='22' stroke='yellow' stroke-width='2' fill='transparent' />\
          <text font-size=11 x='"+(x*cellw+100)+"' y='"+(y*cellh+45)+"' fill='yellow'>CLOCK</text>\
          <polygon points='"+(x*cellw+120)+","+(y*cellh+35)+" "+(x*cellw+120)+","+(y*cellh+22)+"'style='stroke:yellow;stroke-width:2;'/>\
          <polygon points='"+(x*cellw+120)+","+(y*cellh+35)+" "+(x*cellw+135)+","+(y*cellh+35)+"'style='stroke:yellow;stroke-width:2;'/>\
          <polygon points='"+(x*cellw+143)+","+(y*cellh+35)+" "+(x*cellw+160)+","+(y*cellh+35)+"'style='stroke:yellow;stroke-width:2;'/>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+25)+"' fill='yellow'>BTime:</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+38)+"' fill='yellow'>BDate:</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+51)+"' fill='yellow'>ETime:</text>\
          <text font-size=11 x='"+(x*cellw+3)+"' y='"+(y*cellh+64)+"' fill='yellow'>EDate:</text>"
          break;
        case  63:    //Clock  
          retval=
          "<path fill-rule='evenodd' d='M20 17a7 7 0 100-14 7 7 0 000 14zm0 1a8 8 0 100-16 8 8 0 000 16z' clip-rule='evenodd'/>"
          break;                                                                
        case  80:
          retval="";
          //retval="<text font-size=11 x='"+(x*cellw+98)+"' y='"+(y*cellh+30)+"' fill='yellow'>Delete</text>"
          break;
        case 81:    //cursor        
          retval="<polygon points='"+(x*cellw)+","+(y*cellh+78)+" "+(x*cellw+cellw)+","+(y*cellh+78)+"'style='stroke:rgb(20,20,20);stroke-width:3;stroke:"+outcolor+"'/>"          
          break;   
        case 82:    //up arrow        
          retval=        
          //"<image href='data:image/png;base64,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' x='"+x+"' y='"+(y*cellh+1)+"' height='26' width='26' onclick='Editmouseright(1,"+y+")'/>"           
          "<image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAAAXNSR0IArs4c6QAAAKRJREFUSEvtlNENgzAMRB+bdJVuApMUJimbdJVuArIUU4QqfJFwvuAnEonv+XyBjuSnS9anOWC5yNHW+NFBOuAiAz+Z5hlEDt7AF5iig75f48DE+1I4qhAVsBf35iSIAvgnLkMUwAuwbp/ApygPgIFtnc/yUABW/yjh+ndidf7uNG8V4CJ7gHSRbkA4ptoRhYLHA80B6b/rdED1jKOC5hlEDVXvryCKFxnx2tNvAAAAAElFTkSuQmCC' x='"+x+"' y='"+(y*cellh+1)+"' height='26' width='26' onclick='Editmouseright(1,"+y+")'/>"           
          break;
        case 83:    //left arrow        
          retval= 
          //"<image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsQAAA7EAZUrDhsAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAABAASURBVHhe7Z0LfFPl+cd/SZqkSdu0Te9tWnqBkgClVATsRETd2Jz/yf66OZW/6JwbSMHLdKAifBBB3RDBtmi5TGF+QBGEoQg4PvJXuQgMEBTaWkorvV/pLUmTpkn2Pu9p99EN7T09Tc+Pz2nK6Wnynvd73ud5n+e9VDZjxgw3JIlG8o5XSSKRBERkkoCITBIQkUkCIjINYSBuyGQudrjhdrs6zg19DUEgbsjlLjidMlwu0SK/IJD9X4DjDRpiQAiGG7W1GjQ3qbEx5ziOHdmHS4U62Nu8w/oOobug+NWN6lpfqNUOzP1dHtKvr+XnmswKOL3Eag0ZIOQrGhrViAhtxYK5eXjgD5d4a2E/gdslZ1+9Q6IHQg5bqXKipMyfV/pv7rqMX99bguZ6Jc4dDoaLtQwZ8ynekv8RORAXFAo3ior9ER7cioVPnMes+4qwfXsCbvnxT1Fa6ddxnfdIxEAEGBWVWhgiLHhm8ZeYeUcJDh6IQk72WOZHfBFnsHSYqiHkCruQSO/ExfyDDNXVWgQFOPDsM1/h5puqsG+/AVk5JuQXaSFXtaDdIfcaU9UpUQIhZ11Tq+aO/NXMk7h+eg0+PGDA2leNuHxZi6SkFjjbFR1Xe5dEB4SCvpo6DaysK7tty2cYN7YBH38YhY2vJ6Oh3hfxcVbeMoRusPdJRECEaLu62hetDMbbWz9BXJIZB/4Rg9XrxqKSBYMhITZ+nXeiECQKIEI+Cqiq1jBTBOzecQhjx7fg73visOL58ai/ooJeb2dOnrrB3hJxXF2DDoRgONplqK1TQ6+zYdtbh5FkNOONTUlYuSKVlzAkuA0K9sraEP2G8IteqkEDQmaHYLQ7ZawFqKHTOZCZdQLJphZ8cjAcS5ZdA12gHYG6Ns6AYHg3CkGDBoRgOF0y1NX5IirchlWrTiM+wYr970fjwblTYTQ2w9/Pya6kIg4HFIIGCQhrH8xplFdoEB1pxZKFZzFxQj3KizX4/fx0jIizQKtxsOuGD4hODQoQijNKSvxgGtWEpxd9hUk/qsPxwyG47c4ZGMliDH//dsZr0BrvoMrjd+3j40ReXiASEsyYM68A6VNrcOizKPwuYyqCg23cl1DCcLjKg0BouNWFgks63DytEs8tOYupU6rx9lvxeGrhNQhiDjws1M5HAgfNkopAHrpzF+FAeaUWU9Jq8HDG10ibdAX79sfizS3JgMKNoCAHgyFn0HpRJLcLcu5uqGlR/02sR2f5vl8emEpKLQMoq/CDPrAVq185jWvSruCDXbF4fUMyymq0GGGwchjdER/CrVdDKXch+6UTCE+yYbRxJkymJmh8aVxEfB0BCnrlzDr4svIpFASFynj1cg4oEPpIhcKJrwt1SIprwWs5J7jvOHI0HBs2jEJefhD0FPSxFtLdCJwDYUGkit3Y6y9/jsiRrfj1r6YjNsECtdIpKiBUsTSoKWP3R36xotwPDoec+VHhIb0alAEEQrkpN3ILAjF5XB3Wv3Ecwfo2HDwYiaxME8pZ4fQhdlY4+vjuVyIBoUBSwVrIKytO4rqb6iGjuxa52tvlmD9vMk6dCWUBrwNKBsVjQISgjz0RVRoEqhz49NhHULCK//RQOJYtn4DmFhVPFFJuqicwSPTeNrucPXEyTJpQh6np1Wg2K8FnAfXsrTwgNx/T+b97ChES7cAzi9Nw+FgENBonfFVXN6/9DkTGPobesI7Z+VrmHwoLd/JWsGtnLNatM8Fi8+FdW58emKn/FEFxu9wcRItZBQX7vzg7Zm4U5Oux972PMPn6OixZOgHHjofDT+uE2hNAqKIoN9XcrGQOrB3PP8m6trfW4JN/hCHjsXQEBLZDz8wW2c++Z20JKM3T6uv7DJwotj1/PhA73/wU4yc14NklE3C0CyD99lzxp5ZVUF2dCvTAvrz0NG74eQ1sjTL86t6bEaR3cBik/kmhy9hnyvl7ifZgDyd/FYrbLfULEPpIgkFxRijrNf1l5UlMnEa5KV8Y0+7AaFMzAgMFGN0u2TBVPwBhMNi/yyX+SExowbLnzuJH0+pw7lQgbvzprYiJsfEoXPgoCUZX6iMQFiGzeICCvjGjGvHInHykp9fi8xNhuPv+G3lPivJT1GwldU99ACLMm7p4MRAJ0WbMmVuA6TNoqk4MMjKmICDAhfAwyk3Rtf1iGYeFellT1DKA4mIdjEkNeGLhedwyoxJ7dsfhzy+mQKkEIiKsLCoVHK+k7qsXtSW0DBrPiDO0YPHS87jhxhps35aArCwjLHYFIiNaWctQSDB6oR7VGCXJlEo3LhXpEBluxeo1pzB5ch12vD0Cm95IQn2zip23sShdAtFb9ajmKCn2dWEAq/RWbN58jGdY33snDtk5RtQ3ahAX3QqXBKNP6mbtsabBor3Sci18ZC68/8HHrDtrxe53DHg5cxxsdiUMUVYepUvqm7oEIkTgQFWVBjazHOdO7uVj3lvWJ+LV9WOhYCZMryczRTAkIH3VDwIhGG0OOaqqfREZasW7Oz6BXOPGxvUjGYwxcLQpEKB1QME5SDD6Q98LhGDY7XI0NShhSm5EVuZxGE0tyF6bjBdXpcBf5+DpEOpIiWlQaKjrv4CQeSIYFEPU16tgMFiw7LlziI61Yf/eKDz/UhoS4y3w07azqyUz1d/6DhCCQSNxdmamKpnPGMN6UQRDr3fgrxtH4U9PTUbK+CtQqztnFErqb32nVmlthsXqg9pqNX58SwVPFPr7ObDmFSPW5ZgQF2cWRrqG6SQ2T+jfNUtzptqYk6YF+Pfc8Q0en5cHP40Te/bEYu/+WESxbq1aLcEYaH2rdmWwWBQI0rVh/MQGxI604vQZPbZuTYSjXQ5dwPCeUegp/RsIpchpHUZFjQaZWaOxZ5cB//OLMqzLPoHYSDOKS/06hkslKgOp79gfJzNHlP6oqtHi5TVj8bfNiZh8XR3WZp5CBAv+Sss1zOkzzy9pwPRfDqHdyaDEWtFiUWHDxtHY/U4cTGOasOWtIzBEW/jcXGH2naSB0FU9NE3qGhFr5r7jhVWp2MmgREW14t13P4OGOXYarqVx9I7he0n9qKsCIRGUsDAb1FonCwZT8fYb8Qjwb8fp0x/wWKWcxSnOjiBSUv/pe4FQr4scfaDOzlMkK9ekIjt7NJ/KuXv7IYQG2fgSZmFUUILSX/oBICQhNeLv145w1lqWP5+KzZuTEJPQiuysExgzupGvEWxtVXBQkvquLoCQCIocGk07xqc24pln07B9WzxiR1ix8rkvcEN6FYtf5DCzGIYifUq/SOq9ugFEEEXoSqUTJmMzFi+dgJNHgxFpaMX8eflIS2lAS4sSNrvUUvqqbgPhYlA0vk4kJlox/4nrcGBvDKIMNvx+bgHGjWlAVSVz9E7Jp/RFPQPCRCZJq3UgRO/A0pVp+PD9GIwe1YxHH8lDenoNSkq1rIdGUKRYpTfqMRD6FYKiC2iDLsiBlatS8NbfEvnKqIyMPNw0vQLlLKJ38tmKEpSeqhdASHI+hh7MusRaPxe2bE3i6z9MrKXMvr8YRhbZXy72hzCDVILSE/USCAWEcmaaFAgPtUEml2PdBhNeWWOCaWQjViw/iylTalF62Z8uZFdLULqrXgMhUV1TeiUsxMZXmNK4yebNI5lPacJLL5zBzVMrceFCEF/OJixylNSV+gSERBVNCcmQYDufsbhtRwJy1iUjMroVy188i2vH1+DLr4JASxYERy/1wH5IfQbSKYIRRqtqlcDrm4x4YVkKgoLasOPvhzE5tQ75+QFwOGi+LwHpDyg0X0zYjF+0h6LjVShut9Tviz4pMLRaFbhc5oef31KGzNdO8vMLH52IfYcMCA9nHQGNg1UmFbO3dkyYvGezKdDQpOJnmBsToQZ50Wen6KmgWORCfiCuTanFrvc/4+cWPTkRBz6ORjBrOZQ57t08YOG9aQJfrMGCu+4oRnODig8vi89P0bJoDWbfXQS9oQ1PPZ2Go59HsDjOw0BIBIAK9M8vQnDnz0rw5zWn2ZPhwNrVY7BtZwKUKjc3cd3dUqNTlC+70qhmt+LGskVfYMbtVUMiXUMPEW2yc+RYBHw9uU79P6VSOnHsn2F46J6LeGxhLmsddmSuNeHdXQnMxoJ3m2m7ie4+3VT5dR1ba+SsOYo4kxVZmUaE6GlXCPE1EzKtlG5qafHhew83Nqn5JEOhmIMAhGIQ2gnom+IA3PqTUjzyaD5z9na89poRu/aM4FOLqDJpQKw7dUlAvr35TMTIVqSm3g6TsQkqFc2mFJczoX4lNWA3+0K3R5sofB8MkgdKL4eCNc4RI1rw0aEYvsqqukaLjHn5zLYWwm4TNsGkp7u3qXuZ3Mnu1MXiHfCYR0yHkl6V7GA13RUMkkceJzf7GNpKI85gxv6PYpCdbWS9sADMfvASHnqwgO9i3dSs4v6hN6JWI/aDJoZ0BYPksfZN4ym02UxUlA0nT4Xg4AeRsDcrMHNmKe6/rwBXrvjA1ubDCt0LKMIUfCa6HbphMR6dZftheQwIibq55NAozbL1vUSs2zSanZXhl/9bjpm3laGirHOMvnctxRvkUSDUZCnNQtNSA3Tt2LfPgDWrTXzvqAWP5WPWvcUoKgrocPDDE4pHgZAICsUeHEqgE4cOx2DlCymwtcqw4JF8zP1DAfLzdQwKbaY1/KB4HAiJoJD5otkstA/K8RPheHrRRNjMMjz6eB4W/ekrnDoTgja7ghk0gjLAPXMRaVCAdIp2haONK0NC7cgtCMIfn5yE8hINHs64iIyHc/lfSzBbWF+WAxkeUAYVCMnllvHgMCrChi9zgzFr9jTa9RXLl5/Db1l0T3+8xWxRdsQo3g9m0IGQKPNLQZQhuhUtZh9Mv3EGLKxlPLE4Fw/d/zWs7PsrDb68Py8B8ZAICq0/iTVYUcMi93vumobKSg1+O6cI8+fkscDSicoaDY9luu7ND12JBgiJzBIFkKOSzCgq9cd9s65Hbm4gHnjoEh5fcIHPJ6Zd6+Qs6vdWiQpIp2iyXXycBdW1fnh64bU4fSoUd/6mBA/MvoRgfzuqatReC0WUQKhYNOAUH29G4TcBWLFiHI4cDsfds4oxf0E+QvwZDIcWKlVnfsh7JFIgJDlrKUBiQjNyLwbjpZUpOLgvGrf/sgxPLroAu0OGMma+hN6X9wSQIgZCIigyJCc2o7xWi/WbRuHg/kj84rYi/DXnIPuZ95ktkQMhMSisBxYd0YqLl4Kw6c1knD8XhPGTmnHbnRWsZ8Y6Aizq9xbLNQSAMDEglGGnfVcKCnVYsjwNh/8/jJ0mDG72Mxqf9g4NDSBMFKdQ/UdHWVFX74uFiyfhzDH6e+oyOB0KFqd0XDjEpUhKSlrW8f0QEIPCvvr6OkF/feHU6VC0WeTIuxjEx+W9YdsPD0xyGAgJRbbbfWC2KhAWQns9ekcTGaKPlODC1WoHQoJtXgODNITbOEGh4g99M/VtedfdeIEkICKTBERkkoCISsC/AKgJFGTqBF8UAAAAAElFTkSuQmCC' x='"+x+"' y='"+(y*cellh+27)+"' height='26' width='26' onclick='Editmouseright(3,"+y+")'/>";
          "<image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAAAXNSR0IArs4c6QAAALBJREFUSEvtldENwjAMRF83gU3KJnSSwiSwCWwCm7Q6lFTI4Dr5qJBQ/Bed45ec0l7HxtVVzB+BY+q/AueSvaUADT+ZgVqHEAvogQuwc053AJ7Aw9GlDcA96xZwAwTxSps1RH1eSd97gCkJGZzXkd22fzm4vcH/ASJrrG4dILKoAZpFH2+gvaLws/i9RdHvOrxCygLlxqu+BY7Say0T1iBh4JScsKqnNJOrhr43bw6YAZ1EMRlEIdPdAAAAAElFTkSuQmCC' x='"+x+"' y='"+(y*cellh+27)+"' height='26' width='26' onclick='Editmouseright(3,"+y+")'/>";  
          break;                   
        case 84:    //right arrow        
          retval=        
          //"<image href='data:image/png;base64,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' x='"+x+"' y='"+(y*cellh+27)+"' height='26' width='26' onclick='Editmouseright(4,"+y+")'/>"                  
          "<image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAAAXNSR0IArs4c6QAAATBJREFUSEu1lYFNAzEMRX8nATaBSYBJgElgE9gE2AS9Kh8ZNzlbVxqpUu+U+8/2d5yDLrwOF9ZXBlxLepL0IOlL0oekl/F/VywRgPjnRAXQXQPyOgKzxFE7AryBqB/HLt7djkyArFYW5/u3DCB6skAICMtZkcXNQn0p3gEQ/fsQnjXEpngGIORy2NitEpXiGbAy2ZV5Hh3Fc0s8A1zze0mIsfCCrDKEVvaeX0NnHnUOWhRDw5nw/tvdsmqvDoBvDaGbWLQgPpWrC3DNAfCjbNGTJagDyIZGsRJSzSJHa1EMvQoGR0+mWXRmURQ/Hv/gSe6uE8g5s2jVXX8gEbBnFpWQClDNorJcEbA1i6i9R/jMzGUmHZO7F06GnFw4RMbA8yzylbkV+b+d5FLo3Fm0G/ADeeNeGc+Z+YIAAAAASUVORK5CYII=' x='"+x+"' y='"+(y*cellh+27)+"' height='26' width='26' onclick='Editmouseright(4,"+y+")'/>"                            
          break;
        case 85:    //down arrow        
          retval= 
          //"<image href='data:image/png;base64,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' x='"+x+"' y='"+(y*cellh+53)+"' height='26' width='26' onclick='Editmouseright(2,"+y+")'/>"
          "<image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAAAXNSR0IArs4c6QAAAKlJREFUSEvtlNENgzAMRB+bdBS6CUzSdpJ2k64Ck4AsOTSiorYlnK/mL0py786H6EheXbI+zQHLSYk24/sE6YCTAnxkmndgJSgjdBtzX1TyH3BYwQC8gHpEF2CySvN08AR6BdxV8Aq8Adk/fkE8gJsKiVtxXa9RwYcMD0AeF0hIXC57AXuI6bw4iQAKZLbGUseMAqyP5uu8OSD9d50OCM/YetC8A8tQ+HwFo7gYGWerGzQAAAAASUVORK5CYII=' x='"+x+"' y='"+(y*cellh+53)+"' height='26' width='26' onclick='Editmouseright(2,"+y+")'/>"        
          break;                     
        default:
          retval="";
          break;  
      }            
      //if((type>=24 && type<=38) || type==40 || type==43 || type==44 || type==45 ||type==48 || type==50 || type==55)                     
      //  retval=retval+"<text x='"+(x*cellw+90)+"' y='"+(y*cellh+68)+"' fill='yellow'>STAT:</text>";
      if(type===50 || type===55)
        retval=retval+"<text x='"+(x*cellw+3)+"' y='"+(y*cellh+12)+"' fill='white'>COL:</text>"          
      else if(type>=23 && type<=70)   
        retval=retval+"<text x='"+(x*cellw+3)+"' y='"+(y*cellh+12)+"' fill='white'>ID:</text>"          
    return  retval;
    //set DA AD value by uart or mqtt//   
  }  
//////////end of icontext.js////////////////// 
////////////start of svgpick.h////////////////
//svgpic to change the height of pic windows//  
  let Y=-60; 
  let P=-1;
  let data1=        
    "<image href='data:image/png;base64,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'\
    x='0' y='"+(Y=Y+60)+"' height='60' width='60' onclick='pickLeft(0,"+(P=P+1)+",36)' oncontextmenu='pickRight(0,0,36)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAIPSURBVHhe7d2/SkJRHMDx39VATAkSTJC2kqChUWhr8gWcfAEfo1foEQSnRvEFKmipKegFmhuiP2Ta1W50ub2AFHyH72fRw7k43C/nTIdj0uv1shBGqfgUhEFgDAJjEBiDwBgExiAwBoExCIxBYAwCYxAYg8AYBMYgMAaBQQX5+ChHozGPs7PbGI2uo9WaxWxWLmbXt1iUol7/jNPTuzg/v4qDg+d4e9soZllwK+QnyuHhc7Tbs3h//7uXNp+Xo9N5ie3tRf49y5JihsUtC8YgMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgExiAwBoExCIxBYAwCk4zHe5iLA9I0iWp1GYPBQz7u90/i8bEam5urfLyun3NZtVqan/Xa2VnEdLqb/26l8lU8wZFkWWBvcvivIGRuWTCou05+j5JOJhf5+L9WyHB4HPf3jdjaSosnOFwhMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgExiAwBoExCIxBYAwCYxAYg8DgzmUdHT1FvZ7mN76tVknc3DT/5FzW/v5rNJvzWC6TqFRWcXnZjlptWTzB4Z+CwbhlwRgExiAwBoExCIxBYAwCYxAYg8AYBMYgMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgExiAwBoExCEzS7XY9/Y4R8Q3AzHanQQB1hwAAAABJRU5ErkJggg=='\
    x='60' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(1,"+P+",30)' oncontextmenu='pickRight(1,0,30)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAEPSURBVHhe7dwxEcAwDAAxpzTKI2BDNl0K4gdpMYA/e/Tae98h4/knEYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSMw65/U4IGTdO4KEOFkxfp3E2JAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIESZn5AGNMCVKj9rgiAAAAAElFTkSuQmCC'\
    x='120' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(2,"+P+",4)' oncontextmenu='pickRight(2,0,4)'/>"+
    
    "<image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAH4SURBVHhe7d0xagJBGEDhMWmDhDQpUkTwDjnCegBbvYNHyGHsxANoFfAGNlYBU+QGqdIYdtiFBFbXgOD7l/fBsKMO2zx/7bRXFMUhCeOmugrCIDAGgTEIjEFgDAJjEBiDwBgExiAwBoExCIxBYAwCYxAYg8AYBMYgMAaBMQiMQWAMAoMNMpm859VmsXjLq82597s2bJDp9D2vU4riM/X733mV+1POuR9B6I+s8fij2v3dRxY2SDkRg8FX9SjlfduURBA2SNNEdGFKQgapp2O/v6ueSXnfhSkJGaSehOXyOV9L9T76lIQL8ns61uun6tmU912YknBBmqaj1oUpCRXk2HTUujAloYKcmo5a9CkJFWQ+H6bd7r5xOmrla+WZ8mxEoYJsNo9pNnupHh1XninPRhTuS73rDAJjEBiDwBgExiAwBoHpHQ4J/dMao1FR7ZqtVut8PfccnRMCg/3xmf++8y917tqcEBiDwBgExiAwBoExCIxBYAwCYxAYg8AYBMYgMAaBMQiMQWAMAmMQGIPAGATmdjgcvlZ7nO32Ia82lz53Tf7DDowfWTAGgTEIjEFgDAJjEBiDwBgExiAwBoExCIxBYAwCYxAYg8AYBMYgMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgExiAoKf0AAhmGa2+E6asAAAAASUVORK5CYII='\
    x='0' y='"+(Y=Y+60)+"' height='60' width='60' onclick='pickLeft(0,"+(P=P+1)+",28)' oncontextmenu='pickRight(0,1,28)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAIFSURBVHhe7dy/SkJhGIDxT5siaAsCR1tbT3uDk7ODs7chdCHOXUE3UUNjg+AYFEFTEE7Ge/CAg39axOc9PD+Q79Pz0fLwmmCnzmAwWBVhdNerIDpVVTkhIE4IjEFgDAJjEBg/9sI4ITB+7IVxQmAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgExiAwuCCTyXv9+I9jnT0l3Pchz88v9Xp3V9XrPsc6e0q+ZcEYBMYgMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgEprNaFeQtbcf6CpfOCYHxjxxgnBAYg8AYBMYgMAaBMQiMQWAMApMmyP39d5nN3tbP9otzcT6jNEHi3o7b258yHH6tX9kurse5DPeCbJMmyOPjdb2Oxx/1uktzvTmfTZogT09XZbE4L/3+784pidfjepyL8xml+qV+aEqyT0dIFWTXlMS+DdMRUgUJ26Yk9m2YjpAuyOaUNGLfhukI6YKEXVOQfTpCyiDNlDRi34bpCCmDhM1piH0bpiOc9Xq9h/Ue4/X1sn7sM59flNHosyyX3TKd3tTPD/nPzz01/7M1TNq3rLYyCIxBYAwCYxAYg8AYBMYgMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgExiAwBoExCIxBYAwCYxAYg8AYBMYgKKX8AfTsl7vChhJ3AAAAAElFTkSuQmCC'\
    x='60' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(1,"+P+",29)' oncontextmenu='pickRight(1,1,29)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAEJSURBVHhe7dMxFQAhDAVBOFGRgH9HXIOILWaan35f9jnnLjK+t0QIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsTsmbnvJsCHpKz1A3OJBDn/SC2WAAAAAElFTkSuQmCC'\
    x='120' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(2,"+P+",80)' oncontextmenu='pickRight(2,1,80)'/>"+
   
    "<image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAASfSURBVHhe7ZzNbxNHGId/67Udf8VNbBe7SUzTHFBbqSLyIVJVbpzIfwBXDjkCEseoCpUgRD2BhAQHRCIOSDlW4sAllNKkhxqI2kYNBFIggaKIkECaL+963dllUSuUSpRdyz9530eaZDO7libzzOzMeF6N1tfXV4NAQ8j9LZAgQsgQIWSIEDJECBkihAwRQoYIIUOEkCFCyBAhZIgQMkQIGZ6/7Q2HLTx+HEckYrk5zY9laYjFLKTTJkKqSdd8/L7ckxBLOVheDmN4+D7m5xNubvOTSJh49iyKGzcy2N4OqUbp3vABT0LslvHgQVzJmHTkBAW7V1y+nMfFi13qusYnZG5uCpmM4eYGg7Nni7h0qYNPyPx8HHfvTiKbNVUXzuPIka+UnHX3ieahUtGRTFYwMnILvb0rOHOmiNFR/4X4NMvSnJ+1moZXr0IwzeZLhqGpFHL+x3ri67RX12tq9mEiHq82bbJ7RD2RdQgZIoQMEUKGCCFDhJAhQsgQIWSIEDJECBkihAwRQoYIIUOEkCFCyBAhZIgQMhogpIZIVMPSYhILC/+VElh6AUTC9d0MYsSnPfUpZLMGbt7MY2DgSxSLG+4TOxHC04cGvh6ah+n8bW+JvinCP9dhqwfffBtGR55Dih3uk0waOHXqNvbureOe+suXYXhJ6+sRVaD/U2k1pD7QcOd2DuVyDj9PfISJ3jUcPLiJ/EQBEyqvXM7izm8aUsShXraItbUwVld3rpf3TdrAwKfv3QTtHqLrGo4ff4iens137CHqM6pFrSy1wFCft57GsTj+E5b2RTGWKWGwZwt5+7XWUkF7GqiSxHu93UOGhz/GzEwKra1Vpx78QpuZSXoScu1aBvv3r6hC/vXOQv6NtRDDH6O3cL8vgvHiFzj5+TYK7j0m3hZy9OgeHDr0J9LpqhNa6heaqlRPfu2WcuDAC/Sq106QhBw+/BkuXPjd1/HDRjt2bI+nHjI9ncbY2K/YvXs7UEJOnPhEvfMjTgitHVrqF1p39z5PQp4/j2Jx8Qe0tZmBEnLuXBdOn+527vk6y9q1qwIvKRarolqtbzQfI6apIZczdqwTL0lW6mQ0XEhNtTSjvaKuDKQqGqqvswNLw4WE1Ao/P96FkZECvu800ObmB5WGC9HaDXz4XQeuXMljssOEWgsGmsaPIWpCYLapXpI3kTLklSWDOhkihAwRQoYIIUOEkCFCyBAhZIgQMkQIGSKEDBFChgghQ4SQ4buQjY0wtrb0pkubm7qzr+5nDNZO+BpKev16AUNDvSgUNt0nmgf7JCBdtzA4+IsT5FCvUFJfhMzOTjkb/tPTGSwvt6gCNt/xcnaoz+pqFKXSMjo7N3iFzM0l8OjRj86BkEHi/PlOlbqcI6mohDx50qIKNhuoMxdtyuVWXL2ac3qOrruZPuBJiE00auHevUTgYrPsMbO93T5nUvN1oPcsRPAXWYeQIULIECFkiBAyRAgZIoQMEUKGCCFDhJAhQsgQIWSIEDJECBkihAwRQoYIIUOEkCFCyBAhZIgQMkQIGSKEDBFChgghQ4SQIULIECFkaKVSSWJ7idD6+/tFCA3A31jsON/0NM1cAAAAAElFTkSuQmCC'\
    x='0' y='"+(Y=Y+60)+"' height='60' width='60' onclick='pickLeft(0,"+(P=P+1)+",37)' oncontextmenu='pickRight(0,2,37)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAJlSURBVHhe7dwxTxNxGIDxty7GhIF2Mc6dbRfjynY40xU2wNkQ5DtIDLPCBHOZLR+BOFBInNRBB+LSshGm2qN/De1Ij/C09/ySC3dXlvLkf9w1b1rJsmwQwniSfgrCIDAGgTEIjEFgDAJjEBiDwBgExiAwBoExCIxBYAr7tHd19UfaK6fz8+pwq6Wj+yssyO7u12g0eumofLa3XxUSxEsWjEFgCr9k5cs2X75lkL/f/H3nvGTNKYPAGATGIDAGgTEIjEFgDAJjEBiDwBgExiAwBoExCIxBYAwCYxAYg8AYBAYV5N3BSXQ6E9vBVXq1HCBBrmJ/+Md/U30Zn5ezWP6/LcVZ9TT2t9KvlUDl8LBeyNRJs9m/99RJvjJuY7ReRDudmwWTUyeNRv92fxqVwSCmDnJ0VJ8iSL46TqPWXYrW+6fp3GyYDPJvfxqPf8lauY58mqn3Z7ZiPJTHH5RbuYz224vonWSx8TGdmxGTK2Q+BuWOn0U+ol17fjM6LjnAXdZifPsdsVDvRSudGbP1s1R3WYjb3r311/Fr4SI225djUVofutHJvqejcoA8hyzGxvC540t/GOXOQ+FmM+Ls0+z9b5kGJMjI3vrdh8J8a8bOcXqxJFBBZBAcg8AYBMYgMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDALzIGNA3W41nZ1/a2uj75osagzI71wsyPzMZWlMYStExXCFwBgExiAwBoExCIxBYAwCYxAYg8AYBMYgMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgExiAwBoExCIxBUCL+Ai5prRFXAXVTAAAAAElFTkSuQmCC'\
    x='60' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(1,"+P+",38)' oncontextmenu='pickRight(1,2,38)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAANmSURBVHhe7dyxSxtRAMfxX7q4xKIOWik6VIcuaokllFJwuzh7Y3HTFkcR9W+oUjqKxrlbHIu6FUqHUMTYoR2sg6WIDlYaFyf77vLUMykazV3uV/P7QDT3ohzcN/dyMQ8T6XT6FELjnv0uJBSEjIKQURAyCkJGQcgoCBkFIaMgZBSEjIKQURAyCkJGQcgoCBkFIRPaB1RjY7/svca2sdFsbvft1s2FFmRh4TtSqT92q3FNTDyuKYimLDKhnyFbW22Ynn5qRxtDf/8h5ue/+Pd1htwxCkJGQcgoCBkFIaMgZBSEjIKQURAyCkJGQcgoCBkFIaMgZBSEjIKQURAyMQc5QnZtHWtlt9zciX08Kv/Y7/KRfSxe8QUZ2UNuLY+2whAyGefittgH9BzCtT8WuqkdE6B8v0PYbM2b8R1M2h+LS2xB3GcHSKIXn2aa7Ii10gnX7UTObobrBG+ebwM/03Av7bcJs24au9jGi8jPzqvFFiS332y+FvFgpLRdFyOH6E12YPNDix0IasFqoQPJKM/OKiSWlh6GsupkcLB4w1Un5tma+4gnSbtpHJtp5PIzN2TedOUUsbk4gNkVOxbgzhXwaqAZq5lHeGfHqlG+6iSVKvr3byNxeoqag2SzD28RJMA/UGYqOWOmlMyY9yz2Xnzz6C6N+nbXHYy/BSaX1zHcZQfP2N8rHdh9O2gc92HJmwbrFMRbEnVbHEGCrjloNfEuJF4fYPuqID3tpXh2rBqhBolroZw7t4fumc7KZ+I1B602dpr8fXYGBpXORu/q66bT5h1ZKHeAYXP9n52ymz5zwF5+RfK4HfnQY3jM1dTnXqArX/ZexwtlpkYztb2P8jWsCrEuJa2Y6z3nrx9RqnxtqmW/d2YpaW5mIPDmzN4ij+Fpwfj5Pr33H+Zi4Vs99nu9WINw8OKkAefizyiXp9H6UhBf8IwpXVbHRUHIKAgZBSGjIGQUhIyCkFEQMgpCRkHIKAgZBSGjIGQUhIyCkFEQMpF8hFsotNrRxjE6+sP/XutHuPoHZiH7rz9Tl0qhnSESDp0hZBSEjIKQURAyCkJGQcgoCBkFIaMgZBSEjIKQURAyCkJGQcgoCBkFIaMgZBSEjIKQURAyCkJGQcgoCBkFIaMgZBSEjIKQURAyCkIm4TiOVr/TAP4CZJRI9ojLfycAAAAASUVORK5CYII='\
    x='120' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(2,"+P+",39)' oncontextmenu='pickRight(2,2,39)'/>"+
    
    "<image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAARBSURBVHhe7Zw9SBxBGIa/pJGACaIESYgG/GmEqIGgksZuTyy9MpZRCwUJonaCdp6EaCnanaQ7S9HrAhJQBD2FNP6EmIhIwEhiY5XM7M7qZFm987zZ/Y59H1hudu4P7nG+d769w3uWZf0lwIb76hYwAUKYASHMgBBmQAgzIIQZEMIMCGEGhDADQpgBIcyAEGZACDPyvtrb3b2vRsXN2tpj2t19pM7CJy8hU1Mb1Nh4qs6KGyljYKBNnYVP5EtWff1vGhz8os7CBxnCjDuVrO3tchoefqVmi4+JiU1qbf1pj2dmGmhp6Zk9DpNIr5Dp6QY6PS2xx7JsyfIVNpEWImVIKS4csiTyGSK3vclkrT3mEPAIdcHCQq0tRtLZ+cM+wgJCFFzyBEIUXPIEQjQ45AmEeAg7TyDEhzDzBEJ8CDNPIOQavHkSFBByA948CQIIyYKbJ0FlCYRkQc+TILIEQnLALVtB9CYQkiNB9SYQkiNB9SYQkiNB9SYQcgu8vYkJKYaEXNBkKk0r82fq/Ip4IkMrK+I+daQSF84dQwdq7oDeOTMK57UuH9d1TCnxuLkh5/QS9/k+71lITF/rCnyFpEaaKJauE6NK2pq1KD7i1GWHSjo/36OO236oUpK1R4dpi2Jvy9SkOUzmCbOS9ZBWPwtZVd9osktNZUPK6NuhUyGj572aM4xcFZlMuTojGh/ftH/Jedcjkdgw9TMgWWY+UfOvFv+/WFlerD9ihTTR6KI+R7QcqyGaT1MHuc91Xqtuv91ZTbqAr86YMuq+gJCl0RQsQ/3D0gs6z7pKzmguBBmm4bnLWnxCq99PqPnNMcXVlJdqa52qxW1p05FnE2CeWMz670d1cucl5wpx8BQisFdJ6Q51eHdTCjvAY+20JTcBqevFmUDfXckdl9x5FQq2QuQq+ZippOrXR3QVn15KaDTeQodCXG9AUvT+w9ssFgK+QgSpkefiw96j6lI14UsZ9cw6q6nXcA8icWVI9O1voTArpGpdNXvqEB+Y3RiKnoFIZESf1vD5UkbLYpVkRaymuJQi38/gSpEy3J5D5obbIBaSSP/6/TbIzHBXhxQxNvbSHhca1iWLEyZzQwdCmAEht8REkOtASA645cpUkOtASBbcJrDQDeB1QMgN6E2gySDXgZAbcGVITOaGDoRcg5ShN4FBASE+mLx4mA0I8WD64mE2IMSDnhumew4/IETDmxumew4/IEQRZm7oQIgg7NzQgRBB2LmhE3khHHJDJ9JCuOSGzp2+MTw5eUDp9FM1W1xUVFxcypAlqr+/LdRS5RL5/7kokV/Hhl2qXPIqWclkjRoVPxxyQyevFQLMgW0vMyCEGRDCDAhhBoQwA0KYASHMgBBmQAgzIIQZEMIMCGEGhDADQpgBIcyAEGZACDMghBkQwgwIYQaEMANCmAEhzIAQZkAIMyCEGRDCDAhhBoQwA0JYQfQPCusPVHDnFgkAAAAASUVORK5CYII='\
    x='0' y='"+(Y=Y+60)+"' height='60' width='60' onclick='pickLeft(0,"+(P=P+1)+",23)' oncontextmenu='pickRight(0,3,23)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAN8SURBVHhe7dxdSFNxHMbxxzmHY6U2y3xL04GFaFKR1E2hwaxQiYQgyFszL4LwoiK89kqK0KswgropQggJiUSCqIsgvel9WNmLZa00c2xOrY7rEL1cadvOk3s+MJT/znT45bc/4xyXVFlZ+Q1Cw2Z+FRIKQkZByCgIGQUhoyBkFISMgpBREDIKQkZByCgIGQUhoyBkFITMgs+HBAI2VFRMob7+AyYn7eZqYkhO/oZg0IaBgRXw+VxwOr+a90TPgoNMTNhRVTWO06efIDU1+k+I3Zs3DjQ2lsHvd8QkiF6yyCx6Qrq6HhkjDLS3b0BPTwHc7rB5xNIyNzd/S0Jt7Su0tj7UhCQaBSGjIGQUhIyCkFEQMgpCRkHIKAgZBSGjIGQUhIyCkFEQMgpCRkHIKAgZBSGjIGTiek793fM0nLx+BfuLzIWfNqEjJw9d2TZcGrqKLebq3+wIDlXgzIFsXCmcgdtcjaWlf0498hvX4eKWPdhavQue/DqMYhCtb0fR4p9Fc40XNcZtx/ZdqNtXFnnIYHcDSjfOr1dj7/FMDMQphhXiPyE3jAkpnA/iQefyWSx7lwpf9z2MbLPhWu5GHCsPIc84NhS0IW3la/T23I8EOdj5BWuyfvycePpzQoaHnWhrK8bu3R8RChl/gCizPEjopQuHbvfh8OocI0g5fZAHD1w4dy4XHR0+84josnhTt2M88MmIEQKelaF52XQkRiIj2NTT8fJMNXaeD6B4lblkYJ2QJbyp18GdVYUgPqPgyAu0vHfAHzkgsVn4kjWHkhwXPKc2G98P4ahvCm+fRn+T/N9Yu4dkhlF6Ng8FdzyA8yZG++x4/CLJvDMxWbypG5tYfgglTaUoubsWWN+LkVthPBxOrP87+VVcg2QXTaK7af4NXiEuuGeRnmI8AWMgkvOmUdRWEnlDWNOYglLPLFKNDTMcyI2snbhszYZuBcsnRH6nIGQUhIyCkFEQMgpCRkHIKAgZBSGjIGQUhIyCkFEQMgpCRkHIKAiZf7rqZGbGjv7+bIyNOeFwLN0PMwuHbcjICKOhYSTmV50sOog+UU6fl5UQFjwhEluaEDIKQkZByCgIGQUhoyBkFISMgpBREDIKQkZByCgIGQUhoyBkFISMgpBREDIKQkZByCgIGQUhoyBkFISMgpBREDIKQkZByCgIGQUhk+T1enX1Ow3gO5YhUNAvzBX6AAAAAElFTkSuQmCC'\
    x='60' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(1,"+P+",60)' oncontextmenu='pickRight(1,3,60)'/>\
    <image href='data:image/png;base64,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'\
    x='120' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(2,"+P+",43)' oncontextmenu='pickRight(2,3,43)'/>"+
    
    "<image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAEPSURBVHhe7dwxEcAwDAAxpzTKI2BDNl0K4gdpMYA/e/Tae98h4/knEYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSMw65/U4IGTdO4KEOFkxfp3E2JAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIESZn5AGNMCVKj9rgiAAAAAElFTkSuQmCC'\
    x='0' y='"+(Y=Y+60)+"' height='60' width='60' onclick='pickLeft(0,"+(P=P+1)+",4)' oncontextmenu='pickRight(0,4,4)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAGdSURBVHhe7dwxagJBGEDhmbRKJI0IISewW9htYtqV7aL1Wmjh/aw8h3WisLmEIQQ2sGzu8GZ4XzP/X79qiplY13UfMtG217DbXYd5va6HMzUP4ykIg8AYBMYgMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgExiAwBoExCIxBYAwCYxAYg8AYBMYgMAaBMQiMQWAMAmMQGIPAGATGIDAGgYmrVZPNK9z9/iMcDp/DnOor3Ni2b9kE2Wy6sN1+DXOyQS6Xp2yCzOf3sFh8D3OyQfo+ZBPkX9dNwvH4Om5piefzc3ZBTqeXcLs9jlta4nL5nl2Q2ewnTKe/45aWrP46yYH3EBiDwBgExiAwBoExCIxBYAwCYxAYg8AYBMYgMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgExiAwBoExCIxBYAwCYxAYg8AYBMYgMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgEJjZNPj9b5yAWRWEQkFiWpUFAYlVVBsEI4Q+ecy/zCntXdQAAAABJRU5ErkJggg=='\
    x='60' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(1,"+P+",8)' oncontextmenu='pickRight(1,4,8)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsQAAA7EAZUrDhsAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAGPSURBVHhe7dwxbsIwGEDhPzEwtEJKFg6AOjEwoahVr8YBOFnvgAqnYGCoGhe5rtoLNLzhfZL1O/L4JGdzMwxDDmG0dQrCIDAGgTEIjEFgDAJjEBiDwBgExiAwBoExCIxBYAwCYxAYg8AYBMYgMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgExiAwBoExCIxBYAwCYxAYg8AYBMYgMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgmvX6NR+PbzGb5bhcUmy3z7FafdRjTa1NKeJ0eigf5/NjpOSrsfdUrqyfCMa4P/8hMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgExiAwBoExCIxBYAwCYxAYg8AYBMYgMAaBMQiMQWAMAmMQGIPAGATGIDAGgTEIjEFgDAJjEBiDwBgEpgRZLL4fDJjPxzL/GsfRNeFqNpuXfDi8x/XalvdO9vunWC4/a46Ivu/rTlNodrsht22+1Wnid9bTm67r6k7/L+ILmgE2QibwXd8AAAAASUVORK5CYII='\
    x='120' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(2,"+P+",2)' oncontextmenu='pickRight(2,4,2)'/>"+
    
    "<image href='data:image/png;base64,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'\
    x='0' y='"+(Y=Y+60)+"' height='60' width='60' onclick='pickLeft(0,"+(P=P+1)+",25)' oncontextmenu='pickRight(0,5,25)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGcAAABlCAIAAADf62qlAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAASmSURBVHhe7Zq/ThwxEIdpkhSRoqBIaXJFpJOiiFQ09wgpeAhqah6CFtFS8gAgRENPCdSU19Fcdy9AZuzZ8Xj/QHbO9h2++WQlWu+ed/yt77dC552ZMYa/DrM2DrOmIaG1/fvlzstLaMuHfTozm5097IpTu/en1I/cTFzn5JqOARxKfHxvHj6LDU+dTpdxJ7fmg1TP/MYdNVzP3WXzPToGcCgsiU71NFkbksian4MsBafq7fjqxY2dpiAFD3eXcE34uLDmRhYGXc9yekYHCD6SuAdxLuJhEVSz3IUxg83GmgCfU0u3JIk15yUuLuCkxDX5pdd4xAsm19FlwVp05QC91qizc3e0Nt/Df/kj67HmlsPQPXyVdBAQZXlr0ZVirfVJb9FnDUdw4+ON5FJt7iIKWI+11yY2tAzFZBpronphzY/QRIycP9NjjcfsnOVnE/rftzU/JZyJtNaAlzX64gG71lgNEksRp5oa1mMN7zp4j2gCAVGWsNYM1WeN6TykjjUcPCj2ralB1oMfhFuvx9rAgjp7mGApfSuRyvUH0hopmMzD22DKp4jOJNvW4gEBebvr6Cm6xzOfrMUarREpDoujUpxTOQ2claipPUlaKY01mLCcgBst/j7G1voeofg2xNaomM5zLWMN8Xa4dZ82n4pL7F8a4Rsaf7Z3UQtrQpAgqGxbo7LXZm2LMGsaxlk7P/+xme3w8A+VWIQR1h4fv0T5sknt6ekzVVmESqxBu7r6ToXmZ7Q1+JeON4a7u69e3MnJT+rKTA3WDg72F4sPXlyZgKvBGnB8/MtbKxNwlVgD4E3qxRUIuHqsAcUCriprxQKuKmtAmYCrzRpQIOAqtAbkDrg6reUOuDqtAVkDrlprQL6Aq9kakCngKreWKeAqtwbkCLj6rQHJA24rrAFpA25brKUNuG2xBiQMuC2yBqQKuJTW6Efy+Ldx/K3bFQot7BloXdazPyUXSQIuoTX86X+5BHHR9gPA2QydaO3tPZ65SBJw6azRzHGHRGsTVY+1t/d45gK+pLe337y1xeIjHCraxcU0jTVUw9tPunt+OtaiHSgFrXlfK7ZU1l5TMGDN9Xu/W2ot2k3lAk58SYesedd4ZUFrALxA/eThu0ZdI8FUW90aioifhtQ0bK05VdAavDp9hfAypa7xJLHW2SOHFkLPK9ZoYfbs8cwCvDS9MniNwsuUeseTwFpLiiPsTQRetTa0xzML8FeBtwZ/J1CXitWtRYIYNoWOXKHQ/OprW/Mj5Le2epwxq1t7HySJM2YrrKWKM2YrrKWKM6Z+awnjjKncWto4Y2q2ljzOmJqtJY8zplprOeKMqdNapjhjKrSWL86YCq3lizOmNmtZ44ypylruOGPqsVYgzph6rBWIM6YSa2XijKnBWrE4Y0Zbe37+BM9zc9rlJa2yAnHGjLa2sa1AnDEjrB0d/W4VujkNFh1VWYQR1gzGrGkwaxrMmgazpsGsaTBrGsyaBrOmwaxpMGsazJoGs6bBrGkwaxrMmgazpsGsaTBrGsyaBrOmwaxpMGsazJoGs6bBrGkwaxrMmgazpsGsaSBr/j/jP/HuzNo4zJoGdDab/QOSPWbSTiFQVwAAAABJRU5ErkJggg=='\
    x='60' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(1,"+P+",26)' oncontextmenu='pickRight(1,5,26)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGgAAABmCAIAAACodEOGAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAALiSURBVHhe7dkxThtBGMVxF1EEJUphiTKhpYvcRApdTkHJETgMtEicAfkSgHwDKBBUFHsA583umJ2sHeN9ETPfN3l/jYR32LU8P+0sSJ78UlSCIxMcmeDIBEcmODLBkQmOTHBkgiMTHJngyARHJjgywZEJjiwf3O3tl6urbzZH/IhjygR3ff11uZzYHM/P++fn3+MH3bkccJbVumER7k3t6Wn/7OxHnLURvIzCWVZDRuGMqyGLcPbVkDk4F2rIFpwXNWQIzpEasgLnSw2ZgHOnhsrDeVRDheGcqqGScH7VUDE412qoDJx3NVQArgI1lBuuDjWUFa4aNZQPriY1lAmuMjWUA64+NfThcIza/Chc0hxfxuOk7ler8TCP0+jyfrpcHt3Eo67ZQ3vOzWN/yZ9jcP6IPhaOu9fCOptps5zeXcSZrnb9yeTFcYM3f5x1R1vgktZnyP4JbvDV7GAsFgeE2mptJ3dNjxJqmYZrDjdgpPQE1125fTTNp3HPNVi0m3QAEQ43bN7g29yf4FVtcBjYsPGK9+shBots9+9muO7G9AQXf/4l3GgvL3vj7MJ+7J9iAWu1W/8jOAQ7POB2t2sXH05ORvII27pV2+ddLXBojF26T7vCOuPMe38cBndraH3GERza1S5VWJXu0I3/jiTQ7bbt78p+Fye5gkO72G1+ig00w2F4k26sEbRYbycM1ZA3ODT2eWe8fHCoJruscKgau9xwqA67AnCoArsycMi7XTE45NquJBzya1cYDjm1Kw+HPNqZgEPu7KzAIV92huCQIztbcMiLnTk45MLOIhyyb2cUDhm3swuHUrvF4mDwhXfZMZ8f2oVDqZ3NYRQOwe719fPg4xoZuO/swqHT05/xVRXlg6sswZEJjkxwZIIjExyZ4MgERyY4MsGRCY5McGSCIxMcmeDIBEcmODLBkQmOTHBkgiMTHJngyARHJjgywZEJjkxwZIIjm8wUleDIBEc1m/0GWfEVZ3zF5tAAAAAASUVORK5CYII='\
    x='120' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(2,"+P+",24)' oncontextmenu='pickRight(2,5,24)'/>"+
    
    "<image href='data:image/png;base64,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'\
    x='0' y='"+(Y=Y+60)+"' height='60' width='60' onclick='pickLeft(0,"+(P=P+1)+",40)' oncontextmenu='pickRight(0,6,40)'/>\
    <image href='data:image/png;base64,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'\
    x='60' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(1,"+P+",41)' oncontextmenu='pickRight(1,6,41)'/>\
    <image href='data:image/png;base64,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'\
    x='120' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(2,"+P+",42)' oncontextmenu='pickRight(2,6,42)'/>"+
    
    "<image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAF4AAABTCAIAAACZLifnAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAIjSURBVHhe7dlLcoJAFIVhd8ECwtQpU2euEadugnIVsgWs7KAXYO7tvjQonooYiLScv6iKPDTwVbdRsinYoL1vE36wfgGINA8iDYw0MNLASAMjDYw0MNLASAMjDYw0MNLASAObhuZ63Sx2sVMcH2lgU9LYymIiDYw0MNLASAMjDWzxNKdc917sfxfSoc5kS3OyVTvAL67e+U1F026JS/PdHdYueeWPRoXDbGV8/0LjMtddxu7s9OBA45niLi/SQ/TP3R5sxaouUfCXkqDZni/ZufSr5da5vHGBRi264SPJ3v5YWANNVWfhemSYuLqQgaMidxDaLdYaaA46WOQiZTbJ8NE5hWna8SWtgiagnCLQYEKVRSUiK5xQcnk6lVzm32UjTe9tWFH0RbrZJK2EJly8v/KORpMD/NPVyD/urvzDad4XaWCkgZEGNg1NeJXXluPxKzywl1xMfzwr0sCMxtZejTQw0sBIAyMNDJ+EficIe+MiH/OHd7Ce/Ow/qvDrbGV8c9O0De4/xK9Cz38nGluqNH6wxNsUs5QuDdg4XQnTyFSSZ800m6RkaexezO0dz0lLlKYnorevZplWKdLc/7XWmTXDm3EiNO+INDDSwEgDIw2MNLAF0SxzsVMcH2lg09B8ZKSBkQZGGhhpYKSBkQZGGhhpYKSBkQZGGhhpYKSBkQZGGhhpYKSBkQZGGhhpYKSBkQZGGpjRhB+sXwAizYMUZr//AXQlQh1y7lwDAAAAAElFTkSuQmCC'\
    x='0' y='"+(Y=Y+60)+"' height='60' width='60' onclick='pickLeft(0,"+(P=P+1)+",44)' oncontextmenu='pickRight(0,7,44)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAFoAAABTCAIAAACQxYedAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAJ6SURBVHhe7ZixShxBHIePEBGDRQhYBVIkhY2l3CPcI/kOvsFhKda2PoKdnQ8ggiA22thYmC/3Gyb720KyZpcMm9/HsDfz39m5+X/MDje3WIUNyw0LfQRJiY5CdBjRYUSHER1GdBjRYUSHER1GdBjRYUSHER3G+3W8vi6aLWWKw4kO42916Pl2iA4jOozoMKLDiA6jIR0XF1+J3NzslvZqdXX1hQhxNdVBhVtEjo8Pnp8/1qDK7e2nXoQ+9NQgb6P+ZYrD0SCj6WDej49bmvrR0eHDwzZ9pIP8a1ay0BVHHzrzSGlvoIOs/Tlt6SAlcjg7+06TK03sEFf+8iK4W8XBbHVcX39WDlypEyHeSx56gmar4/z8293dDtlypf6GDiJaRzBbHRJxebknKdJBpa6F9Xqf8r+8LKREDk9PWyRDXTq4S1BbKSJeXj7wrOJizjqUMM2uDnXQU3hh+VCp2c5QRwtEhxEdRnQY0WFoVicnvw9Hg8rp6Q8GiY5S5qmjTHE4GiQ6ChokOgoaJDoKGmQcHfUwUot+nnMlrsOrfrbz63vzxPjoe8sUh6NBRtPBYURpA8eNegyhLgW1MhHt6qBSj/BaFBzbuNZD/RS0q6O7OgAL3f97JqItHd29o+4XAjsEJ31TQF9dpjgcDTL+6ugtDYIsjfV6n2D9+2MKGtUBLAStBW0cstDrMzrt6mCzoHl/v4OL7jvCwiE+0YbakI4WiA4jOozoMKLDiA7jH+tos5QpDic6jPfrmCXRYUSHER1GdBjRYUSHER1GdBjRYUSHER1GdBjRYUSHER1GdBjRYUSHER1GdBjRYUSHER1G0aGPICnRUfglY7n8CR9pDIFcvVP0AAAAAElFTkSuQmCC'\
    x='60' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(1,"+P+",45)' oncontextmenu='pickRight(1,7,45)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAEJSURBVHhe7dMxFQAhDAVBOFGRgH9HXIOILWaan35f9jnnLjK+t0QIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsQIEiNIjCAxgsTsmbnvJsCHpKz1A3OJBDn/SC2WAAAAAElFTkSuQmCC'\
    x='120' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(2,"+P+",80)' oncontextmenu='pickRight(2,7,80)'/>"+
    
    "<image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGsAAABkCAYAAACB6c7ZAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAQrSURBVHhe7ZxNaBNBGIY/RbFYIy1RJLWHQPEHEaFNSY5eSk8leCvSo160IL2Xeim5S6H1UMVDEc1NSo4F6THBWBApEinuobaHEixuPEgFndmd2mSbNJua7vbF94Ghs5NmdzPPzDezzLAnksnkbyHHnq6uLjlp8gQAygKCsoCgLCAoCwjKAoKygKAsICgLCMoCgrKAoCwgKAsIygIitCWS+/e/mlx4PHt22eSOP3qJJBRZAwPf5fHjLxKL/TQlwWPbp+T160swwkJdzwpTlCYS+WVyOITWs54+/eTkHzy4Lu/fn3fyQZHPF5y/8/OX2bPI0UBZQFAWEJQFBGUBQVlAUBYQlAUEZQFBWUBQFhCUBQRlAUFZQFAWEJQFBGUBQVlAUBYQlAUEZQHxX+9uKhbPq2tHnPxxp6Oj4/+WhcTCQh/DIBLc5MlNnuQooCwgKAsIygKCsoCgLCAoCwjKAoKygKAsICgLCMoCgrKAoCwgKAuI0NezSqWzUqmccvJBoa+vQVvPCl1WmFCWT/Rb0RIJ2xyFg16lRiFUWaQ1uKwPBmUBQVlAUBYQlAUEZQFBWUBQFhCUBQRlAUFZQFAWEJQFBGUBQVlAUBYQAS0+7sjs0ooMet5iYBf7ZejhaSc/mS1IOtonM0NReemUGKY2JD/yQ949uSLjr0yZYmzuszxKfDNHmu59/+N+d11lemUx1SMZt1Th3s+1krn+3bIsTaxJvZcsVN9jLRXJ5lclbo72rrH3W/d917kf8dyLP4JffLRuSCqVdNOTPpHEiizN7ZgP/aIro6BEdaofbc6lU65TBicKdc7XLba9LulsxRw3xspVnc+k+qI052Q01S/v9M4E53fVCrDtbokkLJm9awraQHhh8FVU3loikavfZcwU+WJqS7Va3Ys8rXO6R2aKuoK2ZNIUuXTK2+VekfhmWyuuKaWYEvlNBu80byR+gRuzJm+qsGbFasOd4eXDmFiyLremTMEuSuSi1d6Ka84ZGX/eJ3YbG0l4slT8TquAby1XjVGRNXmULzjvqfibnDFnlx3piZrsAURj+0Nr5k3ziouPeK6tUuthugonerSvkQQrK766VxFKgh4jRqfNZxpbTTA8Y0Yqp0JYO9ituHvlhmG3tTHLH24jWZWst7cfgvAmGCrViPLFadkom+wBlDfrV7BTcar3pttQcb4xY3P8duNG4he4MSvzsfFkYWxuU02le+VDo0agKu6FmoTEb2/JBVMUBJnRG2LpRnLTFBwSOFkyfdGdZU1s1M761Bion7us3MHPMM4kJLIu8UDfXHdOFnUjiVePv62DJ0uFwvGhpJqm/5B01UTAfXD2E1rdiqtHaxMM/VBsHvSdsdjTeDy4M9V/g9unQeD2aTAoCwjKAoKygKAsICgLCMoCgrKAODE8PMyHYgC2t7fZs3AQ+QNxkIJD863DygAAAABJRU5ErkJggg=='\
    x='0' y="+(Y=Y+60)+" height='60' width='60' onclick='pickLeft(0,"+(P=P+1)+",50)' oncontextmenu='pickRight(0,8,50)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAASPSURBVHhe7Z3PTxNpGMcfNjGEpE2gh63GUBPLRRMsh80euHibNh7pcT0qnBv88TeIIZxVTmr2VrwZOjcT44F4EM26FzARwioXMGGMIR7Y533nZXdmnNKCdvgSv5/kTd95Gaad+czzPO9khtLned6eEBh+ca8EBAoBg0LAoBAwKAQMCgGDQsCgEDAoBAwKAYNCwKAQMCgEDAoBg0LAoBAwMrlBdfXqqusdD48fl10Pn54LuXRpS27c+EuKxS9uJFuC4JQ8eVI6MVIySVnHJcOQy311vZNBJhFy9+5L27958zd5/bpg+1nQavn29dGjMiOEHA0KAYNCwKAQMCgEDAoBg0LAoBAwKAQMCgGDQsCgEDAoBAwKAYNCwKAQMCgEDAoBg0LAoBAwKASMvocPyz196sQ8AuR5/9g+nzrpTN/enmT21RoU0hmmLDD4oBwYjBAwKAQMCgGDQsCgEDAoBAwKAYNCwKAQMCgEDAoBg0LAoBAwKAQMCgGDQsDI9AbV6mpePn8+ZftZYN7bcKLuqWcp5LigkATm65kqlW23lD3m1vFJIRMhpHtY1MGgEDAoBAwKAYNCwKAQMCgEDAoBg0LAoBAwKAQMCgGDQsCgEDAoBAwKAaMHN6h25U7zmYzl3KIjWL4s9Vv9tt+Y96U2NCr362ekaUcc0++k5e3Iq3sVub3gxpT6zLJMVjbdkqEYX8f+3op2RmSxel7mwlEl/Cwjq+69Jz5Ic+qNJD6aJfr50knZryC5D5/kQWtJCinbsvtQ/lXXH5CarlNy40l6FyHrv0u16oXt3qhI5Zk0Z3bdD7vFHARfZeT1QLttmebnZWzKT2yvKEGwIrX5T265PWt+ZFuuHSjDiGypjO3IPmlb3H4jk61luTPh1uuKQbke2UbVH9ExcyKFy9mkrIUz8nxdJFfekrob6orpDT0jTTREz3pl9rzcXy5KrrIhDTckkpfnL3Tnht8f8gB1pnFFo8pEw7VBNxIyd+2yvAo2ZexK55OgW6BrSOOCpqH1c7H0tU/z1jlZkxW5OO0GDCpqcf3HHiCThi4Oa1S9SKRXS7/ctifBVuTE+D6yEaI5vpbcqZwJd9/+cf9/zdaBfXbl9JDrHkChGE+Dc09HJegQJSUv8b7a2qbTiS/S+asOduT0D4rK3gkZXvp/h/VAm7x9fdb9zGBSQDSXmmbz6Xdi06NGyR8f2qbHQ9eQDMmmqGuLyeiKfvnYxaNcW5vfHkgbJRqBtWg6OyoLAxI+/3gQeflo06quG9iBIwNdQ+b+bl+k6zPvdeo4Im/TRGuU/KlFvzS+0UW66cSgvNUJSWk8LeJ0Fjhu6lzBTTrCkyhX+Pa/0pUKOm3fHkipQ3Gghcjs2XAWM/UuXjS1JpnrkjU/MfuKYIt+bkVKaRcdh2Q/4iYTU+rGvLku0SlrZPYVnkRL8iAanbaG6mzxaXyWlga2EDOLqXs6xd3Ri6lIEbYXj53S4KAsapSkcaiibtCIq1d1ijsUqYva7MVt7EJU0ZmeqYWx90i52G0HHyUFAzxCfj4oBAwKAYNCwKAQMCgEDAqBQuRfylSueSt1wcMAAAAASUVORK5CYII='\
    x='60' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(1,"+P+",55)' oncontextmenu='pickRight(1,8,55)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsIAAA7CARUoSoAAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAEPSURBVHhe7dwxEcAwDAAxpzTKI2BDNl0K4gdpMYA/e/Tae98h4/knEYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSIwgMYLECBIjSMw65/U4IGTdO4KEOFkxfp3E2JAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIEiREkRpAYQWIESZn5AGNMCVKj9rgiAAAAAElFTkSuQmCC'\
    x='120' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(2,"+P+",4)' oncontextmenu='pickRight(2,9,4)'/>"+
    
    "<image href='data:image/png;base64,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'\
    x='0' y="+(Y=Y+60)+" height='60' width='60' onclick='pickLeft(0,"+(P=P+1)+",46)' oncontextmenu='pickRight(0,9,46)'/>\
    <image href='data:image/png;base64,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'\
    x='60' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(1,"+P+",47)' oncontextmenu='pickRight(1,9,47)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAFYAAABRCAIAAADHMcYYAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAAITSURBVHhe7ZpBdoIwEIa5hQeoW7dsu+OMuvUSPk+hV9ArcAD7DzOEIVhLqgVq/u9lwYyRZj6SGH0tyuyhgrKosocKqIAKABVQARUAKqACKgBUQAVUAKggXcF+/4FmwWJ4ZlTJCm63As2CxfDMqKiACqgAUAEVUAF4mYLDVfLa6vPnMCmt3uz0BbDd1CF/LV1yddpa1ITrg124+2jSoXkLEnmNAim1K6+83IrLUa4kH8pzeS3JrqvPU912e6Sgy/dvK8ytIAy0ZXde6USIxorwbr6rcJyC6rjuTaj5FQwGFPhmFshjD4ulQTLy0jgFy5sFTgGev3bQjIxVQ2027t8p8LfqTTqgeQsSeYWCMNBAK8U9LrcRPFgI0u3nWTBkbgVaklsLIeyV6suQ63vbYX+CdLddvgLQLQG0Vkf0tJs+oRKZF9bfzwifD5PrXyiYFyqgAioATynQN6c2e/diiIaX1OJ4ZLO/vBii4SU1LoSp9gI5IJh1/ahvjkOWsSYnIhwrB4ffMegdLEhkAgX+8NecnX2RcuZx4XsqiIrEGXFb7sI5LwcFcih2Xx9ispgFqCp3BYOFgK2x+7EgCwXcDhv8R2C/wjsKQs/oS/QjtL8FiUyj4M+hAiqgAkAFVEAFgAqogArApAr4r5dvCBVQARUAKqACKgBUQAVUAKiACqgAUAEVUAGgAiqgAkAFVEAFIHsFVfUFqTI+ZmQh2wIAAAAASUVORK5CYII='\
    x='120' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(2,"+P+",49)' oncontextmenu='pickRight(2,9,49)'/>"+

    "<image href='data:image/png;base64,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'\
    x='0' y="+(Y=Y+60)+" height='60' width='60' onclick='pickLeft(0,"+(P=P+1)+",62)' oncontextmenu='pickRight(0,9,62)'/>\
    <image href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAF8AAABTCAYAAAD5jtuOAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsQAAA7EAZUrDhsAAAASdEVYdFNvZnR3YXJlAEdyZWVuc2hvdF5VCAUAAARkSURBVHhe7ZsxSBtRGMc/S6FgXQq2FBJNwEEq2qFDsNYKIsTBSRSkuIk6dAgURHRzFBeps7iF0mJxcqgg0iitODhUsXQQTGKgSKAOGuhk33f3LmqqzeXde/eF6/eDeLl75Mj98vJ/5/eRmlgsdgEMCTXxeJzlE3FHbhkCWD4hLJ8Qlk8IyyeE5RPC8glh+YSwfEJYPiEsnxCWTwjLJ4TlE8LyCWH5hBhtpiSTn6G+/rfcCyZjYx2QydTJvcowNvMjkbPAi8/n7ymLR4zN/L6+LCQS32Fj4zHMzj6VR4OBrmszNvPb2n5Z2729B9Y2SOi6NpavgHNt+/tVKN/Je6+ZWI00Nl5eWzrt7dqMyG9t5chxgxH5nPfuYPkVoivvEe3yOe/do10+5717tMvnvHePz/LzMLO8BjNdchfpOoBPywfQI3ft/TX7MZmXBxH7tc7Y5TkKMPIW953xK+eqcrTK95z30TQsJs7g/UQcegfFY/scRqI4gIJ3IbzSaR+faIZwYkeO2TxPnMAmjg22wLo8phudiy2iVb6evD8VC5t8morA0pHYdh3BUCgM75K19vGjh/AldwodLwr2viC7EjUmHdG92CJa5XvOxKMIjC6ExSy2o2Vx2Jbb1HAm/h7DZDF2tsSHYQ0VOc7KD8YQJtay6pKPpFqK0QL9W1a2H2bFTMs1w2srVi4fo843wQeqWr67vK+FTE7kc7uzkIosHziWzwVisS0upFa0yOepR/A19AOm5TcB6Zn0d2HVnfeINvnu8r4WluabIRvblfGxD7ATlmOCVBQyA1eiJfcMZlI4UA8z8ptgj63By21zC2spJvIe0dZMmZr6Bt3dP2Fh4QmsrjbIo8HAVGOo5uICtHayvPQ0qxVTvWitC26hcDfQ9RzdaIkd7teqoWXmm7gNqxZMXhvLL4OJW0wHz/K5fq+OZ/lcv1fHs3zOe3Xo5ZfW88vQNLwj/8sVr8ES9PL10rJOTOY94km+73kvZE/3g6z3my0vmM57xJN83/O+8RwaoA7SWONHsAQ9GLNr/prxI049yVd7gyXtwHZ5uMjN7UIrbhJYAZV1fWwxXosdp51ob+3Xl0bSba3Ivwmg/JJ24GAnZEJXSsr/aBceJmPQu4AV0DDM4dhcvf2SEp4n9gHm7Xr/3M4pDL1JQ5M1cvu5b8J03iPK8pXyvrQdiCXmj1dKyi7aheXIrrQWY2j9QzNkQ+dg+a3g3H7kPaIsXyXvrXZg7j7cFtFu2oXluK2dWMm5/YgcRFm+yhu02oHOTLwBk+3CSs4dSPlWO1DMvlfFdqBYAK1FVGKyXVjBuf3Ie0RJvvr9fWk78AQ2rUXUwWS70N25/cp7RKmez/V7PSjNfL8ykQI/r01p5v8Pv68dH+8wHjsVz3wnE4OMH3mPGPsdLlMe5VtNxjssnxCWTwjLJ4TlE8LyCWH5hLB8Qlg+ISyfEJZPCMsnhOUTwvIJYfmEsHxCWD4hLJ8Qlk8IyyeE5RPC8skA+ANgEbiren9QQwAAAABJRU5ErkJggg=='\
    x='60' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(1,"+P+",61)' oncontextmenu='pickRight(1,9,61)'/>\
    <image href='data:image/png;base64,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'\
    x='120' y='"+(Y)+"' height='60' width='60' onclick='pickLeft(2,"+P+",48)' oncontextmenu='pickRight(2,8,48)'/>"    

var modify="";     
svgdata="<svg class='svgpic' xmlns='http://www.w3.org/2000/svg'>"+data1+"</svg>"                
//modify="<polygon points='"+(x*60)+",60 "+(60+x*60)+",41' style='stroke:red;stroke-width:1'/>\viewBox='0 0 220 220'
//"<polygon points='"+(x*60)+"','"+(y*60+60)+"' '"+(60+x*60)+"','"+(y*60+60)+"' style='stroke:red;stroke-width:1'/>\
    
function pickLeft(x,y,z)
    {var textd="";
    var data=""; 
    modify=  
    "<polygon points='"+(x*60+1)+","+(y*60+59)+" "+(60+x*60)+","+(y*60+59)+"' style='stroke:red;stroke-width:1'/>\
    <polygon points='"+(x*60+1)+","+(y*60+1)+" "+(60+x*60)+","+(y*60+1)+"' style='stroke:red;stroke-width:1'/>\
    <polygon points='"+(x*60+1)+","+(y*60)+" "+(x*60+1)+","+(y*60+59)+"' style='stroke:red;stroke-width:1'/>\
    <polygon points='"+(60+x*60)+","+(y*60)+" "+(60+x*60)+","+(y*60+59)+"' style='stroke:red;stroke-width:1'/>"   
    data=data1+modify;
    svgdata="<svg class='svgpic' xmlns='http://www.w3.org/2000/svg'>"+data+"</svg>"
        document.getElementById('SHOWSVG').innerHTML=svgdata;    
    comv_icon=z;
    switch(z)        
    {case   2:
        textd="Link line";
        break;
    case    4:      
       textd="Vertical Link";
        break;
    case    8:      
        textd="right up Link";
        break;
    case   23:
        textd="Link to relay";
        break;        
    case   24:      
        textd="Analog output";
        break;          
    case   25:
        textd="Analog input";
        break;
    case   26:      
        textd="Constant analog";
        break;           
    case   28:
        textd="Normal open rising edge trigger";
        break;    
    case   30:
        textd="Normal open";
        break;
    case   36:      
        textd="Normal close";
        break;    
    case   37:
        textd="Timer";
        break;
    case   38:      
        textd="Counter";
        break;
    case   39:      
        textd="Latch";
        break;                        
    case   40:
        textd="Digital to Analog";
        break;
    case   41:      
        textd="Analog to digital";
        break;
    case   42:      
        textd="Analog comparator";
        break;
    case   43:      
        textd="Relay output";
        break;                      
    case   44:      
        textd="Mqtt TX input";
        break;
    case   45:      
        textd="Mqtt RX output";
        break;                   
    case   46:      
        textd="User in";
        break;           
    case   47:      
        textd="User out";
        break;  
    case   48:      
        textd="Analog Math";
        break;                         
    case   50:      
        textd="Phone in";
        break;           
    case   55:      
        textd="Phone out";
        break;        
    case   60:      
        textd="Repeat Timer";
        break;
    case   61:      
        textd="Servo";
        break;                   
    case   62:      //accumulator
        textd="accumulator";
        break;  
    case   63:      //accumulator
        textd="clock";
        break;                                           
    case   80:      
        textd="Erase";
        break;                                        
    default:
        break;    
    }     
document.getElementById('textw').innerText=textd;
document.getElementById('HINTS').innerHTML=svghints[z]; 
}    


function Aboutpopup()
  {
  document.getElementById('SHOWSVG').innerHTML=svgdata;  
  document.getElementById('textw').innerText="About Network PLC";
  comv_icon=ABOUT;    
  helpopenModal();   
}

function PleaseLogin()
  {
  //document.getElementById('SHOWSVG').innerHTML=svgdata;  
  //document.getElementById('textw').innerText="About Network PLC";
  comv_icon=LOGIN;      
  helpopenModal();   
}

function pickRight(x,y,z)
    {if (typeof isconnected === 'undefined') 
        window.alert("Help menu not found, check web connection");
    var data=""; 
    comv_icon=z;
    textd="Code sample";
    document.getElementById('textw').innerText=textd;
    modify=  
    "<polygon points='"+(x*60+1)+","+(y*60+59)+" "+(60+x*60)+","+(y*60+59)+"' style='stroke:green;stroke-width:1'/>\
    <polygon points='"+(x*60+1)+","+(y*60+1)+" "+(60+x*60)+","+(y*60+1)+"' style='stroke:green;stroke-width:1'/>\
    <polygon points='"+(x*60+1)+","+(y*60)+" "+(x*60+1)+","+(y*60+59)+"' style='stroke:green;stroke-width:1'/>\
    <polygon points='"+(60+x*60)+","+(y*60)+" "+(60+x*60)+","+(y*60+59)+"' style='stroke:green;stroke-width:1'/>"  
    data=data1+modify;
    svgdata="<svg class='svgpic' xmlns='http://www.w3.org/2000/svg'>"+data+"</svg>"
    document.getElementById('SHOWSVG').innerHTML=svgdata;  
    document.getElementById('HINTS').innerHTML=svghints[0];   
    helpopenModal(); 
    }
)rawliteral";