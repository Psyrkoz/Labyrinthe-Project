#include "robot.h"
#include "carte.h"
#include <iostream>

namespace laby
{
    robot::robot(const laby::carte &c)
    {
        setDepart(c);
    }

    bool robot::setDepart(const laby::carte &c)
    {
        if(c.estValide())
        {
            std::vector<std::vector<int>> map = c.getCarte();
            int i = 0;
            int j = 0;
            while(i < map.size() && map[i][j] != typeCase::DEPART)
            {
                j++;
                if(j == map[i].size())
                {
                    i++;
                    j = 0;
                }
            }

            m_position.move(j*laby::carte::TAILLE_CASE + laby::carte::TAILLE_CASE / 2, i*laby::carte::TAILLE_CASE + laby::carte::TAILLE_CASE / 2);
        }
    }

    geom::point robot::position() const
    {
        return m_position;
    }
}
