//
//  placement.h
//  SDKCommon
//
//  Created by li zhixuan on 2022/11/6.
//

#ifndef ONETEN_AD_SDK_AD_SOURCE_H
#define ONETEN_AD_SDK_AD_SOURCE_H

#include <oneten_object.h>

BEGIN_NAMESPACE_ONETEN_AD

class AdSource: OnetenObject {
public:
    enum class Type {
        kS2S,
        kC2S,
        kNormal,
    };
    
    AdSource();
    Type GetType();
    
    void Load();
    void SetLevel(int32_t level);
    int32_t GetLevel();
    
    std::string GetClassName();
    
private:
    Type type_;
    int32_t level_;
    
    std::string clazz_name_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_AD_SOURCE_H */
