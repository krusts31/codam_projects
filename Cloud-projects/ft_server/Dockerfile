FROM alpine:edge as base

#pecl-imagick comes from testing
RUN echo "https://dl-cdn.alpinelinux.org/alpine/edge/testing" >> /etc/apk/repositories && \
	apk update && apk upgrade && apk add --no-cache \
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
	php82-pecl-imagick \
	php82-fpm \
	php82-session \
	php82-gd \
	php82-iconv \
	php82-intl \
	nginx \
	openssl \
	openrc \
	mariadb \
	mariadb-client \
	ssmtp

RUN wget https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-all-languages.tar.gz \
	https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

RUN ln -s /usr/bin/php82 /usr/bin/php

RUN chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/bin/wp && \
	mkdir -p /var/www/html/phpmyadmin

RUN tar xvf phpMyAdmin-latest-all-languages.tar.gz --strip-components 1 -C /var/www/html/phpmyadmin && \
	rm -rf phpMyAdmin-latest-all-languages.tar.gz

RUN openssl genrsa -aes256 -passout pass:xxxx -out ca.pass.key 4096 && \
	openssl rsa -passin pass:xxxx -in ca.pass.key -out ca.key && \
	rm ca.pass.key && \
	openssl req -new -x509 -days 3650 -key ca.key -out ca.pem -subj "/C=NL/ST=Holland/L=Amsterdam/O=ft_server_srcs inc/OU=IT/CN=127.0.0.1" && \
	mv ca.key /etc/ssl && \
	mv ca.pem /etc/ssl

RUN openrc && \
	echo "" > /run/openrc/softlevel && \
	/etc/init.d/mariadb setup && \
	rc-service mariadb start && \
	echo "GRANT ALL PRIVILEGES ON *.* TO 'user'@'localhost' IDENTIFIED BY 'password';" | mysql -u root && \
	echo "FLUSH PRIVILEGES" | mysql -u root && \
	wp core download --path=/var/www/html/wp && \
	wp config create --path=/var/www/html/wp --dbname=wordpress --dbuser=user --dbpass=password && \
	sed -i "36s/.*/define( 'WP_SITEURL', 'https:\/\/localhost\/wp');/" /var/www/html/wp/wp-config.php && \
	sed -i "39s/.*/define( 'WP_HOME', 'https:\/\/localhost\/wp');/" /var/www/html/wp/wp-config.php && \
	wp db create --path=/var/www/html/wp && \
	wp core install --path=/var/www/html/wp --url="/" --title="hello world" --admin_user="user" --admin_password="password" --admin_email="walave4776@ngopy.com" && \
	wp plugin install --path=/var/www/html/wp "WP Mail SMTP" && \
	wp plugin install --path=/var/www/html/wp "WP Super Cache" && \
	wp plugin activate --path=/var/www/html/wp "wp-super-cache" && \
	wp plugin activate --path=/var/www/html/wp "wp-mail-smtp" && \
	wp plugin delete --path=/var/www/html/wp $(wp --path=/var/www/html/wp plugin list --status=inactive --field=name) && \ 
	wp theme delete --path=/var/www/html/wp $(wp --path=/var/www/html/wp theme list --status=inactive --field=name) && \
	mariadb -e "USE wordpress;UPDATE wp_options SET option_value='https://localhost/wordpress' WHERE option_name='siteurl' OR option_name='home';"

COPY ./local.conf /etc/nginx/http.d/default.conf
COPY ./www.conf /etc/php82/php-fpm.d/www.conf
COPY ./start.sh ./start.sh

ENTRYPOINT ["/bin/sh", "start.sh"]
