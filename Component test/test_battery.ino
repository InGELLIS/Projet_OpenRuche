// Pour le calcul de la batterie 
#define pin_mes_batt A0
#define valeur_max_batt 3.17 //680k*4.2/(220k+680k)
#define valeur_min_batt 2.26 //680k*3.0/(220k+680k)
#define tension_alim 3.3
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  // Mesure de la tension de la batterie sur la broche A0
  int valeur_batt = analogRead(pin_mes_batt); // Mesure de la tension de la batterie sur la broche A0
  float tension = (valeur_batt*tension_alim)/1023.0; // Transforme la mesure (nombre entier) en tension via un produit en croix, 1024 = Valeur max pour 5.79 du convertisseur
  float Pourcent=(tension-valeur_min_batt)/(valeur_max_batt-valeur_min_batt)*100; 
  Serial.println("Tension batt = " + String(tension) +" V");
  Serial.println("Pourcentage batt = " + String(Pourcent) +" %");
  delay(3000);

}
