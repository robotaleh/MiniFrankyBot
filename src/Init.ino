//////////////////////////////////////////////////////////////////////
// Este fichero contendrá todos los procesos iniciales del programa //
// que se deberán ejecutar una sola vez al inicio del mismo.        //
//////////////////////////////////////////////////////////////////////

/**
* Función principal de inicialización de componentes.
*/
void init_all(){
  init_serial();
  delay(100);
  init_posiciones_iniciales();
  delay(100);
  init_servos();
  delay(100);
  init_leds();
  delay(100);
}

/**
* Inicialización del puerto Serial.
*/
void init_serial(){
  Serial.begin(9600);
  while (!Serial){}
}

/**
* Inicialización de los servos y posicionamiento inicial.
*/
void init_servos(){
  init_arduino_servos();
  init_PCA9685_servos();
}

/**
* Inizializa los servos conectados directamente al Arduino y establece su posicion inicial.
*/
void init_arduino_servos(){
  Servo servosHombros[NUM_SERVOS_HOMBROS];
  for (short servo = 0; servo < NUM_SERVOS_HOMBROS; servo++) {
    servosHombros[servo].attach(pinsServosHombros[servo]);
    servosHombros[servo].write(posicionesInicialesHombros[servo]);
  }
}

/**
* Inicizaliza los servos conectados a la PCA9685 y establece su posición inicial.
*/
void init_PCA9685_servos(){
  // Iniciar de la PCA9685 y establecer la frecuencia de funcionamiento.
  servoController.begin();
  servoController.setPWMFreq(50);

  // Establecer posiciones para la PIERNA IZQUIERDA
  for (short servo = 0; servo < NUM_SERVOS_PIERNA_IZQUIERDA; servo++) {
    servoController.setPWM(pinsServosPiernaIzquierda[servo], 0, map(posicionesInicialesPiernaIzquierda[servo], 0, 180, SERVOMIN, SERVOMAX));
  }

  // Establecer posiciones para la PIERNA DERECHA
  for (short servo = 0; servo < NUM_SERVOS_PIERNA_DERECHA; servo++) {
    servoController.setPWM(pinsServosPiernaDerecha[servo], 0, map(posicionesInicialesPiernaDerecha[servo], 0, 180, SERVOMIN, SERVOMAX));
  }

  // Establecer posiciones para la CADERA
  for (short servo = 0; servo < NUM_SERVOS_CADERA; servo++) {
    servoController.setPWM(pinsServosCadera[servo], 0, map(posicionesInicialesCadera[servo], 0, 180, SERVOMIN, SERVOMAX));
  }
}

/**
* Inicialización de leds
*/
void init_leds(){
  pinMode(LED_DERECHO, OUTPUT);
  pinMode(LED_IZQUIERDO, OUTPUT);
}

/**
* Establece los valores para las posiciones iniciales de cada grupo de servos
*/
void init_posiciones_iniciales(){
  /////////////////////////////////////////
  // Posiciones iniciales PIERNA IZQUIERDA //
  /////////////////////////////////////////
  posicionesInicialesPiernaIzquierda[0] = 130;
  posicionesInicialesPiernaIzquierda[1] = 143;
  posicionesInicialesPiernaIzquierda[2] = 170;
  posicionesInicialesPiernaIzquierda[3] = 10;
  posicionesInicialesPiernaIzquierda[4] = 25;

  ///////////////////////////////////////////
  // Posiciones iniciales PIERNA DERECHA //
  ///////////////////////////////////////////
  posicionesInicialesPiernaDerecha[0] = 60;
  posicionesInicialesPiernaDerecha[1] = 28;
  posicionesInicialesPiernaDerecha[2] = 18;
  posicionesInicialesPiernaDerecha[3] = 161;
  posicionesInicialesPiernaDerecha[4] = 146;

  /////////////////////////////////////////
  // Posiciones iniciales CADERA //
  /////////////////////////////////////////
  posicionesInicialesCadera[0] = 130;
  posicionesInicialesCadera[1] = 58;
  posicionesInicialesCadera[2] = 80;

  /////////////////////////////////////////
  // Posiciones iniciales HOMBROS //
  /////////////////////////////////////////
  posicionesInicialesHombros[0] = 180;
  posicionesInicialesHombros[1] = 5;
}
