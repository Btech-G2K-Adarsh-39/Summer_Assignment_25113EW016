#include<stdio.h>
int find_gcd(int a,int b){
    while(b!=0){
        int temp =b;
        b = a % b;
        a = temp;

    }
    return a;
}

int find_lcm(int a, int b){
    if(a==0 || b==0){
        return 0;
    }
    return (a /find_gcd(a,b))*b;
}

int main(){
    int num1,num2,lcm;

    printf("Enter two positive integers : ");

    if(scanf("%d %d",&num1,&num2) !=2){
        printf("Invalid input.\n");
        return 1;
    }

    lcm = find_lcm(num1,num2);

    printf("The LCM of %d and %d is %d\n",num1,num2,lcm);

    return 0;
}