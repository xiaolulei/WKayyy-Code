#include <stdio.h>
void bubble_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int arr[3] = {a, b, c};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, len);
    if (arr[0] > arr[1] + arr[2]) {
        printf("Not triangle\n");
    } else {
        if (arr[0] * arr[0] == arr[1] * arr[1] + arr[2] * arr[2])
            printf("Right triangle\n");
        else if (arr[0] * arr[0] < arr[1] * arr[1] + arr[2] * arr[2])
            printf("Acute triangle\n");
        else
            printf("Obtuse triangle\n");
        if (arr[0] == arr[1] && arr[1] == arr[2])
            printf("Equilateral triangle\n");
        if (arr[0] == arr[1] || arr[1] == arr[2]|| arr[0] == arr[2])
            printf("Isosceles triangle\n");
    }
    return 0;
}