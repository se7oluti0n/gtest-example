# Minimum CMake version require
cmake_minimum_required(VERSION 2.8)
# Create for test option, enable in command with 'cmake -Dtest=ON'
option(test "Build all test." ON)

set(PROJECT_NAME example)
project(${PROJECT_NAME})

# add project code folder by 'aux_source_directory(src SRC_DIR)'
# or can set source code file by command 'file'
set(SRC_DIR ./src)

aux_source_directory(${SRC_DIR} SRC_LIST)
# add project code depenent
find_package(OpenCV REQUIRED)
# find_package will automatically include package include folder to include_directories

#Details test 
if (test)
 
  # CMake only enable test when call this command 
  enable_testing() 
  
  # Add gtest
  include_directories(${SRC_DIR}) 
  include_directories(/usr/local/include/gtest)
  link_directories(/usr/local/lib)
 
  aux_source_directory(test TEST_LIST) 

  add_executable(runTests ${TEST_LIST} ${SRC_LIST})

  target_link_libraries(runTests ${OpenCV_LIBS})
  target_link_libraries(runTests gtest gtest_main)

  #Add test so you can run 'make test' for all test : add_test(Name test_name COMMAND test_executable)
  add_test(first_test runTests)
endif()
