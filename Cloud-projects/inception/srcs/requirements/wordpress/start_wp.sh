#! /bin/sh

echo 'nameserver 8.8.8.8' >> /etc/resolv.conf


wp core download --allow-root --path="/var/www"
wp config create --dbname=$WORDPRESS_DATABASE_NAME --dbuser=$MARIADB_USER --dbpass=$MARIADB_USER_PASSWORD --dbhost=$MARIADB_HOST_NAME --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root --path="/var/www"
wp core install --allow-root --url=$WORDPRESS_URL  --title=$WORDPRESS_TITLE --admin_user=$WORDPRESS_ADMIN --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL --path="/var/www" 
wp user create $WORDPRESS_USER $WORDPRESS_USER_EMAIL --role=$WORDPRESS_USER_ROLE --user_pass=$WORDPRESS_USER_PASSWORD --allow-root --path="/var/www" 

sed 's/false/true/' -i /var/www/wp-config.php
echo "define( 'WP_DEBUG_LOG', '/var/log/wp.error' );" >> /var/www/wp-config.php
echo "define( 'SCRIPT_DEBUG', true );" >> /var/www/wp-config.php

chmod -R 755 /var/www
chown -R www:www /var/www

exec /usr/sbin/php-fpm8 -F -R
