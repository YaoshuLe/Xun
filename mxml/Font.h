#ifndef FONT_H
#define FONT_H
#include "AttrGroup.h"

namespace mxml
{
  class Font: public AttrGroup
  {
  public:
    Font();
    bool hasFontFamily() const;
    void hasFontFamily(bool value);
    std::string fontFamily() const;
    void fontFamily(std::string value);
    bool hasFontStyle() const;
    void hasFontStyle(bool value);
    FontStyleEnum fontStyle() const;
    void fontStyle(FontStyleEnum value);
    bool hasFontSize() const;
    void hasFontSize(bool value);
    FontSizeEnum fontSize() const;
    void fontSize(FontSizeEnum value);
    bool hasFontWeight() const;
    void hasFontWeight(bool value);
    FontWeightEnum fontWeight() const;
    void fontWeight(FontWeightEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasFontFamily {false};
    std::string _fontFamily;
    bool _hasFontStyle {false};
    FontStyleEnum _fontStyle;
    bool _hasFontSize {false};
    FontSizeEnum _fontSize;
    bool _hasFontWeight {false};
    FontWeightEnum _fontWeight;
  };
}
#endif //FONT_H
