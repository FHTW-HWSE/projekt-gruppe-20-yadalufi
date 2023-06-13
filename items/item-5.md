# Description

As a user I want to save the plan including student IDs and assigned seats<br />
So that it can be used for contact tracing.

## Acceptance criteria

### 1.
---
Given that the user has launched the command line program,<br />
when the user did not provide a filename as program argument,<br />
then the user is prompted for a filename.

### 2.
---
Given that the user has launched the command line program with an argument for a filename like “./program filename.txt”,<br />
when the file does not exist,<br />
then an empty file is created.

### 3.
---
Given that the user has launched the command line program with an argument for a filename like “./program filename.txt”,<br />
when the file already exists,<br />
then update the file content with the updated plan.
