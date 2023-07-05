NAME = inception

LOCATION = -f ./srcs/docker-compose.yml

all: $(NAME)

$(NAME): build
	docker-compose $(LOCATION) up

deamon: build
	docker-compose $(LOCATION) up -d

build:
	docker-compose $(LOCATION) build

clean:
	docker-compose $(LOCATION) down

fclean: clean
	docker-compose $(LOCATION) down --rmi all
	rm -r ~/mariadb/*
	rm -r ~/wordpress/*

re: fclean all

redeamon: fclean deamon

keygen:
	@mkdir -p /root/certs/private
	@mkdir -p /root/certs/certs
	@echo "Generating the cert and the key in /root/certs if not present"
	if [ ! -f "/root/certs/private/gfantech.42.fr.key" ]; then \
		openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
		-subj "/C=IT/ST=Italy/L=Florence/O=42/OU=42Firenze/CN=gfantech.42.fr" \
		-keyout /root/certs/private/gfantech.42.fr.key \
		-out /root/certs/certs/gfantech.42.fr.crt; \
	fi
	@cp /root/certs/certs/gfantech.42.fr.crt /var/tmp
	@chmod 444 /var/tmp/gfantech.42.fr.crt

delkey:
	@echo "Deleting the cert and the key in /root/certs"
	@rm -r /root/certs/private
	@rm -r /root/certs/certs

.PHONY: all build clean fclean re browsh deamon
