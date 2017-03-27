#ifndef VIRTUAL_INSTRUMENT_H
#define VIRTUAL_INSTRUMENT_H
#include "Element.h"

namespace mxml
{
  class VirtualLibrary;
  using VirtualLibraryPtr = std::shared_ptr<VirtualLibrary>;
  class VirtualName;
  using VirtualNamePtr = std::shared_ptr<VirtualName>;

  class VirtualInstrument: public Element
  {
  public:
    VirtualInstrument();
    virtual const char* tagname() const { return "virtual-instrument"; }
    VirtualLibraryPtr getVirtualLibrary() const;
    void setVirtualLibrary(const VirtualLibraryPtr& value);
    VirtualNamePtr getVirtualName() const;
    void setVirtualName(const VirtualNamePtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    VirtualLibraryPtr _virtualLibraryPtr;
    VirtualNamePtr _virtualNamePtr;
  };
}
#endif //VIRTUAL_INSTRUMENT_H
