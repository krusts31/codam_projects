FROM alpine:3.15

RUN apk update && apk upgrade && apk add --no-cache \
        vsftpd

COPY vsftpd.conf /tmp/vsftpd.conf

COPY install.sh /tmp/install.sh

COPY vsftpd.baner /etc/vsftpd.baner

CMD sh /tmp/install.sh
