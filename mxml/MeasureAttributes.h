#ifndef MEASURE_ATTRIBUTES_H
#define MEASURE_ATTRIBUTES_H
#include "AttrGroup.h"

namespace mxml
{
  class MeasureAttributes: public AttrGroup
  {
  public:
    MeasureAttributes();
    bool hasNumber() const;
    void hasNumber(bool value);
    std::string number() const;
    void number(std::string value);
    bool hasImplicit() const;
    void hasImplicit(bool value);
    YesNoEnum implicit() const;
    void implicit(YesNoEnum value);
    bool hasNonControlling() const;
    void hasNonControlling(bool value);
    YesNoEnum nonControlling() const;
    void nonControlling(YesNoEnum value);
    bool hasWidth() const;
    void hasWidth(bool value);
    float width() const;
    void width(float value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasNumber {false};
    std::string _number;
    bool _hasImplicit {false};
    YesNoEnum _implicit;
    bool _hasNonControlling {false};
    YesNoEnum _nonControlling;
    bool _hasWidth {false};
    float _width;
  };
}
#endif //MEASURE_ATTRIBUTES_H
