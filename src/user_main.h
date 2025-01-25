#include <M5Stack.h>

#define DEFAULT_INDEX 0

struct imageInfo
{
    const char *imagePath;
    int imageWidth;
    int imageHeight;
};

void showLogo(imageInfo imageInfo);
void runModeFix();
void runModeRandom();
