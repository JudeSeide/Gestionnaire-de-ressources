#if !defined(__PERIODE_H__)
#define __PERIODE_H__

#include <iostream>

class Periode {
private:
    int debut;
    int fin;
public:

    Periode() {
    }

    Periode(int d, int f) : debut(d), fin(f) {
    }

    int getDebut() const {
        return debut;
    }

    int getFin() const {
        return fin;
    }

    friend std::ostream& operator <<(std::ostream&, const Periode&);
    friend std::istream& operator >>(std::istream&, Periode&);
};
#endif
