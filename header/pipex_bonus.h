#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <sys/types.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include "../libft/header/libft.h"

char	**ft_find_path(char **envp);
char	**ft_delenie_cmd(char *argv);
char	**ft_check_file(char **arr, char **cmd);
char	**ft_change_cmd(char **cmd, char **envp);
char	*get_next_line(int fd);
char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *string, int symbol);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);

size_t	ft_strlen_gnl(const char *str);

int		**ft_create_pipes(int argc);

int		ft_choose_child(int **pipes, char **argv, char **envp, int i);
void	ft_choose_last_child(int **pipes, char **argv, char **envp, int i);

void	ft_call_exit(void);
void	ft_call_com_not_found(void);
void	ft_call_cant_open(void);
void	ft_call_cant_exe(void);
void	ft_close_all(int **pipes, int argc);
void	ft_free_all(int **pipes, int argc);

void	ft_for_first_child(int **pipe, char **argv, char **envp, int i);
void	ft_for_circle_child(int **pipe, char **argv, char **envp, int i);
void	ft_for_last_child(int **pipe, char **argv, char **envp, int i);

void	ft_for_first_hand_child(int **pipe, char **argv, char **envp, int i);
void	ft_for_circle_hand_child(int **pipe, char **argv, char **envp, int i);
void	ft_for_last_hand_child(int **pipe, char **argv, char **envp, int i);

#endif