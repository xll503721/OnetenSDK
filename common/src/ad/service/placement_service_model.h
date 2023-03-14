//
//  placement.h
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/11/6.
//

#ifndef TENONE_AD_SDK_PLACEMENT_MODEL_H
#define TENONE_AD_SDK_PLACEMENT_MODEL_H

#include "advert_source.h"

BEGIN_NAMESPACE_TENONE_AD

class PlacementModel {
    
public:
    PlacementModel(const std::string placement_id, void* delegate);
};

END_NAMESPACE_TENONE_AD

#endif /* TENONE_AD_SDK_PLACEMENT_MODEL_H */
