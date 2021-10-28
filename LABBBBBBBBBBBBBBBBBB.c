#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct uint1024
{
    char *str;
    int maxSize;
    int *chunck1;
    int *chunck2;
    int *chunck3;
};

int maxI(int x, int y)
{
    return (x > y) ? x : y;
}
void _swap(char *arr, int Nsize)
{
    int temp;
    for(int i = 0, j = Nsize - 1; i < Nsize / 2; ++i, --j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


void uint1024_tfrom_uint(struct uint1024 bigint)
{
    char *str = bigint.str;
    int maxSize = bigint.maxSize;
    int *chunckMain = bigint.chunck1;
    int length = (strlen(str) % 9 == 0) ? strlen(str) / 9 : strlen(str) / 9 + 1;
    //int *chunck = (int*) malloc(length);
    int *chunck = bigint.chunck2;
    memset(chunck, 0, maxSize);
    memset(chunckMain, 0, maxSize);
    int num = 0;
    const int BUFFSIZE = 9;
    char minichunck[BUFFSIZE];
    for(int i = strlen(str); i >= 0; i-=9)
    {
        for(int j = 0; j < ((BUFFSIZE > i) ? i : BUFFSIZE); j++)
        {
            minichunck[j] = str[i - j - 1];
        }
        _swap(minichunck, ((BUFFSIZE > i) ? i : BUFFSIZE));
        chunck[num] = atoi(minichunck);
        num++;
        memset(minichunck,0,9);
    }
    for(int i = length - 1; i >= 0; i--)
    {
        chunckMain[i] = chunck[i];
    }
    memset(chunck, 0, maxSize);
}
void uint1024_tadd_op(struct uint1024 bigint1, struct uint1024 bigint2, int *cnt)
{
    int maxSize = maxI(bigint1.maxSize, bigint2.maxSize);
    int *chunck1 = bigint1.chunck1;
    int *chunck2 = bigint2.chunck1;
    int *chunck3 = bigint1.chunck2;
    int ost = 0;
    for(int i = 0; i < maxSize; ++i)
    {
        ost = ost + chunck1[i] + chunck2[i];
        if(ost != 0)
        {
            *cnt += 1;
        }
        chunck3[i] = ost % 1000000000;
        ost /= 1000000000;
    }
}
void uint1024_tsubtr_op(struct uint1024 bigint1, struct uint1024 bigint2, int *cnt)
{
    int maxSize = maxI(bigint1.maxSize, bigint2.maxSize);
    int *chunck1 = bigint1.chunck1;
    int *chunck2 = bigint2.chunck1;
    int *chunck3 = bigint1.chunck2;
    int ost = 0;
    for(int i = 0; i < maxSize; ++i)
    {
        ost = chunck1[i] - chunck2[i] + ost;
        if(ost < 0)
        {
            chunck3[i] = 1000000000 + ost;
            ost = -1;
        }
        else
        {
            chunck3[i] = ost % 1000000000;
            ost /= 1000000000;
        }
    }
    for(int i = 0; i < 140; i++)
    {
        if(chunck3[i] != 0)
        {
            *cnt = i + 1;
        }
    }
    int flag = 0;
    for(int i = 0; i < 140; i++)
    {
        if(chunck1[i] == chunck2[i])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if(flag == 1)
    {
        chunck3[0] = 0;
    }
}
void uint1024_tmult_op(struct uint1024 bigint1, struct uint1024 bigint2, int *cnt)
{
    int maxSize = maxI(bigint1.maxSize, bigint2.maxSize);
    int *chunck1 = bigint1.chunck1;
    int *chunck2 = bigint2.chunck1;
    int *chunck3 = bigint1.chunck2;
    unsigned long long ost = 0;
    for(int i = 0; i < maxSize + 1; i++)
    {
        for(int j = 0; j < maxSize + 1; j++)
        {
            unsigned long long p1 = chunck2[i];
            unsigned long long p2 = chunck1[j];
            unsigned long long p12 = p1 * p2;
            unsigned long long tmp = chunck3[j + i];
            ost = ost + p12;
            chunck3[j + i] = (chunck3[j + i] + ost) % 1000000000;
            ost = (ost + tmp) / 1000000000;
        }
    }
    for(int i = 0; i < maxSize * 2 + 1; i++)
    {
        if(chunck3[i] != 0)
        {
            *cnt = i + 1;
        }
    }
}
void printf_value(struct uint1024 bigint1, int cnt)
{
    int maxSize = cnt;
    int *chunck = bigint1.chunck2;
    if(cnt > 139)
    {
        printf("Undefined behavior");

    }
    else
    {
        if(maxSize == 0)
        {
            printf("0");
        }
        else
        {
            for(int i = maxSize - 1; i >= 0; i--)
            {
                if(i != maxSize - 1)
                {
                    printf("%09d", chunck[i]);
                }
                else
                {
                    printf("%d",chunck[i]);
                }
            }
        }
        printf(" ");
    }
}

int main()
{
    char
            symbol[1],
            str1[10000],
            str2[10000];
    char
            str3[10] = "+, -, *";
    printf("Write your number : \n");
    scanf("%s", &str1);
    printf("Write your second number : \n");
    scanf("%s", &str2);
    printf("This is symbols, which u can use : %s\n", str3);
    printf("Ok, what do you want to do? \n");
    scanf("%s", symbol);

    if(strcmp(symbol, "*") != 0  && strcmp(symbol, "+") != 0 && strcmp(symbol, "-") != 0)
    {
        printf("uchi matchast and retry it\n");
        return -1;
    }
    else
    {
        int
                chunck1[1000],
                chunck2[1000],
                chunck3[1000];
        int cnt = 0;
        struct uint1024 bigint1;
        bigint1.chunck2 = chunck3;
        bigint1.chunck1 = chunck1;
        bigint1.maxSize = maxI(strlen(str1), strlen(str2)) + 1;
        bigint1.str = str1;
        uint1024_tfrom_uint(bigint1);
        struct uint1024 bigint2;
        bigint2.chunck2 = chunck3;
        bigint2.chunck1 = chunck2;
        bigint2.maxSize = maxI(strlen(str2), strlen(str2)) + 1;
        bigint2.str = str2;
        uint1024_tfrom_uint(bigint2);
        if(strcmp(symbol, "+") == 0)
        {
            uint1024_tadd_op(bigint1, bigint2, &cnt);
        }
        if(strcmp(symbol, "-") == 0)
        {
            uint1024_tsubtr_op(bigint1, bigint2, &cnt);
        }
        if(strcmp(symbol, "*") == 0)
        {
            uint1024_tmult_op(bigint2, bigint1, &cnt);
        }
        printf("Answer is : \n");
        printf_value(bigint1, cnt);
        return 0;
    }
}

