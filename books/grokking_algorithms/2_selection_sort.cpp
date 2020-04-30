#include <iostream>
#include <vector>

using namespace std;

int find_smallest(vector<int> & arr) {
    int smallest = arr[0];
    int smallest_index = 0;

    for(int i = 1; i < arr.size(); ++i) {
        if (arr[i] < smallest) {
            smallest =  arr[i];
            smallest_index = i;
        }
    }

    return smallest_index;
}

void selection_sort(vector<int> & arr, vector<int> & new_arr) {
    int smallest;
    int n = arr.size();

    for(int i = 0; i < n; ++i) {
        smallest = find_smallest(arr);
        new_arr.push_back(arr[smallest]);
        arr.erase(arr.begin() + smallest);
    }

    return;
}

int main() {
    vector<int> arr{5,3,6,2,10};
    vector<int> new_arr;

    selection_sort(arr, new_arr);

    for(int i = 0; i < new_arr.size(); ++i) {
        cout << new_arr[i] << " ";
    }
    cout << "\n";
}
