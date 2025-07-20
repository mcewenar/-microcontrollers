const int pinBoton = 18; //Le asigno a la constante pinBoton un valor al pin 18

void setup(){
  //Activa el monitor serial para poder imprimir mensajes en la consola.
  Serial.begin(9600); 

  //Configura el pin 18 como entrada digital y activa la resistencia pull-up interna del ESP32.
  //Los ESP32 tienen resistencia interna incorporada, a diferencia de los Arduino UNO
  pinMode(pinBoton, INPUT_PULLUP);
}

void loop(){
  //Lee el estado del botón en ese momento: donde HIGH (1) = no presionado
  //LOW (0) = presionado
  int estado = digitalRead(pinBoton); 

  //Entonces, si 
  if(estado == LOW){ 
    Serial.println("Botón presionado (LOW).");
  }
  else{
    Serial.println("Botón no presionado (HIGH).");
  }

//Detiene el programa durante 5000 milisegundos = 5 segundos.
  delay(5000); 
}
