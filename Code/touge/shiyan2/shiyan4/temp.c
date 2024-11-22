#include <stdio.h>
#include <string.h>
typedef struct {
    int rank;
    char suit;
} Card;
void readCards(Card cards[], int n);
int findMaxRank(Card cards[], int n);
int isStraightFlush(Card cards[], int n);
int isFourOfAKind(Card cards[], int n);
int isFullHouse(Card cards[], int n);
int isFlush(Card cards[], int n);
int isStraight(Card cards[], int n);
int isThreeOfAKind(Card cards[], int n);
int isTwoPairs(Card cards[], int n);
int isOnePair(Card cards[], int n);

int main() {
    int n;
    scanf("%d", &n);

    Card cards[3];
    for (int i = 0; i < n; i++) {
        readCards(cards, 3);
        if (isStraightFlush(cards, 3)) {
            printf("StraightFlush %d\n", findMaxRank(cards, 3));
        } else if (isFourOfAKind(cards, 3)) {
            printf("FourOfAKind %d\n", findMaxRank(cards, 3));
        } else if (isFullHouse(cards, 3)) {
            printf("FullHouse %d\n", findMaxRank(cards, 3));
        } else if (isFlush(cards, 3)) {
            printf("Flush %d\n", findMaxRank(cards, 3));
        } else if (isStraight(cards, 3)) {
            printf("Straight %d\n", findMaxRank(cards, 3));
        } else if (isThreeOfAKind(cards, 3)) {
            printf("ThreeOfAKind %d\n", findMaxRank(cards, 3));
        } else if (isTwoPairs(cards, 3)) {
            printf("TwoPairs %d\n", findMaxRank(cards, 3));
        } else if (isOnePair(cards, 3)) {
            printf("OnePair %d\n", findMaxRank(cards, 3));
        } else {
            printf("HighCard %d\n", findMaxRank(cards, 3));
        }
    }

    return 0;
}
void readCards(Card cards[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d%c", &cards[i].rank, &cards[i].suit);
    }
}

int findMaxRank(Card cards[], int n) {
    int maxRank = 0;
    for (int i = 0; i < n; i++) {
        if (cards[i].rank > maxRank) {
            maxRank = cards[i].rank;
        }
    }
    return maxRank;
}

int isStraightFlush(Card cards[], int n) {
    int isStraight = 1;
    int isFlush = 1;
    for (int i = 1; i < n; i++) {
        if (cards[i].rank!= cards[i - 1].rank + 1) {
            isStraight = 0;
        }
        if (cards[i].suit!= cards[i - 1].suit) {
            isFlush = 0;
        }
    }
    return isStraight && isFlush;
}

int isFourOfAKind(Card cards[], int n) {
    if ((cards[0].rank == cards[1].rank && cards[1].rank == cards[2].rank) ||
        (cards[1].rank == cards[2].rank && cards[2].rank == cards[0].rank) ||
        (cards[2].rank == cards[0].rank && cards[0].rank == cards[1].rank)) {
        return 1;
    }
    return 0;
}


int isFullHouse(Card cards[], int n) {
    int ranks[13] = {0};
    for (int i = 0; i < n; i++) {
        ranks[cards[i].rank]++;
    }
    int hasThree = 0;
    int hasPair = 0;
    for (int i = 0; i < 13; i++) {
        if (ranks[i] == 3) {
            hasThree = 1;
        } else if (ranks[i] == 2) {
            hasPair = 1;
        }
    }
    return hasThree && hasPair;
}


int isFlush(Card cards[], int n) {
    for (int i = 1; i < n; i++) {
        if (cards[i].suit!= cards[i - 1].suit) {
            return 0;
        }
    }
    return 1;
}


int isStraight(Card cards[], int n) {
    int isStraight = 1;
    int ranks[13] = {0};
    for (int i = 0; i < n; i++) {
        ranks[cards[i].rank]++;
    }
    int minRank = 14;
    int maxRank = 0;
    for (int i = 1; i <= 13; i++) {
        if (ranks[i]) {
            if (i < minRank) {
                minRank = i;
            }
            if (i > maxRank) {
                maxRank = i;
            }
            if (ranks[i] > 1) {
                isStraight = 0;
            }
        }
    }

    if (ranks[1] && ranks[2] && ranks[3] && ranks[4] && ranks[13]) {
        isStraight = 1;
        minRank = 1;
        maxRank = 5;
    }
    return isStraight && (maxRank - minRank == n - 1);
}

int isThreeOfAKind(Card cards[], int n) {
    int ranks[13] = {0};
    for (int i = 0; i < n; i++) {
        ranks[cards[i].rank]++;
    }
    for (int i = 0; i < 13; i++) {
        if (ranks[i] == 3) {
            return 1;
        }
    }
    return 0;
}

int isTwoPairs(Card cards[], int n) {
    int ranks[13] = {0};
    int pairCount = 0;
    for (int i = 0; i < n; i++) {
        ranks[cards[i].rank]++;
    }
    for (int i = 0; i < 13; i++) {
        if (ranks[i] == 2) {
            pairCount++;
        }
    }
    return pairCount == 2;
}

int isOnePair(Card cards[], int n) {
    int ranks[13] = {0};
    for (int i = 0; i < n; i++) {
        ranks[cards[i].rank]++;
    }
    for (int i = 0; i < 13; i++) {
        if (ranks[i] == 2) {
            return 1;
        }
    }
    return 0;
}