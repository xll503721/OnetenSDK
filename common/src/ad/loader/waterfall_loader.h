//
//  waterfall_loader.h
//  TenoneSDK
//
//  Created by li zhixuan on 2022/11/5.
//

#ifndef ONETEN_AD_SDK_WATERFALL_LOADER_H
#define ONETEN_AD_SDK_WATERFALL_LOADER_H

#include "main_loader.h"

BEGIN_NAMESPACE_ONETEN_AD

class WaterfallLoader: public MainLoader {
    
private:
    using super_class = MainLoader;
    
public:
    WaterfallLoader(std::shared_ptr<LoaderInterface> loader);
    void Classify(std::shared_ptr<Placement> placement);
    void StartFlow(int32_t level);
    void InternalStartFlow(int32_t level);
    
    void End();
    
private:
    std::shared_ptr<Placement> placement_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_WATERFALL_LOADER_H */
