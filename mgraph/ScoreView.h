#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <QGraphicsView>

class ScoreView : public QGraphicsView
{
  Q_OBJECT

public:
  ScoreView(QWidget *parent = 0);
  ~ScoreView();
};

#endif // SCOREVIEW_H
