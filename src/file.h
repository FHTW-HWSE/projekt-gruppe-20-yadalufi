#ifndef FILE_H_
#define FILE_H_


typedef struct {
    int year;
    int month;
    int day;
} date;

typedef struct {
    char* room_name;
    char* exam_name;
    date exam_date;
    int row;
    int col;        
    int occupancy;
} room;

typedef struct student {
    char *first_name;
    char *last_name;
    char *student_id;
    int col;
    int row;
    struct student *next;
    struct student **students; // struct student *students[]
} student;

room *new_room();
room* create_room();
void set_room_name(room *p_room, char *name);
void set_exam_name(room *p_room, char *name);
int prompt_exam_date_year();
int prompt_exam_date_month();
int free_room(room *new_room);
student* create_student();
int free_student(student *new_student);
int show_room(room *rm, student *head);


#endif /* FILE_H_ */
