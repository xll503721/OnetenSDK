#pragma once


enum class OneTenPlatformType {
    kOneTenPlatformTypeiOS,
    kOneTenPlatformTypeMac,
    kOneTenPlatformTypeAndroid,
};

bool isPlatform(OneTenPlatformType type) {
    bool is_platform = false;
    switch (type) {
        case OneTenPlatformType::kOneTenPlatformTypeiOS: {
#ifdef OS_IOS
            is_platform = true;
#endif
        }
            break;
        case OneTenPlatformType::kOneTenPlatformTypeMac: {
#ifdef OS_MAX
            is_platform = true;
#endif
        }
            break;
        case OneTenPlatformType::kOneTenPlatformTypeAndroid: {
#ifdef OS_ANDROID
            is_platform = true;
#endif
        }
            break;
            
        default:
            break;
    }
    return is_platform;
}
