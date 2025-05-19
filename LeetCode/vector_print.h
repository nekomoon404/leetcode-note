#include <sstream>
#include <vector>

template <typename T>
std::string to_string(const std::vector<T> &nums) {
    std::ostringstream oss;
    oss << "[";
    bool first = true;
    for (auto num : nums) {
        if (!first) {
            oss << " ,";
        }
        oss << num;
        first = false;
    }
    oss << "]";
    return oss.str();
}

template <typename T>
std::string to_string(const std::vector<std::vector<T>> &matrix) {
    std::ostringstream oss;
    oss << "[";
    bool is_first_row = true;
    for (const auto &row : matrix) {
        if (!is_first_row) {
            oss << ", ";
        }
        // oss << "[";
        // bool is_first_element = true;
        // for (const T &element : row) {
        //     if (!is_first_element) {
        //         oss << ", ";
        //     }
        //     oss << element;
        //     is_first_element = false;
        // }
        // oss << "]";
        oss << to_string(row);
        is_first_row = false;
    }
    oss << "]";
    return oss.str();
}