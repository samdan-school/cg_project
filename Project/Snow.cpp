#if !defined(SNOW_CPP)
#define SNOW_CPP

#include <math.h>

class Snowflack {
    public:

    float coordinate[3];
    int life;

    Snowflack(float coordinate[3]) {
        for(int i = 0; i < 3; i++) {
            this->coordinate[i] = coordinate[i];
        }

        // this->life = rand() *
    }
};

#endif // SNOW_CPP
