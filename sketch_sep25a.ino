
/*In this program we are reading the analog value from analog pin A0 and display 
LM35 Connection:
Pin 1 : Vcc/+5V
Pin 2 : Arduino Analog Pin A0
Pin 3 : GND

####### LCD Connection with Arduino #######
LCD Pin
1(Vss) => GND
2(Vdd) => +5V
3(Vee) => Center Pin of 20K Preset or GND
4(RS) => digital pin 8
5(RW) => GND
6(E) => digital pin 9
7(D0) => NC(not connected)
8(D1) => NC
9(D2) => NC
10(D3) => NC
11(D4) => digital pin 10
12(D5) => digital pin 11
13(D6) => digital pin 12
14(D7) => digital pin 13
15(A) => +5V
16(K) => GND */
// include the LCD library
#include<LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
const int buzzer = 6; //buzzer to arduino pin 6
void setup() {
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
int ADCvalue = 0;
pinMode(buzzer, OUTPUT); // Set buzzer - pin 6 as an output
}
void loop() {
// Read the analog value from pin A0
int ADCvalue = analogRead(A0);
ADCvalue = ADCvalue/2;
lcd.setCursor(0, 0); // top left
// print the value at LCD
lcd.print("Temperatura=");
lcd.print(ADCvalue);
lcd.print(" ");
lcd.setCursor(3, 1);
lcd.print("Alarma < 2");
delay(500); // delay in between reads for stability
if(ADCvalue<2 ){
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);        // ...for 1sec
}	
}
