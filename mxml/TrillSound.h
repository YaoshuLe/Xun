#ifndef TRILL_SOUND_H
#define TRILL_SOUND_H
#include "AttrGroup.h"

namespace mxml
{
  class TrillSound: public AttrGroup
  {
  public:
    TrillSound();
    bool hasStartNote() const;
    void hasStartNote(bool value);
    StartNoteEnum startNote() const;
    void startNote(StartNoteEnum value);
    bool hasTrillStep() const;
    void hasTrillStep(bool value);
    TrillStepEnum trillStep() const;
    void trillStep(TrillStepEnum value);
    bool hasTwoNoteTurn() const;
    void hasTwoNoteTurn(bool value);
    TwoNoteTurnEnum twoNoteTurn() const;
    void twoNoteTurn(TwoNoteTurnEnum value);
    bool hasAccelerate() const;
    void hasAccelerate(bool value);
    YesNoEnum accelerate() const;
    void accelerate(YesNoEnum value);
    bool hasBeats() const;
    void hasBeats(bool value);
    float beats() const;
    void beats(float value);
    bool hasSecondBeat() const;
    void hasSecondBeat(bool value);
    float secondBeat() const;
    void secondBeat(float value);
    bool hasLastBeat() const;
    void hasLastBeat(bool value);
    float lastBeat() const;
    void lastBeat(float value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasStartNote {false};
    StartNoteEnum _startNote;
    bool _hasTrillStep {false};
    TrillStepEnum _trillStep;
    bool _hasTwoNoteTurn {false};
    TwoNoteTurnEnum _twoNoteTurn;
    bool _hasAccelerate {false};
    YesNoEnum _accelerate;
    bool _hasBeats {false};
    float _beats;
    bool _hasSecondBeat {false};
    float _secondBeat;
    bool _hasLastBeat {false};
    float _lastBeat;
  };
}
#endif //TRILL_SOUND_H
