//Authors: Ian Nevills, Garret Hay
//Date: 3/12/2018
//File: README.txt
//Description: Readme for picture stacker program

//Instructions

1: Place any number of .txt files in same directory as program.

2: If on a Linux use the make command in same directory as program to compile

3: use the ./ command and type "inventory" to run

4: choose amoung the selected number of choices

5: type 'y' to continue with program or 'n' to end program.

Choices:
1: type the complete file name of file you wish to use
	 (for test.txt type "test.txt" for example)

2: type the complete file name of the file you wish to write to
	(program will create a file if output file is not already in directory)

3: Program will print the full current list that is available

4: type the EXACT item name you are looking for and program will print out format:
   	(item_found: number_in_inventory)
	
5: type the amounts of items you would like to see and program will print out any items at the amount and below
   in format:  (item_found
      	        next_item_found
		etc. )

6: type the name of the item you are adding and then type the amount of the item you will put in
   	(program will automatically sort the items into alphabetic order when adding items)

7: type the name of the item you want removed from the list

8: Exit program

//Design decisions

1: I have the "Add an item" use the sort_inserted function that auto sorts the added items instead of
   push_back or push_front

2: If on "lookup" function if does not find item in list it will return '-1' for amount of item

3: For "reverse lookup", it will only output what items were found and not their amounts

4: at the end of any action the program will ask if "you have more to do".  If choice is no then type 'n'
   or any character than 'y'.  The only way to continue with program is to type 'y' for yes after any actions

//Known errors

1: reading in a file will add an empty entry with the amount of the last item

2: any use of delete[] will throw a segmentation error.
       including: the delete_item function & the inventory's decontructor



