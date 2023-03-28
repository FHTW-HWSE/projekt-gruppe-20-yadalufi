# Description

As a user<br />
I want to be able to define the room size by height and width (rows and cols)<br />
So that the plan matches the actual classroom

## Acceptance criteria

### 1.
---
Given that I am on the room size configuration screen<br />
when the user types in the values as integers only of the room's height and width in rows and columns<br />
then the system should accept my input and save the values in a struct.

### 2.
---
Given that I have entered the values of the room's height and width<br />
when the user hits enter,<br />
then the system should validate the input values to ensure that they are within an acceptable range and display an error message if the values are invalid.

### 3.
---
Given that the input values for the room's height and width have been validated<br />
when the user hits enter<br />
then the system should display a graphical representation of the defined room size as a table that matches the actual classroom.

### 4.
---
Given that I am a user,<br />
when the user puts negative/wrong values of the room’s height and width in,<br />
then the system should refuse my values and display an error message.
