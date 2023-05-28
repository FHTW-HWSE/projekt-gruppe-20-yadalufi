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

room* create_room ();
int free_room (room *new_room);    
student* create_student ();
int free_student (student *new_student);



#endif /* FILE_H_ */
