#include <memory>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int GetBit(char c, int i)
{
    return (c >> i) & 1;
}
void SetBit(char &c, int i, int v)
{
    if (v)
        c |= (1 << i);
    else
        c &= ~(1 << i);
}
void Flip(char &c, int i)
{
    GetBit(c, i) ? SetBit(c, i, 0) : SetBit(c, i, 1);
}
void output(int t, char result[])
{
    cout << "PUZZLE #" << t << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
            cout << GetBit(result[i], j) << " ";
        cout << endl;
    }
}
int main()
{
    char oriLights[5]; // 最初灯矩阵，一个比特表示一盏灯
    char lights[5];    // 不停变化的灯矩阵
    char result[5];    // 结果开关矩阵
    char switchs;      // 某一行的开关状态
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        memset(oriLights, 0, sizeof(oriLights));
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                int s;
                cin >> s;
                SetBit(oriLights[i], j, s);
            }
        }
        for (int n = 0; n < 64; n++)
        {
            memcpy(lights, oriLights, sizeof(lights));
            switchs = n;
            for (int i = 0; i < 5; i++)
            {
                result[i] = switchs;
                for (int j = 0; j < 6; j++)
                {
                    if (GetBit(switchs, j))
                    {
                        Flip(lights[i], j);
                        if (j > 0)
                            Flip(lights[i], j - 1);
                        if (j < 5)
                            Flip(lights[i], j + 1);
                    }
                }
                if (i < 4)
                    lights[i + 1] ^= switchs;
                switchs = lights[i];
            }
            if (lights[4] == 0)
            {
                output(t, result);
                break;
            }
        }
    }
    system("pause");
}