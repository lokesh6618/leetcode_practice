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

int solver(TreeNode* root, int count, string curr_node){
    if(!root) return count - 1;

    if(curr_node == "left"){
        if(root->right){
            solver(root->right, count + 1, "right");
        }else{
            solver(root->left, 1, "left");
        }

    }else if(curr_node == "right"){
        if(root->left){
            solver(root->left, count + 1, "left");
        }else{
            solver(root->right, 1, "right");
        }
    }else{
        return max(solver(root->right, 1, "right"), solver(root->left, 1, "left"));
    }
}

int longestZigZag(TreeNode* root) {
    if(!root) return 0;

    int count = 0;

    vector<pair<TreeNode*, string>> all_nodes;
    all_nodes.push_back(make_pair(root, ""));
    vector<int> results;

    while(!all_nodes.empty()){
        auto current_node = all_nodes.back();
        all_nodes.pop_back();

        count = max(count, solver(current_node.first, 0, current_node.second));

        results.push_back(count);

        if(current_node.first->left) all_nodes.push_back(make_pair(root->left, "left"));
        if(current_node.first->right) all_nodes.push_back(make_pair(root->right, "right"));
    }

    for(auto i : results){
        cout << i << " , ";
    }

    cout << endl;

    return count;
}


int main()
{   
    vector<int> nums = {10,5,-3,3,2,-1,11,3,-2,-1,1};
    TreeNode* root = createBinaryTree(nums);
    printLevelOrder(root);

    int result = longestZigZag(root);
    
    cout << "done testing" << endl;
    return 0;
}
