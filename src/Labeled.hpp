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
     * \warning Returns a reference, be sure to copy correctly as needed.
     */
    const std::string& label() const;

// constructors, etc.
public:
    Labeled(const std::string& label);

// data members
private:
    std::string _label;
};


} // namespace polygons
