// // A basic everyday NeoPixel strip test program.

// // NEOPIXEL BEST PRACTICES for most reliable operation:
// // - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// // - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// // - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// // - AVOID connecting Neostrip_S on a LIVE CIRCUIT. If you must, ALWAYS
// //   connect GROUND (-) first, then +, then data.
// // - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
// //   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// // (Skipping these may work OK on your workbench but can fail in the field)

// #include <Adafruit_NeoPixel.h>
// #include "uRTCLib.h"
// #include <Arduino.h>
// #include "Audio.h"
// #include "SD.h"
// #include "FS.h"
// #include "SPI.h"
// #include <ESP32Servo.h> 

// #include <YoutubeApi.h>
// #include <WiFiClientSecure.h>
// #include <ArduinoJson.h> 

// /////////////////Youtube API//////////////
// char ssid[] = "kale";     
// char password[] = "123456789";
// #define API_KEY "AIzaSyC0NUR6adjB7JIz_fJnF3YcxJA6Bc72x0A"
// #define CHANNEL_ID "UCmWXFDKf36ZgyPB0S3WyxwA"
 
// WiFiClientSecure client;
// YoutubeApi api(API_KEY, client);

// unsigned long api_mtbs = 1000; 
// unsigned long api_lasttime;
// long subs = 0;
// String subs_count;
// String view_count;
//  ////////////////////////////////////////


// // #ifdef __AVR__                                                   ----------
// //  #include <avr/power.h> // Required for 16 MHz Adafruit Trinket  ---------
// // #endif                                                           ---------

// // #include <Arduino_FreeRTOS.h>   --------
// // Which pin on the Arduino is connected to the Neostrip_S?
// // On a Trinket or Gemma we suggest changing this to 1:
// #define LED_PIN_W     18 //6   // Clock  // need to change
// #define LED_PIN_S     19 //10  // wall    // need to change

// // SD Card pins
// #define SD_CS      5
// #define SPI_MOSI   23
// #define SPI_MISO   19
// #define SPI_SCK    18

// // I2S pins for MAX98357A
// #define I2S_DOUT   32
// #define I2S_BCLK   33
// #define I2S_LRC    25

// // How many Neostrip_S are attached to the Arduino?
// #define LED_COUNT_W   200

// #define LED_COUNT_S   100

// Audio audio;
// Servo myservo; 
// uRTCLib rtc(0x68);
// char daysOfTheWeek[7][12] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

// int cnt_s = 103;

// int servoPin = 13;  // GPIO 13 servo connected
// int cnt_s_1 = 90;
// long temp_cnt = 0;

// Adafruit_NeoPixel strip_W(LED_COUNT_W, LED_PIN_W, NEO_GRB + NEO_KHZ800);

// Adafruit_NeoPixel strip_S(LED_COUNT_S, LED_PIN_S, NEO_GRB + NEO_KHZ800);

// void Digit(long hour, uint8_t min, uint8_t format, uint8_t r, uint8_t g, uint8_t b);

// // Argument 1 = Number of strip_S in NeoPixel strip
// // Argument 2 = Arduino pin number (most are valid)
// // Argument 3 = Pixel type flags, add together as needed:
// //   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
// //   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA strip_S, WS2811 drivers)
// //   NEO_GRB     strip_S are wired for GRB bitstream (most NeoPixel products)
// //   NEO_RGB     strip_S are wired for RGB bitstream (v1 FLORA strip_S, not v2)
// //   NEO_RGBW    strip_S are wired for RGBW bitstream (NeoPixel RGBW products)

// // setup() function -- runs once at startup --------------------------------


// void counter(){
  
//   // if(Serial.available()>0){
//   //   uint16_t data = Serial.parseInt();
//   //   strip_W.clear();
//   //   strip_W.setPixelColor(data, strip_W.Color(0,255,0));         //  Set pixel's color (in RAM)
//   //   strip_W.show();
//   //   Serial.println(data);
//   // }

//     if(Serial.available()>0){
//     uint16_t data = Serial.parseInt();
//     strip_W.clear();
//     strip_W.setPixelColor(data, strip_W.Color(0,255,0));         //  Set pixel's color (in RAM)
//     strip_W.show();
//     Serial.println(data);
//   }


//   // for(int i = 42;i>=0;i--){
//   //   strip_W.clear();
//   //   strip_W.setPixelColor(i, strip_W.Color(0,0,255));         //  Set pixel's color (in RAM)
//   //   strip_W.show();
//   //   Serial.println(i);                     //  Update strip to match

//   //   delay(100);   
//   // }
// }

// void letter(){
//   strip_S.setPixelColor(81, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(82, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(83, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(84, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(85, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(86, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(75, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(76, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(77, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(66, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(67, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(68, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(69, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(70, strip_W.Color(255,0,0)); 
//   strip_S.setPixelColor(71, strip_W.Color(255,0,0)); 
//   // strip_S.setPixelColor(, strip_W.Color(255,0,0)); 
//   strip_S.show();
// }

// // void color(){
// //     for(int i = strip_W.numstrip_S();i>=0;i--){
// //     // strip_W.clear();
// //     strip_W.setPixelColor(i, strip_W.Color(0,0,255));         //  Set pixel's color (in RAM)
// //     // strip_W.show();
// //     // Serial.println(i);                     //  Update strip to match
// //     // delay(100);   
// //   }

// //   strip_W.show();

// //       for(int i = strip_S.numstrip_S();i>=0;i--){
// //     // strip_W.clear();
// //     strip_S.setPixelColor(i, strip_S.Color(0,0,255));         //  Set pixel's color (in RAM)
// //     // strip_W.show();
// //     // Serial.println(i);                     //  Update strip to match
// //     // delay(100);   
// //   }

// //   strip_S.show();
// // }

// String myclock(){
  
//   rtc.refresh();
//   // String myString = rtc.hour() + rtc.minute();
//   String hour, min, str; 
//   if (rtc.hour() < 10){
//     hour = "0" + String(rtc.hour());
//   }else{
//     hour = String(rtc.hour());
//   }
//   if (rtc.minute() < 10){
//     min = "0" + String(rtc.minute());
//   }else{
//     min = String(rtc.minute());
//   }

//   str = hour + min;
//   Serial.print("Hour :");
//   Serial.println(rtc.hour());

//   Serial.print("Minutes :");
//   Serial.println(rtc.minute());

//   Serial.print("string :");
//   Serial.println(str);

//   return str;

//   Digit(str.toInt(),0,0,255,0,0);
//   // Digit(temp_cnt,0,0,255,0,0);
//   // Serial.println(temp_cnt);
//   // delay(1000);
//   // temp_cnt++;

// }

// void YoutubeCnt_call(){
//     static int tempSub;
//     if (millis() - api_lasttime > api_mtbs)  {
//         if(api.getChannelStatistics(CHANNEL_ID))
//         {
//             // if (Serial.available()>0)
//             // {
//             //   subs_count = Serial.readString();
//             //   /* code */
//             // }
            
//             subs_count = api.channelStats.subscriberCount ;
//             view_count = api.channelStats.viewCount ;

//             if (tempSub <= 0){
//               tempSub = subs_count.toInt();
//             }else if (tempSub > subs_count.toInt())
//             {
//               Serial.println("Dec !!!");
//                 myservo.write(0); 
//               delay(1000);
//               myservo.write(90); 
//               tempSub = subs_count.toInt();
//               /* code */
//             }else if (tempSub < subs_count.toInt())
//             {
//               Serial.println("Inc !!!");
//               myservo.write(180); 
//               delay(1000);
//               myservo.write(90); 
//               tempSub = subs_count.toInt();
//               /* code */
//             }else{
//               tempSub = subs_count.toInt();
//             }
            
            
//             // tempSub = subs_count.toInt();
            
//             Serial.println("---------Status---------");
//             Serial.println("Zeno_Modiff");
//             Serial.print("S: ");
//             Serial.println(subs_count);

//             Serial.print("V: ");
//             Serial.println(view_count);
//             Serial.println("------------------------");

//             /////// Sub count///////
//             // lcd.clear();
//             // lcd.setCursor(0,0);
//             // lcd.print("Sub :");
//             // lcd.setCursor(6,0);
//             // lcd.print(subs_count);

//             ////// View count///////
//             // lcd.setCursor(0,1);
//             // lcd.print("View :");
//             // lcd.setCursor(7,1);
//             // lcd.print(view_count);

//         }
//     api_lasttime = millis();
//   }
// }

// void wifi_init(){
 
//     WiFi.mode(WIFI_STA);
//     WiFi.disconnect();
//     delay(100);
    
//     Serial.print("Connecting Wifi: ");
//     // lcd.clear();
//     // lcd.setCursor(0,0);
//     // lcd.print("Connecting ");
//     // lcd.setCursor(0,1);
//     // lcd.print("Wifi.....");

//     delay(250);

//     Serial.println(ssid);
//     WiFi.begin(ssid, password);
//     while (WiFi.status() != WL_CONNECTED) {
//     Serial.print(".");
//     delay(500);
//     }

//     Serial.println("");
//     Serial.println("WiFi");


//     Serial.println("IP address: ");
//     IPAddress ip = WiFi.localIP();
//     Serial.println(ip);
    
//     // lcd.clear();
//     // lcd.setCursor(0,0);
//     // lcd.print("Connected");
//     // lcd.setCursor(0,1);
//     // lcd.print(WiFi.SSID());
//     delay(2000);

//      client.setInsecure(); 

// }

// void playFile(const char *filename);
// void setup() {
//   Serial.begin(9600);

//   // SPI SD
//     SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);

//     if (!SD.begin(SD_CS))
//     {
//         Serial.println("SD Card Failed");
//         while (1);
//     }

//     Serial.println("SD Card OK");

//     // Audio output
//     audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);

//     // Volume: 0 - 21
//     audio.setVolume(18);

//   // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
//   // Any other board, you can remove this part (but no harm leaving it):
// #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
//   clock_prescale_set(clock_div_1);
// #endif
//   // END of Trinket-specific code.

//   strip_W.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
//   strip_W.show();            // Turn OFF all strip_S ASAP
//   strip_W.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)


//   strip_S.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
//   strip_S.show();            // Turn OFF all strip_S ASAP
//   strip_S.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)

//     myservo.attach(servoPin, 500, 2400);   // attaches the servo on pin 18 to the servo object
//     myservo.write(90); 
//     wifi_init();
//   ////////////////////////////////////////////////////////////////////////
//     URTCLIB_WIRE.begin();

//   // Comment out below line once you set the date & time.
//   // Following line sets the RTC with an explicit date & time
//   // for example to set April 14 2025 at 12:56 you would call:
//   rtc.set(0, 0, 6, 1, 25, 1, 26);
//   // rtc.adjust()
//   // rtc.set_12hour_mode(true);
//   // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
//   // set day of week (1=Sunday, 7=Saturday)

//   ///////////////////////////////////////////////////////////////////////////
// }


// // loop() function -- runs repeatedly as long as board is on ---------------



// void loop() {

//   // audio.loop();
  
//   myclock();
//   Digit(myclock().toInt(),0,0,255,0,0);
//   // Digit(temp_cnt,0,0,255,0,0);
//   Serial.println(myclock().toInt());
//   delay(1000);
//   // temp_cnt++;
//   // Fill along the length of the strip in various colors...

// //  colorWipe(255,   0,   0, 50); // Red
// //  rainbowSection(104,151,10);
// //  colorWipe(0, 255,   0, 50); // Green
// //  rainbowSection(104,151,10);
// //  colorWipe(0,   0, 255, 50); // Blue
// //  rainbowSection(104,151,10);


//   // temp_cnt++;
//   // Digit(temp_cnt,0,0,255,0,0);
//   // Serial.print(temp_cnt);
// //   myservo.write(0); 
// //  delay(1000);
// //  myservo.write(180); 
// //  delay(1000);
// // YoutubeCnt_call();
// // playFile("/charging.mp3");
// //
// // color();
// //  colorWipe_sign(strip_W.Color(255,   0,   0), 50); // Red
// //  colorWipe_sign(strip_W.Color(  0, 255,   0), 50); // Green
// //  colorWipe_sign(strip_W.Color(  0,   0, 255), 50); // Blue
// //  // Do a theater marquee effect in various colors...
// //  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
// //  theaterChase(strip.Color(127,   0,   0), 50); // Red, half brightness
// //  theaterChase(strip.Color(  0,   0, 127), 50); // Blue, half brightness
// // counter();
// // letter();
// // delay(5000);
//   // rainbow(10);             // Flowing rainbow cycle along the whole strip
//   // rainbow_1(10);
// //  theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant

// }


// // Some functions of our own for creating animated effects -----------------

// // Fill strip strip_S one after another with a color. Strip is NOT cleared
// // first; anything there will be covered pixel by pixel. Pass in color
// // (as a single 'packed' 32-bit value, which you can get by calling
// // strip.Color(red, green, blue) as shown in the loop() function above),
// // and a delay time (in milliseconds) between strip_S.


// void colorWipe(uint8_t R, uint8_t G, uint8_t B, int wait) {
    
//   for(int i=0; i<45; i++) { // For each pixel in strip...
//     strip_W.setPixelColor((89-i), strip_W.Color(R,G,B));

//     strip_W.setPixelColor(i, strip_W.Color(R,G,B));         //  Set pixel's color (in RAM)
   
//                            //  Update strip to match
//     if (i > 31 && i < 43){
      
//       strip_W.setPixelColor(cnt_s, strip_W.Color(R,G,B));
//       strip_W.setPixelColor(cnt_s_1, strip_W.Color(R,G,B));

//       if (cnt_s == 103){
//         strip_W.setPixelColor(103, strip_W.Color(G,R,B));
//       }

//       if (cnt_s == 102 ){
//         strip_W.setPixelColor(102, strip_W.Color(G,R,B));
//       }

//       cnt_s--;
//       cnt_s_1++;
//     }

//     strip_W.show();   
//     if(i == 44){
//       cnt_s = 103;
//       cnt_s_1 = 90;
//     }
//     delay(wait);                           //  Pause for a moment
//   }

//   // for(int i=0; i<strip_S.numstrip_S();i++){
//   //   strip_S.setPixelColor(i, color); 
//   //   strip_S.show();                          //  Update strip to match
//   //   delay(wait); 
//   // }

// }

// void rainbowSection(int start, int end, int wait) {
//   for(long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 256) {
//     for(int i = start; i <= end; i++) {
//       int pixelHue = firstPixelHue + ((i - start) * 65536L / (end - start + 1));
//       strip_W.setPixelColor(i, strip_W.gamma32(strip_W.ColorHSV(pixelHue)));
//     }
//     strip_W.show();
//     delay(wait);
//   }
// }

// void colorWipe_sign(uint32_t color, int wait) {
//   for(int i=42; i>=0; i--) { // For each pixel in strip...
//     // strip_W.setPixelColor((45*2)-i, color);
//     strip_W.setPixelColor(i, color);         //  Set pixel's color (in RAM)
//     strip_W.show();                          //  Update strip to match
//     delay(wait);                           //  Pause for a moment
//   }

//   // for(int i=0; i<strip_S.numstrip_S();i++){
//   //   strip_S.setPixelColor(i, color); 
//   //   strip_S.show();                          //  Update strip to match
//   //   delay(wait); 
//   // }

// }

// // // Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// // // a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// // // between frames.
// // void theaterChase(uint32_t color, int wait) {
// //   for(int a=0; a<10; a++) {  // Repeat 10 times...
// //     for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
// //       strip.clear();         //   Set all strip_S in RAM to 0 (off)
// //       // 'c' counts up from 'b' to end of strip in steps of 3...
// //       for(int c=b; c<strip.numstrip_S(); c += 3) {
// //         strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
// //       }
// //       strip.show(); // Update strip with new contents
// //       delay(wait);  // Pause for a moment
// //     }
// //   }
// // }

// // // Rainbow cycle along whole strip. Pass delay time (in ms) between frames.

// // void rainbow(int wait) {
// //   // Hue of first pixel runs 5 complete loops through the color wheel.
// //   // Color wheel has a range of 65536 but it's OK if we roll over, so
// //   // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
// //   // means we'll make 5*65536/256 = 1280 passes through this outer loop:
// //   for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
// //     for(int i=0; i<strip_S.numstrip_S(); i++) { // For each pixel in strip...
// //       // Offset pixel hue by an amount to make one full revolution of the
// //       // color wheel (range of 65536) along the length of the strip
// //       // (strip.numstrip_S() steps):
// //       int pixelHue = firstPixelHue + (i * 65536L / strip_S.numstrip_S());
// //       // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
// //       // optionally add saturation and value (brightness) (each 0 to 255).
// //       // Here we're using just the single-argument hue variant. The result
// //       // is passed through strip.gamma32() to provide 'truer' colors
// //       // before assigning to each pixel:
// //       strip_S.setPixelColor(i, strip_S.gamma32(strip_S.ColorHSV(pixelHue)));
// //     }
// //     strip_S.show(); // Update strip with new contents
// //     delay(wait);  // Pause for a moment
// //   }
// // }

// // // Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
// // void theaterChaseRainbow(int wait) {
// //   int firstPixelHue = 0;     // First pixel starts at red (hue 0)
// //   for(int a=0; a<30; a++) {  // Repeat 30 times...
// //     for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
// //       strip.clear();         //   Set all strip_S in RAM to 0 (off)
// //       // 'c' counts up from 'b' to end of strip in increments of 3...
// //       for(int c=b; c<strip.numstrip_S(); c += 3) {
// //         // hue of pixel 'c' is offset by an amount to make one full
// //         // revolution of the color wheel (range 65536) along the length
// //         // of the strip (strip.numstrip_S() steps):
// //         int      hue   = firstPixelHue + c * 65536L / strip.numstrip_S();
// //         uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
// //         strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
// //       }
// //       strip.show();                // Update strip with new contents
// //       delay(wait);                 // Pause for a moment
// //       firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
// //     }
// //   }
// // }


// // void rainbow(int wait) {
// //   // Hue of first pixel runs 5 complete loops through the color wheel.
// //   // Color wheel has a range of 65536 but it's OK if we roll over, so
// //   // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
// //   // means we'll make 5*65536/256 = 1280 passes through this outer loop:
// //   for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
// //     for(int i=0; i<strip_W.numstrip_S(); i++) { // For each pixel in strip...
// //       // Offset pixel hue by an amount to make one full revolution of the
// //       // color wheel (range of 65536) along the length of the strip
// //       // (strip.numstrip_S() steps):
// //       int pixelHue = firstPixelHue + (i * 65536L / strip_W.numstrip_S());
// //       // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
// //       // optionally add saturation and value (brightness) (each 0 to 255).
// //       // Here we're using just the single-argument hue variant. The result
// //       // is passed through strip.gamma32() to provide 'truer' colors
// //       // before assigning to each pixel:
// //       strip_W.setPixelColor(i, strip_W.gamma32(strip_W.ColorHSV(pixelHue)));
// //     }
// //     strip_W.show(); // Update strip with new contents
// //     delay(wait);  // Pause for a moment
// //   }
// // }

// // void rainbow_1(int wait) {
// //   // Hue of first pixel runs 5 complete loops through the color wheel.
// //   // Color wheel has a range of 65536 but it's OK if we roll over, so
// //   // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
// //   // means we'll make 5*65536/256 = 1280 passes through this outer loop:
// //   for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
// //     for(int i=0; i<strip_S.numstrip_S(); i++) { // For each pixel in strip...
// //       // Offset pixel hue by an amount to make one full revolution of the
// //       // color wheel (range of 65536) along the length of the strip
// //       // (strip.numstrip_S() steps):
// //       int pixelHue = firstPixelHue + (i * 65536L / strip_S.numstrip_S());
// //       // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
// //       // optionally add saturation and value (brightness) (each 0 to 255).
// //       // Here we're using just the single-argument hue variant. The result
// //       // is passed through strip.gamma32() to provide 'truer' colors
// //       // before assigning to each pixel:
// //       strip_S.setPixelColor(i, strip_S.gamma32(strip_S.ColorHSV(pixelHue)));
// //     }
// //     strip_S.show(); // Update strip with new contents
// //     delay(wait);  // Pause for a moment
// //   }
// // }



// void playFile(const char *filename)
// {
//     Serial.print("Playing: ");
//     Serial.println(filename);

//     audio.stopSong();
//     audio.connecttoFS(SD, filename);
// }


// void Digit(long hour, uint8_t min, uint8_t format, uint8_t r, uint8_t g, uint8_t b){
//     strip_S.clear();
//     int led0,led1,led2;
//     long one, ten, hundred, thousand;

//     int numArray[10][7] = {
//       {1,1,1,0,1,1,1}, // 0
//       {1,0,0,0,1,0,0}, // 1
//       {0,1,1,1,1,1,0}, // 2
//       {1,1,0,1,1,1,0}, // 3
//       {1,0,0,1,1,0,1}, // 4
//       {1,1,0,1,0,1,1}, // 5
//       {1,1,1,1,0,1,1}, // 6
//       {1,0,0,0,1,1,0}, // 7
//       {1,1,1,1,1,1,1}, // 8
//       {1,1,0,1,1,1,1}  // 9
//     };

//     // if(format == 0){
//     //   if(hour > 12)
//     //   hour = 9;
//     // }
//     // if(min >)
//         // 23:59 max
//         // 00:00 min
        
//     thousand = hour / 1000;
    
//     hundred = hour % 1000 / 100;
    
//     ten = hour % 100 / 10;
    
//     one = hour % 10 / 1;

//         Serial.print("data ");
//         Serial.println(hour);

//         Serial.print("thousand ");
//         Serial.println(thousand);

//         Serial.print("hundred ");
//         Serial.println(hundred);

//         Serial.print("ten ");
//         Serial.println(ten);

//         Serial.print("one ");
//         Serial.println(one);


//         for (int i = 0; i < 7; i++) {
//             // Serial.print(numArray[hour][i]);
//             // Serial.println();
//             if (numArray[one][i] == 1){
                
//                 led0 = i*3;
//                 led1 = led0+1;
//                 led2 = led1+1;
//                 // printf("led0: %d, led1: %d, led2: %d \n",led0,led1,led2);
//                 strip_S.setPixelColor(led0, strip_S.Color(r, g, b));
//                 strip_S.setPixelColor(led1, strip_S.Color(r, g, b));
//                 strip_S.setPixelColor(led2, strip_S.Color(r, g, b));
//                 // strip_S.show();
//                 // delay(10);
//             }
//             // if (numArray[one][i] == 0) {
//             //     strip_S.setPixelColor(led0, strip_S.Color(0,0,0));
//             //     strip_S.setPixelColor(led1, strip_S.Color(0,0,0));
//             //     strip_S.setPixelColor(led2, strip_S.Color(0,0,0));
//             //     // strip_S.show();
//             //     // delay(10);
//             // }

//         }

//         for (int i = 7; i < 14; i++) {
//             if (numArray[ten][i-7] == 1){
//                 led0 = i*3;
//                 led1 = led0+1;
//                 led2 = led1+1;
//                 // printf("led0: %d, led1: %d, led2: %d \n",led0,led1,led2);
//                 strip_S.setPixelColor(led0, strip_S.Color(r, g, b));
//                 strip_S.setPixelColor(led1, strip_S.Color(r, g, b));
//                 strip_S.setPixelColor(led2, strip_S.Color(r, g, b));
//                 // strip_S.show();
//             }
//             // if (numArray[ten][i-7] == 0){
//             //     strip_S.setPixelColor(led0, strip_S.Color(0,0,0));
//             //     strip_S.setPixelColor(led1, strip_S.Color(0,0,0));
//             //     strip_S.setPixelColor(led2, strip_S.Color(0,0,0));
//             //     // strip_S.show();
//             // }

//         }

//         for (int i = 15; i < 22; i++) {
//             if (numArray[hundred][i-15] == 1){
//                 led0 = i*3;
//                 led1 = led0+1;
//                 led2 = led1+1;
//                 // printf("led0: %d, led1: %d, led2: %d \n",led0,led1,led2);
//                 strip_S.setPixelColor(led0, strip_S.Color(r, g, b));
//                 strip_S.setPixelColor(led1, strip_S.Color(r, g, b));
//                 strip_S.setPixelColor(led2, strip_S.Color(r, g, b));
//                 // strip_S.show();
//             }
//             // if (numArray[hundred][i-15] == 0){
//             //     strip_S.setPixelColor(led0, strip_S.Color(0,0,0));
//             //     strip_S.setPixelColor(led1, strip_S.Color(0,0,0));
//             //     strip_S.setPixelColor(led2, strip_S.Color(0,0,0));
//             //     // strip_S.show();
//             // }

//         }

//         for (int i = 22; i < 29; i++) {

//             if (numArray[thousand][i-22] == 1){
//                 led0 = i*3;
//                 led1 = led0+1;
//                 led2 = led1+1;
//                 // printf("led0: %d, led1: %d, led2: %d \n",led0,led1,led2);
//                 strip_S.setPixelColor(led0, strip_S.Color(r, g, b));
//                 strip_S.setPixelColor(led1, strip_S.Color(r, g, b));
//                 strip_S.setPixelColor(led2, strip_S.Color(r, g, b));
//                 // strip_S.show();
//             }
//             // if (numArray[thousand][i-22] == 0){
//             //     strip_S.setPixelColor(led0, strip_S.Color(0,0,0));
//             //     strip_S.setPixelColor(led1, strip_S.Color(0,0,0));
//             //     strip_S.setPixelColor(led2, strip_S.Color(0,0,0));
//             //     // strip_S.show();
//             // }

//         }
//         delay(10);
//         strip_S.show();
// }


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
#include "Audio.h"
#include "SD.h"
#include "FS.h"
#include "SPI.h"
#include <ESP32Servo.h> 

// #include <YoutubeApi.h>
// #include <WiFiClientSecure.h>
// #include <ArduinoJson.h> 

#include "BluetoothSerial.h"

/////////////////Youtube API//////////////
// char ssid[] = "kale";     
// char password[] = "123456789";
// #define API_KEY "xxxxxxxx"
// #define CHANNEL_ID "UCmWXFDKf36ZgyPB0S3WyxwA"
 
// WiFiClientSecure client;
// YoutubeApi api(API_KEY, client);

// unsigned long api_mtbs = 1000; 
// unsigned long api_lasttime;
// long subs = 0;
// String subs_count;
// String view_count;
 ////////////////////////////////////////


// #ifdef __AVR__                                                   ----------
//  #include <avr/power.h> // Required for 16 MHz Adafruit Trinket  ---------
// #endif                                                           ---------

// #include <Arduino_FreeRTOS.h>   --------
// Which pin on the Arduino is connected to the Neostrip_C?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN_W     14//18 //6   // Clock  // need to change
#define LED_PIN_C     27//19 //10  // wall    // need to change
#define LED_PIN_S     26//19 //10  // Wall Sign     // need to change

// SD Card pins
#define SD_CS      5
#define SPI_MOSI   23
#define SPI_MISO   19
#define SPI_SCK    18

// I2S pins for MAX98357A
#define I2S_DOUT   32
#define I2S_BCLK   33
#define I2S_LRC    25

// How many Neostrip_C are attached to the Arduino?
#define LED_COUNT_W   160
#define LED_COUNT_C   90
#define LED_COUNT_S   40


char buffer[64]; // Define character array with sufficient size
int bytesRead = 0;

TaskHandle_t ledTask1;
// TaskHandle_t ledTask2;

// Audio audio;
Servo myservo; 
uRTCLib rtc(0x68);
BluetoothSerial SerialBT;

char mode = '0';
char daysOfTheWeek[7][12] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

int cnt_s = 103;

int servoPin = 13;  // GPIO 13 servo connected

int cnt_s_1 = 90;
long temp_cnt = 0;

Adafruit_NeoPixel strip_W(LED_COUNT_W, LED_PIN_W, NEO_GRB + NEO_KHZ800);  // Wall 
Adafruit_NeoPixel strip_C(LED_COUNT_C, LED_PIN_C, NEO_GRB + NEO_KHZ800);  // Clock 
Adafruit_NeoPixel strip_S(LED_COUNT_S, LED_PIN_S, NEO_GRB + NEO_KHZ800);  // Sign 


// void playFile(const char *filename)
// {
//     Serial.print("Playing: ");
//     Serial.println(filename);

//     audio.stopSong();
//     audio.connecttoFS(SD, filename);
// }


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

// void color(){
//     for(int i = strip_W.numstrip_C();i>=0;i--){
//     // strip_W.clear();
//     strip_W.setPixelColor(i, strip_W.Color(0,0,255));         //  Set pixel's color (in RAM)
//     // strip_W.show();
//     // Serial.println(i);                     //  Update strip to match
//     // delay(100);   
//   }

//   strip_W.show();

//       for(int i = strip_C.numstrip_C();i>=0;i--){
//     // strip_W.clear();
//     strip_C.setPixelColor(i, strip_C.Color(0,0,255));         //  Set pixel's color (in RAM)
//     // strip_W.show();
//     // Serial.println(i);                     //  Update strip to match
//     // delay(100);   
//   }

//   strip_C.show();
// }

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
  // Digit(temp_cnt,0,0,255,0,0);
  // Serial.println(temp_cnt);
  // delay(1000);
  // temp_cnt++;

}

// void YoutubeCnt_call(){

//     static int tempSub;
//     if (millis() - api_lasttime > api_mtbs)  {
//         if(api.getChannelStatistics(CHANNEL_ID))
//         {
            
//             subs_count = api.channelStats.subscriberCount ;
//             view_count = api.channelStats.viewCount ;

//             if (tempSub <= 0){
//               tempSub = subs_count.toInt();
//               Digit(subs_count.toInt(),0,0,0,0,255);
//             }else if (tempSub > subs_count.toInt())
//             {
//               Serial.println("Dec !!!");
//               //   myservo.write(0); 
//               // delay(1000);
//               // myservo.write(90); 
//               tempSub = subs_count.toInt();
//               Digit(subs_count.toInt(),0,0,255,0,0);
//               delay(5000);
//               /* code */
//             }else if (tempSub < subs_count.toInt())
//             {
//               Serial.println("Inc !!!");
//               // myservo.write(180); 
//               // delay(1000);
//               // myservo.write(90); 
//               tempSub = subs_count.toInt();
//               Digit(subs_count.toInt(),0,0,0,255,0);
//               delay(5000);
//               /* code */
//             }else{
//               tempSub = subs_count.toInt();
//               Digit(subs_count.toInt(),0,0,0,0,255);
//             }
            
            
//             // tempSub = subs_count.toInt();
            
//             Serial.println("---------Status---------");
//             Serial.println("Zeno_Modiff");
//             Serial.print("S: ");
//             Serial.println(subs_count);

//             Serial.print("V: ");
//             Serial.println(view_count);
//             Serial.println("------------------------");

//             /////// Sub count///////
//             // lcd.clear();
//             // lcd.setCursor(0,0);
//             // lcd.print("Sub :");
//             // lcd.setCursor(6,0);
//             // lcd.print(subs_count);

//             ////// View count///////
//             // lcd.setCursor(0,1);
//             // lcd.print("View :");
//             // lcd.setCursor(7,1);
//             // lcd.print(view_count);

//         }
//     api_lasttime = millis();
//   }
// }

// void wifi_init(){
 
//     WiFi.mode(WIFI_STA);
//     WiFi.disconnect();
//     delay(100);
    
//     Serial.print("Connecting Wifi: ");
//     // lcd.clear();
//     // lcd.setCursor(0,0);
//     // lcd.print("Connecting ");
//     // lcd.setCursor(0,1);
//     // lcd.print("Wifi.....");

//     delay(250);

//     Serial.println(ssid);
//     WiFi.begin(ssid, password);
//     while (WiFi.status() != WL_CONNECTED) {
//     Serial.print(".");
//     delay(500);
//     }

//     Serial.println("");
//     Serial.println("WiFi");


//     Serial.println("IP address: ");
//     IPAddress ip = WiFi.localIP();
//     Serial.println(ip);
    
//     // lcd.clear();
//     // lcd.setCursor(0,0);
//     // lcd.print("Connected");
//     // lcd.setCursor(0,1);
//     // lcd.print(WiFi.SSID());
//     delay(2000);

//      client.setInsecure(); 

// }

// void audio_init(){
//   SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);

//     if (!SD.begin(SD_CS)) {

//         Serial.println("SD Card Failed!");

//         while(1);
//     }

//     Serial.println("SD OK");

//     audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);

//     audio.setVolume(18);

//     Serial.println("Starting audio...");

//     if(audio.connecttoFS(SD, "/charging.mp3")) {

//         Serial.println("MP3 started");

//     } else {

//         Serial.println("MP3 failed");
//     }
// }

void colorWipe(uint8_t R, uint8_t G, uint8_t B, int wait) {
    
  for(int i=0; i<45; i++) { // For each pixel in strip...
    strip_W.setPixelColor((89-i), strip_W.Color(R,G,B));

    strip_W.setPixelColor(i, strip_W.Color(R,G,B));         //  Set pixel's color (in RAM)
   
                           //  Update strip to match
    if (i > 31 && i < 43){
      
      strip_W.setPixelColor(cnt_s, strip_W.Color(R,G,B));
      strip_W.setPixelColor(cnt_s_1, strip_W.Color(R,G,B));

      if (cnt_s == 103){
        strip_W.setPixelColor(103, strip_W.Color(G,R,B));
      }

      if (cnt_s == 102 ){
        strip_W.setPixelColor(102, strip_W.Color(G,R,B));
      }

      cnt_s--;
      cnt_s_1++;
    }

    strip_W.show();   
    if(i == 44){
      cnt_s = 103;
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

void rainbowSection(int start, int end, int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 256) {
    for(int i = start; i <= end; i++) {
      int pixelHue = firstPixelHue + ((i - start) * 65536L / (end - start + 1));
      strip_W.setPixelColor(i, strip_W.gamma32(strip_W.ColorHSV(pixelHue)));
    }
    strip_W.show();
    delay(wait);
  }
}

void rainbow_Sign(int start, int end, int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 256) {
    for(int i = start; i <= end; i++) {
      int pixelHue = firstPixelHue + ((i - start) * 65536L / (end - start + 1));
      strip_S.setPixelColor(i, strip_S.gamma32(strip_S.ColorHSV(pixelHue)));
    }
    strip_S.show();
    delay(wait);
  }
}

void colorWipe_sign(uint32_t color, int wait) {
  for(int i=42; i>=0; i--) { // For each pixel in strip...
    // strip_W.setPixelColor((45*2)-i, color);
    strip_S.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip_S.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }

  // for(int i=0; i<strip_C.numstrip_C();i++){
  //   strip_C.setPixelColor(i, color); 
  //   strip_C.show();                          //  Update strip to match
  //   delay(wait); 
  // }

}

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
  rainbowSection(104,151,10);
  colorWipe(0, 255,   0, 50); // Green
  rainbowSection(104,151,10);
  colorWipe(0,   0, 255, 50); // Blue
  rainbowSection(104,151,10);

  rainbow_Sign(0,35,10);

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

    if (i >= 102){
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
          if (buffer[0] == 'T' && buffer[5] == 'T')
          {
            mode = 'T';
          }

          if (buffer[0] == 'P')
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

// =========================
// TASK 2
// =========================
// void blinkLed2(void * parameter)
// {
//     while(true)
//     {
//         // digitalWrite(LED2, HIGH);
//         // vTaskDelay(100 / portTICK_PERIOD_MS);

//         // digitalWrite(LED2, LOW);
//         // vTaskDelay(100 / portTICK_PERIOD_MS);
//     }
// }

// =========================

void setup() {


  Serial.begin(9600);

  SerialBT.begin("Studio_Wall");

  // audio_init();

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

    myservo.attach(servoPin, 500, 2400);   // attaches the servo on pin 18 to the servo object
    myservo.write(90); 
    // wifi_init();
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

    // Create Task 2
    // xTaskCreatePinnedToCore(
    //     blinkLed2,
    //     "LED2_Task",
    //     1000,
    //     NULL,
    //     1,
    //     &ledTask2,
    //     1
    // );
// =========================

}

void loop() {

  // myclock();
  // Digit(myclock().toInt(),0,0,255,0,0);

 

  if (mode == '0')
  {
    default_effect();
    /* code */
  }else if (mode == '1')
  {
    fadding_effect(255,0,0); // Red
    /* code */
  }
  else if (mode == '2')
  {
    fadding_effect(0,255,0); // Green
    /* code */
  }else if (mode == '3')
  {
    fadding_effect(0,0,255); //Blue
    /* code */
  }else if (mode == '4')
  {
    fadding_effect(0,255,255); // Cyan
    /* code */
  }else if (mode == '5')
  {
    fadding_effect(255,40,0); // Coral
    /* code */
  }else if (mode == '6')
  {
    fadding_effect(255,215,0); // gold
    /* code */
  }else if (mode == '7')
  {
    Solid_Color(255,0,0); // Red solid
    /* code */
  }else if (mode == '8') 
  {
    Solid_Color(0,255,0); // Green solid
    /* code */
  }else if (mode == '9')
  {
    Solid_Color(0,0,255); // Blue solid
    /* code */
  }else if (mode == 'A')
  {
    Solid_Color(0,255,255); // Cyan solid
    /* code */
  }else if (mode == 'B')
  {
    Solid_Color(255,40,0); // Coral solid
    /* code */
  }else if (mode == 'C')
  {
    Solid_Color(255,215,0); // gold solid
    /* code */
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
  }else{
    // default_effect();
  }
  
  
  // Serial.print("Loop mode ");
  // Serial.println(mode);
  



  // for (int i = 0; i < 87; i++)
  // {
  //    strip_C.setPixelColor(i, strip_C.Color(255,0,0));
  //    strip_C.show();
  //    printf("led pos %d \n", i);
  //    delay(500);
  //   /* code */
  // }
  
  

  // Digit(8888,0,0,255,0,0);
  // Serial.println(myclock().toInt());
  // delay(1000);
  // temp_cnt++;
  // Fill along the length of the strip in various colors...


  /////////////////////////////////////////////////
//  colorWipe(255,   0,   0, 50); // Red
//  rainbowSection(104,151,10);
//  colorWipe(0, 255,   0, 50); // Green
//  rainbowSection(104,151,10);
//  colorWipe(0,   0, 255, 50); // Blue
//  rainbowSection(104,151,10);

/////////////////////////////////////////

// fadding_effect(255,0,0); // Red

// fadding_effect(0,255,0); // Green

// fadding_effect(0,0,255); //Blue

// fadding_effect(0,255,255); // Cyan

//                                                                                                                                      

// fadding_effect(255,215,0); // gold

// fadding_effect(255, 255, 255); // white

// YoutubeCnt_call();
// delay(5000);
  // temp_cnt++;
  // Digit(temp_cnt,0,0,255,0,0);
  // Serial.print(temp_cnt);
//   myservo.write(0); 
//  delay(1000);
//  myservo.write(180); 
//  delay(1000);

//
// color();
//  colorWipe_sign(strip_W.Color(255,   0,   0), 50); // Red
//  colorWipe_sign(strip_W.Color(  0, 255,   0), 50); // Green
//  colorWipe_sign(strip_W.Color(  0,   0, 255), 50); // Blue
//  // Do a theater marquee effect in various colors...
//  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
//  theaterChase(strip.Color(127,   0,   0), 50); // Red, half brightness
//  theaterChase(strip.Color(  0,   0, 127), 50); // Blue, half brightness
// counter();
// letter();
// delay(5000);
  // rainbow(10);             // Flowing rainbow cycle along the whole strip
  // rainbow_1(10);
//  theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant

}


// // Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// // a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// // between frames.
// void theaterChase(uint32_t color, int wait) {
//   for(int a=0; a<10; a++) {  // Repeat 10 times...
//     for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
//       strip.clear();         //   Set all strip_C in RAM to 0 (off)
//       // 'c' counts up from 'b' to end of strip in steps of 3...
//       for(int c=b; c<strip.numstrip_C(); c += 3) {
//         strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
//       }
//       strip.show(); // Update strip with new contents
//       delay(wait);  // Pause for a moment
//     }
//   }
// }

// // Rainbow cycle along whole strip. Pass delay time (in ms) between frames.

// void rainbow(int wait) {
//   // Hue of first pixel runs 5 complete loops through the color wheel.
//   // Color wheel has a range of 65536 but it's OK if we roll over, so
//   // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
//   // means we'll make 5*65536/256 = 1280 passes through this outer loop:
//   for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
//     for(int i=0; i<strip_C.numstrip_C(); i++) { // For each pixel in strip...
//       // Offset pixel hue by an amount to make one full revolution of the
//       // color wheel (range of 65536) along the length of the strip
//       // (strip.numstrip_C() steps):
//       int pixelHue = firstPixelHue + (i * 65536L / strip_C.numstrip_C());
//       // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
//       // optionally add saturation and value (brightness) (each 0 to 255).
//       // Here we're using just the single-argument hue variant. The result
//       // is passed through strip.gamma32() to provide 'truer' colors
//       // before assigning to each pixel:
//       strip_C.setPixelColor(i, strip_C.gamma32(strip_C.ColorHSV(pixelHue)));
//     }
//     strip_C.show(); // Update strip with new contents
//     delay(wait);  // Pause for a moment
//   }
// }

// // Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
// void theaterChaseRainbow(int wait) {
//   int firstPixelHue = 0;     // First pixel starts at red (hue 0)
//   for(int a=0; a<30; a++) {  // Repeat 30 times...
//     for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
//       strip.clear();         //   Set all strip_C in RAM to 0 (off)
//       // 'c' counts up from 'b' to end of strip in increments of 3...
//       for(int c=b; c<strip.numstrip_C(); c += 3) {
//         // hue of pixel 'c' is offset by an amount to make one full
//         // revolution of the color wheel (range 65536) along the length
//         // of the strip (strip.numstrip_C() steps):
//         int      hue   = firstPixelHue + c * 65536L / strip.numstrip_C();
//         uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
//         strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
//       }
//       strip.show();                // Update strip with new contents
//       delay(wait);                 // Pause for a moment
//       firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
//     }
//   }
// }


// void rainbow(int wait) {
//   // Hue of first pixel runs 5 complete loops through the color wheel.
//   // Color wheel has a range of 65536 but it's OK if we roll over, so
//   // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
//   // means we'll make 5*65536/256 = 1280 passes through this outer loop:
//   for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
//     for(int i=0; i<strip_W.numstrip_C(); i++) { // For each pixel in strip...
//       // Offset pixel hue by an amount to make one full revolution of the
//       // color wheel (range of 65536) along the length of the strip
//       // (strip.numstrip_C() steps):
//       int pixelHue = firstPixelHue + (i * 65536L / strip_W.numstrip_C());
//       // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
//       // optionally add saturation and value (brightness) (each 0 to 255).
//       // Here we're using just the single-argument hue variant. The result
//       // is passed through strip.gamma32() to provide 'truer' colors
//       // before assigning to each pixel:
//       strip_W.setPixelColor(i, strip_W.gamma32(strip_W.ColorHSV(pixelHue)));
//     }
//     strip_W.show(); // Update strip with new contents
//     delay(wait);  // Pause for a moment
//   }
// }

// void rainbow_1(int wait) {
//   // Hue of first pixel runs 5 complete loops through the color wheel.
//   // Color wheel has a range of 65536 but it's OK if we roll over, so
//   // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
//   // means we'll make 5*65536/256 = 1280 passes through this outer loop:
//   for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
//     for(int i=0; i<strip_C.numstrip_C(); i++) { // For each pixel in strip...
//       // Offset pixel hue by an amount to make one full revolution of the
//       // color wheel (range of 65536) along the length of the strip
//       // (strip.numstrip_C() steps):
//       int pixelHue = firstPixelHue + (i * 65536L / strip_C.numstrip_C());
//       // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
//       // optionally add saturation and value (brightness) (each 0 to 255).
//       // Here we're using just the single-argument hue variant. The result
//       // is passed through strip.gamma32() to provide 'truer' colors
//       // before assigning to each pixel:
//       strip_C.setPixelColor(i, strip_C.gamma32(strip_C.ColorHSV(pixelHue)));
//     }
//     strip_C.show(); // Update strip with new contents
//     delay(wait);  // Pause for a moment
//   }
// }

