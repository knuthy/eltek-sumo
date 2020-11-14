// Pins
int left_IR_pin = A5;
int right_IR_pin = A4;

// Black values
int left_IR_black_value = 930;
int right_IR_black_value = 910;

// Functions
void start_reversing();
void stop_driving();
void start_driving();
void start_turning_right();
void start_turning_left();

void on_line() {
  
  int left_value = analogRead(left_IR_pin);
  int right_value = analogRead(right_IR_pin);

  if(left_value > left_IR_black_value && right_value > right_IR_black_value) {
    start_reversing();
    delay(300);
    stop_driving();
    delay(400);
    start_turning_left();
    delay(1000);
  } else if(left_value > left_IR_black_value) {
    start_reversing();
    delay(300);
    stop_driving();
    delay(400);
    start_turning_right();
    delay(1000);
  } else if(right_value > right_IR_black_value) {
    start_reversing();
    delay(300);
    stop_driving();
    delay(400);
    start_turning_left();
    delay(1000);
  } else {
    // None
    //start_driving();
  }
}
