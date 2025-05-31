#include <iostream>
#include <vector>
#include <algorithm>

int trapRainWater(const std::vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    std::vector<int> leftMax(n), rightMax(n);
    int water = 0;
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) leftMax[i] = std::max(leftMax[i - 1], height[i]);
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) rightMax[i] = std::max(rightMax[i + 1], height[i]);
    for (int i = 0; i < n; ++i) water += std::min(leftMax[i], rightMax[i]) - height[i];
    return water;
}

int main() {
    std::vector<int> heights = {2, 1, 3, 0, 1, 2, 3};
    std::cout << "Water trapped: " << trapRainWater(heights) << " units\n";
    return 0;
}
