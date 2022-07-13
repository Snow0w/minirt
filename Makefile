NAME		=	minirt

CC			=	cc

CFLAGS		+=	-Wall -Wextra -Werror -g -MMD

SRC_FILES	=	main.c

SRC_DIR		=	src

SRC			=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJ_DIR		=	obj

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

DEP			=	$(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.d))

PARSER_FILES=	ambient_parser.c\
				check_scene_correctness.c\
				common_parser_work.c\
				parser_utils.c\
				unsecure_atof.c\
				vlist_funcs.c\
				wrong_msg.c
PARSER_DIR	=	src/parser
SRC			+=	$(addprefix $(PARSER_DIR)/,$(PARSER_FILES))
PARSER_OBJ_DIR=	obj/parser
OBJ			+=	$(addprefix $(PARSER_OBJ_DIR)/,$(PARSER_FILES:.c=.o))
DEP			+=	$(addprefix $(PARSER_OBJ_DIR)/,$(PARSER_FILES:.c=.d))

GNL_FILES	=	get_next_line.c \
				get_next_line_utils.c 

GNL_DIR		=	src/get_next_line
SRC			+=	$(addprefix $(GNL_DIR)/,$(GNL_FILES))

GNL_OBJ_DIR	=	obj/get_next_line
OBJ			+=	$(addprefix $(GNL_OBJ_DIR)/,$(GNL_FILES:.c=.o))

INC_DIR		=	include
CFLAGS		+=	-I$(INC_DIR)

LIBFT_DIR	=	libft
LIBFT_NAME	=	ft
LIBFT		=	$(LIBFT_DIR)/lib$(LIBFT_NAME).a

CFLAGS		+=	-I$(LIBFT_DIR)
LFLAGS		+=	-L$(LIBFT_DIR)
LDLIBS		+=	-l$(LIBFT_NAME)

FL			=	-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

objdirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(PARSER_OBJ_DIR)
	@mkdir -p $(GNL_OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): objdirs $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LFLAGS) $(LDLIBS) $(FL) -o $(NAME)

$(LIBFT): libft

libft:
	@make -C libft bonus

clean:
	@make -C libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@make -C libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re libft  objdirs
