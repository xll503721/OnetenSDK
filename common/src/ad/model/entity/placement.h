//
//  placement.h
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/11/6.
//

#ifndef TENONE_AD_SDK_PLACEMENT_H
#define TENONE_AD_SDK_PLACEMENT_H

#include <oneten_object.h>
#include "ad_source.h"

BEGIN_NAMESPACE_TENONE_AD

class Placement: OnetenObject {
    
public:
    std::vector<std::shared_ptr<AdSource>> GetRequestAdSources();
    
private:
    std::vector<std::shared_ptr<AdSource>> requesting_ad_sources_;
    std::vector<std::shared_ptr<AdSource>> completed_ad_sources_;
    std::vector<std::shared_ptr<AdSource>> ad_sources_;
    std::vector<std::shared_ptr<AdSource>> s2s_ad_sources_;
    std::vector<std::shared_ptr<AdSource>> normal_ad_sources_;
    
};

END_NAMESPACE_TENONE_AD

#endif /* TENONE_AD_SDK_PLACEMENT_H */
