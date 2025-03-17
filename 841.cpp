#include <bits/stdc++.h>

using namespace std;

class Graph {
public:
    void addNode(int value) {
        if (adjList.find(value) == adjList.end()) {
            adjList[value] = {};
        }
    }

    void addEdge(int from, int to, bool isDirected = false) {
        adjList[from].push_back(to);
        if (!isDirected) {
            adjList[to].push_back(from);
        }
    }

    void fillGraph(const std::vector<std::vector<int>>& paths) {
        for (size_t i = 0; i < paths.size(); ++i) {
            addNode(i);
            for (int neighbor : paths[i]) {
                addEdge(i, neighbor, true);
            }
        }

        isVisited.assign(paths.size(), 0);
    }

    void printGraph() const {
        for (const auto& pair : adjList) {
            std::cout << pair.first << " -> ";
            for (int neighbor : pair.second) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    vector<int> getVisitStatus(){
    	return isVisited;
    }

    void dfs(){
    	int start_node = 0;
    	queue<int> visit;

    	vector<int> children = adjList[0];

    	isVisited[0] = 1;
    	
    	for(int i = 0; i < children.size(); i++){
    		visit.push(children[i]);
    	}

    	while(!visit.empty()){

    		int current_size = visit.size();

    		for(int i = 0; i < current_size; i++){
    			int current_node = visit.front();
    			visit.pop();

    			if(isVisited[current_node] == 1) continue;

				isVisited[current_node] = 1;

				children = adjList[current_node];

				for(int i = 0; i < children.size(); i++){
		    		visit.push(children[i]);
		    	}
    		}
    	}
    }

    bool allVisited(){
    	for(auto node : isVisited){
    		if(node == 0) return false;
    	}

    	return true;
    }

private:
    std::unordered_map<int, std::vector<int>> adjList;
    vector<int> isVisited;
};

int main() {
    Graph g;
    std::vector<std::vector<int>> paths = {{1,3},{3,0,1},{2},{0}};
    g.fillGraph(paths);
    g.printGraph();

    for(auto status : g.getVisitStatus()){
    	cout << status << " , ";
    }

    cout << endl;

    g.dfs();

    cout << " after " << endl;

    for(auto status : g.getVisitStatus()){
    	cout << status << " , ";
    }

    cout << endl;

    return 0;
}