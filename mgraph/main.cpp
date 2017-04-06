/*
#include "ScoreView.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  ScoreView w;
  w.show();

  return a.exec();
}
*/

#include "test/test.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  TestClef testclef;
   return QTest::qExec(&testclef, argc, argv);
}

