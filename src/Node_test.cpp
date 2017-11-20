#include "gtest/gtest.h"

#include "Node.hpp"


namespace polygons {


TEST(Node, SetColor)
{
    Node n("test_node", {Color::RED});
    EXPECT_THROW(
            n.setColor(Color::BLUE),
            std::runtime_error
        );
    EXPECT_EQ(Color::NONE, n.color());
    EXPECT_THROW(
            n.setColor(Color::YELLOW),
            std::runtime_error
        );
    EXPECT_EQ(Color::NONE, n.color());
    EXPECT_NO_THROW(n.setColor(Color::RED));
    EXPECT_EQ(Color::RED, n.color());
}


} // namespace polygons
