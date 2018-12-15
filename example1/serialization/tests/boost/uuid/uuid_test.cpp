#include <vector>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "serialization/boost/uuid/uuid.hpp"

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

bool test_uuid()
{
    bool ok = true;
    auto generator = boost::uuids::random_generator();
    for (int i = 0; i < 100; ++i)
        ok = ok && test_value(boost::uuids::uuid(generator()));
    return ok;
}

int main()
{
    bool ok = true;

    ok = ok && test_uuid();

    return ok ? 0 : 1;
}