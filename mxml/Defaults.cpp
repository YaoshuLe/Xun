#include "Defaults.h"
#include <cstring>
#include "Scaling.h"
#include "PageLayout.h"
#include "SystemLayout.h"
#include "StaffLayout.h"
#include "Appearance.h"
#include "MusicFont.h"
#include "WordFont.h"
#include "LyricFont.h"
#include "LyricLanguage.h"

namespace mxml
{
  Defaults::Defaults() {}
  ScalingPtr Defaults::getScaling() const { return _scalingPtr; }
  void Defaults::setScaling(const ScalingPtr& value) { _scalingPtr = value; value->setParent(shared_from_this()); }
  PageLayoutPtr Defaults::getPageLayout() const { return _pageLayoutPtr; }
  void Defaults::setPageLayout(const PageLayoutPtr& value) { _pageLayoutPtr = value; value->setParent(shared_from_this()); }
  SystemLayoutPtr Defaults::getSystemLayout() const { return _systemLayoutPtr; }
  void Defaults::setSystemLayout(const SystemLayoutPtr& value) { _systemLayoutPtr = value; value->setParent(shared_from_this()); }
  const StaffLayoutSet& Defaults::getStaffLayoutSet() const {  return _staffLayoutSet; }
  void Defaults::removeStaffLayout(const StaffLayoutPtr& value) { if(value) { auto i = std::find_if(_staffLayoutSet.begin(), _staffLayoutSet.end(), [&](const StaffLayoutPtr& item) { return item==value; }); if(i!=_staffLayoutSet.end()) _staffLayoutSet.erase(i); } } 
  void Defaults::addStaffLayout(const StaffLayoutPtr& value) { if(value) { _staffLayoutSet.push_back(value); value->setParent(shared_from_this()); } }
  void Defaults::clearStaffLayoutSet() { _staffLayoutSet.clear(); }
  AppearancePtr Defaults::getAppearance() const { return _appearancePtr; }
  void Defaults::setAppearance(const AppearancePtr& value) { _appearancePtr = value; value->setParent(shared_from_this()); }
  MusicFontPtr Defaults::getMusicFont() const { return _musicFontPtr; }
  void Defaults::setMusicFont(const MusicFontPtr& value) { _musicFontPtr = value; value->setParent(shared_from_this()); }
  WordFontPtr Defaults::getWordFont() const { return _wordFontPtr; }
  void Defaults::setWordFont(const WordFontPtr& value) { _wordFontPtr = value; value->setParent(shared_from_this()); }
  const LyricFontSet& Defaults::getLyricFontSet() const {  return _lyricFontSet; }
  void Defaults::removeLyricFont(const LyricFontPtr& value) { if(value) { auto i = std::find_if(_lyricFontSet.begin(), _lyricFontSet.end(), [&](const LyricFontPtr& item) { return item==value; }); if(i!=_lyricFontSet.end()) _lyricFontSet.erase(i); } } 
  void Defaults::addLyricFont(const LyricFontPtr& value) { if(value) { _lyricFontSet.push_back(value); value->setParent(shared_from_this()); } }
  void Defaults::clearLyricFontSet() { _lyricFontSet.clear(); }
  const LyricLanguageSet& Defaults::getLyricLanguageSet() const {  return _lyricLanguageSet; }
  void Defaults::removeLyricLanguage(const LyricLanguagePtr& value) { if(value) { auto i = std::find_if(_lyricLanguageSet.begin(), _lyricLanguageSet.end(), [&](const LyricLanguagePtr& item) { return item==value; }); if(i!=_lyricLanguageSet.end()) _lyricLanguageSet.erase(i); } } 
  void Defaults::addLyricLanguage(const LyricLanguagePtr& value) { if(value) { _lyricLanguageSet.push_back(value); value->setParent(shared_from_this()); } }
  void Defaults::clearLyricLanguageSet() { _lyricLanguageSet.clear(); }

  void Defaults::ostreamContents(pugi::xml_node& self) const
  {
    if(_scalingPtr) {
      auto child = self.append_child("scaling");
      _scalingPtr->ostream(child);
    }
    if(_pageLayoutPtr) {
      auto child = self.append_child("page-layout");
      _pageLayoutPtr->ostream(child);
    }
    if(_systemLayoutPtr) {
      auto child = self.append_child("system-layout");
      _systemLayoutPtr->ostream(child);
    }
    for(auto item : _staffLayoutSet) {
      auto child = self.append_child("staff-layout");
      item->ostream(child);
    }
    if(_appearancePtr) {
      auto child = self.append_child("appearance");
      _appearancePtr->ostream(child);
    }
    if(_musicFontPtr) {
      auto child = self.append_child("music-font");
      _musicFontPtr->ostream(child);
    }
    if(_wordFontPtr) {
      auto child = self.append_child("word-font");
      _wordFontPtr->ostream(child);
    }
    for(auto item : _lyricFontSet) {
      auto child = self.append_child("lyric-font");
      item->ostream(child);
    }
    for(auto item : _lyricLanguageSet) {
      auto child = self.append_child("lyric-language");
      item->ostream(child);
    }
  }
  void Defaults::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "scaling")==0) {
        auto scalingPtr = std::make_shared<Scaling>();
        scalingPtr->istream(child);
        setScaling(scalingPtr);
      }
      else if(strcmp(child.name(), "page-layout")==0) {
        auto pageLayoutPtr = std::make_shared<PageLayout>();
        pageLayoutPtr->istream(child);
        setPageLayout(pageLayoutPtr);
      }
      else if(strcmp(child.name(), "system-layout")==0) {
        auto systemLayoutPtr = std::make_shared<SystemLayout>();
        systemLayoutPtr->istream(child);
        setSystemLayout(systemLayoutPtr);
      }
      else if(strcmp(child.name(), "staff-layout")==0) {
        auto staffLayoutPtr = std::make_shared<StaffLayout>();
        staffLayoutPtr->istream(child);
        addStaffLayout(staffLayoutPtr);
      }
      else if(strcmp(child.name(), "appearance")==0) {
        auto appearancePtr = std::make_shared<Appearance>();
        appearancePtr->istream(child);
        setAppearance(appearancePtr);
      }
      else if(strcmp(child.name(), "music-font")==0) {
        auto musicFontPtr = std::make_shared<MusicFont>();
        musicFontPtr->istream(child);
        setMusicFont(musicFontPtr);
      }
      else if(strcmp(child.name(), "word-font")==0) {
        auto wordFontPtr = std::make_shared<WordFont>();
        wordFontPtr->istream(child);
        setWordFont(wordFontPtr);
      }
      else if(strcmp(child.name(), "lyric-font")==0) {
        auto lyricFontPtr = std::make_shared<LyricFont>();
        lyricFontPtr->istream(child);
        addLyricFont(lyricFontPtr);
      }
      else if(strcmp(child.name(), "lyric-language")==0) {
        auto lyricLanguagePtr = std::make_shared<LyricLanguage>();
        lyricLanguagePtr->istream(child);
        addLyricLanguage(lyricLanguagePtr);
      }
    }
  }
}
