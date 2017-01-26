#include <iostream>

#include "Graph.hpp"
#include "Solver.hpp"


using polygons::Graph;
using polygons::Solver;

int main( int argc, char **argv )
{
    std::cout << "Starting." << std::endl;
    std::shared_ptr<Graph> g = Graph::getExampleGraph();
    Solver s(2);
    int solutions = s.solve(*g);
    std::cout << "Finished." << std::endl;
    std::cout << std::to_string(solutions) << " solutions found." << std::endl;
    return true;
}
