/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    map<int,int>m;
    
    
    void func(Node* r){
        if(!r)return;
        
        m[r->data]++;
        func(r->left);
        func(r->right);
    }
  
    vector<int> findCommon(Node* r1, Node* r2) {
        // code here
        
        func(r1);
        func(r2);
        
        vector<int>ans;
        for(auto i:m){
            if(i.second==2){
                ans.push_back(i.first);
            }
        }
        return ans;
        
    }
};
