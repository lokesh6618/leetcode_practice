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

vector<int> rightSideView(TreeNode* root) {
    vector<TreeNode*> all_nodes;
    vector<int> all_right;

    if(!root) all_nodes.push_back(root);

    while(!all_nodes.empty()){
        int current_items = all_nodes.size();

        all_right.push_back(all_nodes.back()->val);


        for(int i = 0; i < current_items; i++){
            auto current_node = all_nodes.back();
            all_nodes.pop_back();


            if(current_node->left) all_nodes.push_back(current_node->left);
            if(current_node->right) all_nodes.push_back(current_node->right);
        }
    }

    return all_right;

}




int main()
{   
    vector<int> nums = {1,2,3,4,-1,-1,-1,5};
    TreeNode* root = createBinaryTree(nums);
    printLevelOrder(root);

    auto result = rightSideView(root);
    
    cout << "done testing" << endl;
    return 0;
}
