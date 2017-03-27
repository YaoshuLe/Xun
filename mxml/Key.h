#ifndef KEY_H
#define KEY_H
#include "Element.h"
#include "PrintStyle.h"
#include "PrintObject.h"

namespace mxml
{
  class TraditionalKey;
  using TraditionalKeyPtr = std::shared_ptr<TraditionalKey>;
  class NonTraditionalKey;
  using NonTraditionalKeyPtr = std::shared_ptr<NonTraditionalKey>;
  using NonTraditionalKeySet = std::vector<NonTraditionalKeyPtr>;
  class KeyOctave;
  using KeyOctavePtr = std::shared_ptr<KeyOctave>;
  using KeyOctaveSet = std::vector<KeyOctavePtr>;

  class Key: public Element, public PrintStyle, public PrintObject
  {
  public:
    Key();
    virtual const char* tagname() const { return "key"; }
    TraditionalKeyPtr getTraditionalKey() const;
    void setTraditionalKey(const TraditionalKeyPtr& value);
    const NonTraditionalKeySet& getNonTraditionalKeySet() const;
    void removeNonTraditionalKey(const NonTraditionalKeyPtr& value);
    void addNonTraditionalKey(const NonTraditionalKeyPtr& value);
    void clearNonTraditionalKeySet();
    const KeyOctaveSet& getKeyOctaveSet() const;
    void removeKeyOctave(const KeyOctavePtr& value);
    void addKeyOctave(const KeyOctavePtr& value);
    void clearKeyOctaveSet();
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    TraditionalKeyPtr _traditionalKeyPtr;
    NonTraditionalKeySet _nonTraditionalKeySet;
    KeyOctaveSet _keyOctaveSet;
    bool _hasNumber {false};
    int _number;
  };
}
#endif //KEY_H
