#include "MSvgRenderer.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>

namespace mgraph
{
  MSvgRenderer::MSvgRenderer(const QString &svg, const QString &json, QObject *parent):QSvgRenderer(svg, parent)
  {
    QFile file(json);
    if(!file.open(QIODevice::ReadOnly)) {
        return;
      }
    _jmetadata = QJsonDocument::fromJson(file.readAll());
  }
  qreal MSvgRenderer::spatium() const
  {
    return _jmetadata.object().value(QLatin1String("engravingDefaults"))
        .toObject().value(QLatin1String("spatium")).toDouble();
  }
  qreal MSvgRenderer::magnification() const
  {
    return _jmetadata.object().value(QLatin1String("engravingDefaults"))
        .toObject().value(QLatin1String("magnification")).toDouble();
  }
  QPointF MSvgRenderer::bboxne(const QString &name) const
  {
    auto bbox = _jmetadata.object().value(QLatin1String("glyphBBoxes")).toObject().value(name).toObject();
    return QPointF(bbox.value("bBoxNE").toArray()[0].toDouble(), bbox.value("bBoxNE").toArray()[1].toDouble());
  }
  QPointF MSvgRenderer::bboxsw(const QString &name) const
  {
    auto bbox = _jmetadata.object().value(QLatin1String("glyphBBoxes")).toObject().value(name).toObject();
    return QPointF(bbox.value("bBoxSW").toArray()[0].toDouble(), bbox.value("bBoxSW").toArray()[1].toDouble());
  }
}
