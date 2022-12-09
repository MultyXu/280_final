#include <cassert>

template <typename T>
class List
{
private:
  struct Node
  {
    Node *next;
    Node *prev;
    T datum;
  };

  Node *first; // points to first Node in list, or 0 if list is empty
  Node *last;  // points to last Node in list, or 0 if list is empty
public:
  // REQUIRES: there are at least k + 1 elements in the list
  // EFFECTS: return the k from last element in the list
  // e.g.,
  //  k = 2, [3, 7, 6, 4, 9] → 6 (the 2nd from the last element)
  //  k = 1, [3, 7, 6, 4, 9] → 4 (the 1st from the last element)

  T kFromEnd(int k) {
    Node *n = last;
    for (int i = 0; i < k; i++){
      n = last->prev;
    }
    return n->datum;
  } // kFromEnd

  // REQUIRES: n <= length of the list.
  // EFFECTS: Rotates the list by n. The effect is that the 
  // first n elements are moved from the front of the 
  // list to the back (they are still in the same order 
  // with respect to each other). 
  // NOTE: You may not copy any T objects. They could be very large!
  // e.g.,
  // n = 1, [1, 2, 3] → [2, 3, 1]
  // n = 2, [1, 2, 3] → [3, 1, 2]
  // n = 3, [1, 2, 3] → [1, 2, 3]
  void rotate(int n) {
    Node *node;
    for (int i = 0; i < n; i++) {
      node = first; // temp store the first node
      first = first->next; // move first node to the second one
      first->prev = nullptr;
      node->next = nullptr;
      node->prev = last;
      last->next = node; // link temp node to the last node
      last = node; // make the new last
    }
  }
};

int main()
{
}