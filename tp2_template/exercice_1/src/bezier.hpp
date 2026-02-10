#ifndef BEZIER_HPP
#define BEZIER_HPP

class bezier {
    float P[4];
    
public :
    bezier();
    bezier(float p0, float p1, float p2, float p3);
    float coeff(int i) const;
    float& coeff(int i);
    float operator()(float s) const;
    friend std::ostream& operator<<(std::ostream& os, const bezier& b);
};

#endif