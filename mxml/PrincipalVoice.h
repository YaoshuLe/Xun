#ifndef PRINCIPAL_VOICE_H
#define PRINCIPAL_VOICE_H
#include "Element.h"
#include "PrintStyleAlign.h"

namespace mxml
{
  class PrincipalVoice: public Value<std::string>, public PrintStyleAlign
  {
  public:
    PrincipalVoice();
    virtual const char* tagname() const { return "principal-voice"; }
    bool hasType() const;
    void hasType(bool value);
    StartStopEnum type() const;
    void type(StartStopEnum value);
    bool hasSymbol() const;
    void hasSymbol(bool value);
    PrincipalVoiceSymbolEnum symbol() const;
    void symbol(PrincipalVoiceSymbolEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    StartStopEnum _type;
    bool _hasSymbol {false};
    PrincipalVoiceSymbolEnum _symbol;
  };
}
#endif //PRINCIPAL_VOICE_H
