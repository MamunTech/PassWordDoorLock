
#include <Keypad.h>

//constants for LEDs
int greenLED = 12;
int redLED = 13;

//set our code
char* ourCode = "1234";
int currentPosition = 0;

//define the keypad
const byte rows = 4;
const byte cols = 4;

char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[rows] = {11,10,9,8};
byte colPins[cols] = {7,6,5,4};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);



void setup()
{
 
  //setup and turn off both LEDs
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  
}

void loop()
{
  int l;
  
  char key = keypad.getKey();
  
  if (int(key) != 0) {
    
    
    for (l=0; l<=currentPosition; ++l)
    {
      //lcd.print("*");
    }
    
    if (key == ourCode[currentPosition])
      {
        ++currentPosition;
        if (currentPosition == 4)
        {
          unlockDoor();
          currentPosition = 0;
        }
      } else {
        invalidCode();
        currentPosition = 0;
      }
    
    
  }
}

void invalidCode()
{
  digitalWrite(redLED, HIGH);
  
  delay(5000);
  digitalWrite(redLED, LOW);
 
}

void unlockDoor()
{
  digitalWrite(greenLED, HIGH);
 
  
  //add any code to unlock the door here
  delay(5000);
  digitalWrite(greenLED, LOW);
 
}



