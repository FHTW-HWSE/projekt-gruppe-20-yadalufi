# Description

As a user I want to query direct and indirect neighbours of students<br />
So that contact tracing is possible

## Acceptance criteria

### 1.
---
Given that the file database exists and the table of seats is shown,<br />
When a student was selected<br />
Then I want to show the student’s name, student ID, the seat position and a menu containing the options “Show direct neighbours”, “Show indirect neighours”, “Edit student” & “Remove student”

### 2.
---
Given the direct neighbours are shown<br />
When a direct neighbour has been selected<br />
Then show the direct neighbours informa@on (student name, id, seat position) and a menu containing the options “Go back”, “Show direct neighbours”, “Show indirect neighours”, “Edit student” & “Remove student”

### 3.
---
Given the indirect neighbours are shown<br />
When a indirect neighbour has been selected<br />
Then show the indirect neighbours information (student name, id, seat position) and a menu containing the options “Go back”, “Show direct neighbours”, “Show indirect neighours”, “Edit student” & “Remove student”
