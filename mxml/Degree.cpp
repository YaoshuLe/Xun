#include "Degree.h"
#include <cstring>
#include "DegreeValue.h"
#include "DegreeAlter.h"
#include "DegreeType.h"

namespace mxml
{
  Degree::Degree() {}
  DegreeValuePtr Degree::getDegreeValue() const { return _degreeValuePtr; }
  void Degree::setDegreeValue(const DegreeValuePtr& value) { _degreeValuePtr = value; value->setParent(shared_from_this()); }
  DegreeAlterPtr Degree::getDegreeAlter() const { return _degreeAlterPtr; }
  void Degree::setDegreeAlter(const DegreeAlterPtr& value) { _degreeAlterPtr = value; value->setParent(shared_from_this()); }
  DegreeTypePtr Degree::getDegreeType() const { return _degreeTypePtr; }
  void Degree::setDegreeType(const DegreeTypePtr& value) { _degreeTypePtr = value; value->setParent(shared_from_this()); }

  void Degree::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintObject::ostreamAttrs(self);
  }
  void Degree::istreamAttrs(const pugi::xml_node& self)
  {
    PrintObject::istreamAttrs(self);
  }
  void Degree::ostreamContents(pugi::xml_node& self) const
  {
    if(_degreeValuePtr) {
      auto child = self.append_child("degree-value");
      _degreeValuePtr->ostream(child);
    }
    if(_degreeAlterPtr) {
      auto child = self.append_child("degree-alter");
      _degreeAlterPtr->ostream(child);
    }
    if(_degreeTypePtr) {
      auto child = self.append_child("degree-type");
      _degreeTypePtr->ostream(child);
    }
  }
  void Degree::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "degree-value")==0) {
        auto degreeValuePtr = std::make_shared<DegreeValue>();
        degreeValuePtr->istream(child);
        setDegreeValue(degreeValuePtr);
      }
      else if(strcmp(child.name(), "degree-alter")==0) {
        auto degreeAlterPtr = std::make_shared<DegreeAlter>();
        degreeAlterPtr->istream(child);
        setDegreeAlter(degreeAlterPtr);
      }
      else if(strcmp(child.name(), "degree-type")==0) {
        auto degreeTypePtr = std::make_shared<DegreeType>();
        degreeTypePtr->istream(child);
        setDegreeType(degreeTypePtr);
      }
    }
  }
}
