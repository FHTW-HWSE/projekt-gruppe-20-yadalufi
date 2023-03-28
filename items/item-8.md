# Description

As a user I want to put student information (ID, name) in a data type<br />
So that I can use it in assigning seats and contact tracing

## Acceptance criteria

### 1.
---
Given a basic plan has been created,<br />
When a seat was selected,<br />
Then the student name should be entered.

### 2.
---
Given the student name is empty,<br />
When the user should enter the student name,<br />
Then a message will appear “The name is required”.

### 3.
---
Given the student name has been entered,<br />
When the student name contains non-alpha (a-z, A-Z) characters,<br />
Then a message will appear “The name must contain only alphabetic characters”.

### 4.
---
Given the student name has been entered,<br />
When the name is stored in a struct,<br />
Then the student ID should be entered.

### 5.
---
Given the student ID is empty,<br />
When the user should enter the student ID,<br />
Then a message will appear “The student ID is required”.

### 6.
---
Given name and ID were passed in,<br />
When both is valid,<br />
Then update the file database and show “Student has been saved”.
