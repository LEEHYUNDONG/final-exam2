#include<stdio.h>
#include<stdlib.h>

void Towrite()
{
    system("clear");
    presenttime();
    savetime(arr, tnum, &osnum);
    to_write(arr, tnum, &osnum);
}

void Toview()
{
    system("clear");
    to_view(arr, &pnum, tnum);
}


