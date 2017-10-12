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
}
