#include "serialization/string.hpp"

size_t serialize_size(const std::string& value) noexcept
{
    return sizeof(size_t) + value.size();
}