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

SRC =

MANDATORY_SRC = src/utils/Amb.c \
	src/utils/lighting_sq.c \
	src/utils/lighting_tr.c \
	src/utils/lighting_cy.c \
	src/utils/lighting_sp.c \
	src/utils/lighting_pl.c \
	src/utils/utils_for_light_2.c \
	src/utils/utils_for_light.c \
	src/utils/cylinder.c \
	src/utils/utils.c \
	src/utils/utils2.c \
	src/utils/utils3.c \
	src/utils/utils4.c \
	src/utils/utils5.c \
	src/utils/utils6.c \
	src/utils/Res.c \
	src/utils/cylinder2.c \
	src/utils/light.c \
	src/utils/sphere2.c \
	src/utils/camera.c \
	src/utils/light2.c \
	src/utils/plane.c \
	src/utils/vector_5.c \
	src/utils/squar.c \
	src/utils/triangle.c \
	src/utils/camera2.c \
	src/utils/get_task.c \
	src/utils/parce.c \
	src/utils/plane2.c \
	src/utils/squar2.c \
	src/utils/triangle2.c \
	src/utils/colors.c \
	src/utils/hit_list.c \
	src/utils/ray.c \
	src/utils/vector.c \
	src/utils/vector_6.c \
	src/utils/vector_2.c \
	src/utils/vector_4.c \
	src/utils/free_render.c \
	src/utils/pixel.c \
	src/utils/sphere.c \
	src/utils/sphere3.c \
	src/utils/get_next_line.c \
	src/utils/get_next_line_utils.c \
	src/utils/sphereCore.c \
	src/utils/cameraCore.c \
	src/utils/colors2.c \
	src/utils/camera3.c \
	src/utils/vector_3.c \
	src/utils/hooks.c \
	src/utils/shade.c \
	src/utils/save_bmp.c \
	src/utils/plane3.c \
	src/utils/main.c \
	src/utils/screen_resize.c \
	src/utils/render_sq.c \
	src/utils/render_cy.c \
	src/utils/render_triangle.c \
	src/utils/norm_rounding_edge.c \
	src/utils/debug_print.c \
	src/utils/debug_print_2.c

BONUS_SRC = src/utils/bonus/Amb_bonus.c \
	src/utils/bonus/lighting_sq_bonus.c \
	src/utils/bonus/lighting_tr_bonus.c \
	src/utils/bonus/lighting_cy_bonus.c \
	src/utils/bonus/lighting_sp_bonus.c \
	src/utils/bonus/lighting_pl_bonus.c \
	src/utils/bonus/utils_for_light_2_bonus.c \
	src/utils/bonus/utils_for_light_bonus.c \
	src/utils/bonus/cylinder_bonus.c \
	src/utils/bonus/utils_bonus.c \
	src/utils/bonus/utils2_bonus.c \
	src/utils/bonus/utils3_bonus.c \
	src/utils/bonus/utils4_bonus.c \
	src/utils/bonus/utils5_bonus.c \
	src/utils/bonus/utils6_bonus.c \
	src/utils/bonus/Res_bonus.c \
	src/utils/bonus/colors2_bonus.c \
	src/utils/bonus/cylinder2_bonus.c \
	src/utils/bonus/light_bonus.c \
	src/utils/bonus/sphere2_bonus.c \
	src/utils/bonus/camera_bonus.c \
	src/utils/bonus/light2_bonus.c \
	src/utils/bonus/plane_bonus.c \
	src/utils/bonus/vector_5_bonus.c \
	src/utils/bonus/squar_bonus.c \
	src/utils/bonus/triangle_bonus.c \
	src/utils/bonus/camera2_bonus.c \
	src/utils/bonus/get_task_bonus.c \
	src/utils/bonus/parce_bonus.c \
	src/utils/bonus/plane2_bonus.c \
	src/utils/bonus/squar2_bonus.c \
	src/utils/bonus/triangle2_bonus.c \
	src/utils/bonus/colors_bonus.c \
	src/utils/bonus/hit_list_bonus.c \
	src/utils/bonus/ray_bonus.c \
	src/utils/bonus/vector_bonus.c \
	src/utils/bonus/vector_6_bonus.c \
	src/utils/bonus/vector_2_bonus.c \
	src/utils/bonus/vector_4_bonus.c \
	src/utils/bonus/free_render_bonus.c \
	src/utils/bonus/pixel_bonus.c \
	src/utils/bonus/sphere_bonus.c \
	src/utils/bonus/sphere3_bonus.c \
	src/utils/bonus/get_next_line_bonus.c \
	src/utils/bonus/get_next_line_utils_bonus.c \
	src/utils/bonus/sphereCore_bonus.c \
	src/utils/bonus/cameraCore_bonus.c \
	src/utils/bonus/camera3_bonus.c \
	src/utils/bonus/vector_3_bonus.c \
	src/utils/bonus/hooks_bonus.c \
	src/utils/bonus/shade_bonus.c \
	src/utils/bonus/save_bmp_bonus.c \
	src/utils/bonus/plane3_bonus.c \
	src/utils/bonus/screen_resize_bonus.c \
	src/utils/bonus/render_sq_bonus.c \
	src/utils/bonus/render_cy_bonus.c \
	src/utils/bonus/render_triangle_bonus.c \
	src/utils/bonus/norm_rounding_edge_bonus.c \
	src/utils/bonus/debug_print_bonus.c \
	src/utils/bonus/debug_print_2_bonus.c \
	src/utils/bonus/main_bonus.c

ifdef BONUS
	SRC = $(BONUS_SRC)
	CFLAGS =-Wall -Werror -Wextra -O3
	INC = src/utiles/bonus/minRT_bonus.h \
	src/utils/bonus/varibles_bonus.h \
	src/utils/bonus/get_next_line.h \
	src/utils/bonus/parcer_bonus.h
else
	INC = src/utiles/minRT.h \
	src/utils/varibles.h \
	src/utils/get_next_line_bonus.h \
	src/utils/parcer.h
	SRC = $(MANDATORY_SRC)
	CFLAGS =-Wall -Werror -Wextra
endif

HEADER = $(INC)

ifdef DEBUG
	CFLAGS =-Wall -Werror -Wextra -g -fsanitize=address -fsanitize=undefined
else ifdef FAST
	CFLAGS =-Wall -Werror -Wextra -O3
endif


#hidden directory for .o files
OBJ_DIR = src/.obj

OBJ := $(patsubst %,$(ODIR)/%,$(SRC_OBJ))

LIBFT =-Lsrc/libs/libft -lft

MINLIB =-Lsrc/libs/minilibx -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRC)

SRC_OBJ = $(OBJ:.c=.o)

OBJ_B = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	make -C src/libs/libft
	make -C src/libs/minilibx
	cp src/libs/minilibx/libmlx.dylib ./
	$(CC) $(CFLAGS) $(LIBFT) $(MINLIB) $(SRC_OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -Imlx -o $@ $<

debug:
	make debug -C src/libs/libft
	make -C src/libs/minilibx
	make DEBUG=1

fast:
	make fast -C src/libs/libft
	make -C src/libs/minilibx
	make FAST=1

round:
	make -C src/libs/libft
	make -C src/libs/minilibx
	make ROUND=1
dround:
	make -C src/libs/libft
	make -C src/libs/minilibx
	make DROUND=1

bonus:
	@make BONUS=1

clean:
	rm -rf $(SRC_OBJ)
	rm -rf $(OBJ_B)

fclean: clean
	rm -rf $(NAME)
	make clean -C src/libs/libft
	make clean -C src/libs/minilibx
	make fclean -C src/libs/libft
	make clean -C src/norm
	rm -rf libmlx.dylib

re: fclean all
