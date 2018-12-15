#include <array>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "serialization/native.hpp"
#include "serialization/string.hpp"
#include "serialization/boost/uuid/uuid.hpp"

bool test_uuid()
{
    auto generator = boost::uuids::random_generator();
    boost::uuids::uuid source(generator());

    std::vector<char> v(serialize_size(source));
    std::vector<char>::iterator viter(v.begin());

    viter << source;

    boost::uuids::uuid destination;
    std::vector<char>::const_iterator vconstiter(v.begin());

    vconstiter >> destination;

    return source == destination;
}

int main()
{
    bool ok = true;

    ok = ok && test_uuid();

    return ok ? 0 : 1;
}