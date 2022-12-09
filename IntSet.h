#include <iostream>

class IntSet {
public:
  // Maximum size of a set.
  static const int MAX_SIZE = 10;

  // EFFECTS:  Initializes this set to be empty.
  IntSet();

  // REQUIRES: size() < MAX_SIZE
  // MODIFIES: *this
  // EFFECTS:  Adds value to the set, if it isn't already in the set.
  void insert(int value);

  // MODIFIES: *this
  // EFFECTS:  Removes value from the set, if it is in the set.
  void remove(int value);

  // EFFECTS:  Returns whether value is in the set.
  bool contains(int value) const;

  // EFFECTS:  Returns the number of elements.
  int size() const;

  // EFFECTS:  Prints out the set in an arbitrary order.
  void print(std::ostream &os) const;

private:
  int elts[MAX_SIZE];
  size_t elts_size;

  // EFFECTS: Returns the index of the v in the elts
  //          array. If not present, returns -1.
  int indexOf(int v) const;
};

std::ostream &operator<<(std::ostream &os, const IntSet &s);

IntSet::IntSet(): elts_size(0) {

}

void IntSet::insert(int value) {
  assert(elts_size <= MAX_SIZE);
  if (!contains(value)){
    elts[elts_size] = value;
    elts_size++;
  }
}

void IntSet::remove(int value) {
  int idx = indexOf(value);
  if (idx == -1) {
    return;
  } else {
    elts[idx] = elts[elts_size - 1];
    elts_size--;
  }
}

bool IntSet::contains(int value) const {
  return indexOf(value) != -1;
}

int IntSet::size() const {
  return elts_size;
} 

void IntSet::print(std::ostream &os) const {
  for (int i = 0; i < elts_size; i++){
    os << elts[i];
  } 
  os << "\n";
}

int IntSet::indexOf(int v) const {
  for (int i = 0; i < elts_size; i++) {
    if(elts[i] == v) {
      return i;
    } 
  }
  return -1;
}