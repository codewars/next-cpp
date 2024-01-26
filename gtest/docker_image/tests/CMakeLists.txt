set(CMAKE_MESSAGE_LOG_LEVEL WARNING)
set(CMAKE_RULE_MESSAGES OFF)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest) # gtest, gtest_main, gmock, gmock_main

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)

add_executable(tests main.cpp test_solution.cpp)
target_compile_features(tests PRIVATE cxx_std_20)
target_compile_options(tests PRIVATE -Wall -Wextra -O2)
# target_link_libraries(tests PRIVATE challenge gtest gmock m crypto dl sqlite3 tbb fmt Threads::Threads)
target_link_libraries(tests PRIVATE challenge gtest gmock m dl fmt Threads::Threads)

# Not really necessary for CR, but allows running tests through CMake
add_test(NAME tests COMMAND tests)
