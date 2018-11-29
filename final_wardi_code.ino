#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

int buttonSelector=0;
TMRpcm tmrpcm;
int analogPin = 0;
int val = 0; 
int flag;
int c;
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
  c = -1; 
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
      Serial.println("bitch");
      Serial.println(0);
      
  //Serial.println(state);;
  /* the code below choses the music from the selected set
  of music*/    
    }
    else if (state == '1') 
    {
  
      Serial.println("button1");
      state = 1;
      flag = 1;
      Serial.println("bitch");
      Serial.println(1);
      /* the code below choses the music from the selected set
      of music*/ 
     } 
    
    else if (state == '2') 
     {
      
      Serial.println("button2");
      state = 2;
      flag = 2;
      Serial.println("bitch");
      Serial.println(2);
      /* the code below choses the music from the selected set
      of music*/   
     
     } 
     
     else if (state == '3') 
     {
  
        Serial.println("button3");;
        state = 3;
        flag = 3;
        Serial.println("bitch");
      Serial.println(3);
        /* the code below choses the music from the selected set
        of music*/ 
     } 
     else if (state == '4') 
     {
  
      Serial.println("button4");;
      state = 4;
      Serial.println("bitch");
      Serial.println(4);
      /* the code below choses the music from the selected set
  of music*/
      }
   //genre1
  if(flag == 0)
  {
    if(buttonSelector/100==5)
    {
      tmrpcm.setVolume(6);
      tmrpcm.play("14.wav");
//      Serial.println("animalalphabet-1.wav");
    }
    else if (buttonSelector/100==2)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("13.wav");
//        Serial.println("animalalphabet-2.wav");
    }
    else if(buttonSelector/100==9)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("12.wav");
//        Serial.println("animalalphabet-3.wav");
    }
    else if(buttonSelector/100==6)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("11.wav");
//        Serial.println("animalalphabet.wav");
    }
    else if(buttonSelector/100==4)
    {
        flag = 1;

        Serial.println("state");
        Serial.println(flag);
    }
  }
   //genre2
  else if(flag==1)
  {
    if(buttonSelector/100==5)
    {
      tmrpcm.setVolume(6);
      tmrpcm.play("21.wav");
//      Serial.println("animalalphabet-1.wav");
    }
    else if (buttonSelector/100==2)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("22.wav");
//        Serial.println("animalalphabet-2.wav");
    }
    else if(buttonSelector/100==9)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("21.wav");
//        Serial.println("animalalphabet-3.wav");
    }
    else if(buttonSelector/100==6)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("jj.wav");
//        Serial.println("animalalphabet.wav");
    }
    else if(buttonSelector/100==4)
    {
        flag = 2;

        Serial.println("state");
        Serial.println(flag);
    }
  }
  //genre3
  //change songs before code upload
  else if (flag ==2)
  {
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
        tmrpcm.play("jj.wav");
        
    }
    else if(buttonSelector/100==4)
    {
        flag = 3;

        Serial.println("state");
        Serial.println(flag);
    }

  }
  else if (flag ==3)
  {
    if(buttonSelector/100==6)
    {

      c = 1;Serial.println(c);

      tmrpcm.setVolume(6);
      tmrpcm.play("a.wav");
      

    }
    else if (buttonSelector/100==9)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("b.wav");

        if(c == 1) {c++;Serial.println(c);}
        else {c=0;Serial.println(c);}
        
    }
    else if(buttonSelector/100==2)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("c.wav");
        if(c == 2){c++;Serial.println(c);}
        else {c=0;Serial.println(c);}
        
    }
    else if(buttonSelector/100==5)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("d.wav");
        if(c == 3) {flag = 4;state=4;Serial.println(state);}
        else {c=0;Serial.println(c);}
    }
    else if(buttonSelector/100==4)
    {
        flag = 4;

        Serial.println("state");
        Serial.println(flag);
    }

  }

  else if (flag ==4)
  {
    if(buttonSelector/100==6)
    {

      c = 1;Serial.println(c);

      tmrpcm.setVolume(6);
      tmrpcm.play("e.wav");
      

    }
    else if (buttonSelector/100==9)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("f.wav");

        if(c == 1) {c++;Serial.println(c);}
        else {c=0;Serial.println(c);}
        
    }
    else if(buttonSelector/100==2)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("g.wav");
        if(c == 2) {c++;Serial.println(c);}
        else {c=0;Serial.println(c);}
        
    }
    else if(buttonSelector/100==5)
    {
        tmrpcm.setVolume(6);
        tmrpcm.play("h.wav");
        if(c == 3) {flag = 3;state=3;Serial.println(state);}
        else {c=0;Serial.println(c);}
    }
    else if(buttonSelector/100==4)
    {
        flag = 0;

        Serial.println("state");
        Serial.println(flag);
    }

  }
}
