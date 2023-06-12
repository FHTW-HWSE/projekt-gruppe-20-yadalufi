# Description

As a user I want to enter a student (last name, first name, ID)<br />
So that the corresponding student is assigned a seat (row-no./col.-no.)

## Acceptance criteria

### 1.
---
Given a basic plan has been created<br />
(and) an occupancy rate has been selected<br />
when the user enters a student's data<br />
then the student is assigned an empty seat.

### 2.
---
Given the plan is maxed out<br />
When the user enters another student's data<br />
then the user is told that there’s no seat left.

### 4.
---
Given the plan has been created<br />
when the user selects "add student"<br />
then the user can add a student to the plan.

### 5.
---
Given the user has created a room (i.e. assigned a seat to a student)
<br />
when the user wants to end the program/take a break<br />
then the plan is saved to a file.
