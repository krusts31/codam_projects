all:
	docker-compose -f srcs/docker-compose.yml --env-file srcs/.env up
fclean:
	docker-compose -f srcs/docker-compose.yml --env-file srcs/.env down
	docker system prune -a
re:
	docker-compose -f srcs/docker-compose.yml --env-file srcs/.env up --force-recreate --build
	docker image prune -f
stop:
	docker-compose -f srcs/docker-compose.yml down
