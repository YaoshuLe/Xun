#ifndef DEFAULTS_H
#define DEFAULTS_H
#include "Element.h"

namespace mxml
{
  class Scaling;
  using ScalingPtr = std::shared_ptr<Scaling>;
  class PageLayout;
  using PageLayoutPtr = std::shared_ptr<PageLayout>;
  class SystemLayout;
  using SystemLayoutPtr = std::shared_ptr<SystemLayout>;
  class StaffLayout;
  using StaffLayoutPtr = std::shared_ptr<StaffLayout>;
  using StaffLayoutSet = std::vector<StaffLayoutPtr>;
  class Appearance;
  using AppearancePtr = std::shared_ptr<Appearance>;
  class MusicFont;
  using MusicFontPtr = std::shared_ptr<MusicFont>;
  class WordFont;
  using WordFontPtr = std::shared_ptr<WordFont>;
  class LyricFont;
  using LyricFontPtr = std::shared_ptr<LyricFont>;
  using LyricFontSet = std::vector<LyricFontPtr>;
  class LyricLanguage;
  using LyricLanguagePtr = std::shared_ptr<LyricLanguage>;
  using LyricLanguageSet = std::vector<LyricLanguagePtr>;

  class Defaults: public Element
  {
  public:
    Defaults();
    virtual const char* tagname() const { return "defaults"; }
    ScalingPtr getScaling() const;
    void setScaling(const ScalingPtr& value);
    PageLayoutPtr getPageLayout() const;
    void setPageLayout(const PageLayoutPtr& value);
    SystemLayoutPtr getSystemLayout() const;
    void setSystemLayout(const SystemLayoutPtr& value);
    const StaffLayoutSet& getStaffLayoutSet() const;
    void removeStaffLayout(const StaffLayoutPtr& value);
    void addStaffLayout(const StaffLayoutPtr& value);
    void clearStaffLayoutSet();
    AppearancePtr getAppearance() const;
    void setAppearance(const AppearancePtr& value);
    MusicFontPtr getMusicFont() const;
    void setMusicFont(const MusicFontPtr& value);
    WordFontPtr getWordFont() const;
    void setWordFont(const WordFontPtr& value);
    const LyricFontSet& getLyricFontSet() const;
    void removeLyricFont(const LyricFontPtr& value);
    void addLyricFont(const LyricFontPtr& value);
    void clearLyricFontSet();
    const LyricLanguageSet& getLyricLanguageSet() const;
    void removeLyricLanguage(const LyricLanguagePtr& value);
    void addLyricLanguage(const LyricLanguagePtr& value);
    void clearLyricLanguageSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    ScalingPtr _scalingPtr;
    PageLayoutPtr _pageLayoutPtr;
    SystemLayoutPtr _systemLayoutPtr;
    StaffLayoutSet _staffLayoutSet;
    AppearancePtr _appearancePtr;
    MusicFontPtr _musicFontPtr;
    WordFontPtr _wordFontPtr;
    LyricFontSet _lyricFontSet;
    LyricLanguageSet _lyricLanguageSet;
  };
}
#endif //DEFAULTS_H
