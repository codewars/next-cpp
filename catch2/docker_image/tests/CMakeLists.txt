set(CMAKE_MESSAGE_LOG_LEVEL WARNING)
set(CMAKE_RULE_MESSAGES OFF)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.1
)
FetchContent_MakeAvailable(Catch2) # Catch2::Catch2, Catch2::Catch2WithMain

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)


add_executable(tests codewars_reporter.cpp test_solution.cpp)
target_compile_features(tests PRIVATE cxx_std_20)
target_compile_options(tests PRIVATE -Wall -Wextra -O2)
# target_link_libraries(tests PRIVATE challenge Catch2::Catch2 m crypto dl sqlite3 tbb fmt Threads::Threads)
target_link_libraries(tests PRIVATE challenge Catch2::Catch2WithMain m dl fmt Threads::Threads)

# Not really necessary for CR, but allows running tests through CMake
add_test(NAME tests COMMAND tests)
