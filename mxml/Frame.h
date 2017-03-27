#ifndef FRAME_H
#define FRAME_H
#include "Element.h"
#include "Position.h"
#include "Color.h"
#include "Halign.h"
#include "ValignImage.h"

namespace mxml
{
  class FrameStrings;
  using FrameStringsPtr = std::shared_ptr<FrameStrings>;
  class FrameFrets;
  using FrameFretsPtr = std::shared_ptr<FrameFrets>;
  class FirstFret;
  using FirstFretPtr = std::shared_ptr<FirstFret>;
  class FrameNote;
  using FrameNotePtr = std::shared_ptr<FrameNote>;
  using FrameNoteSet = std::vector<FrameNotePtr>;

  class Frame: public Element, public Position, public Color, public Halign, public ValignImage
  {
  public:
    Frame();
    virtual const char* tagname() const { return "frame"; }
    FrameStringsPtr getFrameStrings() const;
    void setFrameStrings(const FrameStringsPtr& value);
    FrameFretsPtr getFrameFrets() const;
    void setFrameFrets(const FrameFretsPtr& value);
    FirstFretPtr getFirstFret() const;
    void setFirstFret(const FirstFretPtr& value);
    const FrameNoteSet& getFrameNoteSet() const;
    void removeFrameNote(const FrameNotePtr& value);
    void addFrameNote(const FrameNotePtr& value);
    void clearFrameNoteSet();
    bool hasHeight() const;
    void hasHeight(bool value);
    float height() const;
    void height(float value);
    bool hasWidth() const;
    void hasWidth(bool value);
    float width() const;
    void width(float value);
    bool hasUnplayed() const;
    void hasUnplayed(bool value);
    std::string unplayed() const;
    void unplayed(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    FrameStringsPtr _frameStringsPtr;
    FrameFretsPtr _frameFretsPtr;
    FirstFretPtr _firstFretPtr;
    FrameNoteSet _frameNoteSet;
    bool _hasHeight {false};
    float _height;
    bool _hasWidth {false};
    float _width;
    bool _hasUnplayed {false};
    std::string _unplayed;
  };
}
#endif //FRAME_H
