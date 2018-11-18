#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include <string>
#include <vector>


namespace laby
{
    enum typeCase {VIDE = 0, MUR = 1, DEPART = 2, ARRIVE = 3};
    class carte
    {
        public:
            static const int TAILLE_CASE = 32;

            carte() = delete;
            carte(const std::string &fichier);
            void afficher(std::ostream &ost) const;
            void afficherGraphique();

            bool estValide() const;
            std::vector<std::vector<int>> getCarte() const;

        private:
            void lire();

        private:
            bool m_estValide;
            std::string m_nomFichier;
            std::vector<std::vector<int>> m_carte;
    };

    std::ostream& operator<<(std::ostream &ost, const carte &c);
}

#endif // CARTE_H_INCLUDED
