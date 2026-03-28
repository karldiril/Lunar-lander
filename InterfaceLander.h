#ifndef INTERFACELANDER_H
#define INTERFACELANDER_H


#include <iostream>
#include "Lander.h"
#include "Constantes.h"

class InterfaceLander {
public:
    InterfaceLander(int xP, int yP, Lander& lander);
    void update(float dt);
    void draw();

    std::string formaterVx(float vx);
    std::string formaterVy(float vy);
    std::string formaterRotation(int rotationDegres);

    void afficherTexteFin(int etatJeu);
    void cacherTexteFin();


    Lander& lander;
    int x { 0 };
    int y { 0 };
    std::string libelleVx { "vx : 0" };
    std::string libelleVy { "vy : 0" };
    std::string libelleRotation { "angle : 0" };
    std::string texteFin { "" };
    bool texteFinAffiche { false };

    bool vxOk { false };
    bool vyOk { false };
    bool rotationOk { false };

};


#endif
