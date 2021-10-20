#include <bits/stdc++.h>

struct P2di {
    long x;
    long y;

    P2di(long x, long y);
    void add(long x, long y);

    P2di operator+=(const P2di &p);
    P2di operator+(P2di p);
};