#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define BTN_UP     2
#define BTN_DOWN   3
#define BTN_SELECT 4
#define BTN_BACK   5

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

String menu[] = {
  "MUSIC",
  "MOVIES",
  "FILES",
  "SETTINGS"
};

int selected = 0;

enum Screen {
  MAIN_MENU,
  MUSIC_SCREEN,
  MOVIES_SCREEN,
  FILES_SCREEN,
  SETTINGS_SCREEN
};

Screen currentScreen = MAIN_MENU;


// ----------------------------
// Draw main menu
// ----------------------------

void drawMainMenu() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(35, 0);
  display.println("CYBERDECK");

  display.drawLine(0, 9, 127, 9, WHITE);

  for (int i = 0; i < 4; i++) {

    display.setCursor(5, 15 + i * 11);

    if (i == selected) {
      display.print("> ");
    } else {
      display.print("  ");
    }

    display.println(menu[i]);
  }

  display.display();
}


// ----------------------------
// Draw individual screens
// ----------------------------

void drawScreen() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);

  if (currentScreen == MUSIC_SCREEN) {

    display.setCursor(35, 5);
    display.println("MUSIC");

    display.setCursor(10, 25);
    display.println("No music loaded");

    display.setCursor(10, 45);
    display.println("< BACK");

  }

  else if (currentScreen == MOVIES_SCREEN) {

    display.setCursor(32, 5);
    display.println("MOVIES");

    display.setCursor(10, 25);
    display.println("No movies loaded");

    display.setCursor(10, 45);
    display.println("< BACK");

  }

  else if (currentScreen == FILES_SCREEN) {

    display.setCursor(35, 5);
    display.println("FILES");

    display.setCursor(10, 25);
    display.println("Storage empty");

    display.setCursor(10, 45);
    display.println("< BACK");

  }

  else if (currentScreen == SETTINGS_SCREEN) {

    display.setCursor(27, 5);
    display.println("SETTINGS");

    display.setCursor(10, 25);
    display.println("Volume: 70%");

    display.setCursor(10, 45);
    display.println("< BACK");

  }

  display.display();
}


// ----------------------------
// Setup
// ----------------------------

void setup() {

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_SELECT, INPUT_PULLUP);
  pinMode(BTN_BACK, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  drawMainMenu();
}


// ----------------------------
// Main loop
// ----------------------------

void loop() {

  // MAIN MENU
  if (currentScreen == MAIN_MENU) {

    // UP
    if (digitalRead(BTN_UP) == LOW) {

      selected--;

      if (selected < 0)
        selected = 3;

      drawMainMenu();

      delay(200);
    }


    // DOWN
    if (digitalRead(BTN_DOWN) == LOW) {

      selected++;

      if (selected > 3)
        selected = 0;

      drawMainMenu();

      delay(200);
    }


    // SELECT
    if (digitalRead(BTN_SELECT) == LOW) {

      if (selected == 0)
        currentScreen = MUSIC_SCREEN;

      else if (selected == 1)
        currentScreen = MOVIES_SCREEN;

      else if (selected == 2)
        currentScreen = FILES_SCREEN;

      else if (selected == 3)
        currentScreen = SETTINGS_SCREEN;

      drawScreen();

      delay(200);
    }
  }


  // SUB-SCREENS

  else {

    if (digitalRead(BTN_BACK) == LOW) {

      currentScreen = MAIN_MENU;

      drawMainMenu();

      delay(200);
    }
  }
}