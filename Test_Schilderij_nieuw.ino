#define button_pin 9
#define red 3
#define yellow 4
#define green 5
#define blue 6
#define white 7
#define relais 13

// variables will change:
int button_press_count = 0;
int button_state = 0;
int prev_button_state = 0;



void setup() {
  // put your setup code here, to run once:
  delay(100);
  Serial.begin(9600);
  pinMode (button_pin, INPUT_PULLUP); //Set digi pin 7 as pull up button
  pinMode (red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(relais, OUTPUT);  

  Serial.println("Button Count:");
}

void loop() {
  // put your main code here, to run repeatedly:
  button_state = digitalRead(button_pin);
  if (button_state != prev_button_state) {
    if (button_state == HIGH) {
//      digitalWrite(red, LOW);
    } else { //button press
//      digitalWrite(red, HIGH);
      button_press_count++;
      Serial.println(button_press_count); //print the count
    }
    delay(50);
  }
  prev_button_state = button_state;

if (button_press_count >= 1) {
      digitalWrite(red, HIGH);
    } else { //button press
      digitalWrite(red, LOW);
   delay(20);
  
}

if (button_press_count >= 2) {
      digitalWrite(yellow, HIGH);
    } else { //button press
      digitalWrite(yellow, LOW);
   delay(20);
}

  if (button_press_count >= 3) {
      digitalWrite(green, HIGH);
    } else { //button press
      digitalWrite(green, LOW);
   delay(20);
}

if (button_press_count >= 4) {
      digitalWrite(blue, HIGH);
    } else { //button press
      digitalWrite(blue, LOW);
   delay(20);
}

  if (button_press_count >= 5) {
      digitalWrite(white, HIGH);
      digitalWrite(relais, HIGH);
    } else { //button press
      digitalWrite(white, LOW);
      digitalWrite(relais, LOW);
   delay(20);
}


}
