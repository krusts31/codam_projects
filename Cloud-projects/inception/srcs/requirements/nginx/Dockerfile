FROM alpine:3.15

RUN apk update && apk upgrade && apk add --no-cache \
  nginx \
  openssl

RUN mkdir /etc/nginx/ssl

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
        -out /etc/nginx/ssl/alkrusts.pem \
        -keyout /etc/nginx/ssl/alkrusts.key \
        -subj "/C=NL/ST=Amsterdam/L=Amsterdam/ School/OU=alkrusts/CN=alkrusts/"

RUN mkdir -p /run/nginx

COPY default.conf /etc/nginx/http.d/default.conf

COPY install.sh /tmp/install.sh

CMD sh /tmp/install.sh
