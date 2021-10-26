// #include <Adafruit_ADXL345_U.h>

//#include <Adafruit_Sensor.h>


//define pin numbers
#define trigPin1 9
#define echoPin1 8
#define trigPin2 11
#define echoPin2 10
#define trigPin3 13
#define echoPin3 12

#define motorPin1 5
#define motorPin2 6
#define motorPin3 7



//define variables
long duration;
int distance;
int SafetyDistance; 
//duration is gonna define the duration of the signal we get back & distance is going to be 
//the final result in cm

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //starts serial terminal

  pinMode(trigPin1, OUTPUT); //Set trigpin as output
  pinMode(echoPin1, INPUT); //Set echopin as input 
  pinMode(motorPin1, OUTPUT); //Set motorPin as output
  pinMode(motorPin2, OUTPUT); //Set motorPin as output
  pinMode(motorPin3, OUTPUT); //Set motorPin as output
  

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT); //Set echopin as input 

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT); //Set echopin as input 

  //Serial.println(sizeof(int));
  //Serial.println(",");
}

float getDistance(int echoPin, int trigPin)
{
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW); //clears trigpin
  delayMicroseconds(2);
  //sets trigpin on high state for 10 ms
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //Reads echopin, returns sound wave travel time in mseconds
  int duration = pulseIn(echoPin, HIGH, 50000);  
  float distance = duration*0.034/2;
  return distance;
}

void loop() {
  float distance1 = getDistance(echoPin1, trigPin1);
  delayMicroseconds(100000);
  float distance2 = getDistance(echoPin2, trigPin2);
  delayMicroseconds(100000);
  float distance3 = getDistance(echoPin3, trigPin3);

  if (distance1 >= 20 && distance1 <= 40) {
    digitalWrite(motorPin1, HIGH);  
    delay(100);
    digitalWrite(motorPin1, LOW);
    delay(100);
  } else if(distance1 >= 40 && distance1 <= 60){
    digitalWrite(motorPin1, HIGH);  
    delay(200);
    digitalWrite(motorPin1, LOW);
    delay(200);
  } else if(distance1 >= 60 && distance1 <= 80){
    digitalWrite(motorPin1, HIGH);  
    delay(300);
    digitalWrite(motorPin1, LOW);
    delay(300);
  } else {
    digitalWrite(motorPin1, LOW);
  }
  

  if (distance2 >= 20 && distance2 <= 40) {
    digitalWrite(motorPin2, HIGH);
    delay(100);
    digitalWrite(motorPin2, LOW);
    delay(100);
  } else if(distance2 > 40 && distance2 <= 60){
    digitalWrite(motorPin2, HIGH);  
    delay(200);
    digitalWrite(motorPin2, LOW);
    delay(200);
  } else if(distance2 > 60 && distance2 <= 80){
    digitalWrite(motorPin2, HIGH);  
    delay(300);
    digitalWrite(motorPin2, LOW);
    delay(300);
  } else {
    digitalWrite(motorPin2, LOW);
  }

  if(distance3 >= 20 && distance3 <= 40) {
    digitalWrite(motorPin3, HIGH);
    delay(100);
    digitalWrite(motorPin3, LOW);
    delay(100);
  } else if(distance3 > 40 && distance3 <= 60){
    digitalWrite(motorPin3, HIGH);  
    delay(200);
    digitalWrite(motorPin3, LOW);
    delay(00);
  } else if(distance3 > 60 && distance3 <= 80){
    digitalWrite(motorPin3, HIGH);  
    delay(300);
    digitalWrite(motorPin3, LOW);
    delay(300);
  } else {
    digitalWrite(motorPin3, LOW);
  }


  Serial.print("Sensor1,");
  Serial.print(",");
  Serial.print(distance1);
  
  Serial.print("Sensor2,");
  Serial.print(",");
  Serial.println(distance2);

  Serial.print("Sensor3");
  Serial.print(",");
  Serial.println(distance3);

  

  
  //Prints the distance on the Serial Monitor
  delay(1000);

  //digitalWrite(trigPin2, LOW)
  //delayMicroseconds(2);
  //digitalWrite(trigPin3, LOW)
  //delayMicroseconds(2); // pauses for 2 microseconds

}
