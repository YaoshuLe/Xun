#ifndef GROUPING_H
#define GROUPING_H
#include "Element.h"

namespace mxml
{
  class Feature;
  using FeaturePtr = std::shared_ptr<Feature>;
  using FeatureSet = std::vector<FeaturePtr>;

  class Grouping: public Element
  {
  public:
    Grouping();
    virtual const char* tagname() const { return "grouping"; }
    const FeatureSet& getFeatureSet() const;
    void removeFeature(const FeaturePtr& value);
    void addFeature(const FeaturePtr& value);
    void clearFeatureSet();
    bool hasType() const;
    void hasType(bool value);
    StartStopSingleEnum type() const;
    void type(StartStopSingleEnum value);
    bool hasNumber() const;
    void hasNumber(bool value);
    std::string number() const;
    void number(std::string value);
    bool hasMemberOf() const;
    void hasMemberOf(bool value);
    std::string memberOf() const;
    void memberOf(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    FeatureSet _featureSet;
    bool _hasType {false};
    StartStopSingleEnum _type;
    bool _hasNumber {false};
    std::string _number;
    bool _hasMemberOf {false};
    std::string _memberOf;
  };
}
#endif //GROUPING_H
