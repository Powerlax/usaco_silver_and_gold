#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;
        std::vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }

        std::vector<long long> cum(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            cum[i + 1] = cum[i] + A[i];
        }

        long long min_bessie = std::numeric_limits<long long>::max();
        for (int i = 0; i <= N - N / 2 - 1; ++i) {
            min_bessie = std::min(min_bessie, cum[i + N / 2 + 1] - cum[i]);
        }

        std::cout << min_bessie << " " << (std::accumulate(A.begin(), A.end(), 0LL) - min_bessie) << std::endl;
    }

    return 0;
}
