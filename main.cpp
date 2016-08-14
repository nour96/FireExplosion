#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
#include "Particle.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

using namespace std;
using namespace creatingParticles;

int main()
{

    srand(time(NULL));

    Screen screen;
    if (screen.init()==false)
    {
        cout << "Error." << endl;
    };

    Swarm swarm;

    while (true)
    {

        int elapsed= SDL_GetTicks();

        swarm.update(elapsed);

        unsigned char red=(unsigned char)((1+sin (elapsed*0.0001))*128);
        unsigned char green=(unsigned char)((1+sin (elapsed*0.0002))*128);
        unsigned char blue=(unsigned char)((1+sin (elapsed*0.0003))*128);


        const Particle * const pParticle = swarm.getParticles();
        for (int i=0; i<Swarm::NPARTICLES; i++)
        {
            Particle particle = pParticle[i];
            int x = (particle.m_x +1) * Screen::WINDOW_WIDTH/2;
            int y = particle.m_y * Screen::WINDOW_WIDTH/2 + Screen::WINDOW_HEIGHT/2 ;

            screen.setPixel(x,y,red,green,blue);

        }

        screen.boxBlur();
        //Update screen..
        screen.screenUpdate();

        if (screen.processEvents() == false)
            break;
    }

    screen.close();

    return 0;
}
