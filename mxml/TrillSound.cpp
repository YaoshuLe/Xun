#include "TrillSound.h"
#include <cstring>

namespace mxml
{
  TrillSound::TrillSound() {}
  bool TrillSound::hasStartNote() const { return _hasStartNote; }
  void TrillSound::hasStartNote(bool value) { _hasStartNote = value; }
  StartNoteEnum TrillSound::startNote() const { return _startNote; }
  void TrillSound::startNote(StartNoteEnum value) { _startNote = value; }
  bool TrillSound::hasTrillStep() const { return _hasTrillStep; }
  void TrillSound::hasTrillStep(bool value) { _hasTrillStep = value; }
  TrillStepEnum TrillSound::trillStep() const { return _trillStep; }
  void TrillSound::trillStep(TrillStepEnum value) { _trillStep = value; }
  bool TrillSound::hasTwoNoteTurn() const { return _hasTwoNoteTurn; }
  void TrillSound::hasTwoNoteTurn(bool value) { _hasTwoNoteTurn = value; }
  TwoNoteTurnEnum TrillSound::twoNoteTurn() const { return _twoNoteTurn; }
  void TrillSound::twoNoteTurn(TwoNoteTurnEnum value) { _twoNoteTurn = value; }
  bool TrillSound::hasAccelerate() const { return _hasAccelerate; }
  void TrillSound::hasAccelerate(bool value) { _hasAccelerate = value; }
  YesNoEnum TrillSound::accelerate() const { return _accelerate; }
  void TrillSound::accelerate(YesNoEnum value) { _accelerate = value; }
  bool TrillSound::hasBeats() const { return _hasBeats; }
  void TrillSound::hasBeats(bool value) { _hasBeats = value; }
  float TrillSound::beats() const { return _beats; }
  void TrillSound::beats(float value) { _beats = value; }
  bool TrillSound::hasSecondBeat() const { return _hasSecondBeat; }
  void TrillSound::hasSecondBeat(bool value) { _hasSecondBeat = value; }
  float TrillSound::secondBeat() const { return _secondBeat; }
  void TrillSound::secondBeat(float value) { _secondBeat = value; }
  bool TrillSound::hasLastBeat() const { return _hasLastBeat; }
  void TrillSound::hasLastBeat(bool value) { _hasLastBeat = value; }
  float TrillSound::lastBeat() const { return _lastBeat; }
  void TrillSound::lastBeat(float value) { _lastBeat = value; }

  void TrillSound::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasStartNote) {
      self.append_attribute("start-note").set_value(_startNote.operator const char *());
    }
    if(_hasTrillStep) {
      self.append_attribute("trill-step").set_value(_trillStep.operator const char *());
    }
    if(_hasTwoNoteTurn) {
      self.append_attribute("two-note-turn").set_value(_twoNoteTurn.operator const char *());
    }
    if(_hasAccelerate) {
      self.append_attribute("accelerate").set_value(_accelerate.operator const char *());
    }
    if(_hasBeats) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _beats);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("beats").set_value(str);
    }
    if(_hasSecondBeat) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _secondBeat);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("second-beat").set_value(str);
    }
    if(_hasLastBeat) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _lastBeat);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("last-beat").set_value(str);
    }
  }
  void TrillSound::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("start-note")) {
      _startNote = StartNoteEnum(attr.as_string());
      _hasStartNote = true;
    }
    if(auto attr = self.attribute("trill-step")) {
      _trillStep = TrillStepEnum(attr.as_string());
      _hasTrillStep = true;
    }
    if(auto attr = self.attribute("two-note-turn")) {
      _twoNoteTurn = TwoNoteTurnEnum(attr.as_string());
      _hasTwoNoteTurn = true;
    }
    if(auto attr = self.attribute("accelerate")) {
      _accelerate = YesNoEnum(attr.as_string());
      _hasAccelerate = true;
    }
    if(auto attr = self.attribute("beats")) {
      _beats = attr.as_float();
      _hasBeats = true;
    }
    if(auto attr = self.attribute("second-beat")) {
      _secondBeat = attr.as_float();
      _hasSecondBeat = true;
    }
    if(auto attr = self.attribute("last-beat")) {
      _lastBeat = attr.as_float();
      _hasLastBeat = true;
    }
  }
}
