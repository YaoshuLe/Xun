#ifndef NON_TRADITIONAL_KEY_H
#define NON_TRADITIONAL_KEY_H
#include "Element.h"

namespace mxml
{
  class KeyStep;
  using KeyStepPtr = std::shared_ptr<KeyStep>;
  class KeyAlter;
  using KeyAlterPtr = std::shared_ptr<KeyAlter>;
  class KeyAccidental;
  using KeyAccidentalPtr = std::shared_ptr<KeyAccidental>;

  class NonTraditionalKey: public Element
  {
  public:
    NonTraditionalKey();
    virtual const char* tagname() const { return "non-traditional-key"; }
    KeyStepPtr getKeyStep() const;
    void setKeyStep(const KeyStepPtr& value);
    KeyAlterPtr getKeyAlter() const;
    void setKeyAlter(const KeyAlterPtr& value);
    KeyAccidentalPtr getKeyAccidental() const;
    void setKeyAccidental(const KeyAccidentalPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    KeyStepPtr _keyStepPtr;
    KeyAlterPtr _keyAlterPtr;
    KeyAccidentalPtr _keyAccidentalPtr;
  };
}
#endif //NON_TRADITIONAL_KEY_H
