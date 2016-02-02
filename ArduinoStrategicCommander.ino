#define BTN1 2
#define BTN2 3
#define BTN3 4
#define BTN4 5
#define BTN5 6
#define BTN6 7
#define BTN7 8
#define BTN8 9

int val[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int lastVal[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int mode = 0;
int amountOfModes = 3;

void setup() {
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(BTN4, INPUT_PULLUP);
  pinMode(BTN5, INPUT_PULLUP);
  pinMode(BTN6, INPUT_PULLUP);
  pinMode(BTN7, INPUT_PULLUP);
  pinMode(BTN8, INPUT_PULLUP);
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  for (int i = 2; i <= 8; i++) {
    clickBtn(i);
  }
  nextMode(BTN8);
}

//Function to check each btn
void clickBtn(int btn) {
  val[btn] = digitalRead(btn);

  if (val[btn] == 1 && lastVal[btn] == 0) {
    winampCtrl(0);
  }
  else if (val[btn] == 0 && lastVal[btn] == 1) {
    if (mode == 0) {
      winampCtrl(btn);
    }
    else if (mode == 1) {
      winampCtrl(btn + 8);
    }
    else if (mode == 2) {
      winampCtrl(btn + 16);
    }
    else if (mode == 3) {
      winampCtrl(btn + 24);
    }
    else {
      winampCtrl(0);
    }
  }
  else
  {
    winampCtrl(0);
  }
  lastVal[btn] = val[btn];
}

//Function to cycle through the different modes with a btn
void nextMode(int btn) {
  val[btn] = digitalRead(btn);

  if (val[btn] == 1 && lastVal[btn] == 0) {
    winampCtrl(0);
  }
  else if (val[btn] == 0 && lastVal[btn] == 1) {
    if (mode < (amountOfModes - 1)) {
      mode++;
      Serial.print("Mode = ");
      Serial.println(mode);
      delay(200);
    }
    else {
      mode = 0;
      Serial.print("Mode = ");
      Serial.println(mode);
      delay(200);
    }
  }
  else
  {
    winampCtrl(0);
  }
  lastVal[btn] = val[btn];
}

//CASE-structure to send each keycombination
void winampCtrl(int state) {
  switch (state) {
    //Commands for WINAMP
    case 2:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('z');
      Serial.println("rev");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 3:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_PAGE_UP);
      Serial.println("vol+");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 4:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_PAGE_DOWN);
      Serial.println("vol-");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 5:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('b');
      Serial.println("ffw");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 6:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('c');
      Serial.println("pause");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 7:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('x');
      Serial.println("play");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 8:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('v');
      Serial.println("stop");
      delay(100);
      Keyboard.releaseAll();
      break;

    //Commands for "a sunless sea"
    case 10:
      Keyboard.press('a');
      Serial.println("Steer left");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 11:
      Keyboard.press('w');
      Serial.println("Power+");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 12:
      Keyboard.press('s');
      Serial.println("Power-");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 13:
      Keyboard.press('d');
      Serial.println("Steer right");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 14:
      Keyboard.press('1');
      Serial.println("Fire");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 15:
      Keyboard.press('l');
      Serial.println("Toggle lights");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 16:
      Keyboard.press('g');
      Serial.println("Open journal");
      delay(100);
      Keyboard.releaseAll();
      break;

    //Commands for "Inkscape"
    case 18:
      Keyboard.press(KEY_F5);
      Serial.println("Circles");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 19:
      Keyboard.press(KEY_F8);
      Serial.println("Text");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 20:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_F6);
      Serial.println("Lines");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 21:
      Keyboard.press(KEY_F4);
      Serial.println("Squares");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 22:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('f');
      Serial.println("Fill & stroke");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 23:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('l');
      Serial.println("layers");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 24:
      Keyboard.press(KEY_ESC);
      Serial.println("Return to canvas");
      delay(100);
      Keyboard.releaseAll();
      break;

    //Commands for "OpenSCAD"
    case 26:
      Keyboard.print("sphere(radius | d=diameter)");
      Serial.println("Sphere");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 27:
      Keyboard.print("translate([x,y,z])");
      Serial.println("Translate");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 28:
      Keyboard.print("cylinder(h,r1|d1,r2|d2,center)");
      Serial.println("Cylinder");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 29:
      Keyboard.print("cube([width,depth,height], center)");
      Serial.println("Cube");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 30:
      Keyboard.print("union()");
      Serial.println("Union");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 31:
      Keyboard.print("difference()");
      Serial.println("Difference");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 32:
      Keyboard.print("intersection()");
      Serial.println("Intersection");
      delay(100);
      Keyboard.releaseAll();
      break;

    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
}
