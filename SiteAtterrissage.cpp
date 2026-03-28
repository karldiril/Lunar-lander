#include "SiteAtterrissage.h"

SiteAtterrissage::SiteAtterrissage(std::string cheminTextureP, float xP, float yP)
    : Sprite { cheminTextureP, xP, yP, -PI / 2.0f, false} {

}

void SiteAtterrissage::changerSite() {
    float nombreEntreZeroEtUn = (float)rand() / (float)RAND_MAX;
    x = Constantes::SITE_LARGEUR + (Constantes::LARGEUR_ECRAN - Constantes::SITE_LARGEUR) * nombreEntreZeroEtUn;
    nombreEntreZeroEtUn = (float)rand() / (float)RAND_MAX;
    y = Constantes::SITE_MIN_Y + ((Constantes::HAUTEUR_ECRAN - Constantes::SITE_LARGEUR) - Constantes::SITE_MIN_Y) * nombreEntreZeroEtUn;
}