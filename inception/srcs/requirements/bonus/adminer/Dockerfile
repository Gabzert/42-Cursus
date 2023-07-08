FROM debian:stable


RUN apt-get update && apt-get install -y \
	wget \
	less \
	mariadb-client \
	php \
	php-fpm \
	php-common \
	php-iconv \
	php-json \
	php-gd \
	php-curl \
	php-xml \
	php-mysqli \
	php-imap \
	php-pdo \
	php-soap \
	php-posix \
	php-ldap \
	php-ctype \
	php-dom \
	php-simplexml \
	&& rm -rf /var/lib/apt/lists/*

#RUN the adminer part, create html directory, move the adminer directory and add user

# RUN \
# 	curl -L -O https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php && \
# 	mkdir -p /var/www/html && \
# 	mv ./adminer-4.8.1.php /var/www/html/adminer.php

RUN mkdir -p /var/www/html && \
	wget "http://www.adminer.org/latest.php" -O /var/www/html/adminer.php

COPY www.conf /etc/php/8.2/fpm/pool.d/www.conf

EXPOSE 9000

CMD ["php-fpm8.2", "--nodaemonize"]