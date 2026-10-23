/* BST Node Structure
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

vector<int>in;

class Solution {
  public:
  
    void func(Node* root){
        if(!root)return;
        func(root->left);
        in.push_back(root->data);
        func(root->right);
    }
    
    
    long long mergesort(int l,int h){
        if(l>=h)return 0;
        int mid=l+(h-l)/2;
        
        long long ans=0;
        ans+=mergesort(l,mid);
        ans+=mergesort(mid+1,h);
        
        int i=l,j=mid+1;
        vector<int>temp;
        while(i<=mid && j<=h){
            if(in[i]<=in[j]){
                temp.push_back(in[i]);
                i++;
            }
            else{
                temp.push_back(in[j]);
                j++;
                ans+=mid+1-i;
            }
        }
        
        while(i<=mid){
            temp.push_back(in[i]);
            i++;
        }
        
        while(j<=h){
            temp.push_back(in[j]);
            j++;
        }
        
        for(int k=0;k<temp.size();k++){
            in[l+k]=temp[k];
        }
        return ans;
    }
  
    int pairsViolatingBST(Node *root) {
        // code here
        in.clear();
        func(root);
        
        return mergesort(0,(int)in.size()-1);
    }
};
