cmake_minimum_required(VERSION 3.24)

set(CXX_FILES src/validationLayers.cpp)

add_library(streambreath ${CXX_FILES})
target_include_directories(streambreath PUBLIC ${Dragon_INCLUDE_DIRS})
target_link_libraries(streambreath PUBLIC ${Dragon_LINK_LIBRARIES})
add_library(Dragon::Streambreath ALIAS streambreath)