#pragma once

#include <string>
#include <vector>

#include "Color.hpp"
#include "Labeled.hpp"


namespace polygons {


/**
 * \brief A node in a graph, or the vertex of a Triangle.
 */
class Node : public Labeled
{
// public interface
public:

    /**
     * \return the color of this Node.
     * \warning Returns a reference, be sure to copy correctly as needed.
     */
    const Color& color() const;

    /**
     * \brief Set the color.
     *
     * \param color Must be a single color, not a combination of flags.
     * \throws std::runtime_error if the color is a combination of color flags,
     *                            or the color is not a permitted color.
     */
    void setColor(const Color& color);

    /**
     * \brief A list of colors this node is permitted to be.
     */
    const std::vector<Color>& permittedColors() const;

// constructors, etc.
public:

    /**
     * \brief Construct a new Node.
     *
     * \param label     The Node's name.
     * \param permitted The list of colors this node is permitted to have.
     */
    Node(const std::string& label, std::vector<Color>&& permitted);

// data members
private:
    std::vector<Color> _permitted_colors;
    Color _permitted_color_mask;
    Color _color;
};


} // namespace polygons
