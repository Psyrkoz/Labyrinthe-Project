#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

namespace geom
{
    class point
    {
        public:
            /**
                Constructeur par défaut: Coordonnée (0,0)
            */
            point();

            /**
                Constructeur avec coordonnée:
                @param x - Coordonnée en X
                @param y - Coordonnée en Y
            */
            point(int x, int y);

            /**
                @return coordonnée X
            */
            int x() const;

            /**
                @return coordonnée Y
            */
            int y() const;

            /**
                Positionne le point a (x,y)
                @param x - Coordonnée en X
                @param y - Coordonnée en Y
            */
            void move(int x, int y);

        private:
            int m_x, m_y;
    };
}

#endif // POINT_H_INCLUDED
