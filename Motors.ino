// Pins
// Motor H
const int OA2 = 3;
const int OB2 = 9;

// Motor V
const int OA1 = 10;
const int OB1 = 11;

// Speeds
int driving_speed = 100;
int reverse_speed = 250;
int turn_speed = 125;

void setup_motors() {
  //Motor H
  pinMode (OA2, OUTPUT);
  pinMode (OB2, OUTPUT);

  //Motor V
  pinMode (OA1, OUTPUT);
  pinMode (OB1, OUTPUT);
}

void start_driving() {
  // Motor H
  analogWrite (OA2, driving_speed);
  analogWrite (OB2, 0);
    
  // Motor V
  analogWrite (OA1, driving_speed);
  analogWrite (OB1, 0);
}

void start_attack() {
  // Motor H
  analogWrite (OA2, 200);
  analogWrite (OB2, 0);
    
  // Motor V
  analogWrite (OA1, 200);
  analogWrite (OB1, 0);
}

void stop_driving() {
  // Motor H
  analogWrite (OA2, 0);
  analogWrite (OB2, 0);
    
  // Motor V
  analogWrite (OA1, 0);
  analogWrite (OB1, 0);
}


void start_reversing() {
  // Motor H
  analogWrite (OA2, 0);
  analogWrite (OB2, reverse_speed);
    
  // Motor V
  analogWrite (OA1, 0);
  analogWrite (OB1, reverse_speed);
}

void start_turning_left() {
  // Motor H
  analogWrite (OA2, turn_speed);
  analogWrite (OB2, 0);
    
  // Motor V
  analogWrite (OA1, 0);
  analogWrite (OB1, 0);
}

void start_turning_left_scan() {
  // Motor H
  analogWrite (OA2, 75);
  analogWrite (OB2, 0);
    
  // Motor V
  analogWrite (OA1, 0);
  analogWrite (OB1, 0);
}

void start_turning_right_scan() {
  // Motor H
  analogWrite (OA2, 0);
  analogWrite (OB2, 0);
    
  // Motor V
  analogWrite (OA1, 75);
  analogWrite (OB1, 0);
}

void start_turning_right() {
  // Motor H
  analogWrite (OA2, 0);
  analogWrite (OB2, 0);
    
  // Motor V
  analogWrite (OA1, turn_speed);
  analogWrite (OB1, 0);
}
