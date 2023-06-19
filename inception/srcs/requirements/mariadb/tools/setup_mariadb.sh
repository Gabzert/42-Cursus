#!/bin/sh

set -e

echo "Setup started"

service mariadb start


if [ -d "/var/lib/mysql/$DB_NAME" ]; then 
	echo "Database already exists"
else
	/usr/bin/secure_installation

	echo "GRANT ALL ON *.* TO 'root'@'%' IDENTIFIED BY '$DB_ROOT_PASSWORD'; FLUSH PRIVILEGES;" | mysql -uroot
	echo "CREATE DATABASE IF NOT EXISTS $DB_NAME;" | mysql -uroot
	echo "GRANT ALL ON $DB_NAME.* TO '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';" | mysql -uroot
	echo " FLUSH PRIVILEGES;" | mysql -u root

	#mysql -uroot -p$DB_ROOT_PASSWORD $DB_NAME < /opt/wordpress.sql

fi

service mariadb stop

exec "$@"