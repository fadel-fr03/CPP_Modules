#	Source Files	#
SRCS	= srcs/ScalarConverter.cpp main.cpp

#	Object Files	#
OBJS	= $(SRCS:.cpp=.o)

#	Variables	#
NAME	= convert
CC	= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM	= rm -rf

#	Default Target	#
all:	$(NAME)

#	Creating convert executable	#
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
