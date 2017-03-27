#include "MidiDevice.h"
#include <cstring>

namespace mxml
{
  MidiDevice::MidiDevice() {}
  bool MidiDevice::hasPort() const { return _hasPort; }
  void MidiDevice::hasPort(bool value) { _hasPort = value; }
  int MidiDevice::port() const { return _port; }
  void MidiDevice::port(int value) { _port = value; }
  bool MidiDevice::hasId() const { return _hasId; }
  void MidiDevice::hasId(bool value) { _hasId = value; }
  std::string MidiDevice::id() const { return _id; }
  void MidiDevice::id(std::string value) { _id = value; }

  void MidiDevice::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasPort) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _port);
      self.append_attribute("port").set_value(str);
    }
    if(_hasId) {
      self.append_attribute("id").set_value(_id.c_str());
    }
  }
  void MidiDevice::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("port")) {
      _port = attr.as_int();
      _hasPort = true;
    }
    if(auto attr = self.attribute("id")) {
      _id = attr.as_string();
      _hasId = true;
    }
  }
}
