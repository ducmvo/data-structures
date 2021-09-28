// counter.cpp : implementation file for Counter class

#include "counter.h"

Counter::Counter() {
  count = 0;
  maxValue = INT_MAX;
}

Counter::Counter(int max) {
  count = 0;
  maxValue = max;
}

bool Counter::increment() {
  if (count < maxValue) {
    count++;
    return true;
  } else
    return false;
}

bool Counter::decrement() {
  if (count > 0) {
    count--;
    return true;
  } else
    return false;
}

bool Counter::setCount(int n) {
  if (n >= 0 && n <= maxValue) {
    count = n;
    return true;
  } else
    return false;
}

bool Counter::setMaxValue(int max) {
  if (max >= 0 && max <= INT_MAX) {
    maxValue = max;
    return true;
  } else
    return false;
}

int Counter::getCount() const {
  return count;
}

int Counter::getMaxValue() const {
  return maxValue;
}
