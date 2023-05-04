//
//  model.cc
//  oneten_ad_model
//
//  Created by li zhixuan on 2023/5/2.
//

#include "model.h"
#include <ad/entity/entity_interface.h>

BEGIN_NAMESPACE_ONETEN_AD

bool Model::Save(const std::shared_ptr<EntityInterface> objc) {
    if (objc) {
        map_[objc->Identifier()] = objc;
    }
}

std::shared_ptr<EntityInterface> Model::Read(const std::string& key) {
    if (map_.find(key) == map_.end()) {
        return nullptr;
    }
    return map_[key];
}

bool Model::Update(const std::shared_ptr<EntityInterface> objc) {
    if (!objc) {
        return false;
    }
    
    map_[objc->Identifier()] = objc;
    return true;
}

bool Model::Remove(const std::string& key) {
    if (map_.find(key) == map_.end()) {
        return false;
    }
    map_.erase(key);
    return true;
}

END_NAMESPACE_ONETEN_AD
