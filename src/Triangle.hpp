#pragma once

#include <iostream>
#include <memory>
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

    /**
     * \return a triple containing the three vertice's labels in no specific order.
     */
    std::tuple<std::string, std::string, std::string> vertexLabels() const;

// constructors, etc.
public:
    // TODO docs
    Triangle(const std::string& label, std::shared_ptr<const Node> n1, std::shared_ptr<const Node> n2, std::shared_ptr<const Node> n3);

// data members
private:

    // three vertices
    std::shared_ptr<const Node> _n1;
    std::shared_ptr<const Node> _n2;
    std::shared_ptr<const Node> _n3;

    friend std::ostream& operator<<(std::ostream& s, const Triangle& t);
    friend class Graph; // for constructing the adjacency map
};


} // namespace polygons
