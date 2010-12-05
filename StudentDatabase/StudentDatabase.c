/**
  * StudentDatabase.c
  * Implements a file based Student Database
  * see StudentDatabase.h
  * Includes code from Public Domain. see ../getch_.c and itoa()
  * 
  * Rajat Arora
  * rajat@rajatarora.info
  * http://github.com/rajatarora
  * 
  * Usage of this file is subject to license terms.
  * See https://github.com/rajatarora/BasicCAndDS/blob/master/LICENSE 
  * for more info.
  *
  * December 5, 2010
  *
  **/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StudentDatabase.h"
#include "../getch_.c"

/* Tables for encryption|decryption of metadata */
struct
{
    char inst[6];
    char code[4];
}institute[MAXINST] = { {"USIT",  "164"},
                        {"USBT",  "165"},
                        {"USCT",  "166"},
                        {"USEM",  "167"} };

struct
{
    char majr[9];
    char code[4];
    char icode[4];
}major[MAXMAJR] = { {"MCASE",    "045", "164"},
                    {"BTECHCSE", "046", "164"},
                    {"BTECHBT",  "047", "165"},
                    {"MTECHBT",  "048", "165"},
                    {"BTECHCT",  "049", "166"},
                    {"MTECHCT",  "050", "167"},
                    {"BTECHEM",  "051", "168"},
                    {"MTECHEM",  "052", "169"} };

/* Global vars of FILE, student and pointer-to-student */
FILE *f1;
student s1;
student *ps = &s1;

/* Generate roll number */
int genroll()
{
    int roll=1;
    f1=fopen("student.dat","ab+");

    if(f1==NULL)
        return 0;

    while(fread(ps,sizeof(s1),1,f1)==1)
        roll++;

    fclose(f1);
    return roll;
}

/* Input Student details and write to file */
void inputstu()
{
    int i, j;
    int ins, maj, yr, rol;
    char* pc;
    char stuname[MAXNAME];
    system("clear");
    printf("Enter Student Details:\n\n");
    printf("Name: ");
    fgets(stuname, MAXNAME-1, stdin);
    printf("%s\n", stuname);
    printf("\nInstitute (Choose One):\n");
    for(i=0; i<MAXINST; i++)
    {
        printf("%d. ", i+1);
        printf("%s\n", institute[i].inst);
    }
    printf("Your Choice (1-%d): ", MAXINST);
    scanf("%d", &ins);
    printf("\nMajor (Choose One):\n");
    for(i=0,j=1; i<MAXMAJR; i++)
    {
        if(atoi(major[i].icode)==atoi(institute[ins-1].code))
        {
            printf("%d. ", j++);
            printf("%s\n", major[i].majr);
        }
    }
    printf("Your Choice (1-%d): ", j-1);
    scanf("%d", &maj);
    printf("\nYear of Joining: ");
    scanf("%d", &yr);
    if(yr>=2000)
        yr-=2000;
    else
        yr-=1900;
    rol=genroll();
    pc=encrypt(rol,ins,maj,yr);
    strcpy(s1.meta,pc);
    printf("\nRoll No.: %s", s1.meta);
    assigncourses(s1.meta);
    printf("\n\nCourses: ");
    for(i=0; i<5; i++)
        printf("%s ", s1.courses[i]);
    assignmarks();
    strcpy(s1.name,stuname);
    f1=fopen("student.dat", "ab+");
    fwrite(&s1,sizeof(s1),1,f1);
    fclose(f1);
}

/* Encrypt various student details into a single string */
char* encrypt(int rol, int ins, int maj, int yr)
{
    static char meta[12];
    char tmp[5];
    if(rol<10)
    {
        meta[0]='0';
        meta[1]='0';
        itoa(rol,tmp,10);
        meta[2]=tmp[0];
    }
    else if(rol<100)
    {
        meta[0]='0';
        itoa(rol,tmp,10);
        meta[1]=tmp[0];
        meta[2]=tmp[1];
    }
    else
    {
        itoa(rol,tmp,10);
        meta[0]=tmp[0];
        meta[1]=tmp[1];
        meta[2]=tmp[2];
    }

    strcpy(tmp,institute[ins-1].code);
    meta[3]=tmp[0];
    meta[4]=tmp[1];
    meta[5]=tmp[2];

    strcpy(tmp,major[maj-1].code);
    meta[6]=tmp[0];
    meta[7]=tmp[1];
    meta[8]=tmp[2];

    itoa(yr,tmp,10);
    meta[9]=tmp[0];
    meta[10]=tmp[1];

    meta[11]='\0';

    return meta;
}

/* Assign courses to student based on his/her major */
void assigncourses(char* meta)
{
    char tmp[4];
    tmp[0]=meta[6];
    tmp[1]=meta[7];
    tmp[2]=meta[8];
    tmp[3]='\0';

    if(strcmp("045",tmp)==0||strcmp("046",tmp)==0)
    {
        strcpy(s1.courses[0],"IT");
        strcpy(s1.courses[1],"CSA");
        strcpy(s1.courses[2],"PDS");
        strcpy(s1.courses[3],"FCS");
        strcpy(s1.courses[4],"PMS");
    }
}

/* Assign marks to various courses taken by a student */
void assignmarks()
{
    int i;
    printf("\n\nAssign Marks:\n");

    for(i=0; i<5; i++)
    {
        printf("%s: ", s1.courses[i]);
        scanf("%d", &s1.marks[i]);
    }
}

/* Display all registered students on screen */
void dispstu()
{
    int i=1;
    system("clear");
    printf("The following students are registered:\n\n");
    f1=fopen("student.dat","rb");
    while(fread(ps,sizeof(s1),1,f1))
        printf("%d %s %s\n", i++, ps->name, ps->meta);
    getch();
    fclose(f1);
}

/* itoa */
/* The itoa code is in the puiblic domain */
char* itoa(int value, char* str, int radix) {
    static char dig[] =
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz";
    int n = 0, neg = 0;
    unsigned int v;
    char *p, *q, *ret;
    char c;
    int i,j;

    if (radix == 10 && value < 0) {
        value = -value;
        neg = 1;
    }
    v = value;
    do {
        str[n++] = dig[v%radix];
        v /= radix;
    } while (v);
    if (neg)
        str[n++] = '-';
    str[n] = '\0';
    ret=(char*)malloc((n+1)*sizeof(char));
    for(i=n-1,j=0;i>=0;i--,j++)
    	ret[i]=str[j];
    ret[n]='\0';
    strcpy(str,ret);
    free(ret);
    return str;
}
