#include "afficheur.h"
#include "graphics.h"
#include <iostream>
#include <vector>

namespace laby
{
    afficheur::afficheur(int tailleX, int tailleY) : m_tailleX{tailleX}, m_tailleY{tailleY}, m_estOuvert{false}
    {}

    void afficheur::ouvrir()
    {
        if(!m_estOuvert)
        {
            opengraphsize(m_tailleX, m_tailleY);
            m_estOuvert = true;
        }
    }

    void afficheur::fermer()
    {
        if(m_estOuvert)
        {
            closegraph();
        }
    }

    void afficheur::afficherCarte(const carte &c) const
    {
        if(m_estOuvert)
        {
            const std::vector<std::vector<int>>& ca = c.getCarte();
            for(size_t i = 0; i < ca.size(); i++)
            {
                for(size_t j = 0; j < c.getCarte()[i].size(); j++)
                {
                    if(ca[i][j] == typeCase::MUR)
                        setfillstyle(SOLID_FILL, WHITE);
                    else if(ca[i][j] == typeCase::DEPART)
                        setfillstyle(SOLID_FILL, BLUE);
                    else if(ca[i][j] == typeCase::ARRIVE)
                        setfillstyle(SOLID_FILL, RED);
                    else
                        setfillstyle(EMPTY_FILL, BLACK);

                    rectangle(j*carte::TAILLE_CASE, i*carte::TAILLE_CASE, j*carte::TAILLE_CASE + carte::TAILLE_CASE, i*carte::TAILLE_CASE + carte::TAILLE_CASE);
                    floodfill(j*carte::TAILLE_CASE+1, i*carte::TAILLE_CASE+1, getmaxcolor());
                }
            }
        }
    }

    // TODO : Finir l'affichage du robot
    void afficheur::afficherRobot(const robot& r) const
    {
        if(m_estOuvert)
        {
            int direction = r.direction();
            int decalageSommetX = 0, decalageSommetY = 0;
            geom::point position = r.position();

            if(direction == 0) // Le robot pointe vers la droite
            {
                decalageSommetX = laby::carte::TAILLE_CASE / 2;
            }
            else if(direction == 1) // Le robot pointe vers le bas
            {
                decalageSommetY = laby::carte::TAILLE_CASE / 2;
            }
            else if(direction == 2) // Le robot point vers la gauche
            {
                decalageSommetX = -laby::carte::TAILLE_CASE / 2;
            }
            else
            {
                decalageSommetY = -laby::carte::TAILLE_CASE / 2;
            }
        }
    }
}
