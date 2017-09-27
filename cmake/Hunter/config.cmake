
# versions here https://github.com/ruslo/hunter/blob/master/cmake/projects/GTest/hunter.cmake
hunter_config(GTest VERSION 1.8.0-hunter-p7 CMAKE_ARGS GTEST_SUPER_MODE=ON)

hunter_config(Boost VERSION 1.65.0 CMAKE_ARGS IOSTREAMS_NO_BZIP2=1)