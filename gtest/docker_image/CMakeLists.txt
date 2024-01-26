cmake_minimum_required(VERSION 3.5...3.28)
set(CMAKE_MESSAGE_LOG_LEVEL WARNING)
set(CMAKE_RULE_MESSAGES OFF)

# Project name and a few useful settings. Other commands can pick up the results
project(QualifiedCppChallenge
  VERSION 0.1
  DESCRIPTION "Qualified C++ Challenge"
  LANGUAGES CXX)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # Ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Testing only available if this is the main app.
  # Note this needs to be done in the main CMakeLists
  # since it calls enable_testing, which must be in the
  # main CMakeLists.
  include(CTest)
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# The compiled library code is here
add_subdirectory(src)

# Testing only available if this is the main app
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_subdirectory(tests)
endif()
