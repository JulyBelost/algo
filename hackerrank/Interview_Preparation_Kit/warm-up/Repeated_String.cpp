//https://www.hackerrank.com/challenges/repeated-string/problem
#include <vector>
#include <iostream>
#include <unordered_set>

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long rep = n / s.size();
    int rest = n % s.size();
    int rest_a = 0;
    int cnt = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'a'){
            cnt++;
            if(i < rest){
                rest_a++;
            }
        }
    }

    return cnt * rep + rest_a;
}

int main()
{
    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    cout << result << "\n";

    return 0;
}
