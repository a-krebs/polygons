#pragma once

#include <string>


namespace polygons {


/**
 * \brief Base class for things that have a label string.
 */
class Labeled
{
// public interface
public:

    /**
     * \return The label of this instance.
     */
    std::string label() const;

// constructors, etc.
public:
    Labeled(const std::string& label);

// data members
private:
    std::string _label;
};


} // namespace polygons
