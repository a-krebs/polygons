#pragma once

#include <string>

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

// constructors, etc.
public:
    Node(const std::string& label, const Color& permitted);

// data members
private:
    std::string _label;
    Color _permitted_colors;
    Color _color;
};


} // namespace polygons
