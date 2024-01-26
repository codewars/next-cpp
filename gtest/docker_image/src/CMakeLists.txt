set(CMAKE_MESSAGE_LOG_LEVEL WARNING)
set(CMAKE_RULE_MESSAGES OFF)
set(THREADS_PREFER_PTHREAD_FLAG ON)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)

find_package(Threads REQUIRED)

add_library(challenge solution.cpp preloaded.cpp)
target_include_directories(challenge PUBLIC ../include)
target_compile_features(challenge PUBLIC cxx_std_20)
target_compile_options(challenge PUBLIC -Wall -Wextra -O2)
# target_link_libraries(challenge PUBLIC m crypto dl sqlite3 tbb fmt Threads::Threads)
target_link_libraries(challenge PUBLIC m dl fmt Threads::Threads)
