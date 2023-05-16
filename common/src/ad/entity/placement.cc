//
//  placement.cpp
//  SDKCommon
//
//  Created by li zhixuan on 2022/11/6.
//

#include "placement.h"
BEGIN_NAMESPACE_ONETEN_AD

std::vector<std::shared_ptr<AdSource>> Placement::GetRequestAdSources() {
    std::vector<std::shared_ptr<AdSource>> ad_sources;
//    std::shared_ptr<AdSource> ad_source1 = std::make_shared<AdSource>();
//    ad_source1->SetLevel(0);
//    std::shared_ptr<AdSource> ad_source2 = std::make_shared<AdSource>();
//    ad_source2->SetLevel(1);
//    std::shared_ptr<AdSource> ad_source3 = std::make_shared<AdSource>();
//    ad_source3->SetLevel(2);
//    std::shared_ptr<AdSource> ad_source4 = std::make_shared<AdSource>();
//    ad_source4->SetLevel(3);
    std::shared_ptr<AdSource> ad_source5 = std::make_shared<AdSource>();
    ad_source5->SetLevel(4);
    ad_source5->InitSDK();
    ad_source5->Parse("");
//    ad_sources.push_back(ad_source1);
//    ad_sources.push_back(ad_source2);
//    ad_sources.push_back(ad_source3);
//    ad_sources.push_back(ad_source4);
    ad_sources.push_back(ad_source5);
    
    return ad_sources;
}

std::string Placement::Identifier() {
    return "qwertyuiop";
}

END_NAMESPACE_ONETEN_AD
