// partial refresh on 4.2" epaper display driven by Xiao ESP32S3 and EE04 epaper board

// created by upir, 2026
// youtube channel: https://www.youtube.com/upir_upir

// YouTube Video: https://youtu.be/7UocgE-gukA
// Source Files: https://github.com/upiir/seeed_eink_partial_update

// Links from the video:
// Do you like this video? You can buy me a coffee ☕: https://www.buymeacoffee.com/upir
// Seeed Xiao ESP32S3: https://s.click.aliexpress.com/e/_c3NT6SY7
// EE04 epaper board: https://s.click.aliexpress.com/e/_c4aBW9NZ
// 4.2" epaper display: https://www.seeedstudio.com/4-2-Monochrome-ePaper-Display-with-400x300-Pixels-p-5784.html
// Seeed GFX library: https://github.com/Seeed-Studio/Seeed_GFX
// Photopea (online graphics editor like Photoshop): https://www.photopea.com/

// Related videos with epaper/eink displays:
// reTerminal: https://youtu.be/PtaXK2MAQ08
// Arduino YouTube Counter: https://youtu.be/HFFhTrAkerU
// E-ink Project Ideas: https://youtu.be/oAJUBPxjCwk
// Segmented eink: https://youtu.be/Rf-E-7fFop0
// Electrochromatic displays: https://youtu.be/lxeH1ilL2T0


#include "TFT_eSPI.h"
#include "image.h"
#include "positions.h"

#ifdef EPAPER_ENABLE
EPaper epaper;
#endif

void setup()
{
#ifdef EPAPER_ENABLE
  Serial.begin(115200);
  delay(2000);
  Serial.println("4.2\" E-Paper Bitmap Display Example");
  
  epaper.begin();
  
  // Clear screen to white
  epaper.fillScreen(TFT_WHITE);
  epaper.update();
  delay(1000);
  
  // Display bitmap image using drawBitmap API
  // drawBitmap(x, y, bitmap_data, width, height, color)
  epaper.drawBitmap(0, 0, gImage_4inch2, 400, 300, TFT_BLACK);
  epaper.update();
  
  Serial.println("Bitmap displayed successfully");
  
  // Put display to sleep to save power
  epaper.sleep();
#else
  Serial.begin(115200);
  Serial.println("EPAPER_ENABLE not defined. Please select the correct setup file.");
#endif
}

int counter = 0;

void loop()
{

   int circle_xpos = positions[counter][0]; //80 + random(300);
   int circle_ypos = positions[counter][1]; //50 + random(190);

   int circle_radius = 4;
   
   epaper.fillCircle(circle_xpos, circle_ypos, circle_radius, TFT_BLACK);
   epaper.updataPartial(circle_xpos - circle_radius, circle_ypos - circle_radius, 
                        circle_xpos + circle_radius, circle_ypos + circle_radius);

   delay(20);

   counter++;
   if (counter > 500) {counter = 0;}
   
}










