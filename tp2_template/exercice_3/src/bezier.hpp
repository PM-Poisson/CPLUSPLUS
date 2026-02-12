#pragma once
#ifndef BEZIER_HPP
#define BEZIER_HPP

#include <array>
#include <stdexcept>
#include <cmath>
#include <ostream>

/** Bézier curve of degree N */
template<typename T, int N>
class bezier {
    std::array<T,N+1> P;

public:
    bezier() : P{} {}
    bezier(const std::array<T,N+1>& pts) : P(pts) {}

    const T& coeff(int i) const {
        if(i<0||i>N) throw std::out_of_range("Bezier control point index out of range");
        return P[i];
    }
    T& coeff(int i) {
        if(i<0||i>N) throw std::out_of_range("Bezier control point index out of range");
        return P[i];
    }

    /** Evaluate curve at parameter s in [0,1] */
    T operator()(float s) const {
        if(s<0.0f||s>1.0f) throw std::out_of_range("s must be in [0,1]");
        T result{};
        for(int k=0;k<=N;++k){
            result += P[k] * (binomial(N,k) * std::pow(s,k) * std::pow(1.0f-s,N-k));
        }
        return result;
    }

private:
    /** Binomial coefficient at runtime (simple factorial formula) */
    static int binomial(int n,int k){
        if(k<0||k>n) return 0;
        if(k==0||k==n) return 1;
        int res=1;
        for(int i=1;i<=k;++i){
            res = res * (n - i + 1) / i;
        }
        return res;
    }

    // Optional: for debugging
public:
    friend std::ostream& operator<<(std::ostream& os,const bezier<T,N>& b){
        os<<"Bezier<"<<N<<"> : ";
        for(int i=0;i<=N;++i) os<<b.coeff(i)<<" ";
        return os;
    }
};

#endif
