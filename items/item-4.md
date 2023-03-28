# Description

As a user I want to enter a student ID<br />
So that the corresponding student is assigned a seat (row-no./col.-no.)

## Acceptance criteria

### 1.
---
Given a basic plan has been created<br />
(and) a pattern has been selected<br />
when I enter a student ID<br />
then the student is assigned an empty seat

### 2.
---
Given a student ID has already been entered<br />
when I enter it again<br />
then I’m told that it is already in the plan<br />

### 3.
---
Given the plan is maxed out<br />
When I enter a student ID<br />
then I’m told that there’s no seat left

### 4.
---
Given the plan including seating pattern has been created<br />
when I open the project<br />
then I can see the number of available seats

### 5.
---
Given the plan including seating pattern has been created<br />
when I enter an input which does not correspond to a student<br />
Then I’m told that the student data has not been entered yet

### 6.
---
Given I have made changes to the current project (i.e. assigned a seat to a student)
<br />
when I want to end the project/take a break<br />
then I can save the current project
