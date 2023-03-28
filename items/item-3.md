# Description

As a user I want to be able to generate 3 different occupancy patterns/percentages (25/50/100)<br />
So that I can map out optimized seating plans

## Acceptance criteria

### 1.
---
Given a basic plan (rows/columns) has been created<br />
when I choose a valid percentage (25/50/100)<br />
then the final plan (rows/columns/available seats) is generated

### 2.
---
Given a basic plan has been created<br />
when I enter an invalid input (letters, numbers != 25/50/100, special characters, space)<br />
then I’m asked to enter a valid input (25/50/100)

### 3.
---
Given I have chosen a seating pattern (25/50/100)<br />
when I want to change the pattern before entering student<br />
then I can edit the plan

### 4.
---
Given I have entered min. 1 student in the plan<br />
when I want to change the pattern<br />
then I’m denied and asked to create a new plan
