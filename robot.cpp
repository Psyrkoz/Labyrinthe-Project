#include "robot.h"
#include "carte.h"
#include <iostream>

namespace laby
{
    robot::robot(const laby::carte &c, int direction) : m_direction{direction}
    {
        setDepart(c);
    }

    void robot::setDepart(const laby::carte &c)
    {
        if(c.estValide())
        {
            std::vector<std::vector<int>> map = c.getCarte();
            size_t i = 0;
            size_t j = 0;
            while(i < map.size() && map[i][j] != typeCase::DEPART)
            {
                j++;
                if(j == map[i].size())
                {
                    i++;
                    j = 0;
                }
            }

            m_position.move(j, i);
        }
    }

    geom::point robot::position() const
    {
        return m_position;
    }

    int robot::direction() const
    {
        return m_direction;
    }

	void robot::position(const geom::point &p)
	{
		m_position = p;
	}

	void robot::tournerDroite()
	{
        m_direction++;
        if(m_direction > 3) // Si on depasse (par le haut) la 4eme direction possible
            m_direction = 0;
	}

	void robot::tournerGauche()
	{
	    m_direction--;
	    if(m_direction < 0) // Si on depasse (par le bas) la 4eme direction possible
            m_direction = 3;
	}
}
