/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sem_open_wraper.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 15:27:23 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/03/09 15:48:50 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
 *	we call sem_unlink before we creat a new semaphore because
 *	if it exists we will remove it from the virtual semaphore file
 *	that will prevent any previus value issues
 */

#include <fcntl.h>           /* For O_* constants */
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

sem_t	*new_semaphore(const char *name, const int value)
{
	sem_t	*semaphore;

	sem_unlink(name);
	semaphore = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (semaphore == SEM_FAILED)
	{
		printf("Error\n%s failed\n", name);
		exit(3);
	}
	return (semaphore);
}
