
int onemin = 51;
int threemin = 26; 
int fourmin = 29;
int twomin = 52;
int ten_m = 23;
int twelve_1 = 24;
int twelve_2 = 22;
int unmapped = 25;
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


unsigned long last_millis = 0;
unsigned long starting_total_min;

void setup() {
  allMode();
  char *compile_time_h, *compile_time_m, *i;
  char *record = __TIME__;
  compile_time_h = strtok_r(record,":",&i);
  compile_time_m = strtok_r(NULL,":",&i);
  String s;
  s = String(compile_time_h);
  int sh = s.toInt() % 12;
  s = String(compile_time_m);
  int sm = s.toInt();
  // Here is where to hack in a specific time for bug testing
  //sh = 12;
  //sm = 20;
  starting_total_min = 60 * sh + sm;
  Serial.begin(9600);
  Serial.println("sh");
  Serial.println(sh);
  Serial.println("sm");
  Serial.println(sm);
  Serial.println("starting_total_min");
  Serial.println(starting_total_min);
  Serial.println("\n");
  
}

void loop(){
  unsigned long millis_now = millis();
  unsigned long seconds_elapsed = millis_now / 1000 ;  
  unsigned long min_elapsed = seconds_elapsed / 60.0;
  unsigned long now_total_min = (min_elapsed + starting_total_min) % 1440;
  int h = now_total_min / 60;
  int m = now_total_min % 60;
  Serial.println(millis_now);
  Serial.println(last_millis);
  Serial.println(h);
  Serial.println(m);
  Serial.println("\n");
  displayTime(h, m);
  if (last_millis >= millis_now && millis_now != 0)
  {
    Serial.println("FAIL");
    while(1) { };
  }
  int loop_delay = 10 * 30;
  int loop_elapsed = millis_now - last_millis;
  int loop_elapsed_deviation = loop_elapsed - loop_delay;
  if (abs(loop_elapsed_deviation) > 5  && last_millis != 0) {
    Serial.println(loop_elapsed);
    Serial.println("Bad loop elapsed deviation");
    while(1) { };
  }
  last_millis = millis_now;
  delay(loop_delay); 
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
