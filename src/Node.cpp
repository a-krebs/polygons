#include "Node.hpp"


namespace polygons {


std::string Node::label() const
{
    return _label;
}


Color Node::color() const
{
    return _color;
}


void Node::setColor(const Color& color)
{
    // TODO error check that it's only a single color
    _color = color;
}


const std::vector<Color>& Node::permittedColors() const
{
    return _permitted_colors;
}


Node::Node(const std::string& label, std::vector<Color>&& permitted)
    : _label(label)
    , _permitted_colors(permitted)
    , _color(Color::NONE)
{
}


} // namespace polygons
