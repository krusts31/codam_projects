FROM alpine:edge as base

RUN apk update && apk upgrade && apk add --no-cache \
	php82 \
	php82-phar \
	php82-openssl \
	php82-curl \
	php82-dom \
	php82-exif \
	php82-fileinfo \
	php82-sodium \
	php82-mbstring \
	php82-mysqli \
	php82-xml \
	php82-zip \
	php82-cgi \
	nginx \
	openssl \
	openrc \
	mariadb \
	mariadb-client \
	ssmtp

RUN openssl genrsa -aes256 -passout pass:xxxx -out ca.pass.key 4096 && \
	openssl rsa -passin pass:xxxx -in ca.pass.key -out ca.key && \
	ca.pass.key && \
	openssl req -new -x509 -days 3650 -key ca.key -out ca.pem -subj "/C=NL/ST=Holland/L=Amsterdam/O=ft_server_srcs inc/OU=IT/CN=127.0.0.1" && \
	mv ca.key /etc/ssl && \
	mv ca.pem /etc/ssl


RUN ln -s /usr/bin/php82 /usr/bin/php

RUN wget https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-all-languages.tar.gz \
	https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

RUN chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/bin/wp && \
	mkdir -p /var/www/html/phpmyadmin

RUN tar xvf phpMyAdmin-latest-all-languages.tar.gz -C /var/www/html/phpmyadmin && \
	rm -rf phpMyAdmin-latest-all-languages.tar.gz

RUN openrc && \
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
