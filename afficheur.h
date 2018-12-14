#ifndef AFFICHEUR_H_INCLUDED
#define AFFICHEUR_H_INCLUDED

#include "carte.h"
#include "robot.h"

namespace laby
{
    class afficheur
    {
        public:
            afficheur() = delete;
            afficheur(int tailleX, int tailleY);

            void ouvrir();
            void fermer();

            void afficherCarte(const carte &c) const;
            void afficherRobot(const robot &r) const;

        private:
            int m_tailleX, m_tailleY;
            bool m_estOuvert;
    };
}

#endif // AFFICHEUR_H_INCLUDED
