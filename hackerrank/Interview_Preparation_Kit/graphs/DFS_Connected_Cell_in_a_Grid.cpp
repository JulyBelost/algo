//https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/problem
#include <iostream>
#include <vector>

using namespace std;

int findRegion(const vector<vector<int>> & grid, vector<vector<int>> & been, int i, int j){
    been[i][j] = 1;

    int n = grid.size();
    int m = grid[0].size();
    int dx[8] = {1, 0, -1,  0, 1, -1,  1, -1};
    int dy[8] = {0, 1,  0, -1, 1,  1, -1, -1};
    int size = 1;

    for(int k = 0; k < 8; ++k){
        int x = i + dx[k];
        int y = j + dy[k];
        if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1 && been[x][y] == 0){
            size += findRegion(grid, been, x, y);
        }
    }

    return size;
}

int maxRegion(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> been(n, vector<int>(m, 0));

    int mx = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 1){
                mx = max(mx, findRegion(grid, been, i, j));
            }
        }
    }

    return mx;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    cout << res << "\n";

    return 0;
}
