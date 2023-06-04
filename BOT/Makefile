NAME = bot
CPP = g++
CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98

SRCDIR = srcs
SRC = Bot.cpp

OBJ = $(addprefix $(SRCDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
