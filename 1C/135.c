//? header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int candy(int* ratings, int ratingsSize){
    int candy_num[ratingsSize];

    int i = 0, j = 0;

    for(i = 0; i < ratingsSize; i++){
        candy_num[i] = 1;
    }

    for(i = 0; i < ratingsSize - 1; i++){
        if (ratings[i] < ratings[i + 1]){
            candy_num[i + 1] = candy_num[i] + 1;
        }
    }

    for(i = ratingsSize - 1; i >= 1; i--){
        if (ratings[i] < ratings[i - 1]){
            candy_num[i - 1] = candy_num[i] + 1 > candy_num[i - 1] ? candy_num[i] + 1: candy_num[i - 1];
        }
    }

    int sum = 0;
    for (i = 0; i < ratingsSize; i++){
        sum += candy_num[i];
    }

    return sum;

}

int main()
{
    int a[5] = {1, 3, 4, 5, 2};

    printf("%d\n", candy(a, 5));

    return 0;
}