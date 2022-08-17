
/*LIBRARIES
 *  The first three libraries are included in standard Arduino IDE installations
 *  The last three libraries should be be downloaded from github and installed manually.
 *  Additionally, the Adafruit_ADS1015 library requires the Adafruit_I2CDevice library, if you do not already have it.
 */
#include <Wire.h>               //standard library
#include <SPI.h>                //standard library
#include <Adafruit_ADS1X15.h>   //Version 2.2.0  https://github.com/adafruit/Adafruit_ADS1X15

/*
 *  CONFIGURATION SETTINGS
 */
 
#define pLED2 2
#define pLED1 3
#define pLED0 4 
#define NUM_SAMPLES 1000

//communications vars
const int MAX_CHAR = 60;            //max num character in messages
char messageBuffer[MAX_CHAR];       //buffer for sending and receiving comms

//time settings
unsigned long millisTime;
long currentTime = 0;

//ADC vars
Adafruit_ADS1115 ads;
int gain;

/* SETUP
* Initialize ADC
 */

void setup() {
  delay(100); //allow power to stabilize

  //if anything writes to these before started, it will crash.
  Serial.begin(115200);
  Serial.setTimeout(50);
  Wire.begin();
  digitalWrite(pLED2, HIGH);
  
  //initialize the ADC
  ads.setGain(GAIN_ONE); 
  ads.begin(0x48); 
  ads.setDataRate(RATE_ADS1115_860SPS); 
  ads.readADC_SingleEnded(0);
  } 

/* LOOP
 *  read sensor
 */

int counter = 1;
double sval=0;
int16_t adc = 0;
double adc0;
float volts0;
static unsigned int averageValue0 = 0;
static unsigned char collectedSample = 0;

const int numReadings = 50; 
int readings[numReadings];
int readIndex = 0 ;
double total = 0; 
double average;

double smooth()  //Rolling average smoothing of continual ADC readings 
{
  total = total - readings[readIndex];
  readings[readIndex]= ads.readADC_SingleEnded(0);
  total = total + readings[readIndex];
  readIndex = readIndex + 1;
  if (readIndex>=numReadings) {
    readIndex=0;
  }
  average = total/numReadings;
  return average;
  }

void loop() {
  millisTime = millis();
  adc0 += ads.readADC_SingleEnded(0);
  if (++collectedSample >= 1) {
    adc0 /= 1;
    adc = smooth();
    sprintf(messageBuffer,"%05d,%05d,%05d",averageValue0,adc,averageValue0);
    Serial.println(messageBuffer);
    counter++;
    collectedSample=0;
    adc0 = 0;
  }
}
 
