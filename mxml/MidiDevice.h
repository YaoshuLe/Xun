#ifndef MIDI_DEVICE_H
#define MIDI_DEVICE_H
#include "Element.h"

namespace mxml
{
  class MidiDevice: public Value<std::string>
  {
  public:
    MidiDevice();
    virtual const char* tagname() const { return "midi-device"; }
    bool hasPort() const;
    void hasPort(bool value);
    int port() const;
    void port(int value);
    bool hasId() const;
    void hasId(bool value);
    std::string id() const;
    void id(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasPort {false};
    int _port;
    bool _hasId {false};
    std::string _id;
  };
}
#endif //MIDI_DEVICE_H
