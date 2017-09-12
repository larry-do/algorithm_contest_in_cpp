#include <string>
#include <sstream>
        int i;
        float f;
        double d;
        std::string str;

        // string -> integer
        std::istringstream ( str ) >> i;

        // string -> float
        std::istringstream ( str ) >> f;

        // string -> double
        std::istringstream ( str ) >> d;
