
const int pin  = A0; //pin number
const int numReadings  = 10; //total number of readings we can take
int readings [numReadings]; //array of readings
int count  = 0;//counters
long total  = 0;//total to calculate avarage
int val  = 0;//to store the value

void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

void loop() {
  val = analogRead(pin);
  //calling the function
  display_avg();
  //printing the avarage
  Serial.print(F("avg : ")); Serial.println(moving_avarage());
  delay(500);
  //checking if it is moving up or down
  if( val> moving_avarage()){Serial.print(F("it is moving up"));}
  else if( val< moving_avarage()){Serial.print(F("it is moving down"));}
}

void display_avg( ) {
  val = analogRead(pin);
  Serial.print(F("val ")); Serial.println(val);
}
// in this i have pulled the recent value replaed the oldest value with the newest value and calculate the avarage of it.
long moving_avarage() {
  long average;
  //removing the old value
  total = total - readings[count];
  //getting the new one
  readings[count] = analogRead(pin);
  //adding the new one to the total
  total = total + readings[count];
  //increasing the counter to know which value in the array we are on
  count = count + 1;
  // this logic is to take care the index out of range error and putting new values by removing the oldest one
  if (count >= numReadings) {
    count = 0;
  }
  //calculating the avarage
  average = total / numReadings;

  return average;
}

