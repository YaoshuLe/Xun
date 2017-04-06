#ifndef SYMBOL_H_
#define SYMBOL_H_
#include "../mxml/Element.h"
#include "MSvgRenderer.h"
#include <QGraphicsItemGroup>

namespace mxml {
  class Element;
  using ElementPtr = std::shared_ptr<Element>;
}

namespace mgraph
{

  class Symbol : public QGraphicsItemGroup
  {
  public:
    Symbol(QGraphicsItem *parent = Q_NULLPTR);
    void addToGroup(QGraphicsItem *item, Qt::AnchorPoint anchor=Qt::AnchorLeft);
    void setModel(const mxml::ElementPtr& model);
    mxml::ElementPtr getModel() const;
    virtual void expand(MSvgRenderer *renderer);
  private:
    mxml::ElementPtr _model;
  };
}
#endif // SYMBOL_H_
