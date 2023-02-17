/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:38:35 by rchahban          #+#    #+#             */
/*   Updated: 2023/02/15 20:38:36 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

char	*ft_itoa(int n);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*convert_to_binary(char c);
int		powerize(int base, unsigned int power);
int		convert_to_decimal(const char *str);
void	send_signals(int pid, char c);
void	ft_putstr(char *str);

#endif