FROM debian:stable

RUN apt-get update && apt-get install -y mariadb-server \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld \
	&& chown -R mysql:mysql /var/run/mysqld \
	&& chmod 777 /var/run/mysqld

EXPOSE 3306

COPY tools/setup_mariadb.sh /usr/bin/setup_mariadb.sh
COPY tools/secure_installation /usr/bin/secure_installation

RUN chmod +x /usr/bin/secure_installation
RUN chmod +x /usr/bin/setup_mariadb.sh

COPY conf/mariadb.cnf /etc/mysql/mariadb.cnf
COPY conf/wordpress.sql /opt/wordpress.sql

ENTRYPOINT [ "setup_mariadb.sh" ];

CMD ["mysqld"]