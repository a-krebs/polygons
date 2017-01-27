#include <iostream>

#include "Solver.hpp"


namespace polygons {


int Solver::solveRecursive(Graph& g) const
{
    int solutions = 0;
    recurse(solutions, g, g.beginNodes(), g.endNodes());
    return solutions;
}


int Solver::solveRecursiveWithPruning(Graph& g) const
{
    int solutions = 0;
    int complete_triangles = 0;
    recurseWithPruning(solutions, g, complete_triangles, g.beginNodes(), g.endNodes());
    return solutions;
}


int Solver::solveRecursiveWithPruningB(Graph& g) const
{
    int solutions = 0;
    recurseWithPruningB(solutions, g, g.beginNodes(), g.endNodes());
    return solutions;
}


bool Solver::meetsConstraints(const Graph& g) const
{
    std::size_t complete_triangles = 0;

    for(auto cIt = g.cBeginTriangles(); cIt != g.cEndTriangles(); cIt++)
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


void Solver::recurse(int& solutions, Graph& g, Graph::NodeIterator it, Graph::NodeIterator end) const
{
    if(it == end)
    {
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
    it++;
    for(const auto& color : n.permittedColors())
    {
        n.setColor(color);
        recurse(solutions, g, it, end);
    }
}


void Solver::recurseWithPruning(int& solutions, Graph& g, int& complete_triangles, Graph::NodeIterator it, Graph::NodeIterator end) const
{
    if(it == end)
    {
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
    it++;
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
            complete_triangles -= new_complete;
            n.setColor(original);
            continue;
        }
        recurseWithPruning(solutions, g, complete_triangles, it, end);
        n.setColor(original);
        complete_triangles -= new_complete;
    }
}


void Solver::recurseWithPruningB(int& solutions, Graph& g, Graph::NodeIterator it, Graph::NodeIterator end) const
{
    if(it == end)
    {
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
    it++;
    Color original = n.color();
    for(const auto& color : n.permittedColors())
    {
        n.setColor(color);
        std::size_t complete = 0;
        for(auto cIt = g.cBeginTriangles(); cIt != g.cEndTriangles(); cIt++)
        {
            if(cIt->completeColoring())
            {
                complete++;
            }
        }
        if(complete > _req_complete)
        {
            n.setColor(original);
            continue;
        }
        recurseWithPruningB(solutions, g, it, end);
        n.setColor(original);
    }
}


} // namespace polygons
