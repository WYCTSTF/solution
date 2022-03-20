#include <iostream>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n%4==1) cout << "1";
        if (n%4==2) cout << "0001";
        if (n%4==3) cout << "01";
        for (int i = 1; i <= n / 4; i++) cout << "1001";
        cout << endl;
    }
}