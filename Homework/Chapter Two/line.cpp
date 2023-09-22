#include <iostream>
#include <stdexcept>

class Parallel : public std::exception {
public:
    const char* what() const noexcept override {
        return "Parallel";
    }
};

class Line {
    double a, b;

public:
    Line(double a, double b) : a(a), b(b) {}

    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }

    double intersect(const Line& other) const {
        if (this->a == other.a) {
            throw Parallel();
        }
        return (other.b - this->b) / (this->a - other.a);
    }
};

int main() {
    try {
        Line line1(2.0, 1.0); 
        Line line2(-3.0, 5.0); 

        double intersectionX = line1.intersect(line2);
        std::cout << "Intersection at x = " << intersectionX << std::endl;
    } catch (const Parallel& e) {
        std::cerr << "Error: Lines are parallel" << std::endl;
    }

    return 0;
}
