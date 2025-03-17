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

int helper(TreeNode* root, int currSum, int target, unordered_map<int, int>& preSum){
    if(!root) return 0;

    currSum += root->val;

    int count = preSum[currSum - target];

    preSum[currSum]++;

    if (root->left) count += helper(root->left, currSum, target, preSum);
    if (root->right) count += helper(root->right, currSum, target, preSum);

    return count;
}

int pathSum(TreeNode* root, int targetSum) {
    if(!root) return 0;

    unordered_map<int, int> preSum;
    preSum[0] = 1;

    return helper(root, 0, targetSum, preSum);
}

int main()
{   
    vector<int> nums = {10,5,-3,3,2,-1,11,3,-2,-1,1};
    TreeNode* root = createBinaryTree(nums);
    printLevelOrder(root);

    int targetSum = 8;

    int result = pathSum(root, targetSum);
    
    cout << "done testing" << endl;
    return 0;
}
