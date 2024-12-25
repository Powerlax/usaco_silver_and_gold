//
// Created by innav_z3e3dq9 on 12/13/2024.
//

#include <iostream>
#include <vector>
using namespace std;

bool canFileEmails(int M, int N, int K, const vector<int>& folders) {
    int folderStart = 1;
    int emailsProcessed = 0;
    while (emailsProcessed < N) {
        int targetFolder = folders[emailsProcessed];
        while (targetFolder < folderStart || targetFolder >= folderStart + K) {
            folderStart++;
            if (folderStart > M - K + 1) {
                return false;
            }
        }
        emailsProcessed++;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;

        vector<int> folders(N);
        for (int i = 0; i < N; ++i) {
            cin >> folders[i];
        }

        if (canFileEmails(M, N, K, folders)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

