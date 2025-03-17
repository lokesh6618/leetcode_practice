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

TreeNode* createBinaryTree(const vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < values.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < values.size() && values[i] != -1) {
            curr->left = new TreeNode(values[i]);
            q.push(curr->left);
        }
        i++;

        if (i < values.size() && values[i] != -1) {
            curr->right = new TreeNode(values[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

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

void getLeafs(TreeNode* root, vector<int>& leafs){
    if(!root) return;

    if(!root->left && !root->right){
        leafs.push_back(root->val);
    }

    getLeafs(root->left, leafs);
    getLeafs(root->right, leafs);
}

int main()
{   
    vector<int> nums = {3,5,1,6,2,9,8,-1,-1,7,4};
    TreeNode* root = createBinaryTree(nums);
    printLevelOrder(root);
    
    vector<int> leafs;
    getLeafs(root, leafs);

    for(auto item : leafs){
        cout << item << " , ";
    }

    cout << endl;
    cout << "done testing" << endl;
    return 0;
}
