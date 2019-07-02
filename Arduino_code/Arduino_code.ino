#define lightPin 4
int light;

int trigPin = 6;    
int echoPin = 7;   
long duration, distance;   
long aver[3];   

void setup() {     
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT); 
  pinMode(lightPin, INPUT);
} 

void loop() { 
  for (int i=0;i<=2;i++) {   
    measure();               
    aver[i]=distance;            
    delay(50);           
  } 
  distance=(aver[0]+aver[1]+aver[2])/3; 
  light = analogRead(lightPin);
  delay(300);
  
  if (distance > 60 && light <= 150) {
    Serial.write("a");   //白天    
  }

  if (distance < 40 && light <= 150) {
    Serial.write("b");   //白天有人路过   
  }

  if (distance > 60 && light >= 300) {
    Serial.write("c");   //晚上 
  }

  if (distance < 40 && light >= 300) {
    Serial.write("d");   //晚上有人路过 
  }
}

void measure() {  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  distance = duration *0.034 / 2;
}
