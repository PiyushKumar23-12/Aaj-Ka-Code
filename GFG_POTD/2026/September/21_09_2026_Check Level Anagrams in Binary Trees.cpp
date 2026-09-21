/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        // code here
        
        queue<Node*>q1,q2;
        
        q1.push(root1);
        q2.push(root2);
        
        //o(N)
        
        
        while(!q1.empty() || !q2.empty()){
            int x=q1.size();
            int y=q2.size();
            
            if(x!=y)return false;
            
            //number of nodes same
            
            map<int,int>m;
            
            for(int i=0;i<x;i++){
                auto c1=q1.front();
                auto c2=q2.front();
                q1.pop();
                q2.pop();
                
                m[c1->data]++;
                m[c2->data]--;
                
                if(c1->left){
                    q1.push(c1->left);
                }
                
                if(c1->right){
                    q1.push(c1->right);
                }
                
                if(c2->left){
                    q2.push(c2->left);
                }
                
                if(c2->right){
                    q2.push(c2->right);
                }
            }
            
            
            for(auto i:m){
                if(i.second!=0)return false;
            }
        }
        
        return true;
        
    }
};
