/*
enter in the diameter of the spool and
and the length of thread you need to pack, 
everything else should just work,

 */
 
 int spoolDiameter = 11;
 int materialLength = 1500;
 
 int rotationsPerMaterialLenght = materialLength/ (spoolDiameter * 3.14);
 int stepsPerRotation = 200;
 int stepsPerMaterialLength = stepsPerRotation * rotationsPerMaterialLenght;
 

int stepPin = 12;
int enablePin = 9;
int airOnPin = 2;
int airOffPin = 3;
int cutterOnPin = 4;
int cutterOffPin = 5;

int pulseSolinoidTime = 100;
int cutterOnTime = 100;
int blowIntoBagTime = 100;

int maxSpeed = 600;// bigger is slower


void setup() {                
  // initialize the digital pin as an output.
  pinMode(stepPin, OUTPUT); 
  pinMode(enablePin, OUTPUT);
  pinMode(airOnPin, OUTPUT);
  pinMode(airOffPin, OUTPUT);
  pinMode(cutterOnPin, OUTPUT);
  pinMode(cutterOffPin, OUTPUT);
 pinMode(8, INPUT_PULLUP);  
 //Serial.begin(9600);
 //while (!Serial) {  // wait for serial port to connect. Needed for Leonardo only
 
//}
 
}
void cutMaterial()
{
  digitalWrite(cutterOnPin, HIGH);
  delay(pulseSolinoidTime);
  digitalWrite(cutterOnPin, LOW);
  delay(cutterOnTime);
  digitalWrite(cutterOffPin, HIGH);
  delay(pulseSolinoidTime);
  digitalWrite(cutterOffPin, LOW);
}



void blowMaterialIntoBag()
{
 digitalWrite(airOnPin, HIGH);
  delay(pulseSolinoidTime);
 digitalWrite(airOnPin, LOW);
 delay(blowIntoBagTime);
 digitalWrite(airOffPin, HIGH);
 delay(pulseSolinoidTime);
 digitalWrite(airOffPin, LOW);
}
  
void unravleMaterial()
{
digitalWrite(enablePin, LOW);
  
 digitalWrite(airOnPin, HIGH);
  delay(pulseSolinoidTime);
 digitalWrite(airOnPin, LOW);
 

 
 for (int stepNumber = 0;stepNumber < stepsPerMaterialLength; stepNumber++)
{
 digitalWrite(stepPin, HIGH);   
 delayMicroseconds(maxSpeed);            
 digitalWrite(stepPin, LOW);   
 delayMicroseconds(maxSpeed);          
 
}
  
 digitalWrite(airOffPin, HIGH);
 delay(pulseSolinoidTime);
 digitalWrite(airOffPin, LOW);
 
 digitalWrite(enablePin, HIGH);
 
 
}


void loop() {

  
  if (digitalRead(8) == LOW){
    digitalWrite(13, HIGH);
    cutMaterial();
    blowMaterialIntoBag();
    delay(1000);
    unravleMaterial();
  }
  else{digitalWrite(13,LOW);}
}
