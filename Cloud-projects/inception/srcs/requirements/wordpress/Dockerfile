FROM alpine:3.15
RUN apk update && apk upgrade
#install some utils
RUN apk add --no-cache openrc \
	mariadb-client

#install php
RUN apk add --no-cache php8 \
    php8-common \
    php8-fpm \
    php8-pdo \
    php8-opcache \
    php8-zip \
    php8-phar \
    php8-iconv \
    php8-cli \
    php8-curl \
    php8-openssl \
    php8-mbstring \
    php8-tokenizer \
    php8-fileinfo \
    php8-json \
    php8-xml \
    php8-xmlwriter \
    php8-simplexml \
    php8-dom \
    php8-pdo_mysql \
    php8-pdo_sqlite \
    php8-tokenizer \
    php8-mysqli \
    php8-pecl-redis

RUN ln -s /usr/bin/php8 /usr/bin/php

RUN mkdir -p /var/www

COPY start_wp.sh .
COPY www.conf /etc/php8/php-fpm.d/

RUN echo 'nameserver 8.8.8.8' >> /etc/resolv.conf; \
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

RUN rm -rf /var/cache/apk/*

RUN adduser -D -g 'www' www;

CMD sh start_wp.sh
