#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN             6    /* PIN NUMBER OF "matrix" */
#define PIN2            7    /* PIN NUMBER OF "matrix2" */
#define luminosity      255   /* THE BRIGHTNESS LEVEL OF THE LED's */

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(7, 29, PIN,
                            NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                            NEO_GRB            + NEO_KHZ800);

Adafruit_NeoMatrix matrix2 = Adafruit_NeoMatrix(7, 29, PIN2,
                             NEO_MATRIX_BOTTOM  + NEO_MATRIX_LEFT +
                             NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                             NEO_GRB            + NEO_KHZ800);

/* DECLARES COLORS FOR "matrix" */
const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(60, 125, 255), matrix2.Color(255, 120, 60), matrix.Color(220, 20, 60), matrix.Color(255, 215, 0)
};

/* DECLARES COLORS FOR "matrix2" */
const uint16_t colors2[] = {
  matrix2.Color(255, 0, 0), matrix2.Color(0, 255, 0), matrix2.Color(60, 125, 255), matrix2.Color(255, 120, 60), matrix.Color(220, 20, 60), matrix.Color(255, 215, 0)
};

void setup() {
  Serial.begin(250000);
  matrix.begin();                    /* RESETS ALL THE PIXELS IN "matrix" */
  matrix2.begin();                   /* RESETS ALL THE PIXELS IN "matrix2" */
  matrix.setBrightness(luminosity);  /* SETS BRIGHTNESS FOR "matrix" */
  matrix2.setBrightness(luminosity); /* SETS BRIGTNESS FOR "matrix2" */
  matrix.setTextWrap(false);
  matrix2.setTextWrap(false);
  matrix.show();
  matrix2.show();
}

void loop() {
  rainbow();
  matrix.clear();
  matrix2.clear();
  Update();
  delay(2500);
}
