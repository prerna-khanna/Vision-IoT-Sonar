import processing.serial.*;
Serial sender;  
Serial object;
String angle = "";     
int distance;

void setup()
{
 
  sender = new Serial(this, "COM12", 9600);
  object = new Serial(this, "COM5", 9600); 
  
}
  void draw(){ 
    while(true){
  angle = sender.readString();
  delay(100);
  println(angle);
  if(angle != null){
  object.write(angle);
  }
  }
  }
  
 