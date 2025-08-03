#include "incs/Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main()
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point inside(3.0f, 3.0f);  // Should be inside the triangle.
    Point onEdge(0.0f, 5.0f);   // Lies on edge AC; should return false.
    Point outside(10.0f, 10.0f); // Clearly outside; should return false.

    std::cout << "Testing triangle vertices:" << std::endl;
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    std::cout << "C: " << c << std::endl << std::endl;

    // Test the point strictly inside the triangle.
    std::cout << "Test: Point (3, 3) ";
    if (bsp(a, b, c, inside))
        std::cout << "is inside the triangle." << std::endl;
    else
        std::cout << "is NOT inside the triangle." << std::endl;

    // Test the point on the edge of the triangle.
    std::cout << "Test: Point (0, 5) ";
    if (bsp(a, b, c, onEdge))
        std::cout << "is inside the triangle." << std::endl;
    else
        std::cout << "is NOT inside the triangle." << std::endl;

    // Test the point outside the triangle.
    std::cout << "Test: Point (10, 10) ";
    if (bsp(a, b, c, outside))
        std::cout << "is inside the triangle." << std::endl;
    else
        std::cout << "is NOT inside the triangle." << std::endl;

    return 0;
}