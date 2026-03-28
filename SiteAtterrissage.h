#ifndef SITEATTERRISSAGE_H
#define SITEATTERRISSAGE_H


#include <string>
#include "Sprite.h"
#include "Constantes.h"
#include <cstdlib>
#include <ctime>


class SiteAtterrissage : public Sprite {
public:
    SiteAtterrissage(std::string cheminTextureP, float xP, float yP);

    void changerSite();

};




#endif
