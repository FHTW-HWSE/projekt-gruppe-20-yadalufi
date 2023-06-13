/**
 * @file        file.h
 * @brief       Header file for file.cpp
 */

#ifndef FILE_H_
#define FILE_H_

/**
 * @brief       Structure for date
 *
 * @param       year
 * @param       month
 * @param       day
 */
typedef struct
{
    int year;
    int month;
    int day;
} date;

/**
 * @brief       Structure for room
 *
 * @param       room_name
 * @param       exam_name
 * @param       exam_date
 * @param       row
 * @param       col
 * @param       occupancy
 */
typedef struct
{
    char *room_name;
    char *exam_name;
    date exam_date;
    int row;
    int col;
    int occupancy;
} room;

/**
 * @brief       Structure for student
 *
 * @param       first_name
 * @param       last_name
 * @param       student_id
 * @param       col
 * @param       row
 * @param       next
 * @param       students
 */
typedef struct student
{
    char *first_name;
    char *last_name;
    char *student_id;
    int col;
    int row;
    struct student *next;
    struct student **students; // struct student *students[]
} student;

char *allocate_exam_name(room *new_room);
char *allocate_room_name(room *new_room);
room *allocate_new_room(room *new_room);
room *new_room();
void set_room_name(room *p_room, char *name);
void set_exam_name(room *p_room, char *name);
int valid_input_year(int input);
int prompt_exam_date_year();
int valid_input_month(int input);
int prompt_exam_date_month();
int valid_input_day(int input);
int prompt_exam_date_day();
room *create_room(room *r_room, student *r_head);
int free_room(room *new_room);
int number_seats(int row, int col);
int available_seats(int row, int col, int occupancy);
int show_room(room *rm, student *head);
int room_set_occupancy(room *p_room, int selection);
void show_seat_pattern(room *sp_room);

#endif /* FILE_H_ */
