#ifndef OTHER_DYNAMICS_H
#define OTHER_DYNAMICS_H
#include "Element.h"

namespace mxml
{
  class OtherDynamics: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "other-dynamics"; }
  };
}
#endif //OTHER_DYNAMICS_H
