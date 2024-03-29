/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <gfantech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:13:06 by marvin            #+#    #+#             */
/*   Updated: 2023/05/15 12:59:05 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int i = 0;
	std::string str;
	if (argc >= 2)
	{
		str = argv[1];
		for (int j = 2; j < argc; j++)
			str += argv[j];
	}
	else
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (str[i])
	{
		std::cout << std::toupper(str[i]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}
