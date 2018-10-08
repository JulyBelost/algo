#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int make_int(const pair<int, int> &c_i, int rank){
  return (c_i.second * rank) + c_i.first;
}

void counting_sort(vector <pair <int, int> > &c, int rank, int q){
  int l = c.size();
  vector <pair <int, int> > c_c;
  c_c = c;
  vector<int> cnt(rank);

  for(int i = 0; i < l; ++i){
    if(q == 0){
      ++cnt[c[i].first];
    } else {
      ++cnt[c[i].second];
    }
  }

  for(int j = 1; j < rank; ++j){
    cnt[j] += cnt[j - 1];
  }

  for(int i = l - 1; i >= 0; --i){
    if(q == 0){
      --cnt[c_c[i].first];
      c[cnt[c_c[i].first]] = c_c[i];
    } else {
      --cnt[c_c[i].second];
      c[cnt[c_c[i].second]] = c_c[i];
    }
  }
}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);
  vector <pair <int, int> > c;
  c.reserve(n * m);

  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  for(int i = 0; i < m; ++i){
    cin >> b[i];
  }

  int rank = 100000;
  for(int j = 0; j < n; ++j){
    for(int k = 0; k < m; ++k){
      int c_i = a[j] * b[k];
      c.push_back(make_pair(c_i % rank, c_i / rank));
    }
  }

  for(int q = 0; q < 2; ++q){
    counting_sort(c, rank, q);
  }

  long long res = 0;
  for(int i = 0; i < c.size(); i += 10){
    res += make_int(c[i], rank);
  }

  cout << res;
}
