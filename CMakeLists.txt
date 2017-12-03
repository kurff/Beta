project(Beta)
option(test "Build all tests." ON)
SET(CMAKE_C_COMPILER g++)
add_compile_options(-std=c++11)

if (test)
enable_testing()
add_executable(test_tree  test/test_tree.cc)
target_link_libraries(test_tree gtest gtest_main glog)
add_test(NAME test_tree COMMAND test_tree)
endif()

include_directories(./)
include_directories(/usr/local/include)


add_library(libproto proto/beta.pb.cc)
add_executable(Demo main.cpp )

target_link_libraries(Demo  libproto glog protobuf )

