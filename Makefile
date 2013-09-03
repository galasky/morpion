NAME		=	morpion

CXXFLAGS	=	-I include/ -Wextra -Wall -Werror

LDFLAGS		=	-lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio

CC		=	g++

RM		=	rm -fv

SRC		=	src/main.cpp	\
			src/Morpion.cpp	\
			src/Gride.cpp	\
			src/Sprite.cpp	\
			src/Window.cpp	\

OBJ		=	$(SRC:.cpp=.o)

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
