NAME = ft_gkrellm

SRCS = main.cpp \
DateTime.cpp \
Hostname.cpp \
Ncurses.cpp \
Network.cpp \
OSInfo.cpp \
CPU.cpp \
REM.cpp \
Cat.cpp \

OBJ = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -lncurses

all: $(NAME)
	@echo "\033[0;32m"$(NAME)" is ready!"

$(NAME): $(OBJ)
	clang++ $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp
	clang++ $(FLAGS) -o $@ -c $<

