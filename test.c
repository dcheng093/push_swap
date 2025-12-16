/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:49:28 by dcheng            #+#    #+#             */
/*   Updated: 2025/12/16 16:52:39 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_VALUE 10000
/*
// Function to generate unique random numbers
static void generate_random(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % MAX_VALUE;
        // Ensure uniqueness
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                i--; // retry
                break;
            }
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <number_of_elements>\n", argv[0]);
        return 1;
    }

    int len = atoi(argv[1]);
    if (len <= 0)
    {
        printf("Please provide a positive number of elements.\n");
        return 1;
    }

    int *numbers = malloc(sizeof(int) * len);
    if (!numbers)
    {
        perror("malloc");
        return 1;
    }

    srand(time(NULL));
    generate_random(numbers, len);

    // Build command to run push_swap
    char command[65536] = "./push_swap";
    char buffer[32];
    for (int i = 0; i < len; i++)
    {
        snprintf(buffer, sizeof(buffer), " %d", numbers[i]);
        strncat(command, buffer, sizeof(command) - strlen(command) - 1);
    }

    printf("Running: %s\n", command);
    FILE *fp = popen(command, "r");
    if (!fp)
    {
        perror("popen");
        free(numbers);
        return 1;
    }

    // Count the number of operations push_swap outputs
    int operations = 0;
    char line[128];
    while (fgets(line, sizeof(line), fp))
    {
        operations++;
    }

    pclose(fp);

    printf("push_swap used %d operations for %d numbers.\n",
		operations, len);

    free(numbers);
    return 0;
}
*/
