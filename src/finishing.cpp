#include "finishing.h"

Finishing::Finishing() {
}

Finishing::Finishing(float ka, float kd, float ks, float alpha,
                     float kr, float kt, float ior) {
    this->ka = ka;
    this->kd = kd;
    this->ks = ks;
    this->alpha = alpha;
    this->kr = kr;
    this->kt = kt;
    this->ior = ior;
}

ostream& operator<<(ostream& os, Finishing& f) {
    os << f.ka << ' ';
    os << f.kd << ' ';
    os << f.ks << ' ';
    os << f.alpha << ' ';
    os << f.kr << ' ';
    os << f.kt << ' ';
    os << f.ior;
    return os;
}
