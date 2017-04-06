#include "test.h"
#include <QGraphicsView>
#include "../../mxml/pugixml.hpp"
#include "../../mxml/DocumentPartwise.h"
#include "../../mxml/ScorePartwise.h"
#include "../../mxml/Part.h"
#include "../../mxml/Measure.h"
#include "../../mxml/Attributes.h"
#include "../../mxml/Clef.h"

#include "../mgraph/MSvgRenderer.h"
#include "../mgraph/Clef.h"

void TestClef::testGClef()
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
                        <line>3</line> \
                        </clef> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getClefSet()[0];
  auto *item = new mgraph::Clef();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("gClef.jpg");
}

void TestClef::testGClef15mb()
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
                        <line>5</line> \
                        <clef-octave-change>-2</clef-octave-change> \
                        </clef> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getClefSet()[0];
  auto *item = new mgraph::Clef();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("gClef15mb.jpg");
}

void TestClef::testGClef8vb()
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
                        <line>4</line> \
                        <clef-octave-change>-1</clef-octave-change> \
                        </clef> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getClefSet()[0];
  auto *item = new mgraph::Clef();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("gClef8vb.jpg");
}

void TestClef::testGClef8va()
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
                        <line>2</line> \
                        <clef-octave-change>1</clef-octave-change> \
                        </clef> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getClefSet()[0];
  auto *item = new mgraph::Clef();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("gClef8va.jpg");
}

void TestClef::testGClef15ma()
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
                        <line>1</line> \
                        <clef-octave-change>2</clef-octave-change> \
                        </clef> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getClefSet()[0];
  auto *item = new mgraph::Clef();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("gClef15ma.jpg");
}

void TestClef::testCClef8vb()
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
                        <sign>C</sign> \
                        <line>3</line> \
                        <clef-octave-change>-2</clef-octave-change> \
                        </clef> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getClefSet()[0];
  auto *item = new mgraph::Clef();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("cClef8vb.jpg");
}

void TestClef::testFClef15mb()
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
                        <sign>F</sign> \
                        <line>2</line> \
                        <clef-octave-change>-2</clef-octave-change> \
                        </clef> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getClefSet()[0];
  auto *item = new mgraph::Clef();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("fClef15mb.jpg");
}

void TestClef::test6stringTabClef()
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
                        <sign>TAB</sign> \
                        </clef> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getClefSet()[0];
  auto *item = new mgraph::Clef();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("6stringTabClef.jpg");
}

void TestClef::test4stringTabClef()
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
                        <sign>TAB</sign> \
                        </clef> \
                        <staff-details> \
                        <staff-lines>4</staff-lines> \
                        </staff-details> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getClefSet()[0];
  auto *item = new mgraph::Clef();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("4stringTabClef.jpg");
}

void TestClef::testPercussion()
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
                        <sign>percussion</sign> \
                        </clef> \
                        <staff-details> \
                        <staff-lines>4</staff-lines> \
                        </staff-details> \
                        </attributes> \
                        </measure> \
                        </part> \
                        </score-partwise> \
                        ");
  QVERIFY(result);
  auto document = std::make_shared<mxml::DocumentPartwise>();
  document->istream(indoc);
  auto model = std::dynamic_pointer_cast<mxml::Attributes>(document->getScorePartwise()->getPartSet()[0]->getMeasureSet()[0]->getMusicDataSet()[0])->getClefSet()[0];
  auto *item = new mgraph::Clef();
  item->setModel(model);
  item->expand(renderer);
  scoreView.scene()->addItem(item);
  scoreView.grab().save("unpitchedPercussionClef1.jpg");
}
