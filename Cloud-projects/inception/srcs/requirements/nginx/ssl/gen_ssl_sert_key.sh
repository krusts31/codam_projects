openssl genrsa -aes256 -passout pass:xxxx -out ca.pass.key 4096
openssl rsa -passin pass:xxxx -in ca.pass.key -out ca.key
rm ca.pass.key
openssl req -new -x509 -days 3650 -key ca.key -out ca.pem -subj "/C=NL/ST=Holland/L=Amsterdam/O=ft_server_srcs inc/OU=IT/CN=127.0.0.1"
