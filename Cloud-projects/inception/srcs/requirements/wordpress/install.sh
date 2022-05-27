#!/bin/sh

#this is relly insecure because every time we are passing our password for every one to see
while ! mariadb -h$MARIADB_HOST_NAME -u$(echo -n $MARIADB_USER | base64 -d) -p$(echo -n $MARIADB_USER_PASSWORD | base64 -d) -e '\q' 2> /dev/null ; do
    echo "Waiting for maria DB"
    sleep 1
done
if [ ! -f "/var/www/html/wp-config.php" ]; then
	wp core download --allow-root
	wp config create --dbname=$WORDPRESS_DATABASE_NAME --dbuser=$(echo -n $MARIADB_USER | base64 -d) --dbpass=$(echo -n $MARIADB_USER_PASSWORD | base64 -d) --dbhost=$MARIADB_HOST_NAME --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root
	wp core install --allow-root --url=$WORDPRESS_URL  --title=$WORDPRESS_TITLE --admin_user=$(echo -n $WORDPRESS_ADMIN | base64 -d) --admin_password=$(echo -n $WORDPRESS_ADMIN_PASSWORD | base64 -d) --admin_email=$(echo -n $WORDPRESS_ADMIN_EMAIL | base64 -d)
	wp user create $(echo -n $WORDPRESS_USER | base64 -d) $(echo -n $WORDPRESS_USER_EMAIL | base64 -d) --role=$WORDPRESS_USER_ROLE --user_pass=$(echo -n $WORDPRESS_USER_PASSWORD | base64 -d) --allow-root 
	wp plugin delete $(wp plugin list --status=inactive --field=name --allow-root) --allow-root 
	wp theme delete $(wp theme list --status=inactive --field=name --allow-root) --allow-root  
	wp plugin update --all --allow-root
	echo "define( 'FTP_USER', '$(echo -n $VSFPTD_USER | base64 -d)' ); ">> wp-config.php
	echo "define( 'FTP_PASS', '$(echo -n $VSFPTD_PASSWORD | base64 -d)' ); ">> wp-config.php
	echo "define( 'FTP_HOST', '$VSFPTD_HOST'); ">> wp-config.php
fi
echo "Wordpress started"
touch wp_done
exec /usr/sbin/php-fpm8 -F -R
