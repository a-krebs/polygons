#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <unordered_set>
#include <vector>

#include "Node.hpp"
#include "Triangle.hpp"


namespace polygons {


/**
 * \brief Graph that represents a triangulation of a polygon.
 */
class Graph
{
// types
public:
    using NodeIterator = std::vector<Node>::iterator;
    using TriangleConstIterator = std::vector<Triangle>::const_iterator;

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
    TriangleConstIterator cBeginTriangles() const;
    TriangleConstIterator cEndTriangles() const;

    std::size_t triangleCount() const;

    std::size_t adjacentCompleteTriangleCount(const Node& n) const;

    /**
     * \brief Determine which nodes form triangles.
     *
     * Currently only implemented for the example graph.
     */
    void calculateTriangulation();

    NodeIterator beginNodes();
    NodeIterator endNodes();

    std::size_t nodeCount() const;

// constructors, etc.
public:
    Graph(const std::string& label, std::vector<Node>&& nodes);

    ~Graph();

// data members:
private:
    std::string _label;
    std::vector<Node> _nodes;
    std::vector<Triangle> _triangulation;
    std::map<const Node*, std::unordered_set<const Triangle*>> _adjacency;
    bool _triangulated;
    
    friend std::ostream& operator<<(std::ostream& s, const Graph& g);
};




} // namespace polygons
