#ifndef PART_SYMBOL_H
#define PART_SYMBOL_H
#include "Element.h"
#include "Position.h"
#include "Color.h"

namespace mxml
{
  class PartSymbol: public Value<GroupSymbolValueEnum>, public Position, public Color
  {
  public:
    PartSymbol();
    virtual const char* tagname() const { return "part-symbol"; }
    bool hasTopStaff() const;
    void hasTopStaff(bool value);
    int topStaff() const;
    void topStaff(int value);
    bool hasBottomStaff() const;
    void hasBottomStaff(bool value);
    int bottomStaff() const;
    void bottomStaff(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasTopStaff {false};
    int _topStaff;
    bool _hasBottomStaff {false};
    int _bottomStaff;
  };
}
#endif //PART_SYMBOL_H
