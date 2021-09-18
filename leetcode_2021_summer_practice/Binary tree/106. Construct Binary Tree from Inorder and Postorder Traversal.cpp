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
    TreeNode* traversal (vector<int>& inorder, vector<int>& postorder) {
        
        if (postorder.size() == 0) {
            return nullptr;
        }

        // contruct root node
        int rootVal =postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootVal);

        // find delimiter in inorder
        int delimiter;
        for (delimiter = 0; delimiter < inorder.size(); delimiter++) {
            if(inorder[delimiter] == rootVal) 
                break;
        }

        // split inorder
        // [0, delimiter)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiter);

        // [delimiter + 1, end)
        vector<int> rightInorder(inorder.begin() + delimiter + 1, inorder.end());

        // postOrder -> remove last 
        postorder.resize(postorder.size() - 1);
    
        // split postOrder
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;

    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
};