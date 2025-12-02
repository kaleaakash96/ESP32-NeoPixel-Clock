#include <Arduino.h>

#define OUT 11
#define IN A0

#define NUMPIXELS 16 // Popular NeoPixel ring size
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

int led0,led1,led2;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// put function declarations here:
void setup() {
  // pixels.begin(); 

  // pinMode(IN, INPUT);

  // pinMode(OUT, OUTPUT);

  // pinMode(LED_BUILTIN,OUTPUT);
  
  // put your setup code here, to run once:
}

void loop() {

  if (Serial.available() >0)
  {
    char data = Serial.read();
    Digit_one(data)
    /* code */
  }

//   int data = analogRead(IN);
//   int result = map(data, 0, 1023, 0, 255);

//   analogWrite(OUT, result);

// pixels.setPixelColor(i, pixels.Color(0, 150, 0));
//   // digitalWrite(LED_BUILTIN,HIGH);
//   // delay(1000);
//   // digitalWrite(LED_BUILTIN,LOW);
//   // delay(1000);
//   // // put your main code here, to run repeatedly:
}


void Digit_one(char input, uint8_t r, uint8_t g, uint8_t b){

    int numArray[10][7] = {
      {1,1,1,1,1,1,0}, // 0
      {0,1,1,0,0,0,0}, // 1
      {1,1,0,1,1,0,1}, // 2
      {1,1,1,1,0,0,1}, // 3
      {0,1,1,0,0,1,1}, // 4
      {1,0,1,1,0,1,1}, // 5
      {1,0,1,1,1,1,1}, // 6
      {1,1,1,0,0,0,0}, // 7
      {1,1,1,1,1,1,1}, // 8
      {1,1,1,1,0,1,1}  // 9
    };


        for (int i = 0; i < 7; i++) {
        led0 = i*3 +1;
        led1 = led0+1;
        led2 = led1+1;

        pixels.setPixelColor(led0, pixels.Color(r, g, b));
        pixels.setPixelColor(led1, pixels.Color(r, g, b));
        pixels.setPixelColor(led2, pixels.Color(r, g, b));

        }
  

}

void Digit_two(char input, uint8_t r, uint8_t g, uint8_t b){

    int numArray[10][7] = {
      {1,1,1,1,1,1,0}, // 0
      {0,1,1,0,0,0,0}, // 1
      {1,1,0,1,1,0,1}, // 2
      {1,1,1,1,0,0,1}, // 3
      {0,1,1,0,0,1,1}, // 4
      {1,0,1,1,0,1,1}, // 5
      {1,0,1,1,1,1,1}, // 6
      {1,1,1,0,0,0,0}, // 7
      {1,1,1,1,1,1,1}, // 8
      {1,1,1,1,0,1,1}  // 9
    };


        for (int i = 7; i < 14; i++) {
        led0 = i*3 +1;
        led1 = led0+1;
        led2 = led1+1;

        pixels.setPixelColor(led0, pixels.Color(r, g, b));
        pixels.setPixelColor(led1, pixels.Color(r, g, b));
        pixels.setPixelColor(led2, pixels.Color(r, g, b));

        }
  

}

void Digit_three(char input, uint8_t r, uint8_t g, uint8_t b){

    int numArray[10][7] = {
      {1,1,1,1,1,1,0}, // 0
      {0,1,1,0,0,0,0}, // 1
      {1,1,0,1,1,0,1}, // 2
      {1,1,1,1,0,0,1}, // 3
      {0,1,1,0,0,1,1}, // 4
      {1,0,1,1,0,1,1}, // 5
      {1,0,1,1,1,1,1}, // 6
      {1,1,1,0,0,0,0}, // 7
      {1,1,1,1,1,1,1}, // 8
      {1,1,1,1,0,1,1}  // 9
    };


        for (int i = 14; i < 21; i++) {
        led0 = i*3 +1;
        led1 = led0+1;
        led2 = led1+1;

        pixels.setPixelColor(led0, pixels.Color(r, g, b));
        pixels.setPixelColor(led1, pixels.Color(r, g, b));
        pixels.setPixelColor(led2, pixels.Color(r, g, b));

        }
  

}


void Digit_three(char input, uint8_t r, uint8_t g, uint8_t b){

    int numArray[10][7] = {
      {1,1,1,1,1,1,0}, // 0
      {0,1,1,0,0,0,0}, // 1
      {1,1,0,1,1,0,1}, // 2
      {1,1,1,1,0,0,1}, // 3
      {0,1,1,0,0,1,1}, // 4
      {1,0,1,1,0,1,1}, // 5
      {1,0,1,1,1,1,1}, // 6
      {1,1,1,0,0,0,0}, // 7
      {1,1,1,1,1,1,1}, // 8
      {1,1,1,1,0,1,1}  // 9
    };


        for (int i = 14; i < 21; i++) {
        led0 = i*3 +1;
        led1 = led0+1;
        led2 = led1+1;

        pixels.setPixelColor(led0, pixels.Color(r, g, b));
        pixels.setPixelColor(led1, pixels.Color(r, g, b));
        pixels.setPixelColor(led2, pixels.Color(r, g, b));

        }
  

}