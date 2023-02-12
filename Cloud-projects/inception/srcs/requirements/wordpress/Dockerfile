FROM alpine:edge

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
	mariadb-client \
	tini
	
RUN ln -s /usr/bin/php82 /usr/bin/php

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

RUN adduser -S nginx &&	addgroup -S nginx

RUN chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/bin/wp

WORKDIR /var/www/html

COPY www.conf /etc/php82/php-fpm.d/www.conf
COPY install.sh /tmp/install.sh

ENTRYPOINT ["tini", "--"]

CMD sh /tmp/install.sh
