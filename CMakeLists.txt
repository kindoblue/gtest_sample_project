cmake_minimum_required(VERSION 3.7)

include("cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.91.tar.gz"
    SHA1 "7202b636c3456b32a3b869f2aca5dee509c80111"
)


project(soundex)

hunter_add_package(GTest)


find_package(GTest CONFIG REQUIRED) 
find_package(GMock CONFIG REQUIRED) 

add_executable(test_app tests/soundex_test.cpp)
target_link_libraries(test_app PUBLIC GTest::main)

enable_testing()
