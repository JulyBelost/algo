//https://www.hackerrank.com/challenges/counting-valleys/problem
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int level = 0;
    int place = 0;
    int cnt = 0;
    for(int i = 0; i < s.size(); ++i){
        if(level == 0 && s[i] == 'D'){
            place = 1;
            level--;
        } else if(level == -1 && s[i] == 'U') {
            cnt++;
            level++;
            place = 0;
        } else {
            s[i] == 'U' ? level++ : level --;
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    cout << result << "\n";

    return 0;
}
