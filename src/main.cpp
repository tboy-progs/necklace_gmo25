#include <M5Stack.h>
#include <user_main.h>

imageInfo images[] = {
    {"/stmpd_logo.jpg", 240, 240},
    {"/gmo_logo.jpg", 320, 240},
    {"/rose_logo.jpg", 320, 240},
    {"/grx_logo.jpg", 320, 240},
    {"/real_love.jpg", 320, 240},
};

uint8_t brightness[] = {255, 128, 64, 32, 16, 8, 4, 2, 1};

void setup()
{
  M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.setBrightness(brightness[0]);

  SPIFFS.begin();

  // show default image
  showLogo(images[DEFAULT_INDEX]);
}

int imageArraySize = sizeof(images) / sizeof(images[0]);
int buttonCount = DEFAULT_INDEX;

int brightnessIndex = 1;
int brightnessArraySize = sizeof(brightness) / sizeof(brightness[0]);

void loop()
{
  M5.update();

  if (M5.BtnA.wasPressed())
  {
    buttonCount++;

    M5.Lcd.clearDisplay();
    showLogo(images[buttonCount % imageArraySize]);
  }

  if (M5.BtnB.wasPressed())
  {
    brightnessIndex++;

    M5.Lcd.setBrightness(brightness[brightnessIndex % brightnessArraySize]);
  }
}

void showLogo(imageInfo imageInfo)
{
  int x = (m5.Lcd.width() - imageInfo.imageWidth) / 2;
  int y = (m5.Lcd.height() - imageInfo.imageHeight) / 2;

  M5.Lcd.drawJpgFile(SPIFFS, imageInfo.imagePath, x, y);
}

void runModeFix()
{
  M5.update();

  if (M5.BtnA.wasPressed())
  {
    buttonCount++;

    M5.Lcd.clearDisplay();
    showLogo(images[buttonCount % imageArraySize]);
  }
}
