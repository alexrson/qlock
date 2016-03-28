int onemin = 51;
int threemin = 22;
int fourmin = 29;
int twomin = 52;
int ten_m = 23;
int twelve_1 = 24;
int twelve_2 = 25;
int unmapped = 26;
int unmapped_2 = 27;
int nine = 28;
int unmapped_3 = 29;
int eleven_1 = 30;
int ten_h = 31;
int six = 32;
int eleven_2 = 33;
int seven = 34;
int eight = 35;
int four = 36;
int three = 37;
int five_h = 38;
int past = 39;
int one_h = 40;
int to = 41;
int five_m = 42;
int two_h = 43;
int minutes_2 = 44;
int minutes_1 = 45;
int twenty_1 = 46;
int quarter_1 = 47;
int twenty_2 = 48; // bad solder job?
int quarter_2 = 49;
int unmapped_4 = 50;
int half = 53;

//start time
int hour = 8;
int min = 59;

void setup() {
  allMode();
  //int word = 29;
  //digitalWrite(word, HIGH);
  //displayTime(0, 55);
}

void loop(){
  displayTime(hour, min);
  delay(1000 * 60);
  min++;
  if (min == 60) {
    min = 0;
    hour++;
    hour = hour % 12;
  }
  displayTime(hour, min);
}

void allMode()
{
  int word = 22;
  for (word = 22; word <= 53; word++)
  {
    pinMode(word, OUTPUT);
  }
}
void allOn()
{
  int word = 0;
  for (word = 22; word <= 53; word++)
  {
    
    digitalWrite(word, HIGH);
    delay(500);
    digitalWrite(word, LOW);
  }
}

void clearAll()
{
  int word = 0;
  for (word = 22 ; word <= 53; word++)
  {
    digitalWrite(word, LOW);
  }
}

void turnOnPin(int ind)
{
    digitalWrite(ind, HIGH);
}
void turnOnWord(int ind)
{
    digitalWrite(ind, HIGH);
}

void displayTime(int hour_time, int minute_time)
{
  // displays the time
  clearAll();
  //turnOnWord(it_is);
  //turnOnWord(o_clock);
  // what hour should we display?
  int stated_hour = 0;
  if (minute_time < 35) {
    stated_hour = hour_time % 12;
  }
  else {
    stated_hour = (hour_time + 1) % 12;
  }
  // Display hour
  if (stated_hour == 0) {
    turnOnWord(twelve_1);
    turnOnWord(twelve_2);
  }
  else if (stated_hour == 1) {
    turnOnWord(one_h);
  }
  else if (stated_hour == 2) {
    turnOnWord(two_h);
  }
  else if (stated_hour == 3) {
    turnOnWord(three);
  }
  else if (stated_hour == 4) {
    turnOnWord(four);
  }
  else if (stated_hour == 5) {
    turnOnWord(five_h);
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
    turnOnWord(ten_h);
  }
  else if (stated_hour == 11) {
    turnOnWord(eleven_1);
    turnOnWord(eleven_2);
  }

  // Turn on minutes
  int closest_five = minute_time - (minute_time % 5);
  if (closest_five == 0)
  {
    // say noth
  }
  else if (closest_five == 5) {
    turnOnWord(five_m);
    turnOnWord(minutes_1);
    turnOnWord(minutes_2);
    turnOnWord(past);
  }
  else if (closest_five == 10) {
    turnOnWord(ten_m);
    turnOnWord(minutes_1);
    turnOnWord(minutes_2);
    turnOnWord(past);
  }
  else if (closest_five == 15) {
    turnOnWord(quarter_1);
    turnOnWord(quarter_2);
    turnOnWord(past);
  }
  else if (closest_five == 20) {
    turnOnWord(twenty_1);
    turnOnWord(twenty_2);
    // turnOnWord(minutes);// decide
    turnOnWord(past);
  }
  else if (closest_five == 25) {
    turnOnWord(twenty_1);
    turnOnWord(twenty_2);
    turnOnWord(five_m);
    turnOnWord(minutes_1);
    turnOnWord(minutes_2);
    turnOnWord(past);
  }
  else if (closest_five == 30) {
    turnOnWord(half);
    turnOnWord(past);


  }
  else if (closest_five == 35) {
    turnOnWord(twenty_1);
    turnOnWord(twenty_2);
    turnOnWord(five_m);
    turnOnWord(minutes_1);
    turnOnWord(minutes_2);
    turnOnWord(to);

  }
  else if (closest_five == 40) {
    turnOnWord(twenty_1);
    turnOnWord(twenty_2);
    turnOnWord(minutes_1);
    turnOnWord(minutes_2);
    turnOnWord(to);

  }
  else if (closest_five == 45) {
    turnOnWord(quarter_1);
    turnOnWord(quarter_2);
    turnOnWord(to);
  }
  else if (closest_five == 50) {
    turnOnWord(ten_m);
    turnOnWord(minutes_1);
    turnOnWord(minutes_2);
    turnOnWord(to);
  }
  else if (closest_five == 55) {
    turnOnWord(five_m);
    turnOnWord(minutes_1);
    turnOnWord(minutes_2);
    turnOnWord(to);
  }
  // turn on single leds
  int remainder = minute_time %5;
  if (remainder >= 1) {
    turnOnWord(onemin);
   }
    if (remainder >= 2) {
    turnOnWord(twomin);
   }
    if (remainder >= 3) {
    turnOnWord(threemin);
   }
    if (remainder >= 4) {
    turnOnWord(fourmin);
   }
  }
  

