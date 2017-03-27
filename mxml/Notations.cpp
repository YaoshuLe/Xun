#include "Notations.h"
#include <cstring>
#include "Footnote.h"
#include "Level.h"
#include "Tied.h"
#include "Slur.h"
#include "Tuplet.h"
#include "Glissando.h"
#include "Slide.h"
#include "Ornaments.h"
#include "Technicals.h"
#include "Articulations.h"
#include "Dynamics.h"
#include "Fermata.h"
#include "Arpeggiate.h"
#include "NonArpeggiate.h"
#include "AccidentalMark.h"
#include "OtherNotation.h"

namespace mxml
{
  Notations::Notations() {}
  FootnotePtr Notations::getFootnote() const { return _footnotePtr; }
  void Notations::setFootnote(const FootnotePtr& value) { _footnotePtr = value; value->setParent(shared_from_this()); }
  LevelPtr Notations::getLevel() const { return _levelPtr; }
  void Notations::setLevel(const LevelPtr& value) { _levelPtr = value; value->setParent(shared_from_this()); }
  const NotationSet& Notations::getNotationSet() const {  return _notationSet; }
  void Notations::removeNotation(const NotationPtr& value) { if(value) { auto i = std::find_if(_notationSet.begin(), _notationSet.end(), [&](const NotationPtr& item) { return item==value; }); if(i!=_notationSet.end()) _notationSet.erase(i); } }
  void Notations::addNotation(const NotationPtr& value) { if(value) { _notationSet.push_back(value); value->setParent(shared_from_this()); } }
  void Notations::clearNotationSet() { _notationSet.clear(); }

  void Notations::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintObject::ostreamAttrs(self);
  }
  void Notations::istreamAttrs(const pugi::xml_node& self)
  {
    PrintObject::istreamAttrs(self);
  }
  void Notations::ostreamContents(pugi::xml_node& self) const
  {
    if(_footnotePtr) {
      auto child = self.append_child("footnote");
      _footnotePtr->ostream(child);
    }
    if(_levelPtr) {
      auto child = self.append_child("level");
      _levelPtr->ostream(child);
    }
    for(auto item : _notationSet) {
      if(std::dynamic_pointer_cast<Tied>(item).get()) {
        auto child = self.append_child("tied");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Slur>(item).get()) {
        auto child = self.append_child("slur");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Tuplet>(item).get()) {
        auto child = self.append_child("tuplet");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Glissando>(item).get()) {
        auto child = self.append_child("glissando");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Slide>(item).get()) {
        auto child = self.append_child("slide");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Ornaments>(item).get()) {
        auto child = self.append_child("ornaments");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Technicals>(item).get()) {
        auto child = self.append_child("technical");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Articulations>(item).get()) {
        auto child = self.append_child("articulations");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Dynamics>(item).get()) {
        auto child = self.append_child("dynamics");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Fermata>(item).get()) {
        auto child = self.append_child("fermata");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Arpeggiate>(item).get()) {
        auto child = self.append_child("arpeggiate");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<NonArpeggiate>(item).get()) {
        auto child = self.append_child("non-arpeggiate");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<AccidentalMark>(item).get()) {
        auto child = self.append_child("accidental-mark");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<OtherNotation>(item).get()) {
        auto child = self.append_child("other-notation");
        item->ostream(child);
      }
    }      
  }
  void Notations::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "footnote")==0) {
        auto footnotePtr = std::make_shared<Footnote>();
        footnotePtr->istream(child);
        setFootnote(footnotePtr);
      }
      else if(strcmp(child.name(), "level")==0) {
        auto levelPtr = std::make_shared<Level>();
        levelPtr->istream(child);
        setLevel(levelPtr);
      }
      else if(strcmp(child.name(), "tied")==0) {
        auto tiedPtr = std::make_shared<Tied>();
        tiedPtr->istream(child);
        addNotation(tiedPtr);
      }
      else if(strcmp(child.name(), "slur")==0) {
        auto slurPtr = std::make_shared<Slur>();
        slurPtr->istream(child);
        addNotation(slurPtr);
      }
      else if(strcmp(child.name(), "tuplet")==0) {
        auto tupletPtr = std::make_shared<Tuplet>();
        tupletPtr->istream(child);
        addNotation(tupletPtr);
      }
      else if(strcmp(child.name(), "glissando")==0) {
        auto glissandoPtr = std::make_shared<Glissando>();
        glissandoPtr->istream(child);
        addNotation(glissandoPtr);
      }
      else if(strcmp(child.name(), "slide")==0) {
        auto slidePtr = std::make_shared<Slide>();
        slidePtr->istream(child);
        addNotation(slidePtr);
      }
      else if(strcmp(child.name(), "ornaments")==0) {
        auto ornamentsPtr = std::make_shared<Ornaments>();
        ornamentsPtr->istream(child);
        addNotation(ornamentsPtr);
      }
      else if(strcmp(child.name(), "technical")==0) {
        auto technicalsPtr = std::make_shared<Technicals>();
        technicalsPtr->istream(child);
        addNotation(technicalsPtr);
      }
      else if(strcmp(child.name(), "articulations")==0) {
        auto articulationsPtr = std::make_shared<Articulations>();
        articulationsPtr->istream(child);
        addNotation(articulationsPtr);
      }
      else if(strcmp(child.name(), "dynamics")==0) {
        auto dynamicsPtr = std::make_shared<Dynamics>();
        dynamicsPtr->istream(child);
        addNotation(dynamicsPtr);
      }
      else if(strcmp(child.name(), "fermata")==0) {
        auto fermataPtr = std::make_shared<Fermata>();
        fermataPtr->istream(child);
        addNotation(fermataPtr);
      }
      else if(strcmp(child.name(), "arpeggiate")==0) {
        auto arpeggiatePtr = std::make_shared<Arpeggiate>();
        arpeggiatePtr->istream(child);
        addNotation(arpeggiatePtr);
      }
      else if(strcmp(child.name(), "non-arpeggiate")==0) {
        auto nonArpeggiatePtr = std::make_shared<NonArpeggiate>();
        nonArpeggiatePtr->istream(child);
        addNotation(nonArpeggiatePtr);
      }
      else if(strcmp(child.name(), "accidental-mark")==0) {
        auto accidentalMarkPtr = std::make_shared<AccidentalMark>();
        accidentalMarkPtr->istream(child);
        addNotation(accidentalMarkPtr);
      }
      else if(strcmp(child.name(), "other-notation")==0) {
        auto otherNotationPtr = std::make_shared<OtherNotation>();
        otherNotationPtr->istream(child);
        addNotation(otherNotationPtr);
      }
    }
  }
}
