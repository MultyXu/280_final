#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;


class SquareSum
{
  int sum = 0;

public:
  // REQUIRES: Accepts one int N as its argument.
  // MODIFIES: sum
  // EFFECTS: Adds the square of N to sum, then returns the new 
  // value of sum.
  // EXAMPLE: sum=3,N=2=>7
  //sum=3+(2*2)=7
  SquareSum() {

  }

  int operator()(int N) {
    sum += N * N;
    return sum;
  }

  //int traverse(Iterator begin, Iterator end, Functor func)
};

// REQUIRES: Iterator supports the *, (prefix) ++, ==, and !=
//           operators.
// The provided iterators point to elements of type int.
// func takes one argument of type int, and returns an int.
//           begin != end
// EFFECTS:
// Applies func to every element in the range [begin, end).
// Returns the last value returned by a call to func.
//           Note: The elements in the range are not modified by func.
// EXAMPLES:
// Note: element ranges represented with braced lists: {...}
// traverse({1, 3}, fn) => fn(3) 
// calls fn(1), fn(3);
// traverse({10}, fn) => fn(10) 
// calls fn(10);
template<typename Iterator, typename Functor>
int traverse(Iterator begin, Iterator end, Functor func) {
  int last_value = 0;
  for (Iterator it = begin; it != end; ++it) {
    last_value = func(*it);
  }
  return last_value;
}

// REQUIRES: vec contains at least one element.
// EFFECTS:  Computes the magnitude of vec. The magnitude of a vector
// is defined as the square root of the sum of squares of
// its elements.
// magnitude(X1, X2, ... Xn) = sqrt(X1*X1 + X2*X2 + ... +
//
// EXAMPLES:
// magnitude({29}) => 29
// magnitude({3, 4}) => 5
// magnitude({1, 2, 2}) => 3 // sqrt(1*1 + 2*2 + 2*2)
double magnitude(const vector<int> &vec) {
  SquareSum func();
  int sum_of_squre = traverse(vec.begin(), vec.end(), func());
  // don't use SquareSum()
  double result = sqrt(sum_of_squre);
  return result;
}
    