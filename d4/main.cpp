#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> d) {
    int n = d.size(), a = 0;
    int Q[1001], L = 0;
    for(size_t i=0; i<n; i++) {
        char ranges[d[i].length()+1];
        strcpy(ranges, d[i].c_str());
        char *t = strtok(ranges, "-");
        while(t) {
            //cout << t << '\n';
            Q[++L] = atoi(t);
            t = strtok(NULL, "-");
        }
        if((i+1)%2 == 0) {
            if((Q[2] >= Q[3] && Q[1] <= Q[4]) || (Q[3] >= Q[2] && Q[4] <= Q[1])) {
                a++;
                cout << Q[1] << ' ' << Q[2] << ' ' << Q[3] << ' ' << Q[4] << '\n';
            }
            L = 0;
        }
    }
    return a;
}

int main(int argc, char const *argv[]) {
    char s[201];
    ifstream fin("input.txt");
    vector<string> v;
    while(fin.getline(s, 201)) {
        char *p1 = strtok(s, ","); 
        while(p1) {
            v.push_back(string(p1));
            p1 = strtok(NULL, ",");
        }
    }
    int ans = solve(v);
    cout << ans << '\n';
    return 0;
}
