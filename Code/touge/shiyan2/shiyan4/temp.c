#include <stdio.h>
#include <stdlib.h>

// 定义扑克牌结构体，包含点数和花色两个成员
typedef struct Card {
    char point;  // 用于存储牌面点数，比如 '2'、'A' 等字符形式，后续按需转换为整数
    char suit;   // 用于存储牌的花色，比如 'H'（红桃）、'S'（黑桃）等字符形式
} Card;

// 冒泡排序函数，对传入的三个整数进行从小到大排序
int sort(int *nums) {
    int temp;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    return 1;
}

// 判断是否是豹子（三张牌点数一样）
int Leopard(Card cards[]) {
    // 通过比较三张牌的点数是否完全相同来判断是否为豹子牌型
    return (cards[0].point == cards[1].point && cards[1].point == cards[2].point);
}

// 判断是否是同花顺（同花色且点数相邻）
int Flush_straight(Card cards[]) {
    int numbers[3];
    // 将字符形式的牌面点数转换为整数，方便后续比较大小和判断连续性
    numbers[0] = cards[0].point - '0';
    numbers[1] = cards[1].point - '0';
    numbers[2] = cards[2].point - '0';

    // 先调用排序函数对点数进行排序
    if (sort(numbers)) {
        // 再判断三张牌的花色是否相同，如果点数连续且花色相同则是同花顺
        if (cards[0].suit == cards[1].suit && cards[1].suit == cards[2].suit) {
            return 1;
        }
    }
    return 0;
}

// 判断是否是顺子（不同花色但点数相邻）
int Straight(Card cards[]) {
    int numbers[3];
    numbers[0] = cards[0].point - '0';
    numbers[1] = cards[1].point - '0';
    numbers[2] = cards[2].point - '0';

    // 只需调用排序函数判断点数是否连续，忽略花色情况
    return sort(numbers);
}

// 判断是否是同花（花色相同，点数不全同）
int Same_king(Card cards[]) {
    // 通过比较三张牌的花色是否相同来判断是否为同花牌型
    return (cards[0].suit == cards[1].suit && cards[1].suit == cards[2].suit);
}

// 判断是否是对子（有两张牌点数相同，花色不全同）
int Pair(Card cards[]) {
    if ((cards[0].point == cards[1].point && cards[0].point!= cards[2].point) ||
        (cards[0].point == cards[2].point && cards[0].point!= cards[1].point) ||
        (cards[1].point == cards[2].point && cards[1].point!= cards[0].point)) {
        // 在存在两张牌点数相同的基础上，判断花色是否不全同，若满足则是对子牌型
        if (cards[0].suit!= cards[1].suit || cards[1].suit!= cards[2].suit || cards[0].suit!= cards[2].suit) {
            return 1;
        }
    }
    return 0;
}

// 判断是否是花牌（花色不全同，点数全不同）
int General(Card cards[]) {
    // 先判断三张牌的点数是否全不同
    if (cards[0].point!= cards[1].point && cards[1].point!= cards[2].point && cards[0].point!= cards[2].point) {
        // 再判断三张牌的花色是否全不同，若点数和花色都满足全不同条件则是花牌牌型
        if (cards[0].suit!= cards[1].suit && cards[1].suit!= cards[2].suit && cards[0].suit!= cards[2].suit) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    Card cards[3];
    for (int i = 0; i < N; i++) {
        // 清理输入缓冲区，防止残留换行符等影响下一次输入读取
        getchar();
        for (int j = 0; j < 3; j++) {
            scanf("%c%c", &cards[j].point, &cards[j].suit);
        }

        if (Leopard(cards)) {
            printf("豹子 %c\n", cards[0].point);
        } else if (Flush_straight(cards)) {
            printf("同花顺 %c\n", cards[2].point);
        } else if (Straight(cards)) {
            printf("顺子 %c\n", cards[2].point);
        } else if (Same_king(cards)) {
            printf("同花 %c\n", cards[2].point);
        } else if (Pair(cards)) {
            printf("对子 %c\n", cards[2].point);
        } else if (General(cards)) {
            printf("花牌 %c\n", cards[2].point);
        }
    }
    return 0;
}