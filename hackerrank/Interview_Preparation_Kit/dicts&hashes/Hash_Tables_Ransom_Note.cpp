//https://www.hackerrank.com/challenges/ctci-ransom-note/problem
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    multiset<string> mag;
    for(int i = 0; i < magazine.size(); ++i){
        mag.insert(magazine[i]);
    }
    for(int i = 0; i < note.size(); ++i){
        auto el = mag.find(note[i]);
        if(el == mag.end()){
            cout << "No\n";
            return;
        } else {
            mag.erase(el);
        }
    }
    cout << "Yes\n";
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        cin >> magazine[i];
    }

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        cin >> note[i];
    }

    checkMagazine(magazine, note);

    return 0;
}
