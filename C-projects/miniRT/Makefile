# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alkrusts <alkrust@student.codam.nl>          +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 16:50:00 by alkrusts      #+#    #+#                  #
#    Updated: 2020/12/28 14:11:27 by alkrusts      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

MANDATORY_SRC = src/Amb.c \
	src/lighting_sq.c \
	src/lighting_tr.c \
	src/lighting_cy.c \
	src/lighting_sp.c \
	src/lighting_pl.c \
	src/cylinder.c \
	src/utils.c \
	src/utils2.c \
	src/utils3.c \
	src/utils4.c \
	src/utils5.c \
	src/utils6.c \
	src/Res.c \
	src/cylinder2.c \
	src/light.c \
	src/sphere2.c \
	src/camera.c \
	src/light2.c \
	src/plane.c \
	src/vector_5.c \
	src/squar.c \
	src/triangle.c \
	src/camera2.c \
	src/get_task.c \
	src/parce.c \
	src/plane2.c \
	src/squar2.c \
	src/triangle2.c \
	src/colors.c \
	src/hit_list.c \
	src/ray.c \
	src/vector.c \
	src/vector_6.c \
	src/vector_2.c \
	src/vector_4.c \
	src/free_render.c \
	src/pixel.c \
	src/sphere.c \
	src/sphere3.c \
	src/get_next_line.c \
	src/get_next_line_utils.c \
	src/sphereCore.c \
	src/cameraCore.c \
	src/colors2.c \
	src/camera3.c \
	src/vector_3.c \
	src/hooks.c \
	src/shade.c \
	src/save_bmp.c \
	src/plane3.c \
	src/main.c \
	src/screen_resize.c \
	src/render_sq.c \
	src/render_cy.c \
	src/render_triangle.c \
	src/norm_rounding_edge.c \
	src/debug_print.c \
	src/utils_for_light_2.c \
	src/utils_for_light.c \
	src/debug_print_2.c

BONUS_SRC = src/bonus/Amb_bonus.c \
	src/bonus/lighting_sq_bonus.c \
	src/bonus/lighting_tr_bonus.c \
	src/bonus/lighting_cy_bonus.c \
	src/bonus/lighting_sp_bonus.c \
	src/bonus/lighting_pl_bonus.c \
	src/bonus_for_light_2_bonus.c \
	src/bonus_for_light_bonus.c \
	src/bonus/cylinder_bonus.c \
	src/bonus_bonus.c \
	src/bonus2_bonus.c \
	src/bonus3_bonus.c \
	src/bonus4_bonus.c \
	src/bonus5_bonus.c \
	src/bonus6_bonus.c \
	src/bonus/Res_bonus.c \
	src/bonus/colors2_bonus.c \
	src/bonus/cylinder2_bonus.c \
	src/bonus/light_bonus.c \
	src/bonus/sphere2_bonus.c \
	src/bonus/camera_bonus.c \
	src/bonus/light2_bonus.c \
	src/bonus/plane_bonus.c \
	src/bonus/vector_5_bonus.c \
	src/bonus/squar_bonus.c \
	src/bonus/triangle_bonus.c \
	src/bonus/camera2_bonus.c \
	src/bonus/get_task_bonus.c \
	src/bonus/parce_bonus.c \
	src/bonus/plane2_bonus.c \
	src/bonus/squar2_bonus.c \
	src/bonus/triangle2_bonus.c \
	src/bonus/colors_bonus.c \
	src/bonus/hit_list_bonus.c \
	src/bonus/ray_bonus.c \
	src/bonus/vector_bonus.c \
	src/bonus/vector_6_bonus.c \
	src/bonus/vector_2_bonus.c \
	src/bonus/vector_4_bonus.c \
	src/bonus/free_render_bonus.c \
	src/bonus/pixel_bonus.c \
	src/bonus/sphere_bonus.c \
	src/bonus/sphere3_bonus.c \
	src/bonus/get_next_line_bonus.c \
	src/bonus/get_next_line_utils_bonus.c \
	src/bonus/sphereCore_bonus.c \
	src/bonus/cameraCore_bonus.c \
	src/bonus/camera3_bonus.c \
	src/bonus/vector_3_bonus.c \
	src/bonus/hooks_bonus.c \
	src/bonus/shade_bonus.c \
	src/bonus/save_bmp_bonus.c \
	src/bonus/plane3_bonus.c \
	src/bonus/screen_resize_bonus.c \
	src/bonus/render_sq_bonus.c \
	src/bonus/render_cy_bonus.c \
	src/bonus/render_triangle_bonus.c \
	src/bonus/norm_rounding_edge_bonus.c \
	src/bonus/debug_print_bonus.c \
	src/bonus/debug_print_2_bonus.c \
	src/bonus/main_bonus.c

INC = -Isrc/includes \
	-Ilibs/libft/ \
	-Ilibs/MLX42/include/MLX42 \
	-Ilibs/MLX42/include

ifdef BONUS
	SRC = $(BONUS_SRC)
	INC = src/bonus/minRT_bonus.h \
	src/bonus/varibles_bonus.h \
	src/bonus/get_next_line.h \
	src/bonus/parcer_bonus.h
else
	SRC = $(MANDATORY_SRC)
endif

HEADER = $(INC)

CFLAGS = -Wall -Werror -Wextra -g

ifdef DEBUG
	#CFLAGS += -fsanitize=address -g 
else ifdef FAST
	CFLAGS += -O3 
endif

OBJ_DIR = src/.obj

#OBJ := $(patsubst %,$(ODIR)/%,$(SRC_OBJ))

LIBS := libs/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm libs/libft/libft.a

#OBJ = $(SRC)

SRC_OBJ = $(SRC:.c=.o)

OBJ_B = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): LIBFT LIBMLX $(SRC_OBJ)
	$(CC) $(SRC_OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(INC) -c $(CFLAGS) $< -o $@ 

LIBFT:
	make -C libs/libft

LIBMLX:
	cmake ./libs/MLX42 -B ./libs/MLX42/build && make -C ./libs/MLX42/build -j4

debug:
	make debug -C libs/libft
	make DEBUG=1

fast:
	make fast -C libs/libft
	make FAST=1

round:
	make -C libs/libft
	make ROUND=1
dround:
	make -C libs/libft
	make DROUND=1

bonus:
	@make BONUS=1

clean:
	rm -rf $(SRC_OBJ)
	rm -rf $(OBJ_B)

fclean: clean
	rm -rf $(NAME)
	rm -rf libs/MLX42/build/
	make fclean -C libs/libft

re: fclean all
