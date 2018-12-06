#include <Servo.h>
#define trigPin 8          // connect trigger pin of sensor to pin 8 of arduino
#define echoPin 9          // connect echo pin of sensor to pin 9 of arduino
Servo myservo;

long duration;
double distance, pos, theta, ang,jump,len1;  
int a, len, x, y,j;
int k=1; 
int thresh = 35;

void setup() { 
  myservo.attach(10);    // connect signal pin of servo motor to pin 10 of arduino
  myservo.write(0);
  delay(1000);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
 
}

float angle (){                   //function to move servo from 0- 180 deg and back to 0
    myservo.write(pos); 
    pos = pos + k;
    if(pos == 0 || pos == 180){     
      k = -k;
      delay(10);
    j=j+1;
    }    
    
 return pos;    
}

float dist(){                          //function to calculate the distance of the obstacle from the sensor
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);    
    
    duration = pulseIn(echoPin, HIGH);    
    distance= duration*0.033/2;  
    return distance;
}

void output(){                           //function to print the output to the serial monitor
      
      Serial.print(pos);
      Serial.print(",");       
      Serial.print(distance);   
      Serial.println(".");
      Serial.print("\t");
      Serial.print("x=");
      Serial.print(x);
      Serial.print("\t");
      Serial.print("y=");
      Serial.println(y);
     Serial.println("\n");
     Serial.println("\n"); 
     Serial.print("\t");
     Serial.println(len);  
     delay(10);
}

void loop() {                                        //calls the function in a loop and prints the output as soon as the obstacle is detected
   pos = angle();
   distance = dist();   

     while((distance < thresh) && (j%2==0) && (pos>20)){          
      x = distance * cos(pos*(3.14/180));
      y = distance * sin(pos*(3.14/180));
      delay(10);
      output();
      distance = dist();    
      ang = angle();
            
     }
theta = angle(); 
jump = theta - ang; 
len = distance*sin(jump*(3.14/180)); 

}
