#define IR_PROXIMITY_SENSOR A1 // Analog input pin that  is attached to the sensor
    #define ADC_REF 5//reference voltage of ADC is 5v.If the Vcc switch on the Seeeduino
                     //board switches to 3V3, the ADC_REF should be 3.3
    float voltage;//the sensor voltage, you can calculate or find the distance
                    // to the reflective object according to the figures
                    //on page 4 or page 5 of the datasheet of the GP2Y0A21YK.
    float distance;  //Ici on déclare notre variable distance qu'on va utiliser
    void setup()
    {
        // initialise serial communications at 9600 bps:
        Serial.begin(9600);

    }

    void Conversion(){

      distance = 27.86 * pow(getVoltage(),-1.15);  //Fonction permettant de convertir les Volts en cm.
                                                   //On utilise ici 
      
    }
    int test = 0;
    void loop()
    {
        voltage = getVoltage();
        Serial.print("sensor voltage  = " );                       
        Serial.println(voltage);      //On affiche ici la distance en Volts capteé par le capteur infrarouge.
        Conversion();                 //Ici on appel la fonction permettant de convertir nos données.
     
        Serial.print("distance en cm = "); 
        Serial.println(distance);       //On affiche ici la distance en cm à partir des volts captés.
        if (((distance-test) > 5)||((distance-test) < -5)){
          Serial.println("OK");
        }
        test = distance;
          Serial.println("    ");
        // wait 500 milliseconds before the next loop
        delay(500);
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
