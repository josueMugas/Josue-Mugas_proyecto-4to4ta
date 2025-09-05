# define trig 13
# define echo 12
float tiempo,distancia;
void setup()
{
  pinMode (11 ,OUTPUT);
  pinMode (10 ,OUTPUT);
  pinMode ( 4 ,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  tiempo= pulseIn (echo,HIGH);
  distancia =(tiempo/2)/29.15;
  Serial.println(distancia);
  if(distancia>=150){
    digitalWrite( 4, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
  }
  else{
    digitalWrite(10, LOW);
    digitalWrite( 4, HIGH);
    digitalWrite(11, HIGH);
    delay(50);
    digitalWrite( 4, LOW);
  	digitalWrite(11, LOW);
    delay(50);
  }
}