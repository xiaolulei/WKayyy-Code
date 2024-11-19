#include <stdio.h>
#include <ctype.h>
int charToNum(char ch) {
    if (isdigit(ch)) {
        return ch - '0';
    } else if (ch == 'A') {
        return 1;
    } else if (ch == 'J') {
        return 11;
    } else if (ch == 'Q') {
        return 12;
    } else if (ch == 'K') {
        return 13;
    }
    return -1;
}

int isLeopard(char a, char a1, char b, char b1, char c, char c1) {
    int numA = charToNum(a);
    int numB = charToNum(b);
    int numC = charToNum(c);
    return numA == numB && numB == numC;
}

int isFlushStraight(char a, char a1, char b, char b1, char c, char c1) {
    int num[3];
    num[0] = charToNum(a);
    num[1] = charToNum(b);
    num[2] = charToNum(c);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (num[j] > num[j + 1]) {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    return (a1 == b1 && b1 == c1) && (num[0] + 1 == num[1] && num[1] + 1 == num[2]);
}

int getFlushStraightMaxNum(char a, char a1, char b, char b1, char c, char c1) {
    if (isFlushStraight(a, a1, b, b1, c, c1)) {
        return charToNum(a);
    }
    return -1;
}

int isStraight(char a, char a1, char b, char b1, char c, char c1) {
    int num[3];
    num[0] = charToNum(a);
    num[1] = charToNum(b);
    num[2] = charToNum(c);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (num[j] > num[j + 1]) {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    return (a1!= b1 && b1!= c1 && a1!= c1) && (num[0] + 1 == num[1] && num[1] + 1 == num[2]);
}

int getStraightMaxNum(char a, char a1, char b, char b1, char c, char c1) {
    if (isStraight(a, a1, b, b1, c, c1)) {
        return charToNum(a);
    }
    return -1;
}
int isSameSuit(char a1, char b1, char c1) {
    return a1 == b1 && b1 == c1;
}
int getSameSuitMaxNum(char a, char a1, char b, char b1, char c, char c1) {
    if (isSameSuit(a1, b1, c1)) {
        int num[3];
        num[0] = charToNum(a);
        num[1] = charToNum(b);
        num[2] = charToNum(c);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2 - i; j++) {
                if (num[j] > num[j + 1]) {
                    int temp = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = temp;
                }
            }
        }
        return num[0];
    }
    return -1;
}
int isPair(char a, char a1, char b, char b1, char c, char c1) {
    int numA = charToNum(a);
    int numB = charToNum(b);
    int numC = charToNum(c);
    return ((numA == numB && numA!= numC) || (numA == numC && numA!= numB) || (numB == numC && numA!= numB))
           && (a1!= b1 && b1!= c1 && a1!= c1);
}
int getPairMaxNum(char a, char a1, char b, char b1, char c, char c1) {
    if (isPair(a, a1, b, b1, c, c1)) {
        int num[3];
        num[0] = charToNum(a);
        num[1] = charToNum(b);
        num[2] = charToNum(c);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2 - i; j++) {
                if (num[j] > num[j + 1]) {
                    int temp = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = temp;
                }
            }
        }
        return num[0];
    }
    return -1;
}
int isGeneral(char a, char a1, char b, char b1, char c, char c1) {
    int numA = charToNum(a);
    int numB = charToNum(b);
    int numC = charToNum(c);
    return numA!= numB && numB!= numC;
}
int getGeneralMaxNum(char a, char a1, char b, char b1, char c, char c1) {
    if (isGeneral(a, a1, b, b1, c, c1)) {
        int num[3];
        num[0] = charToNum(a);
        num[1] = charToNum(b);
        num[2] = charToNum(c);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2 - i; j++) {
                if (num[j] > num[j + 1]) {
                    int temp = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = temp;
                }
            }
        }
        return num[0];
    }
    return -1;
}
int getMaxCardTypePosition(int flag[]) {
    int position = 0;
    for (int i = 0; i < 6; i++) {
        if (flag[i] > flag[position]) {
            position = i;
        }
    }
    return position;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char a, b, c;
        char a1, b1, c1;
        scanf(" %c%c %c%c %c%c", &a, &a1, &b, &b1, &c, &c1);

        int flag[6] = {0};
        flag[0] = isLeopard(a, a1, b, b1, c, c1);
        flag[1] = isFlushStraight(a, a1, b, b1, c, c1);
        flag[2] = isStraight(a, a1, b, b1, c, c1);
        flag[3] = isSameSuit(a1, b1, c1);
        flag[4] = isPair(a, a1, b, b1, c, c1);
        flag[5] = isGeneral(a, a1, b, b1, c, c1);

        int maxCardTypePosition = getMaxCardTypePosition(flag);
        switch (maxCardTypePosition) {
            case 0:
                printf("Leopard ");
                printf("%d\n", charToNum(a));
                break;
            case 1:
                printf("Flush straight ");
                printf("%d\n", getFlushStraightMaxNum(a, a1, b, b1, c, c1));
                break;
            case 2:
                printf("Straight ");
                printf("%d\n", getStraightMaxNum(a, a1, b, b1, c, c1));
                break;
            case 3:
                printf("Same suit ");
                printf("%d\n", getSameSuitMaxNum(a, a1, b, b1, c, c1));
                break;
            case 4:
                printf("Pair ");
                printf("%d\n", getPairMaxNum(a, a1, b, b1, c, c1));
                break;
            case 5:
                printf("General ");
                printf("%d\n", getGeneralMaxNum(a, a1, b, b1, c, c1));
                break;
        }
    }
    return 0;
}