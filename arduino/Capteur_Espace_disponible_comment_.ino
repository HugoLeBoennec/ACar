#define IR_PROXIMITY_SENSOR A1 // Analog input pin that  is attached to the sensor
    #define ADC_REF 5//reference voltage of ADC is 5v.If the Vcc switch on the Seeeduino
                     //board switches to 3V3, the ADC_REF should be 3.3
    float voltage;//the sensor voltage, you can calculate or find the distance
                    // to the reflective object according to the figures
                    //on page 4 or page 5 of the datasheet of the GP2Y0A21YK.
                    
    float distance;  //Ici on dÃ©clare notre variable distance qu'on va utiliser

     int test = 0;
    
   long timer = 0 ; 
   
  long timer2 = 0;
  
  long ecart = 0; //Ecart en ms

  int Vitesse = 5 ; //Vitesse en cm/s

  long ecartS;  //ecart en s

 int Place; //Variable donnant en cm la longueur de place libre
    
    void setup()
    {
        // initialise serial communications at 9600 bps:
        Serial.begin(9600);

       

    }

    
    void Conversion(){

      distance = 27.86 * pow(getVoltage(),-1.15);  //Fonction permettant de convertir les Volts en cm.
                                                   //On utilise ici 
  }

    void Conversionecart(){

      ecartS = ecart * pow(10,-3);  //Ici on converti la durée de ms à seconde

      
    }

    void TaillePlace(){


      Place = Vitesse * ecartS ;  // C'est ici qu'à l'aide de la vitesse on calcule la place disponible.

      

      
    }


    void loop()
    {
        voltage = getVoltage();
        Serial.print("sensor voltage  = " );                       
        Serial.println(voltage);      //On affiche ici la distance en Volts capteÃ© par le capteur infrarouge.
        Conversion();                 //Ici on appel la fonction permettant de convertir nos donnÃ©es.
     
        Serial.print("distance en cm = "); 
        Serial.println(distance);       //On affiche ici la distance en cm Ã  partir des volts captÃ©s.
       
        if (((distance-test) > 5)||((distance-test) < -5)){
          Serial.println("OK");

           do
{
     timer = millis();
} while (((distance != test) > 5));  // Ici lorsque le capteur détecte un epsace un timer se déclenche
  
            }
     timer2 = millis();  //quand le capteur arrive à la fin un deuxieme timer s'enclenche


                /*Serial.print(" timer = ");
                Serial.println(timer);
                Serial.println("     ");
                Serial.print(" timer2 = ");
                Serial.println(timer2);*/

      ecart = timer2 - timer;  // l'ecare en ms se calcule par la différence des deux timer.
      Conversionecart();      //on converti l'ecar en seconde
      TaillePlace();          //on calcule la place disponible

            
          test = distance;

          if ( ecartS > 5 ){

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

