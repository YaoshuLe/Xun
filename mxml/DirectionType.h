#ifndef DIRECTION_TYPE_H
#define DIRECTION_TYPE_H
#include "Element.h"

namespace mxml
{
  class Rehearsal;
  using RehearsalPtr = std::shared_ptr<Rehearsal>;
  using RehearsalSet = std::vector<RehearsalPtr>;
  class Segno;
  using SegnoPtr = std::shared_ptr<Segno>;
  using SegnoSet = std::vector<SegnoPtr>;
  class Words;
  using WordsPtr = std::shared_ptr<Words>;
  using WordsSet = std::vector<WordsPtr>;
  class Coda;
  using CodaPtr = std::shared_ptr<Coda>;
  using CodaSet = std::vector<CodaPtr>;
  class Wedge;
  using WedgePtr = std::shared_ptr<Wedge>;
  class Dynamics;
  using DynamicsPtr = std::shared_ptr<Dynamics>;
  using DynamicsSet = std::vector<DynamicsPtr>;
  class Dashes;
  using DashesPtr = std::shared_ptr<Dashes>;
  class Bracket;
  using BracketPtr = std::shared_ptr<Bracket>;
  class Pedal;
  using PedalPtr = std::shared_ptr<Pedal>;
  //class Metronome;
  //using MetronomePtr = std::shared_ptr<Metronome>;
  class OctaveShift;
  using OctaveShiftPtr = std::shared_ptr<OctaveShift>;
  class HarpPedals;
  using HarpPedalsPtr = std::shared_ptr<HarpPedals>;
  class Damp;
  using DampPtr = std::shared_ptr<Damp>;
  class DampAll;
  using DampAllPtr = std::shared_ptr<DampAll>;
  class Eyeglasses;
  using EyeglassesPtr = std::shared_ptr<Eyeglasses>;
  class StringMute;
  using StringMutePtr = std::shared_ptr<StringMute>;
  class Scordatura;
  using ScordaturaPtr = std::shared_ptr<Scordatura>;
  class Image;
  using ImagePtr = std::shared_ptr<Image>;
  class PrincipalVoice;
  using PrincipalVoicePtr = std::shared_ptr<PrincipalVoice>;
  class AccordionRegistration;
  using AccordionRegistrationPtr = std::shared_ptr<AccordionRegistration>;
  class Percussion;
  using PercussionPtr = std::shared_ptr<Percussion>;
  using PercussionSet = std::vector<PercussionPtr>;
  class OtherDirection;
  using OtherDirectionPtr = std::shared_ptr<OtherDirection>;

  class DirectionType: public Element
  {
  public:
    DirectionType();
    virtual const char* tagname() const { return "direction-type"; }
    const RehearsalSet& getRehearsalSet() const;
    void removeRehearsal(const RehearsalPtr& value);
    void addRehearsal(const RehearsalPtr& value);
    void clearRehearsalSet();
    const SegnoSet& getSegnoSet() const;
    void removeSegno(const SegnoPtr& value);
    void addSegno(const SegnoPtr& value);
    void clearSegnoSet();
    const WordsSet& getWordsSet() const;
    void removeWords(const WordsPtr& value);
    void addWords(const WordsPtr& value);
    void clearWordsSet();
    const CodaSet& getCodaSet() const;
    void removeCoda(const CodaPtr& value);
    void addCoda(const CodaPtr& value);
    void clearCodaSet();
    WedgePtr getWedge() const;
    void setWedge(const WedgePtr& value);
    const DynamicsSet& getDynamicsSet() const;
    void removeDynamics(const DynamicsPtr& value);
    void addDynamics(const DynamicsPtr& value);
    void clearDynamicsSet();
    DashesPtr getDashes() const;
    void setDashes(const DashesPtr& value);
    BracketPtr getBracket() const;
    void setBracket(const BracketPtr& value);
    PedalPtr getPedal() const;
    void setPedal(const PedalPtr& value);
    //MetronomePtr getMetronome() const;
    //void setMetronome(const MetronomePtr& value);
    OctaveShiftPtr getOctaveShift() const;
    void setOctaveShift(const OctaveShiftPtr& value);
    HarpPedalsPtr getHarpPedals() const;
    void setHarpPedals(const HarpPedalsPtr& value);
    DampPtr getDamp() const;
    void setDamp(const DampPtr& value);
    DampAllPtr getDampAll() const;
    void setDampAll(const DampAllPtr& value);
    EyeglassesPtr getEyeglasses() const;
    void setEyeglasses(const EyeglassesPtr& value);
    StringMutePtr getStringMute() const;
    void setStringMute(const StringMutePtr& value);
    ScordaturaPtr getScordatura() const;
    void setScordatura(const ScordaturaPtr& value);
    ImagePtr getImage() const;
    void setImage(const ImagePtr& value);
    PrincipalVoicePtr getPrincipalVoice() const;
    void setPrincipalVoice(const PrincipalVoicePtr& value);
    AccordionRegistrationPtr getAccordionRegistration() const;
    void setAccordionRegistration(const AccordionRegistrationPtr& value);
    const PercussionSet& getPercussionSet() const;
    void removePercussion(const PercussionPtr& value);
    void addPercussion(const PercussionPtr& value);
    void clearPercussionSet();
    OtherDirectionPtr getOtherDirection() const;
    void setOtherDirection(const OtherDirectionPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    RehearsalSet _rehearsalSet;
    SegnoSet _segnoSet;
    WordsSet _wordsSet;
    CodaSet _codaSet;
    WedgePtr _wedgePtr;
    DynamicsSet _dynamicsSet;
    DashesPtr _dashesPtr;
    BracketPtr _bracketPtr;
    PedalPtr _pedalPtr;
    //MetronomePtr _metronomePtr;
    OctaveShiftPtr _octaveShiftPtr;
    HarpPedalsPtr _harpPedalsPtr;
    DampPtr _dampPtr;
    DampAllPtr _dampAllPtr;
    EyeglassesPtr _eyeglassesPtr;
    StringMutePtr _stringMutePtr;
    ScordaturaPtr _scordaturaPtr;
    ImagePtr _imagePtr;
    PrincipalVoicePtr _principalVoicePtr;
    AccordionRegistrationPtr _accordionRegistrationPtr;
    PercussionSet _percussionSet;
    OtherDirectionPtr _otherDirectionPtr;
  };
}
#endif //DIRECTION_TYPE_H
