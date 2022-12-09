// Write the operator() overload for the comparison functor that first prioritizes odd numbers over even numbers, then prioritizes low numbers over high numbers when called with std::sort(). Higher priority numbers will appear before lower priority numbers after the range has been sorted.

class Compare {
public:

  bool operator() (int a, int b) {

  }
};

bool Compare::operator() (int a, int b) {
  if (a % 2 == 1 && b % 2 == 0) {
    // a is odd
    return true;
  } else if (a % 2 == 0 && b % 2 == 1) {
    // b is odd
    return false;
  } 
  return a < b;
} //Compare::operator()
