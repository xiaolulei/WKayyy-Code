    #include <stdio.h>
    // ¶¨Òåmainº¯Êý
    int main()
    {
        // ÇëÔÚ´ËÌí¼Ó´úÂë
        /********** Begin *********/
        int a,b;
        printf("请选择石头（0）、布（1）、剪刀（2）：\n");
        printf("玩家1：");
        scanf("%d", &a);
        printf("玩家2：");
        scanf("%d", &b);
        if(a==b){
            printf("平局！");
        }
        else if(a==0){
            if(b==1){
                printf("玩家2胜！");
            } 
            if(b==2){
                printf("玩家1胜！");
            }
        }
        else if(a==1){
            if(b==2){
                printf("玩家2胜！");
            } 
            if(b==0){
                printf("玩家1胜！");
            }
        }
        else if(a==2){
            if(b==1){
                printf("玩家1胜！");
            } 
            if(b==0){
                printf("玩家2胜！");
            }
        }
        /********** End **********/
        return 0;
    }