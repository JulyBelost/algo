 //https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
#include <iostream>
#include <vector>

using namespace std;

// Complete the activityNotifications function below.
int activityNotifications(vector<int> exp, int d) {
    int cnt = 0;
    multiset<int, greater<int> > mins;
    multiset<int> maxs;
    vector<int> d_vec;

    for(int i = 0; i < d; ++i) {
        d_vec.push_back(exp[i]);
    }

    sort(d_vec.begin(), d_vec.end());

    for(int i = 0; i < d / 2 + d % 2; ++i) {
        mins.insert(d_vec[i]);
        maxs.insert(d_vec[d-i-1]);
    }

    for(int i = d; i < exp.size(); ++i) {
        int med2 = (*mins.begin() + *maxs.begin());

        if(exp[i] >= med2){
            cnt++;
        }

        if(d % 2 == 1){
            maxs.erase(maxs.begin());
        }

        if(exp[i-d] <= *mins.begin() && exp[i] <= *maxs.begin()) {
            mins.erase(mins.find(exp[i-d]));
            mins.insert(exp[i]);
        } else if(exp[i-d] >= *maxs.begin() && exp[i] >= *mins.begin()) {
            maxs.erase(maxs.find(exp[i-d]));
            maxs.insert(exp[i]);
        } else if(exp[i-d] <= *mins.begin()) {
            mins.erase(mins.find(exp[i-d]));
            maxs.insert(exp[i]);
            mins.insert(*maxs.begin());
            maxs.erase(maxs.begin());
        } else {
            maxs.erase(maxs.find(exp[i-d]));
            mins.insert(exp[i]);
            maxs.insert(*mins.begin());
            mins.erase(mins.begin());
        }

        if(d % 2 == 1){
            maxs.insert(*mins.begin());
        }
    }

    return cnt;
}

int main()
{
    int n, d;
    cin >> n >> d;

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        cin >> expenditure[i];
    }

    int result = activityNotifications(expenditure, d);

    cout << result << "\n";

    return 0;
}
