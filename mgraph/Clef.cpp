#include "Clef.h"
#include "../mxml/Clef.h"
#include "../mxml/Sign.h"
#include "../mxml/Line.h"
#include "../mxml/ClefOctaveChange.h"

#include "../mxml/Measure.h"
#include "../mxml/StaffDetails.h"
#include "../mxml/StaffLines.h"
#include <QGraphicsSvgItem>
#include <QDebug>

namespace mgraph
{
  void Clef::expand(MSvgRenderer *renderer)
  {
    auto model = std::dynamic_pointer_cast<mxml::Clef>(getModel());
    switch(model->getSign()->value()) {
      case mxml::ClefSignEnum::G : {
          int line = 2;
          if(model->getLine()) line = model->getLine()->value();
          if(model->getClefOctaveChange()) {
              switch(model->getClefOctaveChange()->value()) {
                case -2 : {
                    QGraphicsSvgItem *gClef = new QGraphicsSvgItem();
                    gClef->setSharedRenderer(renderer);
                    gClef->setElementId(QLatin1String("uniE050"));
                    gClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    gClef->setTransform(QTransform().translate(0, renderer->bboxsw("gClef").y()*renderer->spatium()), true);
                    addToGroup(gClef);
                    QGraphicsSvgItem *clef15 = new QGraphicsSvgItem();
                    clef15->setSharedRenderer(renderer);
                    clef15->setElementId(QLatin1String("uniE07E"));
                    clef15->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    clef15->setTransform(QTransform().translate(0, (renderer->bboxsw("clef15").y()-renderer->bboxne("clef15").y())*renderer->spatium()), true);
                    clef15->setTransform(QTransform().translate(0, renderer->bboxsw("gClef").y()*renderer->spatium()), true);
                    addToGroup(clef15, Qt::AnchorHorizontalCenter);
                    break;
                  }
                case -1 : {
                    QGraphicsSvgItem *gClef = new QGraphicsSvgItem();
                    gClef->setSharedRenderer(renderer);
                    gClef->setElementId(QLatin1String("uniE050"));
                    gClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    gClef->setTransform(QTransform().translate(0, renderer->bboxsw("gClef").y()*renderer->spatium()), true);
                    addToGroup(gClef);
                    QGraphicsSvgItem *clef8 = new QGraphicsSvgItem();
                    clef8->setSharedRenderer(renderer);
                    clef8->setElementId(QLatin1String("uniE07D"));
                    clef8->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    clef8->setTransform(QTransform().translate(0, (renderer->bboxsw("clef8").y()-renderer->bboxne("clef8").y())*renderer->spatium()), true);
                    clef8->setTransform(QTransform().translate(0, renderer->bboxsw("gClef").y()*renderer->spatium()), true);
                    addToGroup(clef8, Qt::AnchorHorizontalCenter);
                    break;
                  }
                case 0 : {
                    QGraphicsSvgItem *gClef = new QGraphicsSvgItem();
                    gClef->setSharedRenderer(renderer);
                    gClef->setElementId(QLatin1String("uniE050"));
                    gClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    gClef->setTransform(QTransform().translate(0, renderer->bboxsw("gClef").y()*renderer->spatium()), true);
                    addToGroup(gClef);
                    break;
                  }
                case 1 : {
                    QGraphicsSvgItem *gClef = new QGraphicsSvgItem();
                    gClef->setSharedRenderer(renderer);
                    gClef->setElementId(QLatin1String("uniE050"));
                    gClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    gClef->setTransform(QTransform().translate(0, renderer->bboxsw("gClef").y()*renderer->spatium()), true);
                    addToGroup(gClef);
                    QGraphicsSvgItem *clef8 = new QGraphicsSvgItem();
                    clef8->setSharedRenderer(renderer);
                    clef8->setElementId(QLatin1String("uniE07D"));
                    clef8->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    clef8->setTransform(QTransform().translate(0, (renderer->bboxne("gClef").y()-renderer->bboxsw("gClef").y())*renderer->spatium()), true);
                    clef8->setTransform(QTransform().translate(0, renderer->bboxsw("gClef").y()*renderer->spatium()), true);
                    addToGroup(clef8, Qt::AnchorHorizontalCenter);
                    break;
                  }
                case 2 : {
                    QGraphicsSvgItem *gClef = new QGraphicsSvgItem();
                    gClef->setSharedRenderer(renderer);
                    gClef->setElementId(QLatin1String("uniE050"));
                    gClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    gClef->setTransform(QTransform().translate(0, renderer->bboxsw("gClef").y()*renderer->spatium()), true);
                    addToGroup(gClef);
                    QGraphicsSvgItem *clef15 = new QGraphicsSvgItem();
                    clef15->setSharedRenderer(renderer);
                    clef15->setElementId(QLatin1String("uniE07E"));
                    clef15->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    clef15->setTransform(QTransform().translate(0, (renderer->bboxne("gClef").y()-renderer->bboxsw("gClef").y())*renderer->spatium()), true);
                    clef15->setTransform(QTransform().translate(0, renderer->bboxsw("gClef").y()*renderer->spatium()), true);
                    addToGroup(clef15, Qt::AnchorHorizontalCenter);
                    break;
                  }
                }
            }else {
              QGraphicsSvgItem *gClef = new QGraphicsSvgItem();
              gClef->setSharedRenderer(renderer);
              gClef->setElementId(QLatin1String("uniE050"));
              gClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
              gClef->setTransform(QTransform().translate(0, renderer->bboxsw("gClef").y()*renderer->spatium()), true);
              addToGroup(gClef);
            }
          setTransform(QTransform().translate(0, (5-line)*renderer->magnification()*renderer->spatium()));
          break;
        }
      case mxml::ClefSignEnum::F : {
          int line = 4;
          if(model->getLine()) line = model->getLine()->value();
          if(model->getClefOctaveChange()) {
              switch(model->getClefOctaveChange()->value()) {
                case -2 : {
                    QGraphicsSvgItem *fClef = new QGraphicsSvgItem();
                    fClef->setSharedRenderer(renderer);
                    fClef->setElementId(QLatin1String("uniE062"));
                    fClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    fClef->setTransform(QTransform().translate(0, renderer->bboxsw("fClef").y()*renderer->spatium()), true);
                    addToGroup(fClef);
                    QGraphicsSvgItem *clef15 = new QGraphicsSvgItem();
                    clef15->setSharedRenderer(renderer);
                    clef15->setElementId(QLatin1String("uniE07E"));
                    clef15->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    clef15->setTransform(QTransform().translate(0, (renderer->bboxsw("clef15").y()-renderer->bboxne("clef15").y())*renderer->spatium()), true);
                    clef15->setTransform(QTransform().translate(0, renderer->bboxsw("fClef").y()*renderer->spatium()), true);
                    addToGroup(clef15, Qt::AnchorHorizontalCenter);
                    break;
                  }
                case -1 : {
                    QGraphicsSvgItem *fClef = new QGraphicsSvgItem();
                    fClef->setSharedRenderer(renderer);
                    fClef->setElementId(QLatin1String("uniE062"));
                    fClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    fClef->setTransform(QTransform().translate(0, renderer->bboxsw("fClef").y()*renderer->spatium()), true);
                    addToGroup(fClef);
                    QGraphicsSvgItem *clef8 = new QGraphicsSvgItem();
                    clef8->setSharedRenderer(renderer);
                    clef8->setElementId(QLatin1String("uniE07D"));
                    clef8->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    clef8->setTransform(QTransform().translate(0, (renderer->bboxsw("clef8").y()-renderer->bboxne("clef8").y())*renderer->spatium()), true);
                    clef8->setTransform(QTransform().translate(0, renderer->bboxsw("fClef").y()*renderer->spatium()), true);
                    addToGroup(clef8, Qt::AnchorHorizontalCenter);
                    break;
                  }
                case 0 : {
                    QGraphicsSvgItem *fClef = new QGraphicsSvgItem();
                    fClef->setSharedRenderer(renderer);
                    fClef->setElementId(QLatin1String("uniE062"));
                    fClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    fClef->setTransform(QTransform().translate(0, renderer->bboxsw("fClef").y()*renderer->spatium()), true);
                    addToGroup(fClef);
                    break;
                  }
                case 1 : {
                    QGraphicsSvgItem *fClef = new QGraphicsSvgItem();
                    fClef->setSharedRenderer(renderer);
                    fClef->setElementId(QLatin1String("uniE062"));
                    fClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    fClef->setTransform(QTransform().translate(0, renderer->bboxsw("fClef").y()*renderer->spatium()), true);
                    addToGroup(fClef);
                    QGraphicsSvgItem *clef8 = new QGraphicsSvgItem();
                    clef8->setSharedRenderer(renderer);
                    clef8->setElementId(QLatin1String("uniE07D"));
                    clef8->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    clef8->setTransform(QTransform().translate(0, (renderer->bboxne("fClef").y()-renderer->bboxsw("fClef").y())*renderer->spatium()), true);
                    clef8->setTransform(QTransform().translate(0, renderer->bboxsw("fClef").y()*renderer->spatium()), true);
                    addToGroup(clef8, Qt::AnchorHorizontalCenter);
                    break;
                  }
                case 2 : {
                    QGraphicsSvgItem *fClef = new QGraphicsSvgItem();
                    fClef->setSharedRenderer(renderer);
                    fClef->setElementId(QLatin1String("uniE062"));
                    fClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    fClef->setTransform(QTransform().translate(0, renderer->bboxsw("fClef").y()*renderer->spatium()), true);
                    addToGroup(fClef);
                    QGraphicsSvgItem *clef15 = new QGraphicsSvgItem();
                    clef15->setSharedRenderer(renderer);
                    clef15->setElementId(QLatin1String("uniE07E"));
                    clef15->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    clef15->setTransform(QTransform().translate(0, (renderer->bboxne("fClef").y()-renderer->bboxsw("fClef").y())*renderer->spatium()), true);
                    clef15->setTransform(QTransform().translate(0, renderer->bboxsw("fClef").y()*renderer->spatium()), true);
                    addToGroup(clef15, Qt::AnchorHorizontalCenter);
                    break;
                  }
                }
            }else {
              QGraphicsSvgItem *fClef = new QGraphicsSvgItem();
              fClef->setSharedRenderer(renderer);
              fClef->setElementId(QLatin1String("uniE062"));
              fClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
              fClef->setTransform(QTransform().translate(0, renderer->bboxsw("fClef").y()*renderer->spatium()), true);
              addToGroup(fClef);
            }
          setTransform(QTransform().translate(0, (5-line)*renderer->magnification()*renderer->spatium()));
          break;
        }
      case mxml::ClefSignEnum::C : {
          int line = 3;
          if(model->getLine()) line = model->getLine()->value();
          if(model->getClefOctaveChange()) {
              switch(model->getClefOctaveChange()->value()) {
                case -2 : {
                    QGraphicsSvgItem *cClef = new QGraphicsSvgItem();
                    cClef->setSharedRenderer(renderer);
                    cClef->setElementId(QLatin1String("uniE05C"));
                    cClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    cClef->setTransform(QTransform().translate(0, renderer->bboxsw("cClef").y()*renderer->spatium()), true);
                    addToGroup(cClef);
                    QGraphicsSvgItem *clef15 = new QGraphicsSvgItem();
                    clef15->setSharedRenderer(renderer);
                    clef15->setElementId(QLatin1String("uniE07E"));
                    clef15->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    clef15->setTransform(QTransform().translate(0, (renderer->bboxsw("clef15").y()-renderer->bboxne("clef15").y())*renderer->spatium()), true);
                    clef15->setTransform(QTransform().translate(0, renderer->bboxsw("cClef").y()*renderer->spatium()), true);
                    addToGroup(clef15, Qt::AnchorHorizontalCenter);
                    break;
                  }
                case -1 : {
                    QGraphicsSvgItem *cClef = new QGraphicsSvgItem();
                    cClef->setSharedRenderer(renderer);
                    cClef->setElementId(QLatin1String("uniE05C"));
                    cClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    cClef->setTransform(QTransform().translate(0, renderer->bboxsw("cClef").y()*renderer->spatium()), true);
                    addToGroup(cClef);
                    QGraphicsSvgItem *clef8 = new QGraphicsSvgItem();
                    clef8->setSharedRenderer(renderer);
                    clef8->setElementId(QLatin1String("uniE07D"));
                    clef8->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    clef8->setTransform(QTransform().translate(0, (renderer->bboxsw("clef8").y()-renderer->bboxne("clef8").y())*renderer->spatium()), true);
                    clef8->setTransform(QTransform().translate(0, renderer->bboxsw("cClef").y()*renderer->spatium()), true);
                    addToGroup(clef8, Qt::AnchorHorizontalCenter);
                    break;
                  }
                case 0 : {
                    QGraphicsSvgItem *cClef = new QGraphicsSvgItem();
                    cClef->setSharedRenderer(renderer);
                    cClef->setElementId(QLatin1String("uniE05C"));
                    cClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    cClef->setTransform(QTransform().translate(0, renderer->bboxsw("cClef").y()*renderer->spatium()), true);
                    addToGroup(cClef);
                    break;
                  }
                case 1 : {
                    QGraphicsSvgItem *cClef = new QGraphicsSvgItem();
                    cClef->setSharedRenderer(renderer);
                    cClef->setElementId(QLatin1String("uniE05C"));
                    cClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    cClef->setTransform(QTransform().translate(0, renderer->bboxsw("cClef").y()*renderer->spatium()), true);
                    addToGroup(cClef);
                    QGraphicsSvgItem *clef8 = new QGraphicsSvgItem();
                    clef8->setSharedRenderer(renderer);
                    clef8->setElementId(QLatin1String("uniE07D"));
                    clef8->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    clef8->setTransform(QTransform().translate(0, (renderer->bboxne("cClef").y()-renderer->bboxsw("cClef").y())*renderer->spatium()), true);
                    clef8->setTransform(QTransform().translate(0, renderer->bboxsw("cClef").y()*renderer->spatium()), true);
                    addToGroup(clef8, Qt::AnchorHorizontalCenter);
                    break;
                  }
                case 2 : {
                    QGraphicsSvgItem *cClef = new QGraphicsSvgItem();
                    cClef->setSharedRenderer(renderer);
                    cClef->setElementId(QLatin1String("uniE05C"));
                    cClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    cClef->setTransform(QTransform().translate(0, renderer->bboxsw("cClef").y()*renderer->spatium()), true);
                    addToGroup(cClef);
                    QGraphicsSvgItem *clef15 = new QGraphicsSvgItem();
                    clef15->setSharedRenderer(renderer);
                    clef15->setElementId(QLatin1String("uniE07E"));
                    clef15->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                    clef15->setTransform(QTransform().translate(0, (renderer->bboxne("cClef").y()-renderer->bboxsw("cClef").y())*renderer->spatium()), true);
                    clef15->setTransform(QTransform().translate(0, renderer->bboxsw("cClef").y()*renderer->spatium()), true);
                    addToGroup(clef15, Qt::AnchorHorizontalCenter);
                    break;
                  }
                }
            }else {
              QGraphicsSvgItem *cClef = new QGraphicsSvgItem();
              cClef->setSharedRenderer(renderer);
              cClef->setElementId(QLatin1String("uniE05C"));
              cClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
              cClef->setTransform(QTransform().translate(0, renderer->bboxsw("cClef").y()*renderer->spatium()), true);
              addToGroup(cClef);
            }
          setTransform(QTransform().translate(0, (5-line)*renderer->magnification()*renderer->spatium()));
          break;
        }
      case mxml::ClefSignEnum::TAB : {
          int staffLines = 6;
          auto staffDetails = model->getParent<mxml::Measure>()->getStaffDetails(model->hasNumber()?model->number():1);
          if(staffDetails&&staffDetails->getStaffLines()) staffLines = staffDetails->getStaffLines()->value();
          switch(staffLines) {
            case 6 : {
                QGraphicsSvgItem *sixstringTabClef = new QGraphicsSvgItem();
                sixstringTabClef->setSharedRenderer(renderer);
                sixstringTabClef->setElementId(QLatin1String("uniE06D"));
                sixstringTabClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                sixstringTabClef->setTransform(QTransform().translate(0, renderer->bboxsw("6stringTabClef").y()*renderer->spatium()), true);
                addToGroup(sixstringTabClef);
                break;
              }
            case 4 : {
                QGraphicsSvgItem *fourstringTabClef = new QGraphicsSvgItem();
                fourstringTabClef->setSharedRenderer(renderer);
                fourstringTabClef->setElementId(QLatin1String("uniE06E"));
                fourstringTabClef->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
                fourstringTabClef->setTransform(QTransform().translate(0, renderer->bboxsw("4stringTabClef").y()*renderer->spatium()), true);
                addToGroup(fourstringTabClef);
                break;
              }
            }
          setTransform(QTransform().translate(0, 0.5*(staffLines-1)*renderer->magnification()*renderer->spatium()));
          break;
        }
      case mxml::ClefSignEnum::Percussion : {
          int staffLines = 1;
          auto staffDetails = model->getParent<mxml::Measure>()->getStaffDetails(model->hasNumber()?model->number():1);
          if(staffDetails&&staffDetails->getStaffLines()) staffLines = staffDetails->getStaffLines()->value();
          QGraphicsSvgItem *unpitchedPercussionClef1 = new QGraphicsSvgItem();
          unpitchedPercussionClef1->setSharedRenderer(renderer);
          unpitchedPercussionClef1->setElementId(QLatin1String("uniE069"));
          unpitchedPercussionClef1->setTransform(QTransform().scale(renderer->magnification(), -renderer->magnification()));
          unpitchedPercussionClef1->setTransform(QTransform().translate(0, renderer->bboxsw("unpitchedPercussionClef1").y()*renderer->spatium()), true);
          addToGroup(unpitchedPercussionClef1);
          setTransform(QTransform().translate(0, 0.5*(staffLines-1)*renderer->magnification()*renderer->spatium()));
          break;
        }
      default:
        break;
      }
  }
}
