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

int goodNodes(TreeNode* root) {
}

void helper(TreeNode* root, int last, vector<int>& good_nodes){
    if(!root) return;

    if(root->val >= last){
        good_nodes.push_back(root->val);
    }

    helper(root->left, root->val, good_nodes);
    helper(root->right, root->val, good_nodes);
}

int helperStack(TreeNode* root){
    queue<TreeNode*> all_nodes;

    all_nodes.push(root);
    TreeNode* previous = nullptr;

    int count = 0;

    while(!all_nodes.empty()){
        if(!previous){
            previous = root;
        }

        auto current_node = all_nodes.front();
        all_nodes.pop();

        if(current_node->left) all_nodes.push(current_node->left);
        if(current_node->right) all_nodes.push(current_node->right);
        
        if(current_node->val >= previous){
            count++;
        }
    }

    return count;
}

int main()
{   
    vector<int> nums = {3,1,4,3,-1,1,5};
    TreeNode* root = createBinaryTree(nums);
    printLevelOrder(root);
    
    vector<int> good_nodes;
    helper(root, 0, good_nodes);

    for(auto item : good_nodes){
        cout << item << " , ";
    }

    cout << endl;

    cout << good_nodes.size() << endl;
    cout << "done testing" << endl;
    return 0;
}
