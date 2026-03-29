#include <raylib.h>
#include "Lander.h"
#include "SiteAtterrissage.h"
#include "InterfaceLander.h"
#include "Constantes.h"
#include "Montagnes.h"




int etat = 0;


void load();
void update();
void draw();
void unload();



Lander lander{"assets/images/lander.png", static_cast<float>(Constantes::LARGEUR_ECRAN) / 2, 0, true};
SiteAtterrissage site {"assets/images/cible.png", static_cast<float>(Constantes::LARGEUR_ECRAN / 2), static_cast<float>(Constantes::HAUTEUR_ECRAN) - 100};
InterfaceLander interface { 50, 50, lander };
Montagnes montagnes { site.x, site.y};


// Code et définitions


int main() {
    load();
    while (!WindowShouldClose()) {
        update();
        draw();
    }
    unload();
}


void load() {
    InitWindow(Constantes::LARGEUR_ECRAN, Constantes::HAUTEUR_ECRAN, "Lander");
    SetTargetFPS(60);
    lander.load();
    site.load();
}


void update() {
    float dt = GetFrameTime();

    // Jeu Normal
    if (etat == 0) {
        lander.update(dt);
        interface.update(dt);
        Rectangle rectLander = lander.getRectangle();
        rectLander.y = rectLander.y + rectLander.height / 2;
        Rectangle rectSite = site.getRectangle();
        if (CheckCollisionRecs(rectLander, rectSite)) {
            float xMaxLander = rectLander.x + rectLander.width;
            float xMaxSite = rectSite.x + rectSite.width;
            // Réussite
            if ((rectLander.x >= rectSite.x || xMaxLander <= xMaxSite) && lander.atterrissageOk()) {
                etat = 1;
            }
            else {
                etat = 2;
            }
            interface.afficherTexteFin(etat);
            lander.eteindreFlamme();
        }
        if (rectLander.y + rectLander.height > Constantes::HAUTEUR_ECRAN
            || rectLander.x < 0
            || rectLander.x + rectLander.width > Constantes::LARGEUR_ECRAN) {
            etat = 2;
            interface.afficherTexteFin(etat);

        }
    }
    // Victoire ou défaite
    else {
        if (IsKeyPressed(KEY_R)) {
            etat = 0;
            lander.replacer();
            interface.cacherTexteFin();
            site.changerSite();
            montagnes.effacerLignes();
            montagnes.tracerLignes(site.x, site.y);
        }
    }
}

void draw() {
    BeginDrawing();
    ClearBackground(SKYBLUE);

    site.draw();
    lander.draw();
    interface.draw();
    montagnes.draw();

    EndDrawing();
}


void unload() {
    lander.unload();
    site.unload();
    CloseWindow();
}