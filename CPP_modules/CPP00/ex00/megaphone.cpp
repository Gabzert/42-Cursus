/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:13:06 by marvin            #+#    #+#             */
/*   Updated: 2023/03/21 10:13:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int i = 0;
	string str;
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
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++; 
	}
	cout << str << endl;
	return (0);
}