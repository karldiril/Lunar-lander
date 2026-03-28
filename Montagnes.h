#ifndef MONTAGNES_H
#define MONTAGNES_H

#include "Ligne.h"
#include <vector>
#include "Constantes.h"
#include <math.h>
#include "SiteAtterrissage.h"


class Montagnes {
public:
    Montagnes(float siteX, float siteY);
    void draw();
    void ajouterLigne(Vector2 debut, Vector2 fin);
    void tracerLignes(float siteX, float siteY);
    void effacerLignes();

    std::vector<Ligne> lignes;
};


#endif
