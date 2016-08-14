#ifndef PARTICLE_H
#define PARTICLE_H
#include <iostream>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
namespace creatingParticles
{


struct Particle
{
    double m_x;
    double m_y;
private:
    double m_speed;
    double m_direction;
private:
    void init();

public:
    Particle();
    virtual ~Particle();
    void update(int interval);

};
}
#endif // PARTICLE_H
