#include<stdio.h>
#include<stdlib.h>
#define MAX_P 10
#define MAX_N 80

typedef struct information
{
    char name[20];
    char id[20];
    char psw[20];
    char sch[10];
    char city[10];
    char age[10];
    char title[80][30];
    char memo [80][200];
    int stime[80][6];

}info;

info arr[10];
int pnum = 0;
int tnum[10] = {0,};
int osnum = 0;
