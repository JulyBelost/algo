#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
     int capacity_;
     vector<int> data_;
     vector< pair<int, int> > swaps_;

     void WriteResponse() const {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

    void ReadData() {
        int n;
        cin >> n;
        data_.resize(n);
        for(int i = 0; i < n; ++i){
            cin >> data_[i];
        }
    }

    void CountCapacity() {
        int d = data_.size(), c = 1;
        while(d > 1) {
            ++c;
            d >>= 1;
        }
        capacity_ = 1 << c;
    }

    void GenerateSwaps() {
        swaps_.clear();

        int n = (capacity_ - 1) / 2;

        for (int i = n; i >= 0; --i){
            SiftDown(i);
        }

    }

    void SiftDown(int i) {
            int ind = i;
            int ch = (i + 1) * 2;

            if (ch - 1 < data_.size() && data_[ind] > data_[ch - 1]) {
                ind  = ch - 1;
            }
            if (ch < data_.size() && data_[ind] > data_[ch]) {
                ind  = ch;
            }
            if(ind != i){
                swap(data_[i], data_[ind]);
                swaps_.push_back(make_pair(i, ind));
                SiftDown(ind);
            }
    }

 public:
    void Solve() {
        ReadData();
        CountCapacity();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
