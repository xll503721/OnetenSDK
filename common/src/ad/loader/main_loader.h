//
//  main_loader.h
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/11/11.
//

#ifndef TENONE_AD_SDK_MAIN_LOADER_H
#define TENONE_AD_SDK_MAIN_LOADER_H

#include "loader.h"
#include <oneten_object.h>

BEGIN_NAMESPACE_TENONE_AD

class MainLoader: public OnetenObject, public LoaderInterface {
    
public:
    MainLoader(std::shared_ptr<LoaderInterface> loader);
    void Start(const std::string& placement_id);
    void Flow(std::shared_ptr<AdSource> ad_source);
    void Classify(std::shared_ptr<Placement> placement);
    void NextLoader();
    void End();
    
private:
    std::shared_ptr<LoaderInterface> mainloader_;
};

END_NAMESPACE_TENONE_AD

#endif /* TENONE_AD_SDK_MAIN_LOADER_H */
