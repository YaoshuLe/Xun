#ifndef NOTE_SIZE_H
#define NOTE_SIZE_H
#include "Element.h"

namespace mxml
{
  class NoteSize: public Value<float>
  {
  public:
    NoteSize();
    virtual const char* tagname() const { return "note-size"; }
    bool hasType() const;
    void hasType(bool value);
    NoteSizeTypeEnum type() const;
    void type(NoteSizeTypeEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    NoteSizeTypeEnum _type;
  };
}
#endif //NOTE_SIZE_H
