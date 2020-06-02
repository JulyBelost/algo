//https://www.hackerrank.com/challenges/angry-children/problem
#include <vector>
#include <iostream>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int unf_min = arr[arr.size() - 1] - arr[0];
    for(int i = 0; i + k - 1 < arr.size(); ++i){
        unf_min = min(unf_min, arr[i + k - 1] - arr[i]);
    }

    return unf_min;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    cout << result << "\n";

    return 0;
}
