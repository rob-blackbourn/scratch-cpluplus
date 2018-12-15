#include <limits>
#include <string>
#include <vector>

#include "serialization/string.hpp"

#include "test_value.hpp"

int main()
{
    bool ok = true;

    ok = ok && test_value(std::string());
    ok = ok && test_value(std::string(""));
    ok = ok && test_value(std::string("This is not a test"));

    return ok ? 0 : 1;
}