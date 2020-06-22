#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

class Fraction{
    public:
        int numerator,denominator;
        Fraction(){}
        Fraction(int n, int d) : numerator(n), denominator(d){}
        Fraction& reduce(){
            int gcd = std::__gcd(std::abs(numerator), std::abs(denominator));
            if(gcd > 1){
                numerator /= gcd;
                denominator /= gcd;
            } 
            return *this;
        }
        bool isEqual(const Fraction &fraction) const{
            return numerator == fraction.numerator && denominator == fraction.denominator;
        }
};

class Line{
    int a,b,c; // ax + by = c
    
    public:
        Line(){}
        Line(int _a, int _b, int _c) : a(_a), b(_b), c(_c){}
        
        friend std::istream& operator >> (std::istream&, Line&);
        friend std::ostream& operator << (std::ostream&, Line&);
        
        bool isZero() const{
            return !a && !b && !c;
        }

        Fraction slope() const{
            return Fraction(-a,b).reduce();
        }

        bool isParallel(const Line &line) const{
            Fraction slopeLine1 = this -> slope(); 
            Fraction slopeLine2 = line.slope();
            return slopeLine1.isEqual(slopeLine2);
        }

        void printIntersection(const Line &line) const{
            int determinant = a * line.b - b * line.a;
            if(determinant){
                int d_x = c * line.b - line.c * b;
                int d_y = a * line.c - line.a * c;
                double x = static_cast<double>(d_x) / determinant;
                double y = static_cast<double>(d_y) / determinant;
                std::cout << "The fixed point is at " << std::fixed << std::setprecision(2) << x << " " << std::setprecision(2) << y << ".\n";
            } else{
                std::cout << "No fixed point exists.\n";
            }
        }
};

std::istream& operator >> (std::istream &is, Line &line){
    is >> line.a >> line.b >> line.c;
    return is;
}

std::ostream& operator << (std::ostream& os, Line &line){
    os << "a: " << line.a << " b: " << line.b << " c: " << line.c;
    return os;
}

int main(int argc, char const *argv[])
{
    Line line1,line2;
    while(std::cin >> line1 >> line2){
        if(line1.isZero() && line2.isZero()) break;
        if(line1.isParallel(line2)){
            std::cout << "No fixed point exists.\n";
        } else{
            line1.printIntersection(line2);
        }
    }
    return 0;
}
