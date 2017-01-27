#include "Labeled.hpp"


namespace polygons {


const std::string& Labeled::label() const
{
    return _label;
}


Labeled::Labeled(const std::string& label)
    : _label(label)
{
}


} // namespace polygons
