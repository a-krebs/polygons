#pragma once

#include <iostream>


namespace polygons {


/**
 * Possible colors to use for nodes/vertices.
 * Can be compared as flags/bitmask.
 */
enum class Color : std::uint8_t
{
    NONE   = 0x00,
    RED    = 0x01,
    YELLOW = 0x02,
    BLUE   = 0x04
};


inline Color operator|(const Color& lhs, const Color& rhs)
{
    using T = std::underlying_type<Color>::type;
    return Color(static_cast<T>(lhs) | static_cast<T>(rhs));
}


inline std::ostream& operator<<(std::ostream& s, const Color& c)
{
    switch(c)
    {
        case Color::NONE:
            s << "NONE";
            return s;
        case Color::RED:
            s << "RED";
            return s;
        case Color::YELLOW:
            s << "YELLOW";
            return s;
        case Color::BLUE:
            s << "BLUE";
            return s;
        default:
            throw std::runtime_error("Not Implemented.");
    }
    return s;
}


} // namespace polygons
