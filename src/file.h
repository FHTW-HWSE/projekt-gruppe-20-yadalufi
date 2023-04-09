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

room* create_room ();
int free_room (room *new_room);    


#endif /* FILE_H_ */
