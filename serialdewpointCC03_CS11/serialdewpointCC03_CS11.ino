#include <xCore.h>  //add core library
#include <xSW01.h>  //add weather sensor library

#if defined(ESP8266)
#define RED   RED
#define GREEN GREEN
#define BLUE  BLUE
#include <ESP8266WiFi.h>
#define Serial Serial

#elif defined(ARDUINO_SAMD_ZERO)
#define RED   CC03_RED
#define GREEN CC03_GREEN
#define BLUE  CC03_BLUE
#define Serial SerialUSB

#elif defined(ARDUINO_AVR_PRO)
#define RED   CC01_RED
#define GREEN CC01_GREEN
#define BLUE  CC01_BLUE
#define Serial Serial

#elif defined(ESP32)
#define RED   CW02_RED
#define GREEN CW02_GREEN
#define BLUE  CW02_BLUE
#define Serial Serial
#endif

xSW01 SW01;

const int DelayTime = 500; //Defining set delay time that could be used elsewhere in the code

//Create a variable to store the data read from SW01
float dew_point;

void setup(){

  //Initialise variables to zero
  dew_point = 0;
  
  //Start Serial Monitor
  Serial.begin(115200);

  //Start I2C communication
  Wire.begin();

  //Start SW01 Sensor
  SW01.begin();
  
  //String intro for project
  Serial.println("XinaBox Dew Point Experiment");
  Serial.println("____________________________");

  //Delay for sensor to normalise
  delay(3000);
  
}

void loop(){
  
  //Read and calculate data from SW01
  SW01.poll();

  //Request to get humidity, temperature and dew point data then store in the variables
  dew_point = SW01.getDewPoint();


  //Display recorded data over the Serial Monitor

  Serial.print("Dew Point:");
  Serial.print(dew_point);
  Serial.println("℃ ");

  delay(5000);

}
