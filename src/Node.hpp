#pragma once

#include <string>
#include <vector>

#include "Color.hpp"


namespace polygons {


/**
 * \brief A node in a graph.
 */
class Node
{
// public interface
public:
    std::string label() const;

    Color color() const;

    void setColor(const Color& color);

    const std::vector<Color>& permittedColors() const;

// constructors, etc.
public:
    Node(const std::string& label, std::vector<Color>&& permitted);

// data members
private:
    std::string _label;
    std::vector<Color> _permitted_colors;
    Color _color;
};


} // namespace polygons
