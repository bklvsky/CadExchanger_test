SRCS_FILES		=	ACurve2D.cpp \
					Line2D.cpp \
					Point2D.cpp \
					Ellipse2D.cpp \
					main.cpp
SRCS_PATH = ./src/
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

INC_FILES = ACurve2D.hpp \
			Line2D.hpp \
			Point2D.hpp \
			Ellipse2D.hpp
INC_PATH = ./inc/
INC = $(addprefix $(INC_PATH), $(INC_FILES))

OBJS_PATH = ./objs/
OBJS = $(addprefix $(OBJS_PATH), $(SRCS_FILES:.cpp=.o))
DEP = $(SRCS:.cpp=.d)

CXX = c++
RM = rm -rf
CXXFLAGS = -Wall -Wextra -Werror

TARGET = curves

all: $(TARGET)

$(TARGET):  $(OBJS_PATH) $(OBJS) 
	$(CXX) $(CXXFLAGS) -I$(INC_PATH) $(OBJS) -o $(TARGET)
	@echo "build $(TARGET) finished"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	$(CXX) -I$(INC_PATH) $(CXXFLAGS) -c $< -o $@ -MD
	@echo "Compiling: $<"

$(OBJS_PATH):
	@echo "Creating $(OBJS_PATH)"
	mkdir -p $(OBJS_PATH)

clean:
	$(RM) $(OBJS_PATH)

fclean: clean
	$(RM) $(TARGET)

re: fclean $(TARGET)

include $(wildcard $(DEP))

.PHONY:			all clean fclean re
