en este día yo falte al colegio debido a que me encontraba enfermo pero estuvimos mejorando los motores y haciendo que tenga la capacidad de identificar si está o no está en una línea negra 

 
así quedo funcionando y el código fue el siguiente:
//entrada motores

"#" define ENTRADAM1 5

"#" define ENTRADAM2 6

// Control motores

"#" define ControlM1A 7

"#" define ControlM1B 8

// Control motor2

"#" define ControlM2A 9

"#" define ControlM2B	11



void setup()

{	
  		//Motores//

  pinMode(ENTRADAM1,OUTPUT);

  pinMode(ENTRADAM2,OUTPUT);

  pinMode( 7,ControlM1A);

  pinMode( 8,ControlM1B);

  pinMode( 9,ControlM2A);

  pinMode(11,ControlM2B);

 		//sensores//

  pinMode( 2,INPUT);

  pinMode( 4,INPUT);

  pinMode(10,INPUT);

}

void loop()

{

  int sensor1,sensor2,sensor3;

  sensor1=digitalRead(2);

  sensor2=digitalRead(4);

  sensor3=digitalRead(10);

  if(sensor1==LOW && sensor3==HIGH && sensor2==HIGH){

  	derecha();

  }

  else if(sensor3==LOW && sensor2==HIGH && sensor1==HIGH){

  	izquierda(); 	

  }

  else if(sensor2==HIGH && sensor3==HIGH && sensor1==HIGH){

  	avanzar();

  }

  else {

  	parar();

  }

}
void derecha() {

  analogWrite(ENTRADAM1,255);

  analogWrite(ENTRADAM2,255);

  digitalWrite(ControlM1A,HIGH);

  digitalWrite(ControlM2A,HIGH);

  digitalWrite(ControlM1B,LOW);

  digitalWrite(ControlM2B,LOW); 

}

void izquierda(){

  analogWrite(ENTRADAM1,255);

  analogWrite(ENTRADAM2,255);

  digitalWrite(ControlM1A,LOW);

  digitalWrite(ControlM2A,LOW);

  digitalWrite(ControlM1B,HIGH);

  digitalWrite(ControlM2B,HIGH); 


}

void avanzar() {

  analogWrite(ENTRADAM1,255);

  analogWrite(ENTRADAM2,255);

  digitalWrite(ControlM1A,HIGH);

  digitalWrite(ControlM2A,LOW);

  digitalWrite(ControlM1B,LOW);

  digitalWrite(ControlM2B,HIGH); 

}

void atras() {

  analogWrite(ENTRADAM1,255);

  analogWrite(ENTRADAM2,255);

  digitalWrite(ControlM1A,LOW);

  digitalWrite(ControlM2A,HIGH);

  digitalWrite(ControlM1B,HIGH);

  digitalWrite(ControlM2B,LOW); 

}

void parar() {

  analogWrite(ENTRADAM1,255);

  analogWrite(ENTRADAM2,255);

  digitalWrite(ControlM1A,LOW);

  digitalWrite(ControlM2B,LOW);

  digitalWrite(ControlM1A,LOW);

  digitalWrite(ControlM2B,LOW); 

}

# Josue-Mugas_proyecto-4to4ta
