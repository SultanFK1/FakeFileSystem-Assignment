# Virtual File System - C++

## Description  
The Virtual File System (FFS) is an interactive console-based file system that operates entirely in dynamic/heap memory. Users can interact with the FFS through console commands (similar to a Windows-style command prompt) to manage files and directories. This system simulates a file system without modifying the real file system on disk. All changes made are limited to the in-memory representation of the file system.  

A Visual Studio 2022 starting project is provided with basic code to enumerate the real file system and extract information, but all commands will operate solely on the fake file system.  

## Key Features  
- **In-Memory Representation**: Files and directories exist only in memory and do not affect the actual file system.  
- **Dynamic Commands**: Interact with the file system using standard commands such as `dir`, `cd`, `mkdir`, and `mkfile`.  
- **Sorting**: Sort files and directories in the current folder by name or size, with the new order persisting across operations.  

## Commands  

### `dir`  
Lists the files and directories in the current directory in the current internal order.  

### `sortsize`  
Sorts the current directory by increasing size, with directories listed at the top. Updates the internal order, so subsequent `dir` commands reflect this change.  

### `sortname`  
Sorts the current directory lexicographically. Updates the internal order, so subsequent `dir` commands reflect this change.  

### `cd name`  
- Changes into the specified directory, if it exists.  
- Use `cd ..` to move back to the parent directory.  

### `mkdir name`  
Creates a new directory named `name` and adds it to the end of the current list.  

### `mkfile name`  
Creates a new file named `name` with a random size and adds it to the end of the current list.  

### `del name`  
Removes the file or directory named `name` from the current directory.  

### `exit`  
Exits the application.  

---

## Example Console Interaction  

```plaintext
Initialisation complete...  
\ :> dir  
12/09/2023  09:42    <DIR>     DirectoryName1  
12/04/2023  13:43     12,432   MyFile.tmp  
08/10/2022  15:32    <DIR>     DirectoryName2  
    1 File(s)        12,432 total bytes  
    2 Dir(s)  

\ :> cd DirectoryName1  
\DirectoryName1 :> dir  
...  
