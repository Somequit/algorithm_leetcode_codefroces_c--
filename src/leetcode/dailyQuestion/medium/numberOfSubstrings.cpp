/*
 * @Author: 辜思学 gusixue@foxmail.com
 * @Description: 3234. 统计 1 显著的字符串的数量
 * @Date: 2025-11-15 07:23:29
 */
#include <bits/stdc++.h>

using namespace std;

int numberOfSubstrings(string s) {
    int res = 0;
    int keepCnt1 = 0;
    int n = s.length();

    int prefixCnt1[n + 2];
    std::memset(prefixCnt1, 0, sizeof(prefixCnt1));

    int index0[n + 2];
    index0[0] = 0;
    int index0I = 1;

    for (int i = 0;i < n;i++)
    {
        prefixCnt1[i + 1] = prefixCnt1[i];
        if (s[i] == '1')
        {
            prefixCnt1[i + 1]++;
            keepCnt1++;
            res += keepCnt1;
        }
        else
        {
            index0[index0I] = i + 1;
            index0I++;
            keepCnt1 = 0;
        }
    }
    index0[index0I] = n + 1;
    index0I++;
    prefixCnt1[n + 1] = prefixCnt1[n];

    // 枚举右端点
    for (int i = index0[1],j=1;i <= n;i++)
    {
        if (index0[j + 1] == i)
        {
            j++;
        }

        for (int l = j;l > 0;l--)
        {
            int cnt0 = j - l + 1;
            cout << j << " " << index0[j + 1] << " " << cnt0 << " " << prefixCnt1[index0[j + 1]] << endl;
            if (cnt0 * cnt0 > prefixCnt1[index0[j + 1]])
            {
                break;
            }

            int midCnt1 = prefixCnt1[index0[j]] - prefixCnt1[index0[l]];
            int leftCnt1 = prefixCnt1[index0[l]] - prefixCnt1[index0[l - 1]];
            int rightCnt1 = i - index0[j];

            res += max(0, leftCnt1 - max(0, cnt0 * cnt0 - midCnt1 - rightCnt1) + 1);

        }
    }

    return res;
}

int main() {
    cout << numberOfSubstrings("01010001100110") << endl;
}