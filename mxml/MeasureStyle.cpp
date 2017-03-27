#include "MeasureStyle.h"
#include <cstring>
#include "MultipleRest.h"
#include "MeasureRepeat.h"
#include "BeatRepeat.h"
#include "Slash.h"

namespace mxml
{
  MeasureStyle::MeasureStyle() {}
  MultipleRestPtr MeasureStyle::getMultipleRest() const { return _multipleRestPtr; }
  void MeasureStyle::setMultipleRest(const MultipleRestPtr& value) { _multipleRestPtr = value; value->setParent(shared_from_this()); }
  MeasureRepeatPtr MeasureStyle::getMeasureRepeat() const { return _measureRepeatPtr; }
  void MeasureStyle::setMeasureRepeat(const MeasureRepeatPtr& value) { _measureRepeatPtr = value; value->setParent(shared_from_this()); }
  BeatRepeatPtr MeasureStyle::getBeatRepeat() const { return _beatRepeatPtr; }
  void MeasureStyle::setBeatRepeat(const BeatRepeatPtr& value) { _beatRepeatPtr = value; value->setParent(shared_from_this()); }
  SlashPtr MeasureStyle::getSlash() const { return _slashPtr; }
  void MeasureStyle::setSlash(const SlashPtr& value) { _slashPtr = value; value->setParent(shared_from_this()); }
  bool MeasureStyle::hasNumber() const { return _hasNumber; }
  void MeasureStyle::hasNumber(bool value) { _hasNumber = value; }
  int MeasureStyle::number() const { return _number; }
  void MeasureStyle::number(int value) { _number = value; }

  void MeasureStyle::ostreamAttrs(pugi::xml_node& self) const
  {
    Font::ostreamAttrs(self);
    Color::ostreamAttrs(self);
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
  }
  void MeasureStyle::istreamAttrs(const pugi::xml_node& self)
  {
    Font::istreamAttrs(self);
    Color::istreamAttrs(self);
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
  }
  void MeasureStyle::ostreamContents(pugi::xml_node& self) const
  {
    if(_multipleRestPtr) {
      auto child = self.append_child("multiple-rest");
      _multipleRestPtr->ostream(child);
    }
    else if(_measureRepeatPtr) {
      auto child = self.append_child("measure-repeat");
      _measureRepeatPtr->ostream(child);
    }
    else if(_beatRepeatPtr) {
      auto child = self.append_child("beat-repeat");
      _beatRepeatPtr->ostream(child);
    }
    else if(_slashPtr) {
      auto child = self.append_child("slash");
      _slashPtr->ostream(child);
    }
  }
  void MeasureStyle::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "multiple-rest")==0) {
        auto multipleRestPtr = std::make_shared<MultipleRest>();
        multipleRestPtr->istream(child);
        setMultipleRest(multipleRestPtr);
        break;
      }
      else if(strcmp(child.name(), "measure-repeat")==0) {
        auto measureRepeatPtr = std::make_shared<MeasureRepeat>();
        measureRepeatPtr->istream(child);
        setMeasureRepeat(measureRepeatPtr);
        break;
      }
      else if(strcmp(child.name(), "beat-repeat")==0) {
        auto beatRepeatPtr = std::make_shared<BeatRepeat>();
        beatRepeatPtr->istream(child);
        setBeatRepeat(beatRepeatPtr);
        break;
      }
      else if(strcmp(child.name(), "slash")==0) {
        auto slashPtr = std::make_shared<Slash>();
        slashPtr->istream(child);
        setSlash(slashPtr);
        break;
      }
    }
  }
}
