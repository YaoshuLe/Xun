#include "Articulations.h"
#include <cstring>
#include "Accent.h"
#include "StrongAccent.h"
#include "Staccato.h"
#include "Tenuto.h"
#include "DetachedLegato.h"
#include "Staccatissimo.h"
#include "Spiccato.h"
#include "Scoop.h"
#include "Plop.h"
#include "Doit.h"
#include "Falloff.h"
#include "BreathMark.h"
#include "Caesura.h"
#include "Stress.h"
#include "Unstress.h"
#include "OtherArticulation.h"

namespace mxml
{
  Articulations::Articulations() {}
  const ArticulationSet& Articulations::getArticulationSet() const {  return _articulationSet; }
  void Articulations::removeArticulation(const ArticulationPtr& value) { if(value) { auto i = std::find_if(_articulationSet.begin(), _articulationSet.end(), [&](const ArticulationPtr& item) { return item==value; }); if(i!=_articulationSet.end()) _articulationSet.erase(i); } }
  void Articulations::addArticulation(const ArticulationPtr& value) { if(value) { _articulationSet.push_back(value); value->setParent(shared_from_this()); } }
  void Articulations::clearArticulationSet() { _articulationSet.clear(); }

  void Articulations::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _articulationSet) {
      if(std::dynamic_pointer_cast<Accent>(item).get()) {
        auto child = self.append_child("accent");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<StrongAccent>(item).get()) {
        auto child = self.append_child("strong-accent");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Staccato>(item).get()) {
        auto child = self.append_child("staccato");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Tenuto>(item).get()) {
        auto child = self.append_child("tenuto");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<DetachedLegato>(item).get()) {
        auto child = self.append_child("detached-legato");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Staccatissimo>(item).get()) {
        auto child = self.append_child("staccatissimo");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Spiccato>(item).get()) {
        auto child = self.append_child("spiccato");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Scoop>(item).get()) {
        auto child = self.append_child("scoop");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Plop>(item).get()) {
        auto child = self.append_child("plop");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Doit>(item).get()) {
        auto child = self.append_child("doit");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Falloff>(item).get()) {
        auto child = self.append_child("falloff");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<BreathMark>(item).get()) {
        auto child = self.append_child("breath-mark");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Caesura>(item).get()) {
        auto child = self.append_child("caesura");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Stress>(item).get()) {
        auto child = self.append_child("stress");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Unstress>(item).get()) {
        auto child = self.append_child("unstress");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<OtherArticulation>(item).get()) {
        auto child = self.append_child("other-articulation");
        item->ostream(child);
      }
    }      
  }
  void Articulations::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "accent")==0) {
        auto accentPtr = std::make_shared<Accent>();
        accentPtr->istream(child);
        addArticulation(accentPtr);
      }
      else if(strcmp(child.name(), "strong-accent")==0) {
        auto strongAccentPtr = std::make_shared<StrongAccent>();
        strongAccentPtr->istream(child);
        addArticulation(strongAccentPtr);
      }
      else if(strcmp(child.name(), "staccato")==0) {
        auto staccatoPtr = std::make_shared<Staccato>();
        staccatoPtr->istream(child);
        addArticulation(staccatoPtr);
      }
      else if(strcmp(child.name(), "tenuto")==0) {
        auto tenutoPtr = std::make_shared<Tenuto>();
        tenutoPtr->istream(child);
        addArticulation(tenutoPtr);
      }
      else if(strcmp(child.name(), "detached-legato")==0) {
        auto detachedLegatoPtr = std::make_shared<DetachedLegato>();
        detachedLegatoPtr->istream(child);
        addArticulation(detachedLegatoPtr);
      }
      else if(strcmp(child.name(), "staccatissimo")==0) {
        auto staccatissimoPtr = std::make_shared<Staccatissimo>();
        staccatissimoPtr->istream(child);
        addArticulation(staccatissimoPtr);
      }
      else if(strcmp(child.name(), "spiccato")==0) {
        auto spiccatoPtr = std::make_shared<Spiccato>();
        spiccatoPtr->istream(child);
        addArticulation(spiccatoPtr);
      }
      else if(strcmp(child.name(), "scoop")==0) {
        auto scoopPtr = std::make_shared<Scoop>();
        scoopPtr->istream(child);
        addArticulation(scoopPtr);
      }
      else if(strcmp(child.name(), "plop")==0) {
        auto plopPtr = std::make_shared<Plop>();
        plopPtr->istream(child);
        addArticulation(plopPtr);
      }
      else if(strcmp(child.name(), "doit")==0) {
        auto doitPtr = std::make_shared<Doit>();
        doitPtr->istream(child);
        addArticulation(doitPtr);
      }
      else if(strcmp(child.name(), "falloff")==0) {
        auto falloffPtr = std::make_shared<Falloff>();
        falloffPtr->istream(child);
        addArticulation(falloffPtr);
      }
      else if(strcmp(child.name(), "breath-mark")==0) {
        auto breathMarkPtr = std::make_shared<BreathMark>();
        breathMarkPtr->istream(child);
        addArticulation(breathMarkPtr);
      }
      else if(strcmp(child.name(), "caesura")==0) {
        auto caesuraPtr = std::make_shared<Caesura>();
        caesuraPtr->istream(child);
        addArticulation(caesuraPtr);
      }
      else if(strcmp(child.name(), "stress")==0) {
        auto stressPtr = std::make_shared<Stress>();
        stressPtr->istream(child);
        addArticulation(stressPtr);
      }
      else if(strcmp(child.name(), "unstress")==0) {
        auto unstressPtr = std::make_shared<Unstress>();
        unstressPtr->istream(child);
        addArticulation(unstressPtr);
      }
      else if(strcmp(child.name(), "other-articulation")==0) {
        auto otherArticulationPtr = std::make_shared<OtherArticulation>();
        otherArticulationPtr->istream(child);
        addArticulation(otherArticulationPtr);
      }
    }
  }
}
