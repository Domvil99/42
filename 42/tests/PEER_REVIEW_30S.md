# Peer Review 30s (solo tests C portables)

## Guion corto para explicar a un companero

1. "Tus tests no dependen de rutas fijas en el codigo: yo paso la ruta al compilar con cc usando -I y librerias .a."
2. "Si compila con -Wall -Wextra -Werror y el binario de test devuelve OK, tienes una validacion funcional fuerte."
3. "Para comparar comportamiento, uso test de referencia (por ejemplo printf real en ft_printf)."
4. "Esto sirve igual para tu repo o el mio: solo cambio <RUTA_...>."

## Comandos rapidos por proyecto

### libft
cc -Wall -Wextra -Werror 42/tests/testsLibf/test_libft_portable_strict.c -I<RUTA_LIBFT> <RUTA_LIBFT>/libft.a -o /tmp/test_libft && /tmp/test_libft

### ft_printf mandatory
cc -Wall -Wextra -Werror 42/tests/tests_ft_printf/test_mandatory_matrix.c -I<RUTA_FT_PRINTF> <RUTA_FT_PRINTF>/libftprintf.a <RUTA_FT_PRINTF>/libft/libft.a -o /tmp/test_ftp_m && /tmp/test_ftp_m

### ft_printf referencia libc
cc -Wall -Wextra -Werror 42/tests/tests_ft_printf/test_mandatory_ref.c -o /tmp/test_ftp_ref && /tmp/test_ftp_ref

### get_next_line mandatory
cc -Wall -Wextra -Werror -DBUFFER_SIZE=42 42/tests/tests_get_next_line/test_gnl_mandatory_strict.c <RUTA_GNL>/get_next_line.c <RUTA_GNL>/get_next_line_utils.c -I<RUTA_GNL> -o /tmp/test_gnl_m && /tmp/test_gnl_m

### get_next_line bonus
cc -Wall -Wextra -Werror -DBUFFER_SIZE=42 42/tests/tests_get_next_line/test_gnl_bonus_multifd_strict.c <RUTA_GNL>/get_next_line_bonus.c <RUTA_GNL>/get_next_line_utils_bonus.c -I<RUTA_GNL> -o /tmp/test_gnl_b && /tmp/test_gnl_b

### push_swap
cc -Wall -Wextra -Werror 42/tests/tests_push_swap/test_push_swap_portable_strict.c -o /tmp/test_ps && /tmp/test_ps <RUTA_PUSH_SWAP_BIN> <RUTA_CHECKER_BIN>

### currentLibft integration
cc -Wall -Wextra -Werror 42/tests/tests_currentLibft/test_current_libft_link_strict.c -I<RUTA_CURRENT_LIBFT>/libft -I<RUTA_CURRENT_LIBFT>/libft/ft_printf <RUTA_CURRENT_LIBFT>/libft/ft_printf/libftprintf.a <RUTA_CURRENT_LIBFT>/libft/libft.a -o /tmp/test_current && /tmp/test_current

## Nota practica
- Si el repo del companero no tiene estructura estandar, ajusta solo las rutas.
- El codigo de test no se toca: se tocan los paths del comando cc.
