#include "BendSound.h"
#include <cstring>

namespace mxml
{
  BendSound::BendSound() {}
  bool BendSound::hasAccelerate() const { return _hasAccelerate; }
  void BendSound::hasAccelerate(bool value) { _hasAccelerate = value; }
  YesNoEnum BendSound::accelerate() const { return _accelerate; }
  void BendSound::accelerate(YesNoEnum value) { _accelerate = value; }
  bool BendSound::hasBeats() const { return _hasBeats; }
  void BendSound::hasBeats(bool value) { _hasBeats = value; }
  float BendSound::beats() const { return _beats; }
  void BendSound::beats(float value) { _beats = value; }
  bool BendSound::hasFirstBeat() const { return _hasFirstBeat; }
  void BendSound::hasFirstBeat(bool value) { _hasFirstBeat = value; }
  float BendSound::firstBeat() const { return _firstBeat; }
  void BendSound::firstBeat(float value) { _firstBeat = value; }
  bool BendSound::hasLastBeat() const { return _hasLastBeat; }
  void BendSound::hasLastBeat(bool value) { _hasLastBeat = value; }
  float BendSound::lastBeat() const { return _lastBeat; }
  void BendSound::lastBeat(float value) { _lastBeat = value; }

  void BendSound::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasAccelerate) {
      self.append_attribute("accelerate").set_value(_accelerate.operator const char *());
    }
    if(_hasBeats) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _beats);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("beats").set_value(str);
    }
    if(_hasFirstBeat) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _firstBeat);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("first-beat").set_value(str);
    }
    if(_hasLastBeat) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _lastBeat);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("last-beat").set_value(str);
    }
  }
  void BendSound::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("accelerate")) {
      _accelerate = YesNoEnum(attr.as_string());
      _hasAccelerate = true;
    }
    if(auto attr = self.attribute("beats")) {
      _beats = attr.as_float();
      _hasBeats = true;
    }
    if(auto attr = self.attribute("first-beat")) {
      _firstBeat = attr.as_float();
      _hasFirstBeat = true;
    }
    if(auto attr = self.attribute("last-beat")) {
      _lastBeat = attr.as_float();
      _hasLastBeat = true;
    }
  }
}
