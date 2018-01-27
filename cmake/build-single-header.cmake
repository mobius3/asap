find_program(CPP cpp)
find_program(SED sed)

foreach(INCLUDE ctime string iomanip sstream cmath type_traits cstdint)
  file(WRITE "${BIN_DIR}/include-surrogates/${INCLUDE}" "include <${INCLUDE}>")
endforeach()

if ("${CPP}" STREQUAL "CPP-NOTFOUND")
  message(FATAL_ERROR "The C preprocessor (cpp) was not found.")
endif()

if ("${SED}" STREQUAL "SED-NOTFOUND")
  message(FATAL_ERROR "The sed stream editor (sed) was not found.")
endif()

file(MAKE_DIRECTORY ${BIN_DIR}/dist/)

execute_process(
  COMMAND
    ${CPP}
      "-Dinclude=#include"
      "-I${SRC_DIR}/include/asap"
      "-I${BIN_DIR}/include-surrogates/"
      "${SRC_DIR}/include/asap/asap.h"
    OUTPUT_FILE ${BIN_DIR}/.tmp.h
  COMMAND
    ${SED}
      "-e"
      "s/^# [0-9].*$//g"
      "-e"
      "/^\\s*$/d"
   OUTPUT_FILE ${BIN_DIR}/dist/asap.h
)

message(STATUS "${BIN_DIR}/dist/asap.h ready")
