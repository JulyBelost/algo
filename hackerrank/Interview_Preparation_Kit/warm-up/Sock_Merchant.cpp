// https://www.hackerrank.com/challenges/sock-merchant/problem
#include <vector>
#include <iostream>
#include <unordered_set>


using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    unordered_set<int> left;
    int cnt = 0;
    for(int i = 0; i < ar.size(); ++i){
        if(find(left.begin(), left.end(), ar[i]) != left.end()){
            left.erase(ar[i]);
            cnt++;
        } else {
            left.insert(ar[i]);
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int result = sockMerchant(n, ar);

    cout << result << "\n";

    return 0;
}
