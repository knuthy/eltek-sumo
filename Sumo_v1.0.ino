// Libraries
#include <TimedAction.h>

// Functions for use in Timed Actions
void on_line();
void scan_ultra();
void start_driving();
void stop_driving();

// Timed Actions
TimedAction IR = TimedAction(200, on_line);
TimedAction ULTRA = TimedAction(200, scan_ultra);
//TimedAction DriveChange = TimedAction();

bool started = false;

void setup() {

  // Setups
  setup_motors();
  setup_ultra();
  
  Serial.begin(9600);

}

void loop() {

  if(!started) {
    delay(3000);
    start_driving();
    delay(500);
    stop_driving();
    started = true;
  }

  IR.check();
  ULTRA.check();
}
