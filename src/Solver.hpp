#pragma once

#include <cstddef>
#include <functional>
#include <memory>
#include "gtest/gtest.h"

#include "Graph.hpp"


namespace polygons {


/**
 * Finds a coloring solution for a given Graph so that exactly the given
 * number of completely colored triangles are present.
 */
class Solver
{
// types, constants
public:

    using CallbackFunc = std::function<void(const Solver&, const Graph&)>;

// public interface
public:

    /**
     * \brief Find all solutions to the coloring of Graph g with the constraints.
     *
     * \warning The given graph's nodes are modified.
     * Calls the callback set in the constructor once for each solution.
     * 
     * This implementation is a recursive backtracking algorithm. It applies all
     * possible colorings to each node (depth-first), and validates the solution
     * when all nodes have a color.
     *
     * \returns The number of solutions.
     */
    std::size_t solveRecursive(Graph& g) const;

    /**
     * \brief Find all solutions to the coloring of Graph g with the constraints.
     *
     * \warning The given graph's nodes are modified.
     * Calls the callback set in the constructor once for each solution.
     *
     * This implementation is a recursive backtracking algorithm with early pruning.
     * It iteratively applies colors to each node (depth-first), and aborts search
     * branches as soon as the graph violates the given constraints (even if
     * not all Nodes have a color yet).
     *
     * \returns The number of solutions.
     */
    std::size_t solveRecursiveWithPruning(Graph& g) const;

    /**
     * \return true if the given graph meets the constraints.
     *
     * Does not call the callback set in the constructor.
     */
    bool meetsConstraints(const Graph& g) const;

// constructors, etc.
public:
    
    /**
     * \brief Construct a new Solver instance.
     *
     * \param req_complete The required exact number of completely colored triangles in the graph.
     * \param callback     Callback called once for each found solution.
     */
    Solver(const std::size_t& req_complete, const CallbackFunc callback);

// private interface
private:

    /**
     * \brief Implementation of depth-first, non-pruning, backtracking search.
     *
     * \param[out] solutions  Set to the number of solutions found.
     * \param[out] attempts   Set to the number of possible graph colorings tried.
     * \param[in]  g          The graph to solve (will be modified).
     * \param[in]  it         Iterator to the next node to which to apply a color.
     * \param[in]  end        Iterator past the last node to which to apply a color.
     */
    void recurse(std::size_t& solutions, std::size_t& attempts, Graph& g, Graph::NodeIterator it, Graph::NodeIterator end) const;

    /**
     * \brief Implementation of depth-first, pruning, backtracking search.
     *
     * \param[out] solutions          Set to the number of solutions found.
     * \param[out] attempts           Set to the number of possible graph colorings tried.
     * \param[in]  g                  The graph to solve (will be modified).
     * \param[out] complete_triangles Number of complete_triangles found so far. Will be updated.
     * \param[in]  it                 Iterator to the next node to which to apply a color.
     * \param[in]  end                Iterator past the last node to which to apply a color.
     */
    void recurseWithPruning(std::size_t& solutions, std::size_t& attempts, Graph& g, std::size_t& complete_triangles, Graph::NodeIterator it, Graph::NodeIterator end) const;

// data members
private:
    std::size_t _req_complete;
    CallbackFunc _callback;

    FRIEND_TEST(Solver, NonPruningColorings);
};


} // namespace polygons
