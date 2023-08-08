#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student
{
    int id;
    char name[20];
    char dept[10];
    char sec;
    float cgpa;
    char phone[20];
    struct Student *nxt;
} *s1, *s2, *s3;

void List(struct Student *p)
{
    int i = 0;
    while (p != NULL)
    {
        i++;
        printf("\nStudent-%d: \n", i);
        printf("ID : %d\n", p->id);
        printf("Name : %s\n", p->name);
        printf("Department : %s\n", p->dept);
        printf("Section : %c\n", p->sec);
        printf("CGPA : %.2f\n", p->cgpa);
        printf("Phone No. : %s\n", p->phone);
        printf("Address : %x\n", p);
        p = p->nxt;
    }
}
int main()
{
    s1 = (struct Student *)malloc(sizeof(struct Student));
    s2 = (struct Student *)malloc(sizeof(struct Student));
    s3 = (struct Student *)malloc(sizeof(struct Student));
  
    s1->id = 1111;
    strcpy(s1->name, "Sajjadul Islam");
    strcpy(s1->dept, "CSE");
    s1->sec = 'H';
    strcpy(s1->phone, "01234567891");
    s1->cgpa = 4.00;
    s1->nxt = s2;
  
    s2->id = 2222;
    strcpy(s2->name, "Lima");
    strcpy(s2->dept, "CSE");
    s2->sec = 'H';
    strcpy(s2->phone, "01234567892");
    s2->cgpa = 2.50;
    s2->nxt = s3;
  
    s3->id = 3333;
    strcpy(s3->name, "John");
    strcpy(s3->dept, "CSE");
    s3->sec = 'H';
    strcpy(s3->phone, "01234567893");
    s3->cgpa = 3.00;
    s3->nxt = NULL;
  
    List(s1);
  
    return 0;
}
