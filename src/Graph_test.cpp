#include <set>
#include "gtest/gtest.h"

#include "Graph.hpp"


namespace polygons {


// test adjacency of an arbitrary node
TEST(Graph, Adjacency)
{
    Graph g = Graph::getExampleGraph();

    const auto& triangles = g._adjacency.at("15");
    std::set<std::string> expected_labels;
    expected_labels.insert("22");
    expected_labels.insert("23");
    expected_labels.insert("24");
    expected_labels.insert("26");
    expected_labels.insert("27");

    std::set<std::string> actual_labels;
    for(const Triangle* t : triangles)
    {
        actual_labels.insert(t->label());
    }

    EXPECT_EQ(expected_labels, actual_labels);
}


} // namespace polygons
