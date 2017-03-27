#ifndef NOTATIONS_H
#define NOTATIONS_H
#include "Element.h"
#include "PrintObject.h"

namespace mxml
{
  using Notation = Element;
  using NotationPtr = std::shared_ptr<Notation>;
  using NotationSet = std::vector<NotationPtr>;
  class Footnote;
  using FootnotePtr = std::shared_ptr<Footnote>;
  class Level;
  using LevelPtr = std::shared_ptr<Level>;
  class Tied;
  using TiedPtr = std::shared_ptr<Tied>;
  class Slur;
  using SlurPtr = std::shared_ptr<Slur>;
  class Tuplet;
  using TupletPtr = std::shared_ptr<Tuplet>;
  class Glissando;
  using GlissandoPtr = std::shared_ptr<Glissando>;
  class Slide;
  using SlidePtr = std::shared_ptr<Slide>;
  class Ornaments;
  using OrnamentsPtr = std::shared_ptr<Ornaments>;
  class Technicals;
  using TechnicalsPtr = std::shared_ptr<Technicals>;
  class Articulations;
  using ArticulationsPtr = std::shared_ptr<Articulations>;
  class Dynamics;
  using DynamicsPtr = std::shared_ptr<Dynamics>;
  class Fermata;
  using FermataPtr = std::shared_ptr<Fermata>;
  class Arpeggiate;
  using ArpeggiatePtr = std::shared_ptr<Arpeggiate>;
  class NonArpeggiate;
  using NonArpeggiatePtr = std::shared_ptr<NonArpeggiate>;
  class AccidentalMark;
  using AccidentalMarkPtr = std::shared_ptr<AccidentalMark>;
  class OtherNotation;
  using OtherNotationPtr = std::shared_ptr<OtherNotation>;

  class Notations: public Element, public PrintObject
  {
  public:
    Notations();
    virtual const char* tagname() const { return "notations"; }
    FootnotePtr getFootnote() const;
    void setFootnote(const FootnotePtr& value);
    LevelPtr getLevel() const;
    void setLevel(const LevelPtr& value);
    const NotationSet& getNotationSet() const;
    void removeNotation(const NotationPtr& value);
    void addNotation(const NotationPtr& value);
    void clearNotationSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    FootnotePtr _footnotePtr;
    LevelPtr _levelPtr;
    NotationSet _notationSet;
  };
}
#endif //NOTATIONS_H
