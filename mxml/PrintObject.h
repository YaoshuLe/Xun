#ifndef PRINT_OBJECT_H
#define PRINT_OBJECT_H
#include "AttrGroup.h"

namespace mxml
{
  class PrintObject: public AttrGroup
  {
  public:
    PrintObject();
    bool hasPrintObject() const;
    void hasPrintObject(bool value);
    YesNoEnum printObject() const;
    void printObject(YesNoEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasPrintObject {false};
    YesNoEnum _printObject;
  };
}
#endif //PRINT_OBJECT_H
