#define _CRT_SECURE_NO_WARNINGS 1
//数组的右方区域
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    char letter;
    cin >> letter;
    double arr[12][12], sum = 0;
    int row, line, mount = 0;
    //数组的右方区域
    for (row = 0; row < 12; row++) {
        for (line = 0; line < 12; line++) {
            cin >> arr[row][line];
            if (row < line && line + row > 11) {
                sum = sum + arr[row][line];
                mount++;
            }
        }
    }
    if (letter == 'S') {
        printf("%.1lf", sum);
    }
    else {
        printf("%.1lf", sum / mount);
    }
}