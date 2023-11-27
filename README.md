# FakeFileSystem - C2026900

Fake file system in dynamic/heap memory that the user can interact with via console inputs (i.e. no GUI).  A Visual Studio 2022 starting project has been provided with some basic code that allows you to enumerate your real file system and extract all relevant information.  The commands you interact with should only modify your in-memory representation of that file system and it must not make changes back to the real file system (i.e. if you ask your application to remove a file, it only removes the the objects you are using to represent that file in your application’s dynamic memory and not a real file on disk).
Interact with your fake file system (FFS) via a Windows-style command prompt (cmd.exe).  An example of the application running is demonstrated below:


Initialisation complete...
\ :> dir
12/09/2023  09:42	  <DIR>		DirectoryName1
12/04/2023  13:43		12,432	MyFile.tmp
08/10/2022  15:32	  <DIR>		DirectoryName2
	1 File(s)		12,432 total bytes
	2 Dir(s)
\ :> cd DirectoryName1
\DirectoryName1 :> dir
	...


The command prompt shows the current directory and path, starting with “\” for the root directory.  In C++, the backslash character needs to be coded up using the escape-sequence “\\”.  This is similar to a tab, which is “\t”, and newline, which is “\n”.
The list of commands are:
dir	list the files and directories in the current directoy, and in the order they are currently held in your data structure

sortsize 	sorts the current directory by increasing size with all directories at the top of the list.  This order must persistent by updating the internal order of your 
collections so when dir is called again, this order is shown until a new sort is performed

sortname	sorts the current directory lexographically.  This order must persistent by updating the internal order of your collections so when dir is called again, this 
order is shown until a new sort is performed

cd name	changes into that directory, if it exists.  If name is “..”, move back up to the current directory’s parent

mkdir name	makes a new directory called name – add to the end of current list

mkfile name	makes a new file called name – add to the end of the current list and set the size to a random value

del name	removes the file or directory called name

exit	exits your application
