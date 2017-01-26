#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "Node.hpp"
#include "Triangle.hpp"


namespace polygons {


/**
 * \brief Graph that represents a triangulation of a polygon.
 */
class Graph
{
// static functions
public:

    /**
     * \brief Construct graph given as example.
     *
     * Has 22 nodes.
     */
    static std::shared_ptr<Graph> getExampleGraph();

// public interface
public:
    std::string label() const;

    /**
     * \brief The triangles that are formed by this graph.
     *
     * Call calculateTriangulation() first.
     * 
     * \throws std::logic_error If calculateTriangulation() has not been called;
     */
    const std::vector<Triangle>& triangulation() const;

    /**
     * \brief Determine which nodes form triangles.
     *
     * Currently only implemented for the example graph.
     */
    void calculateTriangulation();

    std::vector<Node>& nodes();

// constructors, etc.
public:
    Graph(const std::string& label, std::vector<Node>&& nodes);

    ~Graph();

// data members:
private:
    std::string _label;
    std::vector<Node> _nodes;
    std::vector<Triangle> _triangulation;
    bool _triangulated;
    
    friend std::ostream& operator<<(std::ostream& s, const Graph& g);
};




} // namespace polygons
