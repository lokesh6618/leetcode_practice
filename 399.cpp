#include <bits/stdc++.h>

using namespace std;

void generateGraph(unordered_map<string, unordered_map<string, int>>& graph, vector<vector<string>>& equations, vector<double>& values){
    for(int i = 0; i < equations.size(); i++){
        graph[equations[i][0]][equations[i][1]] = values[i];
        graph[equations[i][1]][equations[i][0]] = 1/values[i];
    }
}

double dfs(unordered_map<string, unordered_map<string, int>>& graph, string start_node, string end_node){

    if(start_node == end_node){
        return 1.0;
    }

    for(auto neighbour : graph){

    }

}

double calFebonacci(int n){
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return 1;
    }

    return calFebonacci(n-1) + calFebonacci(n-2);

}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, int>> graph;

    vector<double> result;

    return result;
}

int main()
{   
    vector<vector<string>> nums = {{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> values = {1.5,2.5,5.0};
    vector<vector<string>> queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};

    cout << "done testing" << endl;
    return 0;
}
