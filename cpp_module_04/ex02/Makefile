#	Source Files	#
SRCS	= srcs/Animal.cpp srcs/Dog.cpp srcs/Cat.cpp srcs/WrongAnimal.cpp \
			srcs/WrongCat.cpp srcs/Brain.cpp main.cpp

#	Object Files	#
OBJS	= $(SRCS:.cpp=.o)

#	Variables	#
NAME	= animal
CC	= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM	= rm -rf

#	Default Target	#
all:	$(NAME)

#	Creating animal executable	#
$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

#	Compilation rule	#
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#	Delete object files	#
clean:
	$(RM) $(OBJS)

#	Delete object files and the executable	#
fclean: clean
	$(RM) $(NAME)

#	Rebuild everything	#
re: fclean all

.PHONY: all clean fclean re
