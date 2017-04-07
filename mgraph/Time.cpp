#include "Time.h"
#include "../mxml/Time.h"
#include "../mxml/TimeSignature.h"
#include "../mxml/Interchangeable.h"
#include "../mxml/Beats.h"
#include "../mxml/BeatType.h"
#include "../mxml/SenzaMisura.h"

#include "../mxml/Measure.h"
#include "../mxml/StaffDetails.h"
#include "../mxml/StaffLines.h"
#include <QGraphicsSvgItem>
#include <QDebug>

namespace mgraph
{
  class Beats: public Symbol
  {
  public:
    void expand(MSvgRenderer *renderer)
    {
      auto model = std::dynamic_pointer_cast<mxml::Beats>(getModel());
      for(auto c : model->value()) {
          switch(c) {
            case '0': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE080"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig0").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '1': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE081"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig1").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '2': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE082"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig2").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '3': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE083"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig3").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '4': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE084"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig4").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '5': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE085"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig5").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '6': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE086"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig6").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '7': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE087"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig7").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '8': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE088"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig8").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '9': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE089"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig9").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '+': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE08C"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSigPlus").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            }
        }
    }
  };
  class BeatType: public Symbol
  {
  public:
    void expand(MSvgRenderer *renderer)
    {
      auto model = std::dynamic_pointer_cast<mxml::BeatType>(getModel());
      for(auto c : model->value()) {
          switch(c) {
            case '0': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE080"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig0").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '1': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE081"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig1").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '2': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE082"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig2").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '3': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE083"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig3").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '4': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE084"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig4").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '5': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE085"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig5").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '6': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE086"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig6").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '7': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE087"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig7").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '8': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE088"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig8").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '9': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE089"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig9").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            }
        }
    }
  };
  class SenzaMisura: public Symbol
  {
  public:
    void expand(MSvgRenderer *renderer)
    {
      auto model = std::dynamic_pointer_cast<mxml::SenzaMisura>(getModel());
      for(auto c : model->value()) {
          switch(c) {
            case '0': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE080"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig0").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '1': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE081"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig1").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '2': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE082"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig2").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '3': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE083"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig3").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '4': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE084"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig4").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '5': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE085"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig5").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '6': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE086"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig6").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '7': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE087"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig7").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '8': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE088"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig8").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case '9': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE089"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSig9").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            case 'x': {
                QGraphicsSvgItem *item = new QGraphicsSvgItem();
                item->setSharedRenderer(renderer);
                item->setElementId(QLatin1String("uniE09C"));
                item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSigX").y()*renderer->spatium()), true);
                addToGroup(item, Qt::AnchorRight);
                break;
              }
            }
        }
    }
  };

  void Time::expand(MSvgRenderer *renderer)
  {
    auto model = std::dynamic_pointer_cast<mxml::Time>(getModel());
    if(model->getSenzaMisura()) {
        auto *item = new SenzaMisura();
        item->setModel(model->getSenzaMisura());
        item->expand(renderer);
        addToGroup(item);
      }else {
        if(model->symbol()==mxml::TimeSymbolEnum::Common) {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE08A"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSigCommon").y()*renderer->spatium()), true);
            addToGroup(item);
          }else if(model->symbol()==mxml::TimeSymbolEnum::Cut) {
            QGraphicsSvgItem *item = new QGraphicsSvgItem();
            item->setSharedRenderer(renderer);
            item->setElementId(QLatin1String("uniE08B"));
            item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
            item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSigCutCommon").y()*renderer->spatium()), true);
            addToGroup(item);
          }else if((!model->hasSymbol())||(model->symbol()==mxml::TimeSymbolEnum::Normal)) {
            for(auto item : model->getTimeSignatureSet()) {
                if(item!=model->getTimeSignatureSet().front()) {
                    QGraphicsSvgItem *item = new QGraphicsSvgItem();
                    item->setSharedRenderer(renderer);
                    item->setElementId(QLatin1String("uniE08C"));
                    item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSigPlus").y()*renderer->spatium()), true);
                    addToGroup(item, Qt::AnchorRight);
                  }
                Symbol *strap = new Symbol();
                auto *beats = new Beats();
                beats->setModel(item->getBeats());
                beats->expand(renderer);
                beats->setTransform(QTransform().translate(0, -renderer->magnification()*renderer->spatium()));
                strap->addToGroup(beats, Qt::AnchorHorizontalCenter);
                auto *beatType = new BeatType();
                beatType->setModel(item->getBeatType());
                beatType->expand(renderer);
                beatType->setTransform(QTransform().translate(0, renderer->magnification()*renderer->spatium()));
                strap->addToGroup(beatType, Qt::AnchorHorizontalCenter);
                addToGroup(strap, Qt::AnchorRight);
              }
            if(model->getInterchangeable()) {
                {
                  QGraphicsSvgItem *item = new QGraphicsSvgItem();
                  item->setSharedRenderer(renderer);
                  item->setElementId(QLatin1String("uniE094"));
                  item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                  item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSigParensLeft").y()*renderer->spatium()), true);
                  addToGroup(item, Qt::AnchorRight);
                }
                for(auto item : model->getInterchangeable()->getTimeSignatureSet()) {
                    if(item!=model->getInterchangeable()->getTimeSignatureSet().front())  {
                        QGraphicsSvgItem *item = new QGraphicsSvgItem();
                        item->setSharedRenderer(renderer);
                        item->setElementId(QLatin1String("uniE08C"));
                        item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                        item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSigPlus").y()*renderer->spatium()), true);
                        addToGroup(item, Qt::AnchorRight);
                      }
                    Symbol *strap = new Symbol();
                    auto *beats = new Beats();
                    beats->setModel(item->getBeats());
                    beats->expand(renderer);
                    beats->setTransform(QTransform().translate(0, -renderer->magnification()*renderer->spatium()));
                    strap->addToGroup(beats, Qt::AnchorHorizontalCenter);
                    auto *beatType = new BeatType();
                    beatType->setModel(item->getBeatType());
                    beatType->expand(renderer);
                    beatType->setTransform(QTransform().translate(0, renderer->magnification()*renderer->spatium()));
                    strap->addToGroup(beatType, Qt::AnchorHorizontalCenter);
                    addToGroup(strap, Qt::AnchorRight);
                  }
                {
                  QGraphicsSvgItem *item = new QGraphicsSvgItem();
                  item->setSharedRenderer(renderer);
                  item->setElementId(QLatin1String("uniE095"));
                  item->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                  item->setTransform(QTransform().translate(0, renderer->bboxsw("timeSigParensRight").y()*renderer->spatium()), true);
                  addToGroup(item, Qt::AnchorRight);
                }
              }
          }
        int staffLines = 5;
        auto staffDetails = model->getParent<mxml::Measure>()->getStaffDetails(model->hasNumber()?model->number():1);
        if(staffDetails&&staffDetails->getStaffLines()) staffLines = staffDetails->getStaffLines()->value();
        setTransform(QTransform().translate(0, 0.5*(staffLines-1)*renderer->magnification()*renderer->spatium()));
      }
  }
}
