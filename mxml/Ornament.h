#ifndef ORNAMENT_H
#define ORNAMENT_H
#include "Element.h"

namespace mxml
{
  class TrillMark;
  using TrillMarkPtr = std::shared_ptr<TrillMark>;
  class Turn;
  using TurnPtr = std::shared_ptr<Turn>;
  class DelayedTurn;
  using DelayedTurnPtr = std::shared_ptr<DelayedTurn>;
  class InvertedTurn;
  using InvertedTurnPtr = std::shared_ptr<InvertedTurn>;
  class DelayedInvertedTurn;
  using DelayedInvertedTurnPtr = std::shared_ptr<DelayedInvertedTurn>;
  class VerticalTurn;
  using VerticalTurnPtr = std::shared_ptr<VerticalTurn>;
  class Shake;
  using ShakePtr = std::shared_ptr<Shake>;
  class WavyLine;
  using WavyLinePtr = std::shared_ptr<WavyLine>;
  class Mordent;
  using MordentPtr = std::shared_ptr<Mordent>;
  class InvertedMordent;
  using InvertedMordentPtr = std::shared_ptr<InvertedMordent>;
  class Schleifer;
  using SchleiferPtr = std::shared_ptr<Schleifer>;
  class Tremolo;
  using TremoloPtr = std::shared_ptr<Tremolo>;
  class OtherOrnament;
  using OtherOrnamentPtr = std::shared_ptr<OtherOrnament>;
  class AccidentalMark;
  using AccidentalMarkPtr = std::shared_ptr<AccidentalMark>;
  using AccidentalMarkSet = std::vector<AccidentalMarkPtr>;

  class Ornament: public Element
  {
  public:
    Ornament();
    virtual const char* tagname() const { return "ornament"; }
    TrillMarkPtr getTrillMark() const;
    void setTrillMark(const TrillMarkPtr& value);
    TurnPtr getTurn() const;
    void setTurn(const TurnPtr& value);
    DelayedTurnPtr getDelayedTurn() const;
    void setDelayedTurn(const DelayedTurnPtr& value);
    InvertedTurnPtr getInvertedTurn() const;
    void setInvertedTurn(const InvertedTurnPtr& value);
    DelayedInvertedTurnPtr getDelayedInvertedTurn() const;
    void setDelayedInvertedTurn(const DelayedInvertedTurnPtr& value);
    VerticalTurnPtr getVerticalTurn() const;
    void setVerticalTurn(const VerticalTurnPtr& value);
    ShakePtr getShake() const;
    void setShake(const ShakePtr& value);
    WavyLinePtr getWavyLine() const;
    void setWavyLine(const WavyLinePtr& value);
    MordentPtr getMordent() const;
    void setMordent(const MordentPtr& value);
    InvertedMordentPtr getInvertedMordent() const;
    void setInvertedMordent(const InvertedMordentPtr& value);
    SchleiferPtr getSchleifer() const;
    void setSchleifer(const SchleiferPtr& value);
    TremoloPtr getTremolo() const;
    void setTremolo(const TremoloPtr& value);
    OtherOrnamentPtr getOtherOrnament() const;
    void setOtherOrnament(const OtherOrnamentPtr& value);
    const AccidentalMarkSet& getAccidentalMarkSet() const;
    void removeAccidentalMark(const AccidentalMarkPtr& value);
    void addAccidentalMark(const AccidentalMarkPtr& value);
    void clearAccidentalMarkSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    TrillMarkPtr _trillMarkPtr;
    TurnPtr _turnPtr;
    DelayedTurnPtr _delayedTurnPtr;
    InvertedTurnPtr _invertedTurnPtr;
    DelayedInvertedTurnPtr _delayedInvertedTurnPtr;
    VerticalTurnPtr _verticalTurnPtr;
    ShakePtr _shakePtr;
    WavyLinePtr _wavyLinePtr;
    MordentPtr _mordentPtr;
    InvertedMordentPtr _invertedMordentPtr;
    SchleiferPtr _schleiferPtr;
    TremoloPtr _tremoloPtr;
    OtherOrnamentPtr _otherOrnamentPtr;
    AccidentalMarkSet _accidentalMarkSet;
  };
}
#endif //ORNAMENT_H
