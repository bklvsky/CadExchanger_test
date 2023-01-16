# Assignment_3_build
### Test assignment for CadExchanger

Crossplatform CMake building example without using Visual Studio Code.  
Tested on Ubuntu Linux, using Unix Makefiles, and Windows PowerShell, using MinGW Makefiles. 

## Usage

To build run:
- Windows: 
    ```
    cmake -G 'MinGW Makefiles' -B/path/to/my/build/folder -S/path/to/my/source/folder  
    cd /path/to/my/build/folder 
    make  
    ```
- Other:
    ```
    cmake -B/path/to/my/build/folder -S/path/to/my/source/folder
    cd /path/to/my/build/folder 
    make
    ```

To run:
```
cd /path/to/my/build/folder  
./triangle a b c  
```
Where a, b, c are the sides of the triangle.
