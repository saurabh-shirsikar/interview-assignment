#include <iostream>
#include <vector>
#include <cmath>

double sampleFunction(double x) {
    return std::sin(x);
}

int trapAnalogRainWater(double start, double end, double step) {
    std::vector<double> heights;
    for (double x = start; x <= end; x += step) heights.push_back(sampleFunction(x));
    int n = heights.size();
    std::vector<double> leftMax(n), rightMax(n);
    double water = 0.0;
    leftMax[0] = heights[0];
    for (int i = 1; i < n; ++i) leftMax[i] = std::max(leftMax[i - 1], heights[i]);
    rightMax[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; --i) rightMax[i] = std::max(rightMax[i + 1], heights[i]);
    for (int i = 0; i < n; ++i) {
        double trapped = std::min(leftMax[i], rightMax[i]) - heights[i];
        if (trapped > 0) water += trapped;
    }
    return static_cast<int>(round(water / step));
}

int main() {
    int trapped = trapAnalogRainWater(0.0, 6.28, 0.1);
    std::cout << "Approx water trapped (analog): " << trapped << " units\n";
    return 0;
}
