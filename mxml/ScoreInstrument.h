#ifndef SCORE_INSTRUMENT_H
#define SCORE_INSTRUMENT_H
#include "Element.h"

namespace mxml
{
  class InstrumentName;
  using InstrumentNamePtr = std::shared_ptr<InstrumentName>;
  class InstrumentAbbreviation;
  using InstrumentAbbreviationPtr = std::shared_ptr<InstrumentAbbreviation>;
  class InstrumentSound;
  using InstrumentSoundPtr = std::shared_ptr<InstrumentSound>;
  class Solo;
  using SoloPtr = std::shared_ptr<Solo>;
  class Ensemble;
  using EnsemblePtr = std::shared_ptr<Ensemble>;
  class VirtualInstrument;
  using VirtualInstrumentPtr = std::shared_ptr<VirtualInstrument>;

  class ScoreInstrument: public Element
  {
  public:
    ScoreInstrument();
    virtual const char* tagname() const { return "score-instrument"; }
    InstrumentNamePtr getInstrumentName() const;
    void setInstrumentName(const InstrumentNamePtr& value);
    InstrumentAbbreviationPtr getInstrumentAbbreviation() const;
    void setInstrumentAbbreviation(const InstrumentAbbreviationPtr& value);
    InstrumentSoundPtr getInstrumentSound() const;
    void setInstrumentSound(const InstrumentSoundPtr& value);
    SoloPtr getSolo() const;
    void setSolo(const SoloPtr& value);
    EnsemblePtr getEnsemble() const;
    void setEnsemble(const EnsemblePtr& value);
    VirtualInstrumentPtr getVirtualInstrument() const;
    void setVirtualInstrument(const VirtualInstrumentPtr& value);
    bool hasId() const;
    void hasId(bool value);
    std::string id() const;
    void id(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    InstrumentNamePtr _instrumentNamePtr;
    InstrumentAbbreviationPtr _instrumentAbbreviationPtr;
    InstrumentSoundPtr _instrumentSoundPtr;
    SoloPtr _soloPtr;
    EnsemblePtr _ensemblePtr;
    VirtualInstrumentPtr _virtualInstrumentPtr;
    bool _hasId {false};
    std::string _id;
  };
}
#endif //SCORE_INSTRUMENT_H
