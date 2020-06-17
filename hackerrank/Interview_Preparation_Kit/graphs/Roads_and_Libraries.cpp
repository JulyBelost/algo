//https://www.hackerrank.com/challenges/torque-and-development/problem
#include <iostream>
#include <vector>

using namespace std;

int findParent(vector<int> & sets, int city){
    if(sets[city] == city){
        return city;
    }
    sets[city] = findParent(sets, sets[city]);
    return sets[city];
}

void mergeSets(vector<int> & sets, vector<int> & rank, int city, int city2){
    int p1 = findParent(sets, city);
    int p2 = findParent(sets, city2);
    if(rank[p1] > rank[p2]){
        sets[p2] = p1;
    } else {
        sets[p2] = p1;
        if(rank[p1] == rank[p2]){
            ++rank[p2];
        }
    }
}

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if(c_lib <= c_road) {
        return (long long)n * c_lib;
    }
    vector<int> sets(n + 1);
    vector<int> rank(n + 1);
    long rds = 0;
    long set_cnt = n;

    for(int i = 1; i <= n; ++i){
        sets[i] = i;
        rank[i] = 0;
    }

    for(int i = 0; i < cities.size(); ++i){
        if(findParent(sets, cities[i][0]) != findParent(sets, cities[i][1])){
            ++rds;
            --set_cnt;
            mergeSets(sets, rank, cities[i][0], cities[i][1]);
        }
    }

    return rds * c_road + set_cnt * c_lib;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n, m, c_lib, c_road;
        cin >> n >> m >> c_lib >> c_road;

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        cout << result << "\n";
    }

    return 0;
}
