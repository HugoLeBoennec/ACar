#define IR_PROXIMITY_SENSOR A1 
    #define ADC_REF 5
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
int encoches = 2; //16;       //nombre d encoches de la roue codeuse (1 ou plus)
float trmin;  //vitesse de rotation en tour/min
float vitesse; // vitesse en m/s cette valeur est réelle
int roue = 0.064 / 2; // rayon roue en ms
                     
    float voltage;
                    
    float distance;  //Ici on dÃ©clare notre variable distance qu'on va utiliser
    int test = 0;
    long timer = 0 ; 
    long timer2 = 0;
    long ecart = 0; //Ecart en ms
    //int Vitesse = 8.5 ; //Vitesse en cm/s cette valeur est une constante
    long ecartS;  //ecart en s
    float Place; //Variable donnant en cm la longueur de place libre
    
    void setup()
    {
        // initialise serial communications at 9600 bps:
        Serial.begin(9600);
         Serial.println("Frequencemetre");
    }

     /****************************************************************************/
    /*Function: Get voltage from the sensor pin that is connected with analog pin*/
    /*Parameter:-void                                                       */
    /*Return:   -float,the voltage of the analog pin                        */
    float getVoltage()
    {
        int sensor_value;
        int sum;  
        // read the analog in value:
        for (int i = 0;i < 20;i ++)//Continuous sampling 20 times
        {
            sensor_value = analogRead(IR_PROXIMITY_SENSOR);
            sum += sensor_value;
        }
        sensor_value = sum / 20;
        float voltage;
        voltage = (float)sensor_value*ADC_REF/1024;
        return voltage;
    }

    void ConversionVitesse() {
      vitesse = (2 * PI * roue * trmin / 60) * 100; // fonction pour calculer la vitesse ( en cm/s)//en fonction du tr/mn
                  }

     void Conversion(){
      distance = 27.86 * pow(getVoltage(),-1.15);  //Fonction permettant de convertir les Volts en cm.
             }

    void Conversionecart(){

      ecartS = ecart * pow(10,-3);  //Ici on converti la durée de ms à seconde
      }

    void TaillePlace(){
    Place = vitesse * ecartS ;  // C'est ici qu'à l'aide de la vitesse on calcule la place disponible.
         }


    void loop()
    {   
      // Attendre le signal
  //compensation (étalonnage)
  FreqCounter::f_comp = 10; // Cal Value / Calibrate with professional Freq Counter

  // 10, 100 ou 1000 ms pour une résolution de 100, 10 et 1 Hz
  FreqCounter::start(100);  // 100 ms Gate Time

  // Attendre jusqu'à avoir un comptage terminé
  while (FreqCounter::f_ready == 0)

    // Afficher la mesure de fréquence (et de rotation)
    frq = FreqCounter::f_freq; // a ne pas supprimer permet de calculer le trmn
  //Serial.print(cnt++);
  //Serial.print("  Freq (Hz): ");
  //Serial.print(frq);

  trmin = frq / encoches * 60; //Vitesse de rotation en tour/min
  ConversionVitesse();
 /* Serial.print("  tour/min: ");
  Serial.println(trmin);
  Serial.print(" vitesse en cm/s: ");
  Serial.println(vitesse);*/


  //delay(500);
        voltage = getVoltage();
        Serial.print("sensor voltage  = " );                       
        Serial.println(voltage);      //On affiche ici la distance en Volts capteÃ© par le capteur infrarouge.
        Conversion();                 //Ici on appel la fonction permettant de convertir nos donnÃ©es.
     
        Serial.print("distance en cm = "); 
        Serial.println(distance);       //On affiche ici la distance en cm Ã  partir des volts captÃ©s.
       
        if (((distance-test) > 5)||((distance-test) < -5)){
          //Serial.println("espace");

           do{
     timer = millis();
} while (((distance != test) > 5));  // Ici lorsque le capteur détecte un epsace un timer se déclenche
  
            }
     timer2 = millis();  //quand le capteur arrive à la fin un deuxieme timer s'enclenche
  ecart = timer2 - timer;  // l'ecare en ms se calcule par la différence des deux timer.
      Conversionecart();      //on converti l'ecar en seconde
      TaillePlace();          //on calcule la place disponible
           test = distance;
           if ( ecartS > 3 ){

            Serial.print(" ecart en seconde  = ");  // lorsque l'espace est suffiamment grand on affiche sa taille
          Serial.println(ecartS);
          Serial.println("     ");
           Serial.print(" Taille de la place en cm  = ");
          Serial.println(Place);
          }
          Serial.println("     ");
        Serial.println("     ");
        // wait 500 milliseconds before the next loop
        delay(1000);
    }


 





   
