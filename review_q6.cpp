class List {
private:
  struct Node
  {
    int datum; 
    Node *next;
  };

  int index_of_helper(Node *node, int value, int index) {
    if (node == nullptr) {
      // does not find a value
      return -1;
    } else if (node->datum == value) {
      // find the value
      return index;
    } else {
      // in the iteration, doesn't reach the end of the list
      return index_of_helper(node->next, value, index + 1);
    }
  }
  
public:
  // EFFECTS: Returns the index at which 'value' first occurs in the
  //          given list. If the value does not occur, returns -1.
  int index_of(Node *node, int value) {
    return index_of_helper(node, value, 0);
}
};