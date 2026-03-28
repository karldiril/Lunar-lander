#ifndef CONSTANTES_H
#define CONSTANTES_H


class Constantes {
public:
    // UI
    static const int LARGEUR_ECRAN;
    static const int HAUTEUR_ECRAN;
    static const int SEPARATION_VERTICALE;
    static const int X_TEXTE_FIN;
    static const int Y_TEXTE_FIN;

    // Lander
    static const float GRAVITE;
    static const float PROPULSION;
    static const float VITESSE_ROTATION;
    static const float MAX_ROTATION_DEGRES;
    static const float MAX_VY;
    static const float MAX_VX;


    // Site atterrissage
    static const float SITE_LARGEUR;
    static const float SITE_MIN_Y;
    static const float SITE_MAX_X;


    // Montagnes

    static const int MONTAGNES_HAUTEUR_DEPART;
    static const float MONTAGNES_SEPARATION_SOMMETS;
    static const int MONTAGNES_HAUTEUR_MIN;

};


#endif