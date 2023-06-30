void SensorPIR() {
  if (sensor) {
    if (digitalRead(PIRPin) == HIGH) {
      if (anterior == S_OFF) {
        state1 = 11;
      } else {
        state = seq_anterior;
      }
      lastButtonPress = millis();
    } else if (millis() - lastButtonPress > 10000) {
      state = OFF;
      state1 = 0;
    }
  }
}

void BTN_Control() {
  if (on_off) {
    if (digitalRead(BTN_MODO) == HIGH || button == true) {
      if (state == OFF) {
        state1 = 11;
      } else {
        state++;
        state = state % 4;
      }
      if (!buttonState) {
        tiempoInicio = millis();
        buttonState = true;
      } else {
        state--;
        state = state % 4;
      }

      if (((millis() - tiempoInicio) >= tiempoEspera)) {
        FSM_Modo();
        state1 = 0;
        buttonState = false;
      }
      lastButtonPress = millis();
    } else {
      buttonState = false;
    }

    if (millis() - lastButtonPress > 10000 && sensor) {
      state = OFF;
    }
  }
}

void onoff(float bri, uint8_t r2, uint8_t g2, uint8_t b2) {
  bool o = colorLed.getSwitch();
  bool o2 = digitalRead(pinSwitch);
  if (o && (brillo == bri) && !(r2 != r || g2 != g || b2 != b)) {
    on_off = o;
    sensor = o;
    state1 = 11;
    Serial.print("1");
  } else if (o && (brillo == bri || bri == 100) && (r2 == r && g2 == g && b2 == b)) {
    on_off = o;
    sensor = o;
    state1 = 11;
    Serial.print("2");
  } else if (o && (bri == 100) && (r2 != r || g2 != g || b2 != b) && sensor) {
    on_off = o;
    sensor = o;
    state1 = 11;
    Serial.print("3");
  } else if (o && sensor == false && (r2 != r || g2 != g || b2 != b)) {
    on_off = o;
    sensor = false;
    Serial.print("4");
  } else if (o && sensor && (r2 != r || g2 != g || b2 != b)) {
    on_off = o;
    sensor = o;
    Serial.print("5");
  } else {
    on_off = o;
    sensor = false;
    state = OFF;
    state1 = 0;
    Serial.print("6");
  }
}

void onoff2() {
  bool o = colorLed.getSwitch();
  bool o2 = digitalRead(pinSwitch);
  Serial.println();
  Serial.print(o2);
  Serial.print("   :   ");
  Serial.print(o);
  if (o && o2) {
    on_off = o;
    sensor = o;
    state1 = 11;
  } else {
    on_off = 0;
    sensor = false;
    state = OFF;
    state1 = 0;
  }
}
