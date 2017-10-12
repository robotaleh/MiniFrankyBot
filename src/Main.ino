///////////////
// LIBRERÍAS //
///////////////
#include <Wire.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>
#include <Octosnake.h>
#include <Comandos.h>

//////////////////
//PINES DE LEDS //
//////////////////
#define LED_DERECHO 5
#define LED_IZQUIERDO 9

/////////////////////////
//DEFINICIÓN DE SERVOS //
/////////////////////////
#define NUM_SERVOS_PIERNA_IZQUIERDA 5
#define NUM_SERVOS_PIERNA_DERECHA 5
#define NUM_SERVOS_CADERA 3
#define NUM_SERVOS_HOMBROS 2
#define SERVOMIN  110 // Ancho de pulso mínimo
#define SERVOMAX  500 // Ancho de pulso máximo

////////////////////
//PINES DE SERVOS //
////////////////////
short pinsServosPiernaIzquierda[] = {9, 13, 12, 1, 10}; // Los números son los índices de la PCA9685
short pinsServosPiernaDerecha[] = {5, 3, 2, 0, 7}; // Los números son los índices de la PCA9685
short pinsServosCadera[] = {14, 8, 6}; // Los números son los índices de la PCA9685
short pinsServosHombros[] = {3, 11}; // Los servos de los hombros van directos al Arduino para dejar espacio en la PCA9685
Servo servosHombros[NUM_SERVOS_HOMBROS]; // Objetos Servo para los hombros


////////////////////////
//INICIO DE LIBRERÍAS //
////////////////////////
Adafruit_PWMServoDriver servoController = Adafruit_PWMServoDriver();
Oscillator oscillatorPiernaIzquierda[NUM_SERVOS_PIERNA_IZQUIERDA];
Oscillator oscillatorPiernaDerecha[NUM_SERVOS_PIERNA_DERECHA];
Oscillator oscillatorCadera[NUM_SERVOS_CADERA];
Oscillator oscillatorHombros[NUM_SERVOS_HOMBROS];

///////////////////////////////////
//ARRAYS DE POSICIONES INICIALES //
///////////////////////////////////
byte posicionesInicialesPiernaIzquierda[NUM_SERVOS_PIERNA_IZQUIERDA];
byte posicionesInicialesPiernaDerecha[NUM_SERVOS_PIERNA_DERECHA];
byte posicionesInicialesCadera[NUM_SERVOS_CADERA];
byte posicionesInicialesHombros[NUM_SERVOS_HOMBROS];

//////////////////////////////
//POSICIONES DE ARRAYS      //
//POSICIONES DE MOVIMIENTOS //
//////////////////////////////
#define OFFSET 0
#define PERIODO 1
#define AMPLITUD 2
#define FASE 3
#define DEFAULT 4

/////////////////////
// VARIABLES PARA  //
// COMUNICACIÓN BT //
/////////////////////
long last_update;
char letra = ' ';
String valor = "";

void setup() {
  init_all();
}

void loop() {
}
