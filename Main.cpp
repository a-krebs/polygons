#include <iostream>

#include "Graph.hpp"
#include "Solver.hpp"


using polygons::Graph;
using polygons::Solver;

int main( int argc, char **argv )
{
    std::cout << "Starting." << std::endl;

    Graph g = Graph::getExampleGraph();

    // called once for each solution
    auto callback = [](const Solver& solver, const Graph& g)
        {
            std::cout << g << std::endl;
        };

    // find exactly solutions with exactly two complete triangles
    Solver s(2, callback);

    int solutions = s.solveRecursiveWithPruning(g);
    std::cout << std::to_string(solutions) << " solutions found." << std::endl;
    return true;
}
