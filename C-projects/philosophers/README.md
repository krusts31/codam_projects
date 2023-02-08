# philosophers

##### to run the famous dining philosophers simulations    

> philo uses mutexes
>
> philo_bonus uses semaphores
>

```sh
git clone
cd philo
make
./philo 4 410 200 200
./philo 4 410 200 200 3
./philo 200 410 200 200 3
./philo 7 800 200 200
```

### My journey

I love this project because I tried to make it as if I was programming in a functional language.
At the time I was reading Clean Code and got very intrigued on how to make a function just to do on thing.
I found that almost impossible to do in C, but I learned a lot in the process. Like why I was getting segfaults when the call stack exceeded 255.

1. Learned how to spot data races with `-fsanitize=thread`.
2. Learned about how to sync threads.
3. Learned about dead locks.
4. Learned about mulithreding in C
5. Learned what is a scheduler. 
6. Learned what are data races.
7. Learned about process syncrinozation
8. Learned what are threads.
9. Learned about the x86 processor.
10. Leraned about thread leaks.
11. Learned about the call stack.
12. Learned how to make `.mk` files
