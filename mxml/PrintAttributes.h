#ifndef PRINT_ATTRIBUTES_H
#define PRINT_ATTRIBUTES_H
#include "AttrGroup.h"

namespace mxml
{
  class PrintAttributes: public AttrGroup
  {
  public:
    PrintAttributes();
    bool hasStaffSpacing() const;
    void hasStaffSpacing(bool value);
    float staffSpacing() const;
    void staffSpacing(float value);
    bool hasNewSystem() const;
    void hasNewSystem(bool value);
    YesNoEnum newSystem() const;
    void newSystem(YesNoEnum value);
    bool hasNewPage() const;
    void hasNewPage(bool value);
    YesNoEnum newPage() const;
    void newPage(YesNoEnum value);
    bool hasBlankPage() const;
    void hasBlankPage(bool value);
    int blankPage() const;
    void blankPage(int value);
    bool hasPageNumber() const;
    void hasPageNumber(bool value);
    std::string pageNumber() const;
    void pageNumber(std::string value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasStaffSpacing {false};
    float _staffSpacing;
    bool _hasNewSystem {false};
    YesNoEnum _newSystem;
    bool _hasNewPage {false};
    YesNoEnum _newPage;
    bool _hasBlankPage {false};
    int _blankPage;
    bool _hasPageNumber {false};
    std::string _pageNumber;
  };
}
#endif //PRINT_ATTRIBUTES_H
