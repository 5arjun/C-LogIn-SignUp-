# C-LogIn-SignUp-Program
This project was created after taking a programming in C class at Temple University, using basically everything 
  learned and incorporating it into one thing. This is a personal project and has nothing to do with the class.
  
Everything is done in the terminal.
Pretty simple program which involes basic login or sign up options.
Program opens and reads a file which contains the usernames and passwords for users that are 
  already in the system. It is a csv file (So each username and. pasword contains a comma in-between)
  the read users are put into a list of usernames and passwords in a struct.
When the user decides to login, the program checks to see if their login matches any of those in the 
  list of structs. Both username and password has to match or it will ask the user again for another entry
If the user wants to sign up, the program writes to the end of the file whatever the user wants their
  username and password to be. The next time the program is ran, it will be in the logins file so they can 
  login successfully.
