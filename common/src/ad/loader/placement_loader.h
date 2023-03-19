//
//  placement_loader.h
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/12/3.
//

#ifndef TENONE_AD_SDK_PLACEMENT_LOADER_H
#define TENONE_AD_SDK_PLACEMENT_LOADER_H

#include "main_loader.h"

BEGIN_NAMESPACE_TENONE_AD

class PlacementLoader: public MainLoader {
    
private:
    using super_class = MainLoader;
    
public:
    PlacementLoader(std::shared_ptr<LoaderInterface> loader);
    void Start(const std::string& placement_id) override;
    void End() override;
    
    void RequestPlacement(const std::string& placement_id) override;
};

END_NAMESPACE_TENONE_AD

#endif /* TENONE_AD_SDK_PLACEMENT_LOADER_H */
