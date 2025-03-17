#include <bits/stdc++.h>

using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    unordered_map<string, int> cols, rows;
    int count = 0;

    int n = grid.size();

    for(int i = 0; i < n; i++){
        string current = "";

        for(int j = 0; j < n; j++){
            current += to_string(grid[i][j]);
            current += ",";
        }

        rows[current]++;
    }

    for(int i = 0; i < n; i++){
        string current = "";

        for(int j = 0; j < n; j++){
            current += to_string(grid[j][i]);
            current += ",";
        }

        cols[current]++;
    }

    for(auto item : rows){
        auto current_item = cols.find(item.first);

        if(current_item != cols.end()){
            count += current_item->second*item.second;
        }
    }

    cout << "rows --------------- " << endl;

    for(auto item : rows){
        cout << item.first << endl;
    }

    cout << endl;

    cout << "cols --------------- " << endl;

    for(auto item : cols){
        cout << item.first << endl;
    }

    cout << endl;

    return count;
}

int main()
{   
    vector<vector<int>> grid = {{3,1,2,2}, {1,4,4,5}, {2,4,2,2}, {2,4,2,2}};

    auto result = equalPairs(grid);

    cout << result << endl;
    cout << "done testing" << endl;
    
    return 0;
}