NAME = minirt

SRCS_NAME = ./main_c/main \
			./main_c/main_draw \
			./main_c/main_set \
			./main_c/main_set2 \
			./main_c/main_parse \
			./main_c/main_parse2 \
			./main_c/main_parse3 \
			./main_c/main_parse4 \
			./main_c/utils/check_num \
			./main_c/utils/check_vec \
			./main_c/utils/free_split \
			./main_c/utils/ft_atof \
			./main_c/utils/ft_strexit \
			./main_c/utils/ft_strncmp \
			./include/vec_utils/vec_utils \
			./include/vec_utils/vec_utils2 \
			./include/vec_utils/vec_utils3 \
			./include/vec_utils/vec_utils4 \
			./include/vec_utils/vec_utils5 \
			./include/vec_utils/vec_utils6 \
			./include/vec_utils/vec_utils7 \
			./include/ray \
			./include/mlx_functions/mlx_utils \
			./include/mlx_functions/mlx_utils2 \
			./include/hit/hit \
			./include/hit/hit_cone \
			./include/hit/hit_cone2 \
			./include/hit/hit_cylinder \
			./include/hit/hit_cylinder2 \
			./include/hit/hit_cube \
			./include/hit/hit_cube2 \
			./include/hit/hit_cube3	\
			./include/hit/hit_paraboloid \
			./include/hit/hit_paraboloid2 \
			./include/hit/hit_obj \
			./include/hit/hit_ray \
			./include/hit/hit_ray2 \
			./include/hit/hit_ray3 \
			./include/hit/hit_aabb \
			./include/hit/hit_aabb2 \
			./include/hit/hit_aabb3 \
			./include/hit/hit_noise \
			./include/hit/hit_noise2 \
			./include/hit/hit_img \
			./include/hit/hit_xyz_plane \
			./include/hit/hit_light_color \
			./include/pthread/pthread \

SRCS = $(addsuffix .c, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CC = cc

FLAGS = -Wall -Wextra -Werror

DEBUG = -fsanitize=undefined -g
DEBUG1 = -fsanitize=thread -g

MLX = -L./mlx -lmlx -framework OpenGL -framework Appkit

all:	$(NAME)

$(NAME):	$(OBJS)
			make bonus -C libft
			make -C mlx
			@$(CC) $(MLX) $(FLAGS) $(OBJS) -o $(NAME) ./mlx/libmlx.a ./libft/libft.a

%.o:	%.c
			$(CC) $(FLAGS) -c $< -o $@

clean:
			@make clean -C libft
			@make clean -C mlx
			@rm -rf $(OBJS)

fclean:		clean
			make fclean -C libft
			rm -rf $(NAME)

re:			
	make fclean
	make all

.PHONEY:	clean fclean re all