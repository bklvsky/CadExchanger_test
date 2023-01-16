cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.


project (cylinder)  #not sure whether this should be the same name of the executable, but I always see that "convention"


set(LIBS 
    CadExCore
    CadExSTL
    CadExBRep
    geom
    CadExPara
)


ADD_EXECUTABLE(cylinder main.cpp createCylinder.cpp)

include_directories(/usr/local/include)

# Change the path according to your configuration
target_link_libraries(cylinder -L/usr/local/lib/cadex/)
target_link_libraries(cylinder -l${LIBS})