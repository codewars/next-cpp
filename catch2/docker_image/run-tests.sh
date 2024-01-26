#!/bin/sh

cmake --build build && ./build/tests/tests --reporter=codewars
