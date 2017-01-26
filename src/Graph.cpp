#include "Graph.hpp"

namespace polygons {


namespace {


static std::vector<Color> getExampleNodePermittedColors(const int& node)
{
    switch(node)
    {
        case 0:
            return {Color::RED};
        case 1:
            return {Color::RED};
        case 2:
            return {Color::YELLOW};
        case 3:
            return {Color::BLUE};
        case 4:
            return {Color::BLUE};
        case 8:
            return {Color::RED};
        case 13:
            return {Color::YELLOW};
        case 18:
            return {Color::YELLOW};
        case 19:
            return {Color::RED};
        case 20:
            return {Color::RED};
        case 21:
            return {Color::BLUE};
        default:
            return {Color::RED, Color::YELLOW, Color::BLUE};
    }
}


static std::vector<Triangle> getExampleGraphTriangulation(std::vector<Node>& nodes)
{
    if(nodes.size() != 22)
    {
        throw std::runtime_error("Expected 22 nodes in example graph.");
    }

    std::vector<Triangle> triangulation;
    triangulation.emplace_back( "0", nodes[17], nodes[18], nodes[21]);
    triangulation.emplace_back( "1", nodes[0],  nodes[4],  nodes[5]);
    triangulation.emplace_back( "2", nodes[0],  nodes[1],  nodes[5]);
    triangulation.emplace_back( "3", nodes[1],  nodes[5],  nodes[6]);
    triangulation.emplace_back( "4", nodes[1],  nodes[2],  nodes[6]);
    triangulation.emplace_back( "5", nodes[2],  nodes[6],  nodes[7]);
    triangulation.emplace_back( "6", nodes[2],  nodes[3],  nodes[7]);
    triangulation.emplace_back( "7", nodes[3],  nodes[7],  nodes[8]);
    triangulation.emplace_back( "8", nodes[4],  nodes[5],  nodes[9]);
    triangulation.emplace_back( "9", nodes[5],  nodes[6],  nodes[9]);
    triangulation.emplace_back("10", nodes[6],  nodes[7],  nodes[11]);
    triangulation.emplace_back("11", nodes[7],  nodes[8],  nodes[11]);
    triangulation.emplace_back("12", nodes[4],  nodes[9],  nodes[13]);
    triangulation.emplace_back("13", nodes[6],  nodes[9],  nodes[10]);
    triangulation.emplace_back("14", nodes[6],  nodes[10], nodes[11]);
    triangulation.emplace_back("15", nodes[8],  nodes[11], nodes[12]);
    triangulation.emplace_back("16", nodes[9],  nodes[13], nodes[14]);
    triangulation.emplace_back("17", nodes[9],  nodes[10], nodes[14]);
    triangulation.emplace_back("18", nodes[10], nodes[11], nodes[16]);
    triangulation.emplace_back("19", nodes[11], nodes[16], nodes[17]);
    triangulation.emplace_back("20", nodes[11], nodes[12], nodes[17]);
    triangulation.emplace_back("21", nodes[8],  nodes[12], nodes[18]);
    triangulation.emplace_back("22", nodes[13], nodes[14], nodes[15]);
    triangulation.emplace_back("23", nodes[10], nodes[14], nodes[15]);
    triangulation.emplace_back("24", nodes[10], nodes[15], nodes[16]);
    triangulation.emplace_back("25", nodes[12], nodes[17], nodes[18]);
    triangulation.emplace_back("26", nodes[13], nodes[15], nodes[19]);
    triangulation.emplace_back("27", nodes[15], nodes[16], nodes[19]);
    triangulation.emplace_back("28", nodes[16], nodes[19], nodes[20]);
    triangulation.emplace_back("29", nodes[16], nodes[17], nodes[20]);
    triangulation.emplace_back("30", nodes[17], nodes[20], nodes[21]);
    return triangulation;
}


} // end anonymous namespace


std::shared_ptr<Graph> Graph::getExampleGraph()
{
    std::vector<Node> nodes;
    for(int i = 0; i < 22; ++i)
    {
        std::vector<Color> permitted_colors = getExampleNodePermittedColors(i);
        nodes.emplace_back(std::to_string(i), std::move(permitted_colors));
    }
    std::shared_ptr<Graph> g = std::make_shared<Graph>("ExampleGraph", std::move(nodes));
    g->calculateTriangulation();
    return g;
}


std::string Graph::label() const
{
    return _label;
}


Graph::TriangleConstIterator Graph::cBeginTriangles() const
{
    if(!_triangulated)
    {
        throw std::logic_error("Call calculateTriangulation() first.");
    }
    return _triangulation.cbegin();
}


Graph::TriangleConstIterator Graph::cEndTriangles() const
{
    if(!_triangulated)
    {
        throw std::logic_error("Call calculateTriangulation() first.");
    }
    return _triangulation.cend();
}


std::size_t Graph::triangleCount() const
{
    return _triangulation.size();
}


void Graph::calculateTriangulation()
{
    // TODO add safety check that this is the example graph
    _triangulation = std::move(getExampleGraphTriangulation(_nodes));
    _triangulated = true;
}


Graph::NodeIterator Graph::beginNodes()
{
    return _nodes.begin();
}


Graph::NodeIterator Graph::endNodes()
{
    return _nodes.end();
}


std::size_t Graph::nodeCount() const
{
    return _nodes.size();
}


Graph::Graph(const std::string& label, std::vector<Node>&& nodes)
    : _label( label )
    , _nodes( nodes )
    , _triangulation()
    , _triangulated( false )
{
}


Graph::~Graph()
{
    // clear _triangulation first, to avoid dangling references
    _triangulation.clear();
    _nodes.clear();
}


std::ostream& operator<<(std::ostream& s, const Graph& g)
{
    s << "Graph '" << g.label() << "':\n"
      << "Node Colors:";
    for(const auto& n : g._nodes)
    {
        s << "\n" << n.label() << ":\t" << n.color();
    }
    return s;
}


} // namespace polygons
