#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_STRINGS 500
#define MAX_LENGTH 1000

typedef struct {
    uint16_t id;
    char* name;
    char* gender;
    uint16_t yearOfBirth;
} typeStudent;

typedef struct 
{
    char* name;
    int freq;
} aName;

typedef struct 
{
    aName list[MAX_STRINGS];
    int lenght;
} nameArray;

typedef struct 
{
    char* year;
    int freq;
} aYearOfBirth;

typedef struct 
{
    aYearOfBirth list[MAX_STRINGS];
    int lenght;
} yearArray;

//<----------------------------------------------------------------------------------->

//Chuyen ki tu tu chuoi nay sang chuoi kia
void copyString(char* destination, const char* source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

//So sanh 2 chuoi: return 0 neu string1 > string2; return 2 neu string1 < string2; return 1 neu string1 = string2
int compareString(char* string1, char* string2){
    while ((*string1 != '\0') && (*string2 != '\0')){
        if (*string1 > *string2) return 0;
        if (*string1 < *string2) return 2;
        string1++; string2++;
    }
    if ((*string1 == '\0') && (*string2 == '\0')) return 1;
    if (*string1 == '\0') return 2;
    return 0;
}

//Lay ten sinh vien trong 1 dong du lieu cua file csv
char* getName(char string[]){
    char* temp;
    char* final = malloc(MAX_LENGTH);
    temp = final;
    int i = 0;
    while (string[i] != ','){
        if (string[i] != ' '){
            *final = string[i];
            i++;
            final++;
        }
        else {
            final = temp;
            i++;
        }
    }
    *final = '\0';
    return temp;
}

//Lay nam sinh sinh vien trong 1 dong du lieu cua file csv
char* getYear(char string[]){
    int countComma = 0; //Dem so luong dau ','
    int i = 0;
    while (countComma != 2){
        if (string[i] == ',') countComma++;
        i++;
    }
    i++;
    char* temp;
    char* final = malloc(MAX_LENGTH);
    temp = final;
    while (string[i] != ','){
        *final = string[i];
        i++;
        final++;
    }
    *final = '\0';
    return temp;
}

//Xoa ki tu xuong dong cua chuoi
void deleteNewlineCharacter(char* string){
    while (*string != '\0'){
        if (*string == '\n'){
            *string = '\0';
            return;
        }
        string++;
    }
}

//Them thong tin 1 sinh vien vao file csv 
void writeInfoStudent(){
     typeStudent student;

    //Nhap ID
    printf("Enter student id: ");
    scanf("%hu", &student.id);
    getchar(); // đọc ký tự '\n'

    //Nhap ho va ten
    printf("Enter student name: ");
    student.name = malloc(MAX_LENGTH); 
    fgets(student.name, MAX_LENGTH, stdin); 
    deleteNewlineCharacter(student.name);
    printf("%s\n", student.name);
    
    //Nhap gioi tinh
    printf("Enter student gender: ");
    student.gender = malloc(MAX_LENGTH);
    scanf("%s", student.gender);

    //Nhap nam sinh
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

//In ra thong tin sinh vien
void printInforStudents(){
    FILE *file = fopen("student.txt", "r");
    int count = -1; //Bien dem so thu tu
    char stt[MAX_LENGTH];
    char id[MAX_LENGTH];
    char name[MAX_LENGTH];
    char gender[MAX_LENGTH];
    char yearOfBirth[MAX_LENGTH];
    if (file != NULL){
        printf("%-15s %-15s %-25s %-15s %-15s\n", "STT", "ID", "Name", "Gender", "Year of birth"); //In ra dong ten cua cac cot
        char buffer[1000];
        while (fgets(buffer, sizeof(buffer), file) != NULL){    //Le Thi Khanh Thuong, Nu, 2002, 1212
            count++;
            int indexComma = 0; //Dem so luong dau ',' de xac dinh cot thong tin
            int indexBuffer = 0;
            int i = 0;
            //Tach thong tin tu 1 dong trong file csv
            while ((buffer[indexBuffer] != '\0') && (count > 0)){
                if (buffer[indexBuffer] == ','){
                    switch (indexComma)
                    {
                    case 0:
                        name[i] = '\0';
                        break;
                    case 1:
                        gender[i] = '\0';
                        break;
                    case 2:
                        yearOfBirth[i] = '\0';
                        break;
                    case 3:
                        id[i] = '\0';
                        break;

                    default:
                        break;
                    }
                    indexComma++;
                    i = 0;
                    indexBuffer++;
                } 
                else {
                    switch (indexComma)
                    {
                    case 0:
                        name[i] = buffer[indexBuffer];
                        i++;
                        break;
                    case 1:
                        gender[i] = buffer[indexBuffer];
                        i++;
                        break;
                    case 2:
                        yearOfBirth[i] = buffer[indexBuffer];
                        i++;
                        break;
                    case 3:
                        id[i] = buffer[indexBuffer];
                        i++;
                        break;

                    default:
                        break;
                    }
                    indexBuffer++;
                }
            }
            if (count > 0){
                itoa(count, stt, 10);
                deleteNewlineCharacter(id);
                printf("%-14s %-16s %-25s %-15s %-15s\n", stt, id, name, gender, yearOfBirth);
            }
        }
    } else {
        printf("ERROR!!!\n");
    }
}

//Sap xep thong tin sinh vien tang theo thu tu Anphabet dua theo ten 
void sortNameStudents(){
    FILE *file = fopen("student.txt", "r");
    if (file != NULL){
        int line = 0;   //STT cac dong trong file csv
        char tempString[MAX_LENGTH];
        char string[MAX_STRINGS][MAX_LENGTH]; //Mang string luu cac dong trong file csv
        while (fgets(string[line], sizeof(string[line]), file) != NULL){  
            deleteNewlineCharacter(string[line]);
            line++;
        }
        fclose(file);
        FILE *file = fopen("student.txt", "w");
        //Sap xep ten theo thu tu Anphabet
        for (int i = 1; i < line; i++){
            for (int j = i + 1; j < line; j++){
                if (compareString(getName(string[i]),getName(string[j])) == 0){
                    copyString(tempString, string[i]);
                    copyString(string[i], string[j]);
                    copyString(string[j], tempString);
                }
            }
        }
        //Ghi de vao file csv voi cac dong da duoc sap xep
        for (int i = 0; i < line; i++){
            if (i != (line - 1)) fprintf(file, "%s\n", string[i]);
            else fprintf(file, "%s", string[i]);
        }
    }
    else {
        printf("ERROR");
    }
    fclose(file);
}

//Thong ke so luong theo ten sinh vien
void analysisNameStudents(){
    FILE *file = fopen("student.txt", "r");
    nameArray listName; //Danh sach ten trong file csv
    listName.lenght = 0;
    if (file != NULL){
        char buffer[MAX_LENGTH];
        while (fgets(buffer, sizeof(buffer), file) != NULL){  
            char* tempName = getName(buffer);   //Lay ten sinh vien tu 1 dong trong file csv
            int i;
            //Duyet listname xem ten xuat hien chua
            for (i=0; i < listName.lenght; i++){
                if (compareString(tempName, listName.list[i].name) == 1){
                    listName.list[i].freq++;
                    break;
                }
            }
            //Gan neu ten chua xuat hien
            if (i == listName.lenght){
                listName.list[listName.lenght].name = tempName;
                listName.list[listName.lenght].freq = 1; 
                listName.lenght++; 
            }
        }
        //In ra thong ke
        for (int i=1; i<listName.lenght; i++){
            printf("%s: %d nguoi\n", listName.list[i].name, listName.list[i].freq);
        }      
    }
    else {
        printf("ERROR");
    }
    fclose(file);
}

//Thong so luong theo nam sinh sinh vien
void analysisYearOfBirthStudents(){
    FILE *file = fopen("student.txt", "r");
    yearArray listYear; //Danh sach nam sinh trong file csv
    listYear.lenght = 0;
    if (file != NULL){
        char buffer[MAX_LENGTH];
        while (fgets(buffer, sizeof(buffer), file) != NULL){  //Le Thi Khanh Thuong, Nu, 2002, 1212
            char* tempYear = getYear(buffer);
            //printf("%s\n", tempName);
            int i;
            for (i=0; i < listYear.lenght; i++){
                if (compareString(tempYear, listYear.list[i].year) == 1){
                    listYear.list[i].freq++;
                    break;
                }
            }
            if (i == listYear.lenght){
                listYear.list[listYear.lenght].year = tempYear;
                listYear.list[listYear.lenght].freq = 1; 
                listYear.lenght++; 
            }
        }
        for (int i=1; i<listYear.lenght; i++){
            printf("Nam %s: %d nguoi\n", listYear.list[i].year, listYear.list[i].freq);
        }      
    }
    else {
        printf("ERROR");
    }
    fclose(file);
    
}

int main(int argc, char const *argv[])
{
    int option = 0;
    while (option != 6){
        printf("-------------------------------------------------\n");
        printf("Nhan phim:\n");
        printf("1. De them thong tin mot sinh vien\n");
        printf("2. In danh sach thong tin sinh vien\n");
        printf("3. Sap xep ten sinh vien theo thu tu Alphabet\n");
        printf("4. Thong ke so luong ten sinh vien\n");
        printf("5. Thong ke so luong nam sinh sinh vien\n");
        printf("6. Thoat chuong trinh\n");
        printf("-------------------------------------------------\n");

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
        case 3:
            /* code */
            sortNameStudents();
            break;
        case 4:
            /* code */
            analysisNameStudents();
            break;
        case 5:
            /* code */
            analysisYearOfBirthStudents();
            break;
        default:
            break;
        }
    }

    return 0;
}
