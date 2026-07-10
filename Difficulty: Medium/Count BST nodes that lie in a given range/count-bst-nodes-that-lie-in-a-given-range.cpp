/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    int count = 0;
  private:
    void traverse(Node* root, int l, int h){
        if(root == NULL) return;
        
        traverse(root->left, l, h);
        
        if(root->data >= l && root->data <= h) count++;
        
        traverse(root->right, l, h);
    }
  public:
    int getCount(Node *root, int l, int h) {
        traverse(root, l, h);
        return count;
    }
};