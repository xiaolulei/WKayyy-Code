    #include <stdio.h>
    
    int main() {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
    
        if (a + b <= c || a + c <= b || b + c <= a) {
            printf("Not triangle\n");
        } else {
            if (a == b && b == c) {
                printf("Equilateral triangle\n");
            } else if (a == b || b == c || a == c) {
                printf("Isosceles triangle\n");
            }
            if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
                printf("Right triangle\n");
            } else if (a * a + b * b < c * c || a * a + c * c < b * b || b * b + c * c < a * a) {
                printf("Obtuse triangle\n");
            } else {
                printf("Acute triangle\n");
            }
        }
    
        return 0;
    }