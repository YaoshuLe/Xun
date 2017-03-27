#ifndef HARP_PEDALS_H
#define HARP_PEDALS_H
#include "Element.h"
#include "PrintStyleAlign.h"

namespace mxml
{
  class PedalTuning;
  using PedalTuningPtr = std::shared_ptr<PedalTuning>;
  using PedalTuningSet = std::vector<PedalTuningPtr>;

  class HarpPedals: public Element, public PrintStyleAlign
  {
  public:
    HarpPedals();
    virtual const char* tagname() const { return "harp-pedals"; }
    const PedalTuningSet& getPedalTuningSet() const;
    void removePedalTuning(const PedalTuningPtr& value);
    void addPedalTuning(const PedalTuningPtr& value);
    void clearPedalTuningSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    PedalTuningSet _pedalTuningSet;
  };
}
#endif //HARP_PEDALS_H
