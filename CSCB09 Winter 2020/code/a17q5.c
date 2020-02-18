#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int student_number;
    char *last_name;
    struct student *next;
} Student;

Student *insert_new_student(Student *list, int newStudentNo, char *newName) {
    Student *newStudent = (Student *)malloc(sizeof(Student));
    newStudent->student_number = newStudentNo;
    newStudent->last_name = (char *)malloc(strlen(newName)*sizeof(char));
    strcpy(newStudent->last_name, newName);
    if (!list){
        return newStudent;
    }
    Student *prev;
    Student *curr = list;
    // loop until you find equal or larger last name or end of list
    while (curr && strcmp(newName, curr->last_name)){
        prev = curr;
        curr = curr->next;
    }
    if (curr){
        char *matchedName = curr->last_name;
        int matchedNum = curr->student_number;
        // while name match, loop until larger number or end of list
        while (curr && ! strcmp(matchedName, curr->last_name) && newStudentNo > matchedNum){
            prev = curr;
            curr = curr->next;
        }
    }
    newStudent->next = curr;
    prev->next = newStudent;
    return list;
}

int main(){
    Student *head = NULL;

    head = insert_new_student(head, 1, "A");
    head = insert_new_student(head, 2, "B");

    head = insert_new_student(head, 3, "B");

    head = insert_new_student(head, 5, "C");

    head = insert_new_student(head, 6, "D");

    Student *curr = head;
    while (curr){
        printf("%s %d\n", curr->last_name, curr->student_number);
        curr = curr->next;
    }
    
    printf("----------insert B w/ 30---------\n");
    head = insert_new_student(head, 30, "B");

    curr = head;
    while (curr){
        printf("%s %d\n", curr->last_name, curr->student_number);
        curr = curr->next;
    }


}