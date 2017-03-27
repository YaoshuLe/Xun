#include "Identification.h"
#include <cstring>
#include "Creator.h"
#include "Rights.h"
#include "EncodingDate.h"
#include "Encoder.h"
#include "Software.h"
#include "EncodingDescription.h"
#include "Supports.h"
#include "Source.h"
#include "Relation.h"
#include "Miscellaneous.h"

namespace mxml
{
  Identification::Identification() {}
  const CreatorSet& Identification::getCreatorSet() const {  return _creatorSet; }
  void Identification::removeCreator(const CreatorPtr& value) { if(value) { auto i = std::find_if(_creatorSet.begin(), _creatorSet.end(), [&](const CreatorPtr& item) { return item==value; }); if(i!=_creatorSet.end()) _creatorSet.erase(i); } } 
  void Identification::addCreator(const CreatorPtr& value) { if(value) { _creatorSet.push_back(value); value->setParent(shared_from_this()); } }
  void Identification::clearCreatorSet() { _creatorSet.clear(); }
  const RightsSet& Identification::getRightsSet() const {  return _rightsSet; }
  void Identification::removeRights(const RightsPtr& value) { if(value) { auto i = std::find_if(_rightsSet.begin(), _rightsSet.end(), [&](const RightsPtr& item) { return item==value; }); if(i!=_rightsSet.end()) _rightsSet.erase(i); } } 
  void Identification::addRights(const RightsPtr& value) { if(value) { _rightsSet.push_back(value); value->setParent(shared_from_this()); } }
  void Identification::clearRightsSet() { _rightsSet.clear(); }
  const EncodingSet& Identification::getEncodingSet() const {  return _encodingSet; }
  void Identification::removeEncoding(const EncodingPtr& value) { if(value) { auto i = std::find_if(_encodingSet.begin(), _encodingSet.end(), [&](const EncodingPtr& item) { return item==value; }); if(i!=_encodingSet.end()) _encodingSet.erase(i); } } 
  void Identification::addEncoding(const EncodingPtr& value) { if(value) { _encodingSet.push_back(value); value->setParent(shared_from_this()); } }
  void Identification::clearEncodingSet() { _encodingSet.clear(); }
  SourcePtr Identification::getSource() const { return _sourcePtr; }
  void Identification::setSource(const SourcePtr& value) { _sourcePtr = value; value->setParent(shared_from_this()); }
  const RelationSet& Identification::getRelationSet() const {  return _relationSet; }
  void Identification::removeRelation(const RelationPtr& value) { if(value) { auto i = std::find_if(_relationSet.begin(), _relationSet.end(), [&](const RelationPtr& item) { return item==value; }); if(i!=_relationSet.end()) _relationSet.erase(i); } } 
  void Identification::addRelation(const RelationPtr& value) { if(value) { _relationSet.push_back(value); value->setParent(shared_from_this()); } }
  void Identification::clearRelationSet() { _relationSet.clear(); }
  MiscellaneousPtr Identification::getMiscellaneous() const { return _miscellaneousPtr; }
  void Identification::setMiscellaneous(const MiscellaneousPtr& value) { _miscellaneousPtr = value; value->setParent(shared_from_this()); }

  void Identification::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _creatorSet) {
      auto child = self.append_child("creator");
      item->ostream(child);
    }
    for(auto item : _rightsSet) {
      auto child = self.append_child("rights");
      item->ostream(child);
    }
    if(_encodingSet.size()>0) {
      auto node = self.append_child("encoding");
      for(auto item : _encodingSet) {
        if(std::dynamic_pointer_cast<EncodingDate>(item).get()) {
          auto child = node.append_child("encoding-date");
          item->ostream(child);
        }else if(std::dynamic_pointer_cast<Encoder>(item).get()) {
          auto child = node.append_child("encoder");
          item->ostream(child);
        }else if(std::dynamic_pointer_cast<Software>(item).get()) {
          auto child = node.append_child("software");
          item->ostream(child);
        }else if(std::dynamic_pointer_cast<EncodingDescription>(item).get()) {
          auto child = node.append_child("encoding-description");
          item->ostream(child);
        }else if(std::dynamic_pointer_cast<Supports>(item).get()) {
          auto child = node.append_child("supports");
          item->ostream(child);
        }
      }
    }
    if(_sourcePtr) {
      auto child = self.append_child("source");
      _sourcePtr->ostream(child);
    }
    for(auto item : _relationSet) {
      auto child = self.append_child("relation");
      item->ostream(child);
    }
    if(_miscellaneousPtr) {
      auto child = self.append_child("miscellaneous");
      _miscellaneousPtr->ostream(child);
    }
  }
  void Identification::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "creator")==0) {
        auto creatorPtr = std::make_shared<Creator>();
        creatorPtr->istream(child);
        addCreator(creatorPtr);
      }
      else if(strcmp(child.name(), "rights")==0) {
        auto rightsPtr = std::make_shared<Rights>();
        rightsPtr->istream(child);
        addRights(rightsPtr);
      }
      else if(strcmp(child.name(), "encoding")==0) {
        for(auto node: child.children()) {
          if(strcmp(node.name(), "encoding-date")==0) {
            auto item = std::make_shared<EncodingDate>();
            item->istream(node);
            addEncoding(item);
          }else if(strcmp(node.name(), "encoder")==0) {
            auto item = std::make_shared<Encoder>();
            item->istream(node);
            addEncoding(item);
          }else if(strcmp(node.name(), "software")==0) {
            auto item = std::make_shared<Software>();
            item->istream(node);
            addEncoding(item);
          }else if(strcmp(node.name(), "encoding-description")==0) {
            auto item = std::make_shared<EncodingDescription>();
            item->istream(node);
            addEncoding(item);
          }else if(strcmp(node.name(), "supports")==0) {
            auto item = std::make_shared<Supports>();
            item->istream(node);
            addEncoding(item);
          }
        }
      }
      else if(strcmp(child.name(), "source")==0) {
        auto sourcePtr = std::make_shared<Source>();
        sourcePtr->istream(child);
        setSource(sourcePtr);
      }
      else if(strcmp(child.name(), "relation")==0) {
        auto relationPtr = std::make_shared<Relation>();
        relationPtr->istream(child);
        addRelation(relationPtr);
      }
      else if(strcmp(child.name(), "miscellaneous")==0) {
        auto miscellaneousPtr = std::make_shared<Miscellaneous>();
        miscellaneousPtr->istream(child);
        setMiscellaneous(miscellaneousPtr);
      }
    }
  }
}
