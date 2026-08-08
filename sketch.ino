#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

String menu[] = {
  "Music",
  "Movies",
  "Files",
  "Settings"
};

int selected = 0;

void drawMenu() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(25,0);
  display.println("CYBERDECK");

  for(int i=0;i<4;i++){

    display.setCursor(0,16+i*12);

    if(i==selected)
      display.print("> ");
    else
      display.print("  ");

    display.println(menu[i]);

  }

  display.display();
}

void setup() {

  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC,0x3C);

  drawMenu();

}

void loop() {

  if(digitalRead(2)==LOW){

    selected--;

    if(selected<0)
      selected=3;

    drawMenu();

    delay(200);

  }

  if(digitalRead(3)==LOW){

    selected++;

    if(selected>3)
      selected=0;

    drawMenu();

    delay(200);

  }

}