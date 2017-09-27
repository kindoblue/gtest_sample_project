cmake_minimum_required(VERSION 3.7)

set (CMAKE_CXX_STANDARD 11)

include("cmake/HunterGate.cmake")

# latest release could be found at https://github.com/ruslo/hunter/releases
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.19.111.tar.gz"
        SHA1 "683bdd1a56711abd24907973665f7f58f792ce5f"
)

project(soundex)

hunter_add_package(GTest)
hunter_add_package(Boost COMPONENTS system chrono)

# configure packages
find_package(Boost CONFIG REQUIRED system chrono)
find_package(GTest CONFIG REQUIRED) 
find_package(GMock CONFIG REQUIRED) 

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG=1)
endif()

add_executable(test_app tests/soundex_test.cpp src/Soundex.h src/dumb_array.cpp src/dumb_array.h)
target_link_libraries(test_app PUBLIC GTest::main Boost::system Boost::chrono)


enable_testing()
