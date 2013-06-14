// author: http://antonio.sejas.es
// license: GPLv3
// 

//Average  to make more reliable
const int numOfReadings = 10;                   // number of readings to take/ items in the array
int readings[numOfReadings];                    // stores the distance readings in an array
int arrayIndex = 0;                             // arrayIndex of the current item in the array
int total = 0;                                  // stores the cumlative total
int averageDistance = 0;                        // stores the average value

// setup pins and variables for SRF05 sonar device

int echoPin = 2;                                // SRF05 echo pin (digital 2)
int initPin = 3;                                // SRF05 trigger pin (digital 3)
unsigned long pulseTime = 0;                    // stores the pulse in Micro Seconds
unsigned long distance = 0;                     // variable for storing the distance (cm)

//Deteccion
int next=0;
int anterior=0;
int led=13;



//setup

void setup() {
  pinMode(led, OUTPUT);                     // set init pin 13 as output (To blink the led)
  pinMode(initPin, OUTPUT);                     // set init pin 3 as output
  pinMode(echoPin, INPUT);                      // set echo pin 2 as input

  // create array loop to iterate over every item in the array

 for (int thisReading = 0; thisReading < numOfReadings; thisReading++) {
  readings[thisReading] = 0;
 }
 // initialize the serial port, lets you view the
 // distances being pinged if connected to computer
     Serial.begin(9600);
 } 

// execute
void loop() {
  digitalWrite(initPin, HIGH);                    // send 10 microsecond pulse
  delayMicroseconds(10);                  // wait 10 microseconds before turning off
  digitalWrite(initPin, LOW);                     // stop sending the pulse
  pulseTime = pulseIn(echoPin, HIGH);             // Look for a return pulse, it should be high as the pulse goes low-high-low
  distance = pulseTime/58;                        // Distance = pulse time / 58 to convert to cm.
  total= total - readings[arrayIndex];           // subtract the last distance
  readings[arrayIndex] = distance;                // add distance reading to array
  total= total + readings[arrayIndex];            // add the reading to the total
  arrayIndex = arrayIndex + 1;                    // go to the next item in the array
  // At the end of the array (10 items) then start again
  if (arrayIndex >= numOfReadings)  {
      arrayIndex = 0;
  }

  averageDistance = total / numOfReadings;      // calculate the average distance

  // if the distance is less than 255cm then do something (music,leds,etc)
  if (averageDistance < 70 && averageDistance > 20 ) {
            Serial.println(averageDistance, DEC);         // print out the average distance to the debugger
            anterior=0;
            next++;
            if(next>=4){
               Serial.println("next");
               //2 parpadeos de confirmación
               digitalWrite(led, HIGH);
               delay(300);        
               digitalWrite(led, LOW);  
               delay(300);   
               digitalWrite(led, HIGH);  
               delay(300);      
               digitalWrite(led, LOW);  
               delay(300);
               next=0;
            }
  } else if (averageDistance < 9 && averageDistance > 0) {
            Serial.println(averageDistance, DEC);         // print out the average distance to the debugger
            next=0;
            anterior++;
            if(anterior>=4){
               Serial.println("prev");
               //3 parpadeos de confirmación
               digitalWrite(led, HIGH);
               delay(1000);        
               digitalWrite(led, LOW);  
               delay(300);   
               digitalWrite(led, HIGH);  
               delay(300);      
               digitalWrite(led, LOW); 
               delay(200);     
               digitalWrite(led, HIGH);    
               delay(100); 
               digitalWrite(led, LOW);       
               anterior=0;
            }
  } else {
//         Serial.println(averageDistance, DEC);
         next=0;
         anterior=0;
         
        }
  delay(100);                                   // wait 100 milli seconds before looping again

}
