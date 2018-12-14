#include "Point.h"

namespace geom
{
    point::point() : m_x{0}, m_y{0}
    {}

    point::point(int x, int y) : m_x{x}, m_y{y}
    {}

    int point::x() const
    {
        return m_x;
    }

    int point::y() const
    {
        return m_y;
    }

    void point::move(int x, int y)
    {
        m_x = x; m_y = y;
    }
}
