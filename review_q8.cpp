
template <typename T>
class DoubleTree
{
public:
  DoubleTree() : root(nullptr) {}

  // EFFECTS: inserts datum into the tree
  void insert(T datum);

  // EFFECTS: returns the number of times datum is present
  //   in the tree using a linear recursive algorithm
  int count(T datum) const;

private:
  struct Node
  {
  public:
    Node() : datumCount(0), left(nullptr), right(nullptr) {}

    // EFFECTS: inserts datum into the subtree rooted at this node
    void insert(T datum);

    // EFFECTS: returns the number of times datum is present in the
    //   subtree rooted at this node using a linear recursive algorithm
    int count(T datum) const;

  private:
    int datumCount;
    T datum1;
    T datum2;

    Node *left;
    Node *right;
  };

  Node *root;
};

template<typename T>
int DoubleTree<T>::Node::count(T datum) const {
  int current_node_count = 0; 

  if (datumCount == 0) {
    // no data is stored
    return 0; 
  }

  if (datum < datum1) {
    if (datumCount == 2) {
      if (this->left != nullptr) {
        return this->left->count(datum);
      }
    }
    return 0; // not sub-node if don't have both datum
  }

  if (datum1 == datum) {
    current_node_count++;
  } 

  if (datumCount == 2) {
    if (datum >= datum2) {
      if (datum2 == datum) {
      current_node_count++;
      // left node will not contain a datum that is same as the input datum
      } 
      // datum >= datum2
      // find count on sub node since both dataums have value, it is possible to 
      // find a sub-datum same as datum2
      if (this->right != nullptr) {
        return current_node_count + this->right->count(datum); 
      }
    }
    
  }

  // return 1, if datum 1 same, and there is no datum 2
  // return 0, if datum1 < datum < datum2
  return current_node_count; 
}

template<typename T>

int DoubleTree<T>::count(T datum) const {
  if (root == nullptr) {
    return 0;
  }
  return root->count(datum);
}
