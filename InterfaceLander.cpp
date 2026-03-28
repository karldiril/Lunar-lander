#include "InterfaceLander.h"
#include <raylib.h>

InterfaceLander::InterfaceLander(int xP, int yP, Lander& landerP)
    : x { xP }, y { yP }, lander { landerP } {

}


void InterfaceLander::update(float dt) {
    vxOk = lander.vxOk();
    vyOk = lander.vyOk();
    rotationOk = lander.rotationOk();

    libelleVx = formaterVx(lander.vx);
    libelleVy = formaterVy(lander.vy);
    libelleRotation = formaterRotation(lander.rotationDegres360());
}


void InterfaceLander::draw() {
    Color couleurVx = vxOk ? WHITE : RED;
    Color couleurVy = vyOk ? WHITE : RED;
    Color couleurRotation = rotationOk ? WHITE : RED;

    DrawText(libelleVx.c_str(), x, y, 10, couleurVx);
    DrawText(libelleVy.c_str(), x, y + Constantes::SEPARATION_VERTICALE, 10, couleurVy);
    DrawText(libelleRotation.c_str(), x, y + Constantes::SEPARATION_VERTICALE * 2, 10, couleurRotation);
    if (texteFinAffiche) {
        DrawText(texteFin.c_str(), x + Constantes::X_TEXTE_FIN, y + Constantes::Y_TEXTE_FIN, 20, WHITE);
    }

}

std::string InterfaceLander::formaterVx(float vx) {
    std::string valeurVx { "" };
    if (vx < 0.0f) {
        valeurVx = std::to_string(vx).substr(0, 6);
    }
    else {
        valeurVx = std::to_string(vx).substr(0, 5);
    }
    std::string texteVx = "vx : " + valeurVx;
    return texteVx;
}


std::string InterfaceLander::formaterVy(float vy) {
    std::string valeurVy { "" };
    if (vy < 0.0f) {
        valeurVy = std::to_string(vy).substr(0, 6);
    }
    else {
        valeurVy = std::to_string(vy).substr(0, 5);
    }
    std::string texteVy = "vy : " + valeurVy;
    return texteVy;
}


std::string InterfaceLander::formaterRotation(int rotationDegres) {
    std::string texteRotation = "rotation : " + std::to_string(rotationDegres);
    return texteRotation;
}


void InterfaceLander::afficherTexteFin(int etatJeu) {
    if (etatJeu == 1) {
        texteFin = "Bravo, vous avez gagné \n R pour relancer le jeu";
    }
    else {
        texteFin = "Vous avez perdu :'( \n R pour relancer le jeu";
    }
    texteFinAffiche = true;
}


void InterfaceLander::cacherTexteFin() {
    texteFinAffiche = false;
}
