project(MYSWAP)
#项目名
cmake_minimum_required(VERSION 3.16)
#cmake最低版本
set(CMAKE_CXX_STANDARD 14)
#c++最低协议

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/inc/*.h)

add_executable(main main.cpp ${sources} ${headers})
