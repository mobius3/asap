# This file is part of the Asap library.
#
# Copyright (c) 2018 Leonardo G. Lucena de Freitas
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

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
# FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
# COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

# This file purpose is to setup exports and version files, so that other people using cmake can use the library
# when installed.

include(CMakePackageConfigHelpers)

# Setup install of exported targets
install(EXPORT asap-targets DESTINATION lib/cmake/asap)

# Macro to write config
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/asap-config-version.cmake"
    VERSION ${ASAP_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Setup install of version config
install(
    FILES
        cmake/asap-config.cmake
        "${CMAKE_CURRENT_BINARY_DIR}/asap-config-version.cmake"
    DESTINATION
        lib/cmake/asap
)
