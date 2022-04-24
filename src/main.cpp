#include <Arduino.h>
#include <SoftwareSerial.h>

/*  ~ Simple Arduino - xBee Receiver sketch ~ Coordinator
 */

SoftwareSerial zigbee(12, 11);
char received;

bool started = false; // True: Message is strated
bool ended = false;   // True: Message is finished
byte i;           // Index of array

char character; // Variable to store the incoming byte
char msg[13];   // Message - array



void packetCheck() {

  while (Serial.available())
  {
    character = Serial.read();
    if (character == '<')
    {
      started = true;
      i = 0;
      msg[i] = '\0'; // Throw away any incomplete packet
    }

    // End the message when the '>' symbol is received
    else if (character == '>')
    {
      ended = true;
      break; // Done reading - exit from while loop!
    }

    // Read the message!
    else
    {
      if (i < 11)
      {                         // Make sure there is room
        msg[i] = character; // Add char to array
        i++;
        msg[i] = '\0'; // Add NULL to end
      }
    }
  }

  if (started && ended)
  {
    Serial.print("Message: ");
    Serial.println(msg);

    i = 0;
    msg[i] = '\0';
    started = false;
    ended = false;
  }

}

void setup()
{
  Serial.begin(9600);
  zigbee.begin(9600);
}

void loop()
{

  if (zigbee.available() > 0) {
    received = zigbee.read();
    if(received == '0') {
      Serial.print("Off");
    }
    else if(received == '1') {
      Serial.println("On");
    }
  }
  // packetCheck();
}
