cmake_minimum_required (VERSION 3.13)

set (CMAKE_BUILD_TYPE Release CACHE STRING "Build type")

project(cmake-example)

option(BUILD_SHARED_LIBS "shared/static" ON)

if(POLICY CMP0042)
  # Set MACOSX_RPATH to ON
  cmake_policy(SET CMP0042 NEW)
endif()
if(POLICY CMP0078)
  cmake_policy(SET CMP0078 NEW)
endif()
if(POLICY CMP0086)
  cmake_policy(SET CMP0086 NEW)
endif()

# RPATH settings
set (CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
set (CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

list (APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package (R REQUIRED)
find_package (SWIG 3 REQUIRED)
include (${SWIG_USE_FILE})

set(CMAKE_SWIG_FLAGS "" CACHE STRING "swig flags")

set_property(SOURCE base.i PROPERTY CPLUSPLUS ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(agrum Variable.cpp)

swig_add_library (base LANGUAGE R SOURCES base.i)

message(STATUS "R_INCLUDE_DIR=${R_INCLUDE_DIR}")
target_include_directories(base PRIVATE ${R_INCLUDE_DIR})
target_link_libraries(base PRIVATE ${R_LIBRARY})
target_link_libraries(base PRIVATE agrum)

include (GNUInstallDirs)
install (TARGETS ${SWIG_MODULE_base_REAL_NAME} DESTINATION ${CMAKE_INSTALL_LIBDIR}/R/library)
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/base.R DESTINATION ${CMAKE_INSTALL_LIBDIR}/R/library)

enable_testing ()

add_test (NAME agrum COMMAND ${RSCRIPT_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/t_agrum.R)
set_tests_properties (agrum PROPERTIES WORKING_DIRECTORY ${CMAKE_BINARY_DIR} ENVIRONMENT "PYTHONPATH=${CMAKE_INSTALL_PREFIX}/${PYTHON_SITE_PACKAGES}")

