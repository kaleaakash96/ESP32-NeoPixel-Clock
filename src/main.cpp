///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// A basic everyday NeoPixel strip test program.

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting Neostrip_C on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

#include <Adafruit_NeoPixel.h>
#include "uRTCLib.h"
#include <Arduino.h>
#include "BluetoothSerial.h"

#define LED_PIN_W     14//18 //6   // wall  // need to change
#define LED_PIN_C     27//19 //10  // clock     // need to change
#define LED_PIN_S     26//19 //10  // Wall Sign     // need to change

// How many Neostrip_C are attached to the Arduino?
#define LED_COUNT_W   150 // 160 
#define LED_COUNT_C   90
#define LED_COUNT_S   40

char buffer[64]; // Define character array with sufficient size
int bytesRead = 0;

TaskHandle_t ledTask1;
uRTCLib rtc(0x68);
BluetoothSerial SerialBT;

char clock_color = '0';
char mode = '0';

int cnt_s = 99; // old 103

int cnt_s_1 = 86; // old 90

Adafruit_NeoPixel strip_W(LED_COUNT_W, LED_PIN_W, NEO_GRB + NEO_KHZ800);  // Wall 
Adafruit_NeoPixel strip_C(LED_COUNT_C, LED_PIN_C, NEO_GRB + NEO_KHZ800);  // Clock 
Adafruit_NeoPixel strip_S(LED_COUNT_S, LED_PIN_S, NEO_GRB + NEO_KHZ800);  // Sign 



void Digit(long hour, uint8_t min, uint8_t format, uint8_t r, uint8_t g, uint8_t b){
    strip_C.clear();
    int led0,led1,led2;
    long one, ten, hundred, thousand;

    int numArray[10][7] = {
      {1,1,1,0,1,1,1}, // 0
      {1,0,0,0,1,0,0}, // 1
      {0,1,1,1,1,1,0}, // 2
      {1,1,0,1,1,1,0}, // 3
      {1,0,0,1,1,0,1}, // 4
      {1,1,0,1,0,1,1}, // 5
      {1,1,1,1,0,1,1}, // 6
      {1,0,0,0,1,1,0}, // 7
      {1,1,1,1,1,1,1}, // 8
      {1,1,0,1,1,1,1}  // 9
    };

    // if(format == 0){
    //   if(hour > 12)
    //   hour = 9;
    // }
    // if(min >)
        // 23:59 max
        // 00:00 min
        
    thousand = hour / 1000;
    
    hundred = hour % 1000 / 100;
    
    ten = hour % 100 / 10;
    
    one = hour % 10 / 1;

        // Serial.print("d743one);


        for (int i = 0; i < 7; i++) {
            // Serial.print(numArray[hour][i]);
            // Serial.println();
            if (numArray[one][i] == 1){
                
                led0 = i*3;
                led1 = led0+1;
                led2 = led1+1;
                // printf("led0: %d, led1: %d, led2: %d \n",led0,led1,led2);
                strip_C.setPixelColor(led0, strip_C.Color(r, g, b));
                strip_C.setPixelColor(led1, strip_C.Color(r, g, b));
                strip_C.setPixelColor(led2, strip_C.Color(r, g, b));
                // strip_C.show();
                // delay(10);
            }
            // if (numArray[one][i] == 0) {
            //     strip_C.setPixelColor(led0, strip_C.Color(0,0,0));
            //     strip_C.setPixelColor(led1, strip_C.Color(0,0,0));
            //     strip_C.setPixelColor(led2, strip_C.Color(0,0,0));
            //     // strip_C.show();
            //     // delay(10);
            // }

        }

        for (int i = 7; i < 14; i++) {
            if (numArray[ten][i-7] == 1){
                led0 = i*3;
                led1 = led0+1;
                led2 = led1+1;
                // printf("led0: %d, led1: %d, led2: %d \n",led0,led1,led2);
                strip_C.setPixelColor(led0, strip_C.Color(r, g, b));
                strip_C.setPixelColor(led1, strip_C.Color(r, g, b));
                strip_C.setPixelColor(led2, strip_C.Color(r, g, b));
                // strip_C.show();
            }
            // if (numArray[ten][i-7] == 0){
            //     strip_C.setPixelColor(led0, strip_C.Color(0,0,0));
            //     strip_C.setPixelColor(led1, strip_C.Color(0,0,0));
            //     strip_C.setPixelColor(led2, strip_C.Color(0,0,0));
            //     // strip_C.show();
            // }

        }

        for (int i = 15; i < 22; i++) {
            if (numArray[hundred][i-15] == 1){
                led0 = i*3;
                led1 = led0+1;
                led2 = led1+1;
                // printf("led0: %d, led1: %d, led2: %d \n",led0,led1,led2);
                strip_C.setPixelColor(led0, strip_C.Color(r, g, b));
                strip_C.setPixelColor(led1, strip_C.Color(r, g, b));
                strip_C.setPixelColor(led2, strip_C.Color(r, g, b));
                // strip_C.show();
            }
            // if (numArray[hundred][i-15] == 0){
            //     strip_C.setPixelColor(led0, strip_C.Color(0,0,0));
            //     strip_C.setPixelColor(led1, strip_C.Color(0,0,0));
            //     strip_C.setPixelColor(led2, strip_C.Color(0,0,0));
            //     // strip_C.show();
            // }

        }

        for (int i = 22; i < 29; i++) {

            if (numArray[thousand][i-22] == 1){
                led0 = i*3;
                led1 = led0+1;
                led2 = led1+1;
                // printf("led0: %d, led1: %d, led2: %d \n",led0,led1,led2);
                strip_C.setPixelColor(led0, strip_C.Color(r, g, b));
                strip_C.setPixelColor(led1, strip_C.Color(r, g, b));
                strip_C.setPixelColor(led2, strip_C.Color(r, g, b));
                // strip_C.show();
            }

            // if (numArray[thousand][i-22] == 0){
            //     strip_C.setPixelColor(led0, strip_C.Color(0,0,0));
            //     strip_C.setPixelColor(led1, strip_C.Color(0,0,0));
            //     strip_C.setPixelColor(led2, strip_C.Color(0,0,0));
            //     // strip_C.show();
            // }

        }
        
        strip_C.show();
        delay(20);
}

void counter(){
  
  // if(Serial.available()>0){
  //   uint16_t data = Serial.parseInt();
  //   strip_W.clear();
  //   strip_W.setPixelColor(data, strip_W.Color(0,255,0));         //  Set pixel's color (in RAM)
  //   strip_W.show();
  //   Serial.println(data);
  // }

    if(Serial.available()>0){
    uint16_t data = Serial.parseInt();
    strip_W.clear();
    strip_W.setPixelColor(data, strip_W.Color(0,255,0));         //  Set pixel's color (in RAM)
    strip_W.show();
    Serial.println(data);
  }


  // for(int i = 42;i>=0;i--){
  //   strip_W.clear();
  //   strip_W.setPixelColor(i, strip_W.Color(0,0,255));         //  Set pixel's color (in RAM)
  //   strip_W.show();
  //   Serial.println(i);                     //  Update strip to match

  //   delay(100);   
  // }
}

void letter(){
  strip_C.setPixelColor(81, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(82, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(83, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(84, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(85, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(86, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(75, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(76, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(77, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(66, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(67, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(68, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(69, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(70, strip_W.Color(255,0,0)); 
  strip_C.setPixelColor(71, strip_W.Color(255,0,0)); 
  // strip_C.setPixelColor(, strip_W.Color(255,0,0)); 
  strip_C.show();
}

String myclock(){
  
  rtc.refresh();
  // String myString = rtc.hour() + rtc.minute();
  String hour, min, str; 
  if (rtc.hour() < 10){
    hour = "0" + String(rtc.hour());
  }else{
    hour = String(rtc.hour());
  }
  if (rtc.minute() < 10){
    min = "0" + String(rtc.minute());
  }else{
    min = String(rtc.minute());
  }

  str = hour + min;
  Serial.print("Hour :");
  Serial.println(rtc.hour());

  Serial.print("Minutes :");
  Serial.println(rtc.minute());

  Serial.print("string :");
  Serial.println(str);

  return str;

  Digit(str.toInt(),0,0,255,0,0);

}

void colorWipe(uint8_t R, uint8_t G, uint8_t B, int wait) {
    
  for(int i=0; i<45; i++) { // For each pixel in strip...

    if ((89-i) < 85){
      strip_W.setPixelColor((89-i), strip_W.Color(R,G,B));  
    }
    
    strip_W.setPixelColor(i, strip_W.Color(R,G,B));         //  Set pixel's color (in RAM)
   
                           //  Update strip to match
    if (i > 31 && i < 43){
      
      strip_W.setPixelColor(cnt_s, strip_W.Color(R,G,B));
      strip_W.setPixelColor(cnt_s_1, strip_W.Color(R,G,B));

      if (cnt_s == 99){
        strip_W.setPixelColor(99, strip_W.Color(G,R,B));
      }

      if (cnt_s == 98 ){
        strip_W.setPixelColor(98, strip_W.Color(G,R,B));
      }

      cnt_s--;
      cnt_s_1++;
    }

    strip_W.show(); 

    if(i == 44){
      cnt_s = 99;
      cnt_s_1 = 90;
    }
    delay(wait);                           //  Pause for a moment
  }

  // for(int i=0; i<strip_C.numstrip_C();i++){
  //   strip_C.setPixelColor(i, color); 
  //   strip_C.show();                          //  Update strip to match
  //   delay(wait); 
  // }

}

void rainbowSection(int start, int end, int wait, Adafruit_NeoPixel strip) {
  for(long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 256) {
    for(int i = start; i <= end; i++) {
      int pixelHue = firstPixelHue + ((i - start) * 65536L / (end - start + 1));
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    delay(wait);
  }
}

// void rainbow_Sign(int start, int end, int wait) {
//   for(long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 256) {
//     for(int i = start; i <= end; i++) {
//       int pixelHue = firstPixelHue + ((i - start) * 65536L / (end - start + 1));
//       strip_S.setPixelColor(i, strip_S.gamma32(strip_S.ColorHSV(pixelHue)));
//     }
//     strip_S.show();
//     delay(wait);
//   }
// }

void fadding_effect(uint8_t targetRed, uint8_t targetGreen, uint8_t targetBlue){

  Digit(myclock().toInt(),0,0,targetRed,targetGreen,targetBlue);
// Fade Up: 0 to 100% brightness
  for (int brightness = 0; brightness <= 100; brightness++) {
    // Calculate current RGB values as a percentage of the target
    int r = (targetRed * brightness) / 100;
    int g = (targetGreen * brightness) / 100;
    int b = (targetBlue * brightness) / 100;

    for (int i = 0; i < strip_W.numPixels(); i++) {

      strip_W.setPixelColor(i, strip_W.Color(g,r,b));
      strip_S.setPixelColor(i, strip_S.Color(g,r,b));

       if (i >= 102){
        strip_W.setPixelColor(i, strip_W.Color(r,g,b));
      }

      // if (i == 103){
      //   strip_W.setPixelColor(103, strip_W.Color(g,r,b));
      // }

    }
    strip_W.show();
    strip_S.show(); 
    delay(10); // Adjust delay for fade speed
  }

  // Fade Down: 100% to 0% brightness
  for (int brightness = 100; brightness >= 0; brightness--) {
    int r = (targetRed * brightness) / 100;
    int g = (targetGreen * brightness) / 100;
    int b = (targetBlue * brightness) / 100;

    for (int i = 0; i < strip_W.numPixels(); i++) {
      strip_W.setPixelColor(i, strip_W.Color(g,r,b));
      strip_S.setPixelColor(i, strip_S.Color(g,r,b));

       if (i >= 102){
        strip_W.setPixelColor(i, strip_W.Color(r,g,b));
      }

      // if (i == 103){
      //   strip_W.setPixelColor(103, strip_W.Color(g,r,b));
      // }
    }
    strip_W.show();
    strip_S.show();
    delay(10);
  }

}

void default_effect(){

  Digit(myclock().toInt(),0,0,0,255,0);
  colorWipe(255,   0,   0, 50); // Red
  rainbowSection(100,147,10,strip_W);
  colorWipe(0, 255,   0, 50); // Green
  rainbowSection(100,147,10,strip_W);
  colorWipe(0,   0, 255, 50); // Blue
  rainbowSection(100,147,10,strip_W);

  rainbowSection(0,35,10,strip_S);

  // rainbow_Sign(0,35,10);

}

void Solid_Color(uint8_t R, uint8_t G, uint8_t B){

  for (int i = 0; i < strip_S.numPixels(); i++)
  {
    strip_S.setPixelColor(i,strip_S.Color(G,R,B));
    /* code */
  }

    for (int i = 0; i < strip_W.numPixels(); i++)
  {
    strip_W.setPixelColor(i,strip_W.Color(G,R,B));

    if (i >= 98){
        strip_W.setPixelColor(i, strip_W.Color(R,G,B));
      }
    /* code */
  }
  
  strip_S.show();
  strip_W.show();

   Digit(myclock().toInt(),0,0,R,G,B);
  
}

// =========================
// TASK 1
// =========================
void blinkLed1(void * parameter)
{
    while(true)
    {
       if (SerialBT.available()>0)
  {
        // buffer[64]; // Define character array with sufficient size
        bytesRead = SerialBT.readBytesUntil('\n', buffer, sizeof(buffer) - 1);
        
        // Null-terminate the string if bytes were read
        if (bytesRead > 0) {
          // buffer[bytesRead] = '\0';
          // Serial.println(buffer);
          if (buffer[0] == 'T' && buffer[5] == 'T')  // for Clock time Set 
          {
            mode = 'T';
          }

          if (buffer[0] == 'C' && buffer[2] == 'C')  // for Clock color change
          {
            mode = 'Z';
          }

          if (buffer[0] == 'P')  // to check set clock time on serial blue terinal
          {
            mode = 'P';
            /* code */
          }
        }

      switch (buffer[0])
    {
    case '0':
      mode = '0';
      /* code */
      break;

    case '1':
      mode = '1';
      /* code */
      break;
    
    case '2':
      mode = '2';
      /* code */
      break;

    case '3':
      mode = '3';
      /* code */
      break;
    
    case '4':
      mode = '4';
      /* code */
      break;
    
    case '5':
      mode = '5';
      /* code */
      break;

    case '6':
      mode = '6';
      /* code */
      break;

          case '7':
      mode = '7';
      /* code */
      break;

          case '8':
      mode = '8';
      /* code */
      break;

          case '9':
      mode = '9';
      /* code */
      break;
    
                case 'A':
      mode = 'A';
      /* code */
      break;

                case 'B':
      mode = 'B';
      /* code */
      break;

                case 'C':
      mode = 'C';
      /* code */
      break;
    default:
      break;
    }
    /* code */
  }
        // digitalWrite(LED1, LOW);
        // vTaskDelay(500 / portTICK_PERIOD_MS);
        Serial.println(mode);
    }
}

void setup() {


  Serial.begin(9600);

  SerialBT.begin("Studio_Wall");

  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
  // END of Trinket-specific code.

  strip_W.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip_W.show();            // Turn OFF all strip_C ASAP
  strip_W.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)


  strip_C.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip_C.show();            // Turn OFF all strip_C ASAP
  strip_C.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
  ////////////////////////////////////////////////////////////////////////
    URTCLIB_WIRE.begin();

  // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  // for example to set April 14 2025 at 12:56 you would call:
  // rtc.set(0, 31, 1, 1, 24, 5, 26);
  // // rtc.adjust();
  // rtc.set_12hour_mode(true);
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year);
  // set day of week (1=Sunday, 7=Saturday)

  ///////////////////////////////////////////////////////////////////////////


  // Create Task 1
    xTaskCreatePinnedToCore(
        blinkLed1,
        "LED1_Task",
        1000,
        NULL,
        1,
        &ledTask1,
        0
    );

}

void loop() {

  if (mode == '0')
  {
    default_effect();
    /* code */
  }else if (mode == '1')
  {
    fadding_effect(255,0,0); // Red fadding effect
    /* code */
  }
  else if (mode == '2')
  {
    fadding_effect(0,255,0); // Green fadding effect
    /* code */
  }else if (mode == '3')
  {
    fadding_effect(0,0,255); //Blue fadding effect
    /* code */
  }else if (mode == '4')
  {
    fadding_effect(0,255,255); // Cyan fadding effect
    /* code */
  }else if (mode == '5')
  {
    fadding_effect(255,40,0); // Coral fadding effect
    /* code */
  }else if (mode == '6')
  {
    fadding_effect(255,215,0); // gold fadding effect
    /* code */
  }else if (mode == '7')
  {
    fadding_effect(255,127,0); // Orange fadding effect
    /* code */
  }else if (mode == '8')
  {
    Solid_Color(255,0,0); // Red solid
    /* code */
  }else if (mode == '9') 
  {
    Solid_Color(0,255,0); // Green solid
    /* code */
  }else if (mode == 'A')
  {
    Solid_Color(0,0,255); // Blue solid
    /* code */
  }else if (mode == 'B')
  {
    Solid_Color(0,255,255); // Cyan solid
    /* code */
  }else if (mode == 'C')
  {
    Solid_Color(255,40,0); // Coral solid
    /* code */
  }else if (mode == 'D')
  {
    Solid_Color(255,215,0); // gold solid
  
  }else if (mode== 'E')
  {
    Solid_Color(255,127,0); // orange solid

  }else if(mode == 'T') {
    uint8_t IncomingHour = (uint8_t)((buffer[1] - '0') * 10 + (buffer[2] - '0'));
    uint8_t IncomingMin = (uint8_t)((buffer[3] - '0') * 10 + (buffer[4] - '0'));
  
    // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year);
    rtc.set(0,IncomingMin,IncomingHour,0,0,0,0);
    SerialBT.print("ok");
    SerialBT.println(IncomingHour);
    SerialBT.println(IncomingMin);
    /* code */

    mode = 0;
    
  }else if (mode == 'P')
  {
    String myString = String(rtc.hour()) + String(rtc.minute());
    SerialBT.print(myString);
    mode = 0;
    /* code */
  }else if (mode == 'Z') // 
  {
    uint8_t clock_color = buffer[1];

    if(clock_color == '1'){ // Red
      Digit(myclock().toInt(),0,0,255,0,0);
      SerialBT.printf("Clock Color %s",clock_color);
    }

    if(clock_color == '2'){ // Solid_Color(0,255,0); // Green solid
      Digit(myclock().toInt(),0,0,0,255,0);
    }

    if(clock_color == '3'){ // Solid_Color(0,0,255); // Blue solid
      Digit(myclock().toInt(),0,0,0,0,255);
    }

    if(clock_color == '4'){ // Solid_Color(0,255,255); // Cyan solid
      Digit(myclock().toInt(),0,0,0,255,255);
    }

    if(clock_color == '5'){ // Solid_Color(255,40,0); // Coral solid
      Digit(myclock().toInt(),0,0,255,40,0);
    }

    if(clock_color == '6'){ // Solid_Color(255,215,0); // gold solid
      Digit(myclock().toInt(),0,0,255,215,0);
    }

    if(clock_color == '7'){ // Solid_Color(255,215,0); // Orange solid
      Digit(myclock().toInt(),0,0,255,127,0);
    }

  }else{
    // default_effect();
  }

}