#include <bits/stdc++.h>
using namespace std;

void part1() {
    ifstream fin("input.txt");
    int wins[3][3] = {
        {1, 0, 2},
        {2, 1, 0},
        {0, 2, 1}
    };
    long long score = 0;
    char p1, p2;
    while(fin >> p1 >> p2) {
        int x1 = p1 - 'A';
        int x2 = p2 - 'X';
        score += x2 + 1 + wins[x2][x1]*3;
    }
    cout << score << '\n';
}

void part2() {
    ifstream fin("input.txt");
    int sup[3] = {1, 2, 0};
    long long score = 0;
    char p1, p2;
    while(fin >> p1 >> p2) {
        int x1 = p1 - 'A';
        int x2 = p2 - 'X';
        score += x2*3 + 1;
        if(x2 == 0) {
            score += 3 - x1 - sup[x1];
        }
        else if(x2 == 1) {
            score += x1;
        }
        else if(x2 == 2) {
            score += sup[x1];
        }
    }
    cout << score << '\n';
}

int main(int argc, char const *argv[]) {
    part2();
    return 0;
}
