// Name: Areeba Tariq
// Reg No: 23-ntu-cs-1139
// Task 5: Student Database Thread

#include <stdio.h>
#include <pthread.h>

typedef struct {
    int student_id;
    char name[50];
    float gpa;
} Student;

int countDean = 0; // Count eligible students

void *checkStudent(void *arg) {
    Student *s = (Student *)arg;
    
    printf("\nStudent ID: %d\nName: %s\nGPA: %.2f\n", 
           s->student_id, s->name, s->gpa);

    if(s->gpa >= 3.5) {
        printf("Status: Dean's List ✅\n");
        countDean++;
    } else {
        printf("Status: Not Eligible ❌\n");
    }

    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    Student s1 = {101, "Areeba", 3.8};
    Student s2 = {102, "Hamna", 3.2};
    Student s3 = {103, "Ali", 3.6};

    pthread_create(&t1, NULL, checkStudent, &s1);
    pthread_create(&t2, NULL, checkStudent, &s2);
    pthread_create(&t3, NULL, checkStudent, &s3);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("\nTotal students on Dean's List: %d\n", countDean);
    return 0;
}
