#include "Triangle.hpp"


namespace polygons {


std::string Triangle::label() const
{
    return _label;
}


bool Triangle::completeColoring() const
{
    const Color all = Color::RED | Color::YELLOW | Color::BLUE;
    return (_n1.color() | _n2.color() | _n3.color()) == all;
}


Triangle::Triangle(const std::string& label, Node& n1, Node& n2, Node& n3)
    : _label(label)
    , _n1(n1)
    , _n2(n2)
    , _n3(n3)
{
}


} // namespace polygons
