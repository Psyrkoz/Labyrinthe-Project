#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

namespace geom
{
    class point
    {
        public:
            /**
                Constructeur par d�faut: Coordonn�e (0,0)
            */
            point();

            /**
                Constructeur avec coordonn�e:
                @param x - Coordonn�e en X
                @param y - Coordonn�e en Y
            */
            point(int x, int y);

            /**
                @return coordonn�e X
            */
            int x() const;

            /**
                @return coordonn�e Y
            */
            int y() const;

            /**
                Positionne le point a (x,y)
                @param x - Coordonn�e en X
                @param y - Coordonn�e en Y
            */
            void move(int x, int y);

        private:
            int m_x, m_y;
    };
}

#endif // POINT_H_INCLUDED
