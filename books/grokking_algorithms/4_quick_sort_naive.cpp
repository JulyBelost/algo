#include <iostream>
#include <vector>

using namespace std;

vector<int> quick_sort(const vector<int> & a) {
    if(a.size() < 2) {
        return a;
    } else {
        int pivot = a[0];
        vector<int> less, greater;
        for(int i = 1; i < a.size(); ++i){
            if(a[i] <= pivot) {
                less.push_back(a[i]);
            } else {
                greater.push_back(a[i]);
            }
        }
        less = quick_sort(less);
        greater = quick_sort(greater);
        less.push_back(pivot);
        less.insert(less.end(), greater.begin(), greater.end());
        return less;
    }
}

int main() {
    vector<int> arr{10, 5, 1, 6, 5, 2, 3};
    vector<int> new_arr;

    new_arr = quick_sort(arr);

    copy(
      new_arr.begin(),
      new_arr.end(),
      ostream_iterator<int>(std::cout, " ")
    );
}
