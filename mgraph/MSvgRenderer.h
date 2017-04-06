#ifndef MSVGRENDERER_H_
#define MSVGRENDERER_H_
#include <QSvgRenderer>
#include <QJsonDocument>

namespace mgraph
{
  class MSvgRenderer : public QSvgRenderer
  {
  public:
    MSvgRenderer(const QString &svg, const QString &json, QObject *parent = Q_NULLPTR);
    qreal spatium() const;
    qreal magnification() const;
    QPointF bboxne(const QString &name) const;
    QPointF bboxsw(const QString &name) const;
  private:
    QJsonDocument _jmetadata;
  };
}
#endif // MSVGRENDERER_H_
