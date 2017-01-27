#include <cmath>
#include "gtest/gtest.h"

#include "Solver.hpp"


namespace polygons {


TEST(Solver, CompareAlgorithms)
{
    Graph g1 = Graph::getExampleGraph();
    Graph g2 = Graph::getExampleGraph();

    // use 3, since that actually has solutions
    Solver s(3, Solver::CallbackFunc());

    std::size_t solutions1 = s.solveRecursive(g1);
    std::size_t solutions2 = s.solveRecursiveWithPruning(g2);
    EXPECT_EQ(solutions1, solutions2);
}


// non-pruning algorithm should try all 3^11 possible colorings of the uncolored nodes
TEST(Solver, NonPruningColorings)
{
    Graph g = Graph::getExampleGraph();

    // solver constraint here doesn't matter
    Solver s(2, Solver::CallbackFunc());

    std::size_t solutions = 0;
    std::size_t attempts = 0;
    s.recurse(solutions, attempts, g, g.beginNodes(), g.endNodes());

    std::size_t expected = std::pow(3,11);
    EXPECT_EQ(expected, attempts);
}


} // namespace polygons
