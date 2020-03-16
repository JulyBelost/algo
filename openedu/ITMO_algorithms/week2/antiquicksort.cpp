// Анти-quick sort
// Ограничение по времени: 	2 секунды
// Ограничение по памяти: 	256 мегабайт
//
// Для сортировки последовательности чисел широко используется быстрая сортировка
// — QuickSort. Далее приведен алгоритм.
//
// var a : array [1..N] of integer;
//
// procedure QSort(left, right : integer);
// var i, j, key, buf : integer;
// begin
//    key := a[(left + right) div 2];
//    i := left;
//    j := right;
//    repeat
//        while a[i] < key do
//            inc(i);
//        while key < a[j] do
//            dec(j);
//        if i <= j then begin
//            buf := a[i];
//            a[i] := a[j];
//            a[j] := buf;
//            inc(i);
//            dec(j);
//        end;
//    until i > j;
//    if left < j then QSort(left, j);
//    if i < right then QSort(i, right);
// end;
// begin
//    ...
//    QSort(1, N);
// end.
//
// Хотя QuickSort является очень быстрой сортировкой в среднем, существуют тесты,
// на которых она работает очень долго. Оценивать время работы алгоритма будем
// числом сравнений с элементами массива (суммарным числом сравнений в 1 и 2 while)
// Требуется написать программу, генерирующую тест, на котором быстрая сортировка
// сделает наибольшее число таких сравнений.
// Формат входного файла:
// В первой строке находится единственное число n<=10^6
// Формат выходного файла:
// Вывести перестановку чисел от 1 до  n, на которой быстрая сортировка выполнит
// максимальное число сравнений. Если их несколько, вывести любую.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<int> a;

	for (int k=1; k<=n; ++k){
    a.push_back(k);
    int m = a.size() - 1;
    if(k > 2){
      swap(a[m/2], a[m]);
    }
	}

  for (int i=0; i<n; ++i){
 		cout << a[i] << " ";
 	}

}
