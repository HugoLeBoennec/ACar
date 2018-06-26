#include <VirtualWire.h> 

int RF_RX_PIN = 6; 
int num = 0;
int numero = 0;

void setup() 
{
  Serial.begin(9600);
  Serial.println("setup"); 
  vw_set_rx_pin(RF_RX_PIN);  // Setup receive pin. 
  vw_setup(2000); // Transmission speed in bits per second. 
  vw_rx_start(); // Start the PLL receiver. 
} 

void loop() 
{ 

  uint8_t buf[12]; 
  uint8_t buflen = sizeof buf; 
  if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      if (numero == 0){
        if ((char *)buf == "P")numero = 1;
        else if ((char *)buf == "D") numero = 3;
      }
      else if (numero == 1){
        numero = 2;
        num = atoi((char *)buf);
        Serial.print("Px = ");
        Serial.println(num);
      }
      else if (numero == 2){
        num = atoi((char *)buf);
        Serial.print("Py = ");
        Serial.println(num);
        numero = 0;
      }
      else if (numero == 3){
        num = atoi((char *)buf);
        Serial.print("Distance = ");
        Serial.println(num);
        numero = 0;
      }
    }
}
