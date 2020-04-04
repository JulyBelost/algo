#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    int n = values.size();
    vector<pair<double, int> > per_value(n);

    for(int i = 0; i < n; ++i) {
        per_value[i] = make_pair(values[i] / (double) weights[i], i);
    }

    sort(per_value.begin(), per_value.end());

    int j = n - 1;
    while(capacity > 0 && j >= 0){
        value += (capacity >= weights[per_value[j].second] ?  values[per_value[j].second] :
            per_value[j].first * capacity);
        capacity -= weights[per_value[j].second];
        --j;
    }

    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
