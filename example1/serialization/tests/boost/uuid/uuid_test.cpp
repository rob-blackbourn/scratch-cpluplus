#include <vector>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "serialization/boost/uuid/uuid.hpp"

#include "../../test_value.hpp"

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