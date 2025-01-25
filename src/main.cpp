#include <M5Stack.h>
#include <user_main.h>

imageInfo images[] = {
    {"/stmpd_logo.jpg", 240, 240},
    {"/gmo_logo.jpg", 320, 240},
    {"/rose_logo.jpg", 320, 240},
    {"/grx_logo.jpg", 320, 240},
    {"/real_love.jpg", 320, 240},
};

void setup()
{
  M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.setBrightness(50);

  SPIFFS.begin();

  // show default image
  showLogo(images[DEFAULT_INDEX]);
}

int arraySize = sizeof(images) / sizeof(images[0]);
int buttonCount = DEFAULT_INDEX;

void loop()
{
  M5.update();

  if (M5.BtnA.wasPressed())
  {
    buttonCount++;

    M5.Lcd.clearDisplay();
    showLogo(images[buttonCount % arraySize]);
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
    showLogo(images[buttonCount % arraySize]);
  }
}
