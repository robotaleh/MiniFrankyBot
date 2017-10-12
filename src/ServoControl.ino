// Este fichero contendrá todas las funciones responsables de asignar
// posiciones y gestionar movimientos de todos los servos


void set_servo_position(int id_servo, int servo_offset){
  servoController.setPWM(id_servo, 0, map(servo_offset, 0, 180, (int)SERVOMIN, (int)SERVOMAX));
}

void set_servo_position(Servo servo, int servo_offset){
  servo.write(servo_offset);
}


void ejecutar_movimiento(short servosMovimiento[], short ajustesMovimiento[][5], byte numServos, float repeticiones) {
	Oscillator oscillatorMovimiento[numServos];

	// Iniciamos los osciladores
	for (byte servo = 0; servo < numServos; servo++) {
		oscillatorMovimiento[servo].setOffset(ajustesMovimiento[servo][OFFSET]);
		oscillatorMovimiento[servo].setPeriod(ajustesMovimiento[servo][PERIODO]);
		oscillatorMovimiento[servo].setAmplitude(ajustesMovimiento[servo][AMPLITUD]);
		oscillatorMovimiento[servo].setPhase(ajustesMovimiento[servo][FASE]);
		oscillatorMovimiento[servo].start();
		oscillatorMovimiento[servo].setTime(millis());
	}

  // Inicia el contador de servos parados e inicia el bucle del movimiento mientras haya servos en movimiento.
	byte countStopped = 0;
	do {
		for (byte servo = 0; servo < numServos; servo++) {
        set_servo_position(servosMovimiento[servo], oscillatorMovimiento[servo].refresh());
			if (repeticiones > 0 && oscillatorMovimiento[servo].getLoops() >= repeticiones && oscillatorMovimiento[servo].isRunning()) {
				oscillatorMovimiento[servo].stop();
        countStopped++;
				if (ajustesMovimiento[servo][DEFAULT]) {
          set_servo_position(servosMovimiento[servo], ajustesMovimiento[servo][OFFSET]);
				}
			}
		}
	} while (countStopped < numServos);
}
