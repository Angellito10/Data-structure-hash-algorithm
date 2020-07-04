# Data-structure-hash-algorithm
DS-hash-algorithm

 First use this command in Visual Code if you want to compile and run the code (clang++ -std=c++17) :)

In the real codding world, Writing a code isn’t about learning the syntax, It’s more  about the runtime for  the code and the time complexity, also beside on 
the algorithm we will use when we writing code or developing the application. Overall the evaluate level of knowledge and understanding the data structure 
algorithms concepts as a practice. Hashing algorithm comes as the most important data structure algorithm, That nowadays used, Which is designed to use a 
special function called the Hash function, that use to map a given value with a particular key for faster access of elements, Hashing method is use to index 
and retrieve items in a database as it is faster to search that specific item using the shorter hashed key instead of using its original value. The efficiency 
of mapping depends of the efficiency of the hash function used. 
There are several type of hash function: 
1.	Truncation
2.	Modular Arithmetic (Division)
3.	Digit Extraction Method

It may happen that the hashing technique is used to create an already used index of the array.  The situation where a newly inserted key maps to an already 
occupied slot in the hash table is called collision and must be handled using some collision handling technique. There a numerous techniques that can be 
used to solve collision such as:
1.	Linear Probing
2.	Quadratic Probing
3.	Chaining.

For the more understanding I have wrote this code to help me to understand the hash algorithm  in practical, the program that I had wrote  will store the staff 
information into a static array/dynamic array(STL) as follows:

1.	Staff ID no (key) : 8 integer numbers starting from 90020001 until 90020999
2.	Staff Name : string
3.	Staff Position (Dean/ Deputy Dean / Head of Department / Head of Program / Lecturer) : string. 

I used Modular Arithmetic method for hash function and handle collision (if any) using Quadratic Probing method as well as produce the correct index locations 
according to applied technique.
Hash function = key mod table size; Table size = 100.
