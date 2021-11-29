#include <Servo.h>
 //librerias del servo
Servo servo1;       //solo contabamos con 1 servomotor

String entradaSerial = "";    //String para almacenar la entrada del serial
bool entradaCompleta = false; //indicar que el string esta completo

int pin = 9;                  //pin donde se conecra el servo
int pulsoMinimo = 580;        //duracion de microsegundos del puslo min
int pulsoMaximo = 2500;       //duracion de microsegundos del puslo max
int angulo = 0;               //variable para guardar el anguno deseado

void setup()
{
  servo1.attach(pin, pulsoMinimo, pulsoMaximo);
  Serial.begin(9600);
}

void loop()
{
  if (entradaCompleta){
    if(entradaSerial == "izq1\n") {
      Serial.print("0 grados\n");
      //se manda a escribir el angulo deseado del giro
      servo1.write(0);
    }
    else if (entradaSerial == "izq2\n") {
      Serial.print("30 grados\n");
      //se manda a escribir el angulo deseado del giro
      servo1.write(30);
    }
    else if (entradaSerial == "izq3\n") {
      Serial.print("60 grados\n");
      //se manda a escribir el angulo deseado del giro
      servo1.write(60);
    }
    else if (entradaSerial == "ctr\n") {
      Serial.print("Centro a 90 grados\n");
      //se manda a escribir el angulo deseado del giro
      servo1.write(90);
    }
    else if (entradaSerial == "der3\n") {
      Serial.print("120 grados\n");
      //se manda a escribir el angulo deseado del giro
      servo1.write(120);
    }
    else if (entradaSerial == "der2\n") {
      Serial.print("150 grados\n");
      //se manda a escribir el angulo deseado del giro
      servo1.write(150);
    }
    else if (entradaSerial == "der1\n") {
      Serial.print("180 grados\n");
      //se manda a escribir el angulo deseado del giro
      servo1.write(180);
    }
    else { //En caso de recibir cualquier otro dato recibido
      Serial.print("El dato que se recibió no es válido, verificar");
    }
    entradaSerial = "";
    entradaCompleta = false;
  }
}

//funcion que se activa al recibir algo por puerto serie
//o interrupcion del puertoserie
void serialEvent(){
  while (Serial.available()){
    //obtiene bytes de entrada
    char inChar = (char)Serial.read();
    //Agregaal string de entrada:
    entradaSerial += inChar;
    //para saber si el string esta completo se detendrá al recibirr inf
    // el caracter de retorno dela lienea y entrer
    if (inChar == '\n'){
      entradaCompleta = true;
    }
  }
}
