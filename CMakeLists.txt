cmake_minimum_required(VERSION 3.8)

set (CMAKE_CXX_STANDARD 11)

include("cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.91.tar.gz"
    SHA1 "7202b636c3456b32a3b869f2aca5dee509c80111"
)


project(soundex)

hunter_add_package(GTest)

find_package(GTest CONFIG REQUIRED) 
find_package(GMock CONFIG REQUIRED) 

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG=1)
endif()

add_executable(test_app tests/soundex_test.cpp src/Soundex.h)
target_link_libraries(test_app PUBLIC GTest::main)

enable_testing()
