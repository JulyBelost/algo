//https://www.hackerrank.com/challenges/two-strings/problem
#include <iostream>
#include <vector>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    vector<int> a1(26, 0);
    vector<int> a2(26, 0);

    for(int i = 0; i < s1.size(); ++i){
        a1[s1[i] - 'a']++;
    }
    for(int i = 0; i < s2.size(); ++i){
        a2[s2[i] - 'a']++;
    }
    for(int i = 0; i < 26; ++i){
        if(a1[i] != 0  && a2[i] != 0){
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        cout << result << "\n";
    }

    return 0;
}
