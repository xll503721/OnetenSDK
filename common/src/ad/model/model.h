//
//  model.hpp
//  oneten_ad_model
//
//  Created by li zhixuan on 2023/5/2.
//

#ifndef ONETEN_AD_SDK_MODEL_H
#define ONETEN_AD_SDK_MODEL_H

#include <oneten_object.h>
#include <storage/memory/storage_memory.h>
#include <ad/entity/entity_interface.h>

BEGIN_NAMESPACE_ONETEN_AD

class Model: public ONETEN::Object {
    
public:
    
    bool Save(const std::shared_ptr<EntityInterface> objc);
    
    std::shared_ptr<EntityInterface> Read(const std::string& key);
    
    bool Update(const std::shared_ptr<EntityInterface> objc);
    
    bool Remove(const std::string& key);
    
private:
    
    std::map<std::string, std::shared_ptr<EntityInterface>> map_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_MODEL_H */
