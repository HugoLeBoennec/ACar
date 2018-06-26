#include <VirtualWire.h> 

int RF_RX_PIN = 6; 

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
 Serial.println((char *)buf);
    }
}
