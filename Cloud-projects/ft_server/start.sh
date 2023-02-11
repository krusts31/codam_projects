openrc && \
	echo "" > /run/openrc/softlevel && \
	/etc/init.d/mariadb setup && \
	rc-service mariadb start && \
	wp core download --path=/wp && \
	wp config create --path=/wp --dbname=wordpress --dbuser=root --dbpass= && \
	wp db create --path=/wp && \
	wp core install --path=/wp --url="/" --title="hello world" --admin_user="alkrusts" --admin_password="password" --admin_email="alkrusts@student.codam.nl" && \
	wp  --path=/wp plugin install "WP Mail SMTP" && \
	wp  --path=/wp plugin activate "wp-mail-smtp" && \
	mariadb -e "USE wordpress;UPDATE wp_options SET option_value='https://localhost/wordpress' WHERE option_name='siteurl' OR option_name='home';"
