# 1 "c:\\users\\alexe\\appdata\\local\\temp\\tmplgr_k0"
#include <Arduino.h>
# 1 "C:/Users/alexe/Dropbox/OPRobots/__ROBOTS__/MiniFrankyBot/MiniFrankyBot/src/Main.ino"






#include <Wire.h>



#include <Adafruit_PWMServoDriver.h>

#include <Octosnake.h>
# 23 "C:/Users/alexe/Dropbox/OPRobots/__ROBOTS__/MiniFrankyBot/MiniFrankyBot/src/Main.ino"
#define NUM_SERVOS_PIERNA_IZQUIERDA 5

#define NUM_SERVOS_PIERNA_DERECHA 5

#define NUM_SERVOS_CADERA 3

#define NUM_SERVOS_HOMBROS 2

#define SERVOMIN 500

#define SERVOMAX 2500
# 43 "C:/Users/alexe/Dropbox/OPRobots/__ROBOTS__/MiniFrankyBot/MiniFrankyBot/src/Main.ino"
short pinsServosPiernaIzquierda[] = {9, 13, 12, 1, 10};

short pinsServosPiernaDerecha[] = {5, 3, 2, 0, 7};

short pinsServosCadera[] = {14, 8, 6};

short pinsServosHombros[] = {11, 3};
# 61 "C:/Users/alexe/Dropbox/OPRobots/__ROBOTS__/MiniFrankyBot/MiniFrankyBot/src/Main.ino"
Adafruit_PWMServoDriver servoController = Adafruit_PWMServoDriver();

Oscillator oscillatorPiernaIzquierda[NUM_SERVOS_PIERNA_IZQUIERDA];

Oscillator oscillatorPiernaDerecha[NUM_SERVOS_PIERNA_DERECHA];

Oscillator oscillatorCadera[NUM_SERVOS_CADERA];

Oscillator oscillatorHombros[NUM_SERVOS_HOMBROS];
# 79 "C:/Users/alexe/Dropbox/OPRobots/__ROBOTS__/MiniFrankyBot/MiniFrankyBot/src/Main.ino"
byte posicionesInicialesPiernaIzquierda[NUM_SERVOS_PIERNA_IZQUIERDA];

byte posicionesInicialesPiernaDerecha[NUM_SERVOS_PIERNA_DERECHA];

byte posicionesInicialesCadera[NUM_SERVOS_CADERA];

byte posicionesInicialesHombros[NUM_SERVOS_HOMBROS];
# 97 "C:/Users/alexe/Dropbox/OPRobots/__ROBOTS__/MiniFrankyBot/MiniFrankyBot/src/Main.ino"
#define OFFSET 0

#define PERIODO 1

#define AMPLITUD 2

#define FASE 3

#define DEFAULT 4
void setup();
void loop();
#line 109 "C:/Users/alexe/Dropbox/OPRobots/__ROBOTS__/MiniFrankyBot/MiniFrankyBot/src/Main.ino"
void setup() {

}



void loop() {

}