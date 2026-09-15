/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        // code here
        
        //leaf nodes cost
        //sorted 
        vector<int>cost;
        
        int level=1;
        
        queue<Node*>q;
        
        q.push(root);
        
        //10
        
        
        while(!q.empty()){
            int x=q.size();
            
            for(int i=0;i<x;i++)
            {
                auto cur=q.front();
                q.pop();
                
                
                if(cur->left){
                    q.push(cur->left);
                }
                
                if(cur->right){
                    q.push(cur->right);
                }
                
                
                //leaf 
                
                if(!cur->left && !cur->right){
                    cost.push_back(level);
                }
                
            }
            level++;
        }
        
        
        int i=0,sum=0;
        
        while(i<cost.size() && sum+cost[i]<=k){
            sum+=cost[i];
            i++;

        }
        return i;

    }
};
