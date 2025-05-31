#include <iostream>
#include <string>

std::string basicCompressor(const std::string& input) {
    std::string compressed;
    int count = 1;
    for (size_t i = 1; i <= input.length(); ++i) {
        if (i < input.length() && input[i] == input[i - 1]) ++count;
        else {
            compressed += input[i - 1] + std::to_string(count);
            count = 1;
        }
    }
    return compressed;
}

std::string secondCompressor(const std::string& input) {
    std::string optimized;
    size_t i = 0;
    while (i < input.size()) {
        char ch = input[i++];
        std::string count;
        while (i < input.size() && isdigit(input[i])) count += input[i++];
        if (count == "1") optimized += ch;
        else optimized += ch + count;
    }
    return optimized;
}

std::string decompressor(const std::string& input) {
    std::string result;
    for (size_t i = 0; i < input.size(); ++i) {
        char ch = input[i];
        std::string count;
        while (i + 1 < input.size() && isdigit(input[i + 1])) count += input[++i];
        int freq = count.empty() ? 1 : std::stoi(count);
        result += std::string(freq, ch);
    }
    return result;
}

int main() {
    std::string input = "aabcccccaaa";
    std::string comp1 = basicCompressor(input);
    std::string comp2 = secondCompressor(comp1);
    std::string decomp = decompressor(comp2);

    std::cout << "Original:      " << input << "\n";
    std::cout << "Compressed 1:  " << comp1 << "\n";
    std::cout << "Compressed 2:  " << comp2 << "\n";
    std::cout << "Decompressed:  " << decomp << "\n";
}
