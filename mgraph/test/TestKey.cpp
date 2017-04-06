#include "test.h"
#include <QGraphicsView>
#include "../../mxml/pugixml.hpp"
#include "../../mxml/DocumentPartwise.h"
#include "../../mxml/ScorePartwise.h"
#include "../../mxml/Part.h"
#include "../../mxml/Measure.h"
#include "../../mxml/Attributes.h"
#include "../../mxml/Key.h"

#include "../mgraph/MSvgRenderer.h"
#include "../mgraph/Key.h"

void TestKey::testCSharpMajor()
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
                        <clef> \
                        <sign>G</sign> \
                        </clef> \
                        <key> \
                        <fifths>7</fifths> \
                        </key> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getKeySet()[0];
  auto *item = new mgraph::Key();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("cSharpMajor.jpg");
}

void TestKey::testCFlatMajor()
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
                        <clef> \
                        <sign>G</sign> \
                        </clef> \
                        <key> \
                        <fifths>-7</fifths> \
                        </key> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getKeySet()[0];
  auto *item = new mgraph::Key();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("cFlatMajor.jpg");
}

void TestKey::testCNaturalFlatMajor()
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
                        <clef> \
                        <sign>G</sign> \
                        </clef> \
                        <key> \
                        <fifths>7</fifths> \
                        </key> \
                        </attributes> \
                        </measure> \
                        <measure> \
                        <attributes> \
                        <key> \
                        <fifths>-7</fifths> \
                        </key> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[1]->getMusicDataSet()[0])->getKeySet()[0];
  auto *item = new mgraph::Key();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("cNaturalFlatMajor.jpg");
}
