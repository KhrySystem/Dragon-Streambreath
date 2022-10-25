cmake_minimum_required(VERSION 3.24)

set(CXX_FILES src/init.cpp src/validationLayers.cpp)

if(DRAGON_BUILD_SHARED)
	add_library(streambreath SHARED ${CXX_FILES})
else() 
	add_library(streambreath STATIC ${CXX_FILES})
endif()
target_include_directories(streambreath PUBLIC ${Dragon_INCLUDE_DIRS})
target_link_libraries(streambreath PUBLIC ${Boost_LIBRARIES} ${Vulkan_LIBRARiES})
add_library(Dragon::Streambreath ALIAS streambreath)