# Assignment_2_cylinder
### Test assignment for CadExchanger

A program with CadExchanger SDK that creates a cylinder, generates its triangulation and writes it to the STL file.  
The number of generated triangles is displayed at stdout.  
Examples of generated STL files are located in the `examples` directory.  
The value of triangulation parameters - chordal and angular deflection - can also be adjusted in `cylinder.h`.

## Usage
The program is built with CMake. I assume that the CadEx SDK is already installed, otherwise refer [here](https://cadexchanger.com/products/sdk/).  
The build was tested on Linux with the library at `/usr/local/cadexchanger/3.9.2/` and header files at `/usr/local/include/`.  
You can update the paths in `CMakeLists.txt` according to your configuration, the same for your path to your license file in `cylinder.h`.

To build in the temporary directory run:

```
mkdir tmp  
cd tmp  
cmake ../  
make
```

This will build the "cylinder" executable that you can run with:  
`
./cylinder [radius] [height] [the new filename without .stl extension] 
`
## Conclusion

At first the assignment looked pretty simple to me, especially considering the fact that there are similar examples in the CadEx documentation.
Still, the problem turned out to be not so trivial after some revealed inconsistencies between the documentation and implementation of the SDK (it is always possible that it was me who missed something though). To figure out my own approach, I had to turn my research to the inner header files to understand some classes' members, methods and inner logic and overall I gained a decent grasp of the instrument's basics.  
