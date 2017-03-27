#include "Ornament.h"
#include <cstring>
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
  Ornament::Ornament() {}
  TrillMarkPtr Ornament::getTrillMark() const { return _trillMarkPtr; }
  void Ornament::setTrillMark(const TrillMarkPtr& value) { _trillMarkPtr = value; value->setParent(shared_from_this()); }
  TurnPtr Ornament::getTurn() const { return _turnPtr; }
  void Ornament::setTurn(const TurnPtr& value) { _turnPtr = value; value->setParent(shared_from_this()); }
  DelayedTurnPtr Ornament::getDelayedTurn() const { return _delayedTurnPtr; }
  void Ornament::setDelayedTurn(const DelayedTurnPtr& value) { _delayedTurnPtr = value; value->setParent(shared_from_this()); }
  InvertedTurnPtr Ornament::getInvertedTurn() const { return _invertedTurnPtr; }
  void Ornament::setInvertedTurn(const InvertedTurnPtr& value) { _invertedTurnPtr = value; value->setParent(shared_from_this()); }
  DelayedInvertedTurnPtr Ornament::getDelayedInvertedTurn() const { return _delayedInvertedTurnPtr; }
  void Ornament::setDelayedInvertedTurn(const DelayedInvertedTurnPtr& value) { _delayedInvertedTurnPtr = value; value->setParent(shared_from_this()); }
  VerticalTurnPtr Ornament::getVerticalTurn() const { return _verticalTurnPtr; }
  void Ornament::setVerticalTurn(const VerticalTurnPtr& value) { _verticalTurnPtr = value; value->setParent(shared_from_this()); }
  ShakePtr Ornament::getShake() const { return _shakePtr; }
  void Ornament::setShake(const ShakePtr& value) { _shakePtr = value; value->setParent(shared_from_this()); }
  WavyLinePtr Ornament::getWavyLine() const { return _wavyLinePtr; }
  void Ornament::setWavyLine(const WavyLinePtr& value) { _wavyLinePtr = value; value->setParent(shared_from_this()); }
  MordentPtr Ornament::getMordent() const { return _mordentPtr; }
  void Ornament::setMordent(const MordentPtr& value) { _mordentPtr = value; value->setParent(shared_from_this()); }
  InvertedMordentPtr Ornament::getInvertedMordent() const { return _invertedMordentPtr; }
  void Ornament::setInvertedMordent(const InvertedMordentPtr& value) { _invertedMordentPtr = value; value->setParent(shared_from_this()); }
  SchleiferPtr Ornament::getSchleifer() const { return _schleiferPtr; }
  void Ornament::setSchleifer(const SchleiferPtr& value) { _schleiferPtr = value; value->setParent(shared_from_this()); }
  TremoloPtr Ornament::getTremolo() const { return _tremoloPtr; }
  void Ornament::setTremolo(const TremoloPtr& value) { _tremoloPtr = value; value->setParent(shared_from_this()); }
  OtherOrnamentPtr Ornament::getOtherOrnament() const { return _otherOrnamentPtr; }
  void Ornament::setOtherOrnament(const OtherOrnamentPtr& value) { _otherOrnamentPtr = value; value->setParent(shared_from_this()); }
  const AccidentalMarkSet& Ornament::getAccidentalMarkSet() const {  return _accidentalMarkSet; }
  void Ornament::removeAccidentalMark(const AccidentalMarkPtr& value) { if(value) { auto i = std::find_if(_accidentalMarkSet.begin(), _accidentalMarkSet.end(), [&](const AccidentalMarkPtr& item) { return item==value; }); if(i!=_accidentalMarkSet.end()) _accidentalMarkSet.erase(i); } }
  void Ornament::addAccidentalMark(const AccidentalMarkPtr& value) { if(value) { _accidentalMarkSet.push_back(value); value->setParent(shared_from_this()); } }
  void Ornament::clearAccidentalMarkSet() { _accidentalMarkSet.clear(); }

  void Ornament::ostreamContents(pugi::xml_node& self) const
  {
    if(_trillMarkPtr) {
      auto child = self.append_child("trill-mark");
      _trillMarkPtr->ostream(child);
    }
    else if(_turnPtr) {
      auto child = self.append_child("turn");
      _turnPtr->ostream(child);
    }
    else if(_delayedTurnPtr) {
      auto child = self.append_child("delayed-turn");
      _delayedTurnPtr->ostream(child);
    }
    else if(_invertedTurnPtr) {
      auto child = self.append_child("inverted-turn");
      _invertedTurnPtr->ostream(child);
    }
    else if(_delayedInvertedTurnPtr) {
      auto child = self.append_child("delayed-inverted-turn");
      _delayedInvertedTurnPtr->ostream(child);
    }
    else if(_verticalTurnPtr) {
      auto child = self.append_child("vertical-turn");
      _verticalTurnPtr->ostream(child);
    }
    else if(_shakePtr) {
      auto child = self.append_child("shake");
      _shakePtr->ostream(child);
    }
    else if(_wavyLinePtr) {
      auto child = self.append_child("wavy-line");
      _wavyLinePtr->ostream(child);
    }
    else if(_mordentPtr) {
      auto child = self.append_child("mordent");
      _mordentPtr->ostream(child);
    }
    else if(_invertedMordentPtr) {
      auto child = self.append_child("inverted-mordent");
      _invertedMordentPtr->ostream(child);
    }
    else if(_schleiferPtr) {
      auto child = self.append_child("schleifer");
      _schleiferPtr->ostream(child);
    }
    else if(_tremoloPtr) {
      auto child = self.append_child("tremolo");
      _tremoloPtr->ostream(child);
    }
    else if(_otherOrnamentPtr) {
      auto child = self.append_child("other-ornament");
      _otherOrnamentPtr->ostream(child);
    }
    for(auto item : _accidentalMarkSet) {
      auto child = self.append_child("accidental-mark");
      item->ostream(child);
    }
  }
  void Ornament::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "trill-mark")==0) {
        auto trillMarkPtr = std::make_shared<TrillMark>();
        trillMarkPtr->istream(child);
        setTrillMark(trillMarkPtr);
      }
      else if(strcmp(child.name(), "turn")==0) {
        auto turnPtr = std::make_shared<Turn>();
        turnPtr->istream(child);
        setTurn(turnPtr);
      }
      else if(strcmp(child.name(), "delayed-turn")==0) {
        auto delayedTurnPtr = std::make_shared<DelayedTurn>();
        delayedTurnPtr->istream(child);
        setDelayedTurn(delayedTurnPtr);
      }
      else if(strcmp(child.name(), "inverted-turn")==0) {
        auto invertedTurnPtr = std::make_shared<InvertedTurn>();
        invertedTurnPtr->istream(child);
        setInvertedTurn(invertedTurnPtr);
      }
      else if(strcmp(child.name(), "delayed-inverted-turn")==0) {
        auto delayedInvertedTurnPtr = std::make_shared<DelayedInvertedTurn>();
        delayedInvertedTurnPtr->istream(child);
        setDelayedInvertedTurn(delayedInvertedTurnPtr);
      }
      else if(strcmp(child.name(), "vertical-turn")==0) {
        auto verticalTurnPtr = std::make_shared<VerticalTurn>();
        verticalTurnPtr->istream(child);
        setVerticalTurn(verticalTurnPtr);
      }
      else if(strcmp(child.name(), "shake")==0) {
        auto shakePtr = std::make_shared<Shake>();
        shakePtr->istream(child);
        setShake(shakePtr);
      }
      else if(strcmp(child.name(), "wavy-line")==0) {
        auto wavyLinePtr = std::make_shared<WavyLine>();
        wavyLinePtr->istream(child);
        setWavyLine(wavyLinePtr);
      }
      else if(strcmp(child.name(), "mordent")==0) {
        auto mordentPtr = std::make_shared<Mordent>();
        mordentPtr->istream(child);
        setMordent(mordentPtr);
      }
      else if(strcmp(child.name(), "inverted-mordent")==0) {
        auto invertedMordentPtr = std::make_shared<InvertedMordent>();
        invertedMordentPtr->istream(child);
        setInvertedMordent(invertedMordentPtr);
      }
      else if(strcmp(child.name(), "schleifer")==0) {
        auto schleiferPtr = std::make_shared<Schleifer>();
        schleiferPtr->istream(child);
        setSchleifer(schleiferPtr);
      }
      else if(strcmp(child.name(), "tremolo")==0) {
        auto tremoloPtr = std::make_shared<Tremolo>();
        tremoloPtr->istream(child);
        setTremolo(tremoloPtr);
      }
      else if(strcmp(child.name(), "other-ornament")==0) {
        auto otherOrnamentPtr = std::make_shared<OtherOrnament>();
        otherOrnamentPtr->istream(child);
        setOtherOrnament(otherOrnamentPtr);
      }
      else if(strcmp(child.name(), "accidental-mark")==0) {
        auto accidentalMarkPtr = std::make_shared<AccidentalMark>();
        accidentalMarkPtr->istream(child);
        addAccidentalMark(accidentalMarkPtr);
      }
    }
  }
}
