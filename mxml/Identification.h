#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H
#include "Element.h"

namespace mxml
{
  class Creator;
  using CreatorPtr = std::shared_ptr<Creator>;
  using CreatorSet = std::vector<CreatorPtr>;
  class Rights;
  using RightsPtr = std::shared_ptr<Rights>;
  using RightsSet = std::vector<RightsPtr>;
  using Encoding = Element;
  using EncodingPtr = std::shared_ptr<Encoding>;
  using EncodingSet = std::vector<EncodingPtr>;
  class Source;
  using SourcePtr = std::shared_ptr<Source>;
  class Relation;
  using RelationPtr = std::shared_ptr<Relation>;
  using RelationSet = std::vector<RelationPtr>;
  class Miscellaneous;
  using MiscellaneousPtr = std::shared_ptr<Miscellaneous>;

  class Identification: public Element
  {
  public:
    Identification();
    virtual const char* tagname() const { return "identification"; }
    const CreatorSet& getCreatorSet() const;
    void removeCreator(const CreatorPtr& value);
    void addCreator(const CreatorPtr& value);
    void clearCreatorSet();
    const RightsSet& getRightsSet() const;
    void removeRights(const RightsPtr& value);
    void addRights(const RightsPtr& value);
    void clearRightsSet();
    const EncodingSet& getEncodingSet() const;
    void removeEncoding(const EncodingPtr& value);
    void addEncoding(const EncodingPtr& value);
    void clearEncodingSet();
    SourcePtr getSource() const;
    void setSource(const SourcePtr& value);
    const RelationSet& getRelationSet() const;
    void removeRelation(const RelationPtr& value);
    void addRelation(const RelationPtr& value);
    void clearRelationSet();
    MiscellaneousPtr getMiscellaneous() const;
    void setMiscellaneous(const MiscellaneousPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    CreatorSet _creatorSet;
    RightsSet _rightsSet;
    EncodingSet _encodingSet;
    SourcePtr _sourcePtr;
    RelationSet _relationSet;
    MiscellaneousPtr _miscellaneousPtr;
  };
}
#endif //IDENTIFICATION_H
