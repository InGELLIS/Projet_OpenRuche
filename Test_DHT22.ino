#include <DHT.h>
#define DHTPIN0 0
#define DHTPIN1 1 
#define DHTTYPE    DHT22
DHT dht1(DHTPIN0, DHTTYPE);
DHT dht2(DHTPIN1, DHTTYPE);



// ========================
// Initialisation programme
// ========================
void setup () {
  
  // Initialisation de la liaison série (pour retourner les infos au moniteur série de l'ordi)
  Serial.begin(9600);
  Serial.println("Programme de test du DHT22");
  Serial.println("==========================");
  Serial.println();

  

  
}


// =================
// Boucle principale
// =================
void loop () {
  // Lecture des données
   // DHT22 INTERIEUR
    dht1.begin();
    float temp1=dht1.readTemperature();
    float hum1=dht1.readHumidity();
    

    // DHT22 EXTERRIEUR
    dht2.begin(); 
    float temp2 = dht2.readTemperature();
    float hum2 = dht2.readHumidity();
    
    
    Serial.println("Temperature DHT22 intérieure 0 = " +String(temp1) +" °C");
    Serial.println("Temperature DHT22 extérieure 1  = " + String(temp2) +" °C");
    Serial.println("Humidite DHT22 intérieure 0= " + String(hum1) +" %");
    Serial.println("Humidite DHT22 extérieure  1= " + String(hum2) +" %");
  // Temporisation de 2 secondes (pour rappel : il ne faut pas essayer de faire plus d'1 lecture toutes les 2 secondes, avec le DHT22, selon le fabricant)
  delay(2000);
}