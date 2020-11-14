#include <Ultrasonic.h>

int left_trig_pin = 5;
int left_echo_pin = 4;

int right_trig_pin = 12;
int right_echo_pin = 13;

Ultrasonic left_ultrasonic(left_trig_pin, left_echo_pin);
Ultrasonic right_ultrasonic(right_trig_pin, right_echo_pin);

int min_distance = 60;

bool attack = false;

// Functions
void start_reversing();
void stop_driving();
void start_driving();
void start_turning_right();
void start_turning_left();

void setup_ultra() {
  pinMode(left_trig_pin, OUTPUT);
  pinMode(right_trig_pin, OUTPUT);
  pinMode(left_echo_pin, INPUT);
  pinMode(right_echo_pin, INPUT);
}

void scan_ultra() {
  int left_distance = left_ultrasonic.read();
  int right_distance = right_ultrasonic.read();

  if(left_distance < min_distance || right_distance < min_distance) {

    stop_driving();
    delay(100);

    if(!attack) {
      if(left_distance < 50 && right_distance > 50) {
        // LEFT
        attack = true;
        start_turning_left_scan();
        delay(200);
        start_driving();
        delay(600);
        stop_driving();
        attack = false;
      } else if(right_distance < 50 && left_distance > 50) {
        // RIGHT
        attack = true;
        start_turning_right_scan();
        delay(200);
        start_driving();
        delay(600);
        stop_driving();
        attack = false;
      }
    }
    

    /*
    if((left_distance - right_distance < 20 && left_distance - right_distance > 0) || (right_distance - left_distance < 20 && right_distance - left_distance > 0)) {
      start_driving();
    } else if(left_distance < 50 && right_distance > 50) {
      // LEFT
      start_turning_left_scan();
    } else if(right_distance < 50 && left_distance > 50) {
      // RIGHT
      start_turning_right_scan();
    }
    */
    
  } else {
    start_turning_left_scan();
  }
}
