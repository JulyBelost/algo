#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class JobQueue {
 private:
    int num_workers_;
    vector<int> jobs_;

    vector<int> assigned_workers_;
    vector<long long> start_times_;
    vector<pair<long long, int> > next_thread;


    void WriteResponse() const {
        for (int i = 0; i < jobs_.size(); ++i) {
          cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
        }
    }

    void ReadData() {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        for(int i = 0; i < m; ++i)
          cin >> jobs_[i];
    }

    void AssignJobs() {
        assigned_workers_.resize(jobs_.size());
        start_times_.resize(jobs_.size());
        next_thread.resize(num_workers_);

        for(int i = 0; i < num_workers_; ++i) {
            next_thread[i] = make_pair(0, i);
        }

        for (int i = 0; i < jobs_.size(); ++i) {
            pair<long long, int> thr = ExtractHead();
            assigned_workers_[i] = thr.second;
            start_times_[i] = thr.first;

            next_thread[num_workers_ - 1] = make_pair(thr.first + jobs_[i], thr.second);
            SiftLastUp();

        }
    }

    pair<long long, int> ExtractHead() {
        swap(next_thread[0], next_thread[num_workers_ - 1]);

        int k = 0;
        while (k < num_workers_ - 1) {
            int min_ind = k;
            if(k+k+1 < num_workers_ - 1) {
                min_ind = next_thread[k] <= next_thread[k+k+1] ? k : k+k+1;
                if(k+k+1 < num_workers_) {
                  min_ind = next_thread[min_ind] <= next_thread[k+k+2] ? min_ind : k+k+2;
                }
            }
            if (k != min_ind) {
                swap(next_thread[k], next_thread[min_ind]);
                k = min_ind;
            } else {
                break;
            }
        }

        return next_thread[num_workers_ - 1];
    }

    void SiftLastUp() {
        int k = num_workers_ - 1;
        while (next_thread[(k - 1) / 2] > next_thread[k]) {
          swap(next_thread[(k - 1) / 2], next_thread[k]);
          k = (k - 1) / 2;
        }
    }

 public:
    void Solve() {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}
