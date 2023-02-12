#!/bin/sh

if [ ! -f "/var/www/html/wp-config.php" ]; then
	wp core download --allow-root
	wp config create --dbname=$WORDPRESS_DATABASE_NAME --dbuser=$MARIADB_USER --dbpass=$MARIADB_USER_PASSWORD --dbhost=$MARIADB_HOST_NAME --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root
	wp core install --allow-root --url="/"  --title=$WORDPRESS_TITLE --admin_user=$WORDPRESS_ADMIN --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL
	wp user create $WORDPRESS_USER $WORDPRESS_USER_EMAIL --role=$WORDPRESS_USER_ROLE --user_pass=$WORDPRESS_USER_PASSWORD --allow-root 
	wp plugin delete $(wp plugin list --status=inactive --field=name --allow-root) --allow-root 
	wp theme delete $(wp theme list --status=inactive --field=name --allow-root) --allow-root  
	wp plugin update --all --allow-root
	wp plugin install "WP Super Cache" --allow-root
	wp plugin activate "wp-super-cache" --allow-root
	sed -i "27s/.*/define( 'FTP_USER', '$VSFPTD_USER');/" ./wp-config.php
	sed -i "30s/.*/define( 'FTP_PASS', '$VSFPTD_PASSWORD');/" ./wp-config.php
	sed -i "33s/.*/define( 'FTP_HOST', '$VSFPTD_HOST');/" ./wp-config.php
	sed -i "36s/.*/define( 'WP_SITEURL', 'https:\/\/localhost\/');/" ./wp-config.php
	sed -i "39s/.*/define( 'WP_HOME', 'https:\/\/localhost\/');/" ./wp-config.php
fi

exec /usr/sbin/php-fpm82 -F -R
