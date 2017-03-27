#include "DirectionType.h"
#include <cstring>
#include "Rehearsal.h"
#include "Segno.h"
#include "Words.h"
#include "Coda.h"
#include "Wedge.h"
#include "Dynamics.h"
#include "Dashes.h"
#include "Bracket.h"
#include "Pedal.h"
//#include "Metronome.h"
#include "OctaveShift.h"
#include "HarpPedals.h"
#include "Damp.h"
#include "DampAll.h"
#include "Eyeglasses.h"
#include "StringMute.h"
#include "Scordatura.h"
#include "Image.h"
#include "PrincipalVoice.h"
#include "AccordionRegistration.h"
#include "Percussion.h"
#include "OtherDirection.h"

namespace mxml
{
  DirectionType::DirectionType() {}
  const RehearsalSet& DirectionType::getRehearsalSet() const {  return _rehearsalSet; }
  void DirectionType::removeRehearsal(const RehearsalPtr& value) { if(value) { auto i = std::find_if(_rehearsalSet.begin(), _rehearsalSet.end(), [&](const RehearsalPtr& item) { return item==value; }); if(i!=_rehearsalSet.end()) _rehearsalSet.erase(i); } } 
  void DirectionType::addRehearsal(const RehearsalPtr& value) { if(value) { _rehearsalSet.push_back(value); value->setParent(shared_from_this()); } }
  void DirectionType::clearRehearsalSet() { _rehearsalSet.clear(); }
  const SegnoSet& DirectionType::getSegnoSet() const {  return _segnoSet; }
  void DirectionType::removeSegno(const SegnoPtr& value) { if(value) { auto i = std::find_if(_segnoSet.begin(), _segnoSet.end(), [&](const SegnoPtr& item) { return item==value; }); if(i!=_segnoSet.end()) _segnoSet.erase(i); } } 
  void DirectionType::addSegno(const SegnoPtr& value) { if(value) { _segnoSet.push_back(value); value->setParent(shared_from_this()); } }
  void DirectionType::clearSegnoSet() { _segnoSet.clear(); }
  const WordsSet& DirectionType::getWordsSet() const {  return _wordsSet; }
  void DirectionType::removeWords(const WordsPtr& value) { if(value) { auto i = std::find_if(_wordsSet.begin(), _wordsSet.end(), [&](const WordsPtr& item) { return item==value; }); if(i!=_wordsSet.end()) _wordsSet.erase(i); } } 
  void DirectionType::addWords(const WordsPtr& value) { if(value) { _wordsSet.push_back(value); value->setParent(shared_from_this()); } }
  void DirectionType::clearWordsSet() { _wordsSet.clear(); }
  const CodaSet& DirectionType::getCodaSet() const {  return _codaSet; }
  void DirectionType::removeCoda(const CodaPtr& value) { if(value) { auto i = std::find_if(_codaSet.begin(), _codaSet.end(), [&](const CodaPtr& item) { return item==value; }); if(i!=_codaSet.end()) _codaSet.erase(i); } } 
  void DirectionType::addCoda(const CodaPtr& value) { if(value) { _codaSet.push_back(value); value->setParent(shared_from_this()); } }
  void DirectionType::clearCodaSet() { _codaSet.clear(); }
  WedgePtr DirectionType::getWedge() const { return _wedgePtr; }
  void DirectionType::setWedge(const WedgePtr& value) { _wedgePtr = value; value->setParent(shared_from_this()); }
  const DynamicsSet& DirectionType::getDynamicsSet() const {  return _dynamicsSet; }
  void DirectionType::removeDynamics(const DynamicsPtr& value) { if(value) { auto i = std::find_if(_dynamicsSet.begin(), _dynamicsSet.end(), [&](const DynamicsPtr& item) { return item==value; }); if(i!=_dynamicsSet.end()) _dynamicsSet.erase(i); } } 
  void DirectionType::addDynamics(const DynamicsPtr& value) { if(value) { _dynamicsSet.push_back(value); value->setParent(shared_from_this()); } }
  void DirectionType::clearDynamicsSet() { _dynamicsSet.clear(); }
  DashesPtr DirectionType::getDashes() const { return _dashesPtr; }
  void DirectionType::setDashes(const DashesPtr& value) { _dashesPtr = value; value->setParent(shared_from_this()); }
  BracketPtr DirectionType::getBracket() const { return _bracketPtr; }
  void DirectionType::setBracket(const BracketPtr& value) { _bracketPtr = value; value->setParent(shared_from_this()); }
  PedalPtr DirectionType::getPedal() const { return _pedalPtr; }
  void DirectionType::setPedal(const PedalPtr& value) { _pedalPtr = value; value->setParent(shared_from_this()); }
  //MetronomePtr DirectionType::getMetronome() const { return _metronomePtr; }
  //void DirectionType::setMetronome(const MetronomePtr& value) { _metronomePtr = value; value->setParent(shared_from_this()); }
  OctaveShiftPtr DirectionType::getOctaveShift() const { return _octaveShiftPtr; }
  void DirectionType::setOctaveShift(const OctaveShiftPtr& value) { _octaveShiftPtr = value; value->setParent(shared_from_this()); }
  HarpPedalsPtr DirectionType::getHarpPedals() const { return _harpPedalsPtr; }
  void DirectionType::setHarpPedals(const HarpPedalsPtr& value) { _harpPedalsPtr = value; value->setParent(shared_from_this()); }
  DampPtr DirectionType::getDamp() const { return _dampPtr; }
  void DirectionType::setDamp(const DampPtr& value) { _dampPtr = value; value->setParent(shared_from_this()); }
  DampAllPtr DirectionType::getDampAll() const { return _dampAllPtr; }
  void DirectionType::setDampAll(const DampAllPtr& value) { _dampAllPtr = value; value->setParent(shared_from_this()); }
  EyeglassesPtr DirectionType::getEyeglasses() const { return _eyeglassesPtr; }
  void DirectionType::setEyeglasses(const EyeglassesPtr& value) { _eyeglassesPtr = value; value->setParent(shared_from_this()); }
  StringMutePtr DirectionType::getStringMute() const { return _stringMutePtr; }
  void DirectionType::setStringMute(const StringMutePtr& value) { _stringMutePtr = value; value->setParent(shared_from_this()); }
  ScordaturaPtr DirectionType::getScordatura() const { return _scordaturaPtr; }
  void DirectionType::setScordatura(const ScordaturaPtr& value) { _scordaturaPtr = value; value->setParent(shared_from_this()); }
  ImagePtr DirectionType::getImage() const { return _imagePtr; }
  void DirectionType::setImage(const ImagePtr& value) { _imagePtr = value; value->setParent(shared_from_this()); }
  PrincipalVoicePtr DirectionType::getPrincipalVoice() const { return _principalVoicePtr; }
  void DirectionType::setPrincipalVoice(const PrincipalVoicePtr& value) { _principalVoicePtr = value; value->setParent(shared_from_this()); }
  AccordionRegistrationPtr DirectionType::getAccordionRegistration() const { return _accordionRegistrationPtr; }
  void DirectionType::setAccordionRegistration(const AccordionRegistrationPtr& value) { _accordionRegistrationPtr = value; value->setParent(shared_from_this()); }
  const PercussionSet& DirectionType::getPercussionSet() const {  return _percussionSet; }
  void DirectionType::removePercussion(const PercussionPtr& value) { if(value) { auto i = std::find_if(_percussionSet.begin(), _percussionSet.end(), [&](const PercussionPtr& item) { return item==value; }); if(i!=_percussionSet.end()) _percussionSet.erase(i); } } 
  void DirectionType::addPercussion(const PercussionPtr& value) { if(value) { _percussionSet.push_back(value); value->setParent(shared_from_this()); } }
  void DirectionType::clearPercussionSet() { _percussionSet.clear(); }
  OtherDirectionPtr DirectionType::getOtherDirection() const { return _otherDirectionPtr; }
  void DirectionType::setOtherDirection(const OtherDirectionPtr& value) { _otherDirectionPtr = value; value->setParent(shared_from_this()); }

  void DirectionType::ostreamContents(pugi::xml_node& self) const
  {
    if(_rehearsalSet.size()>0) {
      for(auto item : _rehearsalSet) {
        auto child = self.append_child("rehearsal");
        item->ostream(child);
      }
    }
    else if(_segnoSet.size()>0) {
      for(auto item : _segnoSet) {
        auto child = self.append_child("segno");
        item->ostream(child);
      }
    }
    else if(_wordsSet.size()>0) {
      for(auto item : _wordsSet) {
        auto child = self.append_child("words");
        item->ostream(child);
      }
    }
    else if(_codaSet.size()>0) {
      for(auto item : _codaSet) {
        auto child = self.append_child("coda");
        item->ostream(child);
      }
    }
    else if(_wedgePtr) {
      auto child = self.append_child("wedge");
      _wedgePtr->ostream(child);
    }
    else if(_dynamicsSet.size()>0) {
      for(auto item : _dynamicsSet) {
        auto child = self.append_child("dynamics");
        item->ostream(child);
      }
    }
    else if(_dashesPtr) {
      auto child = self.append_child("dashes");
      _dashesPtr->ostream(child);
    }
    else if(_bracketPtr) {
      auto child = self.append_child("bracket");
      _bracketPtr->ostream(child);
    }
    else if(_pedalPtr) {
      auto child = self.append_child("pedal");
      _pedalPtr->ostream(child);
    }
    //else if(_metronomePtr) {
      //auto child = self.append_child("metronome");
      //_metronomePtr->ostream(child);
    //}
    else if(_octaveShiftPtr) {
      auto child = self.append_child("octave-shift");
      _octaveShiftPtr->ostream(child);
    }
    else if(_harpPedalsPtr) {
      auto child = self.append_child("harp-pedals");
      _harpPedalsPtr->ostream(child);
    }
    else if(_dampPtr) {
      auto child = self.append_child("damp");
      _dampPtr->ostream(child);
    }
    else if(_dampAllPtr) {
      auto child = self.append_child("damp-all");
      _dampAllPtr->ostream(child);
    }
    else if(_eyeglassesPtr) {
      auto child = self.append_child("eyeglasses");
      _eyeglassesPtr->ostream(child);
    }
    else if(_stringMutePtr) {
      auto child = self.append_child("string-mute");
      _stringMutePtr->ostream(child);
    }
    else if(_scordaturaPtr) {
      auto child = self.append_child("scordatura");
      _scordaturaPtr->ostream(child);
    }
    else if(_imagePtr) {
      auto child = self.append_child("image");
      _imagePtr->ostream(child);
    }
    else if(_principalVoicePtr) {
      auto child = self.append_child("principal-voice");
      _principalVoicePtr->ostream(child);
    }
    else if(_accordionRegistrationPtr) {
      auto child = self.append_child("accordion-registration");
      _accordionRegistrationPtr->ostream(child);
    }
    else if(_percussionSet.size()>0) {
      for(auto item : _percussionSet) {
        auto child = self.append_child("percussion");
        item->ostream(child);
      }
    }
    else if(_otherDirectionPtr) {
      auto child = self.append_child("other-direction");
      _otherDirectionPtr->ostream(child);
    }
  }
  void DirectionType::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "rehearsal")==0) {
        auto rehearsalPtr = std::make_shared<Rehearsal>();
        rehearsalPtr->istream(child);
        addRehearsal(rehearsalPtr);
      }
      else if(strcmp(child.name(), "segno")==0) {
        auto segnoPtr = std::make_shared<Segno>();
        segnoPtr->istream(child);
        addSegno(segnoPtr);
      }
      else if(strcmp(child.name(), "words")==0) {
        auto wordsPtr = std::make_shared<Words>();
        wordsPtr->istream(child);
        addWords(wordsPtr);
      }
      else if(strcmp(child.name(), "coda")==0) {
        auto codaPtr = std::make_shared<Coda>();
        codaPtr->istream(child);
        addCoda(codaPtr);
      }
      else if(strcmp(child.name(), "wedge")==0) {
        auto wedgePtr = std::make_shared<Wedge>();
        wedgePtr->istream(child);
        setWedge(wedgePtr);
      }
      else if(strcmp(child.name(), "dynamics")==0) {
        auto dynamicsPtr = std::make_shared<Dynamics>();
        dynamicsPtr->istream(child);
        addDynamics(dynamicsPtr);
      }
      else if(strcmp(child.name(), "dashes")==0) {
        auto dashesPtr = std::make_shared<Dashes>();
        dashesPtr->istream(child);
        setDashes(dashesPtr);
      }
      else if(strcmp(child.name(), "bracket")==0) {
        auto bracketPtr = std::make_shared<Bracket>();
        bracketPtr->istream(child);
        setBracket(bracketPtr);
      }
      else if(strcmp(child.name(), "pedal")==0) {
        auto pedalPtr = std::make_shared<Pedal>();
        pedalPtr->istream(child);
        setPedal(pedalPtr);
      }
      //else if(strcmp(child.name(), "metronome")==0) {
        //auto metronomePtr = std::make_shared<Metronome>();
        //metronomePtr->istream(child);
        //setMetronome(metronomePtr);
      //}
      else if(strcmp(child.name(), "octave-shift")==0) {
        auto octaveShiftPtr = std::make_shared<OctaveShift>();
        octaveShiftPtr->istream(child);
        setOctaveShift(octaveShiftPtr);
      }
      else if(strcmp(child.name(), "harp-pedals")==0) {
        auto harpPedalsPtr = std::make_shared<HarpPedals>();
        harpPedalsPtr->istream(child);
        setHarpPedals(harpPedalsPtr);
      }
      else if(strcmp(child.name(), "damp")==0) {
        auto dampPtr = std::make_shared<Damp>();
        dampPtr->istream(child);
        setDamp(dampPtr);
      }
      else if(strcmp(child.name(), "damp-all")==0) {
        auto dampAllPtr = std::make_shared<DampAll>();
        dampAllPtr->istream(child);
        setDampAll(dampAllPtr);
      }
      else if(strcmp(child.name(), "eyeglasses")==0) {
        auto eyeglassesPtr = std::make_shared<Eyeglasses>();
        eyeglassesPtr->istream(child);
        setEyeglasses(eyeglassesPtr);
      }
      else if(strcmp(child.name(), "string-mute")==0) {
        auto stringMutePtr = std::make_shared<StringMute>();
        stringMutePtr->istream(child);
        setStringMute(stringMutePtr);
      }
      else if(strcmp(child.name(), "scordatura")==0) {
        auto scordaturaPtr = std::make_shared<Scordatura>();
        scordaturaPtr->istream(child);
        setScordatura(scordaturaPtr);
      }
      else if(strcmp(child.name(), "image")==0) {
        auto imagePtr = std::make_shared<Image>();
        imagePtr->istream(child);
        setImage(imagePtr);
      }
      else if(strcmp(child.name(), "principal-voice")==0) {
        auto principalVoicePtr = std::make_shared<PrincipalVoice>();
        principalVoicePtr->istream(child);
        setPrincipalVoice(principalVoicePtr);
      }
      else if(strcmp(child.name(), "accordion-registration")==0) {
        auto accordionRegistrationPtr = std::make_shared<AccordionRegistration>();
        accordionRegistrationPtr->istream(child);
        setAccordionRegistration(accordionRegistrationPtr);
      }
      else if(strcmp(child.name(), "percussion")==0) {
        auto percussionPtr = std::make_shared<Percussion>();
        percussionPtr->istream(child);
        addPercussion(percussionPtr);
      }
      else if(strcmp(child.name(), "other-direction")==0) {
        auto otherDirectionPtr = std::make_shared<OtherDirection>();
        otherDirectionPtr->istream(child);
        setOtherDirection(otherDirectionPtr);
      }
    }
  }
}
