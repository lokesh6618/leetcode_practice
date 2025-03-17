#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else if (val > root->val)
        root->right = insertIntoBST(root->right, val);
    return root;
}

// Function to create a BST from an array of values
TreeNode* createBinarySearchTree(const vector<int>& values) {
    TreeNode* root = nullptr;
    for (int val : values) {
        if (val != -1)  // Ignore -1 values
            root = insertIntoBST(root, val);
    }
    return root;
}

// Function to print level-order traversal of the tree
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr)
            cout << curr->val << " ";
        else
            cout << "null ";
        
        if (curr) {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    cout << endl;
}

void moveRoot(TreeNode* root){

    if(!root->right && !root->left){
        delete root;
        return;
    }

    int temp_val = root->val;

    if(root->right){
        root->val = root->right->val;
        root->right->val = temp_val;
        moveRoot(root->right);
    }else{
        root->val = root->left->val;
        root->left->val = temp_val;
        moveRoot(root->left);
    }
}

TreeNode* findMin(TreeNode* root){
    while(root->left){
        root = root->left;
    }

    return root;
}

TreeNode* deleteNode(TreeNode* root, int val){
    if(!root) return root;

    if(val > root->val){
        root->right = deleteNode(root->right, val);
    }else if(val < root->val){
        root->left = deleteNode(root->left, val);
    }else{
        if(!root->right){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }else if(!root->left){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        TreeNode* temp = findMin(root->right);
        root->val = temp->val;

        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}




int main()
{   
    vector<int> nums = {4,2,7,1,3};
    TreeNode* root = createBinarySearchTree(nums);
    printLevelOrder(root);

    auto result = rightSideView(root);
    
    cout << "done testing" << endl;
    return 0;
}
