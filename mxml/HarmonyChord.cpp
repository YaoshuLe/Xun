#include "HarmonyChord.h"
#include <cstring>
#include "Root.h"
#include "Function.h"
#include "Kind.h"
#include "Inversion.h"
#include "Bass.h"
#include "Degree.h"

namespace mxml
{
  HarmonyChord::HarmonyChord() {}
  RootPtr HarmonyChord::getRoot() const { return _rootPtr; }
  void HarmonyChord::setRoot(const RootPtr& value) { _rootPtr = value; value->setParent(shared_from_this()); }
  FunctionPtr HarmonyChord::getFunction() const { return _functionPtr; }
  void HarmonyChord::setFunction(const FunctionPtr& value) { _functionPtr = value; value->setParent(shared_from_this()); }
  KindPtr HarmonyChord::getKind() const { return _kindPtr; }
  void HarmonyChord::setKind(const KindPtr& value) { _kindPtr = value; value->setParent(shared_from_this()); }
  InversionPtr HarmonyChord::getInversion() const { return _inversionPtr; }
  void HarmonyChord::setInversion(const InversionPtr& value) { _inversionPtr = value; value->setParent(shared_from_this()); }
  BassPtr HarmonyChord::getBass() const { return _bassPtr; }
  void HarmonyChord::setBass(const BassPtr& value) { _bassPtr = value; value->setParent(shared_from_this()); }
  const DegreeSet& HarmonyChord::getDegreeSet() const {  return _degreeSet; }
  void HarmonyChord::removeDegree(const DegreePtr& value) { if(value) { auto i = std::find_if(_degreeSet.begin(), _degreeSet.end(), [&](const DegreePtr& item) { return item==value; }); if(i!=_degreeSet.end()) _degreeSet.erase(i); } } 
  void HarmonyChord::addDegree(const DegreePtr& value) { if(value) { _degreeSet.push_back(value); value->setParent(shared_from_this()); } }
  void HarmonyChord::clearDegreeSet() { _degreeSet.clear(); }

  void HarmonyChord::ostreamContents(pugi::xml_node& self) const
  {
    if(_rootPtr) {
      auto child = self.append_child("root");
      _rootPtr->ostream(child);
    }
    else if(_functionPtr) {
      auto child = self.append_child("function");
      _functionPtr->ostream(child);
    }
    if(_kindPtr) {
      auto child = self.append_child("kind");
      _kindPtr->ostream(child);
    }
    if(_inversionPtr) {
      auto child = self.append_child("inversion");
      _inversionPtr->ostream(child);
    }
    if(_bassPtr) {
      auto child = self.append_child("bass");
      _bassPtr->ostream(child);
    }
    for(auto item : _degreeSet) {
      auto child = self.append_child("degree");
      item->ostream(child);
    }
  }
  void HarmonyChord::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "root")==0) {
        auto rootPtr = std::make_shared<Root>();
        rootPtr->istream(child);
        setRoot(rootPtr);
      }
      else if(strcmp(child.name(), "function")==0) {
        auto functionPtr = std::make_shared<Function>();
        functionPtr->istream(child);
        setFunction(functionPtr);
      }
      else if(strcmp(child.name(), "kind")==0) {
        auto kindPtr = std::make_shared<Kind>();
        kindPtr->istream(child);
        setKind(kindPtr);
      }
      else if(strcmp(child.name(), "inversion")==0) {
        auto inversionPtr = std::make_shared<Inversion>();
        inversionPtr->istream(child);
        setInversion(inversionPtr);
      }
      else if(strcmp(child.name(), "bass")==0) {
        auto bassPtr = std::make_shared<Bass>();
        bassPtr->istream(child);
        setBass(bassPtr);
      }
      else if(strcmp(child.name(), "degree")==0) {
        auto degreePtr = std::make_shared<Degree>();
        degreePtr->istream(child);
        addDegree(degreePtr);
      }
    }
  }
}
