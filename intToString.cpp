#include <sstream>
#include <string>

int main() {
    int x = 5;
    std::ostringstream stream;
    stream << x;
    std::string x_str = stream.str();
    return 0;
}
