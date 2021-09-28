// counter.h : header file for Counter class

#ifndef COUNTER_H
#define COUNTER_H

#include <iostream> 
#include <climits> // for default max value INT_MAX

class Counter {
  public:
    Counter();
    Counter(int);
    // constructors
    
    bool increment();
    // increments counter by one unless max value reached;
    // returns false if max value was reached

    bool decrement();
    // decrements counter by one unless min value reached;
    // returns false if min value (0) was reached

    bool setCount(int);
    // sets counter to n; returns false if n is less than 0 
    // or greater than max value

    bool setMaxValue(int);
    // sets max value for counter; returns false if max is
    // greater than maximum integer value for system

    int getCount() const;
    // returns current counter value
   
    int getMaxValue() const;
    // returns current max value

  private:
    int count;
    int maxValue;
};

#endif // COUNTER_H
