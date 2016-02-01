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

void clickBtn(int btn) {
  val[btn] = digitalRead(btn);

  if (val[btn] == 1 && lastVal[btn] == 0) {
    winampCtrl(0);
  }
  else if (val[btn] == 0 && lastVal[btn] == 1) {
    if(mode == 0){
       winampCtrl(btn);
    }
    else if(mode == 1){
       winampCtrl(btn+8);
    }
    else if(mode == 2){
       winampCtrl(btn+16);
    }
    else{
       winampCtrl(0);
    }
  }
  else
  {
    winampCtrl(0);
  }
  lastVal[btn] = val[btn];
}

void nextMode(int btn) {
  val[btn] = digitalRead(btn);

  if (val[btn] == 1 && lastVal[btn] == 0) {
    winampCtrl(0);
  }
  else if (val[btn] == 0 && lastVal[btn] == 1) {
    if(mode<1){
      mode++;
    }
    else{
      mode = 0;  
    }
  }
  else
  {
    winampCtrl(0);
  }
  lastVal[btn] = val[btn];
}

void winampCtrl(int state) {
  switch (state) {
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
      Keyboard.press('x');
      Serial.println("play");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 4:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('c');
      Serial.println("pause");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 5:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('v');
      Serial.println("stop");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 6:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('b');
      Serial.println("ffw");
      delay(100);
      Keyboard.releaseAll();
      break;
    case 7:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('b');
      delay(100);
      Keyboard.releaseAll();
      break;
    case 8:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('b');
      Serial.println("vol-");
      delay(100);
      Keyboard.releaseAll();
      break;
      
    case 10:
      Keyboard.press('a');
      delay(100);
      Keyboard.releaseAll();
      break;
    case 11:
      Keyboard.press('w');
      delay(100);
      Keyboard.releaseAll();
      break;
    case 12:
      Keyboard.press('d');
      delay(100);
      Keyboard.releaseAll();
      break;
    case 13:
      Keyboard.press('s');
      delay(100);
      Keyboard.releaseAll();
      break;
    case 14:
      Keyboard.press('1');
      delay(100);
      Keyboard.releaseAll();
      break;
    case 15:
      Keyboard.press('g');
      delay(100);
      Keyboard.releaseAll();
      break;
    case 16:
      Keyboard.press('h');
      delay(100);
      Keyboard.releaseAll();
      break;
      
    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
}
