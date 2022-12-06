#include <bits/stdc++.h>
using namespace std;

int f[2][1001], val[1001];

ifstream fin("input.txt");

void calc() {
    val['a'] = 1;
    for(char i='b'; i<='z'; i++) {
        val[i] = val[i-1]+1;
    }
    val['A'] = val['z'] + 1;
    for(char i='B'; i<='Z'; i++) {
        val[i] = val[i-1]+1;
    }
}

void part1() {
    string x; 
            long long score = 0;
    calc();
    while(fin >> x) {
        int f1[1001] = {0}, f2[1001] = {0};
        int n = x.length();
        for(int i=0; i<n; i++) {
            if(i < n/2)
                f1[x[i]]++;
            else
                f2[x[i]]++;
        }
        for(char i='A'; i<='Z'; i++)
            if(f1[i] != 0 && f2[i] != 0)
                score += val[i];
        for(char i='a'; i<='z'; i++)
            if(f1[i] != 0 && f2[i] != 0)
                score += val[i];
    }
    cout << score << '\n';
}

void part2() {
    string s1, s2, s3;
    calc();
    long long score = 0;
    while(fin >> s1 >> s2 >> s3) {
        bool b1[201] = {0}, b2[201] = {0}, b3[201] = {0};
        for(int i=0; i<s1.length(); i++)
            b1[s1[i]] = 1;
        for(int i=0; i<s2.length(); i++)
            b2[s2[i]] = 1;
        for(int i=0; i<s3.length(); i++)
            b3[s3[i]] = 1;
        for(char c = 'A'; c <= 'z'; c++) {
            if(b1[c] && b2[c] && b3[c])
                score += val[c];
        }
    }
    cout << score << '\n';
}

int main(int argc, char const *argv[]) {
    part2();
    return 0;
}
