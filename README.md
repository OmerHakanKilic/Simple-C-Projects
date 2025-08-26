# ** Beginner-Friendly C Projects**

### **1\. Simple Calculator**
#### simple-calculator.c file

A program that takes two numbers and an operator from the user and performs the corresponding calculation.

**Requirements:**

* Prompt the user to enter two numbers.  
* Prompt the user to enter an operator (+, \-, \*, /).  
* Use a **switch statement** or a series of **if-else statements** to perform the correct operation.  
* Handle division by zero by printing an error message.  
* Print the result of the calculation.

**Key Concepts:**

* Variables and data types  
* Basic I/O (printf and scanf)  
* Arithmetic operators  
* Conditional statements (if-else or switch)

### **2\. Guess the Number Game**
#### guess-the-number-game.c

A simple game where the computer generates a random number and the user has to guess it.

**Requirements:**

* Generate a **random number** between 1 and 100\.  
* Use a **do-while loop** to repeatedly prompt the user for a guess.  
* After each guess, tell the user if their guess was too high, too low, or correct.  
* Keep track of the number of guesses and print it when the user wins.  
* End the game when the user guesses the correct number.

**Key Concepts:**

* Loops (do-while or while)  
* Random number generation (stdlib.h and time.h)  
* Conditional logic (if-else)  
* User input validation

### **3\. Basic To-Do List Manager**
#### to-do.c file

A command-line program that lets you add and view to-do items. The list will be stored in memory and reset each time the program is run.

**Requirements:**

* Display a menu with options: "Add a new to-do item" and "View all to-do items".  
* Use a **switch statement** to handle the menu options.  
* Store the to-do items in an **array of strings**.  
* When a user adds an item, store it in the next available slot in the array.  
* When a user views the list, loop through the array and print each item.

**Key Concepts:**

* Arrays  
* Strings  
* Functions  
* Loops (for or while)  
* Menu-driven programs

### **4\. Simple Contact Book**
#### simple-contact-book.c file

A program that stores and displays a list of contacts with a name and phone number. The contacts will be stored in memory and disappear when the program ends.

**Requirements:**

* Define a **struct** for a contact, containing a string for the name and a string for the phone number.  
* Create an array of these structs to hold multiple contacts.  
* Implement a function to add a new contact by taking the name and number as input.  
* Implement a function to display all contacts in the list.  
* Provide a menu for the user to choose to add or view contacts.

**Key Concepts:**

* struct (structures)  
* Arrays of structs  
* Functions with struct parameters

### **5\. String Reverser**
#### string-reverser.c file

A program that takes a string from the user and prints it in reverse.

**Requirements:**

* Prompt the user to enter a string.  
* Read the string into a character array.  
* Write a function that takes the string as input and returns the reversed string. You'll need to use a loop and two index variables (one from the start, one from the end) to swap characters.  
* Print the original and the reversed string.

**Key Concepts:**

* Character arrays and strings  
* Loops (for)  
* Pointers  
* String length (strlen)


### **6\. Student Grade Calculator**
#### grade-calculator.c file

A program that reads student names and grades, calculates their average, and determines if they passed or failed.

**Requirements:**

* Prompt the user for the number of students.  
* Use a loop to get the name and three grades for each student.  
* Store the data in an **array of structs**, where each struct holds the student's name and their three grades.  
* Create a function that calculates the average grade for a student.  
* After all data is entered, loop through the student array and print each student's name, their average grade, and whether they passed (average \>= 60\) or failed.

**Key Concepts:**

* structs  
* Arrays of structs  
* Functions  
* Loops

### **7\. Simple Timer**
#### simple-timer.c file

A program that acts as a simple countdown timer.

**Requirements:**

* Prompt the user to enter a duration in seconds.  
* Use a **while loop** that runs as long as the remaining time is greater than zero.  
* Inside the loop, print the remaining time and then use **sleep()** from unistd.h to pause the program for one second.  
* After the loop, print a message like "Time's up\!".

**Key Concepts:**

* Loops (while)  
* Using system library functions (sleep)  
* Variables  
* Conditional statements

### **8\. Palindrome Checker**
#### palindrome-checker.c file

A program that checks if a string is a palindrome (reads the same forwards and backward).

**Requirements:**

* Prompt the user to enter a word or phrase.  
* Read the input string.  
* Write a function that returns a 1 if the string is a palindrome and a 0 otherwise.  
* Inside the function, you'll need to compare the characters from the beginning and end of the string, moving inward.  
* Print a message telling the user if their input is a palindrome or not.

**Key Concepts:**

* Strings and character arrays  
* Loops (for or while)  
* Conditional statements  
* Pointers
