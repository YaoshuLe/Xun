#include "Lyric.h"
#include <cstring>
#include "Syllabic.h"
#include "Text.h"
#include "Extend.h"
#include "Laughing.h"
#include "Humming.h"
#include "EndLine.h"
#include "EndParagraph.h"
#include "Footnote.h"
#include "Level.h"

namespace mxml
{
  Lyric::Lyric() {}
  SyllabicPtr Lyric::getSyllabic() const { return _syllabicPtr; }
  void Lyric::setSyllabic(const SyllabicPtr& value) { _syllabicPtr = value; value->setParent(shared_from_this()); }
  TextPtr Lyric::getText() const { return _textPtr; }
  void Lyric::setText(const TextPtr& value) { _textPtr = value; value->setParent(shared_from_this()); }
  ExtendPtr Lyric::getExtend() const { return _extendPtr; }
  void Lyric::setExtend(const ExtendPtr& value) { _extendPtr = value; value->setParent(shared_from_this()); }
  LaughingPtr Lyric::getLaughing() const { return _laughingPtr; }
  void Lyric::setLaughing(const LaughingPtr& value) { _laughingPtr = value; value->setParent(shared_from_this()); }
  HummingPtr Lyric::getHumming() const { return _hummingPtr; }
  void Lyric::setHumming(const HummingPtr& value) { _hummingPtr = value; value->setParent(shared_from_this()); }
  EndLinePtr Lyric::getEndLine() const { return _endLinePtr; }
  void Lyric::setEndLine(const EndLinePtr& value) { _endLinePtr = value; value->setParent(shared_from_this()); }
  EndParagraphPtr Lyric::getEndParagraph() const { return _endParagraphPtr; }
  void Lyric::setEndParagraph(const EndParagraphPtr& value) { _endParagraphPtr = value; value->setParent(shared_from_this()); }
  FootnotePtr Lyric::getFootnote() const { return _footnotePtr; }
  void Lyric::setFootnote(const FootnotePtr& value) { _footnotePtr = value; value->setParent(shared_from_this()); }
  LevelPtr Lyric::getLevel() const { return _levelPtr; }
  void Lyric::setLevel(const LevelPtr& value) { _levelPtr = value; value->setParent(shared_from_this()); }
  bool Lyric::hasNumber() const { return _hasNumber; }
  void Lyric::hasNumber(bool value) { _hasNumber = value; }
  std::string Lyric::number() const { return _number; }
  void Lyric::number(std::string value) { _number = value; }
  bool Lyric::hasName() const { return _hasName; }
  void Lyric::hasName(bool value) { _hasName = value; }
  std::string Lyric::name() const { return _name; }
  void Lyric::name(std::string value) { _name = value; }

  void Lyric::ostreamAttrs(pugi::xml_node& self) const
  {
    Justify::ostreamAttrs(self);
    Position::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    Color::ostreamAttrs(self);
    PrintObject::ostreamAttrs(self);
    if(_hasNumber) {
      self.append_attribute("number").set_value(_number.c_str());
    }
    if(_hasName) {
      self.append_attribute("name").set_value(_name.c_str());
    }
  }
  void Lyric::istreamAttrs(const pugi::xml_node& self)
  {
    Justify::istreamAttrs(self);
    Position::istreamAttrs(self);
    Placement::istreamAttrs(self);
    Color::istreamAttrs(self);
    PrintObject::istreamAttrs(self);
    if(auto attr = self.attribute("number")) {
      _number = attr.as_string();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("name")) {
      _name = attr.as_string();
      _hasName = true;
    }
  }
  void Lyric::ostreamContents(pugi::xml_node& self) const
  {
    if(_syllabicPtr) {
      auto child = self.append_child("syllabic");
      _syllabicPtr->ostream(child);
      if(_textPtr) {
        auto child = self.append_child("text");
        _textPtr->ostream(child);
      }
      if(_extendPtr) {
        auto child = self.append_child("extend");
        _extendPtr->ostream(child);
      }
    }    
    else if(_extendPtr) {
      auto child = self.append_child("extend");
      _extendPtr->ostream(child);
    }
    else if(_laughingPtr) {
      auto child = self.append_child("laughing");
      _laughingPtr->ostream(child);
    }
    else if(_hummingPtr) {
      auto child = self.append_child("humming");
      _hummingPtr->ostream(child);
    }
    if(_endLinePtr) {
      auto child = self.append_child("end-line");
      _endLinePtr->ostream(child);
    }
    if(_endParagraphPtr) {
      auto child = self.append_child("end-paragraph");
      _endParagraphPtr->ostream(child);
    }
    if(_footnotePtr) {
      auto child = self.append_child("footnote");
      _footnotePtr->ostream(child);
    }
    if(_levelPtr) {
      auto child = self.append_child("level");
      _levelPtr->ostream(child);
    }
  }
  void Lyric::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "syllabic")==0) {
        auto syllabicPtr = std::make_shared<Syllabic>();
        syllabicPtr->istream(child);
        setSyllabic(syllabicPtr);
      }
      else if(strcmp(child.name(), "text")==0) {
        auto textPtr = std::make_shared<Text>();
        textPtr->istream(child);
        setText(textPtr);
      }
      else if(strcmp(child.name(), "extend")==0) {
        auto extendPtr = std::make_shared<Extend>();
        extendPtr->istream(child);
        setExtend(extendPtr);
      }
      else if(strcmp(child.name(), "laughing")==0) {
        auto laughingPtr = std::make_shared<Laughing>();
        laughingPtr->istream(child);
        setLaughing(laughingPtr);
      }
      else if(strcmp(child.name(), "humming")==0) {
        auto hummingPtr = std::make_shared<Humming>();
        hummingPtr->istream(child);
        setHumming(hummingPtr);
      }
      else if(strcmp(child.name(), "end-line")==0) {
        auto endLinePtr = std::make_shared<EndLine>();
        endLinePtr->istream(child);
        setEndLine(endLinePtr);
      }
      else if(strcmp(child.name(), "end-paragraph")==0) {
        auto endParagraphPtr = std::make_shared<EndParagraph>();
        endParagraphPtr->istream(child);
        setEndParagraph(endParagraphPtr);
      }
      else if(strcmp(child.name(), "footnote")==0) {
        auto footnotePtr = std::make_shared<Footnote>();
        footnotePtr->istream(child);
        setFootnote(footnotePtr);
      }
      else if(strcmp(child.name(), "level")==0) {
        auto levelPtr = std::make_shared<Level>();
        levelPtr->istream(child);
        setLevel(levelPtr);
      }
    }
  }
}
