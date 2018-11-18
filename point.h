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
    };
}

#endif // POINT_H_INCLUDED
