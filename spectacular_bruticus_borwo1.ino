#include <Servo.h>
#define atras 2
#define adelante 3

Servo servo1,servo2;
int grados;
bool avanzar,retroceder;
void setup()
{
	servo1.attach(A1);
  	servo2.attach(A2);
  	servo1.write(0);
  	servo2.write(0);
	pinMode(adelante, INPUT);
  	pinMode(atras, INPUT);
    Serial.begin(9600);
}

void loop()
{
  
  avanzar=digitalRead(3);
  retroceder=digitalRead(2);
  if (avanzar==LOW){
  	avanza();
  }
  if (retroceder==LOW){
    atrasas();
  }
  Serial.println(avanzar);
  Serial.println(retroceder);

}
void avanza(){
  	grados+=10;
	servo1.write(grados);
  	servo2.write(grados);
     delay(1000);
  
}
void atrasas(){
  	grados-=10;
  	if(grados<0){
    	grados=0;
    }
	servo1.write(grados);
  	servo2.write(grados);
    delay(1000);
  
}