#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "point.h"


namespace laby
{
    class carte;
    class robot
    {
        public:
            robot(const laby::carte &c);
            geom::point position() const;

        private:
            bool setDepart(const laby::carte &c);

        private:
            geom::point m_position;
    };
}

#endif // ROBOT_H_INCLUDED
