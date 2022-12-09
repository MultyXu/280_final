#include <iostream>
#include "IntSet.h"

using namespace std;

ostream &operator<<(ostream &os, const IntSet &s) {
  s.print(os);
  return os;
}

int main() {
  IntSet set; 
  set.insert(2);

  cout << set;
}

