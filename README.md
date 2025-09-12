carpeta dia 2

en el  dia de hoy en el colegio estuvimos viendo servomotores y la manera de dividir el codigo en funciones
aparte en el dia pudimos implementar de manera casi perfecta el sensor de distancia ultrasonico  
el codigo termino siendo el siguiente:
//entrada motores
# define ENTRADAM1 5
# define ENTRADAM2 6
// Control motoresr
# define ControlM1A 7
# define ControlM1B 8
// Control motor2
# define ControlM2A 9
# define ControlM2B	11
//sensor de sonido
# define trig 12
# define echo 13
float tiempo,distancia;
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
 		//sensores//
  pinMode( 2,INPUT);
  pinMode( 4,INPUT);
  pinMode(10,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop()
{
          //Sensores de luz
    int sensor1,sensor2,sensor3;
    sensor1=digitalRead(2);
    sensor2=digitalRead(4);
    sensor3=digitalRead(10);
    if(sensor1==HIGH && sensor3==LOW && sensor2==LOW){
      derecha();
    }
    else if(sensor3==HIGH && sensor2==LOW && sensor1==LOW){
      izquierda();
    }
    else if (sensor2==HIGH && sensor3==HIGH && sensor1==HIGH){
      atras();
    }
  	else if (sensor2==LOW && sensor3==LOW && sensor1==LOW){
    		//sensor de sonido
      digitalWrite (trig,LOW);
      delay(0.2);
      digitalWrite (trig, HIGH);
      delay(0.10);
      digitalWrite (trig, LOW);
      tiempo= pulseIn (echo,HIGH);
      distancia =(tiempo/2)/29.15;
      Serial.print (distancia);
      Serial.println ("cm");
      if (distancia<=150){  
        avanzar();
      }else{
      	parar();
  	  }
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
con esto el robot ira en la direccion del enemigo si es que este esta a un metro o menos de el y en el caso de que no lo este encontrando se queda verificando si es q sigue dentro del ring o si toca la linea del ring (suponiendo que las lineas del ring sean negras y el interior sea negro)
el principal problema que tenemos es la poca cantidad de pines que tiene el arduino debemos buscar una manera de conseguir más pines. 
asi quedo el esquema final  
