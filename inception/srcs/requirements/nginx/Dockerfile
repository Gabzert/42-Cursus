FROM debian:stable


RUN apt-get update && apt-get install -y nginx openssl \
    && rm -rf /var/lib/apt/lists/*

EXPOSE 443

COPY ./ft_nginx.conf /etc/nginx/conf.d
COPY ./test.html /var/www/html/test.html

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
 	-subj "/C=IT/ST=Italy/L=Florence/O=42/OU=42Firenze/CN=gfantech.42.fr" \
 	-keyout /etc/ssl/gfantech.42.fr.key \
 	-out /etc/ssl/gfantech.42.fr.crt

RUN cp /etc/ssl/gfantech.42.fr.crt /var/tmp/shared
RUN cp /etc/ssl/gfantech.42.fr.key /var/tmp/shared

RUN rm /etc/nginx/sites-enabled/default && \
    rm /etc/nginx/sites-available/default

CMD ["nginx", "-g", "daemon off;"]