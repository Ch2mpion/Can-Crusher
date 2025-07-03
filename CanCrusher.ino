// Pin assignments
const int IR_SENSOR1_PIN = 6;     
const int IR_SENSOR2_PIN = 7;     
const int MOTOR_PIN      = 5;    
const int BUZZER_PIN     = 12;    

// Timing constants (in milliseconds)
const unsigned long SENSOR_HOLD_TIME = 5000;  // 5 seconds hold before motor state changes
const int PISTON_DOWN_DELAY = 2000;           // wait 2 seconds for can drop & piston reset
const int BUZZER_BEEP_TIME  = 100;            // Buzzer ON time for beeps
const int BUZZER_PAUSE_TIME = 100;            // Buzzer OFF time between beeps
const int LOOP_PAUSE        = 50;             // Small debounce pause

// State tracking variables
bool motorOn = false;
unsigned long sensorOnStart = 0;
unsigned long sensorOffStart = 0;
bool timingOn = false;
bool timingOff = false;

void setup() {
  pinMode(IR_SENSOR1_PIN, INPUT);
  pinMode(IR_SENSOR2_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Ensure motor and buzzer are off at startup
  digitalWrite(MOTOR_PIN, HIGH);
  digitalWrite(BUZZER_PIN, LOW);
  
  Serial.begin(9600);
  Serial.println("Can Crusher System Started");
}

void beepMultipleTimes(int times, int onTime, int offTime) {
  for (int i = 0; i < times; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(onTime);
    digitalWrite(BUZZER_PIN, LOW);
    if (i < times - 1) {  // Don't delay after the last beep
      delay(offTime);
    }
  }
}

void loop() {
  // Read both IR sensors
  bool sensor1 = digitalRead(IR_SENSOR1_PIN) == LOW;
  bool sensor2 = digitalRead(IR_SENSOR2_PIN) == LOW;
  bool bothDetected = sensor1 && sensor2;

  // Print sensor status to serial monitor
  Serial.print("Sensor 1: ");
  Serial.print(sensor1 ? "DETECTED" : "NOT DETECTED");
  Serial.print(" | Sensor 2: ");
  Serial.print(sensor2 ? "DETECTED" : "NOT DETECTED");
  Serial.print(" | Motor: ");
  Serial.println(motorOn ? "ON" : "OFF");

  unsigned long currentMillis = millis();

  // --- Motor ON logic ---
  if (bothDetected) {
    if (!timingOn) {
      sensorOnStart = currentMillis;
      timingOn = true;
    }
    
    // If sensors have detected can for the required hold time AND motor is currently off
    if (timingOn && (currentMillis - sensorOnStart >= 2000) && !motorOn) {
      Serial.println("Beeping before turning motor ON...");
      beepMultipleTimes(14, BUZZER_BEEP_TIME, BUZZER_PAUSE_TIME);  // Short beep pattern before turning ON
      
      digitalWrite(MOTOR_PIN, LOW);
      motorOn = true;
      Serial.println("Motor turned ON");
    }
    
    timingOff = false;  // Reset the OFF timing flag when both sensors detect
  } 
  else {
    // At least one sensor not detecting anything
    timingOn = false;  // Reset the ON timing flag
    
    // --- Motor OFF logic ---
    if (!timingOff) {
      sensorOffStart = currentMillis;
      timingOff = true;
    }
    
    // If sensors have NOT detected can for the required hold time AND motor is currently on
    if (timingOff && (currentMillis - sensorOffStart >= 600) && motorOn) {
      Serial.println("Beeping before turning motor OFF...");
      beepMultipleTimes(4, BUZZER_BEEP_TIME, BUZZER_PAUSE_TIME);  // Longer beep pattern before turning OFF
      
      digitalWrite(MOTOR_PIN, HIGH);
      motorOn = false;
      Serial.println("Motor turned OFF");
      
      // Additional delay to allow piston to reset after turning off
      delay(PISTON_DOWN_DELAY);
    }
  }
  
  delay(LOOP_PAUSE);  // Small delay for debounce
}