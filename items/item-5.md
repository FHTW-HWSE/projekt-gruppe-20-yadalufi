# Description

As a user I want to save the plan including student IDs and assigned seats<br />
So that the user can edit it later or so that it can be used for contact tracing

## Acceptance criteria

### 1.
---
Given that the user has launched the command line program without an argument,<br />
when the user hits enter and launches the program,<br />
then show a help menu to tell the user that a filename is required and has to be passed in.

### 2.
---
Given that the user has launched the command line program with an argument for a filename like “./program filename.txt”,<br />
when the file does not exist,<br />
then create an empty file and insert the plan including student IDs and assigned seats.

### 3.
---
Given that the user has launched the command line program with an argument for a filename like “./program filename.txt”,<br />
when the file already exists,<br />
then update the file content with the updated plan.
