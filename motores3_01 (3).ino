//entrada motores//
# define ENTRADAM1 6
# define ENTRADAM2 7
# define ENTRADAM3 5
// Control motor1//
# define ControlM1A  8
# define ControlM1B  9
// Control motor2//
# define ControlM2A 10
# define ControlM2B	11
// Control motor3//
# define ControlM3A  2
# define ControlM3B	 3
//sensor de sonido//
# define trig 13
# define echo 12
//variables//
int sensor1,sensor2,sensor3,hayMovimiento,estado_boton;
float tiempo,distancia;
bool hayEnemigo;
void setup()
{	
  Serial.begin(9600);
  		//Motores//
  pinMode(ENTRADAM1 ,OUTPUT);
  pinMode(ENTRADAM2 ,OUTPUT);
  pinMode(ControlM1A,OUTPUT);
  pinMode(ControlM1B,OUTPUT);
  pinMode(ControlM2A,OUTPUT);
  pinMode(ControlM2B,OUTPUT);
  pinMode(ControlM3B,OUTPUT);
  pinMode(ControlM3A,OUTPUT);
 		//sensores//
  pinMode(4,INPUT);//movimiento//
  pinMode(echo,INPUT);//distancia//
  pinMode(trig,OUTPUT);//distancia//
  Serial.begin(9600);
}

void loop(){ 
  estado_boton=analogRead(A0);
  //En esta instancia se determina el estado del onterruptor//
  while(estado_boton==1023){
	deteccionRing();
  }
  parar();
}
		//------------funciones de deteccion------------//
bool detectarEnemigo(){
    //sensor de sonido//
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    tiempo= pulseIn (echo,HIGH);
    distancia =(tiempo/2)/29.15; 
    //sensor de movimiento//
    hayMovimiento=digitalRead(4);
    Serial.println(hayMovimiento);
  if (distancia<=100 && hayMovimiento==HIGH){
  	return (true);
  }
  else{
    return(false);
  }
}
void deteccionRing(){
    estado_boton=analogRead(A0);
    //Sensores de luz//
    sensor1=analogRead(A1);
    sensor2=analogRead(A2);
    sensor3=analogRead(A3);
    if(sensor1==HIGH && sensor3==LOW){
      derecha();
      delay(500);
      parar();
    }
    else if(sensor3==HIGH && sensor1==LOW){
      izquierda();
      delay(500);
      parar();
    }
    else if (sensor2==HIGH && sensor1==LOW && sensor3==LOW){
      atras();
    }
    else{
        hayEnemigo=detectarEnemigo();
		Serial.println(hayEnemigo);
        if (hayEnemigo){
          avanzar();
          }
        else {
          giroDeInspeccion();
        }
    }
}
		//------------funciones de movimiento------------//
void giroDeInspeccion(){
	analogWrite(ENTRADAM1,255);
    analogWrite(ENTRADAM2,255);
    analogWrite(ENTRADAM3,255);
    digitalWrite(ControlM1A,LOW);
    digitalWrite(ControlM2A,LOW);
    digitalWrite(ControlM3A,LOW);
    digitalWrite(ControlM1B,HIGH);
    digitalWrite(ControlM2B,HIGH);
    digitalWrite(ControlM3B,LOW);
    estado_boton=analogRead(A0);
}
void derecha() {
    analogWrite(ENTRADAM1,255);
    analogWrite(ENTRADAM2,255);
    analogWrite(ENTRADAM3,255);
    digitalWrite(ControlM1A,HIGH);
    digitalWrite(ControlM2A,HIGH);
    digitalWrite(ControlM3A,LOW);
    digitalWrite(ControlM1B,LOW);
    digitalWrite(ControlM2B,LOW);
    digitalWrite(ControlM3B,HIGH);
    estado_boton=analogRead(A4);
}
void izquierda(){
    analogWrite(ENTRADAM1,255);
    analogWrite(ENTRADAM2,255);
    analogWrite(ENTRADAM3,255);
    digitalWrite(ControlM1A,LOW);
    digitalWrite(ControlM2A,LOW);
    digitalWrite(ControlM3A,LOW);
    digitalWrite(ControlM1B,HIGH);
    digitalWrite(ControlM2B,HIGH);
    digitalWrite(ControlM3B,HIGH);
    estado_boton=analogRead(A0);
}
void avanzar() {
    analogWrite(ENTRADAM1,255);
    analogWrite(ENTRADAM2,255);
    analogWrite(ENTRADAM3,255);
    digitalWrite(ControlM1A,HIGH);
    digitalWrite(ControlM2A,LOW);
    digitalWrite(ControlM3A,LOW);
    digitalWrite(ControlM1B,LOW);
    digitalWrite(ControlM2B,HIGH);
    digitalWrite(ControlM3B,HIGH);
    estado_boton=analogRead(A0);
}
void atras() {
    analogWrite(ENTRADAM1,255);
    analogWrite(ENTRADAM2,255);
    analogWrite(ENTRADAM3,255);
    digitalWrite(ControlM1A,LOW);
    digitalWrite(ControlM2A,HIGH);
    digitalWrite(ControlM3A,HIGH);
    digitalWrite(ControlM1B,HIGH);
    digitalWrite(ControlM2B,LOW); 
    digitalWrite(ControlM3B,LOW);
    estado_boton=analogRead(A0);
}
void parar() {
    analogWrite(ENTRADAM1, 0);
    analogWrite(ENTRADAM2, 0);
    analogWrite(ENTRADAM3, 0);
    digitalWrite(ControlM1A, LOW);
    digitalWrite(ControlM1B, LOW);
    digitalWrite(ControlM2A, LOW);
    digitalWrite(ControlM2B, LOW);
    digitalWrite(ControlM3B, LOW);
    estado_boton=analogRead(A0);
}