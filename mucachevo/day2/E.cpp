#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Побудова суфіксного масиву
std::vector<int> build_suffix_array(const std::string &s) {
    int n = s.size();
    std::vector<int> p(n), c(n), cnt(std::max(256, n), 0);

    // Ініціалізація: сортування символів
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    for (int i = 1; i < 256; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        p[--cnt[s[i]]] = i;
    }

    // Побудова класів еквівалентності
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) {
            classes++;
        }
        c[p[i]] = classes - 1;
    }

    // Сортування за довжинами 2^k
    std::vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; h++) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) {
                pn[i] += n;
            }
        }

        std::fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) {
            cnt[c[pn[i]]]++;
        }
        for (int i = 1; i < classes; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            p[--cnt[c[pn[i]]]] = pn[i];
        }

        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            int mid1 = (p[i] + (1 << h)) % n;
            int mid2 = (p[i - 1] + (1 << h)) % n;
            if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) {
                classes++;
            }
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }

    return p;
}

// Побудова LCP масиву
std::vector<int> build_lcp_array(const std::string &s, const std::vector<int> &suffix_array) {
    int n = s.size();
    std::vector<int> rank(n), lcp(n - 1, 0);

    // Побудова масиву рангів
    for (int i = 0; i < n; i++) {
        rank[suffix_array[i]] = i;
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = suffix_array[rank[i] - 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
                k++;
            }
            lcp[rank[i] - 1] = k;
            if (k > 0) {
                k--;
            }
        }
    }

    return lcp;
}

// Пошук спільного підрядка максимальної довжини
std::string find_longest_common_substring(const std::vector<std::string> &strings) {
    // Об'єднання рядків з розділювальними символами
    std::string combined;
    std::vector<int> string_index;  // Зберігає, до якого рядка належить кожен символ
    int n = strings.size();
    for (int i = 0; i < n; i++) {
        combined += strings[i] + char('$' + i);
        for (int j = 0; j < strings[i].size(); j++) {
            string_index.push_back(i);
        }
        string_index.push_back(-1);  // Розділювальний символ
    }

    // Побудова суфіксного масиву
    std::vector<int> suffix_array = build_suffix_array(combined);

    // Побудова LCP масиву
    std::vector<int> lcp_array = build_lcp_array(combined, suffix_array);

    // Пошук максимального LCP
    int max_length = 0;
    int start_index = 0;
    for (int i = 1; i < combined.size(); i++) {
        int a = string_index[suffix_array[i]];
        int b = string_index[suffix_array[i - 1]];
        if (a != b && a != -1 && b != -1) {  // Сусідні суфікси належать різним рядкам
            if (lcp_array[i - 1] > max_length) {
                max_length = lcp_array[i - 1];
                start_index = suffix_array[i];
            }
        }
    }

    return combined.substr(start_index, max_length);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> strings(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strings[i];
    }

    std::string result = find_longest_common_substring(strings);
    std::cout << result << "\n";

    return 0;
}
