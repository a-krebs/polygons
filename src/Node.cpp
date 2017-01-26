#include "Node.hpp"


namespace polygons {


std::string Node::label() const
{
    return _label;
}


Color Node::color() const
{
    // TODO sanity check that it's only a single color
    return _color;
}


Node::Node(const std::string& label, const Color& permitted)
    : _label(label)
    , _permitted_colors(permitted)
    , _color(Color::NONE)
{
}


} // namespace polygons
