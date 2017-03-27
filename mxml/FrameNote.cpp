#include "FrameNote.h"
#include <cstring>
#include "String.h"
#include "Fret.h"
#include "Fingering.h"
#include "Barre.h"

namespace mxml
{
  FrameNote::FrameNote() {}
  StringPtr FrameNote::getString() const { return _stringPtr; }
  void FrameNote::setString(const StringPtr& value) { _stringPtr = value; value->setParent(shared_from_this()); }
  FretPtr FrameNote::getFret() const { return _fretPtr; }
  void FrameNote::setFret(const FretPtr& value) { _fretPtr = value; value->setParent(shared_from_this()); }
  FingeringPtr FrameNote::getFingering() const { return _fingeringPtr; }
  void FrameNote::setFingering(const FingeringPtr& value) { _fingeringPtr = value; value->setParent(shared_from_this()); }
  BarrePtr FrameNote::getBarre() const { return _barrePtr; }
  void FrameNote::setBarre(const BarrePtr& value) { _barrePtr = value; value->setParent(shared_from_this()); }

  void FrameNote::ostreamContents(pugi::xml_node& self) const
  {
    if(_stringPtr) {
      auto child = self.append_child("string");
      _stringPtr->ostream(child);
    }
    if(_fretPtr) {
      auto child = self.append_child("fret");
      _fretPtr->ostream(child);
    }
    if(_fingeringPtr) {
      auto child = self.append_child("fingering");
      _fingeringPtr->ostream(child);
    }
    if(_barrePtr) {
      auto child = self.append_child("barre");
      _barrePtr->ostream(child);
    }
  }
  void FrameNote::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "string")==0) {
        auto stringPtr = std::make_shared<String>();
        stringPtr->istream(child);
        setString(stringPtr);
      }
      else if(strcmp(child.name(), "fret")==0) {
        auto fretPtr = std::make_shared<Fret>();
        fretPtr->istream(child);
        setFret(fretPtr);
      }
      else if(strcmp(child.name(), "fingering")==0) {
        auto fingeringPtr = std::make_shared<Fingering>();
        fingeringPtr->istream(child);
        setFingering(fingeringPtr);
      }
      else if(strcmp(child.name(), "barre")==0) {
        auto barrePtr = std::make_shared<Barre>();
        barrePtr->istream(child);
        setBarre(barrePtr);
      }
    }
  }
}
