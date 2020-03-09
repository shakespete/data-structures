//
//  main.cpp
//  Union Find Disjoint Set
//
//  Created by Jose Mari Prim Syjuco on 3/9/20.
//  Copyright © 2020 Jose Mari Prim Syjuco. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class DisjointSet {
public:
    DisjointSet(int n);
    int findSet(int i);
    bool isSameSet(int i, int j);
    void join(int i, int j);
    int* p;
    int* rank;
};
DisjointSet::DisjointSet(int n) {
    p = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; i++) p[i] = i;
}
int DisjointSet::findSet(int i) {
    return p[i] == i ? i : (p[i] = findSet(p[i]));
}
bool DisjointSet::isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}
void DisjointSet::join(int i, int j) {
    int x = findSet(i);
    int y = findSet(j);

    if (x != y) {
        if (rank[x] > rank[y]) {
            p[y] = x;
        }
        else {
            p[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
}

DisjointSet* ds;

int main() {
    //freopen("input.txt", "r", stdin);

    int T, N, Q;
    char x;
    int y, z;

    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        scanf("%d %d", &N, &Q);
        ds = new DisjointSet(N + 10);

        int yes = 0;
        int no = 0;
        for (int i = 0; i < Q; ++i) {
            scanf(" %c %d %d", &x, &y, &z);

            if (x == 'c') ds->join(y, z);
            else ds->isSameSet(y, z) ? yes++ : no++;
        }
        printf("Case #%d: %d,%d\n", test_case, yes, no);
    }

    return 0;
}
