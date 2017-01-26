#include <iostream>

#include "Solver.hpp"


namespace polygons {


int Solver::solve(Graph& g) const
{
    int solutions = 0;
    recurse(solutions, g, 0);
    return solutions;
}


void Solver::recurse(int& solutions, Graph& g, std::size_t index) const
{
    if(index >= g.nodes().size())
    {
        if(meetsConstraints(g))
        {
            //std::cout << g << std::endl;
            solutions++;
        }
        return;
    }

    Node& n = g.nodes().at(index);
    for(const auto& color : n.permittedColors())
    {
        n.setColor(color);
        recurse(solutions, g, index+1);
    }
}


Solver::Solver(const std::size_t& req_complete)
    : _req_complete(req_complete)
{
}


bool Solver::meetsConstraints(const Graph& g) const
{
    std::size_t complete_triangles = 0;

    for(const auto& t : g.triangulation())
    {
        if(t.completeColoring())
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
