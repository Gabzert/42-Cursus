#!/bin/sh

if [ -d "/var/www/html/wp-admin" ]; then
	echo "Wordpress already installed"
else
	wget -q -O /tmp/wordpress.tar.gz https://wordpress.org/wordpress-6.1.3.tar.gz

	tar -xzf /tmp/wordpress.tar.gz -C /tmp

	mkdir -p /var/www/html

	mv /tmp/wordpress/* /var/www/html

    rm -rf /tmp/worpress.tar.gz
fi

chown -R www-data:www-data /var/www/html
chmod -R 755 /var/www/html

service php8.2-fpm start

sleep 2

 wget -q -O /usr/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
 chmod +x /usr/bin/wp

if [ -f "/var/www/html/wp-config.php" ]; then
	echo "Wordpress already configured"
else
	#wp --allow-root --path=/var/www/html core config --dbhost=mariadb --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_PASSWORD

	sed -i "s/username_here/$DB_USER/g" /var/www/html/wp-config-sample.php
	sed -i "s/password_here/$DB_PASSWORD/g" /var/www/html/wp-config-sample.php
	sed -i "s/localhost/mariadb/g" /var/www/html/wp-config-sample.php
	sed -i "s/database_name_here/$DB_NAME/g" /var/www/html/wp-config-sample.php
	cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
fi

service php8.2-fpm stop

exec "$@"