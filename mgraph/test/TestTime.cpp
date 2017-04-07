#include "test.h"
#include <QGraphicsView>
#include "../../mxml/pugixml.hpp"
#include "../../mxml/DocumentPartwise.h"
#include "../../mxml/ScorePartwise.h"
#include "../../mxml/Part.h"
#include "../../mxml/Measure.h"
#include "../../mxml/Attributes.h"
#include "../../mxml/Time.h"

#include "../mgraph/MSvgRenderer.h"
#include "../mgraph/Time.h"

void TestTime::testSenzaMisura()
{
  mgraph::MSvgRenderer *renderer = new mgraph::MSvgRenderer(QLatin1String(":/bravura.svg"), QLatin1String(":/bravura_metadata.json"));

  QGraphicsView scoreView;
  scoreView.setScene(new QGraphicsScene());
  const double spatium = renderer->spatium()*renderer->magnification();
  scoreView.setFixedSize(400, 400);
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 0, 300, 0));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, spatium, 300, spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 2*spatium, 300, 2*spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 3*spatium, 300, 3*spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 4*spatium, 300, 4*spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 5*spatium, 300, 5*spatium));

  pugi::xml_document indoc;
  pugi::xml_parse_result result =
      indoc.load_string(" \
                        <score-partwise> \
                        <part> \
                        <measure> \
                        <attributes> \
                        <time> \
                        <senza-misura>1234567890x</senza-misura> \
                        </time> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getTimeSet()[0];
  auto *item = new mgraph::Time();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("senzaMisura.jpg");
}

void TestTime::testTimeSigCommon()
{
  mgraph::MSvgRenderer *renderer = new mgraph::MSvgRenderer(QLatin1String(":/bravura.svg"), QLatin1String(":/bravura_metadata.json"));

  QGraphicsView scoreView;
  scoreView.setScene(new QGraphicsScene());
  const double spatium = renderer->spatium()*renderer->magnification();
  scoreView.setFixedSize(400, 400);
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 0, 300, 0));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, spatium, 300, spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 2*spatium, 300, 2*spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 3*spatium, 300, 3*spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 4*spatium, 300, 4*spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 5*spatium, 300, 5*spatium));

  pugi::xml_document indoc;
  pugi::xml_parse_result result =
      indoc.load_string(" \
                        <score-partwise> \
                        <part> \
                        <measure> \
                        <attributes> \
                        <time symbol=\"common\"/> \
                        <staff-details> \
                         <staff-lines>2</staff-lines> \
                        </staff-details> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getTimeSet()[0];
  auto *item = new mgraph::Time();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("timeSigCommon.jpg");
}

void TestTime::testTimeSigCutCommon()
{
  mgraph::MSvgRenderer *renderer = new mgraph::MSvgRenderer(QLatin1String(":/bravura.svg"), QLatin1String(":/bravura_metadata.json"));

  QGraphicsView scoreView;
  scoreView.setScene(new QGraphicsScene());
  const double spatium = renderer->spatium()*renderer->magnification();
  scoreView.setFixedSize(400, 400);
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 0, 300, 0));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, spatium, 300, spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 2*spatium, 300, 2*spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 3*spatium, 300, 3*spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 4*spatium, 300, 4*spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 5*spatium, 300, 5*spatium));

  pugi::xml_document indoc;
  pugi::xml_parse_result result =
      indoc.load_string(" \
                        <score-partwise> \
                        <part> \
                        <measure> \
                        <attributes> \
                        <time symbol=\"cut\"/> \
                        <staff-details> \
                         <staff-lines>3</staff-lines> \
                        </staff-details> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getTimeSet()[0];
  auto *item = new mgraph::Time();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("timeSigCutCommon.jpg");
}

void TestTime::testBeat()
{
  mgraph::MSvgRenderer *renderer = new mgraph::MSvgRenderer(QLatin1String(":/bravura.svg"), QLatin1String(":/bravura_metadata.json"));

  QGraphicsView scoreView;
  scoreView.setScene(new QGraphicsScene());
  const double spatium = renderer->spatium()*renderer->magnification();
  scoreView.setFixedSize(400, 400);
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 0, 300, 0));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, spatium, 300, spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 2*spatium, 300, 2*spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 3*spatium, 300, 3*spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 4*spatium, 300, 4*spatium));
  scoreView.scene()->addItem(new  QGraphicsLineItem(0, 5*spatium, 300, 5*spatium));

  pugi::xml_document indoc;
  pugi::xml_parse_result result =
      indoc.load_string(" \
                        <score-partwise> \
                        <part> \
                        <measure> \
                        <attributes> \
                        <time> \
                        <beats>01</beats> \
                        <beat-type>2</beat-type> \
                        <beats>3</beats> \
                        <beat-type>45</beat-type> \
                        <interchangeable> \
                        <beats>6</beats> \
                        <beat-type>7</beat-type> \
                        <beats>8</beats> \
                        <beat-type>9</beat-type> \
                        </interchangeable> \
                        </time> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getTimeSet()[0];
  auto *item = new mgraph::Time();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("timeBeat.jpg");
}
