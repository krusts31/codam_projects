cat srcs/.env  | grep "=" | cut -f 2 -d '=' | while IFS= read -r line; do echo -n "$line" | base64 --decode 2> /dev/null; echo "" ; done
