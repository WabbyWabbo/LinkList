#include <iostream>
using namespace std;

int x = 0;

void find_w(int M1[], int M2[], int w, int s1, int len1, int s2, int len2)
{
    if (len1 == 1 && len2 == 1 && M1[s1] + M2[s2] != w)
    {
        cout << "not found";
        return;
    }

    // if (len1 == 2 && len2 == 2)
    // {
        
    //     cout << "not found";
    //     return;
    // }

    int mid1 = (s1 + (s1 + len1 - 1)) / 2;
    int mid2 = (s2 + (s2 + len1 - 1)) / 2;
    x++;
    if (M1[mid1] + M2[mid2] > w)
        find_w(M1, M2, w, 0, mid1 + 1, mid2, len2 / 2 + 1);
    else if (M1[mid1] + M2[mid2] < w)
        find_w(M1, M2, w, mid1, len1 / 2 + 1, 0, mid2 + 1);
    else
    {
        cout << mid1 << endl
             << mid2 << endl;
        return;
    }
}

int main(void)
{
    int M1[5] = {1, 2, 3, 4, 5};
    int M2[5] = {9, 7, 5, 3, 1};

    find_w(M1, M2, 13, 0, 5, 0, 5);
    cout<<x;
}