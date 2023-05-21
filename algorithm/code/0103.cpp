#include <iostream>
#include <cstring>

using namespace std;

char lef[3][7];
char righ[3][7];
char result[3][5];
bool isFake(char c, bool light)
{
    for (int i = 0; i < 3; i++)
    {
        char *pLeft, *pRight;
        if (light)
        {
            pLeft = lef[i];
            pRight = righ[i];
        }
        else
        {
            pLeft = righ[i];
            pRight = lef[i];
        }
        switch (result[i][0])
        {
        case 'u':
            if (strchr(pRight, c) == NULL)
                return false;
            break;
        case 'e':
            if (strchr(pRight, c) || strchr(pLeft, c))
                return false;
            break;
        case 'd':
            if (strchr(pLeft, c) == NULL)
                return false;
            break;
        }
    }
    return true;
}
int main()
{
    int numTests;
    cin >> numTests;

    while (numTests--)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> lef[i] >> righ[i] >> result[i];
        }
        for (char c = 'A'; c <= 'L'; c++)
        {
            if (isFake(c, true))
            {
                printf("%c is the counterfeit coin and it is light.\n", c);
                break;
            }
            else if (isFake(c, false))
            {
                printf("%c is the counterfeit coin and it is heavy.\n", c);
                break;
            }
        }
    }
    system("pause");
}

// 自己写的，没过
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int cas;
//     cin >> cas;
//     string left, right, res;
//     unordered_set<char> real;
//     unordered_set<char> light, heavy;
//     while (cas--)
//     {
//         for (int i = 0; i < 3; i++)
//         {
//             cin >> left >> right;
//             cin >> res;
//             if (res == "even")
//             {
//                 for (auto c : left)
//                     real.insert(c);
//                 for (auto c : right)
//                     real.insert(c);
//                 // cout << "real: " << real.size() << endl;
//             }
//             else if (res == "down")
//             {
//                 for (auto c : left)
//                     light.insert(c);
//                 for (auto c : right)
//                     heavy.insert(c);
//                 // cout << "light: " << light.size() << endl;
//                 // cout << "heavy: " << heavy.size() << endl;
//             }
//             else
//             {
//                 for (auto c : left)
//                     heavy.insert(c);
//                 for (auto c : right)
//                     light.insert(c);
//                 // cout << "light: " << light.size() << endl;
//                 // cout << "heavy: " << heavy.size() << endl;
//             }
//         }
//         // cout << "real: " << real.size() << endl;
//         for (auto it = heavy.begin(); it != heavy.end();)
//         {
//             if (real.find(*it) != real.end())
//             {
//                 // cout << *it << endl;
//                 it = heavy.erase(it);
//             }
//             else
//             {
//                 it++;
//             }
//         }
//         // for (auto c : heavy)
//         //     if (real.count(c))
//         //         heavy.erase(c);
//         // cout << "heavy: " << heavy.size() << endl;
//         for (auto it = light.begin(); it != light.end();)
//         {
//             if (real.find(*it) != real.end())
//             {
//                 // cout << *it << endl;
//                 it = light.erase(it);
//             }
//             else
//             {
//                 it++;
//             }
//         }
//         // for (auto c : light)
//         //     if (real.count(c))
//         //         light.erase(c);

//         // cout << "light: " << light.size() << endl;
//         if (!heavy.empty())
//         {
//             cout << *heavy.begin() << " is the counterfeit coin and it is heavy." << endl;
//         }
//         else if (!light.empty())
//         {
//             cout << *light.begin() << " is the counterfeit coin and it is light." << endl;
//         }
//     }

//     system("pause");
// }