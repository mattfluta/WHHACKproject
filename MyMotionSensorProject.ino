// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int lightPin = 2;
const int buzzPin = 3;

// defines variables
long duration;
int distance;
int disWall;

void setup() 
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(lightPin, OUTPUT);
pinMode(buzzPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
//finds intial distance to wall to be compared with the loop to detrime if something has passed the motion detector
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
disWall = duration*0.034/2;
//

}
void loop()
{
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
if(disWall - 10 < disWall < disWall + 10)
{
  digitalWrite(buzzPin, HIGH);
  digitalWrite(lightPin, HIGH);
  delay(1000);
  digitalWrite(buzzPin, LOW);
  digitalWrite(lightPin, LOW);
} 
//Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(1000);
}
 

