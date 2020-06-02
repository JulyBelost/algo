#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {
    int part = 0;
    int cnt = 0;
    for(int i = 0; i < c.size(); ++i){
        if(c[i] == 0){
            part++;
        } else {
            cnt += part/2 + 1;
            part = 0;
        }
    }
    cnt += part/2;
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int result = jumpingOnClouds(c);

    cout << result << "\n";

    return 0;
}
