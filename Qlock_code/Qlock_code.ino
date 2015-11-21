/*
Euge and Arob code for Qlock


*/


// Pin definitions:
// The 74HC595 uses a type of serial connection called SPI
// (Serial Peripheral Interface) that requires three pins:

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


void shiftWrite(int desiredPin, boolean desiredState)
// This function lets you make the shift register outputs
// HIGH or LOW in exactly the same way that you use digitalWrite().

// Like digitalWrite(), this function takes two parameters:

//    "desiredPin" is the shift register output pin
//    you want to affect (0-7)

//    "desiredState" is whether you want that output
//    to be HIGH or LOW

// Inside the Arduino, numbers are stored as arrays of "bits",
// each of which is a single 1 or 0 value. Because a "byte" type
// is also eight bits, we'll use a byte (which we named "data"
// at the top of this sketch) to send data to the shift register.
// If a bit in the byte is "1", the output will be HIGH. If the bit
// is "0", the output will be LOW.

// To turn the individual bits in "data" on and off, we'll use
// a new Arduino commands called bitWrite(), which can make
// individual bits in a number 1 or 0.
{
  // First we'll alter the global variable "data", changing the
  // desired bit to 1 or 0:

  bitWrite(data1, desiredPin, desiredState);
  
  // Now we'll actually send that data to the shift register.
  // The shiftOut() function does all the hard work of
  // manipulating the data and clock pins to move the data
  // into the shift register:

  shiftOut(datapin1, clockpin1, MSBFIRST, data1);

  // Once the data is in the shift register, we still need to
  // make it appear at the outputs. We'll toggle the state of
  // the latchPin, which will signal the shift register to "latch"
  // the data to the outputs. (Latch activates on the high-to
  // -low transition).

  digitalWrite(latchpin1, HIGH);
  digitalWrite(latchpin1, LOW);
}


/*
binaryCount()

Numbers are stored internally in the Arduino as arrays of "bits",
each of which is a 1 or 0. Just like the base-10 numbers we use
every day, The position of the bit affects the magnitude of its 
contribution to the total number:

Bit position   Contribution
0              1
1              2
2              4
3              8
4              16
5              32
6              64
7              128

To build any number from 0 to 255 from the above 8 bits, just
select the contributions you need to make. The bits will then be
1 if you use that contribution, and 0 if you don't.

This function will increment the "data" variable from 0 to 255
and repeat. When we send this value to the shift register and LEDs,
you can see the on-off pattern of the eight bits that make up the
byte. See http://www.arduino.cc/playground/Code/BitMath for more
information on binary numbers.
*/

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
  
  // Add one to data, and repeat!
  // (Because a byte type can only store numbers from 0 to 255,
  // if we add more than that, it will "roll around" back to 0
  // and start over).
  delay(1000000000);

}
