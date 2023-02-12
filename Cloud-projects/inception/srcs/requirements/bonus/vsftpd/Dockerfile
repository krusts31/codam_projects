FROM alpine:3.15

RUN apk update && apk upgrade && apk add --no-cache \
        vsftpd \
	tini

COPY vsftpd.conf /tmp/vsftpd.conf

COPY install.sh /tmp/install.sh

COPY vsftpd.baner /etc/vsftpd.baner

ENTRYPOINT ["tini", "--"]

CMD sh /tmp/install.sh
