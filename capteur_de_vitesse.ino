//===Détection de présence avec une fourche optique
// tiptopboards 22 08 2013
//
// Branchement du capteur sur pin5 digital
//==========================================================

// Pins utilisées
const int fourchePin = 5;     //Sortie de la fourche pin5
const int ledPin =  9;        // LED témoin sur pin

int EtatFourche =0 ;

// Initialisation
void setup() {
  Serial.begin(9600);   //connection au port série 
  pinMode(ledPin, OUTPUT);     //LED en sortie
  pinMode(fourchePin, INPUT);  //en entrée
  Serial.println("Fourche optique - detection de presence");
}

//=== Boucle de mesures
void loop() {
  //Vérifie si un objet obture la fourche optique
  EtatFourche = digitalRead(fourchePin);
  Serial.print("Etat ");
  if (EtatFourche == HIGH) {     
    // Allumer la LED témoin
    digitalWrite(ledPin, HIGH); 
     Serial.println("Presence"); 
  } 
  else {
    // Eteindre la LED
    digitalWrite(ledPin, LOW); 
    Serial.println("Vide"); 
  }
  delay(200);
}  

//===Mesure de fréquence avec la librairie FreqCounter
// tiptopboards 22 08 2013
// Source : http://interface.khm.de/index.php/lab/experiments/arduino-frequency-counter-library/
//
// Branchement du capteur sur pin5 digital
//==========================================================
/*
  Martin Nawrath KHM LAB3
  Kunsthochschule f¸r Medien Kˆln
  Academy of Media Arts
  http://www.khm.de
  http://interface.khm.de/index.php/labor/experimente/   
 */
 
#include <FreqCounter.h>  //Inclure la librairie de fréquence

// Variables utilisées
unsigned long frq;    //fréquence mesurée
int cnt;              //nombre de mesures réalisées
int encoches=2;  //16;       //nombre d encoches de la roue codeuse (1 ou plus)
float trmin;  //vitesse de rotation en tour/min

// Initialisation
void setup() {
  Serial.begin(9600);   //connection au port série 
  Serial.println("Frequencemetre");
}

// === Boucle de mesures
void loop() {
  // Attendre le signal
  //compensation (étalonnage)
  FreqCounter::f_comp=10;   // Cal Value / Calibrate with professional Freq Counter

  // 10, 100 ou 1000 ms pour une résolution de 100, 10 et 1 Hz  
  FreqCounter::start(100);  // 100 ms Gate Time

  // Attendre jusqu'à avoir un comptage terminé
  while (FreqCounter::f_ready == 0) 
  
 // Afficher la mesure de fréquence (et de rotation)
  frq=FreqCounter::f_freq;
  Serial.print(cnt++);
  Serial.print("  Freq (Hz): ");
  Serial.print(frq);
  
  trmin = frq/encoches*60;  //Vitesse de rotation en tour/min
  Serial.print("  tour/min: ");
  Serial.println(trmin);
  delay(500);
}  
