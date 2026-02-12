#pragma once
#ifndef EXPORT_MATLAB_HPP
#define EXPORT_MATLAB_HPP

#include <fstream>
#include <vector>
#include <string>
#include "bezier.hpp"
#include "vec2.hpp"

/**
 * Export a Bézier curve to MATLAB.
 * Works for any T (vec2) and any degree N at compile time.
 */
template<typename T, int N>
void export_matlab(const std::string& filename, const bezier<T, N>& curve, int N_sample = 100) {
    std::ofstream ofs(filename);
    if(!ofs.is_open())
        throw std::runtime_error("Cannot open file: " + filename);

    // Compute N_sample points along the curve
    std::vector<T> points(N_sample);
    for(int i=0; i<N_sample; ++i) {
        float s = float(i)/(N_sample-1);
        points[i] = curve(s);
    }

    // Write x and y coordinates
    ofs << "curve = [\n";
    for(int dim=0; dim<2; ++dim) {
        for(int i=0; i<N_sample; ++i) {
            ofs << (dim==0 ? points[i].x : points[i].y) << " ";
        }
        ofs << ";\n";
    }
    ofs << "];\n";

    // Write control polygon
    ofs << "polygon = [\n";
    for(int dim=0; dim<2; ++dim) {
        for(int k=0; k<=N; ++k) {
            ofs << (dim==0 ? curve.coeff(k).x : curve.coeff(k).y) << " ";
        }
        ofs << ";\n";
    }
    ofs << "];\n";
}

#endif
