#include <stdio.h>

int main(){
    int i,j,a,b;
    scanf("%d %d",&a,&b);

    for(i=a;i<=b;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0){
                break;
            }
        }
        printf("%d ",j);
        printf("%d ",i);
       //if(j==i){
        //    printf("%d ",i);
        //}
    }
    printf("Task Ended...........");
    return 0;
}
