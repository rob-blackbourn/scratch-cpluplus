#include <limits>
#include <string>
#include <vector>

#include "serialization/native.hpp"

#include "test_value.hpp"

int main()
{
    bool ok = true;

    // bool
    ok = ok && test_value(true);
    ok = ok && test_value(false);

    // unsigned char
    ok = ok && test_value(std::numeric_limits<unsigned char>::min());
    ok = ok && test_value(std::numeric_limits<unsigned char>::max());

    // char
    ok = ok && test_value(static_cast<char>(0));
    ok = ok && test_value(static_cast<char>(1));
    ok = ok && test_value(static_cast<char>(-1));
    ok = ok && test_value(std::numeric_limits<char>::min());
    ok = ok && test_value(std::numeric_limits<char>::max());

    // unsigned int
    ok = ok && test_value(std::numeric_limits<unsigned int>::min());
    ok = ok && test_value(std::numeric_limits<unsigned int>::max());

    // int
    ok = ok && test_value(0);
    ok = ok && test_value(1);
    ok = ok && test_value(-1);
    ok = ok && test_value(std::numeric_limits<int>::min());
    ok = ok && test_value(std::numeric_limits<int>::max());

    // size_t
    ok = ok && test_value(std::numeric_limits<size_t>::min());
    ok = ok && test_value(std::numeric_limits<size_t>::max());

    return ok ? 0 : 1;
}