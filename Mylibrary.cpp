#include "Mylibrary.h"

void parla(){
  Serial.println("Ciao, sto parlando");
}//parlare

byte calculateChecksum(byte messaggio[], int nByte) {
  byte somma = 0x00;
  int k = 0;
  for(int i=2; i<nByte-2; i++) { //somma dei byte, saltando lo start e l'end
  //manca il controllo del doppio 0x07 su data
    if (i>4 && i<nByte-3) {
      if(messaggio[i] == 0x07) k++;

      if(k > 1) continue;
    }
    somma = somma + messaggio[i];
  }
  somma = somma + 0xAD; //aggiungo 173

  if (somma > 0xFF) {
    somma = somma - 0x100;
  }
  return (byte)somma;
}

void stampaMessaggio(byte messaggio[], int nByte) {
  for(int i = 0; i<nByte; i++) {
     if(i == 0){
        Serial.print("Start: ");
      }
      if(i == 2){
        Serial.print("\tCommand: ");
      }
      if(i == 4){
        Serial.print("\tByteCount: ");
      }
      if(nByte > 8 && i == 5){
        Serial.print("\tData: ");
      }
      if(i == nByte-3){
        Serial.print("\tChecksum: ");
      }
      if(i == nByte-2){
        Serial.print("\tEnd: ");
      }
  Serial.print(messaggio[i]);
  Serial.print(" ");
  }
}
