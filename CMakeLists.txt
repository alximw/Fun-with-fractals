cmake_minimum_required (VERSION 2.6)
project (fractals)

# The version number.
set (fractals_VERSION_MAJOR 1)
set (fractals_VERSION_MINOR 0)
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/fractalsConfig.h.in"
  "${PROJECT_BINARY_DIR}/fractalsConfig.h"
  )
 
include_directories("${PROJECT_BINARY_DIR}")
 

add_executable(fractals_cantor cantor_set.c)

add_custom_target(run
    COMMAND fractals_cantor
    DEPENDS fractals_cantor
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)