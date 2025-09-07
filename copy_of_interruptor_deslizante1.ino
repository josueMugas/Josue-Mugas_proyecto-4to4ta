
void setup()
{
	pinMode(11, INPUT);
	pinMode(10,OUTPUT);
  	pinMode( 7,OUTPUT);
  	pinMode( 6,OUTPUT);
  	Serial.begin(9600);
}

void loop()
{
  int estadoSensor=digitalRead(11);
  Serial.println(estadoSensor);
  if (estadoSensor==HIGH){
    digitalWrite( 6,LOW);
  	digitalWrite( 7,HIGH);
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite( 7,LOW);
    digitalWrite(10,LOW);
    delay(500);
  }else{
    digitalWrite( 7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(6,HIGH);
  }
}