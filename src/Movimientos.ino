///////////////////////////////////////////////////////////////////
// Este fichero contendrá todos los movimientos y posiciones que //
// podrá adoptar el robot durante su funcionamiento.             //
///////////////////////////////////////////////////////////////////

/**
* Establece todos los servos a su posición inicial.
*/
void init_position(){
  set_servo_position(pinsServosPiernaIzquierda[0], posicionesInicialesPiernaIzquierda[0]);
  set_servo_position(pinsServosPiernaIzquierda[1], posicionesInicialesPiernaIzquierda[1]);
  set_servo_position(pinsServosPiernaIzquierda[2], posicionesInicialesPiernaIzquierda[2]);
  set_servo_position(pinsServosPiernaIzquierda[3], posicionesInicialesPiernaIzquierda[3]);
  set_servo_position(pinsServosPiernaIzquierda[4], posicionesInicialesPiernaIzquierda[4]);
  set_servo_position(pinsServosPiernaDerecha[0], posicionesInicialesPiernaDerecha[0]);
  set_servo_position(pinsServosPiernaDerecha[1], posicionesInicialesPiernaDerecha[1]);
  set_servo_position(pinsServosPiernaDerecha[2], posicionesInicialesPiernaDerecha[2]);
  set_servo_position(pinsServosPiernaDerecha[3], posicionesInicialesPiernaDerecha[3]);
  set_servo_position(pinsServosPiernaDerecha[4], posicionesInicialesPiernaDerecha[4]);
  set_servo_position(pinsServosCadera[0], posicionesInicialesCadera[0]);
  set_servo_position(pinsServosCadera[1], posicionesInicialesCadera[1]);
  set_servo_position(pinsServosCadera[2], posicionesInicialesCadera[2]);
  set_servo_position(servosHombros[0], posicionesInicialesHombros[0]);
  set_servo_position(servosHombros[1], posicionesInicialesHombros[1]);
  delay(100);
}

/**
* Movimiento de agacharse lentamente que parte desde la posición inicial.
* @param repeticiones Número de períodos a ejecutar
*/
void mov_agacharse(float repeticiones){
  init_position();

  const byte numServos = 8;
  short ajustesAgacharse[numServos][5];
  short servosAgacharse[numServos];

  servosAgacharse[0] = pinsServosPiernaDerecha[1];
  servosAgacharse[1] = pinsServosPiernaDerecha[2];
  servosAgacharse[2] = pinsServosPiernaDerecha[3];
  servosAgacharse[3] = pinsServosPiernaDerecha[4];
  servosAgacharse[4] = pinsServosPiernaIzquierda[1];
  servosAgacharse[5] = pinsServosPiernaIzquierda[2];
  servosAgacharse[6] = pinsServosPiernaIzquierda[3];
  servosAgacharse[7] = pinsServosPiernaIzquierda[4];

  ajustesAgacharse[0][OFFSET]           = posicionesInicialesPiernaDerecha[1];
  ajustesAgacharse[0][PERIODO]          = 1000;
  ajustesAgacharse[0][AMPLITUD]         = 20;
  ajustesAgacharse[0][FASE]             = 0;
  ajustesAgacharse[0][DEFAULT]          = 0;

  ajustesAgacharse[1][OFFSET]           = posicionesInicialesPiernaDerecha[2];
  ajustesAgacharse[1][PERIODO]          = 1000;
  ajustesAgacharse[1][AMPLITUD]         = 20;
  ajustesAgacharse[1][FASE]             = 0;
  ajustesAgacharse[1][DEFAULT]          = 0;

  ajustesAgacharse[2][OFFSET]           = posicionesInicialesPiernaDerecha[3];
  ajustesAgacharse[2][PERIODO]          = 1000;
  ajustesAgacharse[2][AMPLITUD]         = 20;
  ajustesAgacharse[2][FASE]             = 180;
  ajustesAgacharse[2][DEFAULT]          = 0;

  ajustesAgacharse[3][OFFSET]           = posicionesInicialesPiernaDerecha[4];
  ajustesAgacharse[3][PERIODO]          = 1000;
  ajustesAgacharse[3][AMPLITUD]         = 20;
  ajustesAgacharse[3][FASE]             = 180;
  ajustesAgacharse[3][DEFAULT]          = 0;

  ajustesAgacharse[4][OFFSET]           = posicionesInicialesPiernaIzquierda[1];
  ajustesAgacharse[4][PERIODO]          = 1000;
  ajustesAgacharse[4][AMPLITUD]         = 20;
  ajustesAgacharse[4][FASE]             = 180;
  ajustesAgacharse[4][DEFAULT]          = 0;

  ajustesAgacharse[5][OFFSET]           = posicionesInicialesPiernaIzquierda[2];
  ajustesAgacharse[5][PERIODO]          = 1000;
  ajustesAgacharse[5][AMPLITUD]         = 20;
  ajustesAgacharse[5][FASE]             = 180;
  ajustesAgacharse[5][DEFAULT]          = 0;

  ajustesAgacharse[6][OFFSET]           = posicionesInicialesPiernaIzquierda[3];
  ajustesAgacharse[6][PERIODO]          = 1000;
  ajustesAgacharse[6][AMPLITUD]         = 20;
  ajustesAgacharse[6][FASE]             = 0;
  ajustesAgacharse[6][DEFAULT]          = 0;

  ajustesAgacharse[7][OFFSET]           = posicionesInicialesPiernaIzquierda[4];
  ajustesAgacharse[7][PERIODO]          = 1000;
  ajustesAgacharse[7][AMPLITUD]         = 20;
  ajustesAgacharse[7][FASE]             = 0;
  ajustesAgacharse[7][DEFAULT]          = 0;

  ejecutar_movimiento(servosAgacharse, ajustesAgacharse, numServos, repeticiones);
}

/**
* Realiza un pequeño salto usando la funcion "mov_agacharse" como primer paso
* @param repeticiones Número de saltos consecutivos.
*/
void mov_salto(int repeticiones) {
  short loops = 0;
  do {

    // Prepara el salto agachandose lentamente
    mov_agacharse(0.25);
    init_position();

    loops ++;
  } while(loops < repeticiones);

}

/**
* Efectua un paso, compuesto por varios segmentos de movimientos.
* @param repeticiones Número de pasos que dará.
*/
void mov_paso(int repeticiones){
  short loops = 0;
  float speed = 0.5;

  do {
    const byte numServosPaso1 = 4;
    short ajustesPaso1[numServosPaso1][5];
    short servosPaso1[numServosPaso1];

    servosPaso1[0] = pinsServosPiernaIzquierda[0];
    servosPaso1[1] = pinsServosCadera[0];
    servosPaso1[2] = pinsServosPiernaDerecha[0];
    servosPaso1[3] = pinsServosCadera[2];

    ajustesPaso1[0][OFFSET]           = posicionesInicialesPiernaIzquierda[0];
    ajustesPaso1[0][PERIODO]          = 6000*speed;
    ajustesPaso1[0][AMPLITUD]         = 15;
    ajustesPaso1[0][FASE]             = 0;
    ajustesPaso1[0][DEFAULT]          = 0;

    ajustesPaso1[1][OFFSET]           = posicionesInicialesCadera[0];
    ajustesPaso1[1][PERIODO]          = 6000*speed;
    ajustesPaso1[1][AMPLITUD]         = 15;
    ajustesPaso1[1][FASE]             = 0;
    ajustesPaso1[1][DEFAULT]          = 0;

    ajustesPaso1[2][OFFSET]           = posicionesInicialesPiernaDerecha[0];
    ajustesPaso1[2][PERIODO]          = 6000*speed;
    ajustesPaso1[2][AMPLITUD]         = 15;
    ajustesPaso1[2][FASE]             = 0;
    ajustesPaso1[2][DEFAULT]          = 0;

    ajustesPaso1[3][OFFSET]           = posicionesInicialesCadera[2];
    ajustesPaso1[3][PERIODO]          = 6000*speed;
    ajustesPaso1[3][AMPLITUD]         = 15;
    ajustesPaso1[3][FASE]             = 270;
    ajustesPaso1[3][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso1, ajustesPaso1, numServosPaso1, 0.25);

    delay(100);

    const byte numServosPaso2 = 2;
    short ajustesPaso2[numServosPaso2][5];
    short servosPaso2[numServosPaso2];

    // servosPaso2[0] = pinsServosPiernaDerecha[1];
    // servosPaso2[1] = pinsServosPiernaDerecha[2];
    servosPaso2[0] = pinsServosPiernaDerecha[3];
    servosPaso2[1] = pinsServosPiernaDerecha[4];

    // ajustesPaso2[0][OFFSET]           = posicionesInicialesPiernaDerecha[1];
    // ajustesPaso2[0][PERIODO]          = 4000*speed;
    // ajustesPaso2[0][AMPLITUD]         = 30;
    // ajustesPaso2[0][FASE]             = 0;
    // ajustesPaso2[0][DEFAULT]          = 0;
    //
    // ajustesPaso2[1][OFFSET]           = posicionesInicialesPiernaDerecha[2];
    // ajustesPaso2[1][PERIODO]          = 4000*speed;
    // ajustesPaso2[1][AMPLITUD]         = 30;
    // ajustesPaso2[1][FASE]             = 0;
    // ajustesPaso2[1][DEFAULT]          = 0;

    ajustesPaso2[0][OFFSET]           = posicionesInicialesPiernaDerecha[3];
    ajustesPaso2[0][PERIODO]          = 4000*speed;
    ajustesPaso2[0][AMPLITUD]         = 27;
    ajustesPaso2[0][FASE]             = 180;
    ajustesPaso2[0][DEFAULT]          = 0;

    ajustesPaso2[1][OFFSET]           = posicionesInicialesPiernaDerecha[4];
    ajustesPaso2[1][PERIODO]          = 4000*speed;
    ajustesPaso2[1][AMPLITUD]         = 27;
    ajustesPaso2[1][FASE]             = 180;
    ajustesPaso2[1][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso2, ajustesPaso2, numServosPaso2, 0.25);

    delay(100);

    // const byte numServosPaso3 = 2;
    // short ajustesPaso3[numServosPaso3][5];
    // short servosPaso3[numServosPaso3];
    //
    // servosPaso3[0] = pinsServosPiernaDerecha[1];
    // servosPaso3[1] = pinsServosPiernaDerecha[2];
    //
    // ajustesPaso3[0][OFFSET]           = posicionesActualesPCA9685[servosPaso3[0]];
    // ajustesPaso3[0][PERIODO]          = 4000*speed;
    // ajustesPaso3[0][AMPLITUD]         = 40;
    // ajustesPaso3[0][FASE]             = 180;
    // ajustesPaso3[0][DEFAULT]          = 0;
    //
    // ajustesPaso3[1][OFFSET]           = posicionesActualesPCA9685[servosPaso3[1]];
    // ajustesPaso3[1][PERIODO]          = 4000*speed;
    // ajustesPaso3[1][AMPLITUD]         = 40;
    // ajustesPaso3[1][FASE]             = 180;
    // ajustesPaso3[1][DEFAULT]          = 0;
    //
    // ejecutar_movimiento(servosPaso3, ajustesPaso3, numServosPaso3, 0.25);
    //
    // delay(100);

    const byte numServosPaso4 = 5;
    short ajustesPaso4[numServosPaso4][5];
    short servosPaso4[numServosPaso4];

    servosPaso4[0] = pinsServosPiernaIzquierda[0];
    servosPaso4[1] = pinsServosCadera[0];
    servosPaso4[2] = pinsServosPiernaDerecha[0];
    servosPaso4[3] = pinsServosCadera[2];
    servosPaso4[4] = pinsServosPiernaIzquierda[1];
    servosPaso4[5] = pinsServosPiernaIzquierda[2];

    ajustesPaso4[0][OFFSET]           = posicionesActualesPCA9685[servosPaso4[0]];
    ajustesPaso4[0][PERIODO]          = 4000*speed;
    ajustesPaso4[0][AMPLITUD]         = 10;
    ajustesPaso4[0][FASE]             = 180;
    ajustesPaso4[0][DEFAULT]          = 0;

    ajustesPaso4[1][OFFSET]           = posicionesActualesPCA9685[servosPaso4[1]];
    ajustesPaso4[1][PERIODO]          = 4000*speed;
    ajustesPaso4[1][AMPLITUD]         = 10;
    ajustesPaso4[1][FASE]             = 180;
    ajustesPaso4[1][DEFAULT]          = 0;

    ajustesPaso4[2][OFFSET]           = posicionesActualesPCA9685[servosPaso4[2]];
    ajustesPaso4[2][PERIODO]          = 4000*speed;
    ajustesPaso4[2][AMPLITUD]         = 15;
    ajustesPaso4[2][FASE]             = 180;
    ajustesPaso4[2][DEFAULT]          = 0;
    //
    ajustesPaso4[3][OFFSET]           = posicionesActualesPCA9685[servosPaso4[3]];
    ajustesPaso4[3][PERIODO]          = 4000*speed;
    ajustesPaso4[3][AMPLITUD]         = 10;
    ajustesPaso4[3][FASE]             = 90;
    ajustesPaso4[3][DEFAULT]          = 0;

    ajustesPaso4[4][OFFSET]           = posicionesInicialesPiernaIzquierda[1];
    ajustesPaso4[4][PERIODO]          = 4000*speed;
    ajustesPaso4[4][AMPLITUD]         = 80;
    ajustesPaso4[4][FASE]             = 180;
    ajustesPaso4[4][DEFAULT]          = 0;

    ajustesPaso4[5][OFFSET]           = posicionesInicialesPiernaIzquierda[2];
    ajustesPaso4[5][PERIODO]          = 4000*speed;
    ajustesPaso4[5][AMPLITUD]         = 80;
    ajustesPaso4[5][FASE]             = 180;
    ajustesPaso4[5][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso4, ajustesPaso4, numServosPaso4, 0.25);

    delay(100);

    const byte numServosPaso5 = 4;
    short ajustesPaso5[numServosPaso5][5];
    short servosPaso5[numServosPaso5];

    servosPaso5[0] = pinsServosPiernaIzquierda[0];
    servosPaso5[1] = pinsServosCadera[0];
    servosPaso5[2] = pinsServosPiernaDerecha[0];
    servosPaso5[3] = pinsServosCadera[2];

    ajustesPaso5[0][OFFSET]           = posicionesActualesPCA9685[servosPaso5[0]];
    ajustesPaso5[0][PERIODO]          = 6000*speed;
    ajustesPaso5[0][AMPLITUD]         = 10;
    ajustesPaso5[0][FASE]             = 180;
    ajustesPaso5[0][DEFAULT]          = 0;

    ajustesPaso5[1][OFFSET]           = posicionesActualesPCA9685[servosPaso5[1]];
    ajustesPaso5[1][PERIODO]          = 6000*speed;
    ajustesPaso5[1][AMPLITUD]         = 10;
    ajustesPaso5[1][FASE]             = 90;
    ajustesPaso5[1][DEFAULT]          = 0;

    ajustesPaso5[2][OFFSET]           = posicionesActualesPCA9685[servosPaso5[2]];
    ajustesPaso5[2][PERIODO]          = 6000*speed;
    ajustesPaso5[2][AMPLITUD]         = 10;
    ajustesPaso5[2][FASE]             = 180;
    ajustesPaso5[2][DEFAULT]          = 0;

    ajustesPaso5[3][OFFSET]           = posicionesActualesPCA9685[servosPaso5[3]];
    ajustesPaso5[3][PERIODO]          = 6000*speed;
    ajustesPaso5[3][AMPLITUD]         = 10;
    ajustesPaso5[3][FASE]             = 90;
    ajustesPaso5[3][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso5, ajustesPaso5, numServosPaso5, 0.25);

    delay(100);

    const byte numServosPaso6 = 6;
    short ajustesPaso6[numServosPaso6][5];
    short servosPaso6[numServosPaso6];

    servosPaso6[0] = pinsServosPiernaIzquierda[1];
    servosPaso6[1] = pinsServosPiernaIzquierda[2];
    servosPaso6[2] = pinsServosPiernaIzquierda[3];
    servosPaso6[3] = pinsServosPiernaIzquierda[4];
    servosPaso6[4] = pinsServosPiernaDerecha[1];
    servosPaso6[5] = pinsServosPiernaDerecha[2];

    ajustesPaso6[0][OFFSET]           = posicionesActualesPCA9685[servosPaso6[0]];
    ajustesPaso6[0][PERIODO]          = 4000*speed;
    ajustesPaso6[0][AMPLITUD]         = 30;
    ajustesPaso6[0][FASE]             = 180;
    ajustesPaso6[0][DEFAULT]          = 0;

    ajustesPaso6[1][OFFSET]           = posicionesActualesPCA9685[servosPaso6[1]];
    ajustesPaso6[1][PERIODO]          = 4000*speed;
    ajustesPaso6[1][AMPLITUD]         = 30;
    ajustesPaso6[1][FASE]             = 180;
    ajustesPaso6[1][DEFAULT]          = 0;

    ajustesPaso6[2][OFFSET]           = posicionesActualesPCA9685[servosPaso6[2]];
    ajustesPaso6[2][PERIODO]          = 4000*speed;
    ajustesPaso6[2][AMPLITUD]         = 30;
    ajustesPaso6[2][FASE]             = 0;
    ajustesPaso6[2][DEFAULT]          = 0;

    ajustesPaso6[3][OFFSET]           = posicionesActualesPCA9685[servosPaso6[3]];
    ajustesPaso6[3][PERIODO]          = 4000*speed;
    ajustesPaso6[3][AMPLITUD]         = 30;
    ajustesPaso6[3][FASE]             = 0;
    ajustesPaso6[3][DEFAULT]          = 0;

    ajustesPaso6[4][OFFSET]           = posicionesActualesPCA9685[servosPaso6[4]];
    ajustesPaso6[4][PERIODO]          = 4000*speed;
    ajustesPaso6[4][AMPLITUD]         = 30;
    ajustesPaso6[4][FASE]             = 0;
    ajustesPaso6[4][DEFAULT]          = 0;

    ajustesPaso6[5][OFFSET]           = posicionesActualesPCA9685[servosPaso6[5]];
    ajustesPaso6[5][PERIODO]          = 4000*speed;
    ajustesPaso6[5][AMPLITUD]         = 30;
    ajustesPaso6[5][FASE]             = 0;
    ajustesPaso6[5][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso6, ajustesPaso6, numServosPaso6, 0.25);

    delay(100);

    const byte numServosPaso7 = 4;
    short ajustesPaso7[numServosPaso7][5];
    short servosPaso7[numServosPaso7];

    servosPaso7[0] = pinsServosPiernaIzquierda[0];
    servosPaso7[1] = pinsServosCadera[0];
    servosPaso7[2] = pinsServosPiernaDerecha[0];
    servosPaso7[3] = pinsServosCadera[2];

    ajustesPaso7[0][OFFSET]           = posicionesActualesPCA9685[servosPaso7[0]];
    ajustesPaso7[0][PERIODO]          = 6000*speed;
    ajustesPaso7[0][AMPLITUD]         = 10;
    ajustesPaso7[0][FASE]             = 0;
    ajustesPaso7[0][DEFAULT]          = 0;

    ajustesPaso7[1][OFFSET]           = posicionesActualesPCA9685[servosPaso7[1]];
    ajustesPaso7[1][PERIODO]          = 6000*speed;
    ajustesPaso7[1][AMPLITUD]         = 10;
    ajustesPaso7[1][FASE]             = 0;
    ajustesPaso7[1][DEFAULT]          = 0;

    ajustesPaso7[2][OFFSET]           = posicionesActualesPCA9685[servosPaso7[2]];
    ajustesPaso7[2][PERIODO]          = 6000*speed;
    ajustesPaso7[2][AMPLITUD]         = 10;
    ajustesPaso7[2][FASE]             = 0;
    ajustesPaso7[2][DEFAULT]          = 0;

    ajustesPaso7[3][OFFSET]           = posicionesActualesPCA9685[servosPaso7[3]];
    ajustesPaso7[3][PERIODO]          = 6000*speed;
    ajustesPaso7[3][AMPLITUD]         = 10;
    ajustesPaso7[3][FASE]             = 270;
    ajustesPaso7[3][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso7, ajustesPaso7, numServosPaso7, 0.25);

    delay(100);

    const byte numServosPaso8 = 6;
    short ajustesPaso8[numServosPaso8][5];
    short servosPaso8[numServosPaso8];

    servosPaso8[0] = pinsServosPiernaDerecha[1];
    servosPaso8[1] = pinsServosPiernaDerecha[2];
    servosPaso8[2] = pinsServosPiernaDerecha[3];
    servosPaso8[3] = pinsServosPiernaDerecha[4];
    servosPaso8[4] = pinsServosPiernaIzquierda[2];
    // servosPaso8[5] = pinsServosPiernaIzquierda[1];
    disable_servo(pinsServosPiernaIzquierda[1]);
    disable_servo(pinsServosPiernaIzquierda[3]);
    // servosPaso8[6] = pinsServosPiernaIzquierda[3];
    servosPaso8[5] = pinsServosPiernaIzquierda[4];

    ajustesPaso8[0][OFFSET]           = posicionesActualesPCA9685[servosPaso8[0]];
    ajustesPaso8[0][PERIODO]          = 4000*speed;
    ajustesPaso8[0][AMPLITUD]         = 20;
    ajustesPaso8[0][FASE]             = 180;
    ajustesPaso8[0][DEFAULT]          = 0;

    ajustesPaso8[1][OFFSET]           = posicionesActualesPCA9685[servosPaso8[1]];
    ajustesPaso8[1][PERIODO]          = 4000*speed;
    ajustesPaso8[1][AMPLITUD]         = 20;
    ajustesPaso8[1][FASE]             = 180;
    ajustesPaso8[1][DEFAULT]          = 0;

    ajustesPaso8[2][OFFSET]           = posicionesActualesPCA9685[servosPaso8[2]];
    ajustesPaso8[2][PERIODO]          = 4000*speed;
    ajustesPaso8[2][AMPLITUD]         = 30;
    ajustesPaso8[2][FASE]             = 0;
    ajustesPaso8[2][DEFAULT]          = 0;

    ajustesPaso8[3][OFFSET]           = posicionesActualesPCA9685[servosPaso8[3]];
    ajustesPaso8[3][PERIODO]          = 4000*speed;
    ajustesPaso8[3][AMPLITUD]         = 30;
    ajustesPaso8[3][FASE]             = 0;
    ajustesPaso8[3][DEFAULT]          = 0;

    ajustesPaso8[4][OFFSET]           = posicionesActualesPCA9685[servosPaso8[4]];
    ajustesPaso8[4][PERIODO]          = 4000*speed;
    ajustesPaso8[4][AMPLITUD]         = 40;
    ajustesPaso8[4][FASE]             = 0;
    ajustesPaso8[4][DEFAULT]          = 0;

    // ajustesPaso8[5][OFFSET]           = posicionesActualesPCA9685[servosPaso8[5]];
    // ajustesPaso8[5][PERIODO]          = 4000*speed;
    // ajustesPaso8[5][AMPLITUD]         = 20;
    // ajustesPaso8[5][FASE]             = 90;
    // ajustesPaso8[5][DEFAULT]          = 0;
    //
    // ajustesPaso8[6][OFFSET]           = posicionesActualesPCA9685[servosPaso8[6]];
    // ajustesPaso8[6][PERIODO]          = 4000*speed;
    // ajustesPaso8[6][AMPLITUD]         = 40;
    // ajustesPaso8[6][FASE]             = 270;
    // ajustesPaso8[6][DEFAULT]          = 0;
    //
    ajustesPaso8[5][OFFSET]           = posicionesActualesPCA9685[servosPaso8[5]];
    ajustesPaso8[5][PERIODO]          = 4000*speed;
    ajustesPaso8[5][AMPLITUD]         = 40;
    ajustesPaso8[5][FASE]             = 180;
    ajustesPaso8[5][DEFAULT]          = 0;

    ejecutar_movimiento(servosPaso8, ajustesPaso8, numServosPaso8, 0.25);

    delay(100);

    init_position();

    loops++;
  } while(loops < repeticiones);


}
