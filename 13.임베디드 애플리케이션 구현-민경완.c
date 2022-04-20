// C++ code
//
int PIN_LED = 6;
int PIN_LED8 = 8;
int PIN_LED10 = 10;
int PIN_LED12 = 12;
int PIN_TRIGER = 4;
int PIN_ECHO = 3;

void setup()
{
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_LED8, OUTPUT);
  pinMode(PIN_LED10, OUTPUT);
  pinMode(PIN_LED12, OUTPUT);
  pinMode(PIN_TRIGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  /*
  digitalWrite(PIN_LED, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(PIN_LED, LOW);
  delay(500); // Wait for 1000 millisecond(s)
  */
  
  int distance = 0;
  
  digitalWrite(PIN_TRIGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGER, LOW);
  
  distance = pulseIn(PIN_ECHO,HIGH);
  int cm = distance / 57;
  
  if(cm > 100){
    digitalWrite(PIN_LED, LOW);
    digitalWrite(PIN_LED8, LOW);
    digitalWrite(PIN_LED10, LOW);
    digitalWrite(PIN_LED12, LOW);
  }else if(cm <=100 && cm> 80) {
    digitalWrite(PIN_LED, HIGH);
    digitalWrite(PIN_LED8, LOW);
    digitalWrite(PIN_LED10, LOW);
    digitalWrite(PIN_LED12, LOW);
  }else if (cm <=80 && cm> 60){
    digitalWrite(PIN_LED, HIGH);
    digitalWrite(PIN_LED8, HIGH);
    digitalWrite(PIN_LED10, LOW);
    digitalWrite(PIN_LED12, LOW);
  }else if (cm <=60 && cm> 40){
    digitalWrite(PIN_LED, HIGH);
    digitalWrite(PIN_LED8, HIGH);
    digitalWrite(PIN_LED10,HIGH);
    digitalWrite(PIN_LED12, LOW);
  }else {
    digitalWrite(PIN_LED, HIGH);
    digitalWrite(PIN_LED8, HIGH);
    digitalWrite(PIN_LED10,HIGH);
    digitalWrite(PIN_LED12, HIGH);
  }
  Serial.println(cm);
}