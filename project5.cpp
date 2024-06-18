#include <iostream>
#include <cmath>

class Shape {
    public: 
    virtual double get_area() const = 0;
};

class Circle : public Shape {
    private: double radius;
    public: 
    Circle(double r) : radius(r) {}

    double get_radius() const {
        return radius;
    }
    void set_radius(double r) {
        radius = r;
    }
    double get_area() const override {
        return radius * radius * 3.14;
    }

};
class Square : public Shape {
private:
    double width;
public:
Square(double w) : width (w) {}
double get_width() const {
    return width;
}
void set_width(double w) {
    width = w;
}
double get_area() const override {
    return width * width;
}

};
class Rectangle : public Square {
private: 
    double height;
public:
    Rectangle(double w, double h) : Square(w), height(h) {}
    
    double get_height() const {
        return height;
    }
    void set_height(double h) {
        height = h;
    }
    double get_area() const override {
        return get_width() * height;
    }
};
void display_area(const Shape& shape) {
    std::cout << "Area: " << shape.get_area() << std:: endl;
}
int main () {
    char choice;
    do {
        std::cout << "The Area Calculator\n";
        std::cout << "Circle, square, or rectangle? (c/s/r): ";
        std::cin >> choice;

        if (choice == 'c') {
            double radius;
            std::cout << "Enter radius: ";
            std::cin >> radius;
            Circle circle(radius);
            display_area(circle);
        } else if (choice == 's') {
            double width;
            std::cout << "Enter width: ";
            std::cin >> width;
            Square square(width);
            display_area(square);
        } else if (choice == 'r') {
            double width, height;
            std::cout << "Enter width: ";
            std::cin >> width;
            std::cout << "Enter height: ";
            std::cin >> height;
            Rectangle rectangle(width, height);
            display_area(rectangle);

        } else{
            std::cout << "Invalid choice. Please enter c, s, or r.\n";
            continue;
        }
        std::cout << "Continue? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y');
    std::cout << "Thank you for using my app!\n";
    return 0;
}