#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    ifstream fin("input.txt");
    string s; long long v = 0;
    vector<long long> a;
    while(getline(fin, s)) {
        if(s.size() == 0) {
            a.push_back(v);
            v = 0;
        }
        else {
            long long q = stoll(s);
            v += q;
        }
    }
    a.push_back(v);
    sort(a.begin(), a.end());
    cout << a[0] + a[1] + a[2] << '\n';
    return 0;
}
