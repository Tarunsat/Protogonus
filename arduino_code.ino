
#include <Servo.h>
#include <SoftwareSerial.h>

int servoPin1 = 13;
Servo Servo1; 
int enA = 9;
int in1 = 8;
int in2 = 7;



SoftwareSerial BTSerial(4,5);

void setup()
  {
     
     Serial.begin(9600);
     BTSerial.begin(9600);
     
     delay(500);
     
    
    Servo1.write(0);
    Servo1.attach(servoPin1);
    
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);  
    // Turn off motors - Initial state
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW); 

   
   }
   
void inject()
{
   Servo1.write(180);
   delay(1000);
   digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(2000);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(2000);   
}

void alert()
{ 
  
  Serial.print("Safety meachnisms initiating- Standby for injection.");
  delay(1000);
  
  
  Serial.print("Injecting...");
}

void loop() {
  int heart_rate=analogRead(0)-440;
  Serial.print("BPM: ");
  Serial.println(heart_rate);
  delay(200); //  take a break
  

  
  if (heart_rate>130)
  {
    
    Serial.print("Your BPM is:");
    Serial.println(heart_rate);
    Serial.println("Please check!");
    
    
    delay(1000);
    if (heart_rate >130)
      {
        alert();
        delay(1000);
        inject();
      }
  }

}
