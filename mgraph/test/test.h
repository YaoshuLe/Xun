#include <QtTest>

class TestClef: public QObject
{
  Q_OBJECT
  private slots:
    void testGClef();
    void testGClef15mb();
    void testGClef8vb();
    void testGClef8va();
    void testGClef15ma();
    void testCClef8vb();
    void testFClef15mb();
    void test6stringTabClef();
    void test4stringTabClef();
    void testPercussion();
};

class TestKey: public QObject
{
  Q_OBJECT
  private slots:
    void testCSharpMajor();
    void testCFlatMajor();
    void testCNaturalFlatMajor();
};

class TestTime: public QObject
{
  Q_OBJECT
  private slots:
    void testSenzaMisura();
    void testTimeSigCommon();
    void testTimeSigCutCommon();
    void testBeat();
};
