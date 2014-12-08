#ifndef VEGETATION_H
#define VEGETATION_H
#include "bati.h"
#include <vector>

class vegetation
{
public:
    /**
     * \brief      Constructeur de la classe végétation
     * \details    Classe permettant de tracer la végétation en OpenGL
     */
    vegetation();
    /**
     * \brief      Tri et stocke le centre de chaque contour de végétation
     * \details    Les contours sont trié en fonction de leur taille et le centre de ces contours est stoqué sans redondance
     *
     * \param[in] contourVeget Vecteur contenant les contours de la végétation
     */
    void triVegeta(vector< vector<Point> > contourVeget);
    /**
     * \brief      Fonction detectant les doublons d'd'un vecteur
     * \details    Les contours sont trié en fonction de leur taille et le centre de ces contours est stoqué sans redondance
     *
     * \param[in] list      Vecteur contenant les contours de la végétation
     * \param[in] lePoint   Point à vérifier
     * \return retourne vrai ou false si lePoint existe déjà dans list
     */
    bool myDoublon(vector<Point> list, Point lePoint);
    /**
     * \brief      Trace un cylindre à partir d'une base et d'une hauteur
     *
     * \param[in] base      base du cylindre
     * \param[in] height    hauteur du cylindre
     *
     */
    void drawCylindre(float base, float height);
    /**
     * \brief      Trace un arbre en fonction de coordonnées et de la taille de l'arbre
     * \details    Trace le tronc de l'arbre avec un cylindre puis appelle la fonction drawBranche pour tracer les branches
     *
     * \param[in] x         coordonnée x de l'arbre
     * \param[in] y         coordonnée y de l'arbre
     * \param[in] taille    taille de l'arbre
     */
    void drawArbre(float x, float y, float taille);
    /**
     * \brief      Fonction recursive traçant les branches d'un arbre
     * \details
     *
     * \param[in] p         nbre d'itération de la fonction
     * \param[in] taille    taille de l'arbre
     */
    void drawBranche(int p, float taille);
    /**
     * \brief      Trace les arbres à partir des listes des centres des arbres
     *
     */
    void drawtotal();
private:
    vector<Point> centrArbre,centreForet;
};

#endif // VEGETATION_H
