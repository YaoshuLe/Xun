#ifndef SCORE_PARTWISE_H
#define SCORE_PARTWISE_H
#include "Element.h"
#include "DocumentAttributes.h"

namespace mxml
{
  class Work;
  using WorkPtr = std::shared_ptr<Work>;
  class MovementNumber;
  using MovementNumberPtr = std::shared_ptr<MovementNumber>;
  class MovementTitle;
  using MovementTitlePtr = std::shared_ptr<MovementTitle>;
  class Identification;
  using IdentificationPtr = std::shared_ptr<Identification>;
  class Defaults;
  using DefaultsPtr = std::shared_ptr<Defaults>;
  class Credit;
  using CreditPtr = std::shared_ptr<Credit>;
  using CreditSet = std::vector<CreditPtr>;
  using PartList = Element;
  using PartListPtr = std::shared_ptr<PartList>;
  using PartListSet = std::vector<PartListPtr>;
  class Part;
  using PartPtr = std::shared_ptr<Part>;
  using PartSet = std::vector<PartPtr>;

  class ScorePartwise: public Element, public DocumentAttributes
  {
  public:
    ScorePartwise();
    virtual const char* tagname() const { return "score-partwise"; }
    WorkPtr getWork() const;
    void setWork(const WorkPtr& value);
    MovementNumberPtr getMovementNumber() const;
    void setMovementNumber(const MovementNumberPtr& value);
    MovementTitlePtr getMovementTitle() const;
    void setMovementTitle(const MovementTitlePtr& value);
    IdentificationPtr getIdentification() const;
    void setIdentification(const IdentificationPtr& value);
    DefaultsPtr getDefaults() const;
    void setDefaults(const DefaultsPtr& value);
    const CreditSet& getCreditSet() const;
    void removeCredit(const CreditPtr& value);
    void addCredit(const CreditPtr& value);
    void clearCreditSet();
    const PartListSet& getPartListSet() const;
    void removePartList(const PartListPtr& value);
    void addPartList(const PartListPtr& value);
    void clearPartListSet();
    const PartSet& getPartSet() const;
    void removePart(const PartPtr& value);
    void addPart(const PartPtr& value);
    void clearPartSet();
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    WorkPtr _workPtr;
    MovementNumberPtr _movementNumberPtr;
    MovementTitlePtr _movementTitlePtr;
    IdentificationPtr _identificationPtr;
    DefaultsPtr _defaultsPtr;
    CreditSet _creditSet;
    PartListSet _partListSet;
    PartSet _partSet;
  };
}
#endif //SCORE_PARTWISE_H
