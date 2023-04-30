#include "Converter8Bit.hpp"
#include "ConverterInt.hpp"
#include "ConverterFloat.hpp"

int main()
{
    Converter8Bit   bit_converter;
    ConverterInt    int_converter;
    ConverterFloat  float_converter;
    
    std::cout << "Testing 8 Bit converter\n" << std::endl;

    std::cout << "Input: 11110000   Output: " << bit_converter.convert("11110000") << std::endl;
    std::cout << "Input: 10010110   Output: " << bit_converter.convert("10010110") << std::endl;
    std::cout << "Input: 11110000   Output: " << bit_converter.convert("01010100") << std::endl;
    std::cout << "Input: 11110000   Output: " << bit_converter.convert("00000000") << std::endl;
    std::cout << "Input: 11110000   Output: " << bit_converter.convert("11111111") << std::endl;

    std::cout << "Testing 32 Bit Integer converter\n" << std::endl;

    std::cout << "Input: 1111000011110000   Output: " << int_converter.convert("1111000011110000") << std::endl;
    std::cout << "Input: 1001000011010000   Output: " << int_converter.convert("1001000011010000") << std::endl;
    std::cout << "Input: 1110001011110110   Output: " << int_converter.convert("1110001011110110") << std::endl;
    std::cout << "Input: 000000001111000011110000   Output: " << int_converter.convert("000000001111000011110000") << std::endl;
    std::cout << "Input: 10101010111100001111000010101010   Output: " << int_converter.convert("10101010111100001111000010101010") << std::endl;

    std::cout << "Testing Floating point converter\n" << std::endl;

    std::cout << "Input: 111100.0011110000   Output: " << float_converter.convert("111100.0011110000") << std::endl;
    std::cout << "Input: 1010111100.00111000   Output: " << float_converter.convert("1010111100.00111000") << std::endl;
    std::cout << "Input: 1111000011110.110   Output: " << float_converter.convert("1111000011110.110") << std::endl;
    std::cout << "Input: 1.0011110000   Output: " << float_converter.convert("1.0011110000") << std::endl;
    std::cout << "Input: 000111111100.1110000   Output: " << float_converter.convert("000111111100.11110000") << std::endl;

    return 0;
}
