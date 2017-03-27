#ifndef DASHED_FORMATTING_H
#define DASHED_FORMATTING_H
#include "AttrGroup.h"

namespace mxml
{
  class DashedFormatting: public AttrGroup
  {
  public:
    DashedFormatting();
    bool hasDashLength() const;
    void hasDashLength(bool value);
    float dashLength() const;
    void dashLength(float value);
    bool hasSpaceLength() const;
    void hasSpaceLength(bool value);
    float spaceLength() const;
    void spaceLength(float value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasDashLength {false};
    float _dashLength;
    bool _hasSpaceLength {false};
    float _spaceLength;
  };
}
#endif //DASHED_FORMATTING_H
