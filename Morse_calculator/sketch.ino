/*
Implementación de una “calculadora binaria especial”:
  •El programa realizara cuatro operaciones sobre dos números binarios y el resultado lo mostrara por medio de un led como código Morse.
  •Las entradas son dos números binarios de dos bits A y B.
  •Las operaciones a realizar tiene un código binario asignado de dos bits que también debe ser dado.
  •00 suma de A+B
  •01 Resta de A-B
  •10 operación XORentre A xor B
  •11 Operación ORentre A or B
  •La salida es serial y corresponde al número decimal equivalente de la respuesta binaria.

*/
//NOTACIÓN DE NÚMEROS EN CÓDIGO MORSE:
//PUNTO = 200ms 
//ESPACIO DE TIEMPO = 300ms
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


    00 -> SUMA (A+B)
    01 -> RESTA (A-B)
    10 -> XOR (A xor B)
    11 -> OR (A or B)

  explicación a Alto nivel:
  BINARIO (inoput1,input2) -> DECIMAL -> OPERAACIÓN EN DECIMALES -> MORSE
*/

const int led1 = 18;

void setup() {
  //Inicialización
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  Serial.print("Calculadora Binaria");

}

void loop() {
  //Representación en Binario de cada parámetro y operación
  String A = "10"; //2 decimal
  String B = "01"; //1 decimal
  String OP = "00"; // Suma

  int resultadoDecimal = operation(A, B, OP);
  Serial.print("Resultado decimal: ");
  Serial.println(resultadoDecimal);
  
  digitalWrite(led1, HIGH);

  String morse = String(resultadoDecimal); //Casteo de decimal a string
  enviarMorse(morse);

  delay(5000);
}

int operation(String a, String b, String OP) {
  //Acá pasamos de Binario a decimal, gracias a la función binarioADecimal
  int numA = binarioADecimal(a);
  int numB = binarioADecimal(b);
  int op = binarioADecimal(OP);

  switch(op){
    case 0: return numA + numB;
    case 1: return numA - numB;
    case 2: return numA ^ numB;
    case 3: return numA | numB;
    default: return 0;
  }
}

//Fuente: https://www.programiz.com/java-programming/examples/binary-decimal-convert
int binarioADecimal(String bin) {
  int decimalNumber = 0;
  int i = 0;
  int remainder;
  long binInt = bin.toInt();

  while (binInt != 0) {
    remainder = binInt % 10;
    binInt = binInt / 10;
    decimalNumber = remainder * pow(2, i) + decimalNumber;
    ++i;
  }

  return decimalNumber;
}


    /*int resultado = 0;
  if(bin.charAt(0) == '1'){
    resultado += 2; // El primer bit vale 2 (2 elevado a la 1)
  }
  if(bin.charAt(1) == '1'){
    resultado += 1; // El segundo bit vale 1 (2 elevado a la 0)
  }
  return resultado;
  */

//PUNTO = 200ms
//ESPACIO DE TIEMPO = 300ms
//RAYA = 600ms
void enviarMorse(String numero){
  String codigoMorse = convertirAMorse(numero.charAt(0));
  Serial.print("Código Morse: ");
  Serial.println(codigoMorse);
  for(int i=0; i<codigoMorse.length(); i++){
    digitalWrite(led1, HIGH);
    if(codigoMorse.charAt(i) == '.'){
      delay(200); // Punto
    }else if(codigoMorse.charAt(i) == '-'){
      delay(600); // Raya
    }
    digitalWrite(led1, LOW);
    delay(300); // Espacio entre señales
  }
  delay(800); // Espacio final entre caracteres
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

