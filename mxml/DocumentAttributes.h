#ifndef DOCUMENT_ATTRIBUTES_H
#define DOCUMENT_ATTRIBUTES_H
#include "AttrGroup.h"

namespace mxml
{
  class DocumentAttributes: public AttrGroup
  {
  public:
    DocumentAttributes();
    bool hasVersion() const;
    void hasVersion(bool value);
    std::string version() const;
    void version(std::string value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasVersion {false};
    std::string _version;
  };
}
#endif //DOCUMENT_ATTRIBUTES_H
