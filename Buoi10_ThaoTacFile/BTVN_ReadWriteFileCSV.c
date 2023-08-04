#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    uint16_t id;
    char* name;
    char* gender;
    uint16_t yearOfBirth;
} typeStudent;


void writeInfoStudent(){
     typeStudent student;

    printf("Enter student id: ");
    scanf("%hu", &student.id);
    getchar(); // đọc ký tự '\n'

    printf("Enter student name: ");
    char buffer[100]; 
    fgets(buffer, sizeof(buffer), stdin); 
    student.name = malloc(strlen(buffer) + 1); 
    strcpy(student.name, buffer); 
    student.name[strlen(student.name) - 1] = '\0'; 
    printf("%s\n", student.name);
    //getchar();
    

    printf("Enter student gender: ");
    scanf("%s", buffer);
    student.gender = strdup(buffer);

    printf("Enter student year of birth: ");
    scanf("%hu", &student.yearOfBirth);

    //Ghi vao file
    FILE *file = fopen("student.txt", "a");
    if (file != NULL){
        fprintf(file, "\n%s, %s, %hu, %hu", student.name, student.gender, student.yearOfBirth, student.id);
        fclose(file);
        printf("HOAN THANH THEM THONG TIN\n");
    } else {
        printf("ERROR!!!\n");
    }

    free(student.name);
    free(student.gender);
}

void printInforStudents(){
    FILE *file = fopen("student.txt", "r");
    int count = -1;
    char* stt;
    char* id;
    char* name;
    char* gender;
    char* yearOfBirth;
    char* token;
    if (file != NULL){
        printf("%-15s %-15s %-25s %-15s %-15s\n", "STT", "ID", "Name", "Gender", "Year of birth");
        char buffer[1000];
        while (fgets(buffer, sizeof(buffer), file) != NULL){
            count++;
            token = strtok(buffer, ",");
            name = token;
            token = strtok(NULL, ",");
            gender = token;
            token = strtok(NULL, ",");
            yearOfBirth = token;
            token = strtok(NULL, ",");
            id = token;
            size_t len = strlen(id);
            int i;
            for (i = 0; i <= len; i = i + 1){
                if(id[i] == '\n') {  
                id[i] = ' '; 
                }     
            }
            if (count > 0){
                itoa(count, stt, 10);
                printf("%-14s %-16s %-25s %-15s %-15s\n", stt, id, name, gender, yearOfBirth);
            }
        }
    } else {
        printf("ERROR!!!\n");
    }
}

int main(int argc, char const *argv[])
{
    int option = 0;
    while (option != 3){
        printf("Nhan phim:\n");
        printf("1. De them thong tin mot sinh vien\n");
        printf("2. In danh sach thong tin sinh vien\n");
        printf("3. Thoat chuong trinh\n");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            /* code */
            writeInfoStudent();
            break;
        case 2:
            /* code */
            printInforStudents();
            break;
        default:
            break;
        }
    }

    return 0;
}
