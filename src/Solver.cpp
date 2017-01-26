#include <iostream>

#include "Solver.hpp"


namespace polygons {


int Solver::solve(Graph& g) const
{
    int solutions = 0;
    recurse(solutions, g.nodes(), 0);
    return solutions;
}


void Solver::recurse(int& solutions, std::vector<Node>& nodes, std::size_t index) const
{
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
