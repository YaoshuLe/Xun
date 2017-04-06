#include "Key.h"
#include "../mxml/Key.h"
#include "../mxml/TraditionalKey.h"
#include "../mxml/Fifths.h"

#include "../mxml/Measure.h"
#include "../mxml/Clef.h"
#include "../mxml/Sign.h"
#include "../mxml/Line.h"
#include <QGraphicsSvgItem>
#include <QDebug>

namespace mgraph
{
  const int KEYSIG_INFO[][14] = {
    {0, 3,-1, 2, 5, 1, 4,  4, 1, 5, 2, 6, 3, 7},//   G2 F5
    {2, 5, 1, 4, 7, 3, 6,  6, 3, 7, 4, 8, 5, 9},//   G1 F4
    {4, 0, 3,-1, 2, 5, 1,  1, 5, 2, 6, 3, 7, 4},//C5    F3
    {5, 1, 4, 0, 3,-1, 2,  2, 6, 3, 7, 4, 8, 5},//C1 G3
    {3, 6, 2, 5, 1, 4, 0,  0, 4, 1, 5, 2, 6, 3},//C2 G4
    {1, 4, 0, 3, 6, 2, 5,  5, 2, 6, 3, 7, 4, 8},//C3 G5 F1
    {6, 2, 5, 1, 4, 0, 3,  3, 0, 4, 1, 5, 2, 6},//C4    F2
  };

  void Key::expand(MSvgRenderer *renderer)
  {
    auto model = std::dynamic_pointer_cast<mxml::Key>(getModel());
    int fifths = 0;
    if(model->getTraditionalKey()) fifths = model->getTraditionalKey()->getFifths()->value();
    int prevFifths = fifths;
    if(model->getParent<mxml::Measure>()->getPrevMeasure()) {
        auto prevKey = model->getParent<mxml::Measure>()->getPrevMeasure()->getKey(model->hasNumber()?model->number():1);
        if(prevKey&&prevKey->getTraditionalKey()) prevFifths = prevKey->getTraditionalKey()->getFifths()->value();
      }
    const int *keySigInfo = KEYSIG_INFO[0];
    auto clef = model->getParent<mxml::Measure>()->getClef(model->hasNumber()?model->number():1);
    switch(clef->getSign()->value()) {
      case mxml::ClefSignEnum::G : {
          int line = 2;
          if(clef->getLine()) line = clef->getLine()->value();
          switch(line) {
            case 1:
              keySigInfo = KEYSIG_INFO[1];break;
            case 2:
              keySigInfo = KEYSIG_INFO[0];break;
            case 3:
              keySigInfo = KEYSIG_INFO[3];break;
            case 4:
              keySigInfo = KEYSIG_INFO[4];break;
            case 5:
              keySigInfo = KEYSIG_INFO[5];break;
            }
          break;
        }
      case mxml::ClefSignEnum::F : {
          int line = 4;
          if(clef->getLine()) line = clef->getLine()->value();
          switch(line) {
            case 1:
              keySigInfo = KEYSIG_INFO[5];break;
            case 2:
              keySigInfo = KEYSIG_INFO[6];break;
            case 3:
              keySigInfo = KEYSIG_INFO[2];break;
            case 4:
              keySigInfo = KEYSIG_INFO[1];break;
            case 5:
              keySigInfo = KEYSIG_INFO[0];break;
            }
          break;
        }
      case mxml::ClefSignEnum::C : {
          int line = 3;
          if(clef->getLine()) line = clef->getLine()->value();
          switch(line) {
            case 1:
              keySigInfo = KEYSIG_INFO[3];break;
            case 2:
              keySigInfo = KEYSIG_INFO[4];break;
            case 3:
              keySigInfo = KEYSIG_INFO[5];break;
            case 4:
              keySigInfo = KEYSIG_INFO[6];break;
            case 5:
              keySigInfo = KEYSIG_INFO[2];break;
            }
          break;
        }
      default:
        break;
      }

    int naturals = 0;
    switch (std::abs(prevFifths)) {
      case 7: naturals = 0x7f; break;
      case 6: naturals = 0x3f; break;
      case 5: naturals = 0x1f; break;
      case 4: naturals = 0xf;  break;
      case 3: naturals = 0x7;  break;
      case 2: naturals = 0x3;  break;
      case 1: naturals = 0x1;  break;
      case 0: naturals = 0;    break;
      }
    int accidentals = 0;
    switch (std::abs(fifths)) {
      case 7: accidentals = 0x7f; break;
      case 6: accidentals = 0x3f; break;
      case 5: accidentals = 0x1f; break;
      case 4: accidentals = 0xf;  break;
      case 3: accidentals = 0x7;  break;
      case 2: accidentals = 0x3;  break;
      case 1: accidentals = 0x1;  break;
      case 0: accidentals = 0;    break;
      }
    if (!((fifths > 0) ^ (prevFifths > 0))) naturals &= ~accidentals;//Exclusive OR

    {
      auto *strap = new Symbol();
      for (int i = 0; i < 7; ++i) {
          if (naturals & (1 << i)) {
              if (prevFifths < 0) {
                  QGraphicsSvgItem *item = new QGraphicsSvgItem();
                  item->setSharedRenderer(renderer);
                  item->setElementId(QLatin1String("uniE261"));
                  item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                  item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalNatural").y()*renderer->spatium()), true);
                  item->setTransform(QTransform().translate(0, -0.5*keySigInfo[i+7]*renderer->spatium()), true);
                  strap->addToGroup(item, Qt::AnchorLeft);
                }else {
                  QGraphicsSvgItem *item = new QGraphicsSvgItem();
                  item->setSharedRenderer(renderer);
                  item->setElementId(QLatin1String("uniE261"));
                  item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                  item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalNatural").y()*renderer->spatium()), true);
                  item->setTransform(QTransform().translate(0, -0.5*keySigInfo[i]*renderer->spatium()), true);
                  strap->addToGroup(item, Qt::AnchorLeft);
                }
            }
        }
      addToGroup(strap, Qt::AnchorRight);
    }

    {
      auto *strap = new Symbol();
      switch(fifths) {
        case 7: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE262"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalSharp").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[6]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
          }
        case 6: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE262"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalSharp").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[5]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
          }
        case 5: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE262"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalSharp").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[4]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
          }
        case 4: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE262"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalSharp").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[3]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
          }
        case 3: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE262"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalSharp").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[2]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
          }
        case 2: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE262"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalSharp").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[1]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
          }
        case 1: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE262"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalSharp").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[0]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
            break;
          }
        case -7: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE260"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalFlat").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[13]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
          }
        case -6: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE260"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalFlat").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[12]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
          }
        case -5: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE260"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalFlat").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[11]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
          }
        case -4: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE260"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalFlat").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[10]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
          }
        case -3: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE260"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalFlat").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[9]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
          }
        case -2: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE260"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalFlat").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[8]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
          }
        case -1: {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE260"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("accidentalFlat").y()*renderer->spatium()), true);
            item->setTransform(QTransform().translate(0, -0.5*keySigInfo[7]*renderer->spatium()), true);
            strap->addToGroup(item, Qt::AnchorLeft);
            break;
          }
        }
      addToGroup(strap, Qt::AnchorRight);
    }
  }
}
