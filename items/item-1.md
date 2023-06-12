# Description

As a user<br />
I want to be able to define the room size by height and width (rows and cols)<br />
So that the plan matches the actual classroom

## Acceptance criteria

### 1.
---
Given that the user is on the room size configuration screen<br />
when the user types in the values of the room's height and width in rows and columns as integers only<br />
then the system should accept the input and save the values in a struct.

### 2.
---
Given that the user has entered the values of the room's height and width<br />
when the user hits enter,<br />
then the system should validate the input values to ensure that they are within an acceptable range and display an error message if the values are invalid.

### 3.
---
Given that the input values for the room's height and width have been saved<br />
when the user selects "show room"<br />
then the system should display a graphical representation of the defined room size as a table that matches the actual classroom.

### 4.
---
Given that the user puts in values for the room's height and width,<br />
when the input values are negative/invalid,<br />
then the system should refuse the values and display an error message.
