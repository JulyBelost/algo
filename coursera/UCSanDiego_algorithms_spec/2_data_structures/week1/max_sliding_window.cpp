#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::deque;

void max_sliding_window(vector<int> const & a, int m) {
    deque<int> max;

    for(int i = 0; i < a.size(); ++i) {
        while(max.size() > 0 && max.back() < a[i]){
            max.pop_back();
        }

        max.push_back(a[i]);

        if(i < m - 1) {
            continue;
        }
        cout << max.front() << " ";

        if(max.front() == a[i - m + 1]) {
            max.pop_front();
        }

    }
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> a(n);
    for (size_t i = 0; i < n; ++i)
        cin >> a.at(i);

    int m = 0;
    cin >> m;

    max_sliding_window(a, m);

    return 0;
}
