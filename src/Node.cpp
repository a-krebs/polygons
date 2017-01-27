#include "Node.hpp"


namespace polygons {


const Color& Node::color() const
{
    return _color;
}


void Node::setColor(const Color& color)
{
    // TODO error check that it's only a single color
    if((color | _permitted_color_mask) != _permitted_color_mask)
    {
        throw std::runtime_error("Not a permitted color for this node.");
    }
    _color = color;
}


const std::vector<Color>& Node::permittedColors() const
{
    return _permitted_colors;
}


Node::Node(const std::string& label, std::vector<Color>&& permitted)
    : Labeled(label)
    , _permitted_colors(permitted)
    , _permitted_color_mask(Color::NONE)
    , _color(Color::NONE)
{
    for(const auto& color : _permitted_colors)
    {
        _permitted_color_mask = _permitted_color_mask | color;
    }
}


} // namespace polygons
