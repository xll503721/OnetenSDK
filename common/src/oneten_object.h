//
//  oneten_object.h
//  SDKCommon
//
//  Created by li zhixuan on 2022/11/6.
//

#ifndef TENONE_SDK_OBJECT_H
#define TENONE_SDK_OBJECT_H

BEGIN_NAMESPACE_ONETEN

class Object: public std::enable_shared_from_this<Object> {
public:
    Object() = default;
    virtual ~Object();
};

END_NAMESPACE_ONETEN

#endif /* TENONE_SDK_OBJECT_H */
