#include "geom.hpp"

P2di::P2di(long x, long y): x(x),y(y){}


void P2di::add(long xa, long ya){
    x += xa;
    y += ya;
}

P2di P2di::operator+=(const P2di &p){
    add(p.x,p.y);
    return *this;
}

P2di P2di::operator+(P2di p){
    return p += *this;
}