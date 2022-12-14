  
  //EFFECTS: returns a if a >= b, returns b if // b>a
  // int max(int a, int b);
  // REQUIRES: root points to the root of a valid
  // binary search tree.The tree does not contain
  // duplicate elements, is not sorted and contains
  // only positive ints.
  //EFFECTS: Returns the greatest sum of the
  //         path starting at the root of the
  //         tree and ending at a leaf node.
  // Returns 0 for an empty tree.
  //EXAMPLE: For the tree on the right, greatest_path
  //         returns (6 + 4 + 8) = 18
  static int greatest_path(const Node *root){
    if(root == nullptr) {
      return 0;
    } else {
      return root->datum + max(greatest_path(root->left), greatest_path(root->right));
    }
  }

  // EFFECTS:  Returns true if every node has exactly two children or is
  //           a leaf node.