#include "Ornaments.h"
#include <cstring>
#include "Ornament.h"
#include "TrillMark.h"
#include "Turn.h"
#include "DelayedTurn.h"
#include "InvertedTurn.h"
#include "DelayedInvertedTurn.h"
#include "VerticalTurn.h"
#include "Shake.h"
#include "WavyLine.h"
#include "Mordent.h"
#include "InvertedMordent.h"
#include "Schleifer.h"
#include "Tremolo.h"
#include "OtherOrnament.h"
#include "AccidentalMark.h"

namespace mxml
{
  Ornaments::Ornaments() {}
  const OrnamentSet& Ornaments::getOrnamentSet() const {  return _ornamentSet; }
  void Ornaments::removeOrnament(const OrnamentPtr& value) { if(value) { auto i = std::find_if(_ornamentSet.begin(), _ornamentSet.end(), [&](const OrnamentPtr& item) { return item==value; }); if(i!=_ornamentSet.end()) _ornamentSet.erase(i); } } 
  void Ornaments::addOrnament(const OrnamentPtr& value) { if(value) { _ornamentSet.push_back(value); value->setParent(shared_from_this()); } }
  void Ornaments::clearOrnamentSet() { _ornamentSet.clear(); }

  void Ornaments::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _ornamentSet) {
      item->ostream(self);
    }
  }
  void Ornaments::istreamContents(const pugi::xml_node& self)
  {
    OrnamentPtr ornamentPtr;
    for(auto child: self.children()) {
      if(strcmp(child.name(), "trill-mark")==0) {
        auto trillMarkPtr = std::make_shared<TrillMark>();
        trillMarkPtr->istream(child);
        ornamentPtr = std::make_shared<Ornament>();
        ornamentPtr->setTrillMark(trillMarkPtr);
        addOrnament(ornamentPtr);
      }
      else if(strcmp(child.name(), "turn")==0) {
        auto turnPtr = std::make_shared<Turn>();
        turnPtr->istream(child);
        ornamentPtr = std::make_shared<Ornament>();
        ornamentPtr->setTurn(turnPtr);
        addOrnament(ornamentPtr);
      }
      else if(strcmp(child.name(), "delayed-turn")==0) {
        auto delayedTurnPtr = std::make_shared<DelayedTurn>();
        delayedTurnPtr->istream(child);
        ornamentPtr = std::make_shared<Ornament>();
        ornamentPtr->setDelayedTurn(delayedTurnPtr);
        addOrnament(ornamentPtr);
      }
      else if(strcmp(child.name(), "inverted-turn")==0) {
        auto invertedTurnPtr = std::make_shared<InvertedTurn>();
        invertedTurnPtr->istream(child);
        ornamentPtr = std::make_shared<Ornament>();
        ornamentPtr->setInvertedTurn(invertedTurnPtr);
        addOrnament(ornamentPtr);
      }
      else if(strcmp(child.name(), "delayed-inverted-turn")==0) {
        auto delayedInvertedTurnPtr = std::make_shared<DelayedInvertedTurn>();
        delayedInvertedTurnPtr->istream(child);
        ornamentPtr = std::make_shared<Ornament>();
        ornamentPtr->setDelayedInvertedTurn(delayedInvertedTurnPtr);
        addOrnament(ornamentPtr);
      }
      else if(strcmp(child.name(), "vertical-turn")==0) {
        auto verticalTurnPtr = std::make_shared<VerticalTurn>();
        verticalTurnPtr->istream(child);
        ornamentPtr = std::make_shared<Ornament>();
        ornamentPtr->setVerticalTurn(verticalTurnPtr);
        addOrnament(ornamentPtr);
      }
      else if(strcmp(child.name(), "shake")==0) {
        auto shakePtr = std::make_shared<Shake>();
        shakePtr->istream(child);
        ornamentPtr = std::make_shared<Ornament>();
        ornamentPtr->setShake(shakePtr);
        addOrnament(ornamentPtr);
      }
      else if(strcmp(child.name(), "wavy-line")==0) {
        auto wavyLinePtr = std::make_shared<WavyLine>();
        wavyLinePtr->istream(child);
        ornamentPtr = std::make_shared<Ornament>();
        ornamentPtr->setWavyLine(wavyLinePtr);
        addOrnament(ornamentPtr);
      }
      else if(strcmp(child.name(), "mordent")==0) {
        auto mordentPtr = std::make_shared<Mordent>();
        mordentPtr->istream(child);
        ornamentPtr = std::make_shared<Ornament>();
        ornamentPtr->setMordent(mordentPtr);
        addOrnament(ornamentPtr);
      }
      else if(strcmp(child.name(), "inverted-mordent")==0) {
        auto invertedMordentPtr = std::make_shared<InvertedMordent>();
        invertedMordentPtr->istream(child);
        ornamentPtr = std::make_shared<Ornament>();
        ornamentPtr->setInvertedMordent(invertedMordentPtr);
        addOrnament(ornamentPtr);
      }
      else if(strcmp(child.name(), "schleifer")==0) {
        auto schleiferPtr = std::make_shared<Schleifer>();
        schleiferPtr->istream(child);
        ornamentPtr = std::make_shared<Ornament>();
        ornamentPtr->setSchleifer(schleiferPtr);
        addOrnament(ornamentPtr);
      }
      else if(strcmp(child.name(), "tremolo")==0) {
        auto tremoloPtr = std::make_shared<Tremolo>();
        tremoloPtr->istream(child);
        ornamentPtr = std::make_shared<Ornament>();
        ornamentPtr->setTremolo(tremoloPtr);
        addOrnament(ornamentPtr);
      }
      else if(strcmp(child.name(), "other-ornament")==0) {
        auto otherOrnamentPtr = std::make_shared<OtherOrnament>();
        otherOrnamentPtr->istream(child);
        ornamentPtr = std::make_shared<Ornament>();
        ornamentPtr->setOtherOrnament(otherOrnamentPtr);
        addOrnament(ornamentPtr);
      }
      else if(strcmp(child.name(), "accidental-mark")==0) {
        if(ornamentPtr) {
          auto accidentalMarkPtr = std::make_shared<AccidentalMark>();
          accidentalMarkPtr->istream(child);
          ornamentPtr->addAccidentalMark(accidentalMarkPtr);
        }
      }      
    }
  }
}
