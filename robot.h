#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "point.h"


namespace laby
{
    class carte;
    class robot
    {
        public:
            robot(const laby::carte &c, int direction = 0);

			/**
				@return position du robot dans le labyrinthe
			*/
            geom::point position() const;

            /**
                @return la direction du robot
            */
            int direction() const;

			/**
				Change la position dans le labyrinthe
				@param[in] p - Nouvelle position dans le labyrinthe
			*/
			void position(const geom::point &p);

			/**
                Tourne vers la gauche le robot
            */
            void tournerGauche();

            /**
                Tourne vers la droite le robot
            */
            void tournerDroite();

        private:
			/**
				Permet de placer le robot dans le labyrinthe
			*/
            void setDepart(const laby::carte &c);

        private:
            geom::point m_position;
            int m_direction; // {DROITE = 0, BAS = 1, GAUCHE = 2, HAUT = 3}

    };
}

#endif // ROBOT_H_INCLUDED
