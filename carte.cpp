#include "carte.h"
#include <fstream>
#include "graphics.h"
#include <iostream>

namespace laby
{
    carte::carte(const std::string& fichier) : m_nomFichier{fichier}, m_estValide{false}
    {
        lire();
    }

    void carte::lire()
    {
        std::ifstream file;
        file.open(m_nomFichier);
        std::string ligne;

        int nbArrive = 0, nbDepart = 0;
        while(std::getline(file, ligne))
        {
            m_carte.push_back(std::vector<int>());
            for(char c : ligne)
            {
                int tc = c - '0';
                if(tc == typeCase::ARRIVE)
                    nbArrive++;
                else if(tc == typeCase::DEPART)
                    nbDepart++;

                m_carte[m_carte.size() - 1].push_back(c - '0');
            }
        }

        m_estValide = (nbArrive == 1 & nbDepart == 1);
    }

    void carte::afficher(std::ostream &ost) const
    {
        for(size_t i = 0; i < m_carte.size(); i++)
        {
            for(size_t j = 0; j < m_carte[i].size(); j++)
            {
                ost << m_carte[i][j];
            }
            ost << std::endl;
        }
    }

    bool carte::estValide() const
    {
        return m_estValide;
    }

    std::vector<std::vector<int>> carte::getCarte() const
    {
        return m_carte;
    }

    void carte::afficherGraphique()
    {
        for(size_t i = 0; i < m_carte.size(); i++)
        {
            for(size_t j = 0; j < m_carte[i].size(); j++)
            {
                if(m_carte[i][j] == typeCase::MUR)
                    setfillstyle(SOLID_FILL, WHITE);
                else if(m_carte[i][j] == typeCase::DEPART)
                    setfillstyle(SOLID_FILL, BLUE);
                else if(m_carte[i][j] == typeCase::ARRIVE)
                    setfillstyle(SOLID_FILL, RED);
                else
                    setfillstyle(EMPTY_FILL, BLACK);

                rectangle(j*TAILLE_CASE, i*TAILLE_CASE, j*TAILLE_CASE + TAILLE_CASE, i*TAILLE_CASE + TAILLE_CASE);
                floodfill(j*TAILLE_CASE+1, i*TAILLE_CASE+1, getmaxcolor());
            }
        }
    }

    std::ostream& operator<<(std::ostream &ost, const carte &c)
    {
        c.afficher(ost);
        return ost;
    }
}
