//
//  placement.h
//  SDKCommon
//
//  Created by li zhixuan on 2022/11/6.
//

#ifndef ONETEN_AD_SDK_AD_SOURCE_H
#define ONETEN_AD_SDK_AD_SOURCE_H

#include <oneten_object.h>

#ifdef __OBJC__
#import "OTAdSource.h"
#endif

BEGIN_NAMESPACE_ONETEN_AD

class AdSource: ONETEN::OnetenObject {
public:
    enum class Type {
        kS2S,
        kC2S,
        kNormal,
    };
    
    using this_class = AdSource;
    
    AdSource();
    Type GetType();
    
    void Load();
    void SetLevel(int32_t level);
    int32_t GetLevel();
    
    std::string GetClassName();
    void Parse(std::string json_string);
    
    void Test(std::string test, std::string test2);
    
private:
    Type type_;
    int32_t level_;
    
    std::string clazz_name_;
    
    PLATFORM_DECLARE
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_AD_SOURCE_H */
