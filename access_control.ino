#include <Key.h>
#include <Keypad.h>

#include <LiquidCrystal_I2C.h>



//4x3 matrix keypad
const byte ROWS = 4;
const byte COLS = 3;

//set counter, val, and ID
int count = 0;
char val[5];
char* ID="7317";


//Define keypad keys
char keys[ROWS][COLS]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
byte rowPins[ROWS]={9,8,7,6};
byte colPins[COLS]={5,4,3};

//Define LEDs and delaytime
const int ledREDPin= 13;
const int ledGREENPin =12;
const int delayTime = 3000;


//Create Keypad and LCD Objects
Keypad kdp= Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
LiquidCrystal_I2C lcd(0x20,16,2);

void setup() {
//  initialize LCD 
lcd.init();
lcd.backlight();
lcd.home();
  
//set LED pins modes
pinMode(ledREDPin,OUTPUT);
pinMode(ledGREENPin,OUTPUT);
}
 
void loop() {
  char key = kdp.getKey();
  if(key){
    if(count<4){
      val[count]=key;
      count++;
      lcd.print(key);
    }

    if(count == 4){
      lcd.clear();
      if(strcmp(val,ID)==0){
        digitalWrite(ledGREENPin,HIGH);
      }else{
        digitalWrite(ledREDPin,HIGH);
      }

      delay(delayTime);
      digitalWrite(ledGREENPin,LOW);
      digitalWrite(ledREDPin,LOW);

      count = 0;
      val[0] = '\0';
    }
  }
  
}
