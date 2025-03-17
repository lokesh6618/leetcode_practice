#include <bits/stdc++.h>

using namespace std;

void printGraph(const std::unordered_map<int, std::vector<int>>& graph) {
    for (const auto& pair : graph) {
        std::cout << pair.first << " -> ";
        for (const auto& neighbor : pair.second) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}


bool pathExists(int a, int b, const std::unordered_map<int, std::vector<int>>& graph) {
    if (graph.find(a) == graph.end()) return false;

    return std::find(graph.at(a).begin(), graph.at(a).end(), b) != graph.at(a).end();
}

int minReorder(int n, vector<vector<int>>& connections) {
    unordered_map<int, unordered_set<int>> temp_graph;
    unordered_map<int, vector<int>> orignal_graph;
    unordered_map<int, vector<int>> final_graph;

    int count = 0;

    for(auto edge : connections){
        orignal_graph[edge[0]].push_back(edge[1]);
        temp_graph[edge[0]].insert(edge[1]);
        temp_graph[edge[1]].insert(edge[0]);
    }

    int nodes = temp_graph.size();

    vector<int> is_visited(nodes, 0);

    queue<int> solve_node;
    solve_node.push(0);

    while(!solve_node.empty()){
        auto current_node = solve_node.front();
        solve_node.pop();

        if(is_visited[current_node] == 1) continue;
        is_visited[current_node] = 1;

        for(auto neighbor : temp_graph[current_node]){
            if(is_visited[neighbor] == 1) continue;
            // final_graph[neighbor].push_back(current_node);
            solve_node.push(neighbor);

            if(!pathExists(neighbor, current_node, orignal_graph)) count++;
        }
    }

    return count;
}

int main()
{   
    vector<vector<int>> nums = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    int n = 6;

    cout << minReorder(6, nums) << endl;
    cout << "done testing" << endl;
    return 0;
}
