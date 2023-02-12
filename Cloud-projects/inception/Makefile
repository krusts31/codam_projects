SHELL:= /bin/bash

all: up

up:
	docker compose -f srcs/docker-compose.yml --env-file srcs/.env up --build

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
	docker compose -f srcs/docker-compose.yml --env-file srcs/.env up --build --force-recreate

detach: set_up_hosts set_up_remap set_up_volumes
	docker compose -f srcs/docker-compose.yml --env-file srcs/.env up -d --build

down:
	docker compose -f srcs/docker-compose.yml --env-file srcs/.env down

clean:
	docker system prune -af

fclean: clean
	sudo rm -rf ~/data
	docker volume rm $(shell docker volume ls -q)

re: fclean up
