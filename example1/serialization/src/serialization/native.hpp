#ifndef __serialization_native_hpp
#define __serialization_native_hpp 1

#include <vector>

size_t serialize_size(bool value) noexcept;
std::vector<char>::const_iterator &operator>>(std::vector<char>::const_iterator &iter, bool &value);
std::vector<char>::iterator &operator<<(std::vector<char>::iterator &iter, bool value);

size_t serialize_size(unsigned char value) noexcept;
std::vector<char>::const_iterator &operator>>(std::vector<char>::const_iterator &iter, unsigned char &value);
std::vector<char>::iterator &operator<<(std::vector<char>::iterator &iter, unsigned char value);

size_t serialize_size(char value) noexcept;
std::vector<char>::const_iterator &operator>>(std::vector<char>::const_iterator &iter, char &value);
std::vector<char>::iterator &operator<<(std::vector<char>::iterator &iter, char value);

size_t serialize_size(unsigned int value) noexcept;
std::vector<char>::const_iterator &operator>>(std::vector<char>::const_iterator &iter, unsigned int &value);
std::vector<char>::iterator &operator<<(std::vector<char>::iterator &iter, unsigned int value);

size_t serialize_size(int value) noexcept;
std::vector<char>::const_iterator &operator>>(std::vector<char>::const_iterator &iter, int &value);
std::vector<char>::iterator &operator<<(std::vector<char>::iterator &iter, int value);

size_t serialize_size(size_t value) noexcept;
std::vector<char>::const_iterator &operator>>(std::vector<char>::const_iterator &iter, size_t &value);
std::vector<char>::iterator &operator<<(std::vector<char>::iterator &iter, size_t value);

size_t serialize_size(const char* value) noexcept;
std::vector<char>::const_iterator &operator>>(std::vector<char>::const_iterator &iter, char*& value);
std::vector<char>::iterator &operator<<(std::vector<char>::iterator &iter, const char* value);

#endif // __serialization_native_hpp
