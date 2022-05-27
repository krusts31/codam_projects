SHELL:= /bin/bash

all: up

set_up_hosts:
	if ! grep --silent -w "127.0.0.1 $(USER).42.fr" /etc/hosts 2> /dev/null; then\
		sudo -- sh -c "echo 127.0.0.1 $(USER).42.fr >> /etc/hosts";\
	fi;

set_up_remap:
	if ! grep --silent -w "$(USER)" /etc/docker/daemon.json 2> /dev/null; then\
		sudo -- sh -c 'echo {\"userns-remap\": \"$(USER)\"} > /etc/docker/daemon.json';\
		sudo systemctl restart docker;\
	fi;

set_up_volumes:
	sudo mkdir -p ~/data/mariadb
	sudo mkdir -p ~/data/wordpress

up: set_up_hosts set_up_remap set_up_volumes
	docker-compose -f srcs/docker-compose.yml --env-file srcs/.env up --build

help:
	@echo "make up start up the cluster"
	@echo "make down shut down the cluster"
	@echo "make clean to clean the docker system"
	@echo "make fclean to delete the volume"
	@echo "make re to force rebuild images"
	@echo "make detach to make the start services in bg"

stop:
	docker stop -t 0 $(shell docker ps -q)

rebuild: set_up_hosts set_up_remap set_up_volumes
	docker-compose -f srcs/docker-compose.yml --env-file srcs/.env up --build --force-recreate

detach: set_up_hosts set_up_remap set_up_volumes
	docker-compose -f srcs/docker-compose.yml --env-file srcs/.env up -d --build

down:
	docker-compose -f srcs/docker-compose.yml --env-file srcs/.env down

clean:
	docker system prune -af

fclean: clean
	sudo rm -rf ~/data
	docker volume rm $(shell docker volume ls -q)

re: fclean up
