#include <iostream>
#include <cmath>

float InvSqrt(float x) {
    float xhalf = 0.5f * x;
    int i = *(int*)&x;
    i = 0x5f3759df - (i >> 1);
    x = *(float*)&i;
    x = x * (1.5f - xhalf * x * x);
    return x;
}

int main() {
    float number = 25.0f;
    float invFast = InvSqrt(number);
    float invStd = 1.0f / std::sqrt(number);

    std::cout << "Fast InvSqrt: " << invFast << "\n";
    std::cout << "Actual InvSqrt: " << invStd << "\n";
    return 0;
}
