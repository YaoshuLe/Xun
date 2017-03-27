#ifndef SOUND_H
#define SOUND_H
#include "Element.h"

namespace mxml
{
  class MidiInfo;
  using MidiInfoPtr = std::shared_ptr<MidiInfo>;
  using MidiInfoSet = std::vector<MidiInfoPtr>;
  class Offset;
  using OffsetPtr = std::shared_ptr<Offset>;

  class Sound: public Element
  {
  public:
    Sound();
    virtual const char* tagname() const { return "sound"; }
    const MidiInfoSet& getMidiInfoSet() const;
    void removeMidiInfo(const MidiInfoPtr& value);
    void addMidiInfo(const MidiInfoPtr& value);
    void clearMidiInfoSet();
    OffsetPtr getOffset() const;
    void setOffset(const OffsetPtr& value);
    bool hasTempo() const;
    void hasTempo(bool value);
    float tempo() const;
    void tempo(float value);
    bool hasDynamics() const;
    void hasDynamics(bool value);
    float dynamics() const;
    void dynamics(float value);
    bool hasDacapo() const;
    void hasDacapo(bool value);
    YesNoEnum dacapo() const;
    void dacapo(YesNoEnum value);
    bool hasSegno() const;
    void hasSegno(bool value);
    std::string segno() const;
    void segno(std::string value);
    bool hasDalsegno() const;
    void hasDalsegno(bool value);
    std::string dalsegno() const;
    void dalsegno(std::string value);
    bool hasCoda() const;
    void hasCoda(bool value);
    std::string coda() const;
    void coda(std::string value);
    bool hasTocoda() const;
    void hasTocoda(bool value);
    std::string tocoda() const;
    void tocoda(std::string value);
    bool hasDivisions() const;
    void hasDivisions(bool value);
    float divisions() const;
    void divisions(float value);
    bool hasForwardRepeat() const;
    void hasForwardRepeat(bool value);
    YesNoEnum forwardRepeat() const;
    void forwardRepeat(YesNoEnum value);
    bool hasFine() const;
    void hasFine(bool value);
    std::string fine() const;
    void fine(std::string value);
    bool hasTimeOnly() const;
    void hasTimeOnly(bool value);
    std::string timeOnly() const;
    void timeOnly(std::string value);
    bool hasPizzicato() const;
    void hasPizzicato(bool value);
    YesNoEnum pizzicato() const;
    void pizzicato(YesNoEnum value);
    bool hasPan() const;
    void hasPan(bool value);
    float pan() const;
    void pan(float value);
    bool hasElevation() const;
    void hasElevation(bool value);
    float elevation() const;
    void elevation(float value);
    bool hasDamperPedal() const;
    void hasDamperPedal(bool value);
    YesNoNumberEnum damperPedal() const;
    void damperPedal(YesNoNumberEnum value);
    bool hasSoftPedal() const;
    void hasSoftPedal(bool value);
    YesNoNumberEnum softPedal() const;
    void softPedal(YesNoNumberEnum value);
    bool hasSostenutoPedal() const;
    void hasSostenutoPedal(bool value);
    YesNoNumberEnum sostenutoPedal() const;
    void sostenutoPedal(YesNoNumberEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    MidiInfoSet _midiInfoSet;
    OffsetPtr _offsetPtr;
    bool _hasTempo {false};
    float _tempo;
    bool _hasDynamics {false};
    float _dynamics;
    bool _hasDacapo {false};
    YesNoEnum _dacapo;
    bool _hasSegno {false};
    std::string _segno;
    bool _hasDalsegno {false};
    std::string _dalsegno;
    bool _hasCoda {false};
    std::string _coda;
    bool _hasTocoda {false};
    std::string _tocoda;
    bool _hasDivisions {false};
    float _divisions;
    bool _hasForwardRepeat {false};
    YesNoEnum _forwardRepeat;
    bool _hasFine {false};
    std::string _fine;
    bool _hasTimeOnly {false};
    std::string _timeOnly;
    bool _hasPizzicato {false};
    YesNoEnum _pizzicato;
    bool _hasPan {false};
    float _pan;
    bool _hasElevation {false};
    float _elevation;
    bool _hasDamperPedal {false};
    YesNoNumberEnum _damperPedal;
    bool _hasSoftPedal {false};
    YesNoNumberEnum _softPedal;
    bool _hasSostenutoPedal {false};
    YesNoNumberEnum _sostenutoPedal;
  };
}
#endif //SOUND_H
