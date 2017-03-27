#include "Technicals.h"
#include <cstring>
#include "UpBow.h"
#include "DownBow.h"
#include "Harmonic.h"
#include "OpenString.h"
#include "ThumbPosition.h"
#include "Fingering.h"
#include "Pluck.h"
#include "DoubleTongue.h"
#include "TripleTongue.h"
#include "Stopped.h"
#include "SnapPizzicato.h"
#include "Fret.h"
#include "String.h"
#include "HammerOn.h"
#include "PullOff.h"
#include "Bend.h"
#include "Tap.h"
#include "Heel.h"
#include "Toe.h"
#include "Fingernails.h"
#include "Hole.h"
#include "Arrow.h"
#include "Handbell.h"
#include "OtherTechnical.h"

namespace mxml
{
  Technicals::Technicals() {}
  const TechnicalSet& Technicals::getTechnicalSet() const {  return _technicalSet; }
  void Technicals::removeTechnical(const TechnicalPtr& value) { if(value) { auto i = std::find_if(_technicalSet.begin(), _technicalSet.end(), [&](const TechnicalPtr& item) { return item==value; }); if(i!=_technicalSet.end()) _technicalSet.erase(i); } }
  void Technicals::addTechnical(const TechnicalPtr& value) { if(value) { _technicalSet.push_back(value); value->setParent(shared_from_this()); } }
  void Technicals::clearTechnicalSet() { _technicalSet.clear(); }

  void Technicals::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _technicalSet) {
      if(std::dynamic_pointer_cast<UpBow>(item).get()) {
        auto child = self.append_child("up-bow");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<DownBow>(item).get()) {
        auto child = self.append_child("down-bow");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Harmonic>(item).get()) {
        auto child = self.append_child("harmonic");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<OpenString>(item).get()) {
        auto child = self.append_child("open-string");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<ThumbPosition>(item).get()) {
        auto child = self.append_child("thumb-position");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Fingering>(item).get()) {
        auto child = self.append_child("fingering");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Pluck>(item).get()) {
        auto child = self.append_child("pluck");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<DoubleTongue>(item).get()) {
        auto child = self.append_child("double-tongue");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<TripleTongue>(item).get()) {
        auto child = self.append_child("triple-tongue");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Stopped>(item).get()) {
        auto child = self.append_child("stopped");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<SnapPizzicato>(item).get()) {
        auto child = self.append_child("snap-pizzicato");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Fret>(item).get()) {
        auto child = self.append_child("fret");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<String>(item).get()) {
        auto child = self.append_child("string");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<HammerOn>(item).get()) {
        auto child = self.append_child("hammer-on");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<PullOff>(item).get()) {
        auto child = self.append_child("pull-off");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Bend>(item).get()) {
        auto child = self.append_child("bend");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Tap>(item).get()) {
        auto child = self.append_child("tap");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Heel>(item).get()) {
        auto child = self.append_child("heel");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Toe>(item).get()) {
        auto child = self.append_child("toe");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Fingernails>(item).get()) {
        auto child = self.append_child("fingernails");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Hole>(item).get()) {
        auto child = self.append_child("hole");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Arrow>(item).get()) {
        auto child = self.append_child("arrow");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Handbell>(item).get()) {
        auto child = self.append_child("handbell");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<OtherTechnical>(item).get()) {
        auto child = self.append_child("other-technical");
        item->ostream(child);
      }
    }      
  }
  void Technicals::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "up-bow")==0) {
        auto upBowPtr = std::make_shared<UpBow>();
        upBowPtr->istream(child);
        addTechnical(upBowPtr);
      }
      else if(strcmp(child.name(), "down-bow")==0) {
        auto downBowPtr = std::make_shared<DownBow>();
        downBowPtr->istream(child);
        addTechnical(downBowPtr);
      }
      else if(strcmp(child.name(), "harmonic")==0) {
        auto harmonicPtr = std::make_shared<Harmonic>();
        harmonicPtr->istream(child);
        addTechnical(harmonicPtr);
      }
      else if(strcmp(child.name(), "open-string")==0) {
        auto openStringPtr = std::make_shared<OpenString>();
        openStringPtr->istream(child);
        addTechnical(openStringPtr);
      }
      else if(strcmp(child.name(), "thumb-position")==0) {
        auto thumbPositionPtr = std::make_shared<ThumbPosition>();
        thumbPositionPtr->istream(child);
        addTechnical(thumbPositionPtr);
      }
      else if(strcmp(child.name(), "fingering")==0) {
        auto fingeringPtr = std::make_shared<Fingering>();
        fingeringPtr->istream(child);
        addTechnical(fingeringPtr);
      }
      else if(strcmp(child.name(), "pluck")==0) {
        auto pluckPtr = std::make_shared<Pluck>();
        pluckPtr->istream(child);
        addTechnical(pluckPtr);
      }
      else if(strcmp(child.name(), "double-tongue")==0) {
        auto doubleTonguePtr = std::make_shared<DoubleTongue>();
        doubleTonguePtr->istream(child);
        addTechnical(doubleTonguePtr);
      }
      else if(strcmp(child.name(), "triple-tongue")==0) {
        auto tripleTonguePtr = std::make_shared<TripleTongue>();
        tripleTonguePtr->istream(child);
        addTechnical(tripleTonguePtr);
      }
      else if(strcmp(child.name(), "stopped")==0) {
        auto stoppedPtr = std::make_shared<Stopped>();
        stoppedPtr->istream(child);
        addTechnical(stoppedPtr);
      }
      else if(strcmp(child.name(), "snap-pizzicato")==0) {
        auto snapPizzicatoPtr = std::make_shared<SnapPizzicato>();
        snapPizzicatoPtr->istream(child);
        addTechnical(snapPizzicatoPtr);
      }
      else if(strcmp(child.name(), "fret")==0) {
        auto fretPtr = std::make_shared<Fret>();
        fretPtr->istream(child);
        addTechnical(fretPtr);
      }
      else if(strcmp(child.name(), "string")==0) {
        auto stringPtr = std::make_shared<String>();
        stringPtr->istream(child);
        addTechnical(stringPtr);
      }
      else if(strcmp(child.name(), "hammer-on")==0) {
        auto hammerOnPtr = std::make_shared<HammerOn>();
        hammerOnPtr->istream(child);
        addTechnical(hammerOnPtr);
      }
      else if(strcmp(child.name(), "pull-off")==0) {
        auto pullOffPtr = std::make_shared<PullOff>();
        pullOffPtr->istream(child);
        addTechnical(pullOffPtr);
      }
      else if(strcmp(child.name(), "bend")==0) {
        auto bendPtr = std::make_shared<Bend>();
        bendPtr->istream(child);
        addTechnical(bendPtr);
      }
      else if(strcmp(child.name(), "tap")==0) {
        auto tapPtr = std::make_shared<Tap>();
        tapPtr->istream(child);
        addTechnical(tapPtr);
      }
      else if(strcmp(child.name(), "heel")==0) {
        auto heelPtr = std::make_shared<Heel>();
        heelPtr->istream(child);
        addTechnical(heelPtr);
      }
      else if(strcmp(child.name(), "toe")==0) {
        auto toePtr = std::make_shared<Toe>();
        toePtr->istream(child);
        addTechnical(toePtr);
      }
      else if(strcmp(child.name(), "fingernails")==0) {
        auto fingernailsPtr = std::make_shared<Fingernails>();
        fingernailsPtr->istream(child);
        addTechnical(fingernailsPtr);
      }
      else if(strcmp(child.name(), "hole")==0) {
        auto holePtr = std::make_shared<Hole>();
        holePtr->istream(child);
        addTechnical(holePtr);
      }
      else if(strcmp(child.name(), "arrow")==0) {
        auto arrowPtr = std::make_shared<Arrow>();
        arrowPtr->istream(child);
        addTechnical(arrowPtr);
      }
      else if(strcmp(child.name(), "handbell")==0) {
        auto handbellPtr = std::make_shared<Handbell>();
        handbellPtr->istream(child);
        addTechnical(handbellPtr);
      }
      else if(strcmp(child.name(), "other-technical")==0) {
        auto otherTechnicalPtr = std::make_shared<OtherTechnical>();
        otherTechnicalPtr->istream(child);
        addTechnical(otherTechnicalPtr);
      }
    }
  }
}
