# MIT License
#
# Copyright (c) 2020 Sung Gon Kim
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

if(ENABLE_TESTS)

build_test_program(
    NAME unittest
    SRCS HumidifierTest.cpp
    LIBS humidifier
)

endif()

######################################################################
#
# The code above can be written as below using the CMake commands.
#
# if(ENABLE_TESTS)
#
# find_package(Threads REQUIRED)
# find_package(GTest REQUIRED)
# find_package(GMock REQUIRED)
#
# add_executable(unittest HumidifierTest.cpp)
#
# target_include_directories(unittest
#   PRIVATE ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})
#
# target_link_libraries(unittest
#   PRIVATE GTest::GTest GMock::GMock GMock::Main ${CMAKE_THREAD_LIBS_INIT} humidifier)
#
# gtest_add_tests(unittest "" AUTO)
#
# endif()
