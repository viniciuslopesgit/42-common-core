Para compilar os ficheiros manualmente:
    '''
        gcc fdf.c -I../minilibx-linux -L../minilibx-linux -lmlx -lXext -lX11 -lm -o fdf
    '''
    ou
    '''
    gcc fdf.c ../files/ultils.c ../libft/get_next_line/get_next_line.c ../libft/get_next_line/get_next_line_utils.c -I../libft/minilibx-linux -L../libft/minilibx-linux  -lmlx -lXext -lX11 -lm -o fdf
    '''