#ifndef LANDER_H
#define LANDER_H

#include <raylib.h>
#include <string>

#include "Sprite.h"
#include "Constantes.h"

class Lander : public Sprite {
public:
    Lander(std::string cheminTextureP, float xP, float yP, bool centreP);
    void update(float dt);
    void load() override;
    void draw() override;
    void unload() override;


    bool vxOk();
    bool vyOk();
    bool rotationOk();
    bool atterrissageOk();
    int rotationDegres360();
    void replacer();
    void eteindreFlamme();


    float vx{0.0f};
    float vy{0.0f};
    float xDepart { 0.0f };
    float yDepart { 0.0f };

    bool flammeVisible { false };
    Sprite flamme {"../assets/images/flamme.png", 0.0f, 0.0f, 0.0f, true};
};


#endif
