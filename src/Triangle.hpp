#pragma once

#include <string>

#include "Labeled.hpp"
#include "Node.hpp"


namespace polygons {


/**
 * \brief A single triangle in a triangulation of a polygon.
 */
class Triangle : public Labeled
{
// types, constants
public:

    //! \brief RED, BLUE, and YELLOW
    static const Color COMPLETE_COLORS;

// public interface
public:

    /**
     * \return True if this Triangle has one vertex of each color.
     */
    bool completeColoring() const;

// constructors, etc.
public:
    Triangle(const std::string& label, Node& n1, Node& n2, Node& n3);

// data members
private:

    // three vertices
    Node& _n1;
    Node& _n2;
    Node& _n3;

    friend std::ostream& operator<<(std::ostream& s, const Triangle& t);
    friend class Graph; // for constructing the adjacency map
};


} // namespace polygons
