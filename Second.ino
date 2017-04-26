void rainbow() {
  float di = 5;
  for (int i = 0; i < floor(2000 / di); i++) {
    for (int j = 0; j < 40; j++) {
      for (int z = 0; z < 7; z++) {
        pixel(z, j, colorCode(int(floor((i + j) * di)) % 765));
      }
    }
    if (i % 2) {
      Update();
    }
  }
}

uint16_t colorCode (int code) {
  int r = 0;
  int g = 0;
  int b = 255;
  if (code >= 255) {
    r = 255;
    b = 0;
    if (code >= 510) {
      r = 0;
      g = 255;
      if (code >= 765) {
        b = 255;
        g = 0;
      }
    } else {
      for (int i = 0; i < (code - 255); i++) {
        r -= 1;
        g += 1;
      }
    }
  } else {
    for (int i = 0; i < code; i++) {
      r += 1;
      b -= 1;
    }
  }
  return matrix.Color(r, g, b);
}

void print_words(char phrase[], uint16_t color) {
  // words
}

void Update () {
  matrix.show();
  matrix2.show();
}

void pixel (int x, int y, uint16_t color) {
  matrix.drawPixel(x, y, color);
  matrix2.drawPixel(x, y, color);
}

