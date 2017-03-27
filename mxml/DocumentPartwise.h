#ifndef DOCUMENT_PARTWISE_H
#define DOCUMENT_PARTWISE_H
#include <memory>
#include <vector>
#include "pugixml.hpp"

namespace mxml
{
  class ScorePartwise;
  using ScorePartwisePtr = std::shared_ptr<ScorePartwise>;
  
  class DocumentPartwise
  {
  public:
    DocumentPartwise();
    ScorePartwisePtr getScorePartwise() const;
    void setScorePartwise(const ScorePartwisePtr& value);
    void ostream(pugi::xml_document& doc) const;
    void istream(const pugi::xml_document& doc);
  private:
    ScorePartwisePtr _scorePartwisePtr;
  };
}
#endif //DOCUMENT_PARTWISE_H
