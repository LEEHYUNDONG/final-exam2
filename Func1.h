#include<stdio.h>
#include<string.h>
#include<unistd.h>

void Loaddata1(info *arr, int *pnum)
{
    FILE *file = fopen("a.txt", "rb");
    if(file ==NULL)
    {
        return;
    }
    while(1)
    {
        fread(arr[*pnum].name, sizeof(arr[*pnum].name), 1, file);
        fread(arr[*pnum].id, sizeof(arr[*pnum].id), 1, file);
        fread(arr[*pnum].psw, sizeof(arr[*pnum].psw), 1, file);
        fread(arr[*pnum].sch, sizeof(arr[*pnum].sch), 1, file);
        fread(arr[*pnum].city, sizeof(arr[*pnum].city), 1, file);
        fread(arr[*pnum].age, sizeof(arr[*pnum].age), 1, file);
        
        if(feof(file) != 0)
        {
            break;
        }
        (*pnum)++;
    }
    fclose(file);
}
void Savedata1(info *arr, int *pnum)
{
    int i;
    FILE *file = fopen("a.txt", "wb");
    if(file ==NULL)
    {
        return;
    }
    for(i = 0;i < (*pnum);i++)
    {
        fwrite(arr[i].name, sizeof(arr[i].name), 1, file);
        fwrite(arr[i].id, sizeof(arr[i].id), 1, file);
        fwrite(arr[i].psw, sizeof(arr[i].psw), 1, file);
        fwrite(arr[i].sch, sizeof(arr[i].sch), 1, file);
        fwrite(arr[i].city, sizeof(arr[i].city), 1, file);
        fwrite(arr[i].age, sizeof(arr[i].age), 1, file);
       
    }
    fclose(file);
}
char getch()
{
    char str[10];
    char ch;

    fgets(str, sizeof(str), stdin);
    fflush(stdin);
    ch = str[0];

    return ch;
}

void sign_up(info *arr, int *pnum)
{
    if((*pnum) < MAX_P)
    {
    int i, j;
    int t = 0;
    char *psw;

    printf("Name : ");
    fgets(arr[*pnum].name, sizeof(arr[*pnum].name), stdin);
    arr[*pnum].name[sizeof(arr[*pnum].name) - 1] = '\0';
    
    if((*pnum) > 0)
    {
        while(1)
        {
            t = 0;
            printf("ID : ");
            fgets(arr[*pnum].id, sizeof(arr[*pnum].id), stdin);
            arr[*pnum].id[sizeof(arr[*pnum].id) - 1] = '\0';
            for(j = 0;j < (*pnum);j++)
            {
                if(strncmp(arr[j].id, arr[*pnum].id, sizeof(arr[*pnum].id)) != 0)
                {
                    t++;
                }
                else
                {
                    printf("Already existing ID\n");
                    break;
                }
            }
            if(t ==(*pnum))
            {
                break;
            }
        }
    }
    else if((*pnum) == 0)
    {
        printf("ID : ");
        fgets(arr[*pnum].id, sizeof(arr[*pnum].id), stdin);
        arr[*pnum].id[sizeof(arr[*pnum].id) - 1] = '\0';
    }

    psw = getpass("Password : ");

    printf("Name : ");
    fgets(arr[*pnum].name, sizeof(arr[*pnum].name), stdin);
    arr[*pnum].name[sizeof(arr[*pnum].name) - 1] = '\0';

    printf("School : ");
    fgets(arr[*pnum].sch, sizeof(arr[*pnum].sch), stdin);
    arr[*pnum].sch[sizeof(arr[*pnum].sch) - 1] = '\0';

    printf("City : ");
    fgets(arr[*pnum].city, sizeof(arr[*pnum].city), stdin);
    arr[*pnum].city[sizeof(arr[*pnum].city) - 1] = '\0';

    printf("Age : ");
    fgets(arr[*pnum].age, sizeof(arr[*pnum].age), stdin);
    arr[*pnum].age[sizeof(arr[*pnum].age) - 1] = '\0';
    (*pnum)++;
    }
}
void sign_in(info *arr, int *pnum, int *osnum)
{
    char *psw;
    char id[20];
    int i, j;
    int pn;
    int flag = 0;

    while(flag != 2)
    {
        printf("ID : ");
        fgets(id, sizeof(id), stdin);
        fflush(stdin);
        id[sizeof(id) - 1] = '\0';
    
        for(i = 0;i < (*pnum);i++)
        {
            if(strncmp(arr[i].id, id, sizeof(id)) == 0)
            {
                pn = i;
                flag++;
                break;
            }
        }

        psw = getpass("Password : ");
            if(strncmp(arr[pn].psw, psw, sizeof(psw)) == 0)
            {
                flag++;
                (*osnum) = pn;
            }
            else
            {
                printf("Acess Denied\n");
                flag = 0;
            }
        }
    }
}

void list_of_user(info *arr, int *pnum)
{
    int i;
    
    for(i = 0;i < *pnum;i++)
    {
        printf("Name : %s", arr[i].name);
        printf("Id : %s", arr[i].id);
        printf("City : %s", arr[i].city);
        printf("School : %s", arr[i].sch);
        printf("Age : %s", arr[i].age);
    }
}

