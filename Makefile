NAME		=	push_swap

BNAME		=	checker

SRCS		= 	push_swap.c \
				sources/combinations1.c \
				sources/combinations2.c \
				sources/parser.c \
				sources/index.c \
				sources/mark.c \
				sources/nextindex.c \
				sources/operations.c \
				sources/push_a.c \
				sources/push_b.c \
				sources/sorting.c \

BSRCS		=	bonus/combinations1.c \
				bonus/combinations2.c \
				bonus/combinations3.c \
				bonus/checker.c \
				bonus/do_operations.c \
				bonus/filter.c \
				bonus/get_next_line.c \
				bonus/index.c \
				bonus/parser.c \

OBJS		= 	${SRCS:.c=.o}

BOBJS       =   ${BSRCS:.c=.o}

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror

INCLUDES	= 	includes/push_swap.h

RM			= 	rm -rf

all: 			$(NAME)

$(NAME): 		$(OBJS)
				$(MAKE) bonus -C ./libft
				${CC} ${CFLAGS} ${OBJS} libft/libft.a -o ${NAME}

bonus:			$(BOBJS)
				$(MAKE) bonus -C ./libft
				${CC} ${CFLAGS} ${BOBJS} libft/libft.a -o ${BNAME}

%.o : %.c 		${INCLUDES}
				${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o ${<:.c=.o}

clean:
				$(MAKE) clean -C ./libft
				${RM} $(OBJS) $(BOBJS)

fclean:			clean
				$(MAKE) fclean -C ./libft
				${RM} ${NAME} ${BNAME}

re:				fclean all

.PHONY:			all clean fclean re bonus
