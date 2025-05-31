#include <iostream>

struct Rectangle {
    int x1, y1, x2, y2;
};

bool doRectanglesIntersect(Rectangle A, Rectangle B) {
    if (A.x2 <= B.x1 || B.x2 <= A.x1) return false;
    if (A.y2 <= B.y1 || B.y2 <= A.y1) return false;
    return true;
}

int main() {
    Rectangle A = {0, 0, 4, 4};
    Rectangle B = {2, 2, 6, 6};
    Rectangle C = {5, 5, 8, 8};

    std::cout << "A & B intersect: " << (doRectanglesIntersect(A, B) ? "Yes" : "No") << "\n";
    std::cout << "A & C intersect: " << (doRectanglesIntersect(A, C) ? "Yes" : "No") << "\n";
    return 0;
}
