#include <bits/stdc++.h>
using namespace std;

vector <int> a, b, c;

void init() {
    int n;
    a.resize(n, -1);
    b.resize(n, 0);
    c.resize(n, numeric_limits<int>::max());
    // numeric_litmits<int>::max()为编译器支持的int类型的最大数据
}

int main() {
    vector <int> tmp = {1, 2, 3, 4, 5}; //c++98应该不支持{...}声明
    for (int i = 0; i < 10; i++) {
        tmp.push_back(i);
    }
    
    // vector可以用以下这三种方式遍历
    vector <int>::iterator it;
    for (it = tmp.begin(); it != tmp.end(); it++) {
        cerr << *it << ' ';
    }
    cerr << '\n';
    
    for (int i = 0; i < tmp.size(); i++) { // 使用小于号的原因：c++大部分容器都是左闭右开的
        cerr << a[i] << ' ';
    }
    cerr << '\n';
    
    for (auto it : tmp) {
        cerr << tmp[it] << ' ';
    }
    cerr << '\n';
    
    vector <int> arr(10, -1); // initialize an array of 10 -1
    arr.resize(5, 0); // resize the vector
    cout << arr.size() << ' ' << typeid(arr.size()).name() << endl;
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << ' ';
    }

    /* arr.erase(arr.begin() + 3, arr.end()); delete all the element after the third element */
    sort (arr.begin(), arr.end());
    cerr << (int)(unique(arr.begin(), arr.end())-arr.begin()) << '\n';
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return 0;
}
