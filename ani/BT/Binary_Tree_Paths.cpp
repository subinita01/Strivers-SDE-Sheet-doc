
// https://leetcode.com/problems/binary-tree-paths/
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(h) where h is the height of the tree
// DFS approach
// LC 257. Binary Tree Paths


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void allpath(TreeNode* root, string path, vector<string>& ans){
        // jitte leaf nodes utte push back
        if(root->left==NULL && root->right==NULL){
            ans.push_back(path);
            return ;
        }
        //what if root->left null and root->right exist and vice versa, nothing to return, 
        //so handle using if
        if(root->left){
            allpath(root->left, path+"->"+to_string(root->left->val), ans);
        }
        if(root->right){
            allpath(root->right, path+"->"+to_string(root->right->val), ans);
        } 
        return ;       
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = to_string(root->val);
        vector<string> ans;
        allpath(root, path, ans);
        return ans;
        
    }
};