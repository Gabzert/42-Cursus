/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:23:21 by gabriele          #+#    #+#             */
/*   Updated: 2023/06/26 17:23:55 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int evaluateRPN(const std::string& expression)
{
    std::stack<int> operandStack;

    std::istringstream iss(expression);
    std::string token;
  
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (operandStack.size() < 2) {
                std::cout << "Error: Invalid expression." << std::endl;
                return 0;
            }
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result;
            if (token == "+")
                result = operand1 + operand2;
            else if (token == "-")
                result = operand1 - operand2;
            else if (token == "*")
                result = operand1 * operand2;
            else if (token == "/") {
                if (operand2 == 0) {
                    std::cout << "Error: Division by zero." << std::endl;
                    return 0;
                }
                result = operand1 / operand2;
            }
            operandStack.push(result);
        }
        else {
            // Assuming the token is a number
            int number;
            try {
                number = std::stoi(token);
            }
            catch (...) {
                std::cout << "Error: Invalid number." << std::endl;
                return 0;
            }
            operandStack.push(number);
        }
    }
  
    if (operandStack.size() == 1)
        return operandStack.top();
    else {
        std::cout << "Error: Invalid expression." << std::endl;
        return 0;
    }
}
