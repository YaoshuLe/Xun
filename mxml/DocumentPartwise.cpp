#include "DocumentPartwise.h"
#include "ScorePartwise.h"

namespace mxml
{
  DocumentPartwise::DocumentPartwise() {}
  ScorePartwisePtr DocumentPartwise::getScorePartwise() const
  {
    return _scorePartwisePtr;
  }
  void DocumentPartwise::setScorePartwise( const ScorePartwisePtr& value )
  {
    _scorePartwisePtr = value;
  }
  void DocumentPartwise::ostream(pugi::xml_document& doc) const
  {
    if(_scorePartwisePtr) {
      auto child = doc.append_child("score-partwise");
      _scorePartwisePtr->ostream(child);
    }
  }
  void DocumentPartwise::istream(const pugi::xml_document& doc)
  {
    if(auto child = doc.child("score-partwise")) {
      _scorePartwisePtr = std::make_shared<ScorePartwise>();
      _scorePartwisePtr->istream(child);
    }
  }
}
