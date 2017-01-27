#include "Triangle.hpp"


namespace polygons {


const Color Triangle::COMPLETE_COLORS( Color::RED | Color::YELLOW | Color::BLUE );


bool Triangle::completeColoring() const
{
    return (_n1.color() | _n2.color() | _n3.color()) == COMPLETE_COLORS;
}


Triangle::Triangle(const std::string& label, Node& n1, Node& n2, Node& n3)
    : Labeled(label)
    , _n1(n1)
    , _n2(n2)
    , _n3(n3)
{
}


std::ostream& operator<<(std::ostream& s, const Triangle& t)
{
    s << "Triangle " << t.label()
      << "(" << t._n1.label() << ", "
      << t._n2.label() << ", "
      << t._n3.label() << ")";
    return s;
}

} // namespace polygons
