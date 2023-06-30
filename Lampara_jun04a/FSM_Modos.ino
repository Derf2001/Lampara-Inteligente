void Efectos();

void FSM_Color() {
  switch (state) {
    case S_HOME:
      if (anterior == S_SEQ) {
        colorWipe(tira.Color(255, 0, 0), 150);  // Rojo
        colorWipe(tira.Color(0, 255, 0), 150);  // Verde
        colorWipe(tira.Color(0, 0, 255), 150);  // Azul
        seq_anterior = S_HOME;
      } else {
        //color_aterior = S_HOME;
        /*for (int i = 0; i < nleds; i++) {
          tira.setPixelColor(i, 255, 255, 255);
        }
        tira.show();*/
        r = 255;
        g = 255;
        b = 255;
        colorLed.setHue(255);
        colorLed.setSaturation(255);
        EEPROM.write(0, 255);
        EEPROM.write(1, 255);
        EEPROM.write(2, 255);
        EEPROM.commit();
        delay(retardo);
         state1 = 11;
      }
      break;
    case C_VERDE:
      if (anterior == S_SEQ) {
        //colorWipe(tira.Color(255, 0, 0), 100);    // Rojo
        colorWipe(tira.Color(0, 255, 255), 50);  // Verde
        //colorWipe(tira.Color(0, 0, 255), 100);    // Azul
        seq_anterior = C_VERDE;
      } else {
        //color_aterior = colorLed;
      /*  for (int i = 0; i < nleds; i++) {
          tira.setPixelColor(i, 255, 0, 0);
        }
        tira.show();*/
        r = 0;
        g = 255;
        b = 0;
        colorLed.setHue(120);
        colorLed.setSaturation(255);
        EEPROM.write(0, 0);
        EEPROM.write(1, 255);
        EEPROM.write(2, 0);
        EEPROM.commit();
        delay(retardo);
         state1 = 11;
      }
      break;
    case C_ROJO:
      if (anterior == S_SEQ) {
        rainbowCycle(20);
        seq_anterior = C_ROJO;
      } else {
        //color_aterior = C_ROJO;
      /*  for (int i = 0; i < nleds; i++) {
          tira.setPixelColor(i, 0, 255, 0);
        }
        tira.show();*/
        r = 255;
        g = 0;
        b = 0;
        colorLed.setHue(0);
        colorLed.setSaturation(255);
        EEPROM.write(0, 255);
        EEPROM.write(1, 0);
        EEPROM.write(2, 0);
        EEPROM.commit();
        delay(retardo);
         state1 = 11;
      }
      break;
    case C_AZUL:
      if (anterior == S_SEQ) {
        theaterChase(tira.Color(127, 255, 0), 30);
        seq_anterior = C_AZUL;
      } else {
        //color_aterior = C_AZUL;
       /* for (int i = 0; i < nleds; i++) {
          tira.setPixelColor(i, 0, 0, 255);
        }
        tira.show();*/
        r = 0;
        g = 0;
        b = 255;
        colorLed.setHue(240);
        colorLed.setSaturation(255);
        EEPROM.write(0, 0);
        EEPROM.write(1, 0);
        EEPROM.write(2, 255);
        EEPROM.commit();
        delay(retardo);
         state1 = 11;
      }
      break;
    case OFF:
      tira.clear();
      tira.show();
      break;
    case 10:
      for (int i = 0; i < nleds; i++) {
        tira.setPixelColor(i, g, r, b);
      }

      tira.show();
      EEPROM.write(0, r);
      EEPROM.write(1, g);
      EEPROM.write(2, b);
      EEPROM.commit();
      delay(retardo);
      break;
    /*case 11:
      r_anterior = EEPROM.read(0);
      g_anterior = EEPROM.read(1);
      b_anterior = EEPROM.read(2);

      for (int i = 0; i < nleds; i++) {
        tira.setPixelColor(i, g_anterior, r_anterior, b_anterior);
      }
      tira.show();
      delay(retardo);
      break;*/
    default: break;
  }
}

void controlLUZ(){
  switch(state1){
    case 11:
      r_anterior = EEPROM.read(0);
      g_anterior = EEPROM.read(1);
      b_anterior = EEPROM.read(2);

      for (int i = 0; i < nleds; i++) {
        tira.setPixelColor(i, g_anterior, r_anterior, b_anterior);
      }
      tira.show();
      delay(retardo);
      break;
    default: break;
  }
}

void FSM_Modo() {
  switch (anterior) {
    case S_OFF:
      state--;
      state = state % 4;
      anterior = S_SEQ;
      delay(200);
      break;
    case S_SEQ:
      state1 = 11;
      anterior = S_OFF;
      delay(300);
      break;
  }
}