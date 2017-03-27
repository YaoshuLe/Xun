#ifndef SYSTEM_LAYOUT_H
#define SYSTEM_LAYOUT_H
#include "Element.h"

namespace mxml
{
  class SystemMargins;
  using SystemMarginsPtr = std::shared_ptr<SystemMargins>;
  class SystemDistance;
  using SystemDistancePtr = std::shared_ptr<SystemDistance>;
  class TopSystemDistance;
  using TopSystemDistancePtr = std::shared_ptr<TopSystemDistance>;
  class SystemDividers;
  using SystemDividersPtr = std::shared_ptr<SystemDividers>;

  class SystemLayout: public Element
  {
  public:
    SystemLayout();
    virtual const char* tagname() const { return "system-layout"; }
    SystemMarginsPtr getSystemMargins() const;
    void setSystemMargins(const SystemMarginsPtr& value);
    SystemDistancePtr getSystemDistance() const;
    void setSystemDistance(const SystemDistancePtr& value);
    TopSystemDistancePtr getTopSystemDistance() const;
    void setTopSystemDistance(const TopSystemDistancePtr& value);
    SystemDividersPtr getSystemDividers() const;
    void setSystemDividers(const SystemDividersPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    SystemMarginsPtr _systemMarginsPtr;
    SystemDistancePtr _systemDistancePtr;
    TopSystemDistancePtr _topSystemDistancePtr;
    SystemDividersPtr _systemDividersPtr;
  };
}
#endif //SYSTEM_LAYOUT_H
