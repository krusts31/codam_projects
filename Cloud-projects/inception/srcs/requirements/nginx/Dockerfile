FROM alpine:3.15
RUN apk update && apk upgrade

RUN apk add --no-cache nginx

RUN adduser -D -g 'www' www; \
	mkdir /www; \
	chown -R www:www /var/lib/nginx; \
	chown -R www:www /www;

COPY local.conf /etc/nginx/nginx.conf

COPY ssl/ca.key /etc/ssl

COPY ssl/ca.pem /etc/ssl/ca.pam

RUN rm -rf /var/cache/apk/*

CMD ["nginx", "-g", "daemon off;"]
