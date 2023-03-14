//
//  Loader.h
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/11/6.
//

#ifndef TENONE_AD_SDK_LOADER_H
#define TENONE_AD_SDK_LOADER_H

#include "placement.h"
#include "header_bid.h"
#include "advert_source.h"

BEGIN_NAMESPACE_TENONE_AD

class PlacementLoaderInterface {
public:
    virtual void RequestPlacement(const std::string& placement_id) = 0;
};

class WaterfallLoaderInterface {
public:
    virtual void Flow(Placement* placement) = 0;
};

class LoaderInterface: public WaterfallLoaderInterface, public PlacementLoaderInterface  {
public:
    virtual void Start(const std::string& placement_id) = 0;
    virtual void End() = 0;
};

END_NAMESPACE_TENONE_AD

#endif /* TENONE_AD_SDK_LOADER_H */
