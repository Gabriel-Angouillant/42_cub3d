cd ..
cd ..
make re
clear
echo 			'**********'
echo 			'*  FILE  *'
echo 			'**********'
echo 			'          '
echo 			'          '
echo ***empty.cub***
valgrind ./cub3D cart/invalid/file/empty.cub
echo 			'          '
echo ***file_letter_begin.cub***
valgrind ./cub3D cart/invalid/file/file_letter_begin.cub
echo 			'          '
echo ***file_letter_middle.cub***
valgrind ./cub3D cart/invalid/file/file_letter_middle.cub
echo 			'          '
echo ***file_letter_end.cub***
valgrind ./cub3D cart/invalid/file/file_letter_end.cub
echo 			'          '
echo ***filetype_missing.txt***
valgrind ./cub3D cart/invalid/file/filetype_missing.txt
echo 			'          '
echo ***filetype_invalid_permission***
valgrind ./cub3D cart/invalid/file/filetype_invalid_permission.cub
echo 			'          '
echo ***forbidden.cub***
valgrind ./cub3D cart/invalid/file/forbidden.cub
echo 			'             '
echo 			'             '
echo 			'*************'
echo 			'*  TEXTURE  *'
echo 			'*************'
echo 			'             '
echo 			'             '
echo ***textures_dir.cub***
valgrind ./cub3D cart/invalid/texture/textures_dir.cub
echo 			'         '
echo ***textures_duplicates.cub***
valgrind ./cub3D cart/invalid/texture/textures_duplicates.cub
echo 			'         '
echo ***textures_forbidden.cub***
valgrind ./cub3D cart/invalid/texture/textures_forbidden.cub
echo 			'         '
echo ***textures_invalid.cub***
valgrind ./cub3D cart/invalid/texture/textures_invalid.cub
echo 			'         '
echo ***textures_missing.cub***
valgrind ./cub3D cart/invalid/texture/textures_missing.cub
echo 			'         '
echo ***textures_none.cub***
valgrind ./cub3D cart/invalid/texture/textures_none.cub
echo 			'         '
echo ***textures_not_xpm.cub***
valgrind ./cub3D cart/invalid/texture/textures_not_xpm.cub
echo 			'           '
echo 			'           '
echo 			'***********'
echo 			'*  COLOR  *'
echo 			'***********'
echo 			'           '
echo 			'           '
echo ***too_much_color.cub***
valgrind ./cub3D cart/invalid/color/too_much_color.cub
echo 			'           '
echo ***color_invalid_rgb_f.cub***
valgrind ./cub3D cart/invalid/color/color_invalid_rgb_f.cub
echo 			'           '
echo ***color_missing_c.cub***
valgrind ./cub3D cart/invalid/color/color_missing_c.cub
echo 			'           '
echo ***color_missing_ceiling_rgb_red.cub***
valgrind ./cub3D cart/invalid/color/color_missing_ceiling_rgb_red.cub
echo 			'           '
echo ***color_missing_ceiling_rgb_green.cub***
valgrind ./cub3D cart/invalid/color/color_missing_ceiling_rgb_green.cub
echo 			'           '
echo ***color_missing_ceiling_rgb_blue.cub***
valgrind ./cub3D cart/invalid/color/color_missing_ceiling_rgb_blue.cub
echo 			'           '
echo ***color_none.cub***
valgrind ./cub3D cart/invalid/color/color_none.cub
echo 			'         '
echo 			'         '
echo 			'*********'
echo			'*  MAP  *'
echo 			'*********'
echo 			'         '
echo 			'         '
echo ***map_first.cub***
valgrind ./cub3D cart/invalid/map/map_first.cub
echo 			'         '
echo ***map_middle.cub***
valgrind ./cub3D cart/invalid/map/map_middle.cub
echo 			'         '
echo ***map_missing.cub***
valgrind ./cub3D cart/invalid/map/map_missing.cub
echo 			'         '
echo ***map_only.cub***
valgrind ./cub3D cart/invalid/map/map_only.cub
echo 			'         '
echo ***map_too_small.cub***
valgrind ./cub3D cart/invalid/map/map_too_small.cub
echo 			'         '
echo ***map_with_wrong_letter.cub***
valgrind ./cub3D cart/invalid/map/map_with_wrong_letter.cub
echo 			'            '
echo 			'            '
echo 			'************'
echo 			'*  PLAYER  *'
echo 			'************'
echo 			'            '
echo 			'            '
echo ***player_multiple.cub***
valgrind ./cub3D cart/invalid/player/player_multiple.cub
echo 			'         '
echo ***player_none.cub***
valgrind ./cub3D cart/invalid/player/player_none.cub
echo 			'         '
echo ***player_on_edge.cub***
valgrind ./cub3D cart/invalid/player/player_on_edge.cub
echo 			'          '
echo 			'          '
echo 			'**********'
echo 			'*  WALL  *'
echo 			'**********'
echo 			'          '
echo 			'          '
echo ***wall_hole_east.cub***
valgrind ./cub3D cart/invalid/wall/wall_hole_east.cub
echo 			'          '
echo ***wall_hole_north.cub***
valgrind ./cub3D cart/invalid/wall/wall_hole_north.cub
echo 			'          '
echo ***wall_hole_south.cub***
valgrind ./cub3D cart/invalid/wall/wall_hole_south.cub
echo 			'          '
echo ***wall_hole_west.cub***
valgrind ./cub3D cart/invalid/wall/wall_hole_west.cub
echo 			'          '
echo ***wall_none.cub***
valgrind ./cub3D cart/invalid/wall/wall_none.cub
