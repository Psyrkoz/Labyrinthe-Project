#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include <string>
#include <vector>
#include "point.h"

namespace laby
{
    enum typeCase {VIDE = 0, MUR = 1, DEPART = 2, ARRIVE = 3};
    class carte
    {
        public:
			/**
				Taille d'une case dans l'affichage graphique
			*/
            static const int TAILLE_CASE = 32;

            carte() = delete;
            carte(const std::string &fichier);

			/**
				Affiche la carte dans la console de commande
			*/
            void afficher(std::ostream &ost) const;

			/*
				Affichage la carte dans la fenêtre graphique
			*/
            void afficherGraphique();

			/**
				@return VRAI si la carte possède une et une seule entrée et sortie.
			*/
            bool estValide() const;

			/*
				Verifie si la case a la position p(x,y) est un mur
				@param[in] p - position a verifier
				@return VRAI si la case est un mur
			*/
			bool estUnMur(const geom::point &p) const;


            const std::vector<std::vector<int>>& getCarte() const;

        private:
			/**
				Permet de lire la carte qui est stocké dans le fichier du nom m_nomFichier
			*/
            void lire();

        private:
            bool m_estValide;
            std::string m_nomFichier;
            std::vector<std::vector<int>> m_carte;
    };

    std::ostream& operator<<(std::ostream &ost, const carte &c);
}

#endif // CARTE_H_INCLUDED
