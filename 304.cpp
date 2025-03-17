#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
    vector<vector<int>> preSums;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        // vector<int> first_row(matrix[0].size(), 0);
        // this->preSums.push_back(first_row);

        // cout << "--------start constructing marix " << endl;

        // for(int i = 0; i < matrix.size(); i++){
        //     vector<int> temp_row;

        //     for(int j = 0; j < matrix[0].size(); j++){
        //         temp_row.push_back(this->preSums[i][j] + matrix[i][j]);
        //     }

        //     this->preSums.push_back(temp_row);
        // }

        int m = matrix.size(), n = matrix[0].size();
        preSums = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                preSums[i][j] = matrix[i-1][j-1] 
                             + preSums[i-1][j] 
                             + preSums[i][j-1] 
                             - preSums[i-1][j-1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        for(int i = col1; i <= col2; i++){
            cout << this->preSums[row2+1][i] << " , " << preSums[row1][i] << endl;
            sum += this->preSums[row2+1][i] - this->preSums[row1][i];
        }

        cout << endl;

        return sum;
    }

    void printMat(){
        for(int i = 0; i < this->preSums.size(); i++){
            for(int j = 0; j < this->preSums[0].size(); j++){
                cout << preSums[i][j] << " , ";
            }
            cout << endl;
        }

        cout << endl;
    }
};

int main()
{   
    vector<vector<int>> mat = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    int row1 = 1;
    int col1 = 2;
    int row2 = 2;
    int col2 = 4;

    NumMatrix mat_1(mat);

    mat_1.printMat();

    int result = 0;

    // cout << mat_1.sumRegion(row1, col1, row2, col2) << endl;

    cout << "done testing" << endl;
    return 0;
}

