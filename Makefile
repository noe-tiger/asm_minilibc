##
## EPITECH PROJECT, 2018
## *
## File description:
## *
##

NAME		=	libasm.so

SRC		=	src/strlen.S	\
			src/strchr.S	\
			src/memset.S	\
			src/memcpy.S	\
			src/strcmp.S	\
			src/memmove.S	\
			src/strncmp.S	\
			src/strncpy.S	\
			src/rindex.S	\
			src/strcpy.S	\
			src/strstr.S	\
			src/strcspn.S	\
			src/strpbrk.S	\
			src/strcasecmp.S

ASMFLAGS	=	-f elf64

LDFLAGS		=	-fPIC -shared

ASM		=	nasm

OBJ		=	$(SRC:.S=.o)

CC		=	gcc

RM		=	rm -f

LD		=	ld

%.o: %.S
		$(ASM) -o $@ $< $(ASMFLAGS)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(LD) $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

test:		all

		$(CC) test/main.c $(OBJ) -o test.out

.phony:		all clean fclean re test
