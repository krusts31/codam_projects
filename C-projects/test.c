#include <pthread.h>
#include <stdio.h>

int	main()
{
	pthread_mutex_t	thread_state_lock;
	pthread_mutex_t	thread_state_lock2;
	int x = 23;
	x++;

	printf("%d\n,%d\n", thread_state_lock.__data.__lock,thread_state_lock.__data.__count);
	pthread_mutex_init(&thread_state_lock, 0);
	pthread_mutex_init(&thread_state_lock2, 0);
	/*
	__data = {__lock = 2, __count = 0, __owner = -1075053569, __nusers = 0, __kind = -6391,
    __spins = 32767, __elision = 0, __list = {__prev = 0x64, __next = 0x1000}},
  __size =
  */
	printf("%d\n,%d\n", thread_state_lock.__data.__lock,thread_state_lock.__data.__count);
	x++;
	return (0);
}
