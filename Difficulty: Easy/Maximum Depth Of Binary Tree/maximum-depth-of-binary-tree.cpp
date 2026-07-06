/* The Node structure is
class Node {
public:
    int data;
    Node* left;
    Node* right;

};
}; */

class Solution {
  public:
    int maxDepth(Node *root) {
        if(root == NULL) return 0;
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
