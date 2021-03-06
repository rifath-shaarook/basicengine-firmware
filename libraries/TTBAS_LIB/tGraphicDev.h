//
// 豊四季Tiny BASIC for Arduino STM32 グラフィック描画デバイス
// 2017/07/19 by たま吉さん
//

#ifndef __tGraphicDev_h__
#define __tGraphicDev_h__

#include "../../ttbasic/ttconfig.h"

#include <Arduino.h>

const uint8_t* tv_getFontAdr() ;

class tGraphicDev {
  protected:
    uint16_t gwidth;             // スクリーングラフィック横サイズ
    uint16_t gheight;            // スクリーングラフィック縦サイズ

  public:
     void  init();
    inline const uint8_t *getfontadr() { return tv_getFontAdr()+3; };   // フォントアドレスの参照
    virtual uint16_t getGWidth();       // グラフックスクリーン横幅取得
    virtual uint16_t getGHeight();      // グラフックスクリーン縦幅取得

    // グラフィック描画
    virtual void pset(int16_t x, int16_t y, uint8_t c);
    virtual void line(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t c);
    virtual void circle(int16_t x, int16_t y, int16_t r, uint8_t c, int8_t f);
    virtual void rect(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t c, int8_t f);
    //virtual void cscroll(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t d);
    virtual void gscroll(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t mode);
    virtual void set_gcursor(uint16_t, uint16_t);
    virtual void gputch(uint8_t c);

};

#endif

