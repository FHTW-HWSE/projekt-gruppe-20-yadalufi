# Description

As a user I want to have a well-structured user interface<br />
So that I can insert the student data.

## Acceptance criteria

### 1.
---
Given that the file database exists,<br />
When no plan was created before<br />
Then the program shows a menu containing the option “Create Plan”.

### 2.
---
Given that the file database exists,<br />
When the basic plan has already been created<br />
Then the program shows a menu containing the options “Show room”, "Show seats" and “Add student”.

### 3.
---
Given that plan has been created,<br />
When the user selects "Show room (list)"<br />
Then the program shows a list containing the added students.

### 4.
---
Given that plan has been created,<br />
When the user selects "Show seat pattern"<br />
Then the program shows a plan displaying the seats.

### 5.
---
Given that plan has been created,<br />
When the user selects "Add student"<br />
Then the program asks for the student's data.