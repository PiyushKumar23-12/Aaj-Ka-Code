/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
    vector<int>temp;
    
    
    void func(Node* root){
        
        //Null
        if(!root)return;
        
        //LNR
        func(root->left);
        
        temp.push_back(root->data);
        
        func(root->right);
        
    }
  
    int absDiff(Node *root) {
        // code here
        
        temp.clear();
        func(root);
        
        
        int ans=1e8;
        
        int i=0;
        while(i<temp.size()-1){
            ans=min(ans,temp[i+1]-temp[i]);
            i++;
        }
        return ans;
        
        
    }
};
