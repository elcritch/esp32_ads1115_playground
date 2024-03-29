# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.11)
include(FetchContent)
FetchContent_Declare(
  espidflib
  GIT_REPOSITORY https://github.com/UncleRus/esp-idf-lib.git
)
FetchContent_MakeAvailable(espidflib)

set(EXTRA_COMPONENT_DIRS ${espidflib_SOURCE_DIR}/components $ENV{IDF_PATH}/examples/common_components/protocol_examples_common)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp32_ads1115_playground)

idf_build_set_property(C_COMPILE_OPTIONS -Wno-error=unused-label APPEND)
idf_build_set_property(C_COMPILE_OPTIONS -Wno-error=parentheses APPEND)
idf_build_set_property(C_COMPILE_OPTIONS -Wno-error=implicit-function-declaration APPEND)
idf_build_set_property(C_COMPILE_OPTIONS -Wno-error=maybe-uninitialized APPEND)
idf_build_set_property(C_COMPILE_OPTIONS -Wno-error=nonnull APPEND)
idf_build_set_property(C_COMPILE_OPTIONS -Wno-error=address APPEND)
idf_build_set_property(C_COMPILE_OPTIONS -Wno-unused-but-set-variable APPEND)
