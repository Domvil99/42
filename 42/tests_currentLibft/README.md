# tests_currentLibft

Manual integration gate for currentLibft.

## Scope
- Validate that currentLibft builds libft (parent) and integrated child projects.
- Start with ft_printf integration checks.
- Extend test set as new projects are integrated into currentLibft.

## Quick Checks
1. `cd 42/C/currentLibft && make && make bonus`
2. Build a minimal binary linking `libft/ft_printf/.mandatory.a` and `libft/libft.a`.
3. Run `norminette` in `42/C/currentLibft/libft` and `42/C/currentLibft/libft/ft_printf`.
