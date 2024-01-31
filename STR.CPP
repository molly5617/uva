#include <iostream>
#include <regex>

std::string match_pattern(const std::string &input_pattern, const std::string &test_string)
{
    std::regex pattern(input_pattern);
    std::smatch match;
    if (std::regex_match(test_string, match, pattern))
    {
        int n_count = std::count(test_string.begin(), test_string.end(), 'n');
        int star_count = std::count(input_pattern.begin(), input_pattern.end(), '*');
        return "Y " + std::to_string(n_count) + " " + std::to_string(star_count);
    }
    else
    {
        return "N";
    }
}

int main()
{
    std::string input_pattern, test_string;
    std::getline(std::cin, input_pattern);
    int n;
    std::cin >> n;
    std::cin.ignore(); // Clear the newline character from the buffer

    for (int i = 0; i < n; ++i)
    {
        std::getline(std::cin, test_string);
        std::string result = match_pattern(input_pattern, test_string);
        std::cout << result << std::endl;
    }

    return 0;
}
