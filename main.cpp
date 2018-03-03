//
//  main.cpp
//  tuili2
//
//  Created by LiFei on 2018/3/3.
//  Copyright © 2018年 RongCloud. All rights reserved.
//

#include <iostream>
#include <math.h>

int *valueToAnswers(int value) {
    int *a = new int[10];
    int i = 0;
    while (value > 3) {
        a[i] = value % 4;
        value /= 4;
        i++;
    }
    a[i] = value;
    return a;
}

void getAnswer() {
    int value, *a = NULL;
    
    for (value = 0; value < pow(4, 10); value++) {
        if (a != NULL) {
            delete []a;
            a = NULL;
        }
        a = valueToAnswers(value);
        //第2题
        if (!((a[4] == 2 && a[1] == 0)
              || (a[4] == 3 && a[1] == 1)
              || (a[4] == 0 && a[1] == 2)
              || (a[4] == 1 && a[1] == 3))) {
            continue;
        }
        //第3题
        if (!((a[2] == a[5] && a[2] == a[1] && a[2] != a[3] && a[2] == 3)
              || (a[2] == a[5] && a[2] == a[3] && a[2] != a[1] && a[2] == 2)
              || (a[2] == a[1] && a[2] == a[3] && a[2] != a[5] && a[2] == 1)
              || (a[5] == a[1] && a[5] == a[3] && a[2] != a[5] && a[2] == 0))) {
            continue;
        }
        //第4题
        if (!((a[0] == a[4] && a[3] == 0)
              || (a[1] == a[6] && a[3] == 1)
              || (a[0] == a[8] && a[3] == 2)
              || (a[5] == a[9] && a[3] == 3))) {
            continue;
        }
        //第5题
        if (!((a[4] == a[7] && a[4] == 0)
              || (a[4] == a[3] && a[4] == 1)
              || (a[4] == a[8] && a[4] == 2)
              || (a[4] == a[6] && a[4] == 3))) {
            continue;
        }
        //第6题
        if (!((a[7] == a[1] && a[7] == a[3] && a[5] == 0)
              || (a[7] == a[0] && a[7] == a[5] && a[5] == 1)
              || (a[7] == a[2] && a[7] == a[9] && a[5] == 2)
              || (a[7] == a[4] && a[7] == a[8] && a[5] == 3))) {
            continue;
        }
        //第7题
        int count[4] = {0,0,0,0};
        for (int i = 0; i < 10; i++) {
            switch (a[i]) {
                case 0:
                    count[0]++;
                    break;
                case 1:
                    count[1]++;
                    break;
                case 2:
                    count[2]++;
                    break;
                case 3:
                    count[3]++;
                    break;
                default:
                    break;
            }
        }
        int min = count[0];
        int max = count[0];
        int minAnswer = 0;
        for (int i = 1; i < 4; i++) {
            if (count[i] < min) {
                min = count[i];
                minAnswer = i;
            }
            if (count[i] > max) {
                max = count[i];
            }
        }
        if (!((minAnswer == 2 && a[6] == 0)
              || (minAnswer == 1 && a[6] == 1)
              || (minAnswer == 0 && a[6] == 2)
              || (minAnswer == 3 && a[6] == 3))) {
            continue;
        }
        //第8题
        if (!((abs(a[6]-a[0]) != 1 && abs(a[0]-a[4]) == 1 && abs(a[0]-a[1]) == 1 && abs(a[0]-a[9]) == 1 && a[7] == 0)
              || (abs(a[6]-a[0]) == 1 && abs(a[0]-a[4]) != 1 && abs(a[0]-a[1]) == 1 && abs(a[0]-a[9]) == 1 && a[7] == 1)
              || (abs(a[6]-a[0]) == 1 && abs(a[0]-a[4]) == 1 && abs(a[0]-a[1]) != 1 && abs(a[0]-a[9]) == 1 && a[7] == 2)
              || (abs(a[6]-a[0]) == 1 && abs(a[0]-a[4]) == 1 && abs(a[0]-a[1]) == 1 && abs(a[0]-a[9]) != 1 && a[7] == 3))) {
            continue;
        }
        //第9题
        switch (a[8]) {
            case 0:
                if (!((a[0] == a[5] && a[5] != a[4]) || (a[0] != a[5] && a[5] == a[4]))) {
                    continue;
                }
                break;
            case 1:
                if (!((a[0] == a[5] && a[9] != a[4]) || (a[0] != a[5] && a[9] == a[4]))) {
                    continue;
                }
                break;
            case 2:
                if (!((a[0] == a[5] && a[1] != a[4]) || (a[0] != a[5] && a[1] == a[4]))) {
                    continue;
                }
                break;
            case 3:
                if (!((a[0] == a[5] && a[8] != a[4]) || (a[0] != a[5] && a[8] == a[4]))) {
                    continue;
                }
                break;
            default:
                break;
        }
        //第10题
        int answer10 = 0;
        switch (max - min) {
            case 3:
                answer10 = 0;
                break;
            case 2:
                answer10 = 1;
                break;
            case 4:
                answer10 = 2;
                break;
            case 1:
                answer10 = 3;
                break;
            default:
                break;
        }
        if (a[9] != answer10) {
            continue;
        }
        std::cout << "value is " << value << "\n";
        for (int i = 0; i < 10; i++) {
            std::cout << i+1 << ". " << (char)(a[i]+65) << "\n";
        }
        delete []a;
        a = NULL;
    }
}

int main(int argc, const char * argv[]) {
    getAnswer();
    return 0;
}
