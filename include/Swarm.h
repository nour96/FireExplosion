#ifndef SWARM_H
#define SWARM_H
#include <iostream>
#include <SDL2/SDL.h>
#include "Particle.h"

using namespace std;
namespace creatingParticles
{


class Swarm
{
public:
    const static int NPARTICLES = 5000;
private:
    Particle *m_pParticle;
    int lastTime;
public:
    Swarm();
    ~Swarm();
    void update(int elapsed);
    const Particle * const getParticles() {return m_pParticle;};
};
}
#endif // SWARM_H
