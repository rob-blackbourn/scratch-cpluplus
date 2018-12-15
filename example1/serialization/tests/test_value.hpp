#ifndef __serialization_tests_test_value_cpp
#define __serialization_tests_test_value_cpp 1

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

#endif // __serialization_tests_test_value_cpp
