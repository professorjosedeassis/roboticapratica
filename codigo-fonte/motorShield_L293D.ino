/**
  Motor Shield L293D
  - Controle de 4 motores CC
  - Controle de um micro servo
  - Leitura do sensor ultrasônico HC-SR04
  @author Professor José de Assis
  @link https://roboticapratica.com.br/

  CHASSI ROBÓTICO (Ligação dos motores)
    
   /- M4 ------ M3 -\
  |                  |
  |  Frente          |
  |  <===            |
  |                  |
   \- M1 ------ M2 -/

  SENSOR ULTRASSÔNICO HC-SR04
   -------------------
  | Sensor  | Arduino |
  | VCC     | 5V      |
  | Trig    | A5      |
  | Echo    | A4      |
  | GND     | GND     |
   -------------------

  MICRO SERVO
   --------------------------------
  | Servo    | Motor Shield (SER1) |
  | Marron   | -                   |
  | Vermelho | +                   |
  | Laranja  | S                   |
   --------------------------------   
*/

#include <AFMotor.h>
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

#include <Servo.h>
Servo SER1;

int distancia;
long sensor;

void setup() {
  Serial.begin(9600);
  pinMode (A4, INPUT ); //Echo HC-SR04
  pinMode (A5, OUTPUT); //Trig HC-SR04
  pinMode (13, OUTPUT);
  SER1.attach(10);
}

void loop() {
  //teste do sensor ultrassônico
  distancia = ping();
  Serial.print(distancia);
  Serial.println(" cm");
  delay(2000);
  //teste do micro servo
  SER1.write(0);
  delay(1000);
  SER1.write(90);
  delay(1000);
  SER1.write(180);
  delay(2000);
  //testes dos motores
  forward();
  delay(1000);
  stopped();
  delay(1000);
  backward();
  delay(1000);
  stopped();
  delay(1000);
  left();
  delay(1000);
  stopped();
  delay(1000);
  right();
  delay(1000);
  stopped();
  delay(2000);  
}

//sensor ultrassônico
long ping() {
  digitalWrite(A5, LOW);
  delayMicroseconds(2);
  digitalWrite(A5, HIGH);
  delayMicroseconds(10);
  sensor = pulseIn (A4, HIGH);
  return (sensor / 29) / 2;
}

//Parar o robô
void stopped() {
  M1.setSpeed(150);
  M2.setSpeed(150);
  M3.setSpeed(150);
  M4.setSpeed(150);
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
}

//Seguir em frente
void forward() {
  M1.setSpeed(150);
  M2.setSpeed(150);
  M3.setSpeed(150);
  M4.setSpeed(150);
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}

//Seguir de ré
void backward() {
  M1.setSpeed(150);
  M2.setSpeed(150);
  M3.setSpeed(150);
  M4.setSpeed(150);
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}

//Girar a direita
void right() {
  M1.setSpeed(150);
  M2.setSpeed(150);
  M3.setSpeed(150);
  M4.setSpeed(150);
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}

//Girar a esquerda
void left() {
  M1.setSpeed(150);
  M2.setSpeed(150);
  M3.setSpeed(150);
  M4.setSpeed(150);
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}
