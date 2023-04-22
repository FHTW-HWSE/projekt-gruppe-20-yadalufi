# Contribution Guide

Below are some guidelines on how to get started in your terminal with cloning the project, committing changes, and branching.

## Cloning the Project

To clone this project, follow these steps:

1. Open the terminal or command prompt
2. Navigate to the directory where you want to clone the project
3. Run the following command:<br />
```sh
git clone git@github.com:FHTW-HWSE/projekt-gruppe-20-yadalufi.git
```

## Committing Changes

To commit changes to the project, follow these steps:

1. Make your changes to the code or files in the project
2. Open a terminal or command prompt
3. Navigate to the project directory
4. Run the following command to stage your changes:<br />
```sh
git add .
```

This will stage all changes you made in the project directory.

5. Run the following command to commit your changes locally:
```sh
git commit -m "#[item-id] your commit message here"
```

Replace `[item-id]` with your item id and write a brief description of the changes you made.

## Branching

To branch the project, follow these steps:

1. Open a terminal or command prompt
2. Navigate to the project directory
3. Run the following command to create a new branch:
```sh
git checkout -b feature/item-[item-id]
```

Replace `[item-id]` with the number of the item you are working on.

4. Make your changes to the code or files in the project
5. Run the following command to stage your changes:
```sh
git add .
```

This will stage all changes you made in the project directory.

6. Run the following command to commit your changes:
```sh
git commit -m "#[item-id] your commit message here"
```

Replace `[item-id]` with your item id and write a brief description of the changes you made.

7. Run the following command to push your changes to the new branch:
```sh
git push origin feature/item-[item-id]
```

Replace `[item-id]` with the id of the item you are working on.
