#include <iostream>

#include "Solver.hpp"


namespace polygons {


int Solver::solve(Graph& g) const
{
    int solutions = 0;
    recurse(solutions, g, g.beginNodes(), g.endNodes());
    return solutions;
}


void Solver::recurse(int& solutions, Graph& g, Graph::NodeIterator it, Graph::NodeIterator end) const
{
    if(it == end)
    {
        if(meetsConstraints(g))
        {
            //std::cout << g << std::endl;
            solutions++;
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


Solver::Solver(const std::size_t& req_complete)
    : _req_complete(req_complete)
{
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


} // namespace polygons
