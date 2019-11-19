#include "stdio.h"

int main(void)
{
    printf("hello world !\n");

    {
        int i = 0;

        for(i=0;i<10;i++)
        {
            printf("counter is %d\n",i);
            if(i==5)
            break;
        }

    }
    return 0;
}