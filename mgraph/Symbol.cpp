#include "Symbol.h"

namespace mgraph
{
  Symbol::Symbol(QGraphicsItem *parent)
    :QGraphicsItemGroup(parent)
  {
  }
  void Symbol::addToGroup(QGraphicsItem *item, Qt::AnchorPoint anchor)
  {
    if(anchor==Qt::AnchorHorizontalCenter) {
        int width = item->mapRectToParent(item->boundingRect()).width()>boundingRect().width() ?
              item->mapRectToParent(item->boundingRect()).width():boundingRect().width();
        QGraphicsItemGroup::addToGroup(item);
        for(auto item:childItems()) {
            item->setX((width-item->mapRectToParent(item->boundingRect()).width())*0.5);
          }
      }else if(anchor==Qt::AnchorRight) {
        item->setX(boundingRect().width());
        QGraphicsItemGroup::addToGroup(item);
      }else if(anchor==Qt::AnchorLeft) {
        item->setX(boundingRect().width());
        QGraphicsItemGroup::addToGroup(item);
        int width = boundingRect().width();
        for(auto item:childItems()) {
            width-=item->mapRectToParent(item->boundingRect()).width();
            item->setX(width);
          }
      }
  }
  void Symbol::setModel(const mxml::ElementPtr& model)
  {
    _model = model;
  }
  mxml::ElementPtr Symbol::getModel() const
  {
    return _model;
  }
  void Symbol::expand(MSvgRenderer *renderer)
  {
    Q_UNUSED(renderer)
  }
}
