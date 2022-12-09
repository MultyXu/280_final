// Requires: node points to root of valid BST 
// Effects: Returns the amount a tree sways in one direction. 
// 		 Sway is denoted by the amount of nodes that are 
// 		 "unbalanced" - nullptr on only one side, a left 
// 		 swaying tree returns the negative amount it sways 
//		 with any right sway offsetting the left and vice versa
// 
// Examples: 
//   (4				(4)			(4)				(4)
//   /   = -1  		/ \  = 0		  \   = 2			   \   = 0
// (2) 			    (2) (7)		   (7)			    (7)
// 								\			   /
// 								 (9)			(5)	
struct Node
{
  int *datum;
  Node *left; 
  Node *right;
};

int tree_sway(Node * node){ 
  if (node == nullptr) {
    return 0;
  } else if (node->left == nullptr && node->right != nullptr) {
    return 1 + tree_sway(node->right);;
  } else if (node->right == nullptr && node->left != nullptr) {
    return tree_sway(node->left) - 1;
  } else {
    return tree_sway(node->left) + tree_sway(node->right);
  }
} //tree_sway 
