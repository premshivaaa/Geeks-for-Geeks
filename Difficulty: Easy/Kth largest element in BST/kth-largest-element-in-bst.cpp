/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
    int result = 0;
    void inOrder(Node* node, int& k){
        if(node == NULL){
            return;
        }
        inOrder(node->right, k);
        
        k--;
        
        if(k==0){
            result = node->data;
        }

        inOrder(node->left, k);
    }
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
        inOrder(root, k);
        return result;
    }
};