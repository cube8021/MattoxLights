/*************************************************************************************************************
 * Author: Matthew Mattox mmattox@cube8021.net
 * Last Update: 20140729
 * Purpose: This code was put together to run Arduino Mega 2650 with Vixen 3 Connect Arduino to PC via USB
 * Version: 1.0
 * v1.0 - Imported  20140729
 *_
 * Special Thanks to the following people who guided me to build this code.
 * 
 * -David (DaVaR) Sargent
 * http://www.village4christmas.com/
 * http://www.christmaslighthunt.com/
 *
 * -Scott Shaver @
 * http://doityourselfchristmas.com/forums/showthread.php?23956-Home-Brew-Lighting-System-Arduino-Mega-SainSmart-16-Channel-Relay-Board
 * 
 * -wirenut1980@
 * http://www.instructables.com/id/Arduino-Light-Display-With-Vixen/step7/The-arduino-code/
 *
 * NOTE * The PWM values that need to be sent to the relay board are reversed from the
 * values comming in from Vixen.  Vixen 0-255 (off-on), Relays 255-0 (off-on)
 *************************************************************************************************************/

// Define which pins control which channels with Vixen 3 and Arduino Mega
#define CHAN01  22
#define CHAN02  23
#define CHAN03  24
#define CHAN04  25
#define CHAN05  26
#define CHAN06  27
#define CHAN07  28
#define CHAN08  29
#define CHAN09  30
#define CHAN10  31
#define CHAN11  32
#define CHAN12  33
#define CHAN13  34
#define CHAN14  35
#define CHAN15  36
#define CHAN16  37
#define CHAN17  38
#define CHAN18  39
#define CHAN19  40
#define CHAN20  41
#define CHAN21  42
#define CHAN22  43
#define CHAN23  44
#define CHAN24  45
#define CHAN25  46
#define CHAN26  47
#define CHAN27  48
#define CHAN28  49
#define CHAN29  50
#define CHAN30  51
#define CHAN31  52
#define CHAN32  53

int channels[] = {
  CHAN01,CHAN02,CHAN03,CHAN04,CHAN05,CHAN06,CHAN07,CHAN08,CHAN09,
  CHAN10,CHAN11,CHAN12,CHAN13,CHAN14,CHAN15,CHAN16,CHAN17,CHAN18,CHAN19,CHAN20,
  CHAN21,CHAN22,CHAN23,CHAN24,CHAN25,CHAN26,CHAN27,CHAN28,CHAN29,CHAN30,CHAN31,CHAN32};



// Total Channel Count
#define CHANNEL_COUNT 32

// Serial Speed
#define PC_COM_SPEED 9600


int i = 0;
int incomingByte[CHANNEL_COUNT];

void setup()
{
  Serial.begin(PC_COM_SPEED);

  // Set the channel pins to output mode
  for(int channelIndex=0;channelIndex<CHANNEL_COUNT;channelIndex++){
    pinMode(channels[channelIndex],OUTPUT);
  }

  powerOnSelfTest();
}


void loop()
{
  if (Serial.available() >= CHANNEL_COUNT)
  {
    for (int i=0; i<CHANNEL_COUNT; i++)
    {
      incomingByte[i] = Serial.read();
    }                                       
    digitalWrite(CHAN01, incomingByte[0]);  
    digitalWrite(CHAN02, incomingByte[1]); 
    digitalWrite(CHAN03, incomingByte[2]);  
    digitalWrite(CHAN04, incomingByte[3]); 
    digitalWrite(CHAN05, incomingByte[4]);  
    digitalWrite(CHAN06, incomingByte[5]);  
    digitalWrite(CHAN07, incomingByte[6]);  
    digitalWrite(CHAN08, incomingByte[7]);  
    digitalWrite(CHAN09, incomingByte[8]); 
    digitalWrite(CHAN10, incomingByte[9]);  
    digitalWrite(CHAN11, incomingByte[10]); 
    digitalWrite(CHAN12, incomingByte[11]); 
    digitalWrite(CHAN13, incomingByte[12]); 
    digitalWrite(CHAN14, incomingByte[13]); 
    digitalWrite(CHAN15, incomingByte[14]); 
    digitalWrite(CHAN16, incomingByte[15]);  
    digitalWrite(CHAN17, incomingByte[16]);  
    digitalWrite(CHAN18, incomingByte[17]);  
    digitalWrite(CHAN19, incomingByte[18]);  
    digitalWrite(CHAN20, incomingByte[19]);  
    digitalWrite(CHAN21, incomingByte[20]);  
    digitalWrite(CHAN22, incomingByte[21]);  
    digitalWrite(CHAN23, incomingByte[22]);  
    digitalWrite(CHAN24, incomingByte[23]);  
    digitalWrite(CHAN25, incomingByte[24]);  
    digitalWrite(CHAN26, incomingByte[25]); 
    digitalWrite(CHAN27, incomingByte[26]); 
    digitalWrite(CHAN28, incomingByte[27]); 
    digitalWrite(CHAN29, incomingByte[28]); 
    digitalWrite(CHAN30, incomingByte[29]); 
    digitalWrite(CHAN31, incomingByte[30]);  
    digitalWrite(CHAN32, incomingByte[31]);  
  }
  else
  {
    //// Turn Off all lights while awaiting for Vixen.
    //turnAllLightsOff();
    powerOnSelfTest();
  }
}


void powerOnSelfTest()
{
  Serial.println("Power on self test running.");
  for(int channelIndex=0;channelIndex<CHANNEL_COUNT;channelIndex++){
    Serial.print("Channel: ");
    Serial.println(channelIndex+1,DEC);
    analogWrite(channels[channelIndex], 255); // Turn ON relays one channel at a time
    delay(100); // Wait .1 seconds
    analogWrite(channels[channelIndex], 0);
  }

  turnAllLightsOn(); 
  delay(1000);
  turnAllLightsOff();
  delay(1000);
  turnAllLightsOn(); 
  delay(2000);
  turnAllLightsOff();
}

void turnAllLightsOn()
{
  // Turn all Channels ON
  for(int channelIndex=0;channelIndex<CHANNEL_COUNT;channelIndex++){
    analogWrite(channels[channelIndex], 255);
  }
}

void turnAllLightsOff()
{
  // Turn all Channels OFF
  for(int channelIndex=0;channelIndex<CHANNEL_COUNT;channelIndex++){
    analogWrite(channels[channelIndex], 0);
  }
}

