# Role-Based-Access-Control-System-Design
This is a sample Role Based Access Control Model with follwing details - 

Roles currently - 1) Admin ( Code - 0)
                  2) Developer ( Code - 1)
                  3) Tester ( Code - 2)

Operations that can be done by - 

ADMIN - 
1) Create a new user 
2) Delete an existing user
3) Check Roles assigned to loggedIn user ( can be exteded later to get the roles of other users as well )
4) Assign Roles 
5) Remove role
6) Read a file
7) Write in a file
8) Verify a file

DEVELOPER - 
1) Read a file
2) Write a file

TESTER - 
1) Read a file
2) Verify a file

Files Description - 
The project contains mainly 6 files - 

1) RBAC.cpp         -> The init file ( start )
2) User class       -> contain the User info.
3) Info class       -> contains the three user info ( USERNAME, USER_ID, ROLES )
4) Role class       -> contains the details of the Roles assigned to a particular user and the operation ptr 
                       to access the desired operations for a particular role. ( ROLE_NAME, ROLE_ID, Operation ptr)
5) Operations class -> This enlists the list of operations currently present in the RBAC system ( can be extended later to inculcate new operations )
6) DataBase class   -> To hold the users details
