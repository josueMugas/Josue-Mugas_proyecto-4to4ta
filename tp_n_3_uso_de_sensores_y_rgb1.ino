int temperatura;
int luz;
void setup()
{
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 Serial.begin(9600);
}

void loop() 
{
  temperatura=analogRead(A0);
  int celsius = map(((temperatura - 20) * 3.04), 0, 1023, -40, 125);
  luz=analogRead(A1);
  luz=map(luz,712,1022,0,255);
  Serial.print("la luz esta dando: ");
  Serial.println(luz);
  Serial.print("estan haciendo: ");
  Serial.println(celsius);
  if(luz<=178 && luz>=76){
    if(celsius>=90){
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
    }else if(celsius<=18){
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
    }else{
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
    }
  }else{
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
  }
}
