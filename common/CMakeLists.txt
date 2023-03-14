cmake_minimum_required(VERSION 3.24)

project(SDKCommon)

set(CMAKE_CXX_STANDARD 17)
set(SDK_NAME_LOWER_CASE "oneten")
set(SDK_NAME_UPPER_CASE "OneTen")
set(SDK_BUNDLE_ID_PREFIX "cn.gz.ch")

set(SDK_AD_LIB "")
string(CONCAT SDK_AD_LIB ${SDK_NAME_LOWER_CASE} "_ad")

set(SDK_AD_MODEL_LIB "")
string(CONCAT SDK_AD_MODEL_LIB ${SDK_NAME_LOWER_CASE} "_ad_model")

set(SDK_AD_SERVICE_LIB "")
string(CONCAT SDK_AD_SERVICE_LIB ${SDK_NAME_LOWER_CASE} "_ad_service")

set(SDK_AD_LOADER_LIB "")
string(CONCAT SDK_AD_LOADER_LIB ${SDK_NAME_LOWER_CASE} "_ad_loader")

if(IOS)
    set(PLATFORM iOS)
    set(ONETEN_SDK "OneTenSDK")
elseif(OSX)
    set(PLATFORM Mac)
    set(ONETEN_SDK "OneTenSDK")
elseif(ANDROID)
    set(PLATFORM Android)
endif()

macro(target_exclude_from_all_if_exist targets)
  foreach(target ${targets})
    if(TARGET ${target})
      set_target_properties(${target} PROPERTIES EXCLUDE_FROM_ALL TRUE EXCLUDE_FROM_DEFAULT_BUILD TRUE)
    endif()
  endforeach()
endmacro()

macro (set_xcode_property TARGET XCODE_PROPERTY XCODE_VALUE)
    set_property (TARGET ${TARGET} PROPERTY XCODE_ATTRIBUTE_${XCODE_PROPERTY} ${XCODE_VALUE})
endmacro (set_xcode_property)

macro(apple_framework_generate 
      project_name 
      bundle_id
      public_h)
  if(IOS OR OSX)
    set_target_properties(${project_name} PROPERTIES 
      XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC "YES"
      XCODE_ATTRIBUTE_FRAMEWORK_SEARCH_PATHS ""
      XCODE_ATTRIBUTE_LIBRARY_SEARCH_PATHS "" 
      XCODE_ATTRIBUTE_LIBRARY_SEARCH_PATHS ""
      XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER ${bundle_id}
      XCODE_ATTRIBUTE_GCC_TREAT_WARNINGS_AS_ERRORS "YES"
      FRAMEWORK TRUE 
      FRAMEWORK_VERSION A 
      MACOSX_FRAMEWORK_INFO_PLIST ${CMAKE_CURRENT_LIST_DIR}/framework.plist.in
      PUBLIC_HEADER "${CMAKE_CURRENT_LIST_DIR}/${public_h}"
      MACOSX_FRAMEWORK_IDENTIFIER ${bundle_id} 
    )
  endif()
endmacro()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
macro(set_target_folder_if_exist target folder)
  if(TARGET ${target})
    set_target_properties(${target} PROPERTIES FOLDER ${folder})
  endif()
endmacro()

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output/${PLATFORM})

add_subdirectory(src)

