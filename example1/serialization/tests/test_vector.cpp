#include <limits>
#include <string>
#include <vector>

#include "serialization/string.hpp"
#include "serialization/vector.hpp"

#include "test_value.hpp"

int main()
{
    bool ok = true;

    ok = ok && test_value(std::vector<std::string>());
    ok = ok && test_value(std::vector<std::string>{std::string("Hello"), std::string("World")});

    return ok ? 0 : 1;
}