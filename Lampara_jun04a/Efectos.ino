void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < tira.numPixels(); i++) {
    tira.setPixelColor(i, color);
  }
  tira.show();
  delay(wait);
  for (int i = 0; i < tira.numPixels(); i++) {
    tira.setPixelColor(i, 0);
  }
  tira.show();
}

void rainbowCycle(uint8_t wait) {
  for (int i = 0; i < tira.numPixels(); i++) {
    tira.setPixelColor(i, 255, 255, 255);
    tira.show();
    delay(wait);
    tira.setPixelColor(i, 0, 0, 0);
  }
}
void theaterChase(uint32_t color, uint8_t wait) {
  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 3; b++) {
      tira.clear();

      for (int c = b; c < tira.numPixels(); c += 3) {
        tira.setPixelColor(c, color);
      }

      tira.show();
      delay(wait);
    }
  }
}