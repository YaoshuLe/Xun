#include "Frame.h"
#include <cstring>
#include "FrameStrings.h"
#include "FrameFrets.h"
#include "FirstFret.h"
#include "FrameNote.h"

namespace mxml
{
  Frame::Frame() {}
  FrameStringsPtr Frame::getFrameStrings() const { return _frameStringsPtr; }
  void Frame::setFrameStrings(const FrameStringsPtr& value) { _frameStringsPtr = value; value->setParent(shared_from_this()); }
  FrameFretsPtr Frame::getFrameFrets() const { return _frameFretsPtr; }
  void Frame::setFrameFrets(const FrameFretsPtr& value) { _frameFretsPtr = value; value->setParent(shared_from_this()); }
  FirstFretPtr Frame::getFirstFret() const { return _firstFretPtr; }
  void Frame::setFirstFret(const FirstFretPtr& value) { _firstFretPtr = value; value->setParent(shared_from_this()); }
  const FrameNoteSet& Frame::getFrameNoteSet() const {  return _frameNoteSet; }
  void Frame::removeFrameNote(const FrameNotePtr& value) { if(value) { auto i = std::find_if(_frameNoteSet.begin(), _frameNoteSet.end(), [&](const FrameNotePtr& item) { return item==value; }); if(i!=_frameNoteSet.end()) _frameNoteSet.erase(i); } } 
  void Frame::addFrameNote(const FrameNotePtr& value) { if(value) { _frameNoteSet.push_back(value); value->setParent(shared_from_this()); } }
  void Frame::clearFrameNoteSet() { _frameNoteSet.clear(); }
  bool Frame::hasHeight() const { return _hasHeight; }
  void Frame::hasHeight(bool value) { _hasHeight = value; }
  float Frame::height() const { return _height; }
  void Frame::height(float value) { _height = value; }
  bool Frame::hasWidth() const { return _hasWidth; }
  void Frame::hasWidth(bool value) { _hasWidth = value; }
  float Frame::width() const { return _width; }
  void Frame::width(float value) { _width = value; }
  bool Frame::hasUnplayed() const { return _hasUnplayed; }
  void Frame::hasUnplayed(bool value) { _hasUnplayed = value; }
  std::string Frame::unplayed() const { return _unplayed; }
  void Frame::unplayed(std::string value) { _unplayed = value; }

  void Frame::ostreamAttrs(pugi::xml_node& self) const
  {
    Position::ostreamAttrs(self);
    Color::ostreamAttrs(self);
    Halign::ostreamAttrs(self);
    ValignImage::ostreamAttrs(self);
    if(_hasHeight) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _height);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("height").set_value(str);
    }
    if(_hasWidth) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _width);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("width").set_value(str);
    }
    if(_hasUnplayed) {
      self.append_attribute("unplayed").set_value(_unplayed.c_str());
    }
  }
  void Frame::istreamAttrs(const pugi::xml_node& self)
  {
    Position::istreamAttrs(self);
    Color::istreamAttrs(self);
    Halign::istreamAttrs(self);
    ValignImage::istreamAttrs(self);
    if(auto attr = self.attribute("height")) {
      _height = attr.as_float();
      _hasHeight = true;
    }
    if(auto attr = self.attribute("width")) {
      _width = attr.as_float();
      _hasWidth = true;
    }
    if(auto attr = self.attribute("unplayed")) {
      _unplayed = attr.as_string();
      _hasUnplayed = true;
    }
  }
  void Frame::ostreamContents(pugi::xml_node& self) const
  {
    if(_frameStringsPtr) {
      auto child = self.append_child("frame-strings");
      _frameStringsPtr->ostream(child);
    }
    if(_frameFretsPtr) {
      auto child = self.append_child("frame-frets");
      _frameFretsPtr->ostream(child);
    }
    if(_firstFretPtr) {
      auto child = self.append_child("first-fret");
      _firstFretPtr->ostream(child);
    }
    for(auto item : _frameNoteSet) {
      auto child = self.append_child("frame-note");
      item->ostream(child);
    }
  }
  void Frame::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "frame-strings")==0) {
        auto frameStringsPtr = std::make_shared<FrameStrings>();
        frameStringsPtr->istream(child);
        setFrameStrings(frameStringsPtr);
      }
      else if(strcmp(child.name(), "frame-frets")==0) {
        auto frameFretsPtr = std::make_shared<FrameFrets>();
        frameFretsPtr->istream(child);
        setFrameFrets(frameFretsPtr);
      }
      else if(strcmp(child.name(), "first-fret")==0) {
        auto firstFretPtr = std::make_shared<FirstFret>();
        firstFretPtr->istream(child);
        setFirstFret(firstFretPtr);
      }
      else if(strcmp(child.name(), "frame-note")==0) {
        auto frameNotePtr = std::make_shared<FrameNote>();
        frameNotePtr->istream(child);
        addFrameNote(frameNotePtr);
      }
    }
  }
}
