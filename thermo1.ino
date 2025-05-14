#include <AFMotor.h>

#define LINE_BUFFER_LENGTH 512

char STEP = MICROSTEP;

// Initialize steppers for X- and Y-axis using this Arduino pins for the L293D H-bridge
const int stepsPerRevolution = 48;
AF_Stepper myStepperY(stepsPerRevolution, 1);            
AF_Stepper myStepperX(stepsPerRevolution, 2);  

/* Structures, global variables */
struct point { 
  float x; 
  float y; 
};

struct point actuatorPos;

// Drawing settings
float StepInc = 1;
int StepDelay = 1;
int LineDelay = 0;

// Motor steps to go 1 millimeter.
float StepsPerMillimeterX = 100.0;
float StepsPerMillimeterY = 100.0;

// Drawing robot limits, in mm
float Xmin = 0;
float Xmax = 280;
float Ymin = 0;
float Ymax = 280;

float Xpos = Xmin;
float Ypos = Ymin;

// Set to true to get debug output.
boolean verbose = false;

void setup() {
  Serial.begin(9600);

  myStepperX.setSpeed(600);
  myStepperY.setSpeed(600);

  Serial.println("Mini CNC Plotter - ULN2003 Version!");
  Serial.print("X range is from "); 
  Serial.print(Xmin); 
  Serial.print(" to "); 
  Serial.print(Xmax); 
  Serial.println(" mm."); 
  Serial.print("Y range is from "); 
  Serial.print(Ymin); 
  Serial.print(" to "); 
  Serial.print(Ymax); 
  Serial.println(" mm."); 
}

void loop() {
  delay(100);
  char line[LINE_BUFFER_LENGTH];
  char c;
  int lineIndex = 0;
  bool lineIsComment = false, lineSemiColon = false;

  while (1) {
    while (Serial.available() > 0) {
      c = Serial.read();
      if ((c == '\n') || (c == '\r')) {
        if (lineIndex > 0) {
          line[lineIndex] = '\0';
          if (verbose) {
            Serial.print("Received : "); 
            Serial.println(line);
          }
          processIncomingLine(line, lineIndex);
          lineIndex = 0;
        }
        lineIsComment = false;
        lineSemiColon = false;
        Serial.println("ok");
      } else {
        if (lineIsComment || lineSemiColon) {
          if (c == ')') lineIsComment = false;
        } else {
          if (c == '(') lineIsComment = true;
          else if (c == ';') lineSemiColon = true;
          else if (lineIndex < LINE_BUFFER_LENGTH - 1) {
            line[lineIndex++] = c;
          }
        }
      }
    }
  }
}

/*********************************
 * Function to process G-code commands
 *********************************/
void processIncomingLine(char* line, int charNB) {
  int currentIndex = 0;
  char buffer[64];
  struct point newPos;

  newPos.x = actuatorPos.x;
  newPos.y = actuatorPos.y;

  while (currentIndex < charNB) {
    switch (line[currentIndex++]) {
    case 'G':
      buffer[0] = line[currentIndex++];
      buffer[1] = '\0';
      switch (atoi(buffer)) {
      case 0:
      case 1: {
        char* indexX = strchr(line + currentIndex, 'X');
        char* indexY = strchr(line + currentIndex, 'Y');

        if (indexX) newPos.x = atof(indexX + 1);
        if (indexY) newPos.y = atof(indexY + 1);

        drawLine(newPos.x, newPos.y);
        actuatorPos.x = newPos.x;
        actuatorPos.y = newPos.y;
        break;
      }
      }
      break;
    }
  }
}

/*********************************
 * Draw a line from (x0;y0) to (x1;y1).
 **********************************/
void drawLine(float x1, float y1) {
  if (x1 > Xmax) x1 = Xmax;
  if (x1 < Xmin) x1 = Xmin;
  if (y1 > Ymax) y1 = Ymax;
  if (y1 < Ymin) y1 = Ymin;

  x1 = (int)(x1 * StepsPerMillimeterX);
  y1 = (int)(y1 * StepsPerMillimeterY);

  float x0 = Xpos;
  float y0 = Ypos;

  long dx = abs(x1 - x0);
  long dy = abs(y1 - y0);
  int sx = x0 < x1 ? StepInc : -StepInc;
  int sy = y0 < y1 ? StepInc : -StepInc;

  long i;
  long over = 0;

  if (dx > dy) {
    for (i = 0; i < dx; ++i) {
      myStepperX.onestep(sx, STEP);
      over += dy;
      if (over >= dx) {
        over -= dx;
        myStepperY.onestep(sy, STEP);
      }
      delay(StepDelay);
    }
  } else {
    for (i = 0; i < dy; ++i) {
      myStepperY.onestep(sy, STEP);
      over += dx;
      if (over >= dy) {
        over -= dy;
        myStepperX.onestep(sx, STEP);
      }
      delay(StepDelay);
    }
  }
  delay(LineDelay);
  Xpos = x1;
  Ypos = y1;
}
