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
        std::ifstream fichier;
        fichier.open(m_nomFichier);
        std::string ligne;

        int nbArrive = 0, nbDepart = 0;
        while(std::getline(fichier, ligne))
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

	bool carte::estUnMur(const geom::point &p) const
	{
		bool estMur = true;
		try
		{
			estMur = m_carte.at(p.x()).at(p.y()) != typeCase::MUR;
		}
		catch(std::out_of_range &e)
		{
			std::cerr << e.what() << std::endl;
		}

		return estMur;
	}

    const std::vector<std::vector<int>>& carte::getCarte() const
    {
        return m_carte;
    }


    std::ostream& operator<<(std::ostream &ost, const carte &c)
    {
        c.afficher(ost);
        return ost;
    }
}
