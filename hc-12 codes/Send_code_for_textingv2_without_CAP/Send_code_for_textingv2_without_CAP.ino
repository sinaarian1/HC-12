

#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

const byte HC12RxdPin = 12;                  // Recieve Pin on HC12
const byte HC12TxdPin = 13;                  // Transmit Pin on HC12
SoftwareSerial HC12(HC12TxdPin,HC12RxdPin); // Create Software Serial Port

//chars for use
char chars[31] = "abcdefghijklmnopqrstuvwxyz,.?!";
// Pins for use and thier use
int pinup = 2;
int pindown = 3;
int pinleft = 4;
int pinright = 5;
int pinselect = 6;
int pinsend = 7;
int pinspace = 9;
int pinswitch = 10;
//the X Y Axies
int x = 0;
int y = 0;
//calling out message as a string
String message;
//ints to make the letters stand out
int a,b,c,d,e,f,g,h,I,j,k,l,m,n,o,p,q,r,s,t,u,v,w,X,Y,z,comma,period,question,exc,space,cap,snd;
//int for the switch button
int i = 1;


void setup() {
  Serial.begin(9600);                       
  HC12.begin(9600);  
  digitalWrite(pinup, HIGH);
  digitalWrite(pindown, HIGH);
  digitalWrite(pinleft, HIGH);
  digitalWrite(pinright, HIGH);
  digitalWrite(pinselect, HIGH);
  digitalWrite(pinsend, HIGH);
  digitalWrite(pinspace,HIGH);
  digitalWrite(pinswitch,HIGH);
  message = String("");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.display();
  display.clearDisplay(); 
}
void loop(){
  
//Button callout
 int buttonup = digitalRead(pinup);
 int buttondown = digitalRead(pindown);
 int buttonleft = digitalRead(pinleft);
 int buttonright = digitalRead(pinright);
 int buttonselect = digitalRead(pinselect);
 int buttonsend = digitalRead(pinsend);
 int buttonspace = digitalRead(pinspace);
/////////////////////////////////////////////////////////////////////////////////
//Char variables
 int charnum;
 int capchar = 0;
/////////////////////////////////////////////////////////////////////////////////
//The XY button controllers
 if(buttonup == LOW){
  y--;
   if(y < 0){
     y++;
    }
  //Serial.print("x=");
  //Serial.println(x);
  delay(300);
 }
  if(buttondown == LOW){
  y++;
  if(y > 4){
    y--;
  }
  //Serial.print("x=");
  //Serial.println(x);
  delay(300);
 }
  if(buttonright == LOW){
  x++;
  if(x > 5){
    x--;
  }
  //Serial.print("y=");
  //Serial.println(y);
  delay(300);
 }
  if(buttonleft == LOW){
  x--;
  if(x < 0){
    x++;
  }
  //Serial.print("y=");
  //Serial.println();
  delay(300);
 }
 
/////////////////////////////////////////////////////////////////////////////////
//All the configs for each char
 if((y == 0) && (x == 0)){
  charnum = 0;
  a = BLACK;
 }
 else{
  a = WHITE;
 }
  if((y == 0) && (x == 1)){
  charnum = 1;
  b = BLACK;
 }
 else{
  b = WHITE;
 }
  if((y == 0) && (x == 2)){
  charnum = 2;
  c = BLACK;
 }
 else{
  c = WHITE;
 }
  if((y == 0) && (x == 3)){
  charnum = 3;
  d = BLACK;
 }
 else{
  d = WHITE;
 }
  if((y == 0) && (x == 4)){
  charnum = 4;
  e = BLACK;
 }
 else{
  e = WHITE;
 }
  if((y == 0) && (x == 5)){
  charnum = 5;
  f = BLACK;
 }
 else{
  f = WHITE;
 }
  if((x == 0) && (y == 1)){
  charnum = 6;
  g = BLACK;
 }
 else{
  g = WHITE;
 }
  if((x == 1) && (y == 1)){
  charnum = 7;
  h = BLACK;
 }
 else{
  h = WHITE;
 }
  if((x == 2) && (y == 1)){
  charnum = 8;
  I = BLACK;
 }
 else{
  I = WHITE;
 }
  if((x == 3) && (y == 1)){
  charnum = 9;
  j = BLACK;
 }
 else{
  j = WHITE;
 }
  if((x == 4) && (y == 1)){
  charnum = 10;
  k = BLACK;
 }
 else{
  k = WHITE;
 }
  if((x == 5) && (y == 1)){
  charnum = 11;
  l = BLACK;
 }
 else{
  l = WHITE;
 }
  if((x == 0) && (y == 2)){
  charnum = 12;
  m = BLACK;
 }
 else{
  m = WHITE;
 }
  if((x == 1) && (y == 2)){
  charnum = 13;
  n = BLACK;
 }
 else{
  n = WHITE;
 }
  if((x == 2) && (y == 2)){
  charnum = 14;
  o = BLACK;
 }
 else{
  o = WHITE;
 }
  if((x == 3) && (y == 2)){
  charnum = 15;
  p = BLACK;
 }
 else{
  p = WHITE;
 }

  if((x == 4) && (y == 2)){
  charnum = 16;
  q = BLACK;
 }
 else{
  q = WHITE;
 }

  if((x == 5) && (y == 2)){
  charnum = 17;
  r = BLACK;
 }
 else{
  r = WHITE;
 }

  if((x == 0) && (y == 3)){
  charnum = 18;
  s = BLACK;
 }
 else{
  s = WHITE;
 }

  if((x == 1) && (y == 3)){
  charnum = 19;
  t = BLACK;
 }
 else{
  t = WHITE;
 }

  if((x == 2) && (y == 3)){
  charnum = 20;
  u = BLACK;
 }
 else{
  u = WHITE;
 }

  if((x == 3) && (y == 3)){
  charnum = 21;
  v = BLACK;
 }
 else{
  v = WHITE;
 }

  if((x == 4) && (y == 3)){
  charnum = 22;
  w = BLACK;
 }
 else{
  w = WHITE;
 }

  if((x == 5) && (y == 3)){
  charnum = 23;
  X = BLACK;
 }
 else{
  X = WHITE;
 }

  if((x == 0) && (y == 4)){
  charnum = 24;
  Y = BLACK;
 }
 else{
  Y = WHITE;
 }
  if((x == 1) && (y == 4)){
  charnum = 25;
  z = BLACK;
 }
 else{
  z = WHITE;
 }

  if((x == 2) && (y == 4)){
  charnum = 26;
  comma = BLACK;
 }
 else{
  comma = WHITE;
 }

  if((x == 3) && (y == 4)){
  charnum = 27;
  period = BLACK;
 }
 else{
  period = WHITE;
 }

  if((x == 4) && (y == 4)){
  charnum = 28;
  question = BLACK;
 }
 else{
  question = WHITE;
 }

  if((x == 5) && (y == 4)){
  charnum = 29;
  exc = BLACK;
 }
 else{
  exc = WHITE;
 }

/////////////////////////////////////////////////////////////////////////////////
//SPACE button callout
 if(buttonspace == LOW){
  message += '_';
  space = BLACK;
  delay(300);
 }
 else{
  space = WHITE;
 }

/////////////////////////////////////////////////////////////////////////////////
//Adding all the chars together to make a message
if(buttonselect == LOW){
    Serial.print("your message: ");
    Serial.print(message += chars[charnum]);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print(message);
    Serial.print(" ");
    Serial.print("x=");
    Serial.print(x);
    Serial.print("y=");
    Serial.println(y);
    delay(300);
  }
///////////////////////////////////////////////////////////////////////////////// 

/////////////////////////////////////////////////////////////////////////////////
//Final step in sending the message and reseting the message back to nothing(space)
  if(buttonsend == LOW){
    Serial.print("message sent: ");
    Serial.println(message);
    message = String("");
    snd = BLACK;
    delay(300);
  }
  else{
    snd = WHITE;
  }

  display.setTextSize(1);
  display.setTextColor(space,WHITE);
  display.setCursor(96,17);
  display.println("SPACE");
  display.setTextColor(snd,WHITE);
  display.setCursor(96,53);
  display.println("SEND");
  display.setTextColor(a,WHITE);
  display.setCursor(0,17);
  display.println("a");
  display.setTextColor(b,WHITE);
  display.setCursor(16,17);
  display.println("b");
  display.setTextColor(c,WHITE);
  display.setCursor(32,17);
  display.println("c");
  display.setTextColor(d,WHITE);
  display.setCursor(48,17);
  display.println("d");
  display.setTextColor(e,WHITE);
  display.setCursor(64,17);
  display.println("e");
  display.setTextColor(f,WHITE);
  display.setCursor(80,17);
  display.println("f");
  display.setTextColor(g,WHITE);
  display.setCursor(0,26);
  display.println("g");
  display.setTextColor(h,WHITE);
  display.setCursor(16,26);
  display.println("h");
  display.setTextColor(I,WHITE);
  display.setCursor(32,26);
  display.println("i");
  display.setTextColor(j,WHITE);
  display.setCursor(48,26);
  display.println("j");
  display.setTextColor(k,WHITE);
  display.setCursor(64,26);
  display.println("k");
  display.setTextColor(l,WHITE);
  display.setCursor(80,26);
  display.println("l");
  display.setTextColor(m,WHITE);
  display.setCursor(0,35);
  display.println("m");
  display.setTextColor(n,WHITE);
  display.setCursor(16,35);
  display.println("n");
  display.setTextColor(o,WHITE);
  display.setCursor(32,35);
  display.println("o");
  display.setTextColor(p,WHITE);
  display.setCursor(48,35);
  display.println("p");
  display.setTextColor(q,WHITE);
  display.setCursor(64,35);
  display.println("q");
  display.setTextColor(r,WHITE);
  display.setCursor(80,35);
  display.println("r");
  display.setTextColor(s,WHITE);
  display.setCursor(0,44);
  display.println("s");
  display.setTextColor(t,WHITE);
  display.setCursor(16,44);
  display.println("t");
  display.setTextColor(u,WHITE);
  display.setCursor(32,44);
  display.println("u");
  display.setTextColor(v,WHITE);
  display.setCursor(48,44);
  display.println("v");
  display.setTextColor(w,WHITE);
  display.setCursor(64,44);
  display.println("w");
  display.setTextColor(X,WHITE);
  display.setCursor(80,44);
  display.println("x");
  display.setTextColor(Y,WHITE);
  display.setCursor(0,53);
  display.println("y");
  display.setTextColor(z,WHITE);
  display.setCursor(16,53);
  display.println("z");
  display.setTextColor(comma,WHITE);
  display.setCursor(32,53);
  display.println(",");
  display.setTextColor(period,WHITE);
  display.setCursor(48,53);
  display.println(".");
  display.setTextColor(question,WHITE);
  display.setCursor(64,53);
  display.println("?");
  display.setTextColor(exc,WHITE);
  display.setCursor(80,53);
  display.println("!");
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(message);
  display.display();
  display.clearDisplay();
  
  delay(10);
 
}
 




