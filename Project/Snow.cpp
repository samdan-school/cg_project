#if !defined(SNOW_CPP)
#define SNOW_CPP

#include <math.h>
#include <vector>
#include<iostream>
#include <math.h>
#include<string.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "w_constant.h"

class Snowflack {
    public:

    float x;
    float y;
    float z;
    int life;

    Snowflack() {};

    Snowflack(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;

        this->life = rand() % 400 + 200;
    }

    void update(){
        if (life <= 0) {
            y = rand() % 400 + 600;
            life = y;
            return;
        }
        x -= rand() % 4 - 2;
        z -= rand() % 4 - 2;
        y -= 10;
        life -= 10;
    }
};



#endif // SNOW_CPP
