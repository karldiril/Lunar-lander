#include <math.h>
#include "Lander.h"




Lander::Lander(std::string cheminTextureP, float xP, float yP, bool centreP)
    : Sprite { cheminTextureP, xP, yP, -PI / 2.0f, centreP }, xDepart { xP }, yDepart { yP } {
}


void Lander::load() {
    flamme.load();
    Sprite::load();
}


void Lander::update(float dt) {
    if (IsKeyDown(KEY_SPACE)) {
        vx += cos(rotation) * abs(Constantes::PROPULSION) * dt;
        vy += sin(rotation) * abs(Constantes::PROPULSION) * dt;
        flammeVisible = true;
    }
    else
        flammeVisible = false;


    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        rotation -= Constantes::VITESSE_ROTATION * dt;
    }
    else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        rotation += Constantes::VITESSE_ROTATION * dt;
    }


    vy += Constantes::GRAVITE * dt;
    x += vx * dt;
    y += vy * dt;

    flamme.x = x;
    flamme.y = y;
    flamme.rotation = rotation;
    flamme.visible = flammeVisible;
}


void Lander::draw() {
    Sprite::draw();
    flamme.draw();
}


void Lander::unload() {
    Sprite::unload();
    flamme.unload();
}

int Lander::rotationDegres360() {
    float rotationAjustee = rotation + PI / 2.0f;
    float rotationDegres = rotationAjustee * 180.0f / PI;
    int rotationArrondie = round(rotationDegres);
    int rotation360 = rotationArrondie % 360;
    return rotation360;
}

bool Lander::vxOk() {
    return abs(vx) < Constantes::MAX_VX;
}


bool Lander::vyOk() {
    return abs(vy) < Constantes::MAX_VY;
}


bool Lander::rotationOk() {
    int rotation360 = rotationDegres360();
    return ((rotation360 < Constantes::MAX_ROTATION_DEGRES) || (rotation360 > 360 - Constantes::MAX_ROTATION_DEGRES));
}



bool Lander::atterrissageOk() {
    return vxOk() && vyOk() && rotationOk();
}



void Lander::replacer() {
    x = xDepart;
    y = yDepart;
    vx = 0.0f;
    vy = 0.0f;
    rotation = -PI / 2.0f;
}

void Lander::eteindreFlamme() {
    flamme.visible = false;
}
