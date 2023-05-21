#include <string>
#include <cstring>
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
void OutputResult(int t, bitset<6> result[]) // 输出结果
{
    cout << "PUZZLE #" << t << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    bitset<6> oriLights[8]; // 最初灯矩阵，一个比特表示一盏灯
    bitset<6> lights[8];    // 不停变化的灯矩阵
    bitset<6> result[8];    // 结果开关矩阵
    bitset<6> switchs;      // 某一行的开关状态
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        for (int i = 0; i < 5; i++)
        { // 读入最初灯状态
            for (int j = 0; j < 6; j++)
            {
                int s;
                cin >> s;
                oriLights[i][j] = s;
            }
        }
        for (int n = 0; n < 64; ++n)
        { // 遍历首行开关的64种状态
            copy(oriLights, oriLights + 8, lights);
            switchs = n; // 第i行的开关状态
            for (int i = 0; i < 5; ++i)
            {
                result[i] = switchs; // 第i行的开关方案
                for (int j = 0; j < 6; ++j)
                {
                    if (switchs[j])
                    {
                        if (j > 0)
                            lights[i].flip(j - 1); // 改左灯
                        lights[i].flip(j);         // 改开关位置的灯
                        if (j < 5)
                            lights[i].flip(j + 1); // 改右灯
                    }
                }
                if (i < 4)
                    lights[i + 1] ^= switchs; // 改下一行的灯
                switchs = lights[i];          // 第i+1行开关方案和第i行灯情况同
            }
            if (lights[4] == 0)
            {
                OutputResult(t, result);
                break;
            }
        }
    }
    system("pause");
}