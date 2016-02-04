#define BTN1 2
#define BTN2 3
#define BTN3 4
#define BTN4 5
#define BTN5 6
#define BTN6 7
#define BTN7 8
#define BTN8 9

int val[7] = {0, 0, 0, 0, 0, 0, 0};
int lastVal[7] = {0, 0, 0, 0, 0, 0, 0};
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
  val[btn-2] = digitalRead(btn);

  if (val[btn-2] == 1 && lastVal[btn-2] == 0) {
    if (mode == 0) {
      hotkeyCtrl(btn+7);
    }
    else if (mode == 1) {
      hotkeyCtrl(btn + 14+7);
    }
    else if (mode == 2) {
      hotkeyCtrl(0);
    }
    else if (mode == 3) {
      hotkeyCtrl(btn + 35+7);
    }
    else {
      hotkeyCtrl(0);
    }
  }
  else if (val[btn-2] == 0 && lastVal[btn-2] == 1) {
    if (mode == 0) {
      hotkeyCtrl(btn);
    }
    else if (mode == 1) {
      hotkeyCtrl(btn + 14);
    }
    else if (mode == 2) {
      hotkeyCtrl(btn + 28);
    }
    else if (mode == 3) {
      hotkeyCtrl(btn + 35);
    }
    else {
      hotkeyCtrl(0);
    }
  }
  else
  {
    hotkeyCtrl(0);
  }
  lastVal[btn-2] = val[btn-2];
}

//Function to cycle through the different modes with a btn
void nextMode(int btn) {
  val[btn-2] = digitalRead(btn);

  if (val[btn] == 1 && lastVal[btn] == 0) {
    hotkeyCtrl(0);
  }
  else if (val[btn-2] == 0 && lastVal[btn-2] == 1) {
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
    hotkeyCtrl(0);
  }
  lastVal[btn-2] = val[btn-2];
}

//CASE-structure to send each keycombination
void hotkeyCtrl(int state) {
  switch (state) {
    //Commands for WINAMP
    case 2:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('z');
      Serial.println("rev");
      delay(100);
      break;
    case 3:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_PAGE_UP);
      Serial.println("vol+");
      delay(100);
      break;
    case 4:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_PAGE_DOWN);
      Serial.println("vol+");
      delay(100);
      break;
    case 5:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('b');
      Serial.println("ffw");
      delay(100);
      break;
    case 6:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('c');
      Serial.println("pause");
      delay(100);
      break;
    case 7:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('x');
      Serial.println("play");
      delay(100);
      break;
    case 8:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('v');
      Serial.println("stop");
      delay(100);
      break;
      
    case 9:
      Keyboard.release(KEY_LEFT_CTRL);
      Keyboard.release(KEY_LEFT_SHIFT);
      Keyboard.release('z');
      Serial.println("rev2");
      break;
    case 10:
      Keyboard.release(KEY_LEFT_CTRL);
      Keyboard.release(KEY_LEFT_SHIFT);
      Keyboard.release(KEY_PAGE_UP);
      Serial.println("vol+2");
      break;
    case 11:
      Keyboard.release(KEY_LEFT_CTRL);
      Keyboard.release(KEY_LEFT_SHIFT);
      Keyboard.release(KEY_PAGE_DOWN);
      Serial.println("vol-2");
      break;
    case 12:
      Keyboard.release(KEY_LEFT_CTRL);
      Keyboard.release(KEY_LEFT_SHIFT);
      Keyboard.release('b');
      Serial.println("ffw2");
      break;
    case 13:
      Keyboard.release(KEY_LEFT_CTRL);
      Keyboard.release(KEY_LEFT_SHIFT);
      Keyboard.release('c');
      Serial.println("pause2");
      break;
    case 14:
      Keyboard.release(KEY_LEFT_CTRL);
      Keyboard.release(KEY_LEFT_SHIFT);
      Keyboard.release('x');
      Serial.println("play2");
      break;
    case 15:
      Keyboard.release(KEY_LEFT_CTRL);
      Keyboard.release(KEY_LEFT_SHIFT);
      Keyboard.release('v');
      Serial.println("stop2");
      break;

    //Commands for "Sunless Sea"
    case 16:
      Keyboard.press('a');
      Serial.println("left");
      delay(100);
      break;
    case 17:
      Keyboard.press('w');
      Serial.println("power+");
      delay(100);
      break;
    case 18:
      Keyboard.press('s');
      Serial.println("power-");
      delay(100);
      break;
    case 19:
      Keyboard.press('d');
      Serial.println("right");
      delay(100);
      break;
    case 20:
      Keyboard.press('1');
      Serial.println("fire");
      delay(100);
      break;
    case 21:
      Keyboard.press('l');
      Serial.println("lights");
      delay(100);
      break;
    case 22:
      Keyboard.press('g');
      Serial.println("journal");
      delay(100);
      break;
      
    case 23:
      Keyboard.release('a');
      break;
    case 24:
      Keyboard.release('w');
      break;
    case 25:
      Keyboard.release('s');
      break;
    case 26:
      Keyboard.release('d');
      break;
    case 27:
      Keyboard.release('1');
      break;
    case 28:
      Keyboard.release('l');
      break;
    case 29:
      Keyboard.release('g');
      break;

       //Commands for "Inkscape"
    case 30:
      Keyboard.press(KEY_F5);
      Serial.println("Circles");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 31:
      Keyboard.press(KEY_F8);
      Serial.println("Text");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 32:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_F6);
      Serial.println("Lines");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 33:
      Keyboard.press(KEY_F4);
      Serial.println("Squares");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 34:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('f');
      Serial.println("Fill & stroke");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 35:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('l');
      Serial.println("layers");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 36:
      Keyboard.press(KEY_ESC);
      Serial.println("Return to canvas");
      delay(100);
      Keyboard.releaseAll();
      break;

    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
}
