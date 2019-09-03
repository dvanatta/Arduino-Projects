#include "LPD8806.h"
#include "SPI.h" // Comment out this line if using Trinket or Gemma
#ifdef __AVR_ATtiny85__
 #include <avr/power.h>
#endif

// Example to control LPD8806-based RGB LED Modules in a strip

/*****************************************************************************/

// Number of RGB LEDs in strand:
int nLEDs = 32;

// Chose 2 pins for output; can be any valid output pins:
int dataPin  = 2;
int clockPin = 3;
int powerPin = 9;




// First parameter is the number of LEDs in the strand.  The LED strips
// are 32 LEDs per meter but you can extend or cut the strip.  Next two
// parameters are SPI data and clock pins:
LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);
int r=255;
int g=66;
int b=223;

// You can optionally use hardware SPI for faster writes, just leave out
// the data and clock pin parameters.  But this does limit use to very
// specific pins on the Arduino.  For "classic" Arduinos (Uno, Duemilanove,
// etc.), data = pin 11, clock = pin 13.  For Arduino Mega, data = pin 51,
// clock = pin 52.  For 32u4 Breakout Board+ and Teensy, data = pin B2,
// clock = pin B1.  For Leonardo, this can ONLY be done on the ICSP pins.
//LPD8806 strip = LPD8806(nLEDs);
int switchState = 0;

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif
  pinMode(powerPin,OUTPUT);
  pinMode(4, INPUT);
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  // Start up the LED strip
  strip.begin();
  strip.show();
  int i;
  // Update the strip, to start they are all 'off'
    for(i=29; i<strip.numPixels(); i++) strip.setPixelColor(i, strip.Color(127,20,100));
  strip.show();
}

  int room_num = 0;
  int room_count = nLEDs/2-1;
  int house_switch = 0;
  int rainbow_switch = 0;
  int house_flag = 0;
  int rainbow_flag = 1;
  int casino_flag = 0;
  int casino_switch =0;
  int roll =50;
  int house_color_flag = 4;
  int room_color_flag = 0;
  int whole_box_switch =0;
  int top_box_switch =0;
  int bottom_box_switch =0;
  int left_box_switch =0;
  int right_box_switch =0;

void loop() {
  
    house_switch = digitalRead(11);
    rainbow_switch = digitalRead(12);
    casino_switch = digitalRead(13);
    whole_box_switch = digitalRead(10);
    top_box_switch = digitalRead(9);
    bottom_box_switch = digitalRead(7);
    left_box_switch = digitalRead(6);
    right_box_switch = digitalRead(5);
    if (casino_flag ==1 ){
      
       houseChase(strip.Color(244,66,244), 100);
    }
    if (digitalRead(4)==HIGH){
        house_flag =0;
        rainbow_flag =0;
        casino_flag=0;
//      pulse(r,g,b,20);
    }
    else if ((house_switch == HIGH)) {
      rainbow_flag = 0;
      house_flag = 1;

      casino_flag = 0;
      
      if (room_num >= room_count){
        change_room(strip.Color(r,g,b), 145, room_num);
        update_rgb();
        room_num = 0;
         
      }
      else {

        change_room(strip.Color(r,g,b), 145, room_num);
        room_num += 1;
        
      }
    }
    else if (whole_box_switch == HIGH) {
      rainbow_flag = 0;
      house_flag = 1;

      casino_flag = 0;
      update_rgb();
      whole_box_color(strip.Color(r,g,b));
      
    }
        else if (top_box_switch == HIGH) {
      rainbow_flag = 0;
      house_flag = 1;

      casino_flag = 0;
      update_rgb();
      top_box_color(strip.Color(r,g,b));
      
    }
        else if (bottom_box_switch == HIGH) {
      rainbow_flag = 0;
      house_flag = 1;

      casino_flag = 0;
      update_rgb();
      bottom_box_color(strip.Color(r,g,b));
      
    }
        else if (left_box_switch == HIGH) {
      rainbow_flag = 0;
      house_flag = 1;

      casino_flag = 0;
      update_rgb();
      left_box_color(strip.Color(r,g,b));
      
    }
        else if (right_box_switch == HIGH) {
      rainbow_flag = 0;
      house_flag = 1;

      casino_flag = 0;
      update_rgb();
      right_box_color(strip.Color(r,g,b));
      
    }
    else if ((rainbow_switch == HIGH) or (rainbow_flag == 1)){
//      theaterChaseRainbow(10);
//        rainbow_flag =1;
        house_flag =0;
        casino_flag = 0;
        rainbow_flag = rainbowCycle(10*house_color_flag);
    }
    
    else if (casino_switch == HIGH){
      casino_flag =1;
      rainbow_flag = 0;
      house_flag =0;
//      colorChase(strip.Color(127, 127, 127), 50);
      roll = casino(50);
      pulse(1,1,1,5);
//      roll = 0;
      animate_roll(roll % 8);
    }
    else if (house_flag ==0 and casino_flag ==0){
      int i;
//      for(i=29; i<strip.numPixels(); i++) strip.setPixelColor(i, strip.Color(127,20,100));
      pulse(1,0,0,20);
      pulse(0,1,0,20);
//      christmas();
//      pulse(1,0,1,20);
//      pulse(0,1,1,20);
//      pulse(0,0,1,20);
//      pulse(1,0,0,20);
    }

//    while(digitalRead(13) == HIGH) {
//      rainbowCycle(10);
//    }
//    while(digitalRead(13) == LOW ){
// 
//    
//      house(strip.Color(5,5,5), 500);
//      house(strip.Color(0,5,5), 500);
//    }
//      house(strip.Color(204,255,229), 500);
//      house(strip.Color(255,0,255), 500);
//      house(strip.Color(255,51,255), 500);
//      colorWipe(strip.Color(  0, 127,   0), 0);
//      colorWipe(strip.Color(  0, 127,   0), 50);
//  // Send a simple pixel chase in...
//    colorChase(strip.Color(127, 127, 127), 50); // White
    
//  colorChase(strip.Color(127,   0,   0), 50); // Red
//  colorChase(strip.Color(127, 127,   0), 50); // Yellow
//  colorChase(strip.Color(  0, 127,   0), 50); // Green
//  colorChase(strip.Color(  0, 127, 127), 50); // Cyan
//  colorChase(strip.Color(  0,   0, 127), 50); // Blue
//  colorChase(strip.Color(127,   0, 127), 50); // Violet
//
////  // Send a theater pixel chase in...
//  theaterChase(strip.Color(127, 127, 127), 50); // White
//  theaterChase(strip.Color(127,   0,   0), 50); // Red
//  theaterChase(strip.Color(127, 127,   0), 50); // Yellow
//  theaterChase(strip.Color(  0, 127,   0), 50); // Green
//  theaterChase(strip.Color(  0, 127, 127), 50); // Cyan
//  theaterChase(strip.Color(  0,   0, 127), 50); // Blue
//  theaterChase(strip.Color(127,   0, 127), 50); // Violet
//
//  // Fill the entire strip with...
//  colorWipe(strip.Color(127,   0,   0), 50);  // Red
//  colorWipe(strip.Color(  0, 127,   0), 50);  // Green
//  colorWipe(strip.Color(  0,   0, 127), 50);  // Blue
//
//  rainbow(10);
    // make it go through the cycle fairly fast
//  theaterChaseRainbow(50);
}
void update_rgb(){
    if (house_color_flag == 0){
//          g = 0;
    r = 255;
    g = 255;
    b = 255;
    house_color_flag += 1;
  }
  else if (house_color_flag == 1 ){
    r = 255;
    g = 0;
    b = 0;
    house_color_flag +=1;
    
  }
    else if (house_color_flag == 2 ){
    r = 127/2;
    g = 0;
    b = 255/2;
    house_color_flag +=1;
    
  }
    else if (house_color_flag == 3 ){
    r = 244/2;
    g = 255/2;
    b = 0;
    house_color_flag +=1;
    
  }
  else {
    r = 0;
    g = 0;
    b = 255;
    house_color_flag =0;
  }
}

void pulse(uint16_t r, uint16_t g, uint16_t b, uint16_t wait){
  int i=0;
  int j=0;
  int k=0;
//   for(i=0; i<strip.numPixels(); i++) strip.setPixelColor(i, 0);
  for(i=0; i<=127; i++){
    for (j=0; j<= strip.numPixels()-4; j++){
      strip.setPixelColor(j,strip.Color(r*i,g*i,b*i));
    }
    strip.show();
    if ((digitalRead(4) == HIGH) or (digitalRead(11)==HIGH) or (digitalRead(12)==HIGH) or (digitalRead(13) == HIGH) or digitalRead(10)==HIGH or digitalRead(9)==HIGH or digitalRead(8)==HIGH or digitalRead(7)==HIGH or digitalRead(6)==HIGH or digitalRead(5)==HIGH){
      return;
    }
    delay(wait);

  }
  for(k=0; k<=127; k++){   
    for (j=0; j<= strip.numPixels()-4; j++){
      strip.setPixelColor(j,strip.Color((127-k)*r,(127-k)*g,(127-k)*b));
    }
    strip.show();
    if ((digitalRead(4) == HIGH) or (digitalRead(11)==HIGH) or (digitalRead(12)==HIGH) or (digitalRead(13) == HIGH) or digitalRead(10)==HIGH or digitalRead(9)==HIGH or digitalRead(8)==HIGH or digitalRead(7)==HIGH or digitalRead(6)==HIGH or digitalRead(5)==HIGH){
      return;
    }
    delay(wait);

  }
//  delay(wait*10);
i=0;
k=0;
}


void whole_box_color(uint32_t c){
  int i;
  for(i=0; i<strip.numPixels(); i++) strip.setPixelColor(i, c);
  strip.show();
  delay(140);
}
void top_box_color(uint32_t c){
  int i;
  for(i=16; i<strip.numPixels(); i++) strip.setPixelColor(i, c);
  strip.show();
  delay(140);
}
void bottom_box_color(uint32_t c){
  int i;
  for(i=0; i<strip.numPixels()/2; i++) strip.setPixelColor(i, c);
  strip.show();
  delay(140);
}
void left_box_color(uint32_t c){
  strip.setPixelColor(0, c);
  strip.setPixelColor(1, c);
  strip.setPixelColor(2, c);
  strip.setPixelColor(3, c);
  strip.setPixelColor(4, c);
  strip.setPixelColor(5, c);
  strip.setPixelColor(6, c);
  strip.setPixelColor(7, c);
  strip.setPixelColor(16, c);
  strip.setPixelColor(17, c);
  strip.setPixelColor(18, c);
  strip.setPixelColor(19, c);
  strip.setPixelColor(20, c);
  strip.setPixelColor(21, c);
  strip.setPixelColor(22, c);
  strip.setPixelColor(23, c);
  strip.show();
  delay(140);
}
void right_box_color(uint32_t c){
  strip.setPixelColor(8, c);
  strip.setPixelColor(9, c);
  strip.setPixelColor(10, c);
  strip.setPixelColor(11, c);
  strip.setPixelColor(12, c);
  strip.setPixelColor(13, c);
  strip.setPixelColor(14, c);
  strip.setPixelColor(15, c);
  strip.setPixelColor(24, c);
  strip.setPixelColor(25, c);
  strip.setPixelColor(26, c);
  strip.setPixelColor(27, c);
  strip.setPixelColor(28, c);
  strip.setPixelColor(29, c);
  strip.setPixelColor(30, c);
  strip.setPixelColor(31, c);
  strip.show();
  delay(140);
}
void christmas(){
    int i =0;
    int j =0;
    int k =0;
    for(i=0; i<=255; i++){
    for (j=0; j<= strip.numPixels()-4; j++){
      strip.setPixelColor(j,strip.Color(j*i,j*(255-i),0));
    }
    strip.show();
    delay(10);
    if ((digitalRead(4) == HIGH) or (digitalRead(11)==HIGH) or (digitalRead(12)==HIGH) or (digitalRead(13) == HIGH) or digitalRead(10)==HIGH or digitalRead(9)==HIGH or digitalRead(8)==HIGH or digitalRead(7)==HIGH or digitalRead(6)==HIGH or digitalRead(5)==HIGH){
      return;
    }


  }
  
}
void change_room(uint32_t c, uint16_t wait, uint16_t room){
    strip.setPixelColor(2*room, c);
    strip.setPixelColor(2*room+1, c);
//    strip.setPixelColor(4*room+2, c);
//    strip.setPixelColor(4*room+3, c);
    strip.show();
    delay(wait);
}

void house(uint32_t c, uint16_t wait) {
  int i, j, k;
//  for(i=0; i<strip.numPixels(); i++){ 
//    strip.setPixelColor(i, strip.Color(0,   127,   0));
//  }
//  analogWrite(powerPin, 255);
  for(k=0; k<strip.numPixels()/4; k++){
    strip.setPixelColor(4*k, c);
    strip.setPixelColor(4*k+1, c);
    strip.setPixelColor(4*k+2, c);
    strip.setPixelColor(4*k+3, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint16_t wait) {
  int i, j;
   
  for (j=0; j < 384; j++) {     // 3 cycles of all 384 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel( (i + j) % 384));
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}
int rainbowLast(uint8_t wait) {
  uint16_t i, j;
  
  for (j=0; j < 384 * 5; j++) {     // 5 cycles of all 384 colors in the wheel
    for (i=27; i < 32; i++) {
      // tricky math! we use each pixel as a fraction of the full 384-color wheel
      // (thats the i / strip.numPixels() part)
      // Then add in j which makes the colors go around per pixel
      // the % 384 is to make the wheel cycle around
      strip.setPixelColor(2*i, Wheel( ((i * 384 / strip.numPixels()) + j) % 384) );
      strip.setPixelColor(2*i+1, Wheel( ((i * 384 / strip.numPixels()) + j) % 384) );
      if (digitalRead(4) == HIGH){
        return 0;
        
      }
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
  return 1;
}

// Slightly different, this one makes the rainbow wheel equally distributed 
// along the chain
int rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  
  for (j=0; j < 384 * 5; j++) {     // 5 cycles of all 384 colors in the wheel
    for (i=0; i < strip.numPixels()/2; i++) {
      // tricky math! we use each pixel as a fraction of the full 384-color wheel
      // (thats the i / strip.numPixels() part)
      // Then add in j which makes the colors go around per pixel
      // the % 384 is to make the wheel cycle around
      strip.setPixelColor(2*i, Wheel( ((i * 384 / strip.numPixels()) + j) % 384) );
      strip.setPixelColor(2*i+1, Wheel( ((i * 384 / strip.numPixels()) + j) % 384) );
      if (digitalRead(4) == HIGH){
        return 0;
        
      }
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
  return 1;
}

int casino(uint8_t wait) {
  int i = 0;
  while(digitalRead(13) == HIGH){
    i += 1;
    houseChase(Wheel(i*25), wait);
    if (i*25 >= 350){
      i=0;
    }
  }
//  while (i>=0){
//    houseChase(strip.Color(127,127,127), i*wait);
//    i -= 1;
//  }
  return i;
}
void animate_roll(uint8_t roll) {
  int final_roll = roll*2;
//  houseChase(strip.Color(0,127,0), 100);
//  houseChase(strip.Color(0,127,0), 100);
  int roll2 = roll % 4;
  while (roll2 < 6){
        if ((digitalRead(4) == HIGH) or (digitalRead(11)==HIGH) or (digitalRead(12)==HIGH) or (digitalRead(13) == HIGH)){
      return;
        }
    houseChase(strip.Color(127,127,127), 100 + 20*(roll2+1));
    roll2 += 1;
    roll2 += 1;
  }
  houseChase(strip.Color(127,127,127), 200 + 20*(roll2+1));
  blink_square(final_roll);
}

void blink_square(uint8_t square){
    int i;

  // Start by turning all pixels off:
//  for(i=0; i<strip.numPixels(); i++) strip.setPixelColor(i, 0);

  // Then display one pixel at a time:
  for(i=0; i<square; i++) {
    strip.setPixelColor(2*i, strip.Color(127,127,127));
    strip.setPixelColor(2*i+1, strip.Color(127,127,127)); // Set new pixel 'on'
    strip.show();              // Refresh LED states
    strip.setPixelColor(2*i, 0);
    strip.setPixelColor(2*i + 1, 0);// Erase pixel, but don't refresh!
    delay(800);
  }

  strip.show();
  
  while (digitalRead(4) == LOW) {
    strip.setPixelColor(2*square, strip.Color(127,127,127));
    strip.setPixelColor(2*square+1, strip.Color(127,127,127));
    strip.show();
    delay(100);
    strip.setPixelColor(2*square, strip.Color(0,0,0));
    strip.setPixelColor(2*square+1, strip.Color(0,0,0));
    strip.show();
    delay(100);
    
  }
}

// Fill the dots progressively along the strip.
void colorWipe(uint32_t c, uint8_t wait) {
  int i;

  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void houseChase(uint32_t c, uint16_t wait) {
  int i;

  // Start by turning all pixels off:
  for(i=0; i<strip.numPixels(); i++) strip.setPixelColor(i, 0);

  // Then display one pixel at a time:
  for(i=0; i<strip.numPixels()/2; i++) {
    if ((digitalRead(4) == HIGH) or (digitalRead(11)==HIGH) or (digitalRead(12)==HIGH)){
      return;
    }
    strip.setPixelColor(2*i, c);
    strip.setPixelColor(2*i+1, c); // Set new pixel 'on'
    strip.show();              // Refresh LED states
    strip.setPixelColor(2*i, 0);
    strip.setPixelColor(2*i + 1, 0);// Erase pixel, but don't refresh!
    delay(wait);
  }

  strip.show(); // Refresh to turn off last pixel
}


// Chase one dot down the full strip.
void colorChase(uint32_t c, uint8_t wait) {
  int i;

  // Start by turning all pixels off:
  for(i=0; i<strip.numPixels(); i++) strip.setPixelColor(i, 0);

  // Then display one pixel at a time:
  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c); // Set new pixel 'on'
    strip.show();              // Refresh LED states
    strip.setPixelColor(i, 0); // Erase pixel, but don't refresh!
    delay(wait);
  }

  strip.show(); // Refresh to turn off last pixel
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 384; j++) {     // cycle all 384 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 384));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}
/* Helper functions */

//Input a value 0 to 384 to get a color value.
//The colours are a transition r - g -b - back to r

uint32_t Wheel(uint16_t WheelPos)
{
  byte r, g, b;
  switch(WheelPos / 128)
  {
    case 0:
      r = 127 - WheelPos % 128;   //Red down
      g = WheelPos % 128;      // Green up
      b = 0;                  //blue off
      break; 
    case 1:
      g = 127 - WheelPos % 128;  //green down
      b = WheelPos % 128;      //blue up
      r = 0;                  //red off
      break; 
    case 2:
      b = 127 - WheelPos % 128;  //blue down 
      r = WheelPos % 128;      //red up
      g = 0;                  //green off
      break; 
  }
  return(strip.Color(r,g,b));
}
