//Pour le calcul de la valeur de la photorésistance 
#define pin_ldr A1
#define valeurDeLaResistanceFixe 10000  //10k en série avec la photorésistance 
float k= 0.5;
#define tension_alim 3.3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Capteur de lumière LDR
  int val_R_fixe= analogRead(pin_ldr);
  float tension_LDR=(val_R_fixe*tension_alim)/1023.0;
  long LDR = valeurDeLaResistanceFixe * (tension_alim - tension_LDR) / tension_LDR; // Valeur de la résistance LDR
  float Lux = pow(valeurDeLaResistanceFixe/LDR,1.0/k );  //calcul pour convertir en lux 
  Serial.println("Valeur LDR= " + String(LDR) +"Ohms");
  Serial.println("Valeur en lux= " + String(Lux) +"Lux");
  delay(10000);
}
