#include "vec2.hpp"
#include "bezier.hpp"
#include "export_matlab.hpp"
#include <array>

int main() {
    std::array<vec2, 4+1> pts = {{
        {0,0}, {1,2}, {2,3}, {3,1}, {4,0}
    }};

    bezier<vec2, 4> curve(pts);
    export_matlab("data.m", curve, 200);

    return 0;
}
