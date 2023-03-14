//
//  placement.h
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/11/6.
//

#ifndef TENONE_AD_SDK_PLACEMENT_H
#define TENONE_AD_SDK_PLACEMENT_H

#include "advert_source.h"

BEGIN_NAMESPACE_TENONE_AD

class Placement {
    
private:
    std::vector<std::shared_ptr<AdvertSource>> adver_source_vector;
};

END_NAMESPACE_TENONE_AD

#endif /* TENONE_AD_SDK_PLACEMENT_H */
