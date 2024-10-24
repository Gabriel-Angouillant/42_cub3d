/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augougea <augougea@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:49:26 by augougea          #+#    #+#             */
/*   Updated: 2024/06/08 14:26:09 by augougea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_isalnum(int character);
int		ft_isalpha(int character);
int		ft_isascii(int character);
int		ft_isdigit(int character);
int		ft_isprint(int character);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_tolower(int character);
int		ft_toupper(int character);
void	ft_bzero(void *memoire, size_t taille);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_free_array(char **array);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_calloc(size_t elementcount, size_t elementsize);
void	*ft_memchr(const void *memory, int searchedchar, size_t size);
void	*ft_memcpy(void *destination, const void *source, size_t taille);
void	*ft_memmove(void *destination, const void *source, size_t taille);
void	*ft_memset(void *memoire, int octet, size_t taille);
char	*ft_itoa(int nbr);
char	*ft_strchr(const char *str, int searchedchar);
char	*ft_strdup(const char *src);
char	*ft_strdup_c(const char *src, char c);
char	*ft_strjoin_free(char *dest, char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *dest, char *src);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
char	*ft_strstr(char *str, char *to_find);
int		ft_strstr_i(char *str, char *to_find);
int		ft_strstr_b(char *str, char *to_find);
int		ft_strnstr_b(const char *str, const char *occurence, size_t size);
char	*ft_strdup_len(const char *src, int len);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strchr_b(const char *str, int searchedchar);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strrchr(const char *str, int searchedchar);
int		ft_strrchr_i(const char *str, int searchedchar);
int		ft_strchr_i(const char *str, int searchedchar);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlen_c(const char *s, char c);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);

#endif
