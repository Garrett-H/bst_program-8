//Authors: Ian Nevills, Garret Hay
//Date: 3/12/2018
//File: README.txt
//Description: Readme for Tree program

//Instructions

1: Place any number of .txt files in same directory as program.

2: If on a Linux use the make command in same directory as program to compile

3: use the ./ command and type "inventory" to run

4: choose amoung the selected number of choices

5: To end choose 8

Choices:
1: To insert an item into the tree
   -type key for the data you want to insert.
   -keys must be 1 word
   -data must be an integer

2: To search for an item in the current tree
   -to search for the data you want search for it using the key that it is given

3: Prints current tree in sorted order

4: Prints the current item that has the smallest key in the tree.
	
5: Prints the current item that has the largest key in the tree.

6: Saving the current tree to a file
   -first, type the FULL name of the file you want it saved to
   -if file already exist the program will override the current saved data on the file
    with the new data
   -if the file does not exist the program will make it in the directory of the program

7: Deleting an item in the current list
   -when prompted enter the EXACT key of the item you wish to delete

8: Exit program

//Design decisions

1: I add a lowest and highest pointer to the class. As to make choices "4 & 5" O(1) in time

2: When printing the tree it shows in the format of: ( key, data )

3: When saving to the file, the items will be formated: key data

//Known errors
