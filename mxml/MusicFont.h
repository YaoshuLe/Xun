#ifndef MUSIC_FONT_H
#define MUSIC_FONT_H
#include "EmptyFont.h"

namespace mxml
{
  class MusicFont: public EmptyFont
  {
  public:
    virtual const char* tagname() const { return "music-font"; }
  };
}
#endif //MUSIC_FONT_H
