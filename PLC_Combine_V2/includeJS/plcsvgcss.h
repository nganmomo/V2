
static const char PROGMEM INDEX_HTML_plcsvgcss[] = R"rawliteral(
/*lower for main page*/ 
body {
    margin: 0;
    font-family: Arial, Helvetica, sans-serif;
    background-color: #555;   
    overflow-y: auto;
    overflow-x: hidden;      
  }
  
/* Styling for the top navbar */
  .navbar {   
    position: fixed;     
    margin-top: 0px;
    top: 0;    
    width: 100%;
    background-color: #333;
    height:30px;    
    z-index: 1;   /*top nav bar blocking top content of the page*/
  }
  
  .navbar a {    
    float: left;
    color: #f2f2f2;
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;
    font-size: 17px;    
  }
  
  .navbar a:hover {
    background-color: #ddd;
    color: black;
  }
  
  .navbar a.active {
    background-color: #04AA6D;
    color: white;
  }
  
   /* Styling for the sidebar */
   .sidebar {
      position: fixed;
      height: 100%;
      width: 220px;
      position: fixed;
      top: 20px; /* Height of the top bar */
      left: 0px;
      background-color: #746363;
      padding-top: 0px;
      }
  
      .sidebar a {
      padding: 0px;
      width: 200px;
      text-align: center;
      text-decoration: none;
      font-size: 18px;
      color: #fff;
      display: block;
      }
  
      .sidebar a:hover {
      background-color: #555;
      }
  
      /* Styling for the bottom bar */
      .bottombar {
      position: fixed;
      bottom: 0;
      left: 0;
      width: 100%;
      height:30px;
      background-color: #333;
      color: #fff;
      padding: 0px;
      text-align: center; 
      }
  
      /* Page content styles */
      .content {        
      margin-top: 30px; /* Height of the top bar */   
      margin-left: 110px;
      height:2550px;  
      z-index: 2;   /*top nav bar blocking top content of the page*/
      }
/*pick up icon windows*/
  #piccont{                
    margin-top: 30px;
    width: 200px; /* Adjust the width and height as needed */            
    height: 360px;   
    margin-left: 5px;   
    overflow-y: auto;
    overflow-x: hidden;          
    scrollbar-color: rgb(59, 58, 58) rgb(26, 26, 25);   
    scrollbar-width: 5px;    
    margin-top: -3px;  
    border-radius: 3px;          
    border: 2px solid rgb(32, 156, 79);
  }

 

  #hintscont {                
    margin-top: 30px;
    width: 200px; /* Adjust the width and height as needed */            
    height: 400px;   
    margin-left: 5px;   
    overflow-y: auto;
    overflow-x: hidden;
    scrollbar-color: rgb(59, 58, 58) rgb(26, 26, 25);               
    scrollbar-width: 5px; 
    margin-top: -2px;  
    border-radius: 3px;
    color:azure;
    font-size: 12px;
    background-color: rgb(56, 58, 58);          
    border: 2px solid rgb(32, 156, 79);  
  }

  .svgpic {             
      width: 190px;
      height: 720px;         
    }
  
  .textw {
  cursor:none;
  caret-color:aliceblue; 
  background-color: rgb(56, 58, 58);
  color:azure;
  margin-top: 30px;      
  margin-left: 5px;              
  width: 200px;
  height: 22px;
  text-align: center;
  font-size: 14px;
  border: 2px solid rgb(32, 156, 79);
  border-radius: 3px;        
  }  
  /*             
  .scaled-content {
    transform: scale(1); 
  }*/
/*PLC main window*/
#tablecont {    
    padding-top: 12px;
    padding-left: 10px;
    margin-top: 0px;        
    width: 1042px; /* Adjust the width and height as needed */            
    height: 3250px;   
    margin-left: 110px;          
    border-radius: 3px;      
    border: 1px solid rgb(32, 156, 79);
    transform: scale(1);                 
}

#svgstring{
  position: fixed;  
}


/*button*/
button{    
    position: absolute;
    margin-top:5px;        
    font-size: 16px;
    background-color: rgb(132, 134, 134);
    border:1px;
    border-radius: 3px; 
    height:20px;
}


#plcsvgmain{
  z-index: 1; 
  caret-color: transparent;
}



#dialog{
  width:700px;
  height:1900px;
  margin-top:30px;
  padding:0px;
  margin-right:0px;
  transform: scale(1); 
  overflow-y: auto;
  overflow-x: hidden; 
  scrollbar-color: rgb(59, 58, 58) rgb(26, 26, 25);   
  background-color:rgb(128, 134, 128);
  }

    
.botstatus{
  left: 105px;     
}

.plcedit{       
  left: 198px;   
}

.botcl{       
  left: 300px;   
}

.botsim{      
    left: 368px;
}

.botdl{      
  left: 443px;
}

.botul{      
    left: 545px;
}

.closeul{    
  right:125px; 
  /*left:520px;*/
  visibility: hidden;
}  

.bqrcode{       
  left: 15px;   
}

.botphone{      
  left: 108px;
}

.clock{      
  left: 36px;
}


.botmqtt{      
    left: 185px;
}

.botfile{      
  left: 245px;
}


.labelul
{
  left: 640px;
  background-color: rgb(54, 54, 54);
}

.about
{
  right: 40px; 
}  

.EDIT
{
  right: 40px;  
}

.bothelp
{margin-left: 30px;
color:#f2f2f2;  
font-size: 16px;
background-color: rgb(54, 54, 54);
}

  
/*display: none;
top: 150px;
left: 500px;*/
/**************************popup**************************************/

#svgstring
{
  font-size: 11px;
}

.comst
{margin-left:5px;
  width:140px;
  height:12px;
}

input
{width:60px;
background-color: rgb(230, 221, 221); 
text-align: center; 
height: 12px;    
}

.overlay {
  display: flex;
  position: fixed; 
  width: 180px;
  height: 80px;
  padding: 20px;
  border-radius: 5px;
  background-color: rgba(0, 0, 0, 0.7);
  z-index: 9999;
}

/*
.overlay {
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;  
  display: flex;
  align-items: center;
  justify-content: center;
  z-index: 9999;
}
*/

.sbut
{margin-top:0px;
margin-left:80px;
font-size: 12px;  
}

#reset
{
  height:20px;
}



/* Styles for the popup */
.popup {
  position: fixed;
  /*top: 350px;
  left: 500px;*/
  width: 160px;
  height: 115px;
  padding: 5px;
  font-size: 12px;
  border-radius: 5px;
  border: 1px solid rgb(32, 156, 79);
      /*transform: translate(-50%, -50%);*/
  background-color: #a19b9b; 
  /*z-index: 2;*/
} 

img
{
  
  /*
  margin-top:-120px;
  margin-bottom:-140px;
  */
  margin-left:-145px;
  transform: scale(0.7); 
}

.helpimage{    
  padding-top:30px;
  padding-bottom:50px;
  margin-top:-120px;
  margin-bottom:-140px;
  margin-left:245px;
  transform: scale(0.7); 
}

.helpimageS{    
  padding-top:0px;
  margin-top:0px;
  margin-bottom:0px;
  margin-left:-145px;
  transform: scale(0.7); 
}

.helpimageM{    
  padding-top:0px;
  margin-top:0px;
  margin-bottom:-30px;
  margin-left:-125px;
  transform: scale(0.7); 
}

h4{
  margin-left:10px;
  color:#b6b2b2;
}

h5{
  margin-top:0px;
  margin-left:10px;
  font-size: 18px;
  color:#313131;
  line-height : 0px;
}

h6{
  margin-top:0px;
  margin-left:10px;
  font-size: 14px;
  line-height:0px;
  color:#313131;
}

h7{ 
  font-size: 12px;
  line-height:0px;
  color:#7a0e0e;
}

b
{ 
  margin-left:10px;
  color:#2e2d2d;
}

.ctt{
  margin-left:10px;
}

.helpcode
{
  margin-top:40px;  
}

.popupbut
{margin-left:150px;
background-color: #313131; 
color:#ddd;
}

select{
height:18px;
}
)rawliteral";