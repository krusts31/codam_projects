FROM alpine:3.15
RUN apk update
RUN apk add openrc
RUN apk add nginx
RUN adduser -D -g 'www' www; \
	mkdir /www; \
	chown -R www:www /var/lib/nginx; \
	chown -R www:www /www;
RUN mv /etc/nginx/nginx.conf /etc/nginx/nginx.conf.orig
RUN rc-status
RUN touch /run/openrc/softlevel
RUN touch /etc/network/interfaces
RUN apk add vim
RUN apk add openssl
RUN openssl genrsa -aes256 -passout pass:xxxx -out ca.pass.key 4096
RUN openssl rsa -passin pass:xxxx -in ca.pass.key -out ca.key
RUN rm ca.pass.key
RUN openssl req -new -x509 -days 3650 -key ca.key -out ca.pem -subj "/C=NL/ST=Holland/L=Amsterdam/O=ft_server_srcs inc/OU=IT/CN=127.0.0.1"
RUN mv ca.key /etc/ssl
RUN mv ca.pem /etc/ssl/ca.pam
COPY local.conf /etc/nginx/nginx.conf
WORKDIR /home
COPY install.sh .
CMD /home/install.sh && sh
EXPOSE 443 9000
