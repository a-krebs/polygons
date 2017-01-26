#pragma once

#include <cstddef>
#include <memory>

#include "Graph.hpp"


namespace polygons {


class Solver
{
// public interface
public:
    int solve(Graph& g) const;

    void recurse(int& solutions, Graph& g, std::size_t index) const;

// constructors, etc.
public:
    // TODO docs
    Solver(const std::size_t& req_complete);

// private interface
private:
    bool meetsConstraints(const Graph& g) const;

// data members
private:
    std::size_t _req_complete;
};


} // namespace polygons
