

/*
  Test strings for serial monitor
  $OPENOBS*4A
  $SET,1616605996,10*7E
*/

/*TODO
*/

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
 
//firmware data
#define pLED2 2
#define pLED1 3
#define pLED0 4 
#define NUM_SAMPLES 115
#define warm 100 

//58 = 50 samples

//communications vars
const int MAX_CHAR = 60;            //max num character in messages
char messageBuffer[MAX_CHAR];       //buffer for sending and receiving comms

//time settings
unsigned long millisTime;
long currentTime = 0;

byte LEDArray[] = {pLED0, pLED1, pLED2};
int bufferVal[]={0,0,0};
byte LEDArrayLength = sizeof(LEDArray)/sizeof(LEDArray[0]);
int16_t darkArray[NUM_SAMPLES];
int16_t lightArray[NUM_SAMPLES];
int16_t dark, darkSD = 0; 
int16_t LED0, LED1, LED2 = 0; 
int16_t LED0SD, LED1SD, LED2SD = 0; 
int collectedSample = 0; 

//ADC vars
Adafruit_ADS1115 ads;
int gain;

/* SETUP
 *  try to establish coms with GUI
 *  initiate components
 *  warm for settings or use default
 *  create text file
 */

void setup() {
  delay(100); //allow power to stabilize

  //if anything writes to these before started, it will crash.
  Serial.begin(115200);
  Serial.setTimeout(50);
  Wire.begin();

  
  //initialize the ADC
  ads.setGain(GAIN_TWO); //reset gain
  ads.begin(0x48);  // Initialize ads1115
  ads.setDataRate(RATE_ADS1115_860SPS); //set the sampling speed
  ads.readADC_SingleEnded(0); //throw one reading away. Seems to come up bad.
  Serial.println("initializing adc, reading...."+ads.readADC_SingleEnded(0));
  bool adc_init = ads.readADC_SingleEnded(0) != -1;
  //LED test sequence 
  for (int k=0;k<5 ;k++){
    for (int i = 0; i < LEDArrayLength; i++) {
    digitalWrite(LEDArray[i], HIGH);
    }
    delay(250);
    for (int i = 0; i < LEDArrayLength; i++) {
    digitalWrite(LEDArray[i], LOW);
    }
    delay(250);
  }
  dark = darkSample();
  
}

/* LOOP
 *  read sensor
 */

int counter = 1;
int16_t adc = 0;
double adc0;
float volts0;
int16_t LEDVal = 0; 
int32_t darkAvg = 0;
int16_t temp; 
int32_t sum=0; 

double darkSample(){
  for (int i = 0; i < LEDArrayLength; i++) {
    digitalWrite(LEDArray[i], LOW);
    }
  delay(warm);
  for (int i; i < NUM_SAMPLES;i++){
    darkArray[i] = ads.readADC_SingleEnded(0);
    sum+= darkArray[i];
  }
  dark = sum/NUM_SAMPLES;
  sum = 0;
  return dark;
}

double LEDSample(byte LED){
  digitalWrite(LED, HIGH);
  delay(warm);
  for (int i=0; i < NUM_SAMPLES;i++){
  lightArray[i] = ads.readADC_SingleEnded(0);
  sum+=lightArray[i];
  }
  digitalWrite(LED,LOW);
  LEDVal = sum/NUM_SAMPLES;
  sum = 0; 
  return LEDVal;
}

double calculateSD(int data[]) {
    float sum = 0.0, mean, SD = 0.0;
    int i;
    for (i = 0; i < 10; ++i) {
        sum += data[i];
    }
    mean = sum / 10;
    for (i = 0; i < 10; ++i) {
        SD += pow(data[i] - mean, 2);
    }
    return sqrt(SD / 10);
}

void loop() {
  temp = dark;
  dark = darkSample();
  darkAvg = (dark/2)+(temp/2)+(dark & temp & 1);
  darkSD = calculateSD(darkArray);
  LED0 = LEDSample(pLED0);
  LED0SD = calculateSD(lightArray);
  LED1 = LEDSample(pLED1);
  LED1SD = calculateSD(lightArray);
  LED2 = LEDSample(pLED2);
  LED2SD = calculateSD(lightArray);
  delay(58);
  sprintf(messageBuffer,"%05d,%05d,%05d,%05d,%05d,%05d,%05d,%05d,%05d",counter,LED0,LED0SD,LED1,LED1SD,LED2,LED2SD,darkAvg,darkSD);
  Serial.println(messageBuffer);
  counter++;
}
 
