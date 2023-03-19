//
//  waterfall_loader.h
//  TenoneSDK
//
//  Created by li zhixuan on 2022/11/5.
//

#ifndef TENONE_AD_SDK_WATERFALL_LOADER_H
#define TENONE_AD_SDK_WATERFALL_LOADER_H

#include "main_loader.h"

BEGIN_NAMESPACE_TENONE_AD

class WaterfallLoader: public MainLoader {
    
private:
    using super_class = MainLoader;
    
public:
    WaterfallLoader(std::shared_ptr<LoaderInterface> loader);
    void Classify(std::shared_ptr<Placement> placement);
};

END_NAMESPACE_TENONE_AD

#endif /* TENONE_AD_SDK_WATERFALL_LOADER_H */
