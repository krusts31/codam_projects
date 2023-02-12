# ft_server

##### To build and run the container

```sh
docker build -t ft_server .
docker run -it -p 80:80 -p 443:443 ft_server
```

#### username: user
#### password: password

##### wordpress ->
https://localhost/wp/
##### phpmyadmin ->
https://localhost/phpmyadmin/

This is a single container with `wordpress`, `mariadb`, `phpmyadmin`, `nginx`.
###### TODO: 
> add smtp, ftp

###### my journey:
1. How to write a `Dockerfile`.
2. How to build, run a docker container.
3. What is a docker container and who its different from a VM.
4. Sysadmin stuff.
5. How to set up a basic nginx, mariadb solution.
