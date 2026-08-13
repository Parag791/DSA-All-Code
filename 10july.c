#include <stdio.h>

struct dob
{
    int day, month, year;
};

struct student_info
{
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void displayValue(struct student_info s)
{
    printf("\nUsing Call by Value:\n");
    printf("Roll No: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("CGPA: %.2f\n", s.CGPA);
    printf("DOB: %d/%d/%d\n",
           s.age.day, s.age.month, s.age.year);
}

void displayAddress(struct student_info *s)
{
    printf("\nUsing Call by Address:\n");
    printf("Roll No: %d\n", s->roll_no);
    printf("Name: %s\n", s->name);
    printf("CGPA: %.2f\n", s->CGPA);
    printf("DOB: %d/%d/%d\n",
           s->age.day, s->age.month, s->age.year);
}

int main()
{
    struct student_info s1;

    printf("Enter Roll No: ");
    scanf("%d", &s1.roll_no);

    printf("Enter Name: ");
    scanf("%s", s1.name);

    printf("Enter CGPA: ");
    scanf("%f", &s1.CGPA);

    printf("Enter DOB (dd mm yyyy): ");
    scanf("%d %d %d",
          &s1.age.day,
          &s1.age.month,
          &s1.age.year);

    displayValue(s1);
    displayAddress(&s1);

    return 0;
}
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

#include <stdio.h>

struct employee
{
    int id;
    char name[50];
    float salary;
    char city[50];
};

void display(struct employee *e)
{
    printf("\nID: %d", e->id);
    printf("\nName: %s", e->name);
    printf("\nSalary: %.2f", e->salary);
    printf("\nCity: %s\n", e->city);
}

int main()
{
    struct employee emp[3];
    int i;

    for(i = 0; i < 3; i++)
    {
        printf("\nEnter details of Employee %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &emp[i].id);

        printf("Name: ");
        scanf("%s", emp[i].name);

        printf("Salary: ");
        scanf("%f", &emp[i].salary);

        printf("City: ");
        scanf("%s", emp[i].city);
    }

    printf("\nEmployee Details:\n");

    for(i = 0; i < 3; i++)
    {
        display(&emp[i]);
    }

    return 0;
}
