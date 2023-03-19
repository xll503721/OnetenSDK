//
//  Loader.h
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/11/6.
//

#ifndef TENONE_AD_SDK_LOADER_H
#define TENONE_AD_SDK_LOADER_H

//#include "placement.h"
//#include "header_bid.h"
//#include "advert_source.h"

#include "../model/entity/placement.h"
#include "../model/entity/ad_source.h"


BEGIN_NAMESPACE_TENONE_AD


class PlacementLoaderInterface {
public:
    virtual void RequestPlacement(const std::string& placement_id) {};
};

class WaterfallLoaderInterface {
public:
    virtual void Classify(std::shared_ptr<Placement> placement) {};
};

class AdSourceLoaderInterface {
public:
    virtual void Flow(std::shared_ptr<AdSource> ad_source) {};
};

class CacheLoaderInterface {
public:
    virtual void Save() {};
};

class LoaderInterface:  public PlacementLoaderInterface,
                        public WaterfallLoaderInterface,
                        public AdSourceLoaderInterface,
                        public CacheLoaderInterface {
public:
    virtual void Start(const std::string& placement_id) = 0;
    virtual void End() = 0;
};

END_NAMESPACE_TENONE_AD

#endif /* TENONE_AD_SDK_LOADER_H */
