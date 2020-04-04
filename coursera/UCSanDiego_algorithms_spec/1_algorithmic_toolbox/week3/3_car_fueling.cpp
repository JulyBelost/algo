#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    stops.push_back(dist);
    int n  = stops.size();
    int i = 0, res = 0, p = 0;

    while(p < dist) {
        if(stops[i] - p > tank) {
            return -1;
        }

        while(stops[i] - p <= tank && i < n) {
            ++i;
        }

        p = stops[i - 1];
        ++res;
    }

    return res - 1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
