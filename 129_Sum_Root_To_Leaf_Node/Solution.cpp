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
    int solve(TreeNode* root, int sum){
        // if root is null return sum 0 
        if(root==NULL){
            return 0;
        }
        // if not null calculate the sum of the current node and store in the sum var
        sum = (sum*10) + root->val;
        // if no left and right is present than it is the leaf node return the current calculated sum
        if(root->left == NULL && root->right == NULL){
            return sum;
        }
        // calculate the left and right sum by passing the left and tight node and the current sum
        int leftSum = solve(root->left,sum);
        int rightSum = solve(root->right,sum);
        // and return the sum of left and right nodes
        return leftSum + rightSum;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};


