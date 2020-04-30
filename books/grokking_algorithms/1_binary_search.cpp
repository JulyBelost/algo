#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> list, int item) {
    int low = 0, mid, guess;
    int high = list.size() - 1;

    while(low <= high) {
        mid = (low + high) / 2;
        guess = list[mid];

        if(guess == item) {
            return mid;
        }

        if(guess > item) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    vector<int> v{1,3,5,7,9};

    cout << binary_search(v, 3) << "\n";
    cout << binary_search(v, -1) << "\n";
}
