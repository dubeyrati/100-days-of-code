class Solution {
public:
    int minDepth(TreeNode* root) {
       if(root==NULL) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int d=1;
        while(q.size()>0){
            int size=q.size();
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left==NULL && node->right==NULL) return d;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(q.size()) d++;
        }
        return d;  
    }
};