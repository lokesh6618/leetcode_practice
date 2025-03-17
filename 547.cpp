#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> generateGraph(vector<vector<int>>& isConnected){
    unordered_map<int, vector<int>> graph;

    int n = isConnected.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isConnected[i][j] == 1){
                graph[i].push_back(j);
            }
        }
    }

    return graph;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();

    vector<int> isVisited(n, 0);
    auto graph = generateGraph(isConnected);

    int count = 0;

    for(int i = 0; i < n; i++){
        if(isVisited[i] == 1) continue;
        count++;


        queue<int> visit;
        isVisited[i] = 1;
        visit.push(i);

        while(!visit.empty()){
            auto current_node = visit.front();
            visit.pop();

            for(auto neighbor : graph[current_node]){
                if(isVisited[neighbor] == 0){
                    isVisited[neighbor] = 1;
                    visit.push(neighbor);
                }
            }
        }
    }

    return count;
}

int main()
{   
    vector<vector<int>> nums = {{1,1,0},{1,1,0},{0,0,1}};

    cout << findCircleNum(nums) << endl;
    cout << "done testing" << endl;
    return 0;
}
