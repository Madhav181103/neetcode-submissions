class Solution {
public:
    unordered_map<int, int> in;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] = i;
        }

        return helper(preorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int preidx, int start, int end) {
        if (start > end)
            return nullptr;

        if(preidx>=preorder.size())return NULL;
        TreeNode* root = new TreeNode(preorder[preidx]);

       
        int idx = in[preorder[preidx]];

        int leftSize = idx - start;


        root->left = helper(
            preorder,
            preidx + 1,
            start,
            idx - 1
        );

        root->right = helper(
            preorder,
            preidx + leftSize + 1,
            idx + 1,
            end
        );

        return root;
    }
};