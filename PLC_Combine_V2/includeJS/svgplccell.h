static const char PROGMEM INDEX_HTML_svgplccell[] = R"rawliteral(
var svgtable="";
var cursign="";
var plccelldata = Array.from(Array(txcount), () => new Array(tycount)); 

function updatacell()  
  {//grapcall1(); 
  //console.log('updatacell');
  var cellw=160;
  var cellh=40;       //color is the same, y for two line with same number
  var cellws=80;
  for(var y=0;y<tycount;y=y+4)
    {   //0 160 320 480 640 800
    plccelldata[0][y]="<rect y='"+(y*cellh)+"' x='0' width='"+cellw+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(0,"+y+")' oncontextmenu='mouseright(0,"+y+")'/>"
    plccelldata[2][y]="<rect y='"+(y*cellh)+"' x='160' width='"+cellw+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(1,"+y+")' oncontextmenu='mouseright(1,"+y+")'/>"             
    plccelldata[4][y]="<rect y='"+(y*cellh)+"' x='320' width='"+cellw+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(2,"+y+")' oncontextmenu='mouseright(2,"+y+")'/>"           
    plccelldata[6][y]="<rect y='"+(y*cellh)+"' x='480' width='"+cellw+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(3,"+y+")' oncontextmenu='mouseright(3,"+y+")'/>"          
    plccelldata[8][y]="<rect y='"+(y*cellh)+"' x='640' width='"+cellw+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(4,"+y+")' oncontextmenu='mouseright(4,"+y+")'/>"          
    plccelldata[10][y]="<rect y='"+(y*cellh)+"' x='800' width='"+cellw+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(5,"+y+")' oncontextmenu='mouseright(5,"+y+")'/>"           
    plccelldata[12][y]="<rect y='"+(y*cellh)+"' x='960' width='"+cellws+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(6,"+y+")' oncontextmenu='mouseright(6,"+y+")'/>"       
    //plccelldata[14][y]="<rect y='"+(y*cellh)+"' x='1010' width='"+cellws+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(8,"+y+")' oncontextmenu='mouseright(8,"+y+")'/>"                      
    }
  for(var y=1;y<tycount;y=y+4)
    {   //0 160 320 480 640 800
    plccelldata[0][y]="<rect y='"+(y*cellh)+"' x='0' width='"+cellw+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(0,"+y+")' oncontextmenu='mouseright(0,"+y+")'/>"       
    plccelldata[2][y]="<rect y='"+(y*cellh)+"' x='160' width='"+cellw+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(1,"+y+")' oncontextmenu='mouseright(1,"+y+")'/>"             
    plccelldata[4][y]="<rect y='"+(y*cellh)+"' x='320' width='"+cellw+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(2,"+y+")' oncontextmenu='mouseright(2,"+y+")'/>"           
    plccelldata[6][y]="<rect y='"+(y*cellh)+"' x='480' width='"+cellw+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(3,"+y+")' oncontextmenu='mouseright(3,"+y+")'/>"          
    plccelldata[8][y]="<rect y='"+(y*cellh)+"' x='640' width='"+cellw+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(4,"+y+")' oncontextmenu='mouseright(4,"+y+")'/>"          
    plccelldata[10][y]="<rect y='"+(y*cellh)+"' x='800' width='"+cellw+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(5,"+y+")' oncontextmenu='mouseright(5,"+y+")'/>"           
    plccelldata[12][y]="<rect y='"+(y*cellh)+"' x='960' width='"+cellws+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(7,"+y+")' oncontextmenu='mouseright(7,"+y+")'/>"       
    //plccelldata[14][y]="<rect y='"+(y*cellh)+"' x='1010' width='"+cellws+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(9,"+y+")' oncontextmenu='mouseright(9,"+y+")'/>"                      
    }  
  for(var y=2;y<tycount;y=y+4)
    {    //0 160 320 480 640 800
    plccelldata[0][y]="<rect y='"+(y*cellh)+"' x='0' width='"+cellw+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(0,"+y+")' oncontextmenu='mouseright(0,"+y+")'/>"   
    plccelldata[2][y]="<rect y='"+(y*cellh)+"' x='160' width='"+cellw+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(1,"+y+")' oncontextmenu='mouseright(1,"+y+")'/>"      
    plccelldata[4][y]="<rect y='"+(y*cellh)+"' x='320' width='"+cellw+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(2,"+y+")' oncontextmenu='mouseright(2,"+y+")'/>"         
    plccelldata[6][y]="<rect y='"+(y*cellh)+"' x='480' width='"+cellw+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(3,"+y+")' oncontextmenu='mouseright(3,"+y+")'/>"        
    plccelldata[8][y]="<rect y='"+(y*cellh)+"' x='640' width='"+cellw+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(4,"+y+")' oncontextmenu='mouseright(4,"+y+")'/>"        
    plccelldata[10][y]="<rect y='"+(y*cellh)+"' x='800' width='"+cellw+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(5,"+y+")' oncontextmenu='mouseright(5,"+y+")'/>"     
    plccelldata[12][y]="<rect y='"+(y*cellh)+"' x='960' width='"+cellws+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(6,"+y+")' oncontextmenu='mouseright(6,"+y+")'/>"         
    //plccelldata[14][y]="<rect y='"+(y*cellh)+"' x='1010' width='"+cellws+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(8,"+y+")' oncontextmenu='mouseright(8,"+y+")'/>"         
    } 
  for(var y=3;y<tycount;y=y+4)
    {    //0 160 320 480 640 800
    plccelldata[0][y]="<rect y='"+(y*cellh)+"' x='0' width='"+cellw+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(0,"+y+")' oncontextmenu='mouseright(0,"+y+")'/>"   
    plccelldata[2][y]="<rect y='"+(y*cellh)+"' x='160' width='"+cellw+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(1,"+y+")' oncontextmenu='mouseright(1,"+y+")'/>"      
    plccelldata[4][y]="<rect y='"+(y*cellh)+"' x='320' width='"+cellw+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(2,"+y+")' oncontextmenu='mouseright(2,"+y+")'/>"         
    plccelldata[6][y]="<rect y='"+(y*cellh)+"' x='480' width='"+cellw+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(3,"+y+")' oncontextmenu='mouseright(3,"+y+")'/>"        
    plccelldata[8][y]="<rect y='"+(y*cellh)+"' x='640' width='"+cellw+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(4,"+y+")' oncontextmenu='mouseright(4,"+y+")'/>"        
    plccelldata[10][y]="<rect y='"+(y*cellh)+"' x='800' width='"+cellw+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(5,"+y+")' oncontextmenu='mouseright(5,"+y+")'/>"     
    plccelldata[12][y]="<rect y='"+(y*cellh)+"' x='960' width='"+cellws+"' height='"+cellh+"' fill='rgb(70, 70, 70)' onclick='mouseleft(7,"+y+")' oncontextmenu='mouseright(7,"+y+")'/>"         
    //plccelldata[14][y]="<rect y='"+(y*cellh)+"' x='1010' width='"+cellws+"' height='"+cellh+"' fill='rgb(54, 54, 54)' onclick='mouseleft(9,"+y+")' oncontextmenu='mouseright(9,"+y+")'/>"         
    }      
    svgtable="";
    for(var y=0;y<tycount;y++)
    {for(var x=0;x<txcount;x++) 
      {svgtable=svgtable+plccelldata[x][y];           //place grip on screen   
      }
    }    
  }  



  function updatetable(z)
  {if(z===FILLALL) 
    {svgdata0="";svgdata3="";svgedit="";  
    for(var y=0;y<ycount;y++)
      {for(var x=0;x<xcount;x++)       
        {if(serialcelldata[x*8+y*48]>0)    //type
          svgdata0=svgdata0+filldata(serialcelldata[x*8+y*48],x,y);   
        //if(serialcelldata[x*8+y*48+3]>0)
        //  svgdata3=svgdata3+filldata(serialcelldata[x*8+y*48+3],x,y);     
        }      
      }
    addtext();   
    //Edit sign
    //for(let xa=0;xa<xcount;xa++)   //order
      {for(let yb=0;yb<ycount;yb++) 
        {svgedit=svgedit+filldata(82,984,yb);
        svgedit=svgedit+filldata(83,966,yb);
        svgedit=svgedit+filldata(84,1004,yb);
        svgedit=svgedit+filldata(85,984,yb);                                
        }
      }
    //Edit sign    
    }
  if(z===0)
    {svgdata0="";
    for(var y=0;y<ycount;y++)
      {for(var x=0;x<xcount;x++)       
          svgdata0=svgdata0+filldata(serialcelldata[x*8+y*48],x,y);               
      }
    }    
  if(z===3 || z===FILLALL)
    {svgdata3="";
    for(var y=0;y<ycount;y++)
      {for(var x=0;x<xcount;x++)       
        {let uppertype=serialcelldata[(y-1)*48+x*8];  
        if((serialcelldata[x*8+y*48+3]&8)>0 && (uppertype===42 || uppertype===48)) //tap in center math analog
          {svgdata3=svgdata3+filldata(serialcelldata[x*8+y*48+3]&7|0x10,x,y,'yellow','yellow');    //0x18 for CMP   
          } 
        else if((serialcelldata[x*8+y*48+3]&8)===8  && (uppertype===40||uppertype===44||uppertype===46||uppertype===60))               
          {if(uppertype===40)  ctltext='DOWN';
          if(uppertype===44)  ctltext='SEND';
          if(uppertype===46)  ctltext='TRIG';
          if(uppertype===60)  ctltext='PAUSE';
          svgdata3=svgdata3+filldata(serialcelldata[x*8+y*48+3],x,y,'yellow','yellow',ctltext);  
          }    
        else   
          svgdata3=svgdata3+filldata(serialcelldata[x*8+y*48+3],x,y);     
        }  
      }
    }      
  //clear table//
  //Showtable = "<svg id='svgstring' width='"+svgwidth+"' height='3200' xmlns='http://www.w3.org/2000/svg'></svg>"  
  //document.getElementById('plcsvgmain').innerHTML= Showtable;   
  //if(z!=CLEAR)
    {if(z===SIM)
      addtext(); 
    svgtext=svgtext+"<polygon points='2,0 2,3200' style='stroke:green;stroke-width:3'/>\
    <polygon points='962,0 962,3200' style='stroke:red;stroke-width:3'/>"
    if(z===SIM)
      {Showtable = "<svg id='svgstring' width='"+svgwidth+"' height='3200' xmlns='http://www.w3.org/2000/svg'>\
      "+svgtable+svgtext+statbuf+Acstatus+svgSimSign+"</svg>"
      //"+svgtable+svgtext+Acstatus+svgSimSign+svgedit"</svg>"  
      }
    else      
      {//svgtext=svgtext+statbuf+Acstatus;  
      Showtable = "<svg id='svgstring' width='"+svgwidth+"' height='3200' xmlns='http://www.w3.org/2000/svg'>\
      "+svgtable+svgtext+svgdata0+svgdata3+svgedit+cursign+"</svg>"  
      }  
    localStorage.setItem('plcdata',JSON.stringify(serialcelldata));       
    document.getElementById('plcsvgmain').innerHTML= Showtable;    
    }
  }
 
  var mouseleftallow=1;
  function mouseleft(x,y)
  {if(mouseleftallow===1)
    { y=y>>1;
      cursign="";   
      if(checksyntax(comv_icon,x,y)===0)  
      {document.getElementById('botul').style.backgroundColor="#f0f0f0";                
      if(comv_icon>22)            
        updataonecell(0,x,y,comv_icon); //clear
      else
        updataonecell(3,x,y,comv_icon); //clear
        //Special handle for (counter updownDAC Math COMPARATOR)
      if((comv_icon>=38 && comv_icon<=40)||comv_icon==48 || comv_icon==42)
        {if(serialcelldata[x*8+(y+1)*48]>0)
          updataonecell(0,x,y+1,Delete); //clear 
        else
          serialcelldata[x*8+(y+1)*48+3]=serialcelldata[x*8+(y+1)*48+3]|8;   
        //updatetable(FILLALL); //3
        }     
      }  
      updatetable(FILLALL); 
    }
  }    

  function mouseright(x,y)
  {y=y>>1      
  var Type=serialcelldata[x*8+y*48];  
  if(Type>0)
    {cursign=filldata(cursor,x,y,'black','black'); 
    updatetable(CURSOR);   
    document.getElementById('plcsvgmain').innerHTML=Showtable;      
    window.addEventListener('scroll', function(){console.log(this.scrollY)});
    var CurY=this.scrollY-35;
    openPopup(Type,x,y);
    document.getElementById('popup').innerHTML=sdata;
    document.getElementById("popup").style.display = "block";
    console.log((y*80)-CurY); 
    console.log(screen.availHeight);               
    popup.style.left = (x*160)+385+'px';   
    if(((y*80)-CurY)>(screen.availHeight-400)) y--;              
    popup.style.top = (y*80)-CurY+'px';    
    //popup.style.display = 'flex';   
    }      
  }
  
  //Check and edit sign

function Editmouseright(x,y)
{var u=0;
document.getElementById('botul').style.backgroundColor="#f0f0f0"; 
if(x==1)  y=y-1;
if(x==2)  y=y-1;  
if(x==4)//save and delete
  {for(let tx=0;tx<6;tx++)
    {for(let t=0;t<6;t++)
      Savefordelect[u++]=serialcelldata[y*48+tx*8+t];
    }
  }     
if(x==1 ||x==3 || x==4)     
  {for(let t=0;t<6;t++)
    updataonecell(0,t,y,Delete);
  }    
if(x==1)  //move up
  {for(let ty=y;ty<ycount-1;ty++)
    {for(let tx=0;tx<6;tx++)
      {for(let t=0;t<6;t++)
      serialcelldata[ty*48+tx*8+t]=serialcelldata[(ty+1)*48+tx*8+t]
      }
    }  
  }  
if(x==2)  //move down
  {for(let ty=ycount-1;ty>y;ty--)
    {for(let tx=0;tx<6;tx++)
      {for(let t=0;t<6;t++)
      serialcelldata[ty*48+tx*8+t]=serialcelldata[(ty-1)*48+tx*8+t]
      }
    }  
  }    
if(x==3) //insert left arrow
  {u=0;
  for(let tx=0;tx<6;tx++)
    {for(let t=0;t<6;t++)
      serialcelldata[y*48+tx*8+t]=Savefordelect[u++];
    }     
  }  
if(x==2)   
  {for(let t=0;t<6;t++)
    updataonecell(0,t,y+1,Delete);
  }                    

updatetable(FILLALL);
//addtext(); //re-arrange text                   
//addsign(gentable);  
//localStorage.setItem('plcdata',JSON.stringify(serialcelldata)); 
}  

function checksyntax(lookup,x,y)  
  { 
    //cellchanged=1;  //cell changed must upload for debug
    let isexit=1; //1 is not allow
    let tv=0;
    let uppertype=serialcelldata[(y-1)*48+x*8];
    //let type=serialcelldata[y*48+x*8];
    //  document.getElementById('ulbutton').style.color="black";                                     
    //  filldata(cursor,x,y,'yellow','yellow');                              
    if(lookup<65)      //sign legal limit  control
        {if(y===0 && (lookup===8 || lookup===15))   //last colum pin 
          {window.alert("cannot not put this on top row")                         
          isexit=2;
          }
        if(y===39 && (lookup===2 || lookup===40 || lookup===42 || lookup===48)) 
          {window.alert("cannot not put this on bottom row")         
          isexit=2;
          }
        if((lookup===1) && (uppertype===60 || uppertype===42 || uppertype===48))    
          {window.alert("Not allow to add vertical line below this device");                   
          isexit=2;
          }       
        }                                         
     
        if(lookup===8)
            {let testarrayup8=[8,37,40,42,44,45,46,48,60,62,''];  
            for(tv=0;tv<testarrayup8.length;tv++) 
              {if(testarrayup8[tv]===uppertype)
                {isexit=2;            
                window.alert("Only for timer, D/A, counter or flip flop");                                      
                }
              }     
            }
        if(isexit===1)    
        {switch(x)
          {case  0:          
            let testarray0=[4,16,23,25,26,28,29,30,36,40,41,45,47,48,49,50,55,60,61,62];
            for(tv=0;tv<testarray0.length;tv++)  
              {if(testarray0[tv]===lookup)
                {isexit=0;
                break;
                }  
              }             
              break;                            
            case  1:  
            case  2:  
            case  3:
            case  4: 
                  let testarray14=[2,4,8,16,23,24,25,26,28,29,30,36,37,38,39,40,41,42,44,45,46,47,48,50,55,60,62];  
                  for(tv=0;tv<testarray14.length;tv++)  
                    {if(testarray14[tv]===lookup)
                      {isexit=0;
                      break;
                      }
                    }                   
                  break;                                            
            case  5:
              let testarray5=[2,8,43,49,24,55,44,46,61];  
              for(tv=0;tv<testarray5.length;tv++)  
                {if(testarray5[tv]===lookup)
                  {isexit=0;
                  break;
                  }  
                }                
                break;                                            
            case  1:   //not allow in column 1                                 
              let testarray1=[8,37,38,39,41,47,48];
              for(tv=0;tv<testarray1.length;tv++)  
                {if(testarray1[tv]===lookup)
                  {isexit=1;
                  break;
                  }  
                }             
              break;  
            }           
          }                                             
    if(isexit===1 && lookup!=80)        
      window.alert("Not allow to put this in this column\nerror code "+lookup);   
    if(lookup===80) isexit=0;
    if((!(lookup>=37 && lookup<=39) || lookup===42 || lookup===48) && serialcelldata[x*8+(y+1)*48+3]===8)
        serialcelldata[x*8+(y+1)*48+3]=0;                                        
  return   isexit;
  }  

function  UploadToHW(){
if(tryonline===1)
  window.alert("This function required hardware");
else  
  {let error=0;
  let message=""; 
  cellchanged=0; 
  var typeused = Array(60).fill(0);  
  //1 for before 44  2 for 
  //peused=[0,1,2,3,4,5,6,7,8,9,1,1,2,3,4,5,6,7,8,9,2,1,2,3,4,5,6,7,8,9,3,1,2,3,4,5,6,7,8,9,4,1,2,3,4,5,6,7,8,9,5,1,2,3,4,5,6,7,8,9,6,1,2,3,4,5,6,7,8,9,]
  //peused=[0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,]
  typeused=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,]
  for(let y=0;y<ycount;y++)
    {for(let x=0;x<xcount;x++)
      {let type=serialcelldata[x*8+y*48];
      let idtext=serialcelldata[x*8+y*48+1]; 
      let linktext=serialcelldata[x*8+y*48+2];         
      if(type>0)    
        {/*if(typeused[type]>1)
          {
          /*switch(type)
          {case 37:                    
            {message="Requires a different device ID\n x="+x+" y="+y;
            window.alert(message);
            error++;
            }
          }
          }*/
          if(type==40)   //DAC Requires two inputs
            {if((serialcelldata[x*8+(y+1)*48+3]&8)!=8)
              {window.alert("Requires two inputs"); 
              error++;
              }
            }
          if(type==44)
            {let typebefore=0;
            if(x>0)
              typebefore=serialcelldata[(x-1)*8+y*48];
            if((typeused[typebefore]&1)!=1)          
              {window.alert("The Mqtt-input must follow an output device\n not a connect line"); 
              error++;
              }
            }
          switch (type)
          {
          case 28: case 29: case 30: case 34: case 35:
          case 25: case 24: case 36: case 26:   
          case 37: case 38: case 39: case 40: case 41:
          case 42: case 43: case 44: case 45: case 46:
          case 47: case 50: case 55: case 60:
          if(idtext==="" || (idtext>>8)===0)      
              {message="No Device Id for x="+(x+1)+" y="+(y+1);
              window.alert(message);
              error++;
              }
          break;  
          case  23:
          if(linktext==="")      
              {message="No Link ID for x="+(x+1)+" y="+(y+1);
              window.alert(message);
              error++;
              }
          break;                
          }
        }
      if(error>0)    
        {
        cursign=filldata(cursor,x,y,'red','red');  //cursor line
        updatetable(TEXT);//gentable();
        break;
        }
      }
    if(error>0)    
    break;
    }
  if(error===0)
    uploadespStart();      
  }
}

function changeframe(fsel) {
if(tryonline===1 && (fsel===2 || fsel===3))
  window.alert("This function required hardware");
else
  {//if(Sceret===0 && fsel!=3)  except phone
  if(Sceret===0)  //include phone  
    {if(fsel===4)
      window.alert("Please login before File handle\n refresh this page to login");
    if(fsel===3)
      window.alert("Please login or move Admin switch in setup position\n before Phone setup\n refresh this page to login");    
    if(fsel===2)
      window.alert("Please login before Mqtt setup\n refresh this page to login");  
    }
  else      
    {statbuf=""; //clear status                  
    if(fsel===0)
        {document.getElementById('closeul').style.visibility='visible';
        document.getElementById("plcsvgmain").innerHTML=
        "<utbar><div class='title1'><p>Clock timer setup</p>\
        </div></utbar>\
        <iframe id='clcoksetup' src='' title='description'\
        style='margin-left:10px;width:95%;height:950px;margin-top:20px;position:fixed;'></iframe>";         
      if(systemtype===1)
        document.getElementById('clcoksetup').src='setupclock';       
      else  
        document.getElementById('clcoksetup').src='setupclock.html';
        }           
    if(fsel===3)
        {document.getElementById('closeul').style.visibility='visible';
        document.getElementById("plcsvgmain").innerHTML=
        "<utbar><div class='title1'><p>Mobile control setup</p>\
        </div></utbar>\
        <iframe id='mobsetup' src='' title='description'\
        style='margin-left:10px;width:95%;height:950px;margin-top:20px;position:fixed;'></iframe>";         
      if(systemtype===1)
        document.getElementById('mobsetup').src='mobile';       
      else  
        document.getElementById('mobsetup').src='mobile.html';
        }                        
    if(fsel===2)
        {document.getElementById('closeul').style.visibility='visible';
              //mqtt setup /direction test http://192.168.1.xx/MQST
        document.getElementById("plcsvgmain").innerHTML=       
        "<form><input type='button' style='height:18px' onclick='freset()' value='Reset all'/></form>\
        <label>Key 'RESET' To clear all browser data </label>\
        </div></utbar><br>\
        <iframe id='mqst' src='' title='description'\
        style='margin-left:10px;width:95%;height:700px;margin-top:20px;position:fixed;'></iframe>";                   
      if(systemtype===1)
        document.getElementById('mqst').src='mqsetup';  
      else 
        document.getElementById('mqst').src='mqsetup.html';       
        }    
    if(fsel===1)     //QR code
        {document.getElementById("plcsvgmain").innerHTML=
        "<utbar><div class='title'><p>QR code for mobile phone</p></div></utbar>\
        <iframe id='qrc' src='' title='description'\
        style='margin-left:10px;width:900px;height:900px;margin-top:20px;position:fixed;'></iframe>";          
    if(systemtype===1)   
        document.getElementById('qrc').src='qrcode';  
    else 
        document.getElementById('qrc').src='qrcode.html'      
        }     
    if(fsel===4)     //file
        {document.getElementById('closeul').style.visibility='visible'
        document.getElementById("plcsvgmain").innerHTML=
        "<utbar><div class='title'><p>File managing Press PLC to exit</p></div></utbar>\
        <iframe id='FILEHAND' src='' title='description'\
        style='margin-left:10px;width:90%;height:800px;margin-top:20px;position:fixed;'>\
        </iframe>";                                 
    if(systemtype===1)   
        document.getElementById('FILEHAND').src='filehandle';   
    else      
        document.getElementById('FILEHAND').src='filehandle.html';        
        }                                   
    }  
  }
}  
)rawliteral";
       
  