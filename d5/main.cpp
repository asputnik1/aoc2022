#include <bits/stdc++.h>
using namespace std;

char QS[1001][1001];
int LS[1001],n, m, mi = 0;
ifstream fin("inputs.txt");

void afis() {
    for(int i=1; i<=mi; i++) {
        cout << i << " : ";
        for(int j=1; j<=LS[i]; j++)
            cout << QS[i][j] << ' ';
        cout << '\n';
    }
}

void mutare(int q, int from, int to) {
    LS[to] += q;
    for(int i=LS[to]; i>q; i--) {
        QS[to][i] = QS[to][i-q];
    }
    for(int i=1; i<=q; i++) {
        //QS[to][i] = QS[from][q-i+1]; part 1
        QS[to][i] = QS[from][i];
    }
    int i = 1;
    while(i + q <= LS[from]) {
        QS[from][i] = QS[from][i+q];
        i++;
    }
    LS[from] -= q;
}

void parseazaCmd(char l[]) {
    if(sizeof(l)/sizeof(char) < 1) return;
    if(!isalpha(l[0])) return;
    char *t = strtok(l, " ");
    int id = 1, q=0, from=0, to=0;
    while(t) {
        if(id ==2)
            q = atoi(t);
        else if(id ==4)
            from = atoi(t);
        else if(id ==6)
            to = atoi(t);
        id++;
        t = strtok(NULL, " ");
    }
    mutare(q, from, to);
    cout << "------------\n";
    afis();
    cout << "------------\n";
}

int main(int argc, char const *argv[]) {
    char linie[1001];
    bool comenzi = 0;
    while(fin.getline(linie, 1001)) {
        if(sizeof(linie)/sizeof(char) >= 2)
            if(linie[1] >= '1' && linie[1] <= '9')
                comenzi = 1;
        if(!comenzi) {
            int grupe = 0;
            for(int i=0, j=1; linie[i]; i++) {
                j++;
                if(j == 3) {
                    grupe++, j = -1;
                }
                if(linie[i] == '[') {
                    int index = grupe+1;
                    cout << linie[i+1] << ' ' << index << '\n';
                    QS[index][++LS[index]] = linie[i+1];
                    mi = max(mi, index);
                }
            }
        }
        else {
            parseazaCmd(linie);
        }
    }
    return 0;
}
