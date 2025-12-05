#include <Adafruit_NeoPixel.h>
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 16 // Popular NeoPixel ring size
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int led0,led1,led2;
void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  if(Serial.available() > 0){
    Digit_one(Serial.parseInt(),255,255,255);
  }
  

}

void Digit_one(int input, uint8_t r, uint8_t g, uint8_t b){

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
            if (numArray[input][i] == 1){
                led0 = i*3;
                led1 = led0+1;
                led2 = led1+1;
                // printf("led0: %d, led1: %d, led2: %d \n",led0,led1,led2);
                pixels.setPixelColor(led0, pixels.Color(r, g, b));
                pixels.setPixelColor(led1, pixels.Color(r, g, b));
                pixels.setPixelColor(led2, pixels.Color(r, g, b));
                pixels.show();
            }else{
                pixels.setPixelColor(led0, pixels.Color(0,0,0));
                pixels.setPixelColor(led1, pixels.Color(0,0,0));
                pixels.setPixelColor(led2, pixels.Color(0,0,0));
                pixels.show();
            }

        }
}
