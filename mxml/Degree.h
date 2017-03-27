#ifndef DEGREE_H
#define DEGREE_H
#include "Element.h"
#include "PrintObject.h"

namespace mxml
{
  class DegreeValue;
  using DegreeValuePtr = std::shared_ptr<DegreeValue>;
  class DegreeAlter;
  using DegreeAlterPtr = std::shared_ptr<DegreeAlter>;
  class DegreeType;
  using DegreeTypePtr = std::shared_ptr<DegreeType>;

  class Degree: public Element, public PrintObject
  {
  public:
    Degree();
    virtual const char* tagname() const { return "degree"; }
    DegreeValuePtr getDegreeValue() const;
    void setDegreeValue(const DegreeValuePtr& value);
    DegreeAlterPtr getDegreeAlter() const;
    void setDegreeAlter(const DegreeAlterPtr& value);
    DegreeTypePtr getDegreeType() const;
    void setDegreeType(const DegreeTypePtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    DegreeValuePtr _degreeValuePtr;
    DegreeAlterPtr _degreeAlterPtr;
    DegreeTypePtr _degreeTypePtr;
  };
}
#endif //DEGREE_H
