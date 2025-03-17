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

void solver(TreeNode* root){

    vector<pair<TreeNode*, string>> all_nodes;
    vector<string> all_paths;

    string curent_path = to_string(root->val) + ",";
    all_nodes.push_back(make_pair(root, curent_path));

    while(!all_nodes.empty()){
        auto current_node = all_nodes.back();
        all_nodes.pop_back();
        all_paths.push_back(current_node.second);

        if(current_node.first->left){
            curent_path = current_node.second + to_string(current_node.first->left->val) + ",";
            all_nodes.push_back(make_pair(current_node.first->left, curent_path));
        }

        if(current_node.first->right){
            curent_path = current_node.second + to_string(current_node.first->right->val) + ",";
            all_nodes.push_back(make_pair(current_node.first->right, curent_path));
        }
    }

    for(auto item : all_paths){
        cout << item << endl;
    }

}

void mainSolver(TreeNode* root){
    unordered_set<string> all_paths;
}


int main()
{   
    vector<int> nums = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* root = createBinaryTree(nums);
    printLevelOrder(root);

    solver(root);
    
    cout << "done testing" << endl;
    return 0;
}
