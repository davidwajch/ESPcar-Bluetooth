#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
const int motorAF = 32;
const int motorAT = 18;
const int motorBF = 19;
const int motorBT = 21;
void setup() {
  Serial.begin(115200);
  SerialBT.begin("LENDA"); // Nome do dispositivo Bluetooth
  Serial.println("O dispositivo Bluetooth está pronto para parear");

  pinMode(motorAF, OUTPUT); 
  pinMode(motorAT, OUTPUT); 
  pinMode(motorBF, OUTPUT); 
  pinMode(motorBT, OUTPUT); 
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();

    switch (command) {
      case 'W':
        frente();
        break;
      case 'S':
        tras();
        break;
      case 'A':
        esquerda();
        break;
      case 'D':
        direita();
        break;         
      default:
        pareCarro();
        break;
    }
  }
}

void frente() {
  digitalWrite(motorAF, HIGH);
  digitalWrite(motorAT, LOW);
  digitalWrite(motorBF, HIGH);
  digitalWrite(motorBT, LOW);

}

void tras() {
  digitalWrite(motorAF, LOW);
  digitalWrite(motorAT, HIGH);
  digitalWrite(motorBF, LOW);
  digitalWrite(motorBT, HIGH);

}

void esquerda() {
    digitalWrite(motorAF, HIGH);
  digitalWrite(motorAT, LOW);
  digitalWrite(motorBF, LOW);
  digitalWrite(motorBT, HIGH);
}

void direita() {
  digitalWrite(motorAF, LOW);
  digitalWrite(motorAT, HIGH);
  digitalWrite(motorBF, HIGH);
  digitalWrite(motorBT, LOW);

}

void pareCarro() {
  digitalWrite(motorAF, LOW);
  digitalWrite(motorAT, LOW);
  digitalWrite(motorBF, LOW);
  digitalWrite(motorBT, LOW);

}
