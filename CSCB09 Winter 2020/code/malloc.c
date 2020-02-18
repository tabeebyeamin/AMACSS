#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char first[6] = "Monday";
    char *second = "Tuesday";
    char *third = malloc(9*sizeof(char));
    strcpy(third, "Wednesday");

    printf("first: %s, second: %s, third: %s\n", first, second, third);

    first[3] = '\0';
    // or strcpy(first, "Mon");
    // strcpy(second, "Tue"); SEG FAULT
    // second[3] = '\0'; SEG FAULT


    third[3] = '\0'; 
    // or strcpy(third, "Wed");
    printf("first: %s, second: %s, third: %s\n", first, second, third);

    // array string_list of 3 pointers to char and point to the strings
    char *string_list[3];
    string_list[0] = first;
    string_list[1] = second;
    string_list[2] = third;

    for (int i = 0; i < 3; i++){
        printf("%s\n",string_list[i]);
    }
    /*
    printf("%d\n", string_list[0]);
    printf("%d\n", string_list[1]);
    printf("%d\n", string_list[2]);
    printf("%d\n", &first);
    printf("%d\n", second);
    printf("%d\n", third);*/
}