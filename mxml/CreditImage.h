#ifndef CREDIT_IMAGE_H
#define CREDIT_IMAGE_H
#include "Image.h"

namespace mxml
{
  class CreditImage: public Image
  {
  public:
    virtual const char* tagname() const { return "credit-image"; }
  };
}
#endif //CREDIT_IMAGE_H
