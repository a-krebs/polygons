#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
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

    /**
     * Wrapper around std::vector<std::shared_ptr<Node>>::iterator
     * that hides the shared_ptr<Node> as a implementation detail and
     * exposes only Node& type.
     */
    class NodeIterator
    {
    // public interface
    public:

        NodeIterator& operator++(); // prefix

        Node& operator*();

        bool operator==(const NodeIterator& other);

    // constructors, etc.
    public:
        NodeIterator(const std::vector<std::shared_ptr<Node>>::iterator& iter);

    // data members:
    private:
        std::vector<std::shared_ptr<Node>>::iterator _iter;
    };

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
     */
    TriangleConstIterator cBeginTriangles() const;

    /**
     * \brief End iterator over the triangles that are formed by this graph.
     */
    TriangleConstIterator cEndTriangles() const;

    /**
     * \returns The number of completely colored triangles adjacent to 'n'.
     */
    std::size_t adjacentCompleteTriangleCount(const Node& n) const;

    /**
     * \brief Start iterator over the graph's nodes.
     */
    NodeIterator beginNodes();

    /**
     * \brief End iterator over the graph's nodes.
     */
    NodeIterator endNodes();

// constructors, etc.
public:
    
    /**
     * \brief Construct a new Graph instance.
     *
     * \param label         The graph's name.
     * \param nodes         All nodes that are part of this graph. Must have unique labels.
     * \param triangulation Triangle instances that enumerate all Triangles formed
     *                      by the given Nodes. The Triangle instances must only
     *                      refer to Nodes in from the 'nodes' parameter. Must
     *                      have unique labels.
     */
    Graph(const std::string& label, std::vector<std::shared_ptr<Node>>&& nodes, std::vector<Triangle>&& triangulation);

    ~Graph();

// data members:
private:
    std::string _label;
    std::vector<std::shared_ptr<Node>> _nodes;
    std::vector<Triangle> _triangulation;
    // possible performance improvements here, see README
    std::unordered_map<std::string, std::unordered_set<const Triangle*>> _adjacency;
    
    friend std::ostream& operator<<(std::ostream& s, const Graph& g);
};




} // namespace polygons
