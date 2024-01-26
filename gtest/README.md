# GoogleTest

## Scripts for local Docker

Locally I use Windows, that's why my scripts are batch files.
- `build-image.bat` builds an image to run C++ kata,
- `run-image.bat` runs code of a kata in a container. Use `run-image KATA-CODE` to run, whenre `KATA-CODE` is a name of one of subdirectories in `kata_code` directory. 

## Docker image

Kata code is built and run with:

```bash
cmake -S . -B build -G Ninja
cmake --build build && ./build/tests/tests
```

Use `./configure.sh` and `./run-tests.sh`.

We'll configure and build an example project while building the container image so each submission will only build the submitted code.

The `snippets` directory contains snippets of example kata as they are submitted, before preprocessing.

The `kata_code` directory contains source file of a kata as produced by the CW preprocessor. The files are cp-ed into a container.

## Example kata

- `ExampleExceptions` - a set of test cases to evaluate output of the reporter in case of expected and unexpected exceptions.
- `ExampleFailureMessages` - showcase of assertions and matchers most useful for CW authors.
- `ExampleOrganization` - a set of test fixtures instantiated in various ways evaluate output of the reporter (especially grouping of tests).
- `ExampleParametrized` - a set of parametrized/generated tests to evaluate output of the reporter.
- `OriginalExample` - the original example of Google Test tests prepared by kazk. It uses no CW preprocessor markers, and only `preloaded.h` and `solution.cpp` are relevant. `preloaded.cpp` and `solution.h` are also saved, but are irrelevant, and cause no problems when buiding and testing the kata.
- `UniqueInOrder` - a kata which requires separate cpp file and header file for solution, because it requires users to implement two functions: one is a template, and one is a "normal" function. It uses CW preprocessor markers to split submitted solution snippet into two files.
- `Cafeteria` - a kata with no preprocessing markers, with a complex preloaded, where both solution and preloaded are treated as headers, and the cpp part of both gets (apparently) ignored. It also defines custom `operator <<` for the preloaded types, which is used by GTest to present instances in failure messages. To be honest, I am not sure why this example works because I expected it to fail with linker errors caused by standalone definitions of `operator<<`. I need to take a better look.
