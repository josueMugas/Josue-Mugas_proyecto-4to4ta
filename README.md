# Josue-Mugas_proyecto-4to4ta


en el primer día durante la clase hicimos el TP3 y empezamos a investigar los diferentes modelos materiales y diseños de los robots de sumo vimos videos de cómo manejar motores puentes h y sensores de luz ambiental  

este fue el primer diseño de los motores que pudimos hacer funcionar con objetos sobrantes como los sensores ultrasónicos y el ir que terminamos sin usar 

void setup() {

  pinMode(3, OUTPUT);
  
  pinMode(4, OUTPUT);
  
  pinMode(5, OUTPUT);
  
  pinMode(6, OUTPUT);
  
}

void loop() {

  left();
  
}

void right() {

  digitalWrite(3,LOW);
  
  digitalWrite(4,HIGH);
  
  digitalWrite(5,LOW);
  
  digitalWrite(6,HIGH); 
  
}

void left() {

  digitalWrite(3,HIGH);
  
  digitalWrite(4,LOW);
  
  digitalWrite(5,HIGH);
  
  digitalWrite(6,LOW); 

}

void forward() {

  digitalWrite(3,LOW);
  
  digitalWrite(4,HIGH);

  digitalWrite(5,HIGH);
  
  digitalWrite(6,LOW); 
  
}

void backward() {

  digitalWrite(3,HIGH);
  
  digitalWrite(4,LOW);
  
  digitalWrite(5,LOW);
  
  digitalWrite(6,HIGH); 
  
}

este fue el primer código utilizado y encontrado en YouTube tras la investigación 
