#pragma once

#include <cstddef>
#include <functional>
#include <memory>

#include "Graph.hpp"


namespace polygons {


class Solver
{
// public interface
public:

    using CallbackFunc = std::function<void(const Solver&, const Graph&)>;

    int solveRecursive(Graph& g) const;

    int solveRecursiveWithPruning(Graph& g) const;

    int solveRecursiveWithPruningB(Graph& g) const;

    bool meetsConstraints(const Graph& g) const;

// constructors, etc.
public:
    // TODO docs
    Solver(const std::size_t& req_complete, const CallbackFunc callback);

// private interface
private:

    void recurse(int& solutions, Graph& g, Graph::NodeIterator it, Graph::NodeIterator end) const;
    void recurseWithPruning(int& solutions, Graph& g, int& complete_triangles, Graph::NodeIterator it, Graph::NodeIterator end) const;
    void recurseWithPruningB(int& solutions, Graph& g, Graph::NodeIterator it, Graph::NodeIterator end) const;

// data members
private:
    std::size_t _req_complete;
    CallbackFunc _callback;
};


} // namespace polygons
