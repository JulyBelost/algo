// Число инверсий
// Ограничение по времени: 	2 секунды
// Ограничение по памяти: 	256 мегабайт
//
// Дан массив целых чисел. Ваша задача — подсчитать число инверсий в нем.
// Чтобы сделать это быстрее, можно воспользоваться модификацией
// сортировки слиянием.
//
// Формат входного файла:
// В первой строке входного файла содержится число 1<=n<=10^5 — число элементов
// в массиве. Во второй строке находятся n целых чисел, по модулю не
// превосходящих 10^9.
// Формат выходного файла:
// В выходной файл надо вывести число инверсий в массиве.
// Пример
// input.txt              output.txt
// 10
// 1 8 2 1 4 7 3 2 3 6 	  17


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void inv_count(vector<int> &a, long long &inv, int l, int r){
  int n = r - l;
  if(n==1){
    return;
  }
  int ll = l;
  int rl = l + n/2;
  int lr = l + n/2;
  int rr = r;
  inv_count(a, inv, ll, rl);
  inv_count(a, inv, lr, rr);

  vector<int> m;
  int i=ll, j=lr;
  while(i < rl || j < rr){
    if(j == rr || (i < rl && a[i] <= a[j])){
      m.push_back(a[i]);
      ++i;
    } else {
      inv += rl - i;
      m.push_back(a[j]);
      ++j;
    }
  }

  for(int i=l; i<r; ++i){
    a[i] = m[i-l];
  }
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector <int> a(n);

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

  long long inv = 0;
  inv_count(a, inv, 0, a.size());

  cout << inv;
}
