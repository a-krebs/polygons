#pragma once

#include <string>

#include "Node.hpp"


namespace polygons {


/**
 * \brief A single triangle in a triangulation of a polygon.
 */
class Triangle
{
// public interface
public:
    std::string label() const;

    bool completeColoring() const;

// constructors, etc.
public:
    Triangle(const std::string& label, Node& n1, Node& n2, Node& n3);

// data members
private:
    std::string _label;

    // three vertices
    Node& _n1;
    Node& _n2;
    Node& _n3;
};


} // namespace polygons
