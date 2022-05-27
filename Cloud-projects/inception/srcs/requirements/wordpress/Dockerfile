FROM alpine:3.15

RUN	apk update && apk upgrade && apk add --no-cache \
	wget	\
	mariadb-client	\
	php8-pecl-imagick \
	php8		\
	php8-fpm	\
	php8-ftp 	\
	php8-bcmath	\
	php8-bz2 	\
	php8-calendar	\
	php8-ctype	\
	php8-curl	\
	php8-dom	\
	php8-exif	\
	php8-fileinfo	\
	php8-gd		\
	php8-gmp	\
	php8-iconv	\
	php8-imap	\
	php8-intl	\
	php8-json	\
	php8-mbstring	\
	php8-pecl-mcrypt \
	php8-pecl-memcache \
	php8-mysqli	\
	php8-mysqlnd	\
	php8-openssl	\
	php8-pcntl	\
	php8-pdo	\
	php8-pdo_mysql	\
	php8-pdo_pgsql	\
	php8-pdo_sqlite \
	php8-pgsql	\
	php8-phar	\
	php8-posix	\
	php8-session	\
	php8-shmop	\
	php8-simplexml	\
	php8-soap	\
	php8-sockets	\
	php8-sodium	\
	php8-sqlite3	\
	php8-sysvsem	\
	php8-sysvshm	\
	php8-tokenizer	\
	php8-xml	\
	php8-xmlreader	\
	php8-xmlwriter	\
	php8-xsl	\
	php8-zip	\
	php8-zlib	
	
RUN	adduser -S nginx &&	addgroup -S nginx

RUN ln -s /usr/bin/php8 /usr/bin/php

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

RUN chmod +x wp-cli.phar
RUN cp wp-cli.phar /usr/bin/wp

WORKDIR /var/www/html

COPY php-fpm.conf /etc/php8/php-fpm.conf
COPY www.conf /etc/php8/php-fpm.d/www.conf
COPY install.sh /tmp/install.sh

CMD sh /tmp/install.sh
