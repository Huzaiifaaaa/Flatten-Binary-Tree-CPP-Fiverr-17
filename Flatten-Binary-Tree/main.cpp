class Solution
{
    public:

    //here we use the recursive approach
    //base case is the root node, i.e., if root node is passed the function exits
    //it takes a node as argument & passes the left & right node respectively to itself
    //if during recursion the root node is reached it returns
    //same goes for right part of tree
    void flatten(TreeNode* root)
    {
        if (!root)
        {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode* const left = root->left;
        TreeNode* const right = root->right;

        root->left = nullptr;
        root->right = left;

        TreeNode* rightnode = root;

        while (rightnode->right)
        {
            rightnode = rightnode->right;
        }

        rightnode->right = right;
    }
};