/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
  public:
  
  
    int func(Node* root,int &ans){
        if(!root)return 0;
        if(!root->left && !root->right)return root->data;
        
        int lt=func(root->left,ans);
        int rt=func(root->right,ans);
        
        
        if(root->left && root->right){
            ans=max(ans,lt+rt+root->data);
            return max(lt,rt)+root->data;
        }
        
        
        if(root->left){
            return lt+root->data;
        }
        return rt+root->data;
    }
    int maxPathSum(Node *root) {
        // code here
        int ans=INT_MIN;
        func(root,ans);
        
        if(ans==INT_MIN)return -1;
        return ans;
    }
};
