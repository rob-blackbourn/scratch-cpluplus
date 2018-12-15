#include <array>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "serialization/native.hpp"
#include "serialization/string.hpp"

bool test_int(int i)
{
    std::vector<char> v(4);
    std::vector<char>::iterator viter(v.begin());

    viter << i;

    int j = 0;
    std::vector<char>::const_iterator vconstiter(v.begin());

    vconstiter >> j;

    return i == j;
}

void test_string()
{
    std::string s1 = "123456789";
    std::vector<char> v(sizeof(size_t) + s1.size());
    std::vector<char>::iterator viter(v.begin());

    viter << s1;

    std::string s2;
    std::vector<char>::const_iterator vconstiter(v.begin());

    vconstiter >> s2;
    std::cout << "s1=" << s1 << ", s2=" << s2 << std::endl;
}

int main()
{
    bool ok = true;

    ok = ok && test_int(0);
    ok = ok && test_int(1);
    ok = ok && test_int(-1);
    ok = ok && test_int(std::numeric_limits<int>::min());
    ok = ok && test_int(std::numeric_limits<int>::max());

    test_string();

    return ok ? 0 : 1;
}