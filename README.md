# Triangulating Polygons

This project is an algorithm to solve the following problem:

Draw a polygon of any number of sides. Place a colored dot at each of the corners,
and then place any number of dots at random on the inside. Then, using the dots
as corners, divide the polygon into non-overlapping triangles and label their
corners using three colors, red blue and yellow.

A triangle having all three colors at its vertices is a complete triangle.

In the example `example.jpg`, the border dots are already colored. Is it possible
to color the inside dots to create two complete triangles and no more?


# Dependencies & Build Steps

The following tools are confirmed to work:
```
g++ 5.4.0
cmake 3.5.1
```

To build:
```
cd <path to source>
mkdir release
cd release
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```

# Output

The built binary will attempt to find all solutions to the above stated problem
and print them to console.

Refer to labels added to each dot and triangle in `example_annotated.png`.

Example output:
```
$ ./polygons 
Starting.
0 solutions found.
```


# Solution Discussion

I identified this problem as a variant of the eight-queens problem (placing
eight chess queens on an 8×8 chessboard so that no two queens threaten each other).

This leaves the usual solutions for this problem; I opted to implement a recursive
backtracking algorithm. To start, an implementation that assigned a color
to each uncolored node in the graph, and then checks for validity of the solution.

Second, an implementation that stops searching a branch as soon as the coloring violates
the problem constraints (exactly two complete triangles). To stop searching early,
the algorithm determines if setting a color adds any complete triangles to the graph
at each iteration. To make this efficient, only triangles adjacent to the node
being colored are inspected (further discussion in Improvements, below).

Before beginning the implementation, I tried to think of a way to simplify the
problem to a space that allows the application of algorithms with better complexity.
Any algorithm that tries all colorings is bound on the number of uncolored dots
(and their color options). With larger graphs, this means a complexity of `O(3^n)`,
where `n` is the number of uncolored dots. As I could not simplify this problem,
my implementation also has this complexity.


# Improvements

Some performance improvements are possible. Specifically, `class Graph` uses
a hashmap to track which instances of `Node` are adjacent to which `Triangle`.
Wrapping `Node` in an `IndexAwareNode` class could allow the use of index into
a vector instead of a hashmap and improve performance. However, further work would
need to be done to `NodeIterator` and other places to encapsulate the `IndexAwareNode`
class as an implementation detail of `Graph`.
