#include "Dynamics.h"
#include <cstring>
#include "P.h"
#include "Pp.h"
#include "Ppp.h"
#include "Pppp.h"
#include "Ppppp.h"
#include "Pppppp.h"
#include "F.h"
#include "Ff.h"
#include "Fff.h"
#include "Ffff.h"
#include "Fffff.h"
#include "Ffffff.h"
#include "Mp.h"
#include "Mf.h"
#include "Sf.h"
#include "Sfp.h"
#include "Sfpp.h"
#include "Fp.h"
#include "Rf.h"
#include "Rfz.h"
#include "Sfz.h"
#include "Sffz.h"
#include "Fz.h"
#include "OtherDynamics.h"

namespace mxml
{
  Dynamics::Dynamics() {}
  const DynamicSet& Dynamics::getDynamicSet() const {  return _dynamicSet; }
  void Dynamics::removeDynamic(const DynamicPtr& value) { if(value) { auto i = std::find_if(_dynamicSet.begin(), _dynamicSet.end(), [&](const DynamicPtr& item) { return item==value; }); if(i!=_dynamicSet.end()) _dynamicSet.erase(i); } }
  void Dynamics::addDynamic(const DynamicPtr& value) { if(value) { _dynamicSet.push_back(value); value->setParent(shared_from_this()); } }
  void Dynamics::clearDynamicSet() { _dynamicSet.clear(); }

  void Dynamics::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyleAlign::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    TextDecoration::ostreamAttrs(self);
    Enclosure::ostreamAttrs(self);
  }
  void Dynamics::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyleAlign::istreamAttrs(self);
    Placement::istreamAttrs(self);
    TextDecoration::istreamAttrs(self);
    Enclosure::istreamAttrs(self);
  }
  void Dynamics::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _dynamicSet) {
      if(std::dynamic_pointer_cast<P>(item).get()) {
        auto child = self.append_child("p");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Pp>(item).get()) {
        auto child = self.append_child("pp");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Ppp>(item).get()) {
        auto child = self.append_child("ppp");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Pppp>(item).get()) {
        auto child = self.append_child("pppp");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Ppppp>(item).get()) {
        auto child = self.append_child("ppppp");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Pppppp>(item).get()) {
        auto child = self.append_child("pppppp");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<F>(item).get()) {
        auto child = self.append_child("f");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Ff>(item).get()) {
        auto child = self.append_child("ff");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Fff>(item).get()) {
        auto child = self.append_child("fff");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Ffff>(item).get()) {
        auto child = self.append_child("ffff");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Fffff>(item).get()) {
        auto child = self.append_child("fffff");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Ffffff>(item).get()) {
        auto child = self.append_child("ffffff");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Mp>(item).get()) {
        auto child = self.append_child("mp");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Mf>(item).get()) {
        auto child = self.append_child("mf");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Sf>(item).get()) {
        auto child = self.append_child("sf");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Sfp>(item).get()) {
        auto child = self.append_child("sfp");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Sfpp>(item).get()) {
        auto child = self.append_child("sfpp");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Fp>(item).get()) {
        auto child = self.append_child("fp");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Rf>(item).get()) {
        auto child = self.append_child("rf");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Rfz>(item).get()) {
        auto child = self.append_child("rfz");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Sfz>(item).get()) {
        auto child = self.append_child("sfz");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Sffz>(item).get()) {
        auto child = self.append_child("sffz");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<Fz>(item).get()) {
        auto child = self.append_child("fz");
        item->ostream(child);
      }
      else if(std::dynamic_pointer_cast<OtherDynamics>(item).get()) {
        auto child = self.append_child("other-dynamics");
        item->ostream(child);
      }
    }      
  }
  void Dynamics::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "p")==0) {
        auto pPtr = std::make_shared<P>();
        pPtr->istream(child);
        addDynamic(pPtr);
      }
      else if(strcmp(child.name(), "pp")==0) {
        auto ppPtr = std::make_shared<Pp>();
        ppPtr->istream(child);
        addDynamic(ppPtr);
      }
      else if(strcmp(child.name(), "ppp")==0) {
        auto pppPtr = std::make_shared<Ppp>();
        pppPtr->istream(child);
        addDynamic(pppPtr);
      }
      else if(strcmp(child.name(), "pppp")==0) {
        auto ppppPtr = std::make_shared<Pppp>();
        ppppPtr->istream(child);
        addDynamic(ppppPtr);
      }
      else if(strcmp(child.name(), "ppppp")==0) {
        auto pppppPtr = std::make_shared<Ppppp>();
        pppppPtr->istream(child);
        addDynamic(pppppPtr);
      }
      else if(strcmp(child.name(), "pppppp")==0) {
        auto ppppppPtr = std::make_shared<Pppppp>();
        ppppppPtr->istream(child);
        addDynamic(ppppppPtr);
      }
      else if(strcmp(child.name(), "f")==0) {
        auto fPtr = std::make_shared<F>();
        fPtr->istream(child);
        addDynamic(fPtr);
      }
      else if(strcmp(child.name(), "ff")==0) {
        auto ffPtr = std::make_shared<Ff>();
        ffPtr->istream(child);
        addDynamic(ffPtr);
      }
      else if(strcmp(child.name(), "fff")==0) {
        auto fffPtr = std::make_shared<Fff>();
        fffPtr->istream(child);
        addDynamic(fffPtr);
      }
      else if(strcmp(child.name(), "ffff")==0) {
        auto ffffPtr = std::make_shared<Ffff>();
        ffffPtr->istream(child);
        addDynamic(ffffPtr);
      }
      else if(strcmp(child.name(), "fffff")==0) {
        auto fffffPtr = std::make_shared<Fffff>();
        fffffPtr->istream(child);
        addDynamic(fffffPtr);
      }
      else if(strcmp(child.name(), "ffffff")==0) {
        auto ffffffPtr = std::make_shared<Ffffff>();
        ffffffPtr->istream(child);
        addDynamic(ffffffPtr);
      }
      else if(strcmp(child.name(), "mp")==0) {
        auto mpPtr = std::make_shared<Mp>();
        mpPtr->istream(child);
        addDynamic(mpPtr);
      }
      else if(strcmp(child.name(), "mf")==0) {
        auto mfPtr = std::make_shared<Mf>();
        mfPtr->istream(child);
        addDynamic(mfPtr);
      }
      else if(strcmp(child.name(), "sf")==0) {
        auto sfPtr = std::make_shared<Sf>();
        sfPtr->istream(child);
        addDynamic(sfPtr);
      }
      else if(strcmp(child.name(), "sfp")==0) {
        auto sfpPtr = std::make_shared<Sfp>();
        sfpPtr->istream(child);
        addDynamic(sfpPtr);
      }
      else if(strcmp(child.name(), "sfpp")==0) {
        auto sfppPtr = std::make_shared<Sfpp>();
        sfppPtr->istream(child);
        addDynamic(sfppPtr);
      }
      else if(strcmp(child.name(), "fp")==0) {
        auto fpPtr = std::make_shared<Fp>();
        fpPtr->istream(child);
        addDynamic(fpPtr);
      }
      else if(strcmp(child.name(), "rf")==0) {
        auto rfPtr = std::make_shared<Rf>();
        rfPtr->istream(child);
        addDynamic(rfPtr);
      }
      else if(strcmp(child.name(), "rfz")==0) {
        auto rfzPtr = std::make_shared<Rfz>();
        rfzPtr->istream(child);
        addDynamic(rfzPtr);
      }
      else if(strcmp(child.name(), "sfz")==0) {
        auto sfzPtr = std::make_shared<Sfz>();
        sfzPtr->istream(child);
        addDynamic(sfzPtr);
      }
      else if(strcmp(child.name(), "sffz")==0) {
        auto sffzPtr = std::make_shared<Sffz>();
        sffzPtr->istream(child);
        addDynamic(sffzPtr);
      }
      else if(strcmp(child.name(), "fz")==0) {
        auto fzPtr = std::make_shared<Fz>();
        fzPtr->istream(child);
        addDynamic(fzPtr);
      }
      else if(strcmp(child.name(), "other-dynamics")==0) {
        auto otherDynamicsPtr = std::make_shared<OtherDynamics>();
        otherDynamicsPtr->istream(child);
        addDynamic(otherDynamicsPtr);
      }
    }
  }
}
