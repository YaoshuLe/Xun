#ifndef BEND_SOUND_H
#define BEND_SOUND_H
#include "AttrGroup.h"

namespace mxml
{
  class BendSound: public AttrGroup
  {
  public:
    BendSound();
    bool hasAccelerate() const;
    void hasAccelerate(bool value);
    YesNoEnum accelerate() const;
    void accelerate(YesNoEnum value);
    bool hasBeats() const;
    void hasBeats(bool value);
    float beats() const;
    void beats(float value);
    bool hasFirstBeat() const;
    void hasFirstBeat(bool value);
    float firstBeat() const;
    void firstBeat(float value);
    bool hasLastBeat() const;
    void hasLastBeat(bool value);
    float lastBeat() const;
    void lastBeat(float value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasAccelerate {false};
    YesNoEnum _accelerate;
    bool _hasBeats {false};
    float _beats;
    bool _hasFirstBeat {false};
    float _firstBeat;
    bool _hasLastBeat {false};
    float _lastBeat;
  };
}
#endif //BEND_SOUND_H
