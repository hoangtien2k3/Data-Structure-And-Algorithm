
#include<bits/stdc++.h>
using namespace std;

int differentSquares(vector<vector<int>> matrix)
{
    set<vector<int>> a;
    for(int i = 0; i < matrix.size() - 1; i++) {
        for(int j = 0; j < matrix[0].size() - 1; j++) { // matrix[0].size() - 1 lấy ra số cột là 2 (vì vector)
            vector<int> b = {matrix[i][j], matrix[i][j + 1], matrix[i + 1][j], matrix[i + 1][j + 1]};
            a.insert(b);
        }
    }
    return a.size();
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 1}, {2, 2, 2}, {2, 2, 2}, {1, 2, 3}, {2, 2, 1}};
    cout << differentSquares(matrix);
    return 0;
}