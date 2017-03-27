#ifndef ROOT_H
#define ROOT_H
#include "Element.h"

namespace mxml
{
  class RootStep;
  using RootStepPtr = std::shared_ptr<RootStep>;
  class RootAlter;
  using RootAlterPtr = std::shared_ptr<RootAlter>;

  class Root: public Element
  {
  public:
    Root();
    virtual const char* tagname() const { return "root"; }
    RootStepPtr getRootStep() const;
    void setRootStep(const RootStepPtr& value);
    RootAlterPtr getRootAlter() const;
    void setRootAlter(const RootAlterPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    RootStepPtr _rootStepPtr;
    RootAlterPtr _rootAlterPtr;
  };
}
#endif //ROOT_H
