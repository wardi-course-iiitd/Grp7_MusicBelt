//TMRpcm library is needed

#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"
int buttonSelector=0;
TMRpcm tmrpcm;
int analogPin = 0;
int val = 0; 
int flag;
#define ledPin 7
int state ;
void setup()
{
tmrpcm.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
flag = -1;
state= 0 ; 
}

void loop() 
{
  
    if(Serial.available() > 0)
    {   
      // Checks whether data is comming from the serial port
      state = Serial.read(); // Reads the data from the serial port
    }
    buttonSelector=analogRead(analogPin);
 
 
    if (state == '0') 
    {
 
      Serial.println("button0"); // Send back, to the phone, the String "LED: ON"
      state = 0;
      flag = 0;
  //Serial.println(state);;
  /* the code below choses the music from the selected set
  of music*/    
    }
 else if (state == '1') 
 {
  
  Serial.println("button1");;
  state = 1;
  flag = 1;
  /* the code below choses the music from the selected set
  of music*/
 
 } 
 else if (state == '2') 
 {
  
  Serial.println("button2");
  state = 2;
  flag = 2;
  /* the code below choses the music from the selected set
  of music*/
 
 
 } else if (state == '3') {
  
  Serial.println("button4");;
  state = 3;
  /* the code below choses the music from the selected set
  of music*/

  
 } else if (state == '4') {
  
  Serial.println("button5");;
  state = 4;
  /* the code below choses the music from the selected set
  of music*/
 }
   //genre1
  if(flag == 0)
  {
    if(buttonSelector/100==5)
    {
      tmrpcm.setVolume(6);
      tmrpcm.play("test.wav");
      Serial.println("animalalphabet-1.wav");
    }
    else if (buttonSelector/100==2)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("2.wav");
        Serial.println("animalalphabet-2.wav");
    }
    else if(buttonSelector/100==9)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("3.wav");
        Serial.println("animalalphabet-3.wav");
    }
    else if(buttonSelector/100==6)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("4.wav");
        Serial.println("animalalphabet.wav");
    }
  }
   //genre2
  else if(flag==1)
  {
    if(buttonSelector/100==5)
    {
      tmrpcm.setVolume(6);
      tmrpcm.play("21.wav");
      Serial.println("animalalphabet-1.wav");
    }
    else if (buttonSelector/100==2)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("22.wav");
        Serial.println("animalalphabet-2.wav");
    }
    else if(buttonSelector/100==9)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("21.wav");
        Serial.println("animalalphabet-3.wav");
    }
    else if(buttonSelector/100==6)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("22.wav");
        Serial.println("animalalphabet.wav");
    }
  }
  //genre3
  //change songs before code upload
  else if (flag ==2){
    if(buttonSelector/100==5)
    {
      tmrpcm.setVolume(6);
      tmrpcm.play("21.wav");
      
    }
    else if (buttonSelector/100==2)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("22.wav");
        
    }
    else if(buttonSelector/100==9)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("21.wav");
        
    }
    else if(buttonSelector/100==6)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("22.wav");
        
    }
    }
}
