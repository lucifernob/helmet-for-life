#include <VirtualWire.h>        //Including library

//Initialise pins
int led_pin = 6;
int transmit_pin = 12;
int ir_sensor = 2;
int val = 0;

void setup()
{
  Serial.begin(9600);
  vw_set_tx_pin(transmit_pin);
  vw_setup(4000);                 // Transmission rate
  pinMode(led_pin, OUTPUT);       // Led is an output device
  pinMode(ir_sensor, INPUT);       // Led is an input device
}

void loop()
{
  char msg[1] = {'0'};
  val = digitalRead(ir_sensor);               // Get sensor value
  Serial.println(val);                        // Print value  
  
  //Check if motion is detected
  if (val == 1)
  {
    msg[0] = '1';
    digitalWrite(led_pin, 1);       //Led flashing to show transmitting
    vw_send((uint8_t *)msg, 1);     //send message
    vw_wait_tx();                   // Wait until the whole message is gone
    delay(500);
  }
  else
  {
    msg[0] = '0';
    digitalWrite(led_pin, 0);       //led off when not detecting
    vw_send((uint8_t *)msg, 1);     //send message
    vw_wait_tx();                   // Wait until the whole message is gone
    delay(500);
  }
}
