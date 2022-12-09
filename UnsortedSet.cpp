//#include "UnsortedSet.h"
#include <iostream>

template <typename T>
class UnsortedSet {
public:
  // Maximum size of a set.
  static const int MAX_SIZE = 10;

  // EFFECTS:  Initializes this set to be empty.
  UnsortedSet();

  // REQUIRES: size() < MAX_SIZE
  // MODIFIES: *this
  // EFFECTS:  Adds value to the set, if it isn't already in the set.
  void insert(T value);

  // MODIFIES: *this
  // EFFECTS:  Removes value from the set, if it is in the set.
  void remove(T value);

  // EFFECTS:  Returns whether value is in the set.
  bool contains(T value) const;

  // EFFECTS:  Returns the number of elements.
  T size() const;

  // EFFECTS:  PrTs out the set in an arbitrary order.
  void print(std::ostream &os) const;

private:
  T elts[MAX_SIZE];
  size_t elts_size;
  // INVARIANTS:
  // 0 <= num_elements && num_elements <= MAX_SIZE
  // the first num_elements items in elements are the items in the set
  // the first num_elements items in elements contain no duplicates

  // EFFECTS: Returns the index of the v in the elts
  //          array. If not present, returns -1.
  int indexOf(T v) const;
};

///////////////// Imeplementation of Unsorted Set////////////////////
template <typename T>
UnsortedSet<T>::UnsortedSet(): elts_size(0) {

}

template <typename T>
void UnsortedSet<T>::insert(T value) {
  assert(elts_size <= MAX_SIZE);
  if (!contains(value)){
    elts[elts_size] = value;
    elts_size++;
  }
}

template <typename T>
void UnsortedSet<T>::remove(T value) {
  T idx = indexOf(value);
  if (idx == -1) {
    return;
  } else {
    elts[idx] = elts[elts_size - 1];
    elts_size--;
  }
}

template <typename T>
bool UnsortedSet<T>::contains(T value) const {
  return indexOf(value) != -1;
}

template <typename T>
T UnsortedSet<T>::size() const {
  return elts_size;
} 

template <typename T>
void UnsortedSet<T>::print(std::ostream &os) const {
  for (int i = 0; i < elts_size; i++){
    os << elts[i];
  } 
  os << "\n";
}

template <typename T>
int UnsortedSet<T>::indexOf(T v) const {
  for (int i = 0; i < elts_size; i++) {
    if(elts[i] == v) {
      return i;
    } 
  }
  return -1;
}
///////////// end of implementation //////////

template <typename T>
std::ostream &operator<<(std::ostream &os, const UnsortedSet<T> &s) {
  s.print(os);
  return os;
}

int main() {
  UnsortedSet<char> char_set; 
  char_set.insert('a');
  char_set.insert('b');
  std::cout << char_set << std::endl;
}