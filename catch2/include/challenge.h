#pragma once

// A simple monotonic counter.
class Counter {
 private:
  int counter_;

 public:
  // Creates a counter that starts at 0.
  Counter() : counter_(1) {}
  // Returns the current counter value, and increments it.
  int Increment();
  // Returns the current counter value, and decrements it.
  int Decrement();
};
