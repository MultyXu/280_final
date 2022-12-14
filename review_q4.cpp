template <typename T>
class List {
public:
  // Assume the default ctor and Big Three are defined as needed

  // EFFECTS: Returns the number of elements that are
  //          at the same position and have the same
  //          value in both this list and the other
  // EXAMPLES:
  //  this list: {6, 5, 6}, other: {2, 5, 6} -> returns 2
  //  this list: {5}, other: {5, 6} -> returns 1
  //  this list: {4, 7}, other: {7, 4} -> returns 0
  //  this list: {5}, other: {} -> returns 0
  int count_matches(const List &other) const {
    int count = 0; 
    Node *n1 = first;
    Node *n2 = other.first;
    while(n1 !== nullptr && n2 != nullptr) {
      if (n1->datum == n2->datum) {
        count++;
      }
    }
    return count;
  }
private:
  struct Node {
    T datum;    // element stored in this Node
    Node *prev; // previous Node, or null if none
    Node *next; // next Node, or null if none
  };

  Node *first;  // first Node in the list, or null if empty
  Node *last;   // last Node in the list, or null if empty

  int num_nodes; // number of nodes in the list

  // REQUIRES: rng_first and rng_last point to Nodes in this list.
  //           The node pointed to by rng_last is either the same node
  //           as pointed to by rng_first or comes after it in the list.
  // MODIFIES: *this
  // EFFECTS:  Moves all nodes starting with rng_first and ending with
  //           (and including) rng_last to the back of the list.
  // EXAMPLE: If list contains [2, 4, 5, 3, 7, 9, 1], rng_first
  //          points to the node holding 5 and rng_last points to the
  //          node holding 7, then list.move_range_to_back(rng_first, rng_last)
  //          modifies it to be [2, 4, 9, 1, 5, 3, 7].
  // HINT:    Use scratch paper to draw a picture.
  template <typename T>
  void move_range_to_back(Node *rng_first, Node *rng_last) {

    if (rng_last == last) {
      return; // do nothing if already at back
    }

    rng_last->next->prev = rng_first->prev;

    if (rng_first->prev) {
      // if is not first node
      rng_first->prev->next = rng_last->next;
    } else {
      // if is first node
      first = rng_last->next;
    }

    last->next = rng_first;
    rng_first->prev = last;

    rng_last->next = nullptr;


};