#ifndef NOTE_TYPE_H
#define NOTE_TYPE_H
#include "Element.h"

namespace mxml
{
  class NoteType: public Value<NoteTypeValueEnum>
  {
  public:
    NoteType();
    virtual const char* tagname() const { return "note-type"; }
    bool hasSize() const;
    void hasSize(bool value);
    SymbolSizeEnum size() const;
    void size(SymbolSizeEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasSize {false};
    SymbolSizeEnum _size;
  };
}
#endif //NOTE_TYPE_H
