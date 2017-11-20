#include <iostream>

#include "Solver.hpp"


namespace polygons {


std::size_t Solver::solveRecursive(Graph& g) const
{
    std::size_t solutions = 0;
    std::size_t attempts = 0;
    recurse(solutions, attempts, g, g.beginNodes(), g.endNodes());
    return solutions;
}


std::size_t Solver::solveRecursiveWithPruning(Graph& g) const
{
    std::size_t solutions = 0;
    std::size_t attempts = 0;
    std::size_t complete_triangles = 0;
    recurseWithPruning(solutions, attempts, g, complete_triangles, g.beginNodes(), g.endNodes());
    return solutions;
}


bool Solver::meetsConstraints(const Graph& g) const
{
    std::size_t complete_triangles = 0;

    for(auto cIt = g.cBeginTriangles(); cIt != g.cEndTriangles(); ++cIt)
    {
        if(cIt->completeColoring())
        {
            complete_triangles++;
        }
        if(complete_triangles > _req_complete)
        {
            return false;
        }
    }

    return complete_triangles == _req_complete;
}


Solver::Solver(const std::size_t& req_complete, CallbackFunc callback)
    : _req_complete(req_complete)
    , _callback(callback)
{
}


void Solver::recurse(std::size_t& solutions, std::size_t& attempts, Graph& g, Graph::NodeIterator it, Graph::NodeIterator end) const
{
    if(it == end)
    {
        attempts++;
        if(meetsConstraints(g))
        {
            solutions++;
            if(_callback)
            {
                _callback(*this, g);
            }
        }
        return;
    }

    Node& n = *it;
    ++it;
    for(const auto& color : n.permittedColors())
    {
        n.setColor(color);
        recurse(solutions, attempts, g, it, end);
    }
}


void Solver::recurseWithPruning(std::size_t& solutions, std::size_t& attempts, Graph& g, std::size_t& complete_triangles, Graph::NodeIterator it, Graph::NodeIterator end) const
{
    if(it == end)
    {
        attempts++;
        if(meetsConstraints(g))
        {
            solutions++;
            if(_callback)
            {
                _callback(*this, g);
            }
        }
        return;
    }

    Node& n = *it;
    ++it;
    Color original = n.color();
    for(const auto& color : n.permittedColors())
    {
        std::size_t before = g.adjacentCompleteTriangleCount(n);
        n.setColor(color);
        std::size_t after = g.adjacentCompleteTriangleCount(n);
        std::size_t new_complete = (after > before) ? (after - before) : 0;
        complete_triangles += new_complete;
        if(complete_triangles > _req_complete)
        {
            // abort this search branch as constraints are already violated
            complete_triangles -= new_complete;
            continue;
        }
        recurseWithPruning(solutions, attempts, g, complete_triangles, it, end);
        complete_triangles -= new_complete;
    }
    n.setColor(original);
}


} // namespace polygons
