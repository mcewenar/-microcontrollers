//NOTACIÓN DE NÚMEROS EN CÓDIGO MORSE:
//PUNTO = 200ms = ESPACIO DE TIEMPO
//RAYA = 600ms
/*case '0': return "-----";
    1:".----"
    2:"..---"
    3:"...--"
    4:"....-"
    5:"....."
    6:"-...."
    7:"--..."
    8:"---.."
    9:"----."
    INDETERMINADO: ""
*/


const int pinBoton = 18; //Le asigno a la constante pinBoton un valor al pin 18

// Pines para LEDs
const int led1 = 5;
const int led2 = 18;
const int led3 = 19;
const int led4 = 21;
void setup(){
  //Activa el monitor serial para poder imprimir mensajes en la consola.
  Serial.begin(9600); 

  //Configura el pin 18 como entrada digital y activa la resistencia pull-up interna del ESP32.
  //Los ESP32 tienen resistencia interna incorporada, a diferencia de los Arduino UNO
  pinMode(pinBoton, INPUT_PULLUP);

  //Configurar pines de los LEDs como salida
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop(){
  //Lee el estado del botón en ese momento: donde HIGH (1) = no presionado
  //LOW (0) = presionado
  int estado = digitalRead(pinBoton); 

  //Entonces, si se presiona el botón, es decir
  if(estado == LOW){ 
    Serial.println("Botón presionado (LOW).");
    mostrarMorse("9530");
    delay(2000); //paiusa de 3segundos
  }
  
}

//Establezco q "." = 200ms y "-" = a 600ms.
void mostrarMorse(String numeros){
  for(int i=0; i < numeros.length(); i++){
    char digito = numeros[i];
    String morse = convertirAMorse(digito);
    
    Serial.print("Morse de ");
    Serial.print(digito);
    Serial.print(": ");
    Serial.println(morse);

    for(int j=0; j < morse.length(); j++){
      if(morse[j] == '.'){
        encenderLeds(200); // punto corto
      } else if(morse[j] == '-'){
        encenderLeds(600); // raya larga
      }
      delay(200); //espacio entre símbolos
    }
    delay(600); // espacio entre dígitos
  }
}

String convertirAMorse(char digito){
  switch(digito){
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    default: return "";
  }
}

void encenderLeds(int duracion){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(duracion);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}