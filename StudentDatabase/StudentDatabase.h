/**
  * StudentDatabase.h
  * Implements a file based Student Database
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
  
#define MAXINST 4
#define MAXMAJR 8
#define MAXNAME 20

/* Declare the student 'data-type' */
typedef struct
{
    char name[MAXNAME];
    char meta[12];
    char courses[5][25];
    int marks[5];
}student;

/* Generate Roll Number */
int genroll();

/* Encrypt|Decrypt Student metadata */
char* encrypt(int,int,int,int);
void decrypt();

/* Register|Remove|Edit|Display Student Details */
void inputstu();
void remstu();
void editstu();
void dispstu();

/* Search for a Student in the database */
void searchstu();

/* Assign courses|marks to a Student */
void assigncourses();
void assignmarks();

/* Finally, a non-std library function */
char* itoa(int,char*,int);
