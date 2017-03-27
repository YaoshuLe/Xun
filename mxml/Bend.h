#ifndef BEND_H
#define BEND_H
#include "Element.h"
#include "PrintStyle.h"
#include "BendSound.h"

namespace mxml
{
  class BendAlter;
  using BendAlterPtr = std::shared_ptr<BendAlter>;
  class PreBend;
  using PreBendPtr = std::shared_ptr<PreBend>;
  class Release;
  using ReleasePtr = std::shared_ptr<Release>;
  class WithBar;
  using WithBarPtr = std::shared_ptr<WithBar>;

  class Bend: public Element, public PrintStyle, public BendSound
  {
  public:
    Bend();
    virtual const char* tagname() const { return "bend"; }
    BendAlterPtr getBendAlter() const;
    void setBendAlter(const BendAlterPtr& value);
    PreBendPtr getPreBend() const;
    void setPreBend(const PreBendPtr& value);
    ReleasePtr getRelease() const;
    void setRelease(const ReleasePtr& value);
    WithBarPtr getWithBar() const;
    void setWithBar(const WithBarPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    BendAlterPtr _bendAlterPtr;
    PreBendPtr _preBendPtr;
    ReleasePtr _releasePtr;
    WithBarPtr _withBarPtr;
  };
}
#endif //BEND_H
