cmake_minimum_required(VERSION 3.15)

project (<myModule> LANGUAGES C)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  MESSAGE(FATAL_ERROR "Toolchain file not set, try using: cmake --preset default")
endif()

add_subdirectory(ag-ffi-header)

find_package(<myModule> CONFIG REQUIRED)

add_library (<myModule> STATIC <myModuleFfi>.c)

target_link_libraries(<myModule> PUBLIC <everything from vcpkg>)

ag_ffi_configure_target(<myModule> <myModuleFfi>.ag)
