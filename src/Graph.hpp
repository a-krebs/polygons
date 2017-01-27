#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <unordered_set>
#include <vector>

#include "Labeled.hpp"
#include "Node.hpp"
#include "Triangle.hpp"


namespace polygons {


/**
 * \brief Graph that represents a triangulation of a polygon.
 */
class Graph : public Labeled
{
// types
public:

    using NodeIterator = std::vector<Node>::iterator;
    using TriangleConstIterator = std::vector<Triangle>::const_iterator;

// static functions
public:

    /**
     * \brief Construct graph given as the example polygon.
     *
     * Has 22 nodes.
     *
     * \returns a new Graph instance.
     */
    static Graph getExampleGraph();

// public interface
public:

    /**
     * \brief Start iterator over the triangles that are formed by this graph.
     *
     * Call calculateTriangulation() first.
     * 
     * \throws std::logic_error If calculateTriangulation() has not been called;
     */
    TriangleConstIterator cBeginTriangles() const;

    /**
     * \brief End iterator over the triangles that are formed by this graph.
     *
     * Call calculateTriangulation() first.
     *
     * \throws std::logic_error If calculateTriangulation() has not been called;
     */
    TriangleConstIterator cEndTriangles() const;


    /**
     * \returns The number of triangles adjacent to 'n'.
     *
     * \throws std::logic_error If calculateTriangulation() has not been called;
     */
    std::size_t adjacentCompleteTriangleCount(const Node& n) const;

    /**
     * \brief Determine which nodes in this graph form triangles.
     *
     * \warning Only implemented for example graph.
     */
    void calculateTriangulation();

    /**
     * \brief Start iterator over the graph's nodes.
     */
    NodeIterator beginNodes();

    /**
     * \brief End iterator over the graph's nodes.
     */
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
