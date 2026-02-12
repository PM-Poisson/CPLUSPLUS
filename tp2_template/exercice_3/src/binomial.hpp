#pragma once
#ifndef BINOMIAL_HPP
#define BINOMIAL_HPP

constexpr int binomial(int n, int k) {
    return (k == 0 || k == n) ? 1 : binomial(n-1, k-1) + binomial(n-1, k);
}

#endif
