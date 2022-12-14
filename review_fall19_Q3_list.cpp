#include <iostream>

template <typename T>
class List
{
public:
  // EFFECTS: Initializes this list to be empty.
  List() : first(nullptr), last(nullptr) {}
  void pop_front();               // removes the first element from the list
  void pop_back();                // removes the last element from the list
  int first_out_of_order();       // *You will implement this in part (3a)*
  void remove_all_out_of_order(); // *You will implement this in part (3c)*
  // Assume the Big Three are defined as needed.

private:
  struct Node
  {
    T datum;    // the element stored in this Node
    Node *next; // the next Node, or null if there is none
    Node *prev; // the previous Node, or null if there is none
  };

  Node *first;                  // first node in the list, or null if it is empty
  Node *last;                   // last node in the list, or null if it is empty

  // REQUIRES: index is a valid index in the list.
  // The list is not empty.
  // EFFECTS: Removes the Node at the given index while maintaining the 
  // list properties.
  // EXAMPLES:
  // Given {1, 3, 5, 1, 8}, remove_index(3) => {1, 3, 5, 8}
  // Given {1, 2, 3}, remove_index(0) => {2, 3}
  // Given {1, 3}, remove_index(1) => {1}
  void remove_index(int index) {
    if (index == 0) {
      pop_front();
      return;
    }

    Node *ptr = first; 
    for (int i = 0; i < index; i++) {
      ptr = ptr->next;
    }

    if (ptr == last) {
      pop_back();
      return;
    }

    ptr->prev->next = ptr->next; // link the previous node to the next node
    ptr->next->pre = ptr->prev;
    delete ptr; 
  } // *You will implement this in part (3b)*
};

// REQUIRES: Type T has implemented the greater-than(>) comparison operator. 
// EFFECTS: Returns the index of the first element out of order (lesser
//           value than the element before it). If the list is empty or
//           already sorted, return -1.
// EXAMPLES:
// {1, 2, 3, 6, 5, 8} => 4 
// {2, 3, 6, 4, 9, 8} => 3 
// {4, 4, 3, 9, 2, 0, 0} => 2
template <typename T>
int List<T>::first_out_of_order() {
  int idx = 0;
  Node *ptr = first;
  if (ptr == nullptr){
    // empty list
    return -1;
  }

  while(ptr->next != nullptr) {
    if (ptr->datum > ptr->next->datum){
      return idx + 1;
    }
    idx++;
    ptr = ptr->next;
  }

  return -1;
}

// EFFECTS: Removes all Nodes in the list whose value is out-of-order 
// (as defined in 3a).
// EXAMPLES:
// {1, 2, 4, 3, 5} => {1, 2, 4, 5}
// {1, 1, 7} => {1, 1, 7}
// {1, 3, 2, 1, 5, 1, 7, 6} => {1, 3, 5, 7}
template <typename T>
void List<T>::remove_all_out_of_order() {
  int out_of_order_idx = first_out_of_order();
  while (out_of_order_idx != -1) {
    remove_index(out_of_order_idx);
    out_of_order_idx = first_out_of_order();
  }
}

int main() {

}