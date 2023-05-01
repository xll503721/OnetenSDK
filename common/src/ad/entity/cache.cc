//
//  cache.cc
//  oneten_ad_entity
//
//  Created by li zhixuan on 2023/4/30.
//

#include "cache.h"

BEGIN_NAMESPACE_ONETEN_AD

Cache::Cache(std::shared_ptr<AdSource> ad_source, std::shared_ptr<Placement> placement):
placement_(placement),
ad_source_(ad_source) {
    
}


std::string Cache::Identifier() {
    
}

END_NAMESPACE_ONETEN_AD
