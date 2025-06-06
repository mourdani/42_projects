DOCKER_COMPOSE = srcs/docker-compose.yml
	
NAME: $(DOCKER_COMPOSE)
	docker compose -f $(DOCKER_COMPOSE) up -d

all:	$(NAME)

delete:
		-docker stop api
		-docker stop frontend
		-docker stop postgresql
		-docker stop pgadmin
		docker system prune -a

api:
		-docker stop api
		-docker rm api
		-docker image rm srcs-api

frontend:
		-docker stop frontend
		-docker rm frontend
		-docker image rm srcs-frontend

db:
		-docker stop postgresql
		-docker rm postgresql
		-docker image rm srcs-db