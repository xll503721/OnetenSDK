project(${SDK_AD_SERVICE_LIB})

file(GLOB
     sdk_ad_src_service_source
     *.cc
     *.h)

add_library(${PROJECT_NAME} STATIC ${sdk_ad_src_service_source})
# if(${CMAKE_VERSION} VERSION_GREATER "3.16.0")
#     target_precompile_headers(${PROJECT_NAME} PRIVATE "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/pch.h>")
# endif()