#ifndef ONETEN_AD_SDK_PCH_H
#define ONETEN_AD_SDK_PCH_H

#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <sstream>
#include <unordered_map>

#ifndef __FILE_NAME__
#define __FILE_NAME__ __FILE__
#endif

#define REGISTER_MODEL(name) \
std::shared_ptr<name> model_##name = std::make_shared<name>();\
ModelFactory::GetInstance().SetModel(ModelFactory::ModelType::kModelType##name, model_##name);\

#define ONETEN_AD oneten_ad
#define BEGIN_NAMESPACE_ONETEN_AD BEGIN_NAMESPACE(ONETEN_AD)
#define END_NAMESPACE_ONETEN_AD END_NAMESPACE()

#define ONETEN oneten
#define BEGIN_NAMESPACE_ONETEN BEGIN_NAMESPACE(ONETEN)
#define END_NAMESPACE_ONETEN END_NAMESPACE()

#define BEGIN_NAMESPACE(ns) namespace ns {
#define END_NAMESPACE() }

#include "platform.h"

#endif /* ONETEN_AD_SDK_PCH_H */
