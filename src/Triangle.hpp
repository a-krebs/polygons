#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "Labeled.hpp"
#include "Node.hpp"


namespace polygons {


/**
 * \brief A single triangle in a triangulation of a polygon.
 *
 * Has three Nodes that are part of a larger Graph.
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
     * \return a triple containing the label of each vertex (in no specific order).
     */
    std::tuple<std::string, std::string, std::string> vertexLabels() const;

// constructors, etc.
public:

    /**
     * \brief Construct a new Triangle.
     *
     * All given vertices must be part of the same Graph.
     *
     * \param label The graph's name.
     * \param n1    Vertex of this Triange.
     * \param n2    Vertex of this Triange.
     * \param n3    Vertex of this Triange.
     */
    Triangle(const std::string& label, std::shared_ptr<const Node> n1, std::shared_ptr<const Node> n2, std::shared_ptr<const Node> n3);

// data members
private:

    // three vertices
    std::shared_ptr<const Node> _n1;
    std::shared_ptr<const Node> _n2;
    std::shared_ptr<const Node> _n3;

    friend std::ostream& operator<<(std::ostream& s, const Triangle& t);
};


} // namespace polygons
