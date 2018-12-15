#include <limits>
#include <string>
#include <vector>

#include "serialization/native.hpp"
#include "serialization/string.hpp"

template<typename T>
inline
bool test_value(const T& value)
{
    std::vector<char> buf(serialize_size(value));
    std::vector<char>::iterator viter(buf.begin());

    viter << value;

    T roundtrip;
    std::vector<char>::const_iterator vconstiter(buf.begin());

    vconstiter >> roundtrip;

    return value == roundtrip && viter == buf.end() && vconstiter == buf.end();
}

int main()
{
    bool ok = true;

    ok = ok && test_value(0);
    ok = ok && test_value(1);
    ok = ok && test_value(-1);
    ok = ok && test_value(std::numeric_limits<int>::min());
    ok = ok && test_value(std::numeric_limits<int>::max());
    ok = ok && test_value(std::numeric_limits<size_t>::min());
    ok = ok && test_value(std::numeric_limits<size_t>::max());

    ok = ok && test_value(std::string());
    ok = ok && test_value(std::string(""));
    ok = ok && test_value(std::string("This is not a test"));

    return ok ? 0 : 1;
}