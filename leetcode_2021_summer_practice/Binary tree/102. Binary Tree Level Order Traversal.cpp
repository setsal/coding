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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> myQue;
        if (root != nullptr) {
            myQue.push(root);
        }

        vector<vector<int>> res;

        while (!myQue.empty()) {
            int length = myQue.size();
            vector<int> tmpVec;

            for (int i = 0; i < length; i++) {
                TreeNode* node = myQue.front();
                myQue.pop();
                tmpVec.push_back(node->val);
                
                if (node->left) {
                    myQue.push(node->left);
                }
                
                if (node->right) {
                    myQue.push(node->right);
                }
                    
            }
            res.push_back(tmpVec);
        }

        return res;
    }
};