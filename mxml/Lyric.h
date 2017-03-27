#ifndef LYRIC_H
#define LYRIC_H
#include "Element.h"
#include "Justify.h"
#include "Position.h"
#include "Placement.h"
#include "Color.h"
#include "PrintObject.h"

namespace mxml
{
  class Syllabic;
  using SyllabicPtr = std::shared_ptr<Syllabic>;
  class Text;
  using TextPtr = std::shared_ptr<Text>;
  class Extend;
  using ExtendPtr = std::shared_ptr<Extend>;
  class Laughing;
  using LaughingPtr = std::shared_ptr<Laughing>;
  class Humming;
  using HummingPtr = std::shared_ptr<Humming>;
  class EndLine;
  using EndLinePtr = std::shared_ptr<EndLine>;
  class EndParagraph;
  using EndParagraphPtr = std::shared_ptr<EndParagraph>;
  class Footnote;
  using FootnotePtr = std::shared_ptr<Footnote>;
  class Level;
  using LevelPtr = std::shared_ptr<Level>;

  class Lyric: public Element, public Justify, public Position, public Placement, public Color, public PrintObject
  {
  public:
    Lyric();
    virtual const char* tagname() const { return "lyric"; }
    SyllabicPtr getSyllabic() const;
    void setSyllabic(const SyllabicPtr& value);
    TextPtr getText() const;
    void setText(const TextPtr& value);
    ExtendPtr getExtend() const;
    void setExtend(const ExtendPtr& value);
    LaughingPtr getLaughing() const;
    void setLaughing(const LaughingPtr& value);
    HummingPtr getHumming() const;
    void setHumming(const HummingPtr& value);
    EndLinePtr getEndLine() const;
    void setEndLine(const EndLinePtr& value);
    EndParagraphPtr getEndParagraph() const;
    void setEndParagraph(const EndParagraphPtr& value);
    FootnotePtr getFootnote() const;
    void setFootnote(const FootnotePtr& value);
    LevelPtr getLevel() const;
    void setLevel(const LevelPtr& value);
    bool hasNumber() const;
    void hasNumber(bool value);
    std::string number() const;
    void number(std::string value);
    bool hasName() const;
    void hasName(bool value);
    std::string name() const;
    void name(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    SyllabicPtr _syllabicPtr;
    TextPtr _textPtr;
    ExtendPtr _extendPtr;
    LaughingPtr _laughingPtr;
    HummingPtr _hummingPtr;
    EndLinePtr _endLinePtr;
    EndParagraphPtr _endParagraphPtr;
    FootnotePtr _footnotePtr;
    LevelPtr _levelPtr;
    bool _hasNumber {false};
    std::string _number;
    bool _hasName {false};
    std::string _name;
  };
}
#endif //LYRIC_H
