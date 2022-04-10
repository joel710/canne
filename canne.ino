
const int echoPin = 4;
const int triggerPin = 2;
float intervalle;
int distanceAvant;

int led = 5;
void setup() 
{
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
   pinMode(led, OUTPUT);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{   
   digitalWrite(triggerPin, LOW);
          delayMicroseconds(2);
            digitalWrite(triggerPin, HIGH); //Envoie d'une onde sonore
              delayMicroseconds(10);
                digitalWrite(triggerPin, LOW);
              intervalle = pulseIn(echoPin, HIGH); //Réception de l'écho
             intervalle = intervalle/5.8/10; //Conversion de la différence de temps entre l'envoie de l'onde sonore et la réception de l'écho en distance (cm)
            Serial.println("Distance avant:");
          Serial.println(intervalle);
       distanceAvant = intervalle;
  if(distanceAvant < 25) //Si la distance avant est de moins de 25cm
  {
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
  }
}
