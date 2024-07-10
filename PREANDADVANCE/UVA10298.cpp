#include <iostream>
#include <vector>
#include <string>

// 函数：计算部分匹配表（也称为前缀函数）
std::vector<int> computePrefixFunction(const std::string& s) {
    int n = s.size();
    std::vector<int> pi(n, 0);
    int k = 0;
    for (int i = 1; i < n; ++i) {
        while (k > 0 && s[k] != s[i]) {
            k = pi[k - 1];
        }
        if (s[k] == s[i]) {
            ++k;
        }
        pi[i] = k;
    }
    return pi;
}

// 函数：计算字符串由多少个重复的子串连接而成
int find_repeated_substring_count(const std::string& s) {
    int n = s.size();
    std::vector<int> pi = computePrefixFunction(s);
    int l = pi[n - 1]; // 最长前缀后缀长度

    // 检查字符串是否可以由子串重复组成
    if (l > 0 && n % (n - l) == 0) {
        return n / (n - l);
    } else {
        return 1;
    }
}

int main() {
    std::vector<std::string> inputs;

    // 读取多组数据
    std::string s;
    while (std::cin >> s && s != ".") inputs.push_back(s);

    // 处理每组数据并输出结果
    for (const auto& s : inputs) {
        std::cout << find_repeated_substring_count(s) << std::endl;
    }

    return 0;
}
