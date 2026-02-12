#ifndef EXPORT_MATLAB_HPP
#define EXPORT_MATLAB_HPP

#include <fstream>
#include <string>
#include <type_traits>
#include "bezier.hpp"

// =========================
// Détection dimension
// =========================

template<typename T>
struct dimension {
    static const int value = std::is_arithmetic<T>::value ? 1 : 2;
};

// Spécialisation Vec3
template<>
struct dimension<class Vec3> {
    static const int value = 3;
};

// =========================
// Export
// =========================

template<typename T>
void export_matlab(const bezier<T>& b,
                   const std::string& filename,
                   int N = 100)
{
    std::ofstream file(filename);
    if(!file)
        throw std::runtime_error("Cannot open file");

    const int dim = dimension<T>::value;

    file << "curve = [\n";

    for(int d = 0; d < dim; ++d)
    {
        for(int i = 0; i <= N; ++i)
        {
            float s = static_cast<float>(i)/N;
            T val = b(s);

            if constexpr (std::is_arithmetic<T>::value)
            {
                file << val;
            }
            else
            {
                if(d == 0) file << val.x;
                if(d == 1) file << val.y;
                if constexpr (dim == 3)
                    if(d == 2) file << val.z;
            }

            if(i != N) file << " ";
        }
        file << ";\n";
    }

    file << "];\n\npolygon = [\n";

    for(int d = 0; d < dim; ++d)
    {
        for(int i = 0; i < 4; ++i)
        {
            T val = b.coeff(i);

            if constexpr (std::is_arithmetic<T>::value)
            {
                file << val;
            }
            else
            {
                if(d == 0) file << val.x;
                if(d == 1) file << val.y;
                if constexpr (dim == 3)
                    if(d == 2) file << val.z;
            }

            if(i != 3) file << " ";
        }
        file << ";\n";
    }

    file << "];\n";

    file.close();
}

#endif
