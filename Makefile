NAME	= MyGKrellm

CC	= g++

RM	= rm -f

SRCS	= 	./main.cpp		\
			./Date_Time.cpp	\
			./Cpu_usage.cpp	\
			./Version.cpp	\
			./Name.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./pp
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lncurses ##-lsfml-graphics -lsfml-window -lsfml-system

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

SRCFML	=	SFML_test.cpp	\
			./Date_Time.cpp	\
			./Cpu_usage.cpp	\
			./Version.cpp	\
			./Name.cpp

csfml:
	$(CC) $(SRCFML) -o $(NAME) $(LDFLAGS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
