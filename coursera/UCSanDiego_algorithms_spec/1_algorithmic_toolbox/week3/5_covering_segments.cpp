#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
    int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
    int n = segments.size();
    vector<int> points;
    vector<pair<int, int> > rights;
    vector<pair<int, int> > lefts;

    for (int i = 0; i < n; ++i) {
        rights.push_back(make_pair(segments[i].end, segments[i].start));
    }
    sort(rights.begin(), rights.end());

    for (int i = 0; i < n; ++i) {
        lefts.push_back(make_pair(rights[i].second, i));
    }
    sort(lefts.begin(), lefts.end());

    for (int i = 0, j = 0; i < n && j < n; ++i) {
        if(rights[i].second == -1) {
            continue;
        }

        points.push_back(rights[i].first);

        while(j < n && rights[i].first >= lefts[j].first) {
            rights[lefts[j].second].second = -1;
            ++j;
        }
    }

    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
    }
}
