#include<stdio.h> 
int debug[5000]={0};
void solve(int a){
    /*********Begin*********/
    int sum1=0,sum2=0;
    for(int i=1;i<a;i++){
        if(a%i==0) sum1+=i;
    }
    for(int i=1;i<sum1;i++){
        if(sum1%i==0) sum2+=i;
    }
    if(sum2==a)
    {
        if(a>sum1&&debug[a]==0&&debug[sum1]==0){
            debug[a]++;
            debug[sum1]++;
            printf("(%d,%d)",sum1,a);
        }
        if(a<sum1&&debug[a]==0&&debug[sum1]==0){
            debug[a]++;
            debug[sum1]++;
            printf("(%d,%d)",a,sum1);
        }
    }
    /*********End**********/ 
}
int main(void)
{  
    int a;
    for(a=2;a<=3000;a++){
    solve(a);
    }
    return 0;
}
/*请仔细阅读右侧代码，结合相关知识，在Begin-End区域内进行代码补充。
输入
 无需输入
输出
3000以内的全部亲密数(输出格式：(A,B)，不加换行，不加分隔符号)
一对亲密数只输出一次，小的在前

测试说明
样例输出：
(220,284)(1184,1210)(2620,2924)

提示：

按照亲密数定义，要判断数a是否有亲密数，只要计算出a的全部因子的累加和为b，再计算b的全部因子的累加和为n，若n等于a则可判定a和b是亲密数。计算数a的各因子的算法：

用a依次对i(i=1~a/2)进行模运算，若模运算结果等于0，则i为a的一个因子；否则i就不是a的因子。*/