# Copyright (C) 2018 Leonardo Guilherme Lucena de Freitas
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of
# this software and associated documentation files (the "Software"), to deal in
# the Software without restriction, including without limitation the rights to
# use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
# the Software, and to permit persons to whom the Software is furnished to do so,
# subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
# FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
# COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

# This file specifies an INTERFACE library, allowing you to include Asap in your CMake project.
# To use Asap in your project, put this folder under your source dir and use `add_subdirectory(asap)`. For every
# target that uses asap, a simple `target_link_libraries(target asap)` is sufficient to set up include and link
# instructions.

cmake_minimum_required(VERSION 3.1.0)
project(asap)

# Setup variables and options
option(ASAP_BUILD_EXAMPLES "Build examples contained in examples/ folder. It might require additional dependencies." ON)

# Setup version
include(cmake/setup-version.cmake)

# Setup cxx standard
set(CMAKE_CXX_STANDARD 11)

# The library target
add_library(asap INTERFACE)

# Set up include directories
target_include_directories(asap INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/asap>
  $<INSTALL_INTERFACE:include/asap>
  )

# Set up install
install(TARGETS asap EXPORT asap-targets)
install(DIRECTORY include/ DESTINATION include/)

# Set up export and config
include(cmake/setup-exports.cmake)

# Set up cpack
include(cmake/setup-cpack.cmake)

# Include examples
if (ASAP_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

# This library is a convenience library to force files to properly appear in the IDE.
add_library(asap-dummy
  include/asap/datetime.h
  include/asap/duration.h
  include/asap/operators.h
  include/asap/constants.h
  include/asap/period.h
  include/asap/asap.h
  include/asap/literals.h
  include/asap/datetime.tcc
  include/asap/duration.tcc
  include/asap/period.tcc)
set_target_properties(asap-dummy PROPERTIES LINKER_LANGUAGE CXX EXCLUDE_FROM_ALL TRUE)
