#include <iostream>

using namespace std;

int main(){
    long long x, e = 0;

    while(cin >> x){
        e ^= x;
    }

    cout << e;
}
