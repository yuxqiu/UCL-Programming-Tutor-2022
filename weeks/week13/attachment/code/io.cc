#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>

int main() {
    // NRW probably
    std::cout << "Hello, World!" << std::endl;
    std::cerr << "Hello cerr!" << std::endl;

    int i;
    double d;
    std::cin >> i >> d;

    std::fstream f = std::fstream("io.cc");

    std::string s;
    while (std::getline(f, s)) {
        std::cout << s << std::endl;
    }

    std::stringstream ss;
    ss << 174982734;
    std::cout << ss.str() << std::endl;

    std::stringstream ss2("1213791391");
    unsigned int uint;
    ss2 >> uint;
    std::cout << uint << std::endl;

    return 0;
}