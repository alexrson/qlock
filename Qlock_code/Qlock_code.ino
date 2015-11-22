/*
Euge and Arob code for Qlock


*/


// Pin definitions:
// The 74HC595 uses a type of serial connection called SPI
// (Serial Peripheral Interface) that requires three pins:

int global_led_index = 0;

//register 1: small board
int datapin1 = 2; 
int clockpin1 = 3;
int latchpin1 = 4 ;

//register 2: bottom of big board
int datapin2 = 5; 
int clockpin2 = 6;
int latchpin2 = 7;

//register 3: top of big board
int datapin3 = 8; 
int clockpin3 = 9;
int latchpin3 = 10;

// We'll also declare a global variable for the data we're
// sending to the shift register:

byte data1 = 0;
byte data2 = 0;
byte data3 = 0;


void setup()
{
  // Set the three SPI pins to be outputs:

  pinMode(datapin1, OUTPUT);
  pinMode(clockpin1, OUTPUT);  
  pinMode(latchpin1, OUTPUT);
  pinMode(datapin2, OUTPUT);
  pinMode(clockpin2, OUTPUT);  
  pinMode(latchpin2, OUTPUT);
  pinMode(datapin3, OUTPUT);
  pinMode(clockpin3, OUTPUT);  
  pinMode(latchpin3, OUTPUT);
}


void loop()
{

  //binaryCount();
  allOn();
}


void binaryCount()
{
  int delayTime = 20; // time (milliseconds) to pause between LEDs
                        // make this smaller for faster switching
  
  // Send the data byte to the shift register:

  shiftOut(datapin1, clockpin1, MSBFIRST, data1);
  shiftOut(datapin2, clockpin2, MSBFIRST, data2);
  shiftOut(datapin3, clockpin3, MSBFIRST, data3);

  // Toggle the latch pin to make the data appear at the outputs:

  digitalWrite(latchpin1, HIGH);
  digitalWrite(latchpin1, LOW);
  digitalWrite(latchpin2, HIGH);
  digitalWrite(latchpin2, LOW);
  digitalWrite(latchpin3, HIGH);
  digitalWrite(latchpin3, LOW);
  
  // Add one to data, and repeat!
  // (Because a byte type can only store numbers from 0 to 255,
  // if we add more than that, it will "roll around" back to 0
  // and start over).

  data3++;
  data2 = data3;
  data1 = data3;

  // Delay so you can see what's going on:

  delay(delayTime);
}

void allOn()
{
  
  // Send the data byte to the shift register:
  data1 = 255;
  data2 = 255;
  data3 = 255;

  shiftOut(datapin1, clockpin1, MSBFIRST, data1);
  shiftOut(datapin2, clockpin2, MSBFIRST, data2);
  shiftOut(datapin3, clockpin3, MSBFIRST, data3);

  // Toggle the latch pin to make the data appear at the outputs:

  digitalWrite(latchpin1, HIGH);
  digitalWrite(latchpin1, LOW);
  digitalWrite(latchpin2, HIGH);
  digitalWrite(latchpin2, LOW);
  digitalWrite(latchpin3, HIGH);
  digitalWrite(latchpin3, LOW);
  
  delay(500);
  clearAll();
  turnOnWord(global_led_index++);
  global_led_index++;
  delay(500);
}


void clearAll()
{
  data1 = 0;
  data2 = 0;
  data3 = 0;

  shiftOut(datapin1, clockpin1, MSBFIRST, data1);
  shiftOut(datapin2, clockpin2, MSBFIRST, data2);
  shiftOut(datapin3, clockpin3, MSBFIRST, data3);

  // Toggle the latch pin to make the data appear at the outputs:

  digitalWrite(latchpin1, HIGH);
  digitalWrite(latchpin1, LOW);
  digitalWrite(latchpin2, HIGH);
  digitalWrite(latchpin2, LOW);
  digitalWrite(latchpin3, HIGH);
  digitalWrite(latchpin3, LOW);
}
/*
it_is   0
ten_1   1
half    2
quarter 3
twenty  4
five    5
minutes 6
past    7
to  8
one 9
two 10
three   11
four    12
five    13
six 14
seven   15
eight   16
nine    17
ten_2   18
eleven  19
twelve  20
o clock 21
onemin  22
twomin  23
threemin    24
fourmin 25
*/
void setTime(int hour, int minutes)
{
  // asdf
  data1 = 0;
  data2 = 0;
  data3 = 0;
  int it_is = 0;
  int ten_1 = 1;
  int half =  2;
  int quarter = 3;
  int twenty =4;
  int five =  5;
  int minutes =6;
  int past =  7;
  int to =8;
  int one 9;
  int two 10;
  int three = 11;
  int four =  12;
  int five =  13;
  int six = 14;
  int seven = 15;
  int eight = 16;
  int nine =  17;
  int ten_2 = 18;
  int eleven =19;
  int twelve =20;
  int o_clock = 21;
  int onemin =22;
  int twomin =23;
  int threemin =  24;
  int fourmin = 25;
  turnOnWord(it_is);
  turnOnWord(o_clock);
  // what hour should we display?
  int stated_hour = 0;
  if (minutes < 35){
    stated_hour = hour % 12;
  }
  else {
      stated_hour = (hour + 1) % 12;
  }
  // Display hour
  if (stated_hour == 0) {
    turnOnWord(twelve);
  }
  else if (stated_hour == 1) {
    turnOnWord(one);
  }
  else if (stated_hour == 2) {
    turnOnWord(two);
  }
  else if (stated_hour == 3) {
    turnOnWord(three);
  }
  else if (stated_hour == 4) {
    turnOnWord(four);
  }
  else if (stated_hour == 5) {
    turnOnWord(five);
  }
  else if (stated_hour == 6) {
    turnOnWord(six);
  }
  else if (stated_hour == 7) {
    turnOnWord(seven);
  }
  else if (stated_hour == 8) {
    turnOnWord(eight);
  }
  else if (stated_hour == 9) {
    turnOnWord(nine);
  }
  else if (stated_hour == 10) {
    turnOnWord(ten_2);
  }
  else if (stated_hour == 11) {
    turnOnWord(eleven);
  }

  // Turn on minutes
  int closest_five = minutes - (minutes % 5);
    if (closest_five == 0)
    {
      // say noth
    }
    else if (closest_five == 5){
      turnOnWord(five);
      turnOnWord(minutes);
      turnOnWord(past);
    }
    else if (closest_five == 10){
       turnOnWord(ten_1);
       turnOnWord(minutes);
       turnOnWord(past);
    }
    else if (closest_five == 15){
       turnOnWord(quarter);
       turnOnWord(past);
    }
    else if (closest_five == 20){
       turnOnWord(twenty);
       // turnOnWord(minutes);// decide
       turnOnWord(past); 
    }
    else if (closest_five == 25){
       turnOnWord(twenty);
       turnOnWord(five);
       turnOnWord(minutes);
       turnOnWord(past);
    }
    else if (closest_five == 30){
       turnOnWord(half);
       turnOnWord(past);
       turnOnWord();

    }
    else if (closest_five == 35){
       turnOnWord(twenty);
       turnOnWord(five);
       turnOnWord(minutes);
       turnOnWord(to);

    }
    else if (closest_five == 40){
       turnOnWord(twenty);
       turnOnWord(minutes);
       turnOnWord(to);

    }
    else if (closest_five == 45){
       turnOnWord(quarter);
       turnOnWord(to);
    }
    else if (closest_five == 50){
       turnOnWord(ten_1);
       turnOnWord(minutes);
       turnOnWord(to);
    }
    else if (closest_five == 55){
       turnOnWord(five);
       turnOnWord(minutes);
       turnOnWord(to);
    }

}


void turnOnWord(int word_index)
{
   int led_index = word_index % 8;
   int register_index = word_index / 8;
   if (register_index == 0)
   {
      bitWrite(data1,led_index,HIGH);
      shiftOut(datapin1, clockpin1, MSBFIRST, data1);
      digitalWrite(latchpin1, HIGH);
      digitalWrite(latchpin1, LOW);
   }
   if (register_index == 1)
   {
      bitWrite(data2,led_index,HIGH);
      shiftOut(datapin2, clockpin2, MSBFIRST, data2);
      digitalWrite(latchpin2, HIGH);
      digitalWrite(latchpin2, LOW);
   }
   if (register_index == 2)
   {
      bitWrite(data3,led_index,HIGH);
      shiftOut(datapin3, clockpin3, MSBFIRST, data3);
      digitalWrite(latchpin3, HIGH);
      digitalWrite(latchpin3, LOW);
   }
}

