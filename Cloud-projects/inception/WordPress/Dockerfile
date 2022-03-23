FROM alpine:3.15
RUN apk update
RUN apk add openrc
RUN rc-status
RUN touch /run/openrc/softlevel
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
    php8-pecl-redis

RUN ln -s /usr/bin/php8 /usr/bin/php
RUN mkdir -p /usr/share/webapps
RUN mkdir -p /usr/share/webapps
RUN mkdir -p /var/www
RUN mkdir -p /var/www/localhost
RUN mkdir -p /var/www/localhost/htdocs

#wordpress.org.		227	IN	A	198.143.164.252
RUN wget 198.143.164.252/latest.tar.gz -P /usr/share/webapps
RUN tar -xzvf /usr/share/webapps/latest.tar.gz -C /usr/share/webapps/
RUN ln -s /usr/share/webapps/wordpress/ /var/www/localhost/htdocs/wordpress
EXPOSE 9000 3306
#rc-service lighttpd start && rc-update add lighttpd default
