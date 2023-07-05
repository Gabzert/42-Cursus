FROM debian:stable

EXPOSE 9000

# RUN apt-get update && apt-get install -y php php-fpm php-mysql mariadb-client wget 

RUN apt-get update && apt-get -y install \
	wget \
	curl \
	bash \
	php \
	php-cgi \
	php-mysql \
	php-fpm \
	php-pdo \
	php-gd php-cli \
	php-mbstring \
	php-redis \
	&& rm -rf /var/lib/apt/lists/*

COPY www.conf /etc/php/8.2/fpm/pool.d/www.conf

COPY setup_wp.sh /opt/setup_wp.sh

RUN chmod +x /opt/setup_wp.sh

ENTRYPOINT ["/opt/setup_wp.sh"]

CMD ["/usr/sbin/php-fpm8.2", "-F"]