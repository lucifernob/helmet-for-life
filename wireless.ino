#include <VirtualWire.h>            //Including library

//Initialise pins
int relay=7;      
int receive_pin=4;

void setup()
{
   Serial.begin(9600); 
   vw_set_rx_pin(receive_pin);
   vw_setup(4000);                              // Transmission rate same as in transmitter
   vw_rx_start();                               // Start the receiver
   pinMode(relay, OUTPUT);
}

void loop()
{
   uint8_t buf[VW_MAX_MESSAGE_LEN];
   uint8_t buflen = VW_MAX_MESSAGE_LEN;
 
   // Checking if a message was received or not
    if (vw_get_message(buf, &buflen)) 
    {
      if(buf[0]=='1')
      {
      digitalWrite(relay,HIGH);                 //Connect relay and complete circuit
      delay(500);
      }
     else
     {
     digitalWrite(relay,LOW);                     //Disconnect the circuit
     delay(500); 
     }
   }
}
