all:
	docker-compose -f srcs/docker-compose.yml up
fclean:
	docker-compose -f srcs/docker-compose.yml down
	docker system prune -a
re:
	docker-compose -f srcs/docker-compose.yml up --force-recreate --build
	docker image prune -f
stop:
	docker-compose down -t 0
