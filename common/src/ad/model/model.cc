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

std::shared_ptr<EntityInterface>& Model::Read(const std::string& key) {
    
}

bool Model::Update(const std::shared_ptr<EntityInterface> objc) {
    if (objc) {
        map_[objc->Identifier()] = objc;
    }
}

bool Model::Remove(const std::string& key) {
    return map_.Remove(key);
}

END_NAMESPACE_ONETEN_AD
