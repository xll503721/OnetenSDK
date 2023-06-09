//
//  placement_loader.h
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/3.
//

#ifndef ONETEN_AD_SDK_PLACEMENT_LOADER_H
#define ONETEN_AD_SDK_PLACEMENT_LOADER_H

#include "main_loader.h"

BEGIN_NAMESPACE_ONETEN_AD

class PlacementLoader: public MainLoader {
    
public:
    ~PlacementLoader();
    PlacementLoader(std::shared_ptr<LoaderInterface> loader);
    void Start(const std::string& placement_id) override;
    void End() override;
    
    void RequestPlacement(const std::string& placement_id) override;
    
private:
    using super_class = MainLoader;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_PLACEMENT_LOADER_H */
