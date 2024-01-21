#include "HX711.h"

#define LOADCELL_DOUT_PIN  11
#define LOADCELL_SCK_PIN  12
#define DONE_PIN 9   // Broche DONE du TPL5110 connectée à la broche 2 de l'Arduino
#define DELAY_PIN 10
HX711 scale;

float calibration_factor = 13350; //-7050 cette variable à régler selon le capteur de poids, 235 avant, 13350 de tare avec une incertitude de .1 à .2
 
void setup() {
  Serial.begin(115200);
  Serial.println("HX711 calibration sketch");
  /*Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");*/
 
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  /*scale.set_scale();*/
  scale.tare(); //Reset the scale to 0
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  

  
  //long zero_factor = scale.read_average(); //Get a baseline reading
  //Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  //Serial.println(zero_factor);
}

void loop() {
  Serial.print("Reading: ");
  float poids =scale.get_units()/2.2046-4.6;
  Serial.println("Poids = " + String(poids) +" kg");
  //Serial.print(" calibration_factor: ");
  //Serial.print(calibration_factor);
 
  /*if(Serial.available())    //permet de calibrer en direct via le moniteur série
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 10;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 10;
  }*/
delay(1000);
}
