//Pin Definitions
const int PING_PIN = 7;          //Ultrasonic Sensor
const int MOTOR_A1 = 5;          //Left motor control 1
const int MOTOR_A2 = 6;          //Left motor control 2
const int MOTOR_B1 = 9;          //Right motor control 1
const int MOTOR_B2 = 10;         //Right motor control 2
const int BUZZER_PIN = 3;        //Buzzer 
const int LED_PIN = 4; 			 //led pin

// Constants
const int OBSTACLE_DISTANCE = 20; // Distance in cm to trigger turn
const int TURN_DELAY = 750;      // How long to turn (milliseconds)
const int MOTOR_SPEED = 5;     // Motor speed (0-255)
const int BUZZER_FREQ = 2000;    // Buzzer frequency in Hz


void setup() {
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);
  pinMode(MOTOR_B1, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  long distance = getDistance();
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  //obstacle detection
  if (distance < OBSTACLE_DISTANCE && distance > 0) {
    digitalWrite(LED_PIN, HIGH);    
    tone(BUZZER_PIN, BUZZER_FREQ);
    
    stopMotors();
    delay(100);
    turnRight();
    delay(TURN_DELAY);
    stopMotors();
    delay(100);
    
    digitalWrite(LED_PIN, LOW);   
    noTone(BUZZER_PIN);
  }
  else {
    moveForward();
    digitalWrite(LED_PIN, LOW);  
    noTone(BUZZER_PIN);
  }
}

long getDistance() {
  //triggered by a HIGH pulse of 2 or more microseconds
  pinMode(PING_PIN, OUTPUT);
  digitalWrite(PING_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(PING_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(PING_PIN, LOW);

  //reading ping
  pinMode(PING_PIN, INPUT);
  
  //converting into distance
  return pulseIn(PING_PIN, HIGH) / 29 / 2;
}

//Motor control
void moveForward() {
  analogWrite(MOTOR_A1, MOTOR_SPEED);
  analogWrite(MOTOR_A2, 0);
  analogWrite(MOTOR_B1, MOTOR_SPEED);
  analogWrite(MOTOR_B2, 0);
}

void turnRight() {
  analogWrite(MOTOR_A1, MOTOR_SPEED);
  analogWrite(MOTOR_A2, 0);
  analogWrite(MOTOR_B1, 0);
  analogWrite(MOTOR_B2, MOTOR_SPEED);
}

void stopMotors() {
  analogWrite(MOTOR_A1, 0);
  analogWrite(MOTOR_A2, 0);
  analogWrite(MOTOR_B1, 0);
  analogWrite(MOTOR_B2, 0);
}